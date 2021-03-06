/**
 * atomic.h - atomic operations
 *
 * @author James Yin <ywhjames@hotmail.com>
 */
#ifndef __ALIB_ATOMIC_H__
#define __ALIB_ATOMIC_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if !defined(__STDC_NO_ATOMICS__)

#include <stdatomic.h>

#define atomic_long_load atomic_load
#define atomic_long_store atomic_store
#define atomic_long_fetch_add atomic_fetch_add
#define atomic_long_fetch_sub atomic_fetch_sub

#define atomic_llong_load atomic_load
#define atomic_llong_store atomic_store
#define atomic_llong_fetch_add atomic_fetch_add
#define atomic_llong_fetch_sub atomic_fetch_sub

#else  // __STDC_NO_ATOMICS__

#if defined(_WIN32)

#include <Windows.h>

typedef LONG atomic_long;

typedef LONG64 atomic_llong;
typedef LONG64 llong;

#else  // _WIN32

typedef long long llong;

#endif  // _WIN32

long atomic_long_load(volatile atomic_long* atom);
void atomic_long_store(volatile atomic_long* atom, long value);
long atomic_long_fetch_add(volatile atomic_long* atom, long value);
long atomic_long_fetch_sub(volatile atomic_long* atom, long value);

llong atomic_llong_load(volatile atomic_llong* atom);
void atomic_llong_store(volatile atomic_llong* atom, llong value);
llong atomic_llong_fetch_add(volatile atomic_llong* atom, llong value);
llong atomic_llong_fetch_sub(volatile atomic_llong* atom, llong value);

#endif  // __STDC_NO_ATOMICS__

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  // __ALIB_ATOMIC_H__
