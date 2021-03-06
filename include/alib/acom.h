/**
 * acom.h - alib common header
 *
 * @author James Yin <ywhjames@hotmail.com>
 *
 * API 语义命名约定:
 *   1. alloc/free            分配、释放对象内存
 *   2. init/clean/reset      初始化、释放缓存、重置状态
 *   3. construct/destruct    构造、析构对象
 *   4. retain/release        增加、减少对象引用
 */
#ifndef _ALIB_COMMON_H_
#define _ALIB_COMMON_H_

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "io/alog.h"
#include "object/aobj.h"
#include "string/astr.h"

//#define DEBUG 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(_WIN32) && !defined(__cplusplus)
#define inline __inline
#endif

#ifdef offsetof
#define offset_of offsetof
#else
#define offset_of(type, member) ((size_t) & ((type*)0)->member)
#endif

#ifndef __TYPEOF__
#define container_of(ptr, type, member) ((type*)((char*)(ptr)-offset_of(type, member)))
#else
#define container_of(ptr, type, member)               \
  ({                                                  \
    const typeof(((type*)0)->member)* __mptr = (ptr); \
    (type*)((char*)__mptr - offset_of(type, member)); \
  })
#endif

#define ROUND_UP(num, ceil) (((num) & ((ceil)-1)) ? ((num) | ((ceil)-1)) + 1 : (num))
#define ROUND_UP_8(num) ROUND_UP(num, 8)
#define ROUND_UP_16(num) ROUND_UP(num, 16)

#ifndef alib_max
#define alib_max(a, b) ((a) >= (b) ? (a) : (b))
#endif

#ifndef alib_swap
#define alib_swap(type, a, b)  \
  do {                         \
    register type __tmp = (a); \
    (a) = (b);                 \
    (b) = __tmp;               \
  } while (0)
#endif

#if !REGION_SIZE
#define REGION_SIZE 0x00001000
#endif

#if !REGION_OFFSET
#define REGION_OFFSET 18
#endif

#define POSITION_MASK ((0x0001ULL << REGION_OFFSET) - 1)

extern const size_t POOL_REGION_SIZE;
extern const size_t POOL_POSITION_SIZE;

sint64_t current_milliseconds(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ALIB_COMMON_H_ */
