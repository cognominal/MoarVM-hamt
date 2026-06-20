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
static const unsigned int actions[796] = {
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
0xf90017fe,
0x9100a3e9,
0xf8000269,
0x000f0003,
0x00000000,
0xd61f0040,
0x00000000,
0x00060014,
0x00000000,
0xf800027f,
0x000f0003,
0x00000000,
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
0x14000000,
0x00050001,
0x00000000,
0x14000000,
0x00070000,
0x00000000,
0x0006000b,
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
0x00000000,
0x54000004,
0x00070800,
0x00000000,
0x5400000b,
0x00070800,
0x00000000,
0x54000009,
0x00070800,
0x00000000,
0x5400000d,
0x00070800,
0x00000000,
0x54000000,
0x00070800,
0x00000000,
0x54000001,
0x00070800,
0x00000000,
0x5400000a,
0x00070800,
0x00000000,
0x5400000c,
0x00070800,
0x00000000,
0x54000001,
0x00070800,
0x00000000,
0x54000000,
0x00070800,
0x00000000,
0xf84002a9,
0x000f0003,
0x00000000,
0xf840026a,
0x000f0003,
0xf840014a,
0x000f0003,
0xf840014a,
0x000f0003,
0x00000000,
0xb4000009,
0x00050801,
0xf840012b,
0x000f0003,
0xeb0b015f,
0x54000001,
0x00050801,
0x00000000,
0xb4000009,
0x00050801,
0x3840012f,
0x000f0000,
0xf20001ff,
0x000e0000,
0x54000000,
0x00050801,
0xf840012b,
0x000f0003,
0xeb0b015f,
0x54000001,
0x00050801,
0x00000000,
0xb4000009,
0x00050801,
0x3840012f,
0x000f0000,
0xf20001ff,
0x000e0000,
0x54000001,
0x00050801,
0xf840012b,
0x000f0003,
0xeb0b015f,
0x54000001,
0x00050801,
0x00000000,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x5800000a,
0x00050810,
0xf840012b,
0x000f0003,
0xf840016c,
0x000f0003,
0xeb0c015f,
0x54000001,
0x00050801,
0x00000000,
0xf840012b,
0x000f0003,
0xeb0b015f,
0x54000001,
0x00050801,
0x00000000,
0xeb09015f,
0x54000001,
0x00050801,
0x00000000,
0xb4000009,
0x00050801,
0x00000000,
0xeb09015f,
0x54000000,
0x00050801,
0x00000000,
0xb4000009,
0x00050801,
0x3840012f,
0x000f0000,
0xf20001ff,
0x000e0000,
0x54000001,
0x00050801,
0x00000000,
0xb4000009,
0x00050801,
0x3840012f,
0x000f0000,
0xf20001ff,
0x000e0000,
0x54000000,
0x00050801,
0x00000000,
0xf80002a9,
0x000f0003,
0x00000000,
0x14000000,
0x00050002,
0x0006000b,
0x00000000,
0xaa1303e0,
0x52800001,
0x000a0205,
0x00010001,
0x0006000f,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x0005080f,
0xd63f0200,
0x14000000,
0x00050014,
0x0006000c,
0x00000000,
0xf84002a9,
0x000f0003,
0xf100013f,
0x5400000b,
0x00050802,
0xf100013f,
0x000c0000,
0x5400000a,
0x00050802,
0x00000000,
0xd37ef52a,
0x1000000b,
0x00052001,
0x8b0a016a,
0xd61f0140,
0x00040003,
0x0006000b,
0x00000000,
0x00080000,
0x14000000,
0x00070000,
0x00000000,
0x0006000c,
0x00000000,
0xd4200000,
0x00000000,
0x00010001,
0x00080000,
0x00000000,
0x00100000,
0x00000000,
0x00100000,
0x00000000,
0x00010000,
0xf84002a0,
0x00110000,
0x000f0003,
0x00000000,
0xfc4002a0,
0x00110000,
0x000f0003,
0x00000000,
0xf80002a0,
0x00110000,
0x000f0003,
0x00000000,
0xfc0002a0,
0x00110000,
0x000f0003,
0x00000000,
0xaa0003e0,
0x00110000,
0x00110010,
0x00000000,
0x9e660000,
0x00110000,
0x00110005,
0x00000000,
0x1e604000,
0x00110000,
0x00110005,
0x00000000,
0x9e670000,
0x00110000,
0x00110005,
0x00000000,
0xf840026e,
0x000f0003,
0xf84001ce,
0x000f0003,
0xb400000e,
0x00050814,
0x00000000,
0x00010001,
0x0006000f,
0x00000000,
0x00100000,
0x00000000,
0x00100000,
0x00000000,
0x00010000,
0xf840026a,
0x000f0003,
0xf940014a,
0xf840026d,
0x000f0003,
0xf80001aa,
0x000f0003,
0x00000000,
0x5280000a,
0x000a0205,
0x380001aa,
0x000f0000,
0x00000000,
0xf80001bf,
0x000f0003,
0x00000000,
0x910002aa,
0x000c0000,
0xf80001aa,
0x000f0003,
0x00000000,
0xd10083ff,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x5800000e,
0x00050810,
0xf90003ee,
0xf840026e,
0x000f0003,
0xf94001ce,
0xf90007ee,
0x1000000e,
0x0005200f,
0xf9000bee,
0x00000000,
0xaa1303e0,
0xf84002a1,
0x000f0003,
0x910003e2,
0x52800003,
0x000a0205,
0x00000000,
0x00010001,
0x00060011,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x00050811,
0xd63f0200,
0x910083ff,
0x00000000,
0x00010001,
0x0006000f,
0x00000000,
0x00100000,
0x00000000,
0x00100000,
0x00000000,
0x00010000,
0xf840026a,
0x000f0003,
0xf940014a,
0xf840026d,
0x000f0003,
0xf80001aa,
0x000f0003,
0x00000000,
0x5280000a,
0x000a0205,
0x380001aa,
0x000f0000,
0x00000000,
0xf80001bf,
0x000f0003,
0x00000000,
0x910002aa,
0x000c0000,
0xf80001aa,
0x000f0003,
0x00000000,
0xd10083ff,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x5800000e,
0x00050810,
0xf90003ee,
0xf840026e,
0x000f0003,
0xf94001ce,
0xf90007ee,
0x1000000e,
0x0005200f,
0xf9000bee,
0x00000000,
0xaa1303e0,
0x910003e1,
0x00000000,
0x00010001,
0x00060011,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x00050811,
0xd63f0200,
0x00000000,
0xf84002b0,
0x000f0003,
0xf8400210,
0x000f0003,
0xd63f0200,
0x00000000,
0x910083ff,
0x00000000,
0xf840026a,
0x000f0003,
0xf940014a,
0xf840026d,
0x000f0003,
0xf80001aa,
0x000f0003,
0x00000000,
0x5280000a,
0x000a0205,
0x380001aa,
0x000f0000,
0x00000000,
0xf80001bf,
0x000f0003,
0x00000000,
0x910002aa,
0x000c0000,
0xf80001aa,
0x000f0003,
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
0x93401c00,
0x00000000,
0x93403c00,
0x00000000,
0x93407c00,
0x00000000,
0x92401c00,
0x00000000,
0x92403c00,
0x00000000,
0x92407c00,
0x00000000,
0x92407c00,
0x00000000,
0xf80002a0,
0x000f0003,
0x00000000,
0x00010001,
0x0006000f,
0x00000000,
0x00100000,
0x00000000,
0x00100000,
0x00000000,
0x00010000,
0xf840026a,
0x000f0003,
0xf940014a,
0xf840026d,
0x000f0003,
0xf80001aa,
0x000f0003,
0x00000000,
0x5280000a,
0x000a0205,
0x380001aa,
0x000f0000,
0x00000000,
0xf80001bf,
0x000f0003,
0x00000000,
0x910002aa,
0x000c0000,
0xf80001aa,
0x000f0003,
0x00000000,
0xaa1303e0,
0xf840026e,
0x000f0003,
0xf84001ce,
0x000f0003,
0xf84001ce,
0x000f0003,
0xf84001c1,
0x000f0003,
0x00010001,
0x00060012,
0x00100000,
0x00100000,
0x00010000,
0x5800000b,
0x00050812,
0x8b0b0021,
0xf9400022,
0x00000000,
0xf8400283,
0x000f0003,
0xf8400063,
0x000f0003,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x58000004,
0x00050810,
0x10000005,
0x0005200f,
0xaa1503e6,
0xaa0e03e7,
0x00000000,
0xd10043ff,
0xb20003e9,
0x000e0000,
0xf90003e9,
0x00000000,
0xf8400050,
0x000f0003,
0xd63f0200,
0x910043ff,
0x00000000,
0xaa1303e0,
0xf84002a1,
0x000f0003,
0xf84002a2,
0x000f0003,
0x910002a3,
0x000c0000,
0x00010001,
0x0006000f,
0x00100000,
0x00100000,
0x00010000,
0x58000010,
0x0005080f,
0xd63f0200,
0x00000000,
0xb5000000,
0x00070800,
0x00000000,
0x00010001,
0x0006000f,
0x00000000,
0x00100000,
0x00000000,
0x00010000,
0xf840026a,
0x000f0003,
0xf940014a,
0xf840026d,
0x000f0003,
0xf80001aa,
0x000f0003,
0x5280000a,
0x000a0205,
0x380001aa,
0x000f0000,
0x910002aa,
0x000c0000,
0xf80001aa,
0x000f0003,
0x00000000,
0xaa1303e0,
0xf840026e,
0x000f0003,
0xf84001ce,
0x000f0003,
0xf84001ce,
0x000f0003,
0xf84001c1,
0x000f0003,
0x00010001,
0x00060012,
0x00100000,
0x00100000,
0x00010000,
0x5800000b,
0x00050812,
0x8b0b0021,
0xf9400022,
0x00000000,
0x00010001,
0x00060010,
0x00100000,
0x00100000,
0x00010000,
0x58000003,
0x00050810,
0xf9400063,
0x00000000,
0x00010001,
0x00060011,
0x00100000,
0x00100000,
0x00010000,
0x58000004,
0x00050811,
0x10000005,
0x0005200f,
0xaa1503e6,
0xaa0e03e7,
0x00000000,
0xd10043ff,
0xb20003e9,
0x000e0000,
0xf90003e9,
0xf8400050,
0x000f0003,
0xd63f0200,
0x910043ff,
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
//|.type CODE,       MVMCode
#define DtD(_V) (int)(ptrdiff_t)&(((MVMCode *)0)_V)
#line 26 "src/jit/arm64/emit.dasc"
//|.type CFUNCTION,  MVMCFunction
#define DtE(_V) (int)(ptrdiff_t)&(((MVMCFunction *)0)_V)
#line 27 "src/jit/arm64/emit.dasc"
//|.type REPR,       MVMREPROps
#define DtF(_V) (int)(ptrdiff_t)&(((MVMREPROps *)0)_V)
#line 28 "src/jit/arm64/emit.dasc"
//|.type MVMDISPINLINECACHE, MVMDispInlineCache
#define Dt10(_V) (int)(ptrdiff_t)&(((MVMDispInlineCache *)0)_V)
#line 29 "src/jit/arm64/emit.dasc"
//|.type MVMDISPINLINECACHEENTRY, MVMDispInlineCacheEntry
#define Dt11(_V) (int)(ptrdiff_t)&(((MVMDispInlineCacheEntry *)0)_V)
#line 30 "src/jit/arm64/emit.dasc"

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

/* Test if an object is a type object (non-concrete).
 * After this macro, NZCV is set: b.ne if type object, b.eq if concrete. */
//|.macro test_type_object, reg
//| ldrb w15, OBJECT:reg->header.flags1
//| tst x15, #MVM_CF_TYPE_OBJECT
//|.endmacro

//|.macro get_stable, out, in
//| ldr out, OBJECT:in->st
//|.endmacro

//|.macro get_repr, out, in
//| get_stable out, in
//| ldr out, STABLE:out->REPR
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
 *   [sp+ 8]: x30 (saved LR  — outer return address, restored by epilogue)
 *   [sp+16]: x19 (saved TC caller value)
 *   [sp+24]: x20 (saved CU caller value)
 *   [sp+32]: x21 (saved WORK caller value)
 *   [sp+40]: scratch copy of LR for jit_return_address
 *   [sp+48..79]: available for spills / C call stack args
 *
 * Trampoline: tc->jit_return_address points to [sp+40].
 * MVM_jit_code_trampoline may overwrite [sp+40] with exit_label and set
 * jit_return_address=NULL. The epilogue restores LR from [sp+8] (untouched),
 * so the trampoline redirect only affects what the caller finds in [sp+40].
 * ----------------------------------------------------------------------- */
void MVM_jit_emit_prologue(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg) {
    //|.code
    dasm_put(Dst, 0);
#line 157 "src/jit/arm64/emit.dasc"
    //| stp x29, x30, [sp, #-80]!
    //| mov x29, sp
    //| stp x19, x20, [sp, #16]
    //| str x21, [sp, #32]
    dasm_put(Dst, 1);
#line 161 "src/jit/arm64/emit.dasc"
    /* Load interpreter state from arguments */
    //| mov x19, ARG1
    //| mov x20, ARG2
    //| ldr TMP1, TC->cur_frame
    //| ldr x21, FRAME:TMP1->work
    dasm_put(Dst, 6, Dt1(->cur_frame), Dt4(->work));
#line 166 "src/jit/arm64/emit.dasc"
    /* Trampoline: save outer LR copy to [sp+40]; point jit_return_address there */
    if (!jg->no_trampoline) {
        //| str x30, [sp, #40]
        //| add TMP1, sp, #40
        //| str TMP1, TC->jit_return_address
        dasm_put(Dst, 13, Dt1(->jit_return_address));
#line 171 "src/jit/arm64/emit.dasc"
    }
    /* Jump to the continuation label supplied by the caller */
    //| br ARG3
    dasm_put(Dst, 18);
#line 174 "src/jit/arm64/emit.dasc"
}

/* ---- Epilogue ------------------------------------------------------------
 * The ->exit global label is the single exit point for all JIT code.
 * Clears jit_return_address, restores callee-saved registers and
 * returns to the C caller via the original saved LR at [sp+8].
 * ----------------------------------------------------------------------- */
void MVM_jit_emit_epilogue(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg) {
    //| ->exit:
    dasm_put(Dst, 20);
#line 184 "src/jit/arm64/emit.dasc"
    if (!jg->no_trampoline) {
        //| str xzr, TC->jit_return_address
        dasm_put(Dst, 22, Dt1(->jit_return_address));
#line 186 "src/jit/arm64/emit.dasc"
    }
    //| ldr x21, [sp, #32]
    //| ldp x19, x20, [sp, #16]
    //| ldp x29, x30, [sp], #80
    //| ret
    dasm_put(Dst, 25);
#line 191 "src/jit/arm64/emit.dasc"
}

/* ---- Labels and branches ------------------------------------------------ */

void MVM_jit_emit_label(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitGraph *jg, MVMint32 label) {
    //| =>(label):
    dasm_put(Dst, 30, (label));
#line 198 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMint32 label) {
    //| b =>(label)
    dasm_put(Dst, 32, (label));
#line 203 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_block_branch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMJitGraph *jg, MVMJitBranch *branch) {
    MVMSpeshIns *ins  = branch->ins;
    MVMint32     name = branch->dest;
    //| gc_sync_point
    dasm_put(Dst, 35, Dt1(->gc_status));
    dasm_put(Dst, 41, (unsigned int)((uintptr_t)(&MVM_gc_enter_from_interrupt)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_gc_enter_from_interrupt))>>32));
    dasm_put(Dst, 45);
#line 210 "src/jit/arm64/emit.dasc"
    if (ins == NULL || ins->info->opcode == MVM_OP_goto) {
        if (name == MVM_JIT_BRANCH_EXIT) {
            //| b ->exit
            dasm_put(Dst, 50);
#line 213 "src/jit/arm64/emit.dasc"
        } else {
            //| b =>(name)
            dasm_put(Dst, 53, (name));
#line 215 "src/jit/arm64/emit.dasc"
        }
    } else {
        MVM_oops(tc, "ARM64 JIT: conditional block branch not yet implemented");
    }
}

void MVM_jit_emit_all_bb_jumps(MVMThreadContext *tc, MVMJitCompiler *compiler,
                               MVMint32 name) {
    MVMuint32 bbidx;
    //| b >1
    dasm_put(Dst, 56);
#line 225 "src/jit/arm64/emit.dasc"
    for (bbidx = 0; bbidx < compiler->graph->sg->num_bbs; bbidx++) {
        //| b =>(bbidx)
        dasm_put(Dst, 59, (bbidx));
#line 227 "src/jit/arm64/emit.dasc"
    }
    //|1:
    dasm_put(Dst, 62);
#line 229 "src/jit/arm64/emit.dasc"
}

/* ---- emit_call_c helpers ------------------------------------------------ */

static void load_call_arg(MVMThreadContext *tc, MVMJitCompiler *compiler,
                          MVMJitGraph *jg, MVMJitCallArg arg) {
    switch (arg.type) {
    case MVM_JIT_INTERP_VAR:
        switch (arg.v.ivar) {
        case MVM_JIT_INTERP_TC:
            //| mov TMP6, x19
            dasm_put(Dst, 64);
#line 240 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_CU:
            //| mov TMP6, x20
            dasm_put(Dst, 66);
#line 243 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_FRAME:
            //| ldr TMP6, TC->cur_frame
            dasm_put(Dst, 68, Dt1(->cur_frame));
#line 246 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_PARAMS:
            //| ldr TMP6, TC->cur_frame
            //| add TMP6, TMP6, #offsetof(MVMFrame, params)
            dasm_put(Dst, 71, Dt1(->cur_frame), offsetof(MVMFrame, params));
#line 250 "src/jit/arm64/emit.dasc"
            break;
        case MVM_JIT_INTERP_CALLER:
            //| ldr TMP6, TC->cur_frame
            //| ldr TMP6, FRAME:TMP6->caller
            dasm_put(Dst, 76, Dt1(->cur_frame), Dt4(->caller));
#line 254 "src/jit/arm64/emit.dasc"
            break;
        }
        break;
    case MVM_JIT_REG_VAL:
    case MVM_JIT_REG_VAL_F: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 81, offset);
#line 261 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_ADDR: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| add TMP6, x21, #offset
        dasm_put(Dst, 84, offset);
#line 266 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_STR_IDX:
        //| get_string TMP6, arg.v.lit_i64
         MVM_cu_ensure_string_decoded(tc, jg->sg->sf->body.cu, arg.v.lit_i64);
        dasm_put(Dst, 87, Dt3(->body.strings), ((arg.v.lit_i64)*8));
#line 270 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_LITERAL:
    case MVM_JIT_LITERAL_64:
    case MVM_JIT_LITERAL_PTR:
    case MVM_JIT_LITERAL_F:
        //| .data
        dasm_put(Dst, 92);
#line 276 "src/jit/arm64/emit.dasc"
        //| 6:
        //| .quad (uintptr_t)(arg.v.lit_i64)
        //| .code
        dasm_put(Dst, 93, (unsigned int)((uintptr_t)(arg.v.lit_i64)), (unsigned int)((unsigned long long)((uintptr_t)(arg.v.lit_i64))>>32));
#line 279 "src/jit/arm64/emit.dasc"
        //| ldr TMP6, <6
        dasm_put(Dst, 97);
#line 280 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_REG_STABLE: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, OBJECT:TMP6->st
        dasm_put(Dst, 100, offset, Dt5(->st));
#line 285 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_OBJBODY: {
        MVMint32 offset = arg.v.reg * sizeof(MVMRegister);
        //| ldr TMP6, [x21, #offset]
        //| add TMP6, TMP6, #offsetof(MVMObjectStooge, data)
        dasm_put(Dst, 105, offset, offsetof(MVMObjectStooge, data));
#line 291 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_REG_DYNIDX:
        //| get_cur_op TMP6
        //| ldrh w14, [x14, #(arg.v.reg * 2)]
        //| ldr x14, [x21, x14, lsl #3]
        dasm_put(Dst, 110, Dt1(->interp_cur_op), (arg.v.reg * 2));
#line 297 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_DATA_LABEL:
        //| adr TMP6, =>(arg.v.lit_i64)
        dasm_put(Dst, 117, (arg.v.lit_i64));
#line 300 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_ARG_I64:
    case MVM_JIT_PARAM_I64: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 120, offset);
#line 305 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_I64_RW:
    case MVM_JIT_PARAM_I64_RW: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| add TMP6, x21, #offset
        dasm_put(Dst, 123, offset);
#line 311 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_DOUBLE:
    case MVM_JIT_PARAM_DOUBLE: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        dasm_put(Dst, 126, offset);
#line 317 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_PTR:
    case MVM_JIT_PARAM_PTR: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, STOOGE:TMP6->data
        dasm_put(Dst, 129, offset, Dt7(->data));
#line 324 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_ARG_VMARRAY:
    case MVM_JIT_PARAM_VMARRAY: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, VMARRAY:TMP6->body.slots
        dasm_put(Dst, 134, offset, Dt8(->body.slots));
#line 331 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_PARAM_CARRAY: {
        MVMint32 offset = (MVMint32)(arg.v.lit_i64 * sizeof(MVMRegister));
        //| ldr TMP6, [x21, #offset]
        //| ldr TMP6, CARRAY:TMP6->body.storage
        dasm_put(Dst, 139, offset, Dt9(->body.storage));
#line 337 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_SPESH_SLOT_VALUE:
        //| get_spesh_slot TMP6, arg.v.lit_i64
        dasm_put(Dst, 144, Dt1(->cur_frame), Dt4(->effective_spesh_slots), ((arg.v.lit_i64)*8));
#line 341 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_STACK_VALUE: {
        MVMint32 offset = 40 + (MVMint32)(arg.v.lit_i64 * 8);
        //| ldr TMP6, [x29, #offset]
        dasm_put(Dst, 151, offset);
#line 345 "src/jit/arm64/emit.dasc"
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
        dasm_put(Dst, 154);
#line 356 "src/jit/arm64/emit.dasc"
        break;
    case 1:
        //| mov ARG2, TMP6
        dasm_put(Dst, 156);
#line 359 "src/jit/arm64/emit.dasc"
        break;
    case 2:
        //| mov ARG3, TMP6
        dasm_put(Dst, 158);
#line 362 "src/jit/arm64/emit.dasc"
        break;
    case 3:
        //| mov ARG4, TMP6
        dasm_put(Dst, 160);
#line 365 "src/jit/arm64/emit.dasc"
        break;
    case 4:
        //| mov ARG5, TMP6
        dasm_put(Dst, 162);
#line 368 "src/jit/arm64/emit.dasc"
        break;
    case 5:
        //| mov ARG6, TMP6
        dasm_put(Dst, 164);
#line 371 "src/jit/arm64/emit.dasc"
        break;
    case 6:
        //| mov x6, TMP6
        dasm_put(Dst, 166);
#line 374 "src/jit/arm64/emit.dasc"
        break;
    case 7:
        //| mov x7, TMP6
        dasm_put(Dst, 168);
#line 377 "src/jit/arm64/emit.dasc"
        break;
    default:
        MVM_oops(tc, "ARM64 JIT: too many GPR call args (%d)", i);
    }
}

static void emit_fpr_arg(MVMThreadContext *tc, MVMJitCompiler *compiler, MVMint32 i) {
    switch (i) {
    case 0:
        //| fmov d0, x14
        dasm_put(Dst, 170);
#line 387 "src/jit/arm64/emit.dasc"
        break;
    case 1:
        //| fmov d1, x14
        dasm_put(Dst, 172);
#line 390 "src/jit/arm64/emit.dasc"
        break;
    case 2:
        //| fmov d2, x14
        dasm_put(Dst, 174);
#line 393 "src/jit/arm64/emit.dasc"
        break;
    case 3:
        //| fmov d3, x14
        dasm_put(Dst, 176);
#line 396 "src/jit/arm64/emit.dasc"
        break;
    case 4:
        //| fmov d4, x14
        dasm_put(Dst, 178);
#line 399 "src/jit/arm64/emit.dasc"
        break;
    case 5:
        //| fmov d5, x14
        dasm_put(Dst, 180);
#line 402 "src/jit/arm64/emit.dasc"
        break;
    case 6:
        //| fmov d6, x14
        dasm_put(Dst, 182);
#line 405 "src/jit/arm64/emit.dasc"
        break;
    case 7:
        //| fmov d7, x14
        dasm_put(Dst, 184);
#line 408 "src/jit/arm64/emit.dasc"
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

/* ARM64 register class helpers.
 * X0-X30 (0-30) are GPRs; V0-V31 (31-62) are FP registers. */
#define ARM64_IS_GPR(x) ((unsigned)(x) < 31u)
#define ARM64_IS_FPR(x) ((unsigned)(x) >= 31u)
#define ARM64_GPR_NUM(x) ((x))
#define ARM64_FPR_NUM(x) ((x) - 31)

/* ---- Stubs for unimplemented emitters ----------------------------------- */

void MVM_jit_emit_primitive(MVMThreadContext *tc, MVMJitCompiler *compiler,
                            MVMJitGraph *jg, MVMJitPrimitive *prim) {
    MVM_oops(tc, "ARM64 JIT: emit_primitive not yet implemented");
}

void MVM_jit_emit_call_c(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMJitGraph *jg, MVMJitCallC *call_spec) {
    emit_arm64_callargs(tc, compiler, jg, call_spec->args, call_spec->num_args);
    //| callp call_spec->func_ptr
    dasm_put(Dst, 186);
    dasm_put(Dst, 187, (unsigned int)((uintptr_t)(call_spec->func_ptr)), (unsigned int)((unsigned long long)((uintptr_t)(call_spec->func_ptr))>>32));
    dasm_put(Dst, 191);
#line 486 "src/jit/arm64/emit.dasc"

    switch (call_spec->rv_mode) {
    case MVM_JIT_RV_VOID:
        break;
    case MVM_JIT_RV_INT:
    case MVM_JIT_RV_PTR: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| str RV, [x21, #offset]
        dasm_put(Dst, 195, offset);
#line 494 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_INT_NEGATED: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| cmp RV, #0
        //| cset TMP2, eq
        //| str TMP2, [x21, #offset]
        dasm_put(Dst, 198, offset);
#line 501 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_NUM: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| str d0, [x21, #offset]
        dasm_put(Dst, 203, offset);
#line 506 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_DEREF: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| ldr TMP1, [RV]
        //| str TMP1, [x21, #offset]
        dasm_put(Dst, 206, offset);
#line 512 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_ADDR: {
        MVMint32 offset = call_spec->rv_idx * (MVMint32)sizeof(MVMRegister);
        //| ldr TMP1, [x21, #offset]
        //| str TMP1, [RV]
        dasm_put(Dst, 210, offset);
#line 518 "src/jit/arm64/emit.dasc"
        break;
    }
    case MVM_JIT_RV_DYNIDX:
        /* cur_op holds a u16 reg index at position rv_idx */
        //| get_cur_op TMP2
        //| ldrh w10, [x10, #(call_spec->rv_idx * 2)]
        //| str RV, [x21, x10, lsl #3]
        dasm_put(Dst, 214, Dt1(->interp_cur_op), (call_spec->rv_idx * 2));
#line 525 "src/jit/arm64/emit.dasc"
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
        dasm_put(Dst, 221, Dt1(->instance), DtA(->VMNull), offset);
#line 535 "src/jit/arm64/emit.dasc"
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
    MVMint32 is_float = (test_type == MVM_reg_num32 || test_type == MVM_reg_num64);
    /* ARM64 condition codes after CMP (integer) or FCMP (float).
     * For FCMP, NaN produces N=0 Z=0 C=1 V=1; most conditions naturally
     * exclude NaN except NE which includes it (matching x64 behaviour). */
    switch (cond) {
    case MVM_JIT_LT:
        if (is_float) {
            /* MI: N=1, which is false for NaN (N=0 after FCMP on NaN) */
            //| bmi =>(label)
            dasm_put(Dst, 235, (label));
#line 555 "src/jit/arm64/emit.dasc"
        } else {
            //| blt =>(label)
            dasm_put(Dst, 238, (label));
#line 557 "src/jit/arm64/emit.dasc"
        }
        break;
    case MVM_JIT_LE:
        if (is_float) {
            /* LS: C=0 or Z=1, false for NaN (C=1, Z=0) */
            //| bls =>(label)
            dasm_put(Dst, 241, (label));
#line 563 "src/jit/arm64/emit.dasc"
        } else {
            //| ble =>(label)
            dasm_put(Dst, 244, (label));
#line 565 "src/jit/arm64/emit.dasc"
        }
        break;
    case MVM_JIT_EQ:
        //| beq =>(label)
        dasm_put(Dst, 247, (label));
#line 569 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_NE:
        /* NE: Z=0; NaN also has Z=0 so NaN branches — same as x64 (jp | jne) */
        //| bne =>(label)
        dasm_put(Dst, 250, (label));
#line 573 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_GE:
        /* GE: N=V; for FCMP: NaN has N=0,V=1 so N!=V -> false. Safe. */
        //| bge =>(label)
        dasm_put(Dst, 253, (label));
#line 577 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_GT:
        /* GT: Z=0 and N=V; NaN: N!=V -> false. Safe. */
        //| bgt =>(label)
        dasm_put(Dst, 256, (label));
#line 581 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_NZ:
        /* NE: Z=0; NaN has Z=0 so branches (NaN is non-zero) */
        //| bne =>(label)
        dasm_put(Dst, 259, (label));
#line 585 "src/jit/arm64/emit.dasc"
        break;
    case MVM_JIT_ZR:
        /* EQ: Z=1; NaN has Z=0 so does NOT branch. Safe. */
        //| beq =>(label)
        dasm_put(Dst, 262, (label));
#line 589 "src/jit/arm64/emit.dasc"
        break;
    default:
        abort();
    }
}

void MVM_jit_emit_guard(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitGraph *jg, MVMJitGuard *guard) {
    MVMint16 op  = guard->ins->info->opcode;
    MVMint16 obj = guard->ins->operands[op == MVM_OP_sp_guardsf ? 0 : 1].reg.orig;
    MVMint32 obj_off = obj * (MVMint32)sizeof(MVMRegister);

    /* Load object into TMP1 */
    //| ldr TMP1, [x21, #obj_off]
    dasm_put(Dst, 265, obj_off);
#line 603 "src/jit/arm64/emit.dasc"

    /* Load spesh slot value into TMP2 (not needed for some ops) */
    if (op != MVM_OP_sp_guardjustconc && op != MVM_OP_sp_guardjusttype &&
            op != MVM_OP_sp_guardnonzero && op != MVM_OP_sp_guardhll &&
                op != MVM_OP_sp_rebless) {
        MVMint16 spesh_idx = guard->ins->operands[op == MVM_OP_sp_guardsf ? 1 : 2].lit_i16;
        //| get_spesh_slot TMP2, spesh_idx
        dasm_put(Dst, 268, Dt1(->cur_frame), Dt4(->effective_spesh_slots), ((spesh_idx)*8));
#line 610 "src/jit/arm64/emit.dasc"
    }

    if (op == MVM_OP_sp_guard) {
        //| cbz TMP1, >1
        //| ldr TMP3, OBJECT:TMP1->st
        //| cmp TMP2, TMP3
        //| bne >1
        dasm_put(Dst, 275, Dt5(->st));
#line 617 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardtype) {
        //| cbz TMP1, >1
        //| test_type_object TMP1
        //| beq >1
        //| ldr TMP3, OBJECT:TMP1->st
        //| cmp TMP2, TMP3
        //| bne >1
        dasm_put(Dst, 283, Dt5(->header.flags1), (unsigned int)(MVM_CF_TYPE_OBJECT), (unsigned int)((unsigned long long)(MVM_CF_TYPE_OBJECT)>>32), Dt5(->st));
#line 624 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardconc) {
        //| cbz TMP1, >1
        //| test_type_object TMP1
        //| bne >1
        //| ldr TMP3, OBJECT:TMP1->st
        //| cmp TMP2, TMP3
        //| bne >1
        dasm_put(Dst, 297, Dt5(->header.flags1), (unsigned int)(MVM_CF_TYPE_OBJECT), (unsigned int)((unsigned long long)(MVM_CF_TYPE_OBJECT)>>32), Dt5(->st));
#line 631 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardhll) {
        MVMuint64 hll_val = guard->ins->operands[2].lit_ui64;
        //| .data
        dasm_put(Dst, 311);
#line 634 "src/jit/arm64/emit.dasc"
        //| 6:
        //| .quad hll_val
        //| .code
        dasm_put(Dst, 312, (unsigned int)(hll_val), (unsigned int)((unsigned long long)(hll_val)>>32));
#line 637 "src/jit/arm64/emit.dasc"
        //| ldr TMP2, <6
        //| ldr TMP3, OBJECT:TMP1->st
        //| ldr TMP4, STABLE:TMP3->hll_owner
        //| cmp TMP2, TMP4
        //| bne >1
        dasm_put(Dst, 316, Dt5(->st), Dt6(->hll_owner));
#line 642 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardsf) {
        //| ldr TMP3, CODE:TMP1->body.sf
        //| cmp TMP2, TMP3
        //| bne >1
        dasm_put(Dst, 326, DtD(->body.sf));
#line 646 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardobj) {
        //| cmp TMP2, TMP1
        //| bne >1
        dasm_put(Dst, 332);
#line 649 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardnonzero) {
        //| cbz TMP1, >1
        dasm_put(Dst, 336);
#line 651 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardnotobj) {
        //| cmp TMP2, TMP1
        //| beq >1
        dasm_put(Dst, 339);
#line 654 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardjustconc) {
        //| cbz TMP1, >1
        //| test_type_object TMP1
        //| bne >1
        dasm_put(Dst, 343, Dt5(->header.flags1), (unsigned int)(MVM_CF_TYPE_OBJECT), (unsigned int)((unsigned long long)(MVM_CF_TYPE_OBJECT)>>32));
#line 658 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_guardjusttype) {
        //| cbz TMP1, >1
        //| test_type_object TMP1
        //| beq >1
        dasm_put(Dst, 352, Dt5(->header.flags1), (unsigned int)(MVM_CF_TYPE_OBJECT), (unsigned int)((unsigned long long)(MVM_CF_TYPE_OBJECT)>>32));
#line 662 "src/jit/arm64/emit.dasc"
    } else if (op == MVM_OP_sp_rebless) {
        MVM_oops(tc, "ARM64 JIT: sp_rebless guard not yet implemented");
    }

    /* Guard passed: optionally copy result to destination register */
    if (op != MVM_OP_sp_guardsf) {
        MVMint16 dest = guard->ins->operands[0].reg.orig;
        if (dest != obj) {
            MVMint32 dst_off = dest * (MVMint32)sizeof(MVMRegister);
            //| str TMP1, [x21, #dst_off]
            dasm_put(Dst, 361, dst_off);
#line 672 "src/jit/arm64/emit.dasc"
        }
    }
    //| b >2
    //|1:
    dasm_put(Dst, 364);
#line 676 "src/jit/arm64/emit.dasc"
    /* Deopt path */
    //| mov ARG1, x19
    //| mov ARG2, #guard->deopt_idx
    //| callp &MVM_spesh_deopt_one
    dasm_put(Dst, 368, guard->deopt_idx);
    dasm_put(Dst, 372, (unsigned int)((uintptr_t)(&MVM_spesh_deopt_one)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_spesh_deopt_one))>>32));
#line 680 "src/jit/arm64/emit.dasc"
    //| b ->exit
    //|2:
    dasm_put(Dst, 376);
#line 682 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_jumplist(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitJumpList *jumplist) {
    MVMint32 i;
    MVMint32 reg_off = jumplist->reg * (MVMint32)sizeof(MVMRegister);
    //| ldr TMP1, [x21, #reg_off]
    //| cmp TMP1, #0
    //| blt >2
    //| cmp TMP1, #jumplist->num_labels
    //| bge >2
    dasm_put(Dst, 383, reg_off, jumplist->num_labels);
#line 693 "src/jit/arm64/emit.dasc"
    /* Compute jump: each entry is one b-instruction = 4 bytes */
    //| lsl TMP2, TMP1, #2
    //| adr TMP3, >1
    //| add TMP2, TMP3, TMP2
    //| br TMP2
    //|.align 4
    //|1:
    dasm_put(Dst, 393);
#line 700 "src/jit/arm64/emit.dasc"
    for (i = 0; i < jumplist->num_labels; i++) {
        //|=>(jumplist->in_labels[i]):
        //| b =>(jumplist->out_labels[i])
        dasm_put(Dst, 401, (jumplist->in_labels[i]), (jumplist->out_labels[i]));
#line 703 "src/jit/arm64/emit.dasc"
    }
    //|2:
    dasm_put(Dst, 405);
#line 705 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_control(MVMThreadContext *tc, MVMJitCompiler *compiler,
                          MVMJitControl *ctrl, MVMJitTile *tile) {
    MVMJitControlType type = (tile != NULL ? (MVMJitControlType)tile->args[0] : ctrl->type);
    if (type == MVM_JIT_CONTROL_BREAKPOINT) {
        //| brk #0
        dasm_put(Dst, 407);
#line 712 "src/jit/arm64/emit.dasc"
    } else {
        MVM_panic(1, "ARM64 JIT: unknown control code: <%s>", ctrl->ins->info->name);
    }
}

void MVM_jit_emit_data(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMJitData *data) {
    MVMuint8 *bytes = (MVMuint8 *)data->data;
    size_t i;
    //| .data
    dasm_put(Dst, 409);
#line 722 "src/jit/arm64/emit.dasc"
    //| =>(data->label):
    dasm_put(Dst, 410, (data->label));
#line 723 "src/jit/arm64/emit.dasc"
    for (i = 0; i + 4 <= data->size; i += 4) {
        MVMuint32 packed = (MVMuint32)bytes[i] | ((MVMuint32)bytes[i+1]<<8) | ((MVMuint32)bytes[i+2]<<16) | ((MVMuint32)bytes[i+3]<<24);
        //| .long packed
        dasm_put(Dst, 412, packed);
#line 726 "src/jit/arm64/emit.dasc"
    }
    if (i < data->size) {
        MVMuint32 tail = 0; size_t j;
        for (j = 0; j < data->size - i; j++) tail |= ((MVMuint32)bytes[i+j] << (j*8));
        //| .long tail
        dasm_put(Dst, 414, tail);
#line 731 "src/jit/arm64/emit.dasc"
    }
    //| .code
    dasm_put(Dst, 416);
#line 733 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_load(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMint8 reg_dst, MVMJitStorageClass mem_cls,
                       MVMint32 mem_src, MVMint32 size) {
    if (mem_cls == MVM_JIT_STORAGE_LOCAL) {
        if (ARM64_IS_GPR(reg_dst)) {
            //| ldr Rx(ARM64_GPR_NUM(reg_dst)), [x21, #mem_src]
            dasm_put(Dst, 417, (ARM64_GPR_NUM(reg_dst)), mem_src);
#line 741 "src/jit/arm64/emit.dasc"
        } else {
            //| ldr Rd(ARM64_FPR_NUM(reg_dst)), [x21, #mem_src]
            dasm_put(Dst, 421, (ARM64_FPR_NUM(reg_dst)), mem_src);
#line 743 "src/jit/arm64/emit.dasc"
        }
    } else {
        MVM_oops(tc, "ARM64 JIT: emit_load: unsupported storage class %d", mem_cls);
    }
}

void MVM_jit_emit_store(MVMThreadContext *tc, MVMJitCompiler *compiler,
                        MVMJitStorageClass mem_cls, MVMint32 mem_pos,
                        MVMint8 reg_src, MVMint32 size) {
    if (mem_cls == MVM_JIT_STORAGE_LOCAL) {
        if (ARM64_IS_GPR(reg_src)) {
            //| str Rx(ARM64_GPR_NUM(reg_src)), [x21, #mem_pos]
            dasm_put(Dst, 425, (ARM64_GPR_NUM(reg_src)), mem_pos);
#line 755 "src/jit/arm64/emit.dasc"
        } else {
            //| str Rd(ARM64_FPR_NUM(reg_src)), [x21, #mem_pos]
            dasm_put(Dst, 429, (ARM64_FPR_NUM(reg_src)), mem_pos);
#line 757 "src/jit/arm64/emit.dasc"
        }
    } else {
        MVM_oops(tc, "ARM64 JIT: emit_store: unsupported storage class %d", mem_cls);
    }
}

void MVM_jit_emit_copy(MVMThreadContext *tc, MVMJitCompiler *compiler,
                       MVMint8 dst_reg, MVMint8 src_reg) {
    if (ARM64_IS_GPR(dst_reg)) {
        if (ARM64_IS_GPR(src_reg)) {
            //| mov Rx(ARM64_GPR_NUM(dst_reg)), Rx(ARM64_GPR_NUM(src_reg))
            dasm_put(Dst, 433, (ARM64_GPR_NUM(dst_reg)), (ARM64_GPR_NUM(src_reg)));
#line 768 "src/jit/arm64/emit.dasc"
        } else {
            //| fmov Rx(ARM64_GPR_NUM(dst_reg)), Rd(ARM64_FPR_NUM(src_reg))
            dasm_put(Dst, 437, (ARM64_GPR_NUM(dst_reg)), (ARM64_FPR_NUM(src_reg)));
#line 770 "src/jit/arm64/emit.dasc"
        }
    } else {
        if (ARM64_IS_FPR(src_reg)) {
            //| fmov Rd(ARM64_FPR_NUM(dst_reg)), Rd(ARM64_FPR_NUM(src_reg))
            dasm_put(Dst, 441, (ARM64_FPR_NUM(dst_reg)), (ARM64_FPR_NUM(src_reg)));
#line 774 "src/jit/arm64/emit.dasc"
        } else {
            //| fmov Rd(ARM64_FPR_NUM(dst_reg)), Rx(ARM64_GPR_NUM(src_reg))
            dasm_put(Dst, 445, (ARM64_FPR_NUM(dst_reg)), (ARM64_GPR_NUM(src_reg)));
#line 776 "src/jit/arm64/emit.dasc"
        }
    }
}

void MVM_jit_emit_marker(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMint32 num) {
    /* no-op for now; used for debug markers */
}

void MVM_jit_emit_deopt_check(MVMThreadContext *tc, MVMJitCompiler *compiler) {
    //| ldr TMP6, TC->cur_frame
    //| ldr TMP6, FRAME:TMP6->spesh_cand
    //| cbz TMP6, ->exit
    dasm_put(Dst, 449, Dt1(->cur_frame), Dt4(->spesh_cand));
#line 789 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_runbytecode(MVMThreadContext *tc, MVMJitCompiler *compiler,
                              MVMJitGraph *jg, MVMJitRunByteCode *runcode) {
    MVMint16 i;
    MVMint32 code_off = runcode->code_register * (MVMint32)sizeof(MVMRegister);

    /* Store arg map in data section at label 5 */
    //| .data
    dasm_put(Dst, 456);
#line 798 "src/jit/arm64/emit.dasc"
    //|5:
    dasm_put(Dst, 457);
#line 799 "src/jit/arm64/emit.dasc"
    {
        MVMuint32 flag_count = runcode->callsite->flag_count;
        MVMuint32 fi;
        for (fi = 0; fi + 2 <= flag_count; fi += 2) {
            MVMuint32 packed = (MVMuint32)(MVMuint16)runcode->map[fi].reg.orig | ((MVMuint32)(MVMuint16)runcode->map[fi+1].reg.orig << 16);
            //| .long packed
            dasm_put(Dst, 459, packed);
#line 805 "src/jit/arm64/emit.dasc"
        }
        if (flag_count & 1) {
            MVMuint32 last = (MVMuint32)(MVMuint16)runcode->map[flag_count-1].reg.orig;
            //| .long last
            dasm_put(Dst, 461, last);
#line 809 "src/jit/arm64/emit.dasc"
        }
    }
    //| .code
    dasm_put(Dst, 463);
#line 812 "src/jit/arm64/emit.dasc"

    /* Set up frame return info */
    //| get_cur_op TMP2
    //| ldr TMP5, TC->cur_frame
    //| str TMP2, FRAME:TMP5->return_address
    dasm_put(Dst, 464, Dt1(->interp_cur_op), Dt1(->cur_frame), Dt4(->return_address));
#line 817 "src/jit/arm64/emit.dasc"
    if (sizeof(MVMReturnType) == 1) {
        //| mov TMP2, #runcode->return_type
        //| strb w10, FRAME:TMP5->return_type
        dasm_put(Dst, 472, runcode->return_type, Dt4(->return_type));
#line 820 "src/jit/arm64/emit.dasc"
    } else {
        MVM_panic(1, "JIT: MVMReturnType has unexpected size");
    }
    if (runcode->return_type == MVM_RETURN_VOID) {
        //| str xzr, FRAME:TMP5->return_value
        dasm_put(Dst, 477, Dt4(->return_value));
#line 825 "src/jit/arm64/emit.dasc"
    } else {
        MVMint32 rv_off = runcode->return_register * (MVMint32)sizeof(MVMRegister);
        //| add TMP2, x21, #rv_off
        //| str TMP2, FRAME:TMP5->return_value
        dasm_put(Dst, 480, rv_off, Dt4(->return_value));
#line 829 "src/jit/arm64/emit.dasc"
    }

    /* On AAPCS64 MVMArgs (24 bytes > 16) is passed by hidden pointer.
     * Allocate 32 bytes on stack (16-byte aligned), fill MVMArgs fields. */
    //| sub sp, sp, #32
    //| .data
    dasm_put(Dst, 485);
#line 835 "src/jit/arm64/emit.dasc"
    //| 6:
    //| .quad (uintptr_t)(runcode->callsite)
    //| .code
    dasm_put(Dst, 487, (unsigned int)((uintptr_t)(runcode->callsite)), (unsigned int)((unsigned long long)((uintptr_t)(runcode->callsite))>>32));
#line 838 "src/jit/arm64/emit.dasc"
    //| ldr TMP6, <6
    //| str TMP6, [sp]
    //| ldr TMP6, TC->interp_reg_base
    //| ldr TMP6, [TMP6]
    //| str TMP6, [sp, #8]
    //| adr TMP6, <5
    //| str TMP6, [sp, #16]
    dasm_put(Dst, 491, Dt1(->interp_reg_base));
#line 845 "src/jit/arm64/emit.dasc"

    //| mov ARG1, x19
    //| ldr ARG2, [x21, #code_off]
    //| mov ARG3, sp
    //| mov ARG4, #runcode->spesh_cand
    dasm_put(Dst, 502, code_off, runcode->spesh_cand);
#line 850 "src/jit/arm64/emit.dasc"

    /* Use label 7 for function pointer to avoid conflict with label 5 (arg map) */
    //| .data
    dasm_put(Dst, 509);
#line 853 "src/jit/arm64/emit.dasc"
    //| 7:
    //| .quad (uintptr_t)(&MVM_frame_dispatch)
    //| .code
    dasm_put(Dst, 510, (unsigned int)((uintptr_t)(&MVM_frame_dispatch)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_frame_dispatch))>>32));
#line 856 "src/jit/arm64/emit.dasc"
    //| ldr FUNCTION, <7
    //| blr FUNCTION
    //| add sp, sp, #32
    dasm_put(Dst, 514);
#line 859 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_runccode(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitRunCCode *runcode) {
    MVMint16 i;

    /* Store arg map at label 5 */
    //| .data
    dasm_put(Dst, 519);
#line 867 "src/jit/arm64/emit.dasc"
    //|5:
    dasm_put(Dst, 520);
#line 868 "src/jit/arm64/emit.dasc"
    {
        MVMuint32 flag_count = runcode->callsite->flag_count;
        MVMuint32 fi;
        for (fi = 0; fi + 2 <= flag_count; fi += 2) {
            MVMuint32 packed = (MVMuint32)(MVMuint16)runcode->map[fi].reg.orig | ((MVMuint32)(MVMuint16)runcode->map[fi+1].reg.orig << 16);
            //| .long packed
            dasm_put(Dst, 522, packed);
#line 874 "src/jit/arm64/emit.dasc"
        }
        if (flag_count & 1) {
            MVMuint32 last = (MVMuint32)(MVMuint16)runcode->map[flag_count-1].reg.orig;
            //| .long last
            dasm_put(Dst, 524, last);
#line 878 "src/jit/arm64/emit.dasc"
        }
    }
    //| .code
    dasm_put(Dst, 526);
#line 881 "src/jit/arm64/emit.dasc"

    /* Set up frame return info */
    //| get_cur_op TMP2
    //| ldr TMP5, TC->cur_frame
    //| str TMP2, FRAME:TMP5->return_address
    dasm_put(Dst, 527, Dt1(->interp_cur_op), Dt1(->cur_frame), Dt4(->return_address));
#line 886 "src/jit/arm64/emit.dasc"
    if (sizeof(MVMReturnType) == 1) {
        //| mov TMP2, #runcode->return_type
        //| strb w10, FRAME:TMP5->return_type
        dasm_put(Dst, 535, runcode->return_type, Dt4(->return_type));
#line 889 "src/jit/arm64/emit.dasc"
    } else {
        MVM_panic(1, "JIT: MVMReturnType has unexpected size");
    }
    if (runcode->return_type == MVM_RETURN_VOID) {
        //| str xzr, FRAME:TMP5->return_value
        dasm_put(Dst, 540, Dt4(->return_value));
#line 894 "src/jit/arm64/emit.dasc"
    } else {
        MVMint32 rv_off = runcode->return_register * (MVMint32)sizeof(MVMRegister);
        //| add TMP2, x21, #rv_off
        //| str TMP2, FRAME:TMP5->return_value
        dasm_put(Dst, 543, rv_off, Dt4(->return_value));
#line 898 "src/jit/arm64/emit.dasc"
    }

    /* Build MVMArgs on stack (AAPCS64: struct > 16 bytes passed by pointer) */
    //| sub sp, sp, #32
    //| .data
    dasm_put(Dst, 548);
#line 903 "src/jit/arm64/emit.dasc"
    //| 6:
    //| .quad (uintptr_t)(runcode->callsite)
    //| .code
    dasm_put(Dst, 550, (unsigned int)((uintptr_t)(runcode->callsite)), (unsigned int)((unsigned long long)((uintptr_t)(runcode->callsite))>>32));
#line 906 "src/jit/arm64/emit.dasc"
    //| ldr TMP6, <6
    //| str TMP6, [sp]
    //| ldr TMP6, TC->interp_reg_base
    //| ldr TMP6, [TMP6]
    //| str TMP6, [sp, #8]
    //| adr TMP6, <5
    //| str TMP6, [sp, #16]
    dasm_put(Dst, 554, Dt1(->interp_reg_base));
#line 913 "src/jit/arm64/emit.dasc"

    //| mov ARG1, x19
    //| mov ARG2, sp
    dasm_put(Dst, 565);
#line 916 "src/jit/arm64/emit.dasc"

    MVMSpeshFacts *function_facts =
        MVM_spesh_get_facts(tc, jg->sg, runcode->code_operand);
    if ((function_facts->flags & MVM_SPESH_FACT_KNOWN_VALUE) && function_facts->value.o) {
        uintptr_t call_target =
            (uintptr_t)(((MVMCFunction *)function_facts->value.o)->body.func);
        //| .data
        dasm_put(Dst, 568);
#line 923 "src/jit/arm64/emit.dasc"
        //| 7:
        //| .quad call_target
        //| .code
        dasm_put(Dst, 569, (unsigned int)(call_target), (unsigned int)((unsigned long long)(call_target)>>32));
#line 926 "src/jit/arm64/emit.dasc"
        //| ldr FUNCTION, <7
        //| blr FUNCTION
        dasm_put(Dst, 573);
#line 928 "src/jit/arm64/emit.dasc"
    } else {
        MVMint32 code_op_off = runcode->code_operand.reg.orig * (MVMint32)sizeof(MVMRegister);
        //| ldr FUNCTION, [x21, #code_op_off]
        //| ldr FUNCTION, CFUNCTION:FUNCTION->body.func
        //| blr FUNCTION
        dasm_put(Dst, 577, code_op_off, DtE(->body.func));
#line 933 "src/jit/arm64/emit.dasc"
    }
    //| add sp, sp, #32
    dasm_put(Dst, 583);
#line 935 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_runnativecall(MVMThreadContext *tc, MVMJitCompiler *compiler,
                                MVMJitGraph *jg, MVMJitRunNativeCall *runcode) {
    /* Set up frame return info */
    //| get_cur_op TMP2
    //| ldr TMP5, TC->cur_frame
    //| str TMP2, FRAME:TMP5->return_address
    dasm_put(Dst, 585, Dt1(->interp_cur_op), Dt1(->cur_frame), Dt4(->return_address));
#line 943 "src/jit/arm64/emit.dasc"
    if (sizeof(MVMReturnType) == 1) {
        //| mov TMP2, #runcode->return_type
        //| strb w10, FRAME:TMP5->return_type
        dasm_put(Dst, 593, runcode->return_type, Dt4(->return_type));
#line 946 "src/jit/arm64/emit.dasc"
    } else {
        MVM_panic(1, "JIT: MVMReturnType has unexpected size");
    }
    if (runcode->return_type == MVM_RETURN_VOID) {
        //| str xzr, FRAME:TMP5->return_value
        dasm_put(Dst, 598, Dt4(->return_value));
#line 951 "src/jit/arm64/emit.dasc"
    } else {
        MVMint32 rv_off = runcode->return_register * (MVMint32)sizeof(MVMRegister);
        //| add TMP2, x21, #rv_off
        //| str TMP2, FRAME:TMP5->return_value
        dasm_put(Dst, 601, rv_off, Dt4(->return_value));
#line 955 "src/jit/arm64/emit.dasc"
    }

    /* Set up call arguments */
    emit_arm64_callargs(tc, compiler, jg, runcode->args, runcode->num_args);

    /* Call the native function */
    //| .data
    dasm_put(Dst, 606);
#line 962 "src/jit/arm64/emit.dasc"
    //| 5:
    //| .quad (MVMuint64)(uintptr_t)(runcode->entry_point)
    //| .code
    dasm_put(Dst, 607, (unsigned int)((MVMuint64)(uintptr_t)(runcode->entry_point)), (unsigned int)((unsigned long long)((MVMuint64)(uintptr_t)(runcode->entry_point))>>32));
#line 965 "src/jit/arm64/emit.dasc"
    //| ldr FUNCTION, <5
    //| blr FUNCTION
    dasm_put(Dst, 611);
#line 967 "src/jit/arm64/emit.dasc"

    if (runcode->return_type != MVM_RETURN_VOID) {
        MVMint32 rv_off = runcode->return_register * (MVMint32)sizeof(MVMRegister);
        /* Sign-extend narrow integer return values */
        if (runcode->rv_type == MVM_NATIVECALL_ARG_CHAR) {
            //| sxtb x0, x0
            dasm_put(Dst, 615);
#line 973 "src/jit/arm64/emit.dasc"
        } else if (runcode->rv_type == MVM_NATIVECALL_ARG_SHORT) {
            //| sxth x0, x0
            dasm_put(Dst, 617);
#line 975 "src/jit/arm64/emit.dasc"
        } else if (runcode->rv_type == MVM_NATIVECALL_ARG_INT) {
            //| sxtw x0, w0
            dasm_put(Dst, 619);
#line 977 "src/jit/arm64/emit.dasc"
        }
        /* Zero-extend narrow unsigned return values */
        if (runcode->rv_type == MVM_NATIVECALL_ARG_UCHAR) {
            //| and x0, x0, #0xFF
            dasm_put(Dst, 621);
#line 981 "src/jit/arm64/emit.dasc"
        } else if (runcode->rv_type == MVM_NATIVECALL_ARG_USHORT) {
            //| and x0, x0, #0xFFFF
            dasm_put(Dst, 623);
#line 983 "src/jit/arm64/emit.dasc"
        } else if (runcode->rv_type == MVM_NATIVECALL_ARG_UINT) {
            //| and x0, x0, #0xFFFFFFFF
            dasm_put(Dst, 625);
#line 985 "src/jit/arm64/emit.dasc"
        } else if (runcode->rv_type == MVM_NATIVECALL_ARG_ULONG && sizeof(long) == 4) {
            //| and x0, x0, #0xFFFFFFFF
            dasm_put(Dst, 627);
#line 987 "src/jit/arm64/emit.dasc"
        }
        //| str RV, [x21, #rv_off]
        dasm_put(Dst, 629, rv_off);
#line 989 "src/jit/arm64/emit.dasc"
    }
}

void MVM_jit_emit_dispatch(MVMThreadContext *tc, MVMJitCompiler *compiler,
                           MVMJitGraph *jg, MVMJitDispatch *dispatch) {
    MVMint16 i;
    MVMuint64 slot_off = (MVMuint64)dispatch->ice_slot * sizeof(void *);

    /* Arg map at label 5 */
    //| .data
    dasm_put(Dst, 632);
#line 999 "src/jit/arm64/emit.dasc"
    //|5:
    dasm_put(Dst, 633);
#line 1000 "src/jit/arm64/emit.dasc"
    {
        MVMuint32 flag_count = dispatch->callsite->flag_count;
        MVMuint32 fi;
        for (fi = 0; fi + 2 <= flag_count; fi += 2) {
            MVMuint32 packed = (MVMuint32)(MVMuint16)dispatch->map[fi].reg.orig | ((MVMuint32)(MVMuint16)dispatch->map[fi+1].reg.orig << 16);
            //| .long packed
            dasm_put(Dst, 635, packed);
#line 1006 "src/jit/arm64/emit.dasc"
        }
        if (flag_count & 1) {
            MVMuint32 last = (MVMuint32)(MVMuint16)dispatch->map[flag_count-1].reg.orig;
            //| .long last
            dasm_put(Dst, 637, last);
#line 1010 "src/jit/arm64/emit.dasc"
        }
    }
    //| .code
    dasm_put(Dst, 639);
#line 1013 "src/jit/arm64/emit.dasc"

    /* Frame return setup */
    //| get_cur_op TMP2
    //| ldr TMP5, TC->cur_frame
    //| str TMP2, FRAME:TMP5->return_address
    dasm_put(Dst, 640, Dt1(->interp_cur_op), Dt1(->cur_frame), Dt4(->return_address));
#line 1018 "src/jit/arm64/emit.dasc"
    if (sizeof(MVMReturnType) == 1) {
        //| mov TMP2, #dispatch->return_type
        //| strb w10, FRAME:TMP5->return_type
        dasm_put(Dst, 648, dispatch->return_type, Dt4(->return_type));
#line 1021 "src/jit/arm64/emit.dasc"
    } else {
        MVM_panic(1, "JIT: MVMReturnType has unexpected size");
    }
    if (dispatch->return_type == MVM_RETURN_VOID) {
        //| str xzr, FRAME:TMP5->return_value
        dasm_put(Dst, 653, Dt4(->return_value));
#line 1026 "src/jit/arm64/emit.dasc"
    } else {
        MVMint32 rv_off = dispatch->return_register * (MVMint32)sizeof(MVMRegister);
        //| add TMP2, x21, #rv_off
        //| str TMP2, FRAME:TMP5->return_value
        dasm_put(Dst, 656, rv_off, Dt4(->return_value));
#line 1030 "src/jit/arm64/emit.dasc"
    }

    /* Build register args.
     * run_dispatch(tc, entry_ptr, seen, id, cs, arg_indices, source, sf, bytecode_offset)
     * x0-x7 = 8 register args; bytecode_offset = -1 on stack. */
    //| mov ARG1, x19
    //| get_spesh_slot TMP6, dispatch->sf_slot
    //| ldr ARG2, STATICFRAME:TMP6->body.inline_cache.entries
    //| .data
    dasm_put(Dst, 661, Dt1(->cur_frame), Dt4(->effective_spesh_slots), ((dispatch->sf_slot)*8), DtB(->body.inline_cache.entries));
#line 1039 "src/jit/arm64/emit.dasc"
    //| 8:
    //| .quad slot_off
    //| .code
    dasm_put(Dst, 671, (unsigned int)(slot_off), (unsigned int)((unsigned long long)(slot_off)>>32));
#line 1042 "src/jit/arm64/emit.dasc"
    //| ldr TMP3, <8
    //| add ARG2, ARG2, TMP3
    //| ldr ARG3, [ARG2]
    //| get_string ARG4, dispatch->id
    dasm_put(Dst, 675);
     MVM_cu_ensure_string_decoded(tc, jg->sg->sf->body.cu, dispatch->id);
#line 1046 "src/jit/arm64/emit.dasc"
    //| .data
    dasm_put(Dst, 680, Dt3(->body.strings), ((dispatch->id)*8));
#line 1047 "src/jit/arm64/emit.dasc"
    //| 6:
    //| .quad (uintptr_t)(dispatch->callsite)
    //| .code
    dasm_put(Dst, 685, (unsigned int)((uintptr_t)(dispatch->callsite)), (unsigned int)((unsigned long long)((uintptr_t)(dispatch->callsite))>>32));
#line 1050 "src/jit/arm64/emit.dasc"
    //| ldr ARG5, <6
    //| adr ARG6, <5
    //| mov x6, x21
    //| mov x7, TMP6
    dasm_put(Dst, 689);
#line 1054 "src/jit/arm64/emit.dasc"

    /* 9th arg (bytecode_offset = -1) on stack */
    //| sub sp, sp, #16
    //| mov TMP1, #-1
    //| str TMP1, [sp]
    dasm_put(Dst, 696, (unsigned int)(-1), (unsigned int)((unsigned long long)(-1)>>32));
#line 1059 "src/jit/arm64/emit.dasc"

    //| ldr FUNCTION, MVMDISPINLINECACHEENTRY:ARG3->run_dispatch
    //| blr FUNCTION
    //| add sp, sp, #16
    dasm_put(Dst, 701, Dt11(->run_dispatch));
#line 1063 "src/jit/arm64/emit.dasc"
}

void MVM_jit_emit_istype(MVMThreadContext *tc, MVMJitCompiler *compiler,
                         MVMJitGraph *jg, MVMJitIsType *istype) {
    MVMuint64 slot_off;

    /* Try cache first */
    //| mov ARG1, x19
    //| ldr ARG2, [x21, #(istype->obj_register * sizeof(MVMRegister))]
    //| ldr ARG3, [x21, #(istype->type_register * sizeof(MVMRegister))]
    //| add ARG4, x21, #(istype->return_register * sizeof(MVMRegister))
    //| callp &MVM_6model_try_cache_type_check
    dasm_put(Dst, 706, (istype->obj_register * sizeof(MVMRegister)), (istype->type_register * sizeof(MVMRegister)), (istype->return_register * sizeof(MVMRegister)));
    dasm_put(Dst, 714, (unsigned int)((uintptr_t)(&MVM_6model_try_cache_type_check)), (unsigned int)((unsigned long long)((uintptr_t)(&MVM_6model_try_cache_type_check))>>32));
    dasm_put(Dst, 718);
#line 1075 "src/jit/arm64/emit.dasc"

    //| cbnz RV, =>(istype->reentry_label)
    dasm_put(Dst, 722, (istype->reentry_label));
#line 1077 "src/jit/arm64/emit.dasc"

    /* Check for HLL istype dispatcher */
    {
        MVMStaticFrame *sf = (MVMStaticFrame *)jg->sg->spesh_slots[istype->sf_slot];
        MVMHLLConfig *hll = sf->body.cu->body.hll_config;
        if (hll->istype_dispatcher) {
            /* Arg map at label 5 */
            //| .data
            dasm_put(Dst, 725);
#line 1085 "src/jit/arm64/emit.dasc"
            //|5:
            dasm_put(Dst, 726);
#line 1086 "src/jit/arm64/emit.dasc"
            {
                MVMuint32 packed = (MVMuint32)(MVMuint16)istype->obj_register | ((MVMuint32)(MVMuint16)istype->type_register << 16);
                //| .long packed
                dasm_put(Dst, 728, packed);
#line 1089 "src/jit/arm64/emit.dasc"
            }
            //| .code
            dasm_put(Dst, 730);
#line 1091 "src/jit/arm64/emit.dasc"

            /* Frame return setup */
            //| get_cur_op TMP2
            //| ldr TMP5, TC->cur_frame
            //| str TMP2, FRAME:TMP5->return_address
            //| mov TMP2, #MVM_RETURN_INT
            //| strb w10, FRAME:TMP5->return_type
            //| add TMP2, x21, #(istype->return_register * sizeof(MVMRegister))
            //| str TMP2, FRAME:TMP5->return_value
            dasm_put(Dst, 731, Dt1(->interp_cur_op), Dt1(->cur_frame), Dt4(->return_address), MVM_RETURN_INT, Dt4(->return_type), (istype->return_register * sizeof(MVMRegister)), Dt4(->return_value));
#line 1100 "src/jit/arm64/emit.dasc"

            slot_off = (MVMuint64)istype->ice_slot * sizeof(void *);
            //| mov ARG1, x19
            //| get_spesh_slot TMP6, istype->sf_slot
            //| ldr ARG2, STATICFRAME:TMP6->body.inline_cache.entries
            //| .data
            dasm_put(Dst, 747, Dt1(->cur_frame), Dt4(->effective_spesh_slots), ((istype->sf_slot)*8), DtB(->body.inline_cache.entries));
#line 1106 "src/jit/arm64/emit.dasc"
            //| 8:
            //| .quad slot_off
            //| .code
            dasm_put(Dst, 757, (unsigned int)(slot_off), (unsigned int)((unsigned long long)(slot_off)>>32));
#line 1109 "src/jit/arm64/emit.dasc"
            //| ldr TMP3, <8
            //| add ARG2, ARG2, TMP3
            //| ldr ARG3, [ARG2]
            dasm_put(Dst, 761);
#line 1112 "src/jit/arm64/emit.dasc"
            MVMString **id_addr = &(hll->istype_dispatcher);
            //| .data
            dasm_put(Dst, 766);
#line 1114 "src/jit/arm64/emit.dasc"
            //| 6:
            //| .quad (uintptr_t)id_addr
            //| .code
            dasm_put(Dst, 767, (unsigned int)((uintptr_t)id_addr), (unsigned int)((unsigned long long)((uintptr_t)id_addr)>>32));
#line 1117 "src/jit/arm64/emit.dasc"
            //| ldr ARG4, <6
            //| ldr ARG4, [ARG4]
            dasm_put(Dst, 771);
#line 1119 "src/jit/arm64/emit.dasc"
            MVMCallsite *callsite = MVM_callsite_get_common(tc, MVM_CALLSITE_ID_OBJ_OBJ);
            //| .data
            dasm_put(Dst, 775);
#line 1121 "src/jit/arm64/emit.dasc"
            //| 7:
            //| .quad (uintptr_t)callsite
            //| .code
            dasm_put(Dst, 776, (unsigned int)((uintptr_t)callsite), (unsigned int)((unsigned long long)((uintptr_t)callsite)>>32));
#line 1124 "src/jit/arm64/emit.dasc"
            //| ldr ARG5, <7
            //| adr ARG6, <5
            //| mov x6, x21
            //| mov x7, TMP6
            dasm_put(Dst, 780);
#line 1128 "src/jit/arm64/emit.dasc"

            //| sub sp, sp, #16
            //| mov TMP1, #-1
            //| str TMP1, [sp]
            //| ldr FUNCTION, MVMDISPINLINECACHEENTRY:ARG3->run_dispatch
            //| blr FUNCTION
            //| add sp, sp, #16
            dasm_put(Dst, 787, (unsigned int)(-1), (unsigned int)((unsigned long long)(-1)>>32), Dt11(->run_dispatch));
#line 1135 "src/jit/arm64/emit.dasc"
        }
    }
}
