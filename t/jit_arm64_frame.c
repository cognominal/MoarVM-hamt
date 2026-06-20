/* t/jit_arm64_frame.c
 * Minimal test for ARM64 JIT frame enter/exit.
 * Builds a JIT graph with only: label(0) -> branch_to_exit
 * and verifies that the prologue and epilogue run without crashing.
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

int main(int argc, char **argv) {
    MVMInstance      *instance;
    MVMThreadContext  *tc;
    MVMFrame         *saved_frame;
    MVMFrame          fake_frame;
    MVMRegister       fake_work[1];
    MVMSpeshGraph     fake_sg;
    MVMJitGraph       jg;
    MVMJitNode        label_node, branch_node;
    MVMJitCode       *code;

    /* ---- 1. JIT support ------------------------------------------------ */
    ok(MVM_jit_support(), "MVM_jit_support() returns 1");

    /* ---- 2. Instance creation ------------------------------------------ */
    instance = MVM_vm_create_instance();
    if (!instance) bail("MVM_vm_create_instance() returned NULL");
    tc = instance->main_thread;
    ok(tc != NULL, "main thread context exists");

    /* ---- 3. Install a minimal fake frame so prologue can read
     *         cur_frame->work without segfaulting. Save original first. ---- */
    saved_frame = tc->cur_frame;
    memset(&fake_frame, 0, sizeof(fake_frame));
    memset(fake_work,   0, sizeof(fake_work));
    fake_frame.work = fake_work;
    tc->cur_frame = &fake_frame;

    /* ---- 4. Minimal JIT graph: label(0) -> branch_to_exit -------------- */
    memset(&fake_sg, 0, sizeof(fake_sg));

    memset(&jg, 0, sizeof(jg));
    jg.sg            = &fake_sg;
    jg.num_labels    = 1;
    jg.no_trampoline = 1;

    memset(&label_node, 0, sizeof(label_node));
    label_node.type         = MVM_JIT_NODE_LABEL;
    label_node.u.label.name = 0;

    memset(&branch_node, 0, sizeof(branch_node));
    branch_node.type          = MVM_JIT_NODE_BRANCH;
    branch_node.u.branch.dest = MVM_JIT_BRANCH_EXIT;
    branch_node.u.branch.ins  = NULL;

    label_node.next  = &branch_node;
    branch_node.next = NULL;
    jg.first_node = &label_node;
    jg.last_node  = &branch_node;

    /* ---- 5. Compile ---------------------------------------------------- */
    code = MVM_jit_compile_graph(tc, &jg);
    ok(code != NULL,           "MVM_jit_compile_graph() succeeds");
    if (!code) bail("cannot continue without compiled code");

    ok(code->func_ptr   != NULL, "compiled code has a function pointer");
    ok(code->exit_label != NULL, "compiled code has an exit label");
    ok(code->num_labels >= 1,    "compiled code has at least 1 label");
    ok(code->labels[0]  != NULL, "label 0 is non-NULL");

    /* ---- 6. Enter the JIT frame ---------------------------------------- */
    fake_frame.jit_entry_label = code->labels[0];
    MVM_jit_code_enter(tc, code, NULL);
    ok(1, "JIT frame enter/exit completed without crash");

    /* ---- 7. Restore frame and cleanup ---------------------------------- */
    tc->cur_frame = saved_frame;
    MVM_jit_code_destroy(tc, code);
    ok(1, "jit_code_destroy succeeded");

    /* MVM_vm_destroy_instance requires a fully bootstrapped VM (serialised
     * 6model objects etc.) — not the case here.  The OS reclaims memory. */

    printf("1..%d\n", test_count);
    return fail_count ? 1 : 0;
}
