/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM arm version 1.5.0
** DO NOT EDIT! The original file is in "src/jit/arm64/emit.dasc".
*/

#line 1 "src/jit/arm64/emit.dasc"
/* -*-C-*- */
#include "moar.h"
#include "jit/internal.h"
#include "dasm_arm64.h"

//|.arch arm64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 7 "src/jit/arm64/emit.dasc"
//|.actionlist actions
static const unsigned int actions[47] = {
0x00010000,
0xa9bb7bfd,
0x910003fd,
0xa90153f3,
0xf90013f5,
0x00000000,
0xaa0003f3,
0xaa0103f4,
0xf8400269,
0x000f0003,
0xf8400135,
0x000f0003,
0x00000000,
0xd61f0040,
0x00000000,
0x00060014,
0xf94013f5,
0xa94153f3,
0xa8c57bfd,
0xd65f03c0,
0x00000000,
0x00080000,
0x00000000,
0x14000000,
0x00070000,
0x00000000,
0xf8400269,
0x000f0003,
0xb4000009,
0x00050801,
0xaa1303e0,
0x00010001,
0x0006000f,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x0005080f,
0xd63f0200,
0x0006000b,
0x00000000,
0x14000000,
0x00050014,
0x00000000,
0x14000000,
0x00070000,
0x00000000
};

#line 8 "src/jit/arm64/emit.dasc"
//|.section code, data
#define DASM_SECTION_CODE	0
#define DASM_SECTION_DATA	1
#define DASM_MAXSECTION		2
#line 9 "src/jit/arm64/emit.dasc"
//|.globals MVM_JIT_LABEL_
enum {
  MVM_JIT_LABEL_exit,
  MVM_JIT_LABEL__MAX
};
#line 10 "src/jit/arm64/emit.dasc"

/* Typed register aliases — binds C struct type to a base register.
 * Field access TC->foo expands to [x19, #offsetof(MVMThreadContext, foo)]. */
//|.type TC,   MVMThreadContext, x19
#define Dt1(_V) (int)(ptrdiff_t)&(((MVMThreadContext *)0)_V)
#line 14 "src/jit/arm64/emit.dasc"
//|.type WORK, MVMRegister,      x21
#define Dt2(_V) (int)(ptrdiff_t)&(((MVMRegister *)0)_V)
#line 15 "src/jit/arm64/emit.dasc"
//|.type CU,   MVMCompUnit,      x20
#define Dt3(_V) (int)(ptrdiff_t)&(((MVMCompUnit *)0)_V)
#line 16 "src/jit/arm64/emit.dasc"
//|.type FRAME, MVMFrame
#define Dt4(_V) (int)(ptrdiff_t)&(((MVMFrame *)0)_V)
#line 17 "src/jit/arm64/emit.dasc"
//|.type OBJECT, MVMObject
#define Dt5(_V) (int)(ptrdiff_t)&(((MVMObject *)0)_V)
#line 18 "src/jit/arm64/emit.dasc"
//|.type STABLE, MVMSTable
#define Dt6(_V) (int)(ptrdiff_t)&(((MVMSTable *)0)_V)
#line 19 "src/jit/arm64/emit.dasc"

/* ---- Register conventions ------------------------------------------------
 * x0-x7  : ARG1-ARG8 / caller-saved
 * x8     : indirect result register (avoid)
 * x9-x15 : TMP1-TMP7 / caller-saved temporaries
 * x16    : FUNCTION / IP0 (linker scratch, used for callp)
 * x17    : spare / IP1
 * x18    : platform register (reserved, do not touch)
 * x19    : TC  (callee-saved — MVMThreadContext*)
 * x20    : CU  (callee-saved — MVMCompUnit*)
 * x21    : WORK (callee-saved — MVMRegister* work array)
 * x29    : FP  (frame pointer)
 * x30    : LR  (link register)
 * v0     : RVF / FP argument 0
 * v1-v7  : FP arguments
 * v8-v15 : callee-saved FP
 * v16-v31: caller-saved FP temporaries
 * ----------------------------------------------------------------------- */
//|.define ARG1,     x0
//|.define ARG2,     x1
//|.define ARG3,     x2
//|.define ARG4,     x3
//|.define ARG5,     x4
//|.define ARG6,     x5
//|.define ARG1F,    v0
//|.define ARG2F,    v1
//|.define TMP1,     x9
//|.define TMP2,     x10
//|.define TMP3,     x11
//|.define TMP4,     x12
//|.define TMP5,     x13
//|.define TMP6,     x14
//|.define TMP7,     x15
//|.define FUNCTION, x16
//|.define RV,       x0
//|.define RVF,      v0

/* Call a C function whose address is known at JIT compile time.
 * Stores the pointer in the data section and loads it PC-relatively. */
//|.macro callp, funcptr
//|.data
//|5:
//|.quad (uintptr_t)(funcptr)
//|.code
//| ldr FUNCTION, <5
//| blr FUNCTION
//|.endmacro

/* GC safe-point: if gc_status != 0, call into the GC. */
//|.macro gc_sync_point
//| ldr TMP1, TC->gc_status
//| cbz TMP1, >1
//| mov ARG1, x19
//| callp &MVM_gc_enter_from_interrupt
//|1:
//|.endmacro


MVMint32 MVM_jit_support(void) {
    return 1;
}

const unsigned char * MVM_jit_actions(void) {
    /* ARM64 DynASM emits unsigned int[] rather than unsigned char[] */
    return (const unsigned char *)actions;
}

/* ---- Prologue ------------------------------------------------------------
 * Called once per JIT compilation unit.  Sets up the C stack frame,
 * saves callee-saved registers, loads TC/CU/WORK, then jumps to the
 * entry label passed in as ARG3 (x2).
 *
 * Stack frame layout (80 bytes, 16-byte aligned):
 *   [sp+ 0]: x29 (saved FP)
 *   [sp+ 8]: x30 (saved LR)
 *   [sp+16]: x19 (saved TC caller value)
 *   [sp+24]: x20 (saved CU caller value)
 *   [sp+32]: x21 (saved WORK caller value)
 *   [sp+40..79]: scratch / spill space
 *
 * NOTE: jit_return_address trampoline not yet implemented for ARM64.
 *       TC->jit_return_address is left as-is (typically NULL).
 * ----------------------------------------------------------------------- */
void MVM_jit_emit_prologue(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg) {
    //|.code
    dasm_put(Dst, 0);
#line 105 "src/jit/arm64/emit.dasc"
    //| stp x29, x30, [sp, #-80]!
    //| mov x29, sp
    //| stp x19, x20, [sp, #16]
    //| str x21, [sp, #32]
    dasm_put(Dst, 1);
#line 109 "src/jit/arm64/emit.dasc"
    /* Load interpreter state from arguments */
    //| mov x19, ARG1
    //| mov x20, ARG2
    //| ldr TMP1, TC->cur_frame
    //| ldr x21, FRAME:TMP1->work
    dasm_put(Dst, 6, Dt1(->cur_frame), Dt4(->work));
#line 114 "src/jit/arm64/emit.dasc"
    /* Jump to the continuation label supplied by the caller */
    //| br ARG3
    dasm_put(Dst, 13);
#line 116 "src/jit/arm64/emit.dasc"
}

/* ---- Epilogue ------------------------------------------------------------
 * The ->exit global label is the single exit point for all JIT code.
 * Restores callee-saved registers and returns to the C caller.
 * ----------------------------------------------------------------------- */
void MVM_jit_emit_epilogue(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg) {
    //| ->exit:
    //| ldr x21, [sp, #32]
    //| ldp x19, x20, [sp, #16]
    //| ldp x29, x30, [sp], #80
    //| ret
    dasm_put(Dst, 15);
#line 129 "src/jit/arm64/emit.dasc"
}

/* ---- Labels and branches ------------------------------------------------ */

void MVM_jit_emit_label(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitGraph *jg, MVMint32 label) {
    //| =>(label):
    dasm_put(Dst, 21, (label));
#line 136 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMint32 label) {
    //| b =>(label)
    dasm_put(Dst, 23, (label));
#line 141 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_block_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMJitGraph *jg, MVMJitBranch *branch) {
    MVMSpeshIns *ins  = branch->ins;
    MVMint32     name = branch->dest;
    //| gc_sync_point
    dasm_put(Dst, 26, Dt1(->gc_status));
    dasm_put(Dst, 32, (unsigned int)((uintptr_t)(&MVM_gc_enter_from_interrupt)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_gc_enter_from_interrupt))>>32));
    dasm_put(Dst, 36);
#line 148 "src/jit/arm64/emit.dasc"
    if (ins == NULL || ins->info->opcode == MVM_OP_goto) {
        if (name == MVM_JIT_BRANCH_EXIT) {
            //| b ->exit
            dasm_put(Dst, 41);
#line 151 "src/jit/arm64/emit.dasc"
        } else {
            //| b =>(name)
            dasm_put(Dst, 44, (name));
#line 153 "src/jit/arm64/emit.dasc"
        }
    } else {
        MVM_oops(tc, "ARM64 JIT: conditional block branch not yet implemented");
    }
}

void MVM_jit_emit_all_bb_jumps(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMint32 name) {
    MVM_oops(tc, "ARM64 JIT: emit_all_bb_jumps not yet implemented");
}

/* ---- Stubs for unimplemented emitters ----------------------------------- */

void MVM_jit_emit_primitive(MVMThreadContext *tc, MVMJitCompiler *compiler,
                            MVMJitGraph *jg, MVMJitPrimitive *prim) {
    MVM_oops(tc, "ARM64 JIT: emit_primitive not yet implemented");
}

void MVM_jit_emit_call_c(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMJitGraph *jg, MVMJitCallC *call_spec) {
    MVM_oops(tc, "ARM64 JIT: emit_call_c not yet implemented");
}

void MVM_jit_emit_conditional_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                                     MVMint32 cond, MVMint32 label,
                                     MVMuint8 test_type) {
    MVM_oops(tc, "ARM64 JIT: emit_conditional_branch not yet implemented");
}

void MVM_jit_emit_guard(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitGraph *jg, MVMJitGuard *guard) {
    MVM_oops(tc, "ARM64 JIT: emit_guard not yet implemented");
}

void MVM_jit_emit_jumplist(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitJumpList *jumplist) {
    MVM_oops(tc, "ARM64 JIT: emit_jumplist not yet implemented");
}

void MVM_jit_emit_control(MVMThreadContext *tc, MVMJitCompiler *compiler,
                          MVMJitControl *ctrl, MVMJitTile *tile) {
    MVM_oops(tc, "ARM64 JIT: emit_control not yet implemented");
}

void MVM_jit_emit_data(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMJitData *data) {
    MVM_oops(tc, "ARM64 JIT: emit_data not yet implemented");
}

void MVM_jit_emit_load(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMint8 reg_dst, MVMJitStorageClass mem_cls,
                       MVMint32 mem_src, MVMint32 size) {
    MVM_oops(tc, "ARM64 JIT: emit_load not yet implemented");
}

void MVM_jit_emit_store(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitStorageClass mem_cls, MVMint32 mem_pos,
                        MVMint8 reg_src, MVMint32 size) {
    MVM_oops(tc, "ARM64 JIT: emit_store not yet implemented");
}

void MVM_jit_emit_copy(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMint8 dst_reg, MVMint8 src_num) {
    MVM_oops(tc, "ARM64 JIT: emit_copy not yet implemented");
}

void MVM_jit_emit_marker(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMint32 num) {
    /* no-op for now; used for debug markers */
}

void MVM_jit_emit_deopt_check(MVMThreadContext *tc, MVMJitCompiler *compiler) {
    MVM_oops(tc, "ARM64 JIT: emit_deopt_check not yet implemented");
}

void MVM_jit_emit_runbytecode(MVMThreadContext *tc, MVMJitCompiler *compiler,
                              MVMJitGraph *jg, MVMJitRunByteCode *runcode) {
    MVM_oops(tc, "ARM64 JIT: emit_runbytecode not yet implemented");
}

void MVM_jit_emit_runccode(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitRunCCode *runcode) {
    MVM_oops(tc, "ARM64 JIT: emit_runccode not yet implemented");
}

void MVM_jit_emit_runnativecall(MVMThreadContext *tc, MVMJitCompiler *compiler,
                                MVMJitGraph *jg, MVMJitRunNativeCall *runcode) {
    MVM_oops(tc, "ARM64 JIT: emit_runnativecall not yet implemented");
}

void MVM_jit_emit_dispatch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitDispatch *dispatch) {
    MVM_oops(tc, "ARM64 JIT: emit_dispatch not yet implemented");
}

void MVM_jit_emit_istype(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMJitGraph *jg, MVMJitIsType *istype) {
    MVM_oops(tc, "ARM64 JIT: emit_istype not yet implemented");
}
