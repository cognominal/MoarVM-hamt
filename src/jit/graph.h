/* Expression-JIT coverage statistics, collected when the environment
 * variable MVM_JIT_EXPR_STATS is set (see MVMInstance.jit_expr_stats).
 * All JIT compilation happens on the (single) spesh worker thread, so
 * plain counters suffice; they are dumped after the worker is joined. */
struct MVMJitExprStats {
    /* basic blocks seen by the JIT graph builder / with >= 1 expr tree */
    MVMuint64 bbs_total;
    MVMuint64 bbs_with_tree;
    /* trees built; total tree nodes; total roots (~ ops lowered per tree) */
    MVMuint64 trees;
    MVMuint64 tree_nodes;
    MVMuint64 tree_roots;
    /* spesh instructions consumed into trees vs by the lego backend */
    MVMuint64 ins_expr;
    MVMuint64 ins_lego;
    /* histogram of tree sizes in roots: 1,2,3,4,5-8,9-16,17-32,33-64,65+ */
    MVMuint64 roots_hist[9];
    /* tree-build bails on an extop (not representable below) */
    MVMuint64 bail_extop;
    /* per-opcode tree-build bail counts (template misses and other
     * op-keyed bails), indexed by core opcode */
    MVMuint32 bail_op[1024]; /* MVM_OP_EXT_BASE */
};

void MVM_jit_expr_stats_bail(MVMThreadContext *tc, MVMSpeshIns *ins);
void MVM_jit_expr_stats_dump_and_free(MVMInstance *instance);

/* The MVMJitGraph is - for now - really a linked list of instructions.
 * It's likely I'll add complexity when it's needed */
struct MVMJitGraph {
    MVMSpeshGraph *sg;
    MVMJitNode    *first_node;
    MVMJitNode    *last_node;

    /* Number of instruction+bb+graph labels, but excluding the expression labels */
    MVMint32       num_labels;
    /* Offset for instruction labels */
    MVMint32       obj_label_ofs;

    /* Sequence number for expr trees */
    MVMuint16      expr_seq_nr;

    /* Whether expression-tree building is allowed for this frame (used by
     * the MVM_JIT_EXPR_ONLY bisection aid; 1 unless restricted), and the
     * BB index ranges it is allowed in (nranges == 0: everything) */
    MVMuint8       expr_allowed;
    MVMint32       expr_bb_ranges[16];
    MVMint32       expr_bb_nranges;

    /* resultant JIT code is supports 'invokish' etc? */
    MVMuint8       no_trampoline;

    /* All labeled things */
    MVM_VECTOR_DECL(void*, obj_labels);
    MVM_VECTOR_DECL(MVMJitDeopt, deopts);
    MVM_VECTOR_DECL(MVMJitHandler, handlers);
    MVM_VECTOR_DECL(MVMJitInline, inlines);
    MVM_VECTOR_DECL(MVMJitNode*, label_nodes);
};

struct MVMJitDeopt {
    MVMint32 idx;
    MVMint32 label;
};

struct MVMJitHandler {
    MVMint32 start_label;
    MVMint32 end_label;
    MVMint32 goto_label;
};

struct MVMJitInline {
    MVMint32 start_label;
    MVMint32 end_label;
};

/* A label (no more than a number) */
struct MVMJitLabel {
    MVMint32    name;
};

struct MVMJitPrimitive {
    MVMSpeshIns * ins;
};

struct MVMJitGuard {
    MVMSpeshIns * ins;
    MVMuint32 deopt_idx;
};


#define MVM_JIT_INFO_INVOKISH 1
#define MVM_JIT_INFO_THROWISH 2

typedef enum {
    MVM_JIT_CONTROL_BREAKPOINT,
} MVMJitControlType;

struct MVMJitControl {
    MVMSpeshIns       *ins;
    MVMJitControlType type;
};

/* Special branch target for the exit */
#define MVM_JIT_BRANCH_EXIT -1


/* What does a branch need? a label to go to, an instruction to read */
struct MVMJitBranch {
    MVMint32     dest;
    MVMSpeshIns *ins;
};

typedef enum {
    MVM_JIT_INTERP_TC,
    MVM_JIT_INTERP_CU,
    MVM_JIT_INTERP_FRAME,
    MVM_JIT_INTERP_PARAMS,
    MVM_JIT_INTERP_CALLER,
} MVMJitInterpVar;

typedef enum {
    MVM_JIT_INTERP_VAR,
    MVM_JIT_REG_VAL,
    MVM_JIT_REG_VAL_F,
    MVM_JIT_REG_ADDR,
    MVM_JIT_STR_IDX,
    MVM_JIT_LITERAL,
    MVM_JIT_LITERAL_F,
    MVM_JIT_LITERAL_64,
    MVM_JIT_LITERAL_PTR,
    MVM_JIT_REG_STABLE,
    MVM_JIT_REG_OBJBODY,
    /* Take from register relative to cur_op. Usually code is JIT compiled by
       spesh which already known the indexes of the registers an op uses.
       Compilation of native calls however happens ahead of time when the code
       that will call the ncinvoke op may not even exist yet. In that case
       we need to do the same as interp.c and address registers relative to
       cur_op. */
    MVM_JIT_REG_DYNIDX,
    MVM_JIT_DATA_LABEL,
    /* The MVM_JIT_ARG_* types are used when the offset into the WORK array is
       not known yet, i.e. for ahead of time compiled native calls. */
    MVM_JIT_ARG_I64,
    MVM_JIT_ARG_I64_RW,
    MVM_JIT_ARG_DOUBLE,
    /* Pointers are passed as objects with CPointer representation, i.e. the
       actual pointer is part of the object's data. The MVM_JIT_ARG_PTR type
       unboxes the CPointer object and passes on the contained pointer */
    MVM_JIT_ARG_PTR,
    MVM_JIT_ARG_VMARRAY,
    /* The MVM_JIT_PARAM_* types are usd when actual JIT compilation is
       happening as part of spesh, i.e. the offset of the args buffer in WORK
       is already known. */
    MVM_JIT_PARAM_I64,
    MVM_JIT_PARAM_I64_RW,
    MVM_JIT_PARAM_DOUBLE,
    MVM_JIT_PARAM_PTR,
    MVM_JIT_PARAM_VMARRAY,
    MVM_JIT_PARAM_CARRAY,
    /* spesh slot value */
    MVM_JIT_SPESH_SLOT_VALUE,
    /* stack relative address */
    MVM_JIT_STACK_VALUE,
} MVMJitArgType;

struct MVMJitCallArg {
    MVMJitArgType type;
    union {
        MVMint64      lit_i64;
        MVMnum64      lit_n64;
        MVMJitInterpVar  ivar;
        MVMint16          reg;
        void             *ptr;
    } v;
};


typedef enum {
    MVM_JIT_RV_VOID,
    /* ptr and int are mostly the same, but they might not be on all
       platforms */
    MVM_JIT_RV_INT,
    MVM_JIT_RV_PTR,
    /* floats aren't */
    MVM_JIT_RV_NUM,
    /* dereference and store */
    MVM_JIT_RV_DEREF,
    /* store local at address */
    MVM_JIT_RV_ADDR,
    /* Store in register relative to cur_op. Usually code is JIT compiled by
       spesh which already known the indexes of the registers an op uses.
       Compilation of native calls however happens ahead of time when the code
       that will call the ncinvoke op may not even exist yet. In that case
       we need to do the same as interp.c and address registers relative to
       cur_op. */
    MVM_JIT_RV_DYNIDX,
    /* store pointer or vmnull */
    MVM_JIT_RV_DEREF_OR_VMNULL,
    /* store on stack with offset */
    MVM_JIT_RV_TO_STACK,
    /* Exactly like the RV_INT, except we negate the value afterwards */
    MVM_JIT_RV_INT_NEGATED,
} MVMJitRVMode;


struct MVMJitCallC {
    void       *func_ptr;
    MVMJitCallArg  *args;
    MVMuint16   num_args;
    MVMJitRVMode rv_mode;
    MVMint16      rv_type;
    MVMint16      rv_idx;
};

struct MVMJitInvoke {
    MVMint16      callsite_idx;
    MVMint16      arg_count;
    MVMSpeshIns **arg_ins;
    MVMReturnType return_type;
    MVMint16      return_register;
    MVMuint32     code_register_or_name;
    MVMint16      spesh_cand_or_sf_slot;
    MVMint8       is_fast;
    MVMuint32     resolve_offset;           /* Only for spesh resolve */
    MVMint32      reentry_label;
};

struct MVMJitRunByteCode {
    MVMCallsite  *callsite;
    MVMReturnType return_type;
    MVMint16      return_register;
    MVMint16      code_register;
    MVMint16      spesh_cand;
    MVMSpeshOperand *map;
    MVMint32      reentry_label;
};

struct MVMJitRunCCode {
    MVMCallsite  *callsite;
    MVMReturnType return_type;
    MVMint16      return_register;
    MVMSpeshOperand code_operand;
    MVMSpeshOperand *map;
    MVMint32      reentry_label;
};

struct MVMJitRunNativeCall {
    void            *entry_point;
    MVMJitCallArg   *args;
    MVMuint16        num_args;
    MVMReturnType    return_type;
    MVMint16         return_register;
    MVMint16         rv_type;
    MVMSpeshOperand *map;
    MVMint32         reentry_label;
};

struct MVMJitDispatch {
    MVMint32      id;
    MVMCallsite  *callsite;
    MVMuint16     sf_slot;
    MVMuint32     ice_slot;
    MVMReturnType return_type;
    MVMint16      return_register;
    MVMSpeshOperand *map;
    MVMint32      reentry_label;
};

struct MVMJitIsType {
    MVMint16      return_register;
    MVMint16      obj_register;
    MVMint16      type_register;
    MVMuint16     sf_slot;
    MVMuint32     ice_slot;
    MVMint32      reentry_label;
};

struct MVMJitJumpList {
    MVMint64 num_labels;
    MVMint16 reg;
    /* labels of the goto's / jump instructions themselves */
    MVMint32 *in_labels;
    /* labels the goto's jump to */
    MVMint32 *out_labels;
};

struct MVMJitData {
    MVMint32 label;
    void     *data;
    size_t    size;
};

struct MVMJitStackSlot {
    MVMint16 slot;
};

/* Node types */
typedef enum {
    MVM_JIT_NODE_PRIMITIVE,
    MVM_JIT_NODE_CALL_C,
    MVM_JIT_NODE_BRANCH,
    MVM_JIT_NODE_LABEL,
    MVM_JIT_NODE_GUARD,
    MVM_JIT_NODE_JUMPLIST,
    MVM_JIT_NODE_CONTROL,
    MVM_JIT_NODE_DATA,
    MVM_JIT_NODE_EXPR_TREE,
    MVM_JIT_NODE_DEOPT_CHECK,
    MVM_JIT_NODE_RUNCCODE,
    MVM_JIT_NODE_RUNBYTECODE,
    MVM_JIT_NODE_RUNNATIVECALL,
    MVM_JIT_NODE_DISPATCH,
    MVM_JIT_NODE_ISTYPE,
    MVM_JIT_NODE_ALL_BB_LABELS,
} MVMJitNodeType;

struct MVMJitNode {
    MVMJitNode   * next; /* linked list */
    MVMJitNodeType type; /* tag */
    union {
        MVMJitPrimitive prim;
        MVMJitCallC     call;
        MVMJitBranch    branch;
        MVMJitLabel     label;
        MVMJitGuard     guard;
        MVMJitInvoke    invoke;
        MVMJitJumpList  jumplist;
        MVMJitControl   control;
        MVMJitData      data;
        MVMJitExprTree *tree;
        MVMJitStackSlot stack;
        MVMJitRunCCode   runccode;
        MVMJitRunByteCode runbytecode;
        MVMJitRunNativeCall runnativecall;
        MVMJitDispatch  dispatch;
        MVMJitIsType    istype;
    } u;
};

MVMJitGraph* MVM_jit_try_make_graph(MVMThreadContext *tc, MVMSpeshGraph *sg);
void MVM_jit_graph_destroy(MVMThreadContext *tc, MVMJitGraph *graph);
