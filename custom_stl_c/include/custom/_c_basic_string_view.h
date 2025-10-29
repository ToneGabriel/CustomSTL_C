#ifndef _C_BASIC_STRING_VIEW_H
#define _C_BASIC_STRING_VIEW_H


#include "custom/c_utility.h"
#include "custom/_c_char_traits.h"


// ======================================================================================================================================================
// Basic String View Data
// ======================================================================================================================================================

#define _DEFINE_GENERIC_BASIC_STRING_VIEW_DATA(    \
    BASIC_STRING_VIEW,                             \
    CHAR_TYPE                                      \
)                                                  \
                                                   \
typedef struct                                     \
{                                                  \
    const CHAR_TYPE* _first;                       \
    const CHAR_TYPE* _last;                        \
} BASIC_STRING_VIEW;                               \


// ======================================================================================================================================================
// Basic String View Const Iterator (only const iterator)
// ======================================================================================================================================================

#define _DEFINE_GENERIC_BASIC_STRING_VIEW_ITERATOR(                                                                                                                                      \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME,                                                                                                                                               \
    BASIC_STRING_VIEW_NAME,                                                                                                                                                              \
    CHAR_TYPE                                                                                                                                                                            \
)                                                                                                                                                                                        \
                                                                                                                                                                                         \
typedef struct                                                                                                                                                                           \
{                                                                                                                                                                                        \
    CHAR_TYPE* _ptr;                                                                                                                                                                     \
    const BASIC_STRING_VIEW_NAME* _strview;                                                                                                                                              \
} BASIC_STRING_VIEW_CONST_ITERATOR_NAME;                                                                                                                                                 \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_VIEW_CONST_ITERATOR_NAME);                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_VIEW_CONST_ITERATOR_NAME);                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_VIEW_CONST_ITERATOR_NAME);                                                                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_VIEW_CONST_ITERATOR_NAME);                                                                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_VIEW_CONST_ITERATOR_NAME);                                                                                                         \
                                                                                                                                                                                         \
static void                                     _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target);                   \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, post_increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target);                  \
static void                                     _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, increment_by)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff);    \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff);       \
static void                                     _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target);                   \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, post_decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target);                  \
static void                                     _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, decrement_by)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff);    \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff);       \
static const CHAR_TYPE*                         _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, dereference)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target);                     \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(BASIC_STRING_VIEW_CONST_ITERATOR_NAME)                                                                                                          \
{                                                                                                                                                                                        \
    return (BASIC_STRING_VIEW_CONST_ITERATOR_NAME){                                                                                                                                      \
        ._ptr = NULL,                                                                                                                                                                    \
        ._strview = NULL                                                                                                                                                                 \
    };                                                                                                                                                                                   \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(BASIC_STRING_VIEW_CONST_ITERATOR_NAME)                                                                                                         \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    target->_ptr = NULL;                                                                                                                                                                 \
    target->_strview = NULL;                                                                                                                                                             \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(BASIC_STRING_VIEW_CONST_ITERATOR_NAME)                                                                                                            \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != dest, "String View Iterator dest is NULL");                                                                                                                 \
    _C_CUSTOM_ASSERT(NULL != source, "String View Iterator source is NULL");                                                                                                             \
    dest->_ptr = source->_ptr;                                                                                                                                                           \
    dest->_strview = source->_strview;                                                                                                                                                   \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(BASIC_STRING_VIEW_CONST_ITERATOR_NAME)                                                                                                            \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != dest, "String View Iterator dest is NULL");                                                                                                                 \
    _C_CUSTOM_ASSERT(NULL != source, "String View Iterator source is NULL");                                                                                                             \
    dest->_ptr = source->_ptr;                                                                                                                                                           \
    dest->_strview = source->_strview;                                                                                                                                                   \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(BASIC_STRING_VIEW_CONST_ITERATOR_NAME)                                                                                                          \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != left, "String View Iterator left is NULL");                                                                                                                 \
    _C_CUSTOM_ASSERT(NULL != right, "String View Iterator right is NULL");                                                                                                               \
    return left->_ptr == right->_ptr;                                                                                                                                                    \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static void _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target)                                                        \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    _C_CUSTOM_ASSERT(target->_ptr < target->_strview->_last, "Cannot increment end iterator.");                                                                                          \
    ++target->_ptr;                                                                                                                                                                      \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, post_increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target)                      \
{                                                                                                                                                                                        \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME temp = *target;                                                                                                                                \
    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_increment)(target);                                                                                                      \
    return temp;                                                                                                                                                                         \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static void _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, increment_by)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                                         \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    _C_CUSTOM_ASSERT(target->_ptr + diff < target->_strview->_last, "Cannot increment end iterator.");                                                                                   \
    target->_ptr += diff;                                                                                                                                                                \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, increment)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff)           \
{                                                                                                                                                                                        \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME temp = *target;                                                                                                                                \
    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, increment_by)(&temp, diff);                                                                                                  \
    return temp;                                                                                                                                                                         \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static void _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target)                                                        \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    _C_CUSTOM_ASSERT(target->_ptr > target->_strview->_first, "Cannot decrement begin iterator.");                                                                                       \
    --target->_ptr;                                                                                                                                                                      \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, post_decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target)                      \
{                                                                                                                                                                                        \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME temp = *target;                                                                                                                                \
    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                                                      \
    return temp;                                                                                                                                                                         \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static void _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, decrement_by)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                                         \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    _C_CUSTOM_ASSERT(target->_ptr - diff > target->_strview->_first, "Cannot decrement begin iterator.");                                                                                \
    target->_ptr -= diff;                                                                                                                                                                \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static BASIC_STRING_VIEW_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, decrement)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target, ptrdiff_t diff)           \
{                                                                                                                                                                                        \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME temp = *target;                                                                                                                                \
    _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, decrement_by)(&temp, diff);                                                                                                  \
    return temp;                                                                                                                                                                         \
}                                                                                                                                                                                        \
                                                                                                                                                                                         \
static const CHAR_TYPE* _C_PUBLIC_MEMBER(BASIC_STRING_VIEW_CONST_ITERATOR_NAME, dereference)(BASIC_STRING_VIEW_CONST_ITERATOR_NAME* target)                                              \
{                                                                                                                                                                                        \
    _C_CUSTOM_ASSERT(NULL != target, "String View Iterator is NULL");                                                                                                                    \
    _C_CUSTOM_ASSERT(target->_ptr < target->_strview->_last, "Cannot dereference end iterator.");                                                                                        \
    return target->_ptr;                                                                                                                                                                 \
}                                                                                                                                                                                        \

// ======================================================================================================================================================
// Basic String View Implementation
// ======================================================================================================================================================

#define _DEFINE_BASIC_STRING_VIEW_IMPL(       \
    BASIC_STRING_VIEW_NAME,                   \
    BASIC_STRING_VIEW_CONST_ITERATOR_NAME,    \
    CHAR_TYPE_TRAITS_NAME,                    \
    CHAR_TYPE                                 \
)                                             \

/* TODO */

// ======================================================================================================================================================
// Basic String View COMPLETE Definition
// ======================================================================================================================================================

/* TODO */


#endif  // _C_BASIC_STRING_VIEW_H