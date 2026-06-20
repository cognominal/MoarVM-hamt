/* t/jit_arm64_call.c
 * TAP tests for ARM64 JIT emit_call_c: builds JIT graphs that contain
 * CALL_C nodes and verifies they execute correctly.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "moar.h"
#include "jit/internal.h"

static int test_count = 0;
static int fail_count = 0;

#define ok(cond, msg) do { \
    test_count++; \
    if (cond) { printf("ok %d - %s\n", test_count, msg); } \
    else { printf("not ok %d - %s\n", test_count, msg); fail_count++; } \
} while(0)

#define bail(msg) do { \
    fprintf(stderr, "Bail out! %s\n", msg); \
    exit(1); \
} while(0)

/* ---- callback functions invoked by JIT-compiled code -------------------- */

static MVMThreadContext *got_tc = NULL;
static void cb_tc(MVMThreadContext *tc) {
    got_tc = tc;
}

static MVMint64 got_lit = 0;
static void cb_lit(MVMint64 val) {
    got_lit = val;
}

static MVMint64 got_a = 0, got_b = 0;
static MVMint64 cb_add(MVMint64 a, MVMint64 b) {
    got_a = a;
    got_b = b;
    return a + b;
}

static MVMRegister *got_addr = NULL;
static void cb_addr(MVMRegister *r) {
    got_addr = r;
}

/* ---- helpers ------------------------------------------------------------ */

/* Build a three-node JIT graph:  label(0) → call_c → branch_exit */
static MVMJitCode *build_call_graph(MVMThreadContext *tc,
                                    MVMJitGraph *jg,
                                    MVMSpeshGraph *sg,
                                    MVMJitCallC *call_spec,
                                    MVMJitNode *label_node,
                                    MVMJitNode *call_node,
                                    MVMJitNode *branch_node) {
    memset(sg,          0, sizeof(*sg));
    memset(jg,          0, sizeof(*jg));
    memset(label_node,  0, sizeof(*label_node));
    memset(call_node,   0, sizeof(*call_node));
    memset(branch_node, 0, sizeof(*branch_node));

    jg->sg            = sg;
    jg->num_labels    = 1;

    label_node->type         = MVM_JIT_NODE_LABEL;
    label_node->u.label.name = 0;

    call_node->type   = MVM_JIT_NODE_CALL_C;
    call_node->u.call = *call_spec;

    branch_node->type          = MVM_JIT_NODE_BRANCH;
    branch_node->u.branch.dest = MVM_JIT_BRANCH_EXIT;
    branch_node->u.branch.ins  = NULL;

    label_node->next  = call_node;
    call_node->next   = branch_node;
    branch_node->next = NULL;

    jg->first_node = label_node;
    jg->last_node  = branch_node;

    return MVM_jit_compile_graph(tc, jg);
}

static void run_jit(MVMThreadContext *tc, MVMJitCode *code, MVMFrame *frame) {
    frame->jit_entry_label = code->labels[0];
    MVM_jit_code_enter(tc, code, NULL);
}

/* ---- main --------------------------------------------------------------- */

int main(int argc, char **argv) {
    MVMInstance     *instance;
    MVMThreadContext *tc;
    MVMFrame          fake_frame;
    MVMRegister       fake_work[8];
    MVMFrame         *saved_frame;

    /* ---- bootstrap ---------------------------------------------------- */
    instance = MVM_vm_create_instance();
    if (!instance) bail("MVM_vm_create_instance() returned NULL");
    tc = instance->main_thread;
    ok(tc != NULL, "instance created");

    saved_frame = tc->cur_frame;
    memset(&fake_frame, 0, sizeof(fake_frame));
    memset(fake_work,   0, sizeof(fake_work));
    fake_frame.work = fake_work;
    tc->cur_frame = &fake_frame;

    /* ==== Test 1: void call, pass TC via INTERP_VAR ==================== */
    {
        MVMJitGraph   jg;
        MVMSpeshGraph sg;
        MVMJitNode    label_node, call_node, branch_node;
        MVMJitCode   *code;
        MVMJitCallArg args[1] = {{
            MVM_JIT_INTERP_VAR, { .ivar = MVM_JIT_INTERP_TC }
        }};
        MVMJitCallC call_spec = {
            .func_ptr = (void *)cb_tc,
            .args     = args,
            .num_args = 1,
            .rv_mode  = MVM_JIT_RV_VOID,
        };

        got_tc = NULL;
        code = build_call_graph(tc, &jg, &sg, &call_spec,
                                &label_node, &call_node, &branch_node);
        ok(code != NULL, "test1: compiled call_c(TC) graph");
        if (!code) bail("cannot continue");

        run_jit(tc, code, &fake_frame);
        ok(got_tc == tc, "test1: callback received correct TC pointer");
        MVM_jit_code_destroy(tc, code);
    }

    /* ==== Test 2: void call, pass literal int64 ======================== */
    {
        MVMJitGraph   jg;
        MVMSpeshGraph sg;
        MVMJitNode    label_node, call_node, branch_node;
        MVMJitCode   *code;
        MVMJitCallArg args[1] = {{
            MVM_JIT_LITERAL, { .lit_i64 = 42LL }
        }};
        MVMJitCallC call_spec = {
            .func_ptr = (void *)cb_lit,
            .args     = args,
            .num_args = 1,
            .rv_mode  = MVM_JIT_RV_VOID,
        };

        got_lit = 0;
        code = build_call_graph(tc, &jg, &sg, &call_spec,
                                &label_node, &call_node, &branch_node);
        ok(code != NULL, "test2: compiled call_c(literal 42) graph");
        if (!code) bail("cannot continue");

        run_jit(tc, code, &fake_frame);
        ok(got_lit == 42, "test2: callback received literal value 42");
        MVM_jit_code_destroy(tc, code);
    }

    /* ==== Test 3: int return, pass two REG_VAL args ==================== */
    {
        MVMJitGraph   jg;
        MVMSpeshGraph sg;
        MVMJitNode    label_node, call_node, branch_node;
        MVMJitCode   *code;
        MVMJitCallArg args[2] = {
            { MVM_JIT_REG_VAL, { .reg = 0 } },
            { MVM_JIT_REG_VAL, { .reg = 1 } },
        };
        MVMJitCallC call_spec = {
            .func_ptr = (void *)cb_add,
            .args     = args,
            .num_args = 2,
            .rv_mode  = MVM_JIT_RV_INT,
            .rv_idx   = 2,
        };

        fake_work[0].i64 = 10;
        fake_work[1].i64 = 20;
        fake_work[2].i64 = 0;
        got_a = got_b = 0;

        code = build_call_graph(tc, &jg, &sg, &call_spec,
                                &label_node, &call_node, &branch_node);
        ok(code != NULL, "test3: compiled call_c(WORK[0], WORK[1]) graph");
        if (!code) bail("cannot continue");

        run_jit(tc, code, &fake_frame);
        ok(got_a == 10 && got_b == 20, "test3: callback received correct WORK register values");
        ok(fake_work[2].i64 == 30, "test3: return value stored to WORK[2]");
        MVM_jit_code_destroy(tc, code);
    }

    /* ==== Test 4: void call, pass REG_ADDR ============================= */
    {
        MVMJitGraph   jg;
        MVMSpeshGraph sg;
        MVMJitNode    label_node, call_node, branch_node;
        MVMJitCode   *code;
        MVMJitCallArg args[1] = {{
            MVM_JIT_REG_ADDR, { .reg = 3 }
        }};
        MVMJitCallC call_spec = {
            .func_ptr = (void *)cb_addr,
            .args     = args,
            .num_args = 1,
            .rv_mode  = MVM_JIT_RV_VOID,
        };

        got_addr = NULL;
        code = build_call_graph(tc, &jg, &sg, &call_spec,
                                &label_node, &call_node, &branch_node);
        ok(code != NULL, "test4: compiled call_c(&WORK[3]) graph");
        if (!code) bail("cannot continue");

        run_jit(tc, code, &fake_frame);
        ok(got_addr == &fake_work[3], "test4: callback received address of WORK[3]");
        MVM_jit_code_destroy(tc, code);
    }

    /* ---- cleanup ------------------------------------------------------ */
    tc->cur_frame = saved_frame;

    printf("1..%d\n", test_count);
    return fail_count ? 1 : 0;
}
