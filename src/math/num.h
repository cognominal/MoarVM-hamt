#ifndef MATH_NUM_H
#define MATH_NUM_H

#ifdef _WIN32
#include <float.h>
#endif
#include <math.h>

#if defined(INFINITY) && !defined(_AIX)
static const MVMnum64 MVM_NUM_POSINF =  INFINITY;
static const MVMnum64 MVM_NUM_NEGINF = -INFINITY;
#else
#  ifdef _MSC_VER
#define MVM_NUM_POSINF  (DBL_MAX+DBL_MAX)
#define MVM_NUM_NEGINF -(DBL_MAX+DBL_MAX)
#  else
static const MVMnum64 MVM_NUM_POSINF =  1.0 / 0.0;
static const MVMnum64 MVM_NUM_NEGINF = -1.0 / 0.0;
#  endif
#endif

#if defined(NAN) && !defined(_AIX)
static const MVMnum64 MVM_NUM_NAN = NAN;
#else
#  ifdef _MSC_VER
#define MVM_NUM_NAN (MVM_NUM_POSINF-MVM_NUM_POSINF)
#  else
static const MVMnum64 MVM_NUM_NAN = 0.0 / 0.0;
#  endif
#endif

/* Ideally we would add a probe for `fpclassify` (which is part of C99) and
 * use that if present, with this approach as a fallback.
 * Likely `fpclassify` will use integer instructions to look at the exponent
 * bits of the floating point value, which tend to be both smaller and play
 * more nicely with the dispatch logic of modern CPUs. */

MVM_STATIC_INLINE MVMint64 MVM_num_isnanorinf(MVMThreadContext *tc, MVMnum64 n) {
    return n == MVM_NUM_POSINF || n == MVM_NUM_NEGINF || n != n;
}

MVM_STATIC_INLINE MVMnum64 MVM_num_posinf(MVMThreadContext *tc) {
    return MVM_NUM_POSINF;
}

MVM_STATIC_INLINE MVMnum64 MVM_num_neginf(MVMThreadContext *tc) {
    return MVM_NUM_NEGINF;
}

MVM_STATIC_INLINE MVMnum64 MVM_num_nan(MVMThreadContext *tc) {
    return MVM_NUM_NAN;
}

MVM_STATIC_INLINE MVMnum64 MVM_num_isnegzero(MVMThreadContext *tc, MVMnum64 n) {
    return n == 0 && 1.0 / n == MVM_NUM_NEGINF;
}

#endif
