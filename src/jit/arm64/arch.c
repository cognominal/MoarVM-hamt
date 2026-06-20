#include "moar.h"
#include "jit/internal.h"

/* GPR bits 0-30 (x0-x30), FPR bits 31-62 (v0-v31) */
const MVMBitmap MVM_JIT_REGISTER_CLASS[] = {
    /* none */ 0,
    /* gpr  */ UINT64_C(0x000000007FFFFFFF),
    /* fpr  */ UINT64_C(0x7FFFFFFF80000000),
};

#define X(n)  (UINT64_C(1) << (n))
#define V(n)  (UINT64_C(1) << (31 + (n)))

/* x16 (IP0) for emit scratch; v0 for FP return value / emit scratch */
const MVMBitmap MVM_JIT_SPARE_REGISTERS = X(16) | V(0);

/* AAPCS64 callee-saved: x18 (platform), x19 (TC), x20 (CU), x21 (WORK),
 * x22-x28, x29 (FP), x30 (LR); FP callee-saved: v8-v15 */
const MVMBitmap MVM_JIT_RESERVED_REGISTERS =
    X(18)|X(19)|X(20)|X(21)|X(22)|X(23)|X(24)|
    X(25)|X(26)|X(27)|X(28)|X(29)|X(30)|
    V(8)|V(9)|V(10)|V(11)|V(12)|V(13)|V(14)|V(15);

/* AAPCS64 caller-saved: x0-x7 (args), x9-x15 (temps), x17 (IP1);
 * FP: v1-v7 (args), v16-v31 (caller-saved temps) */
const MVMBitmap MVM_JIT_AVAILABLE_REGISTERS =
    X(0)|X(1)|X(2)|X(3)|X(4)|X(5)|X(6)|X(7)|
    X(9)|X(10)|X(11)|X(12)|X(13)|X(14)|X(15)|X(17)|
    V(1)|V(2)|V(3)|V(4)|V(5)|V(6)|V(7)|
    V(16)|V(17)|V(18)|V(19)|V(20)|V(21)|V(22)|V(23)|
    V(24)|V(25)|V(26)|V(27)|V(28)|V(29)|V(30)|V(31);

/* AAPCS64: x0-x7 for integer args, v0-v7 for FP args */
static const MVMint8 arg_gpr[] = {
    MVM_JIT_REG(X0), MVM_JIT_REG(X1), MVM_JIT_REG(X2), MVM_JIT_REG(X3),
    MVM_JIT_REG(X4), MVM_JIT_REG(X5), MVM_JIT_REG(X6), MVM_JIT_REG(X7),
};

static const MVMint8 arg_fpr[] = {
    MVM_JIT_REG(V0), MVM_JIT_REG(V1), MVM_JIT_REG(V2), MVM_JIT_REG(V3),
    MVM_JIT_REG(V4), MVM_JIT_REG(V5), MVM_JIT_REG(V6), MVM_JIT_REG(V7),
};

void MVM_jit_arch_storage_for_arglist(MVMThreadContext *tc, MVMJitCompiler *compiler,
                                      MVMJitExprTree *tree, MVMint32 arglist_node,
                                      MVMJitStorageRef *storage) {
    MVMuint32 narg = MVM_JIT_EXPR_NCHILD(tree, arglist_node);
    MVMint32 *args = MVM_JIT_EXPR_LINKS(tree, arglist_node);
    MVMuint32 i, ngpr = 0, nfpr = 0, nstack = 0;
    for (i = 0; i < narg; i++) {
        MVMint32 carg_type = MVM_JIT_EXPR_ARGS(tree, args[i])[0];
        if (carg_type == MVM_JIT_NUM && nfpr < sizeof(arg_fpr)) {
            storage[i]._cls = MVM_JIT_STORAGE_FPR;
            storage[i]._pos = arg_fpr[nfpr++];
        } else if (ngpr < sizeof(arg_gpr)) {
            storage[i]._cls = MVM_JIT_STORAGE_GPR;
            storage[i]._pos = arg_gpr[ngpr++];
        } else {
            storage[i]._cls = MVM_JIT_STORAGE_STACK;
            storage[i]._pos = 8 * nstack++;
        }
    }
}

MVMJitStorageClass MVM_jit_arch_register_class(MVMuint8 reg_id) {
    if (reg_id >= MVM_JIT_REG(V0))
        return MVM_JIT_STORAGE_FPR;
    return MVM_JIT_STORAGE_GPR;
}
