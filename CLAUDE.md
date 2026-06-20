# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What is MoarVM

MoarVM is a virtual machine designed for the NQP compiler and Rakudo Raku runtime. It is written in C and serves as an embeddable runtime with a bytecode interpreter, JIT compiler, garbage collector, and specialization/optimization engine.

## Build Commands

```bash
# Configure (generates Makefile from build/Makefile.in)
perl Configure.pl

# Build and install
make install

# Common configure options
perl Configure.pl --prefix=/path/to/install
perl Configure.pl --debug=3 --optimize=0   # debug build
perl Configure.pl --no-mimalloc            # disable mimalloc allocator
perl Configure.pl --asan                   # enable AddressSanitizer
perl Configure.pl --no-c11-atomics         # for older compilers

# Other useful make targets
make          # build only (no install)
make clean
make realclean
make reconfig  # reconfigure and rebuild
```

## Testing

MoarVM has no standalone test suite. Tests are run via NQP and Rakudo built on top of MoarVM:

```bash
# After building NQP with the Moar backend:
prove -j2 -r -e ../install/bin/nqp t/nqp t/hll t/qregex t/moar t/serialization t/nativecall t/concurrency

# After building Rakudo:
prove -j2 -e ../install/bin/raku -vlr t
```

See `azure-pipelines.yml` for the full CI build-and-test pipeline across platforms.

## Architecture Overview

The source is organized under `src/` by subsystem:

| Directory | Role |
|-----------|------|
| `src/6model/` | Object system (6model meta-object model), representations (REPR), and bootstrap |
| `src/core/` | Bytecode interpreter, callsites, argument handling, contexts, fixups, string core |
| `src/disp/` | Dispatch system: inline caches, multi-dispatch, method lookup |
| `src/gc/` | Precise generational parallel garbage collector: allocation, collection, finalization, write barriers |
| `src/jit/` | JIT compiler: expression-tree IR, tile scheduling, register allocation, graph building |
| `src/spesh/` | Specialization/optimization: inlining, scalar replacement, partial escape analysis, OSR, dead code elimination |
| `src/strings/` | Unicode handling: UTF-8/16, Latin-1, GB2312, Shift-JIS; normalization, decoding |
| `src/io/` | Async I/O (sockets, UDP, file ops, pipes), event loop, process control — backed by libuv |
| `src/platform/` | Platform abstraction: threads, mutexes, semaphores, signals, timers, mmap, fork |
| `src/profiler/` | Instrumentation profiler, heap snapshots, allocation tracking |
| `src/instrument/` | Runtime instrumentation: line coverage, cross-thread write detection |
| `src/debug/` | Remote debug server: single-step, variable introspection (see `docs/debug-server-protocol.md`) |
| `src/math/` | Big integer operations (wraps libtommath) |

**Key top-level files:**
- `moar.h` / `moar.c` — Public embedding API
- `main.c` — CLI entry point
- `src/core/interp.c` — Bytecode interpreter main loop

**Third-party libraries** are in `3rdparty/`: libuv (async I/O), libtommath (bigints), dyncall/dynload (native calls), libatomic_ops, ryu (float formatting).

## Key Subsystem Interactions

- The **interpreter** (`src/core/interp.c`) executes bytecode ops. Hot code paths are handed to **spesh** for specialization, which may generate specialized bytecode or hand off to the **JIT**.
- The **JIT** (`src/jit/`) compiles expression trees to native code using a tile-based instruction selector.
- **GC** is generational with a nursery (gen0) and old space. Write barriers (`src/gc/wb.h`) track inter-generation pointers. GC is triggered from the interpreter and is parallel across threads.
- **6model** defines the object/representation system. Every object has a `MVMSTable` (shared table, like a vtable) and a `MVMREPROps` struct defining allocation, GC marking, serialization, etc.
- **Dispatch** (`src/disp/`) handles polymorphic method/op dispatch with inline caches that feed back into spesh for optimization.

## Documentation

Subsystem documentation lives in `docs/`:
- `docs/bytecode.md` — Bytecode format reference
- `docs/gc.md` — GC overview
- `docs/jit/` — JIT compiler design
- `docs/debug-server-protocol.md` — Remote debug protocol spec
- `docs/exceptions.md`, `docs/interpreter.md`
