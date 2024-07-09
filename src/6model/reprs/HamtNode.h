#include "limits.h"

#include "hamt/src/internal_types.h"

struct MVMHamtNodeBody {
    struct hamt_node node;
};

typedef struct MVMHamtNodeREPRData {
    /* What type of slots we have. */
    MVMuint8 slot_type;
} MVMHamtNodeREPRData;


struct MVMHamtNode {
    MVMObject common;
    MVMHamtNodeBody body;
};

/* Function for REPR setup. */
const MVMREPROps * MVMHamtNode_initialize(MVMThreadContext *tc);
