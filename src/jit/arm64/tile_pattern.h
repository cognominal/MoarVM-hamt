/* Stub tile pattern for ARM64 — no expression tiles implemented yet.
 * tile.c needs these symbols to compile even when tiles are empty. */

static const MVMJitTileTemplate MVM_jit_tile_templates[] = {
    { NULL, "", 0, 0, 0, 0 }
};

static MVMint32* MVM_jit_tile_state_lookup(MVMThreadContext *tc,
        MVMint32 node, MVMint32 c1, MVMint32 c2) {
    (void)tc; (void)node; (void)c1; (void)c2;
    return NULL;
}

static MVMint32 MVM_jit_tile_select_lookup(MVMThreadContext *tc,
        MVMint32 ts, MVMint32 nt) {
    (void)tc; (void)ts; (void)nt;
    return 0;
}
