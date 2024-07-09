#include "moar.h"
#include "hamt/include/murmur3.h"
/*  lifted and adpatd from test_hamt.c */


struct hamt_allocator hamt_allocator_default = {MVM_malloc, MVM_realloc,
                                                MVM_free, NULL};



/* This representation's function pointer table. */
static const MVMREPROps MVMHamtHash_this_repr;

static int my_strncmp_1(const void *lhs, const void *rhs)
{
    return strncmp((const char *)lhs, (const char *)rhs, 1);
}

static uint32_t my_hash_1(const void *key, const size_t gen)
{
    (void) gen; /* ignore gen here */
    return murmur3_32((uint8_t *)key, 1, 0);
}

static struct hamt_config *cfg = NULL;

/* helper function to create a HAMT config; only takes subset of key
 * parameters, uses defaults for the the rest */
struct hamt_config *create_config(struct hamt_allocator *allocator,
                                  hamt_key_hash_fn key_hash_fn,
                                  hamt_key_cmp_fn key_cmp_fn)
{
    struct hamt_config *cfg = NULL;
#if defined(WITH_TABLE_CACHE)
    struct hamt_table_cache_config *tc_cfg =
        allocator->malloc(sizeof *tc_cfg, allocator->ctx);
    if (!tc_cfg)
        goto exit;
    *tc_cfg = (struct hamt_table_cache_config){
        .bucket_count = hamt_table_cache_config_default_bucket_count,
        .initial_bucket_sizes = hamt_table_cache_default_bucket_sizes,
        .backing_allocator = allocator};
    struct hamt_table_cache *cache = hamt_table_cache_create(tc_cfg);
    if (!cache)
        goto cleanup_cache_config;
#endif
    cfg = allocator->malloc(sizeof *cfg, allocator->ctx);
    if (cfg) {
        *cfg = (struct hamt_config)
        {
            .ator = allocator,
#if defined(WITH_TABLE_CACHE)
            .cache = cache,
#endif
            .key_cmp_fn = key_cmp_fn, .key_hash_fn = key_hash_fn
        };
    }
#if defined(WITH_TABLE_CACHE)
    else
        goto cleanup_cache;
    goto exit;
cleanup_cache:
    allocator->free(cache, sizeof *cache, allocator->ctx);
cleanup_cache_config:
    allocator->free(tc_cfg, sizeof *tc_cfg, allocator->ctx);
exit:
#endif
    return cfg;
}


void set_hamt_config() {
    if (cfg == NULL) {
        cfg = create_config(&hamt_allocator_default, my_hash_1, my_strncmp_1);
    }
}


MVM_STATIC_INLINE MVMString *get_string_key(MVMThreadContext *tc, MVMObject *key)
{
    if (MVM_UNLIKELY(!key || REPR(key)->ID != MVM_REPR_ID_MVMString || !IS_CONCRETE(key)))
        MVM_exception_throw_adhoc(tc, "MVMHamtHash representation requires MVMString keys");
    return (MVMString *)key;
}

/* Creates a new type object of this representation, and associates it with
 * the given HOW. */
static MVMObject *type_object_for(MVMThreadContext *tc, MVMObject *HOW)
{
    MVMSTable *st = MVM_gc_allocate_stable(tc, &MVMHamtHash_this_repr, HOW);

    MVMROOT(tc, st, {
        MVMObject *obj = MVM_gc_allocate_type_object(tc, st);
        MVM_ASSIGN_REF(tc, &(st->header), st->WHAT, obj);
        st->size = sizeof(PersistableHash);
    });

    return st->WHAT;
}

/* Copies the body of one object to another. */
static void copy_to(MVMThreadContext *tc, MVMSTable *st, void *src, MVMObject *dest_root, void *dest)
{
}

/* Adds held objects to the GC worklist. */
static void MVMHamtHash_gc_mark(MVMThreadContext *tc, MVMSTable *st, void *data, MVMGCWorklist *worklist)
{
}


static dec_refcount_table(hamt_table *t) {
    if(--t->count == 0) 
        MVM_FREE(t);
}

/* Called by the VM in order to free memory associated with this object. */
static void gc_free(MVMThreadContext *tc, MVMObject *obj)
{
    MVMHamtHashBody *body = (MVMHamtHashBody *)obj;
    return hamt_table_rec(body->trie->root, &dec_refcount_table);


#ifdef HAMT_REFCOUNTED
#endif
}

static void hamt_at_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj, MVMRegister *result, MVMuint16 kind)
{
    if (MVM_UNLIKELY(kind != MVM_reg_obj))
        MVM_exception_throw_adhoc(tc,
            "HamtHash representation does not support native type storage");
    MVMHamtHashBody *body = (MVMHamtHashBody *)data;
    result->o =  (MVMObject*)(body->trie, key_obj);

}

void bind_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj, MVMRegister value, MVMuint16 kind)
{
    if (MVM_UNLIKELY(kind != MVM_reg_obj))
        MVM_exception_throw_adhoc(tc,
            "HamtHash representation does not support native type storage");
    MVMHamtHashBody *body = (MVMHamtHashBody *)data;

}

static MVMuint64 elems(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data)
{
    MVMHamtHashBody *body = (MVMHamtHashBody *)data;
    return body->trie->size;
}

static MVMint64 exists_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj)
{
    return 1;
}

static void delete_key(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMObject *key_obj)
{
}

static MVMStorageSpec get_value_storage_spec(MVMThreadContext *tc, MVMSTable *st)
{
    MVMStorageSpec spec;
    spec.inlineable = MVM_STORAGE_SPEC_REFERENCE;
    spec.boxed_primitive = MVM_STORAGE_SPEC_BP_NONE;
    spec.can_box = 0;
    spec.bits = 0;
    spec.align = 0;
    spec.is_unsigned = 0;
    return spec;
}

static const MVMStorageSpec storage_spec = {
    MVM_STORAGE_SPEC_REFERENCE, /* inlineable */
    0,                          /* bits */
    0,                          /* align */
    MVM_STORAGE_SPEC_BP_NONE,   /* boxed_primitive */
    0,                          /* can_box */
    0,                          /* is_unsigned */
};

/* Gets the storage specification for this representation. */
static const MVMStorageSpec *get_storage_spec(MVMThreadContext *tc, MVMSTable *st)
{
    return &storage_spec;
}

/* Compose the representation. */
static void compose(MVMThreadContext *tc, MVMSTable *st, MVMObject *info)
{
    /* XXX key and value types will be communicated here */
}

/* Deserialize the representation. */
static void deserialize(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data, MVMSerializationReader *reader)
{
}

/* Serialize the representation. */
// static MVMThreadContext *cmp_tc;
// static int cmp_strings(const void *s1, const void *s2)
// {
//     return MVM_string_compare(cmp_tc, *(MVMString **)s1, *(MVMString **)s2);
// }




static void serialize(MVMThreadContext *tc, MVMSTable *st, void *data, MVMSerializationWriter *writer)
{

    // hamt_table_rec();
}

/* Set the size of the STable. */
static void deserialize_stable_size(MVMThreadContext *tc, MVMSTable *st, MVMSerializationReader *reader)
{
    st->size = sizeof(MVMHamtHash);
}


static MVMuint64 unmanaged_size(MVMThreadContext *tc, MVMSTable *st, void *data)
{
    MVMHamtHashBody *body = (MVMHamtHashBody *)data;

    // return MVM_str_hash_allocated_size(tc, &(body->hashtable));
    return 0;
}

static void initialize(MVMThreadContext *tc, MVMSTable *st, MVMObject *root, void *data) {

}


/* Initializes the representation. */
const MVMREPROps *MVMHamtHash_initialize(MVMThreadContext *tc)
{
    return &MVMHamtHash_this_repr;
}

static const MVMREPROps MVMHamtHash_this_repr = {
    type_object_for,
    MVM_gc_allocate_object, /* serialization.c relies on this and the next line */
    initialize,                   /* initialize */
    copy_to,
    MVM_REPR_DEFAULT_ATTR_FUNCS,
    MVM_REPR_DEFAULT_BOX_FUNCS,
    MVM_REPR_DEFAULT_POS_FUNCS,
    {
     hamt_at_key,
     bind_key,
     exists_key,
     delete_key,
     get_value_storage_spec}, /* ass_funcs */
    elems,
    get_storage_spec,
    NULL, /* change_type */
    NULL, /* serialize */
    NULL, /* deserialize */
    NULL, /* serialize_repr_data */
    NULL, /* deserialize_repr_data */
    deserialize_stable_size,
    MVMHamtHash_gc_mark,
    gc_free,
    NULL, /* gc_cleanup */
    NULL, /* gc_mark_repr_data */
    NULL, /* gc_free_repr_data */
    compose,
    NULL, /* spesh */
    "PersistableHash", /* name */
    MVM_REPR_ID_PersistentHash,
    unmanaged_size, /* unmanaged_size */
    NULL,           /* describe_refs */
};
