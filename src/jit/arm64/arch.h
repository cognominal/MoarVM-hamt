/* AArch64 register declarations for MoarVM JIT */

#define MVM_JIT_ARCH_GPR(_) \
    _(X0),  _(X1),  _(X2),  _(X3),  _(X4),  _(X5),  _(X6),  _(X7),  \
    _(X8),  _(X9),  _(X10), _(X11), _(X12), _(X13), _(X14), _(X15), \
    _(X16), _(X17), _(X18), _(X19), _(X20), _(X21), _(X22), _(X23), \
    _(X24), _(X25), _(X26), _(X27), _(X28), _(X29), _(X30)

#define MVM_JIT_ARCH_FPR(_) \
    _(V0),  _(V1),  _(V2),  _(V3),  _(V4),  _(V5),  _(V6),  _(V7),  \
    _(V8),  _(V9),  _(V10), _(V11), _(V12), _(V13), _(V14), _(V15), \
    _(V16), _(V17), _(V18), _(V19), _(V20), _(V21), _(V22), _(V23), \
    _(V24), _(V25), _(V26), _(V27), _(V28), _(V29), _(V30), _(V31)

/* 31 GPR (x0-x30) + 32 FPR (v0-v31) = 63, fits in MVMBitmap (uint64) */
#define MVM_JIT_ARCH_NUM_REG 63
