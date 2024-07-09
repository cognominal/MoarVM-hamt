/* Representation used by VM-level hashes. */

#include "hamt/src/internal_types.h"
#include "hamt/include/hamt.h"

void set_hamt_config();


struct MVMHamtHashEntry {
    /* hash handle inline struct, including the key. */
    struct MVMStrHashHandle hash_handle;
    /* value object */
    MVMObject *value;
};

struct MVMHamtHashBody {
    struct hamt *trie;
};
struct PersistableHash {
    MVMObject common;
    MVMHamtHashBody body;
};

/* Function for REPR setup. */
const MVMREPROps * MVMHamtHash_initialize(MVMThreadContext *tc);

// void at_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj, MVMRegister *result, MVMuint16 kind);
// void bind_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj, MVMRegister value, MVMuint16 kind);

