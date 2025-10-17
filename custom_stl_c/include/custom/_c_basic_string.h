#ifndef _C_BASIC_STRING_H
#define _C_BASIC_STRING_H


#include "custom/c_utility.h"
#include "custom/_c_char_traits.h"


// ======================================================================================================================================================
// Basic String Data
// ======================================================================================================================================================

#define _DEFINE_GENERIC_BASIC_STRING_DATA(              \
    BASIC_STRING_NAME,                                  \
    CHAR_TYPE                                           \
)                                                       \
                                                        \
typedef struct                                          \
{                                                       \
    union                                               \
    {                                                   \
        CHAR_TYPE _buff[16];                            \
        CHAR_TYPE* _ptr;                                \
    } _storage;                                         \
    size_t _size;                                       \
    size_t _capacity;                                   \
                                                        \
    CHAR_TYPE* first;                                   \
    CHAR_TYPE* last;                                    \
    CHAR_TYPE* final;                                   \
} BASIC_STRING_NAME;                                    \


// ======================================================================================================================================================
// Basic String Const and Normal Iterator
// ======================================================================================================================================================

#define _DEFINE_GENERIC_BASIC_STRING_ITERATORS(                                                                                                                             \
    BASIC_STRING_CONST_ITERATOR_NAME,                                                                                                                                       \
    BASIC_STRING_ITERATOR_NAME,                                                                                                                                             \
    BASIC_STRING_NAME,                                                                                                                                                      \
    CHAR_TYPE                                                                                                                                                               \
)                                                                                                                                                                           \
                                                                                                                                                                            \
typedef struct                                                                                                                                                              \
{                                                                                                                                                                           \
    CHAR_TYPE* _ptr;                                                                                                                                                        \
    const BASIC_STRING_NAME* _str;                                                                                                                                          \
} BASIC_STRING_CONST_ITERATOR_NAME, BASIC_STRING_ITERATOR_NAME;                                                                                                             \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_CONST_ITERATOR_NAME);                                                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_ITERATOR_NAME);                                                                                                       \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_CONST_ITERATOR_NAME);                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_ITERATOR_NAME);                                                                                                      \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_CONST_ITERATOR_NAME);                                                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_ITERATOR_NAME);                                                                                                         \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_CONST_ITERATOR_NAME);                                                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_ITERATOR_NAME);                                                                                                         \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_CONST_ITERATOR_NAME);                                                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_ITERATOR_NAME);                                                                                                       \
                                                                                                                                                                            \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_increment)(BASIC_STRING_CONST_ITERATOR_NAME* target);                    \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, pre_increment)(BASIC_STRING_ITERATOR_NAME* target);                                \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_increment)(BASIC_STRING_CONST_ITERATOR_NAME* target);                   \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, post_increment)(BASIC_STRING_ITERATOR_NAME* target);                               \
                                                                                                                                                                            \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment_by)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff);     \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, increment_by)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff);                 \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff);        \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, increment)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff);                    \
                                                                                                                                                                            \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target);                    \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, pre_decrement)(BASIC_STRING_ITERATOR_NAME* target);                                \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target);                   \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, post_decrement)(BASIC_STRING_ITERATOR_NAME* target);                               \
                                                                                                                                                                            \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement_by)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff);     \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, decrement_by)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff);                 \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff);        \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, decrement)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff);                    \
                                                                                                                                                                            \
static const CHAR_TYPE*                     _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, dereference)(BASIC_STRING_CONST_ITERATOR_NAME* target);                      \
static CHAR_TYPE*                           _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, dereference)(BASIC_STRING_ITERATOR_NAME* target);                                  \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_CONST_ITERATOR_NAME)                                                                                                  \
{                                                                                                                                                                           \
    return (BASIC_STRING_CONST_ITERATOR_NAME){                                                                                                                              \
        ._ptr = NULL,                                                                                                                                                       \
        ._str = NULL                                                                                                                                                        \
    };                                                                                                                                                                      \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_ITERATOR_NAME)                                                                                                        \
{                                                                                                                                                                           \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_CONST_ITERATOR_NAME)();                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_CONST_ITERATOR_NAME)                                                                                                 \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    target->_ptr = NULL;                                                                                                                                                    \
    target->_str = NULL;                                                                                                                                                    \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_ITERATOR_NAME)                                                                                                       \
{                                                                                                                                                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_CONST_ITERATOR_NAME)(target);                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_CONST_ITERATOR_NAME)                                                                                                    \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "String Iterator dest is NULL");                                                                                                         \
    _C_CUSTOM_ASSERT(NULL != source, "String Iterator source is NULL");                                                                                                     \
    dest->_ptr = source->_ptr;                                                                                                                                              \
    dest->_str = source->_str;                                                                                                                                              \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_ITERATOR_NAME)                                                                                                          \
{                                                                                                                                                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_CONST_ITERATOR_NAME)(dest, source);                                                                                      \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_CONST_ITERATOR_NAME)                                                                                                    \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "String Iterator dest is NULL");                                                                                                         \
    _C_CUSTOM_ASSERT(NULL != source, "String Iterator source is NULL");                                                                                                     \
    dest->_ptr = source->_ptr;                                                                                                                                              \
    dest->_str = source->_str;                                                                                                                                              \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_ITERATOR_NAME)                                                                                                          \
{                                                                                                                                                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_CONST_ITERATOR_NAME)(dest, source);                                                                                      \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_CONST_ITERATOR_NAME)                                                                                                  \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != left, "String Iterator left is NULL");                                                                                                         \
    _C_CUSTOM_ASSERT(NULL != right, "String Iterator right is NULL");                                                                                                       \
    return left->_ptr == right->_ptr;                                                                                                                                       \
}                                                                                                                                                                           \
                                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_ITERATOR_NAME)                                                                                                        \
{                                                                                                                                                                           \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_CONST_ITERATOR_NAME)(left, right);                                                                              \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_increment)(BASIC_STRING_CONST_ITERATOR_NAME* target)                                                     \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    _C_CUSTOM_ASSERT(target->_ptr < target->_str->last, "Cannot increment end iterator.");                                                                                  \
    ++target->_ptr;                                                                                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, pre_increment)(BASIC_STRING_ITERATOR_NAME* target)                                                                 \
{                                                                                                                                                                           \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_increment)(target);                                                                                              \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_increment)(BASIC_STRING_CONST_ITERATOR_NAME* target)                        \
{                                                                                                                                                                           \
    BASIC_STRING_CONST_ITERATOR_NAME temp = *target;                                                                                                                        \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_increment)(target);                                                                                              \
    return temp;                                                                                                                                                            \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, post_increment)(BASIC_STRING_ITERATOR_NAME* target)                                          \
{                                                                                                                                                                           \
    return _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_increment)(target);                                                                                      \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment_by)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                                      \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    _C_CUSTOM_ASSERT(target->_ptr + diff < target->_str->last, "Cannot increment end iterator.");                                                                           \
    target->_ptr += diff;                                                                                                                                                   \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, increment_by)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff)                                                  \
{                                                                                                                                                                           \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment_by)(target, diff);                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff)             \
{                                                                                                                                                                           \
    BASIC_STRING_CONST_ITERATOR_NAME temp = *target;                                                                                                                        \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment_by)(&temp, diff);                                                                                          \
    return temp;                                                                                                                                                            \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, increment)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff)                               \
{                                                                                                                                                                           \
    return _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, increment)(target, diff);                                                                                     \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target)                                                     \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    _C_CUSTOM_ASSERT(target->_ptr > target->_str->first, "Cannot decrement begin iterator.");                                                                               \
    --target->_ptr;                                                                                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, pre_decrement)(BASIC_STRING_ITERATOR_NAME* target)                                                                 \
{                                                                                                                                                                           \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                                              \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target)                        \
{                                                                                                                                                                           \
    BASIC_STRING_CONST_ITERATOR_NAME temp = *target;                                                                                                                        \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                                              \
    return temp;                                                                                                                                                            \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, post_decrement)(BASIC_STRING_ITERATOR_NAME* target)                                          \
{                                                                                                                                                                           \
    return _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, post_decrement)(target);                                                                                      \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement_by)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                                      \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    _C_CUSTOM_ASSERT(target->_ptr + diff > target->_str->first, "Cannot decrement begin iterator.");                                                                        \
    target->_ptr -= diff;                                                                                                                                                   \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, decrement_by)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff)                                                  \
{                                                                                                                                                                           \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement_by)(target, diff);                                                                                         \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement)(BASIC_STRING_CONST_ITERATOR_NAME* target, ptrdiff_t diff)             \
{                                                                                                                                                                           \
    BASIC_STRING_CONST_ITERATOR_NAME temp = *target;                                                                                                                        \
    _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement_by)(&temp, diff);                                                                                          \
    return temp;                                                                                                                                                            \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static BASIC_STRING_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, decrement)(BASIC_STRING_ITERATOR_NAME* target, ptrdiff_t diff)                               \
{                                                                                                                                                                           \
    return _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, decrement)(target, diff);                                                                                     \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, dereference)(BASIC_STRING_CONST_ITERATOR_NAME* target)                                           \
{                                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "String Iterator is NULL");                                                                                                            \
    _C_CUSTOM_ASSERT(target->_ptr < target->_str->last, "Cannot dereference end iterator.");                                                                                \
    return target->_ptr;                                                                                                                                                    \
}                                                                                                                                                                           \
                                                                                                                                                                            \
static CHAR_TYPE* _C_PUBLIC_MEMBER(BASIC_STRING_ITERATOR_NAME, dereference)(BASIC_STRING_ITERATOR_NAME* target)                                                             \
{                                                                                                                                                                           \
    return (CHAR_TYPE*)(_C_PUBLIC_MEMBER(BASIC_STRING_CONST_ITERATOR_NAME, dereference)(target));                                                                           \
}                                                                                                                                                                           \


// ======================================================================================================================================================
// Basic String Implementation
// ======================================================================================================================================================

#define _DEFINE_BASIC_STRING_IMPL(                                                                                                                          \
    BASIC_STRING_NAME,                                                                                                                                      \
    BASIC_STRING_CONST_ITERATOR_NAME,                                                                                                                       \
    BASIC_STRING_ITERATOR_NAME,                                                                                                                             \
    CHAR_TYPE_TRAITS_NAME,                                                                                                                                  \
    CHAR_TYPE                                                                                                                                               \
)                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_NAME);                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_NAME);                                                                                               \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_NAME);                                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_NAME);                                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_NAME);                                                                                                \
                                                                                                                                                            \
static BASIC_STRING_NAME                    _C_PUBLIC_MEMBER(BASIC_STRING_NAME, create_capacity)(size_t capacity);                                          \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_NAME, clear)(BASIC_STRING_NAME* target);                                          \
static size_t                               _C_PUBLIC_MEMBER(BASIC_STRING_NAME, size)(const BASIC_STRING_NAME* target);                                     \
static size_t                               _C_PUBLIC_MEMBER(BASIC_STRING_NAME, capacity)(const BASIC_STRING_NAME* target);                                 \
static bool                                 _C_PUBLIC_MEMBER(BASIC_STRING_NAME, empty)(const BASIC_STRING_NAME* target);                                    \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_NAME, push_back)(BASIC_STRING_NAME* target, CHAR_TYPE chr);                       \
static void                                 _C_PUBLIC_MEMBER(BASIC_STRING_NAME, pop_back)(BASIC_STRING_NAME* target);                                       \
static CHAR_TYPE*                           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, data)(BASIC_STRING_NAME* target);                                           \
static const CHAR_TYPE*                     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, cdata)(const BASIC_STRING_NAME* target);                                    \
static CHAR_TYPE*                           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, element_front)(BASIC_STRING_NAME* target);                                  \
static const CHAR_TYPE*                     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, celement_front)(const BASIC_STRING_NAME* target);                           \
static CHAR_TYPE*                           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, element_back)(BASIC_STRING_NAME* target);                                   \
static const CHAR_TYPE*                     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, celement_back)(const BASIC_STRING_NAME* target);                            \
static CHAR_TYPE*                           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, element_at)(BASIC_STRING_NAME* target, size_t index);                       \
static const CHAR_TYPE*                     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, celement_at)(const BASIC_STRING_NAME* target, size_t index);                \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, cbegin)(const BASIC_STRING_NAME* target);                                   \
static BASIC_STRING_CONST_ITERATOR_NAME     _C_PUBLIC_MEMBER(BASIC_STRING_NAME, cend)(const BASIC_STRING_NAME* target);                                     \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, begin)(BASIC_STRING_NAME* target);                                          \
static BASIC_STRING_ITERATOR_NAME           _C_PUBLIC_MEMBER(BASIC_STRING_NAME, end)(BASIC_STRING_NAME* target);                                            \
                                                                                                                                                            \
static void                                 _C_PRIVATE_MEMBER(BASIC_STRING_NAME, realloc_if_full)(BASIC_STRING_NAME* target);                               \

// TODO


// ======================================================================================================================================================
// Basic String COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Public macro to define a generic basic string and iterators for a given char type with all required dependencies.
 * @param BASIC_STRING_PUBLIC_PREFIX    The public name prefix for generated string (e.g., `String` -> `String_create`, etc.).
 * @param CHAR_TYPE                     Char type stored in the string.
 */
#define _DEFINE_BASIC_STRING(                                                           \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_GENERIC_CHAR_TRAITS(                                                            \
    _C_PRIVATE_MEMBER(BASIC_STRING_PUBLIC_PREFIX, CharTraits),                          \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_GENERIC_BASIC_STRING_DATA(                                                      \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_GENERIC_BASIC_STRING_ITERATORS(                                                 \
    _C_PUBLIC_MEMBER(BASIC_STRING_PUBLIC_PREFIX, ConstIterator),                        \
    _C_PUBLIC_MEMBER(BASIC_STRING_PUBLIC_PREFIX, Iterator),                             \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_BASIC_STRING_IMPL(                                                              \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    _C_PUBLIC_MEMBER(BASIC_STRING_PUBLIC_PREFIX, ConstIterator),    /*same as above*/   \
    _C_PUBLIC_MEMBER(BASIC_STRING_PUBLIC_PREFIX, Iterator),         /*same as above*/   \
    _C_PRIVATE_MEMBER(BASIC_STRING_PUBLIC_PREFIX, CharTraits),      /*same as above*/   \
    CHAR_TYPE                                                                           \
)                                                                                       \


#endif  // _C_BASIC_STRING_H