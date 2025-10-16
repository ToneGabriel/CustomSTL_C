#ifndef _C_CHAR_TRAITS
#define _C_CHAR_TRAITS

#include <string.h>
#include "custom/c_utility.h"


#define NULLCHR 0

#define _DEFINE_GENERIC_CHAR_TRAITS(                                                                                                                \
    CHAR_TRAITS_NAME_PREFIX,                                                                                                                        \
    CHAR_TYPE                                                                                                                                       \
)                                                                                                                                                   \
                                                                                                                                                    \
static CHAR_TYPE*           _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, copy)(CHAR_TYPE* const first1, const CHAR_TYPE* const first2, size_t count);  \
static CHAR_TYPE*           _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, move)(CHAR_TYPE* const first1, const CHAR_TYPE* const first2, size_t count);  \
static int                  _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(const CHAR_TYPE* first1, const CHAR_TYPE* first2, size_t count);     \
static size_t               _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(const CHAR_TYPE* str);                                                \
static const CHAR_TYPE*     _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find)(const CHAR_TYPE* str, size_t count, CHAR_TYPE chr);                     \
static const CHAR_TYPE*     _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, assign)(CHAR_TYPE* const str, size_t count, CHAR_TYPE chr);                   \
                                                                                                                                                    \
static CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, copy)(CHAR_TYPE* const first1, const CHAR_TYPE* const first2, size_t count)             \
{                                                                                                                                                   \
    return (CHAR_TYPE*)(memcpy(first1, first2, count * sizeof(CHAR_TYPE)));                                                                         \
}                                                                                                                                                   \
                                                                                                                                                    \
static CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, move)(CHAR_TYPE* const first1, const CHAR_TYPE* const first2, size_t count)             \
{                                                                                                                                                   \
    return (CHAR_TYPE*)(memmove(first1, first2, count * sizeof(CHAR_TYPE)));                                                                        \
}                                                                                                                                                   \
                                                                                                                                                    \
static int _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(const CHAR_TYPE* first1, const CHAR_TYPE* first2, size_t count)                       \
{                                                                                                                                                   \
    return memcmp(first1, first2, count * sizeof(CHAR_TYPE));                                                                                       \
}                                                                                                                                                   \
                                                                                                                                                    \
static size_t _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(const CHAR_TYPE* str)                                                               \
{                                                                                                                                                   \
    size_t count = 0;                                                                                                                               \
    for (/*Empty*/; *str != NULLCHR; ++count, ++str) { /*do nothing*/ }                                                                             \
    return count;                                                                                                                                   \
}                                                                                                                                                   \
                                                                                                                                                    \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find)(const CHAR_TYPE* str, size_t count, CHAR_TYPE chr)                          \
{                                                                                                                                                   \
    for (/*Empty*/; 0 < count; --count, ++str)                                                                                                      \
        if (*str == chr) return str;                                                                                                                \
    return NULL;                                                                                                                                    \
}                                                                                                                                                   \
                                                                                                                                                    \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, assign)(CHAR_TYPE* const str, size_t count, CHAR_TYPE chr)                        \
{                                                                                                                                                   \
    for (CHAR_TYPE* next = str; count > 0; --count, ++next)                                                                                         \
        *next = chr;                                                                                                                                \
    return str;                                                                                                                                     \
}                                                                                                                                                   \


#endif  // _C_CHAR_TRAITS