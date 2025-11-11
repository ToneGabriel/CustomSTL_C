#ifndef _C_CHAR_TRAITS
#define _C_CHAR_TRAITS

#include <string.h>
#include "custom/c_utility.h"


#define NULLCHR 0
#define NPOS    (size_t)(-1)

#define _DEFINE_GENERIC_CHAR_TRAITS(                                                                                                                                                        \
    CHAR_TRAITS_NAME_PREFIX,                                                                                                                                                                \
    CHAR_TYPE                                                                                                                                                                               \
)                                                                                                                                                                                           \
                                                                                                                                                                                            \
static CHAR_TYPE*           _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, copy)(CHAR_TYPE* const dest, const CHAR_TYPE* const source, size_t count);                                            \
static CHAR_TYPE*           _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, move)(CHAR_TYPE* const dest, const CHAR_TYPE* const source, size_t count);                                            \
static int                  _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t count);                                                 \
static size_t               _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(const CHAR_TYPE* str);                                                                                        \
static const CHAR_TYPE*     _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find)(const CHAR_TYPE* str, size_t count, CHAR_TYPE chr);                                                             \
static const CHAR_TYPE*     _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, assign)(CHAR_TYPE* const str, size_t count, CHAR_TYPE chr);                                                           \
                                                                                                                                                                                            \
static int                  _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare_substr)(const CHAR_TYPE* str1, size_t pos1, size_t len1, const CHAR_TYPE* str2, size_t pos2, size_t len2);    \
static size_t               _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find_substr)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t pos, size_t len);                                   \
static size_t               _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, rfind_substr)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t pos, size_t len);                                  \
                                                                                                                                                                                            \
static CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, copy)(CHAR_TYPE* const dest, const CHAR_TYPE* const source, size_t count)                                                       \
{                                                                                                                                                                                           \
    return (CHAR_TYPE*)(memcpy(dest, source, count * sizeof(CHAR_TYPE)));                                                                                                                   \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, move)(CHAR_TYPE* const dest, const CHAR_TYPE* const source, size_t count)                                                       \
{                                                                                                                                                                                           \
    return (CHAR_TYPE*)(memmove(dest, source, count * sizeof(CHAR_TYPE)));                                                                                                                  \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static int _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t count)                                                                   \
{                                                                                                                                                                                           \
    return memcmp(str1, str2, count * sizeof(CHAR_TYPE));                                                                                                                                   \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(const CHAR_TYPE* str)                                                                                                       \
{                                                                                                                                                                                           \
    size_t count = 0;                                                                                                                                                                       \
                                                                                                                                                                                            \
    for (/*Empty*/; *str != NULLCHR; ++count, ++str)                                                                                                                                        \
    {                                                                                                                                                                                       \
        /*do nothing*/                                                                                                                                                                      \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return count;                                                                                                                                                                           \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find)(const CHAR_TYPE* str, size_t count, CHAR_TYPE chr)                                                                  \
{                                                                                                                                                                                           \
    for (/*Empty*/; 0 < count; --count, ++str)                                                                                                                                              \
    {                                                                                                                                                                                       \
        if (*str == chr)                                                                                                                                                                    \
        {                                                                                                                                                                                   \
            return str;                                                                                                                                                                     \
        }                                                                                                                                                                                   \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return NULL;                                                                                                                                                                            \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, assign)(CHAR_TYPE* const str, size_t count, CHAR_TYPE chr)                                                                \
{                                                                                                                                                                                           \
    for (CHAR_TYPE* next = str; count > 0; --count, ++next)                                                                                                                                 \
    {                                                                                                                                                                                       \
        *next = chr;                                                                                                                                                                        \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return str;                                                                                                                                                                             \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static int _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare_substr)(const CHAR_TYPE* str1, size_t pos1, size_t len1, const CHAR_TYPE* str2, size_t pos2, size_t len2)                      \
{                                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(   pos1 + len1 <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str1) &&                                                                                           \
                        pos2 + len2 <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str2),                                                                                             \
                        "Char Traits invalid length or starting position");                                                                                                                 \
                                                                                                                                                                                            \
    if (len1 != len2)                                                                                                                                                                       \
    {                                                                                                                                                                                       \
        return len1 - len2;                                                                                                                                                                 \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(str1 + pos1, str2 + pos2, len1);  /* same length */                                                                           \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, find_substr)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t pos, size_t len)                                                  \
{                                                                                                                                                                                           \
    /* search in [str1 + pos, end) the string [str2, str2 + len] */                                                                                                                         \
    _C_CUSTOM_ASSERT(   pos <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str1) &&                                                                                                   \
                        len <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str2),                                                                                                     \
                        "Char Traits invalid length or starting position");                                                                                                                 \
                                                                                                                                                                                            \
    size_t last_substr_pos = _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str1) - len;                                                                                                 \
                                                                                                                                                                                            \
    for (size_t i = pos; i <= last_substr_pos; ++i)                                                                                                                                         \
	{                                                                                                                                                                                       \
        if (_C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(str1 + i, str2, len) == 0)                                                                                                   \
        {                                                                                                                                                                                   \
            return i;                                                                                                                                                                       \
        }                                                                                                                                                                                   \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return NPOS;                                                                                                                                                                            \
}                                                                                                                                                                                           \
                                                                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, rfind_substr)(const CHAR_TYPE* str1, const CHAR_TYPE* str2, size_t pos, size_t len)                                                 \
{                                                                                                                                                                                           \
	/* search in [str1, str1 + pos) the string [str2, str2 + len] from right to left */                                                                                                     \
    _C_CUSTOM_ASSERT(   pos <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str1) &&                                                                                                   \
                        len <= _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str2),                                                                                                     \
                        "Char Traits invalid length or starting position");                                                                                                                 \
                                                                                                                                                                                            \
    size_t len1 = _C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, length)(str1);                                                                                                                  \
	size_t last_substr_pos 	= (pos > len1) ? len1 - len : pos;                                                                                                                              \
                                                                                                                                                                                            \
    for (size_t i = last_substr_pos; i > 0; --i)                                                                                                                                            \
	{                                                                                                                                                                                       \
        if (_C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(str1 + i, str2, len) == 0)                                                                                                   \
        {                                                                                                                                                                                   \
            return i;                                                                                                                                                                       \
        }                                                                                                                                                                                   \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    if (_C_PUBLIC_MEMBER(CHAR_TRAITS_NAME_PREFIX, compare)(str1, str2, len) == 0)                                                                                                           \
    {                                                                                                                                                                                       \
        return 0; /* if i == 0 */                                                                                                                                                           \
    }                                                                                                                                                                                       \
                                                                                                                                                                                            \
    return NPOS;                                                                                                                                                                            \
}                                                                                                                                                                                           \


#endif  // _C_CHAR_TRAITS