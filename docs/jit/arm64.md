# ARM64 JIT Port — Status and Roadmap

This document tracks the ARM64 JIT port on the `arm-jit` branch.
For background, porting risks, required knowledge, and alternate
approaches see [`aarch64-jit-scope.md`](aarch64-jit-scope.md) (2021 draft scope).

---

## Milestone 1 — Infrastructure and frame enter/exit (DONE)

### New files

| File | Purpose |
|------|---------|
| `3rdparty/dynasm/dasm_arm64.h` | ARM64 DynASM C runtime (from LuaJIT v2.1) |
| `3rdparty/dynasm/dasm_arm64.lua` | ARM64 DynASM Lua preprocessor module |
| `src/jit/arm64/arch.h` | Register enum macros: `X0`–`X30`, `V0`–`V31` |
| `src/jit/arm64/arch.c` | Register bitmaps and AAPCS64 calling convention tables |
| `src/jit/arm64/emit.dasc` | DynASM source: prologue, epilogue, label/branch emitters, stubs |
| `src/jit/arm64/tile_pattern.h` | Stub tile tables (no expression tiles yet) |
| `t/jit_arm64_frame.c` | TAP test: compiles and enters a minimal JIT graph, all 9 tests pass |

### Modified files

| File | Change |
|------|--------|
| `src/jit/internal.h` | Added `MVM_JIT_ARCH_ARM64 = 2`; added `MVM_JIT_ARCH_H` / `MVM_JIT_TILE_PATTERN_H` macros for ARM64 |
| `src/jit/tile.c` | Fixed latent arch-detection bug: replaced `#if MVM_JIT_ARCH == MVM_JIT_ARCH_X64` (always true after undefs) with `#ifdef MVM_JIT_TILE_PATTERN_H` |
| `Configure.pl` | Enabled ARM64 JIT code path (was commented out) |
| `build/Makefile.in` | Added `JIT_ARCH_ARM64`, ARM64 build rules, `test-jit-arm64` target |

### Register convention (AAPCS64)

| Role | Register | Notes |
|------|----------|-------|
| TC (thread context) | x19 | callee-saved |
| CU (compile unit)   | x20 | callee-saved |
| WORK (register file)| x21 | callee-saved |
| ARG1–ARG6           | x0–x5 | |
| ARG1F–ARG2F (FP args)| v0–v1 | |
| TMP1–TMP7           | x9–x15 | caller-saved |
| FUNCTION (indirect call scratch) | x16 / IP0 | |
| FP                  | x29 | |
| LR                  | x30 | |

### Stack frame layout (prologue)

80-byte frame; SP remains 16-byte aligned throughout.

```
[sp+0 ]  x29 (FP)
[sp+8 ]  x30 (LR)
[sp+16]  x19 (TC saved)
[sp+24]  x20 (CU saved)
[sp+32]  x21 (WORK saved)
[sp+40..79] available for spills
```

### `callp` macro

ARM64 has no equivalent of x86's `call imm32` for arbitrary 64-bit addresses.
`callp` stores the target pointer in the data section, loads it via a
PC-relative `ldr`, then executes `blr`:

```asm
.data; 5: .quad (uintptr_t)(funcptr); .code
ldr  x16, <5
blr  x16
```

### Known workarounds

- **`unsigned int[]` vs `unsigned char*`**: ARM64 DynASM generates
  `static const unsigned int actions[]` (not `unsigned char[]` as on x86).
  `MVM_jit_actions()` returns it with an explicit cast to `const unsigned char*`.
- **`no_trampoline = 1`**: The x64 trampoline uses `call` to push a return
  address on the stack; ARM64 uses the LR register instead. The trampoline
  mechanism is deferred (Milestone 4). Setting `no_trampoline = 1` is safe
  because all consumers of `tc->jit_return_address` check for NULL first.

---

## Milestone 2 — `emit_call_c`: C function calls from JIT graphs

Most real spesh-generated JIT graphs contain `MVM_JIT_NODE_CALL_C` nodes.
Without `emit_call_c` any graph that calls a C helper will `MVM_oops`.

**What needs implementing in `emit.dasc`:**

1. Save all live caller-saved registers (x0–x15, x17, v0–v7, v16–v31) that
   the register allocator reports as live.
2. Marshal arguments: integer args in x0–x7 (via `jit_arch_storage_for_arglist`),
   FP args in v0–v7.
3. Emit `callp func_ptr`.
4. Restore live caller-saved registers.
5. Move return value from x0 (or v0) to the destination register.

`MVM_jit_emit_call_c` in `emit.dasc` currently calls `MVM_oops`.

---

## Milestone 3 — Remaining lego-JIT emitters

After `emit_call_c`, the following emitters are needed for full lego-JIT
coverage. Each currently calls `MVM_oops`.

| Emitter | Notes |
|---------|-------|
| `emit_conditional_branch` | Emit `b.cond` or `cbz`/`cbnz` |
| `emit_guard` | Deopt/bail-out guards; needs deopt tables |
| `emit_jumplist` | Dispatch table jump via `adr` + `ldr` + `br` |
| `emit_control` | Expression-JIT control flow; needs tiles first |
| `emit_data` | Inline constant pool entries |
| `emit_load` / `emit_store` | Spill/reload from compiler's spill area |
| `emit_copy` | Register-to-register move (`mov`) |
| `emit_deopt_check` | Check deopt flag and bail if set |
| `emit_runbytecode` | Trampoline back to interpreter |
| `emit_runccode` | Run compiled C code fragment |
| `emit_runnativecall` | NativeCall (Raku FFI) |
| `emit_dispatch` | Inline-cache dispatch |
| `emit_istype` | Type-check fast path |
| `emit_all_bb_jumps` | Basic-block epilogue jumps |

`emit_marker` is already a no-op (correct).

---

## Milestone 4 — Trampoline (`jit_return_address`) (DONE)

On x64, `callp` uses a `call` instruction that pushes the return address on
the JIT stack; `jit_return_address` points to that slot so the trampoline can
redirect the return.

On ARM64, `blr` puts the return address in LR (x30), not the stack. The
x64 slot-redirect approach doesn't apply, so we use a scratch copy instead:

- **Prologue** (when `!jg->no_trampoline`):
  - Save LR to `[sp+40]` — the scratch copy slot (never restored by epilogue).
  - `tc->jit_return_address = sp+40`.
- **Epilogue**: clear `tc->jit_return_address = NULL`.
  `ldp x29, x30, [sp], #80` restores the **original** saved LR from `[sp+8]`
  (not `[sp+40]`), so trampoline overwrites to `[sp+40]` don't cause loops.

Limitation: `callp` does not update `[sp+40]` before each `blr`, so
`*jit_return_address` remains the outer LR rather than a per-callp JIT
position. This means `MVM_jit_code_get_current_position` may return an
imprecise address when called from inside a C helper. Exception re-entry
via JIT is therefore not yet precise — a known gap, deferred to a later
milestone.

`no_trampoline = 1` removed from both test files. All 19 tests still pass.

---

## Milestone 5 — Expression tiles (DONE)

Expression tiles let the JIT lower MoarVM's abstract expression tree IR to
ARM64 machine code.

### New files

| File | Purpose |
|------|---------|
| `src/jit/arm64/tile_pattern.tile` | Tile selection patterns (mirrors x64, omits fused memory+ALU tiles, uses X19/X20/X21/X29 fixed regs) |
| `src/jit/arm64/tiles.dasc` | ARM64 tile emit functions included by emit.dasc via `\|.include` |
| `src/jit/arm64/tile_pattern.h` | Generated by `tools/tiler-table-generator.pl` (replaces empty stub) |

### Modified files

| File | Change |
|------|--------|
| `src/jit/arm64/emit.dasc` | Added `\|.include src/jit/arm64/tiles.dasc` at the end |
| `build/Makefile.in` | tiles.dasc dependency on emit.c rule; ARM64 tile_pattern.h generation rule; tile.o depends on both x64 and ARM64 pattern headers |

### ARM64 tile design notes

- **3-operand ISA**: all `add_reg`, `sub_reg`, etc. are true 3-operand — no x64-style `ensure_two_operand` constraint
- **x16 scratch**: the FUNCTION/IP0 spare register (never allocated by regalloc) is used as a scratch in tile emit helpers
- **Large immediates**: `movz + movk` sequence; `add`/`sub` immediate capped at 4095 via C conditional
- **Float comparisons**: `fcmp` sets ARM64 flags — LT→MI, LE→LS, EQ→EQ, NE→NE naturally exclude NaN; GE/GT need explicit `cset hs/hi; cset x16, vc; and` NaN mask
- **`sxtb`/`sxth`**: use both-X form (DNx encoding); `sxtw` uses Dx/Nw (X dest, W source)
- **FPR numbers**: `ARM64_FPR_NUM(x) = x - 31`; tile emit functions use this to map the register allocator enum to V-register indices

All 19 tests (frame + call_c) still pass.

---

## Milestone 6 — NQP integration test

Build MoarVM with ARM64 JIT enabled, build NQP against it, run the NQP test
suite:

```bash
perl Configure.pl --prefix=$(pwd)/../install
make install
cd ../nqp && perl Configure.pl --backends=moar --prefix=$(pwd)/../install
make install
prove -j2 -r -e ../install/bin/nqp t/nqp t/hll t/qregex t/moar t/serialization
```

Expect many `MVM_oops` panics initially as unimplemented emitters are
hit. Track and fix them bottom-up.

---

## Milestone 7 — Rakudo and spectest

Once NQP tests pass cleanly:

1. Build Rakudo against the ARM64 MoarVM.
2. Run `prove -j2 -e ../install/bin/raku -vlr t`.
3. Run Blin (ecosystem tests) on ARM64 — and verify that x64 is not
   regressed (the `tile.c` fix is cross-arch).

---

## Milestone 8 — Tuning and PR

- Benchmark: interpreter-only vs. lego-JIT vs. expression-JIT on ARM64.
- Compare against x64 baselines; investigate anomalies.
- Rebase onto `main`; clean commit history.
- Open GitHub Pull Request (notifies MoarVM team automatically).

---

## Running the current test

```bash
perl Configure.pl           # generates Makefile
make test-jit-arm64         # builds and runs t/jit_arm64_frame
```

Expected output:

```
ok 1 - MVM_jit_support() returns 1
ok 2 - main thread context exists
ok 3 - MVM_jit_compile_graph() succeeds
ok 4 - compiled code has a function pointer
ok 5 - compiled code has an exit label
ok 6 - compiled code has at least 1 label
ok 7 - label 0 is non-NULL
ok 8 - JIT frame enter/exit completed without crash
ok 9 - jit_code_destroy succeeded
1..9
```
