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
static const unsigned int actions[218] = {
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
0x00000000,
0xaa1303ee,
0x00000000,
0xaa1403ee,
0x00000000,
0xf840026e,
0x000f0003,
0x00000000,
0xf840026e,
0x000f0003,
0x910001ce,
0x000c0000,
0x00000000,
0xf840026e,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf84002ae,
0x000f0003,
0x00000000,
0x910002ae,
0x000c0000,
0x00000000,
0xf840028e,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x5800000e,
0x00050810,
0x00000000,
0xf84002ae,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf84002ae,
0x000f0003,
0x910001ce,
0x000c0000,
0x00000000,
0xf840026e,
0x000f0003,
0xf94001ce,
0x784001ce,
0x000f0001,
0xf86e7aae,
0x00000000,
0x1000000e,
0x00072000,
0x00000000,
0xf84002ae,
0x000f0003,
0x00000000,
0x910002ae,
0x000c0000,
0x00000000,
0xf84002ae,
0x000f0003,
0x00000000,
0xf84002ae,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf84002ae,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf84002ae,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf840026e,
0x000f0003,
0xf84001ce,
0x000f0003,
0xf84001ce,
0x000f0003,
0x00000000,
0xf84003ae,
0x000f0003,
0x00000000,
0xaa0e03e0,
0x00000000,
0xaa0e03e1,
0x00000000,
0xaa0e03e2,
0x00000000,
0xaa0e03e3,
0x00000000,
0xaa0e03e4,
0x00000000,
0xaa0e03e5,
0x00000000,
0xaa0e03e6,
0x00000000,
0xaa0e03e7,
0x00000000,
0x9e6701c0,
0x00000000,
0x9e6701c1,
0x00000000,
0x9e6701c2,
0x00000000,
0x9e6701c3,
0x00000000,
0x9e6701c4,
0x00000000,
0x9e6701c5,
0x00000000,
0x9e6701c6,
0x00000000,
0x9e6701c7,
0x00000000,
0x00010001,
0x0006000f,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x0005080f,
0xd63f0200,
0x00000000,
0xf80002a0,
0x000f0003,
0x00000000,
0xf100001f,
0x9a9f17ea,
0xf80002aa,
0x000f0003,
0x00000000,
0xfc0002a0,
0x000f0003,
0x00000000,
0xf9400009,
0xf80002a9,
0x000f0003,
0x00000000,
0xf84002a9,
0x000f0003,
0xf9000009,
0x00000000,
0xf840026a,
0x000f0003,
0xf940014a,
0x7840014a,
0x000f0001,
0xf82a7aa0,
0x00000000,
0xb4000000,
0x00050804,
0xf9400009,
0x14000000,
0x00050005,
0x0006000e,
0xf8400269,
0x000f0003,
0xf8400129,
0x000f0003,
0x0006000f,
0xf80002a9,
0x000f0003,
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
//|.type TC,         MVMThreadContext, x19
#define Dt1(_V) (int)(ptrdiff_t)&(((MVMThreadContext *)0)_V)
#line 14 "src/jit/arm64/emit.dasc"
//|.type WORK,       MVMRegister,      x21
#define Dt2(_V) (int)(ptrdiff_t)&(((MVMRegister *)0)_V)
#line 15 "src/jit/arm64/emit.dasc"
//|.type CU,         MVMCompUnit,      x20
#define Dt3(_V) (int)(ptrdiff_t)&(((MVMCompUnit *)0)_V)
#line 16 "src/jit/arm64/emit.dasc"
//|.type FRAME,      MVMFrame
#define Dt4(_V) (int)(ptrdiff_t)&(((MVMFrame *)0)_V)
#line 17 "src/jit/arm64/emit.dasc"
//|.type OBJECT,     MVMObject
#define Dt5(_V) (int)(ptrdiff_t)&(((MVMObject *)0)_V)
#line 18 "src/jit/arm64/emit.dasc"
//|.type STABLE,     MVMSTable
#define Dt6(_V) (int)(ptrdiff_t)&(((MVMSTable *)0)_V)
#line 19 "src/jit/arm64/emit.dasc"
//|.type STOOGE,     MVMObjectStooge
#define Dt7(_V) (int)(ptrdiff_t)&(((MVMObjectStooge *)0)_V)
#line 20 "src/jit/arm64/emit.dasc"
//|.type VMARRAY,    MVMArray
#define Dt8(_V) (int)(ptrdiff_t)&(((MVMArray *)0)_V)
#line 21 "src/jit/arm64/emit.dasc"
//|.type CARRAY,     MVMCArray
#define Dt9(_V) (int)(ptrdiff_t)&(((MVMCArray *)0)_V)
#line 22 "src/jit/arm64/emit.dasc"
//|.type MVMINSTANCE, MVMInstance
#define DtA(_V) (int)(ptrdiff_t)&(((MVMInstance *)0)_V)
#line 23 "src/jit/arm64/emit.dasc"
//|.type STATICFRAME, MVMStaticFrame
#define DtB(_V) (int)(ptrdiff_t)&(((MVMStaticFrame *)0)_V)
#line 24 "src/jit/arm64/emit.dasc"
//|.type OBJECTPTR,  MVMObject*
#define DtC(_V) (int)(ptrdiff_t)&(((MVMObject* *)0)_V)
#line 25 "src/jit/arm64/emit.dasc"

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

//|.macro get_spesh_slot, reg, idx
//| ldr reg, TC->cur_frame
//| ldr reg, FRAME:reg->effective_spesh_slots
//| ldr reg, [reg, #((idx)*8)]
//|.endmacro

//|.macro get_vmnull, reg
//| ldr reg, TC->instance
//| ldr reg, MVMINSTANCE:reg->VMNull
//|.endmacro

//|.macro get_cur_op, reg
//| ldr reg, TC->interp_cur_op
//| ldr reg, [reg]
//|.endmacro

//|.macro get_string, reg, idx
//|| MVM_cu_ensure_string_decoded(tc, jg->sg->sf->body.cu, idx);
//| ldr reg, CU->body.strings
//| ldr reg, [reg, #((idx)*8)]
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
#line 133 "src/jit/arm64/emit.dasc"
    //| stp x29, x30, [sp, #-80]!
    //| mov x29, sp
    //| stp x19, x20, [sp, #16]
    //| str x21, [sp, #32]
    dasm_put(Dst, 1);
#line 137 "src/jit/arm64/emit.dasc"
    /* Load interpreter state from arguments */
    //| mov x19, ARG1
    //| mov x20, ARG2
    //| ldr TMP1, TC->cur_frame
    //| ldr x21, FRAME:TMP1->work
    dasm_put(Dst, 6, Dt1(->cur_frame), Dt4(->work));
#line 142 "src/jit/arm64/emit.dasc"
    /* Jump to the continuation label supplied by the caller */
    //| br ARG3
    dasm_put(Dst, 13);
#line 144 "src/jit/arm64/emit.dasc"
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
#line 157 "src/jit/arm64/emit.dasc"
}

/* ---- Labels and branches ------------------------------------------------ */

void MVM_jit_emit_label(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitGraph *jg, MVMint32 label) {
    //| =>(label):
    dasm_put(Dst, 21, (label));
#line 164 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMint32 label) {
    //| b =>(label)
    dasm_put(Dst, 23, (label));
#line 169 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_block_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMJitGraph *jg, MVMJitBranch *branch) {
    MVMSpeshIns *ins  = branch->ins;
    MVMint32     name = branch->dest;
    //| gc_sync_point
    dasm_put(Dst, 26, Dt1(->gc_status));
    dasm_put(Dst, 32, (unsigned int)((uintptr_t)(&MVM_gc_enter_from_interrupt)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_gc_enter_from_interrupt))>>32));
    dasm_put(Dst, 36);
#line 176 "src/jit/arm64/emit.dasc"
    if (ins == NULL || ins->info->opcode == MVM_OP_goto) {
        if (name == MVM_JIT_BRANCH_EXIT) {
            //| b ->exit
            dasm_put(Dst, 41);
#line 179 "src/jit/arm64/emit.dasc"
        } else {
            //| b =>(name)
            dasm_put(Dst, 44, (name));
#line 181 "src/jit/arm64/emit.dasc"
        }
    } else {
        MVM_oops(tc, "ARM64 JIT: conditional block branch not yet implemented");
    }
}

void MVM_jit_emit_all_bb_jumps(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMint32 name) {
    MVM_oops(tc, "ARM64 JIT: emit_all_bb_jumps not yet implemented");
}

/* ---- emit_call_c helpers ------------------------------------------------ */

static void load_call_arg(MVMThreadContext *tc, MVMJitCompiler *compiler,
                          MVMJitGraph *jg, MVMJitCallArg arg) {
    switch (arg.type) {
    case MVM_JIT_INTERP_VAR:
        switch (arg.v.ivar) {
        case MVM_JIT_INTERP_TC:
            //| mov TMP6, x19
            dasm_put(Dst, 47);
#line 201 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_CU:
            //| mov TMP6, x20
            dasm_put(Dst, 49);
#line 204 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_FRAME:
            //| ldr TMP6, TC->cur_frame
            dasm_put(Dst, 51, Dt1(->cur_frame));
#line 207 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_PARAMS:
            //| ldr TMP6, TC->cur_frame
            //| add TMP6, TMP6, #offsetof(MVMFrame, params)
            dasm_put(Dst, 54, Dt1(->cur_frame), offsetof(MVMFrame, params));
#line 211 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_CALLER:
            //| ldr TMP6, TC->cur_frame
            //| ldr TMP6, FRAME:TMP6->caller
            dasm_put(Dst, 59, Dt1(->cur_frame), Dt4(->caller));
#line 215 "src/jit/arm64/emit.dasc"
            break;
        }
        break;
    case MVM_JIT_REG_VAL:
    case MVM_JIT_REG_VAL_F: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 64, offset);
#line 222 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_ADDR: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| add TMP6, x21, #offset
        dasm_put(Dst, 67, offset);
#line 227 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_STR_IDX:
        //| get_string TMP6, arg.v.lit_i64
         MVM_cu_ensure_string_decoded(tc, jg->sg->sf->body.cu, arg.v.lit_i64);
        dasm_put(Dst, 70, Dt3(->body.strings), ((arg.v.lit_i64)*8));
#line 231 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_LITERAL:
    case MVM_JIT_LITERAL_64:
    case MVM_JIT_LITERAL_PTR:
    case MVM_JIT_LITERAL_F:
        //| .data
        dasm_put(Dst, 75);
#line 237 "src/jit/arm64/emit.dasc"
        //| 6:
        //| .quad (uintptr_t)(arg.v.lit_i64)
        //| .code
        dasm_put(Dst, 76, (unsigned int)((uintptr_t)(arg.v.lit_i64)), (unsigned int)((unsigned long long)((uintptr_t)(arg.v.lit_i64))>>32));
#line 240 "src/jit/arm64/emit.dasc"
        //| ldr TMP6, <6
        dasm_put(Dst, 80);
#line 241 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_REG_STABLE: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, OBJECT:TMP6->st
        dasm_put(Dst, 83, offset, Dt5(->st));
#line 246 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_OBJBODY: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        //| add TMP6, TMP6, #offsetof(MVMObjectStooge, data)
        dasm_put(Dst, 88, offset, offsetof(MVMObjectStooge, data));
#line 252 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_DYNIDX:
        //| get_cur_op TMP6
        //| ldrh w14, [x14, #(arg.v.reg * 2)]
        //| ldr x14, [x21, x14, lsl #3]
        dasm_put(Dst, 93, Dt1(->interp_cur_op), (arg.v.reg * 2));
#line 258 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_DATA_LABEL:
        //| adr TMP6, =>(arg.v.lit_i64)
        dasm_put(Dst, 100, (arg.v.lit_i64));
#line 261 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_ARG_I64:
    case MVM_JIT_PARAM_I64: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 103, offset);
#line 266 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_I64_RW:
    case MVM_JIT_PARAM_I64_RW: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| add TMP6, x21, #offset
        dasm_put(Dst, 106, offset);
#line 272 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_DOUBLE:
    case MVM_JIT_PARAM_DOUBLE: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 109, offset);
#line 278 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_PTR:
    case MVM_JIT_PARAM_PTR: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, STOOGE:TMP6->data
        dasm_put(Dst, 112, offset, Dt7(->data));
#line 285 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_VMARRAY:
    case MVM_JIT_PARAM_VMARRAY: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, VMARRAY:TMP6->body.slots
        dasm_put(Dst, 117, offset, Dt8(->body.slots));
#line 292 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_PARAM_CARRAY: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, CARRAY:TMP6->body.storage
        dasm_put(Dst, 122, offset, Dt9(->body.storage));
#line 298 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_SPESH_SLOT_VALUE:
        //| get_spesh_slot TMP6, arg.v.lit_i64
        dasm_put(Dst, 127, Dt1(->cur_frame), Dt4(->effective_spesh_slots), ((arg.v.lit_i64)*8));
#line 302 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_STACK_VALUE: {
        MVMint32 offset = 40 + (MVMint32)(arg.v.lit_i64 * 8);
        //| ldr TMP6, [x29, #offset]
        dasm_put(Dst, 134, offset);
#line 306 "src/jit/arm64/emit.dasc"
        break;
    }
    default:
        MVM_oops(tc, "ARM64 JIT: unknown call arg type %d", arg.type);
    }
}

static void emit_gpr_arg(MVMThreadContext *tc, MVMJitCompiler *compiler, MVMint32 i) {
    switch (i) {
    case 0:
        //| mov ARG1, TMP6
        dasm_put(Dst, 137);
#line 317 "src/jit/arm64/emit.dasc"
        break;
    case 1:
        //| mov ARG2, TMP6
        dasm_put(Dst, 139);
#line 320 "src/jit/arm64/emit.dasc"
        break;
    case 2:
        //| mov ARG3, TMP6
        dasm_put(Dst, 141);
#line 323 "src/jit/arm64/emit.dasc"
        break;
    case 3:
        //| mov ARG4, TMP6
        dasm_put(Dst, 143);
#line 326 "src/jit/arm64/emit.dasc"
        break;
    case 4:
        //| mov ARG5, TMP6
        dasm_put(Dst, 145);
#line 329 "src/jit/arm64/emit.dasc"
        break;
    case 5:
        //| mov ARG6, TMP6
        dasm_put(Dst, 147);
#line 332 "src/jit/arm64/emit.dasc"
        break;
    case 6:
        //| mov x6, TMP6
        dasm_put(Dst, 149);
#line 335 "src/jit/arm64/emit.dasc"
        break;
    case 7:
        //| mov x7, TMP6
        dasm_put(Dst, 151);
#line 338 "src/jit/arm64/emit.dasc"
        break;
    default:
        MVM_oops(tc, "ARM64 JIT: too many GPR call args (%d)", i);
    }
}

static void emit_fpr_arg(MVMThreadContext *tc, MVMJitCompiler *compiler, MVMint32 i) {
    switch (i) {
    case 0:
        //| fmov d0, x14
        dasm_put(Dst, 153);
#line 348 "src/jit/arm64/emit.dasc"
        break;
    case 1:
        //| fmov d1, x14
        dasm_put(Dst, 155);
#line 351 "src/jit/arm64/emit.dasc"
        break;
    case 2:
        //| fmov d2, x14
        dasm_put(Dst, 157);
#line 354 "src/jit/arm64/emit.dasc"
        break;
    case 3:
        //| fmov d3, x14
        dasm_put(Dst, 159);
#line 357 "src/jit/arm64/emit.dasc"
        break;
    case 4:
        //| fmov d4, x14
        dasm_put(Dst, 161);
#line 360 "src/jit/arm64/emit.dasc"
        break;
    case 5:
        //| fmov d5, x14
        dasm_put(Dst, 163);
#line 363 "src/jit/arm64/emit.dasc"
        break;
    case 6:
        //| fmov d6, x14
        dasm_put(Dst, 165);
#line 366 "src/jit/arm64/emit.dasc"
        break;
    case 7:
        //| fmov d7, x14
        dasm_put(Dst, 167);
#line 369 "src/jit/arm64/emit.dasc"
        break;
    default:
        MVM_oops(tc, "ARM64 JIT: too many FPR call args (%d)", i);
    }
}

static void emit_arm64_callargs(MVMThreadContext *tc, MVMJitCompiler *compiler,
                                MVMJitGraph *jg, MVMJitCallArg args[], MVMint32 num_args) {
    MVMint32 num_gpr = 0, num_fpr = 0, i;
    MVMJitCallArg in_gpr[8], in_fpr[8];

    for (i = 0; i < num_args; i++) {
        switch (args[i].type) {
        case MVM_JIT_INTERP_VAR:
        case MVM_JIT_REG_VAL:
        case MVM_JIT_REG_ADDR:
        case MVM_JIT_REG_OBJBODY:
        case MVM_JIT_REG_STABLE:
        case MVM_JIT_REG_DYNIDX:
        case MVM_JIT_STR_IDX:
        case MVM_JIT_LITERAL:
        case MVM_JIT_LITERAL_64:
        case MVM_JIT_LITERAL_PTR:
        case MVM_JIT_DATA_LABEL:
        case MVM_JIT_ARG_I64:
        case MVM_JIT_ARG_I64_RW:
        case MVM_JIT_ARG_PTR:
        case MVM_JIT_ARG_VMARRAY:
        case MVM_JIT_PARAM_I64:
        case MVM_JIT_PARAM_I64_RW:
        case MVM_JIT_PARAM_PTR:
        case MVM_JIT_PARAM_VMARRAY:
        case MVM_JIT_PARAM_CARRAY:
        case MVM_JIT_SPESH_SLOT_VALUE:
        case MVM_JIT_STACK_VALUE:
            if (num_gpr < 8) in_gpr[num_gpr++] = args[i];
            else MVM_oops(tc, "ARM64 JIT: too many GPR arguments");
            break;
        case MVM_JIT_ARG_DOUBLE:
        case MVM_JIT_PARAM_DOUBLE:
        case MVM_JIT_REG_VAL_F:
        case MVM_JIT_LITERAL_F:
            if (num_fpr < 8) in_fpr[num_fpr++] = args[i];
            else MVM_oops(tc, "ARM64 JIT: too many FPR arguments");
            break;
        default:
            MVM_oops(tc, "ARM64 JIT: unknown arg type %d in callargs", args[i].type);
        }
    }

    for (i = 0; i < num_gpr; i++) {
        load_call_arg(tc, compiler, jg, in_gpr[i]);
        emit_gpr_arg(tc, compiler, i);
    }
    for (i = 0; i < num_fpr; i++) {
        load_call_arg(tc, compiler, jg, in_fpr[i]);
        emit_fpr_arg(tc, compiler, i);
    }
}

/* ---- Stubs for unimplemented emitters ----------------------------------- */

void MVM_jit_emit_primitive(MVMThreadContext *tc, MVMJitCompiler *compiler,
                            MVMJitGraph *jg, MVMJitPrimitive *prim) {
    MVM_oops(tc, "ARM64 JIT: emit_primitive not yet implemented");
}

void MVM_jit_emit_call_c(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMJitGraph *jg, MVMJitCallC *call_spec) {
    emit_arm64_callargs(tc, compiler, jg, call_spec->args, call_spec->num_args);
    //| callp call_spec->func_ptr
    dasm_put(Dst, 169);
    dasm_put(Dst, 170, (unsigned int)((uintptr_t)(call_spec->func_ptr)), (unsigned int)((unsigned long long)((uintptr_t)(call_spec->func_ptr))>>32));
    dasm_put(Dst, 174);
#line 440 "src/jit/arm64/emit.dasc"

    switch (call_spec->rv_mode) {
    case MVM_JIT_RV_VOID:
        break;
    case MVM_JIT_RV_INT:
    case MVM_JIT_RV_PTR: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| str RV, [x21, #offset]
        dasm_put(Dst, 178, offset);
#line 448 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_INT_NEGATED: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| cmp RV, #0
        //| cset TMP2, eq
        //| str TMP2, [x21, #offset]
        dasm_put(Dst, 181, offset);
#line 455 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_NUM: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| str d0, [x21, #offset]
        dasm_put(Dst, 186, offset);
#line 460 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_DEREF: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| ldr TMP1, [RV]
        //| str TMP1, [x21, #offset]
        dasm_put(Dst, 189, offset);
#line 466 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_ADDR: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| ldr TMP1, [x21, #offset]
        //| str TMP1, [RV]
        dasm_put(Dst, 193, offset);
#line 472 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_DYNIDX:
        /* cur_op holds a u16 reg index at position rv_idx */
        //| get_cur_op TMP2
        //| ldrh w10, [x10, #(call_spec->rv_idx * 2)]
        //| str RV, [x21, x10, lsl #3]
        dasm_put(Dst, 197, Dt1(->interp_cur_op), (call_spec->rv_idx * 2));
#line 479 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_RV_DEREF_OR_VMNULL: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| cbz RV, >4
        //| ldr TMP1, [RV]
        //| b >5
        //|4:
        //| get_vmnull TMP1
        //|5:
        //| str TMP1, [x21, #offset]
        dasm_put(Dst, 204, Dt1(->instance), DtA(->VMNull), offset);
#line 489 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_TO_STACK:
        MVM_oops(tc, "ARM64 JIT: RV_TO_STACK not yet implemented");
        break;
    }
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
