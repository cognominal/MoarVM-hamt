# ARM64 JIT: spesh-worker / main-thread race yields a bogus `VMNull` (Rakudo CORE.setting build)

> **RESOLVED (2026-07-14): not a race.** The failure was three deterministic
> ARM64 miscompiles whose *trigger frames* depend on spesh timing, which made
> every timing perturbation (BLOCKING/NODELAY/TSan/instrumentation) look like
> it "fixed a race". See the **Resolution** section at the end for the bugs,
> the fixes, and the bisection tooling that found them.

## Summary

On an **experimental ARM64 (AArch64) JIT backend** for MoarVM, compiling Rakudo's
`CORE.setting` fails only when the JIT is enabled, with:

```
Could not instantiate role 'Blob':
lang-call cannot invoke object of type 'VMNull' belonging to no language
```

The failure is **deterministic with the default spesh configuration, JIT‑specific,
and disappears the moment the spesh/JIT timing is perturbed** (blocking spesh,
eager spesh, ThreadSanitizer, extra instrumentation). Evidence points to a data
race between the **spesh worker thread** (which writes JIT machine code and
publishes specialization state) and the **main thread** (which executes that JIT
code) on ARM64's weak memory model — a race whose *read* half lives in
JIT‑emitted machine code and is therefore invisible to ThreadSanitizer.

This report documents the symptom, a reliable reproduction, and an extensive
ruled‑out list, in the hope that someone with deep spesh/JIT‑concurrency
knowledge can pinpoint the missing synchronization.

## Environment

- MoarVM `2026.05.1` (+ local ARM64 JIT branch), `x86` JIT sources used as the template.
- Apple Silicon, macOS (`Darwin 25.5.0 arm64`), Apple clang 21.
- NQP self‑hosts on this backend and its full test suite passes (13,476 tests);
  the bug only shows up under the much heavier Rakudo `CORE.setting` compile.

> Note: the ARM64 JIT backend is not upstream. The purpose here is to surface
> what looks like a **latent MoarVM concurrency/ordering assumption** that x86's
> strong memory model (TSO) hides but AArch64's weak model exposes.

## Reproduction

Building Rakudo's setting (the heaviest JIT workload) triggers it:

```sh
cd rakudo
perl rakudo-m-early-build --setting=NULL.c --optimize=3 --target=mbc \
    --output=/tmp/c.mbc gen/moar/CORE.c.setting
```

- **JIT on, default spesh:** fails every run.
- **`MVM_JIT_DISABLE=1`:** clean.
- **`MVM_SPESH_BLOCKING=1`:** clean (masks it).
- **`MVM_SPESH_NODELAY=1`:** clean (masks it).
- **Under ThreadSanitizer:** the `VMNull` no longer reproduces (timing perturbed),
  though TSan does report races (see below).

So it requires the *default* lazy + asynchronous spesh: a frame runs interpreted,
becomes hot, the worker produces a **type‑specialized** candidate (with JIT code)
**concurrently**, and a subsequent call on the main thread uses it. Anything that
serializes or changes that timing hides the bug.

## Symptom detail

Instrumenting the throw site (`src/disp/boot.c`, the `lang-call cannot invoke …`
path) and walking the caller chain shows the `VMNull` flows in indirectly:

```
package_declarator:sym<class> → package_def → pkg_compose → compose
  → specialize (role) → protect (JIT'd) → infix:</> → compare-as-Numeric
  → multi-no-match-handler → (lang-call with a VMNull invokee)
```

i.e. during **parametric‑role instantiation** a numeric comparison multi‑dispatches
to **no candidate** (it matches fine with the JIT off), because one operand has
come out as `VMNull`. So a JIT‑emitted read (a getattr / dispatch result) that
should yield a real object is yielding `VMNull`, and everything downstream is
collateral damage.

- Not OSR (`MVM_SPESH_OSR_DISABLE=1` still fails).
- Not inlining (`MVM_SPESH_INLINE_DISABLE=1` still fails).
- Not the expression JIT (`MVM_JIT_EXPR_DISABLE=1` still fails — it's a "lego"/
  per‑op emitter).
- `MVM_SPESH_LIMIT` bisection gives a *consistent* threshold, but the frame at
  that spesh index **varies per run** — because the async worker's ordering is
  nondeterministic — so the culprit frame can't be named this way (and the only
  config that would make ordering deterministic, `BLOCKING`, hides the bug).

## ThreadSanitizer findings

Built with `Configure.pl … --tsan`, run with
`TSAN_OPTIONS="halt_on_error=0 history_size=7"`. ~99 races are reported. The ones
touching state the JIT reads at run time are, on inspection, benign‑by‑design or
already synchronized:

- **`MVM_cu_string_add` reallocating `cu->body.strings`** (during inlining, on the
  worker) vs readers. Old array freed via `MVM_free_at_safepoint`; JIT reads
  `base` then `base[idx]` in two consecutive instructions with no safepoint
  between, so the old array stays valid. *Tested* adding an `MVM_barrier()` before
  publishing the new pointer — did **not** fix the `VMNull`.
- **`MVM_spesh_candidate_add`** already does `MVM_barrier()` before bumping
  `num_spesh_candidates`, and the frame‑entry reader uses `MVM_load` (acquire) on
  `spesh_arg_guard` (`src/core/frame.c:471`). Looks correct.
- The `MVM_jit_dispatch_thunk` frame appears in a race whose actual contended
  location is the **spesh type‑stats log** (`MVM_spesh_log_entry`,
  `src/core/frame.c:583`) — racy‑by‑design/benign.

**Key limitation:** the racing *read* is in JIT‑emitted machine code, so TSan can
only see the worker‑side *write* half and can never pair it with the JIT read.
That's why every visible race looks harmless.

## Other hypotheses tested and rejected

None of these changed the `VMNull`:

1. **I‑cache incoherence** (worker writes code on one core, main executes on
   another). Added `__builtin___clear_cache()` after `dasm_encode` in
   `src/jit/compile.c`. No effect (macOS `mprotect(RX)` appears to handle code
   visibility).
2. **Missing acquire when entering JIT code.** Emitted a full barrier at the JIT
   prologue (DynASM AArch64 doesn't know `dmb`/`ldar`, but a raw
   `| .long 0xd5033bbf` = `dmb ish` assembles fine). No effect — implying the
   racy read, if it is one, happens mid‑execution, not at frame entry.
3. **jitcode use‑after‑free.** `MVM_spesh_candidate_discard_existing` only sets
   `discarded = 1`; candidates are GC objects kept alive by `frame->spesh_cand`
   while running, so a live frame's JIT code isn't freed. (Aside: `MVMJitCode`
   `ref_cnt` uses `memory_order_relaxed` for both inc and dec in
   `src/jit/compile.c` — that's a genuine latent weak‑memory bug for ref‑counting
   even if it isn't *this* one; a UAF there would crash rather than yield a clean
   `VMNull`.)

## Where this points

A **type‑specialized candidate** produced by the worker, whose JIT code (or the
data it reads at run time) becomes visible to the main thread without sufficient
ordering on AArch64. The main thread then reads a stale/partly‑published value and
gets `VMNull` from a getattr/dispatch. On x86 the strong memory model hides it;
`BLOCKING`/`NODELAY`/TSan all change the timing enough to hide it too.

## What would help

- Anyone who knows precisely **what the spesh worker publishes that JIT‑compiled
  code reads at run time without going through the `spesh_arg_guard`
  acquire/release** (candidate fields? effective spesh slots? something in the
  compunit touched by cross‑compunit inlining?).
- Whether MoarVM's spesh/JIT publish path assumes x86 store ordering anywhere that
  should be an explicit release/acquire (or `MVM_barrier`) for weak‑memory targets.
- A way to make the JIT‑side read visible to TSan (e.g. temporarily routing a
  suspected read through an instrumented C shim) to name the exact contended field.

Happy to provide the full instrumentation patches, TSan logs, and caller‑chain
dumps.

## Resolution (2026-07-14)

The "race" was three deterministic miscompiles in the ARM64 lego emitter.
Which frames get type-specialized (and hence JIT'd) depends on spesh worker
timing, so anything that perturbed timing changed *which* buggy code was
emitted — masquerading as a concurrency bug. The failure was bisected to
single frames with new timing-stable tooling (below), then diagnosed by
op-histogramming the spesh graph and auditing emitters against x64.

### Bug 1: `iscont` read stale condition flags

The emitter ended with `cset TMP1, ne` but nothing before it set NZCV
(`ldr`/`cbz` set no flags; the x64 template's `test` did). `iscont` returned
whatever the Z flag happened to be — and `raku-multi-plan` (cuuid 3643, the
multi-dispatch planner) uses `iscont` to classify argument rw-ness, so multis
"matched no candidate" and `multi-no-match-handler` blew up downstream with
the `VMNull` lang-call. Fix: explicit `cmp TMP1, #0` before the `cset` (audited
every other `cset`/`csel`/`cneg` in the backend; all others set flags first).

### Bug 2: bare `blr` lost the `jit_return_address` discipline

On x64, `call` pushes the return address where `*tc->jit_return_address`
finds it, so the "current JIT position" — used for active-inline resolution,
frame-handler search, dynamic lexical lookup, and **deopt redirection** (deopt
rewrites the slot to redirect the resume) — is maintained for free. AArch64
`blr` only sets LR. The `callp` macro maintained the `[sp,#40]` slot
(store resume addr; call; **reload the slot and branch to it**), but 13
emitters called through a bare `blr FUNCTION` (container fetch/store,
`run_getlexstatic` — which records dispatch programs and can GC/deopt —
`newtype`, `composetype`, `change_type`, atomics, …). Any frame walk or deopt
during those calls used a stale position; with inlined code that means wrong
active-inline sets and lost deopt redirects. This broke `declarator`
(Perl6::Actions, cuuid 127, with `ast`/`make` inlined) — passing with
`MVM_SPESH_INLINE_DISABLE=1` was the giveaway. Fix: a `callf` macro (same
protocol as `callp` for a function address already in x16) applied to all
raw-`blr` sites.

### Bug 3: `sp_add_I`/`sp_sub_I`/`sp_mul_I` clobbered an aliased operand

The slow (bigint fallback) path stored the freshly created result object to
`work[c]` *before* loading `a`/`b` from work. Spesh may assign the result the
same work register as an operand (`c == a` or `c == b`); the fallback then
received the brand-new empty bigint body (`u.bigint == NULL`) and crashed in
`mp_sub` (SIGSEGV at offset 8, from JIT'd `infix:<->`, cuuid 3883). The x64
template even carries a comment warning about exactly this; the port reordered
it. Fix: load `a`/`b` into ARG2/ARG3 first, then store RV (keeping ARG1 last
since RV == ARG1 == x0 on AArch64).

### Hardening added along the way

- **`DASM_CHECKS` is now defined** (src/jit/internal.h). DynASM otherwise
  compiles out all immediate range checks and silently truncates out-of-range
  immediates into wrong-but-valid instructions. Range violations now fail
  `dasm_link`/`dasm_encode`; `MVM_jit_compiler_assemble` prints the frame name
  and falls back to the interpreter. This immediately caught `getcode` with
  coderef index > 4095 (offset past the scaled-LDR limit — Rakudo-sized
  compunits only), fixed via `arm64_ldr_off`/`arm64_str_off` helpers, applied
  to the lexical `env` accesses too.
- **Timing-stable JIT bisection** (src/jit/graph.c), keyed on an FNV-1a hash
  of frame name + cuuid so the same frames are affected every run regardless
  of worker timing (unlike `MVM_SPESH_LIMIT`):
  - `MVM_JIT_BISECT=K:lo-hi` — skip JIT for frames with hash%K in [lo,hi]
  - `MVM_JIT_ONLY=K:lo-hi` — JIT *only* those frames
  - `MVM_JIT_BISECT_VERBOSE=1` — print each skipped/kept frame
  Binary-searching `MVM_JIT_ONLY` buckets reduces a failure to a single-frame
  reproducer in ~15 minutes of unattended runs.

### Verification

- Full `CORE.setting` compile with default spesh/JIT settings: passes
  (repeatedly), where it previously failed every run.
- The single-frame reproducers for all three bugs pass individually.
- NQP test suites re-run clean after the fixes.
