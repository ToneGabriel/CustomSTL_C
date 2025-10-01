#ifndef C_VECTOR_H
#define C_VECTOR_H


#include "custom/c_utility.h"


// ======================================================================================================================================================
// Vector Data
// ======================================================================================================================================================

#define _DEFINE_GENERIC_VECTOR_DATA(    \
    VECTOR_NAME,                        \
    TYPE                                \
)                                       \
                                        \
typedef struct                          \
{                                       \
    TYPE* first;                        \
    TYPE* last;                         \
    TYPE* final;                        \
} VECTOR_NAME;                          \


// ======================================================================================================================================================
// Vector Const and Normal Iterator
// ======================================================================================================================================================

#define _DEFINE_GENERIC_VECTOR_ITERATORS(                                                                                                               \
    VECTOR_CONST_ITERATOR_NAME,                                                                                                                         \
    VECTOR_ITERATOR_NAME,                                                                                                                               \
    VECTOR_NAME,                                                                                                                                        \
    TYPE                                                                                                                                                \
)                                                                                                                                                       \
                                                                                                                                                        \
typedef struct                                                                                                                                          \
{                                                                                                                                                       \
    TYPE* ptr;                                                                                                                                          \
    const VECTOR_NAME* vec;                                                                                                                             \
} VECTOR_CONST_ITERATOR_NAME, VECTOR_ITERATOR_NAME;                                                                                                     \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME);                                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME);                                                                                         \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME);                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_ITERATOR_NAME);                                                                                        \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME);                                                                                     \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_ITERATOR_NAME);                                                                                           \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME);                                                                                     \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_ITERATOR_NAME);                                                                                           \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME);                                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_ITERATOR_NAME);                                                                                         \
                                                                                                                                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(VECTOR_CONST_ITERATOR_NAME* target);                    \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_increment)(VECTOR_ITERATOR_NAME* target);                                \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(VECTOR_CONST_ITERATOR_NAME* target);                   \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_increment)(VECTOR_ITERATOR_NAME* target);                               \
                                                                                                                                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);     \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                 \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);        \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                    \
                                                                                                                                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(VECTOR_CONST_ITERATOR_NAME* target);                    \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_decrement)(VECTOR_ITERATOR_NAME* target);                                \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(VECTOR_CONST_ITERATOR_NAME* target);                   \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_decrement)(VECTOR_ITERATOR_NAME* target);                               \
                                                                                                                                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);     \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                 \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);        \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                    \
                                                                                                                                                        \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(VECTOR_CONST_ITERATOR_NAME* target);                      \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, dereference)(VECTOR_ITERATOR_NAME* target);                                  \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)                                                                                    \
{                                                                                                                                                       \
    return (VECTOR_CONST_ITERATOR_NAME){                                                                                                                \
        .ptr = NULL,                                                                                                                                    \
        .vec = NULL                                                                                                                                     \
    };                                                                                                                                                  \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)                                                                                          \
{                                                                                                                                                       \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                                                           \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME)                                                                                   \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    target->ptr = NULL;                                                                                                                                 \
    target->vec = NULL;                                                                                                                                 \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_ITERATOR_NAME)                                                                                         \
{                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME)(target);                                                                           \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME)                                                                                      \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector Iterator dest is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(NULL != source, "Vector Iterator source is NULL");                                                                                 \
    dest->ptr = source->ptr;                                                                                                                            \
    dest->vec = source->vec;                                                                                                                            \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_ITERATOR_NAME)                                                                                            \
{                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME)(dest, source);                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME)                                                                                      \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector Iterator dest is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(NULL != source, "Vector Iterator source is NULL");                                                                                 \
    dest->ptr = source->ptr;                                                                                                                            \
    dest->vec = source->vec;                                                                                                                            \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_ITERATOR_NAME)                                                                                            \
{                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME)(dest, source);                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME)                                                                                    \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != left, "Vector Iterator left is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(NULL != right, "Vector Iterator right is NULL");                                                                                   \
    return left->ptr == right->ptr;                                                                                                                     \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_ITERATOR_NAME)                                                                                          \
{                                                                                                                                                       \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME)(left, right);                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(VECTOR_CONST_ITERATOR_NAME* target)                                             \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    _C_CUSTOM_ASSERT(target->ptr < target->vec->last, "Cannot increment end iterator.");                                                                \
    ++target->ptr;                                                                                                                                      \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_increment)(VECTOR_ITERATOR_NAME* target)                                                         \
{                                                                                                                                                       \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(target);                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(VECTOR_CONST_ITERATOR_NAME* target)                      \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                          \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(target);                                                                                \
    return temp;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_increment)(VECTOR_ITERATOR_NAME* target)                                        \
{                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(target);                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                              \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    _C_CUSTOM_ASSERT(target->ptr + diff < target->vec->last, "Cannot increment end iterator.");                                                         \
    target->ptr += diff;                                                                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                                          \
{                                                                                                                                                       \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(target, diff);                                                                           \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)           \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                          \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(&temp, diff);                                                                            \
    return temp;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                             \
{                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(target, diff);                                                                       \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(VECTOR_CONST_ITERATOR_NAME* target)                                             \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    _C_CUSTOM_ASSERT(target->ptr > target->vec->first, "Cannot decrement begin iterator.");                                                             \
    --target->ptr;                                                                                                                                      \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_decrement)(VECTOR_ITERATOR_NAME* target)                                                         \
{                                                                                                                                                       \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(VECTOR_CONST_ITERATOR_NAME* target)                      \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                          \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                                \
    return temp;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_decrement)(VECTOR_ITERATOR_NAME* target)                                        \
{                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(target);                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                              \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    _C_CUSTOM_ASSERT(target->ptr + diff > target->vec->first, "Cannot decrement begin iterator.");                                                      \
    target->ptr -= diff;                                                                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                                          \
{                                                                                                                                                       \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(target, diff);                                                                           \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)           \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                          \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(&temp, diff);                                                                            \
    return temp;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                             \
{                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(target, diff);                                                                       \
}                                                                                                                                                       \
                                                                                                                                                        \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(VECTOR_CONST_ITERATOR_NAME* target)                                        \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                        \
    _C_CUSTOM_ASSERT(target->ptr < target->vec->last, "Cannot dereference end iterator.");                                                              \
    return target->ptr;                                                                                                                                 \
}                                                                                                                                                       \
                                                                                                                                                        \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, dereference)(VECTOR_ITERATOR_NAME* target)                                                          \
{                                                                                                                                                       \
    return (TYPE*)(_C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(target));                                                                  \
}                                                                                                                                                       \


// ======================================================================================================================================================
// Vector Implementation
// ======================================================================================================================================================

/// @brief Default capacity used in vector _create function
#define GENERIC_VECTOR_DEFAULT_CAPACITY 8

/**
 * @def _DEFINE_GENERIC_VECTOR_IMPL
 * @brief Internal macro that defines the complete implementation of a vector.
 *
 * This macro generates a full implementation of a dynamic array.
 * The generated vector operates on elements of type `TYPE`.
 *
 * @param VECTOR_NAME               Public-facing name prefix for struct and functions
 * @param VECTOR_ITERATOR_NAME      Public-facing name prefix for iterator struct and functions
 * @param TYPE                      Type of elements to be stored in the vector.
 */
#define _DEFINE_GENERIC_VECTOR_IMPL(                                                                                                                    \
    VECTOR_NAME,                                                                                                                                        \
    VECTOR_CONST_ITERATOR_NAME,                                                                                                                         \
    VECTOR_ITERATOR_NAME,                                                                                                                               \
    VECTOR_RANGE_UTILS_NAME,                                                                                                                            \
    TYPE                                                                                                                                                \
)                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_NAME);                                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME);                                                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_NAME);                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_NAME);                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_NAME);                                                                                                  \
                                                                                                                                                        \
static VECTOR_NAME                  _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(size_t capacity);                                                    \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, clear)(VECTOR_NAME* target);                                                          \
static size_t                       _C_PUBLIC_MEMBER(VECTOR_NAME, size)(const VECTOR_NAME* target);                                                     \
static size_t                       _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(const VECTOR_NAME* target);                                                 \
static bool                         _C_PUBLIC_MEMBER(VECTOR_NAME, empty)(const VECTOR_NAME* target);                                                    \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, realloc)(VECTOR_NAME* target, size_t capacity);                                       \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, realloc_copy)(VECTOR_NAME* target, size_t capacity, const TYPE* item);                \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back)(VECTOR_NAME* target);                                                      \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_copy)(VECTOR_NAME* target, const TYPE* item);                               \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_move)(VECTOR_NAME* target, TYPE* item);                                     \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, pop_back)(VECTOR_NAME* target);                                                       \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, data)(VECTOR_NAME* target);                                                           \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, data_const)(const VECTOR_NAME* target);                                               \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_front)(VECTOR_NAME* target);                                                  \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, element_front_const)(VECTOR_NAME* target);                                            \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_back)(VECTOR_NAME* target);                                                   \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, element_back_const)(VECTOR_NAME* target);                                             \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_at)(VECTOR_NAME* target, size_t index);                                       \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, element_at_const)(const VECTOR_NAME* target, size_t index);                           \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_NAME, begin_const)(VECTOR_NAME* target);                                                    \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_NAME, end_const)(VECTOR_NAME* target);                                                      \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_NAME, begin)(VECTOR_NAME* target);                                                          \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_NAME, end)(VECTOR_NAME* target);                                                            \
                                                                                                                                                        \
static void                         _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(VECTOR_NAME* target);                                               \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_NAME)                                                                                                   \
{                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(GENERIC_VECTOR_DEFAULT_CAPACITY);                                                             \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)                                                                                                  \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (NULL == target->first) return;                                                                                                                  \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, destroy_range)(target->first, _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target));                               \
    free(target->first);                                                                                                                                \
    target->first = target->last = target->final = NULL;                                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_NAME)                                                                                                     \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector dest is NULL");                                                                                              \
    _C_CUSTOM_ASSERT(NULL != source, "Vector source is NULL");                                                                                          \
    if (dest == source) return;                                                                                                                         \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(dest);                                                                                            \
    if (NULL == source->first) return;                                                                                                                  \
    size_t newCapacity = _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(source);                                                                               \
    size_t newSize = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(source);                                                                                       \
    *dest = _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(newCapacity);                                                                                \
    for (size_t i = 0; i < newSize; ++i)                                                                                                                \
        _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(dest->first + i, source->first + i);                                                                    \
    dest->last = dest->first + newSize;                                                                                                                 \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_NAME)                                                                                                     \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector dest is NULL");                                                                                              \
    _C_CUSTOM_ASSERT(NULL != source, "Vector source is NULL");                                                                                          \
    if (dest == source) return;                                                                                                                         \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(dest);                                                                                            \
    if (NULL == source->first) return;                                                                                                                  \
    *dest = *source;                                                                                                                                    \
    source->first = source->last = source->final = NULL;                                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_NAME)                                                                                                   \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != left, "Vector left is NULL");                                                                                              \
    _C_CUSTOM_ASSERT(NULL != right, "Vector right is NULL");                                                                                            \
    if (_C_PUBLIC_MEMBER(VECTOR_NAME, size)(left) !=                                                                                                    \
        _C_PUBLIC_MEMBER(VECTOR_NAME, size)(right)) return false;                                                                                       \
    size_t s = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(left);                                                                                               \
    for (size_t i = 0; i < s; ++i)                                                                                                                      \
        if (!_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE)(left->first + i, right->first + i)) return false;                                                \
    return true;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(size_t capacity)                                                                      \
{                                                                                                                                                       \
    size_t newCapacity = capacity > GENERIC_VECTOR_DEFAULT_CAPACITY ? capacity : GENERIC_VECTOR_DEFAULT_CAPACITY;                                       \
    TYPE* arr = (TYPE*)malloc(sizeof(TYPE) * newCapacity);                                                                                              \
    return (VECTOR_NAME){                                                                                                                               \
        .first = arr,                                                                                                                                   \
        .last = arr,                                                                                                                                    \
        .final = arr + newCapacity                                                                                                                      \
    };                                                                                                                                                  \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, clear)(VECTOR_NAME* target)                                                                                   \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (NULL == target->first) return;                                                                                                                  \
    size_t vec_size = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target);                                                                                      \
    for (size_t i = 0; i < vec_size; ++i)                                                                                                               \
        _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(target->first + i);                                                                                  \
    target->last = target->first;                                                                                                                       \
}                                                                                                                                                       \
                                                                                                                                                        \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, data)(VECTOR_NAME* target)                                                                                   \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    return target->first;                                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, data_const)(const VECTOR_NAME* target)                                                                 \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    return target->first;                                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(VECTOR_NAME, size)(const VECTOR_NAME* target)                                                                            \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    return target->last - target->first;                                                                                                                \
}                                                                                                                                                       \
                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(const VECTOR_NAME* target)                                                                        \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    return target->final - target->first;                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static bool _C_PUBLIC_MEMBER(VECTOR_NAME, empty)(const VECTOR_NAME* target)                                                                             \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    return target->last == target->first;                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, realloc)(VECTOR_NAME* target, size_t capacity)                                                                \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(target);                                                                                          \
    target->first = (TYPE*)malloc(sizeof(TYPE) * capacity);                                                                                             \
    target->last = target->final = target->first + capacity;                                                                                            \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, create_range)(target->first, capacity);                                                                   \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, realloc_copy)(VECTOR_NAME* target, size_t capacity, const TYPE* item)                                         \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(target);                                                                                          \
    target->first = (TYPE*)malloc(sizeof(TYPE) * capacity);                                                                                             \
    target->last = target->final = target->first + capacity;                                                                                            \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, create_range_copy)(target->first, capacity, item);                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back)(VECTOR_NAME* target)                                                                               \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (NULL == target->first) return;                                                                                                                  \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                            \
    *target->last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                        \
    ++target->last;                                                                                                                                     \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_copy)(VECTOR_NAME* target, const TYPE* item)                                                        \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (NULL == target->first) return;                                                                                                                  \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                            \
    *target->last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                        \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(target->last, item);                                                                      \
    ++target->last;                                                                                                                                     \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_move)(VECTOR_NAME* target, TYPE* item)                                                              \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (NULL == target->first) return;                                                                                                                  \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                            \
    *target->last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                        \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(target->last, item);                                                                      \
    ++target->last;                                                                                                                                     \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, pop_back)(VECTOR_NAME* target)                                                                                \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    if (target->first == target->last) return;                                                                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(--target->last);                                                                                         \
}                                                                                                                                                       \
                                                                                                                                                        \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_front)(VECTOR_NAME* target)                                                                          \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first < target->last, "Vector element out of range");                                                                      \
    return target->first;                                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_front_const)(VECTOR_NAME* target)                                                              \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first < target->last, "Vector element out of range");                                                                      \
    return target->first;                                                                                                                               \
}                                                                                                                                                       \
                                                                                                                                                        \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_back)(VECTOR_NAME* target)                                                                           \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first < target->last, "Vector element out of range");                                                                      \
    return target->last - 1;                                                                                                                            \
}                                                                                                                                                       \
                                                                                                                                                        \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_back_const)(VECTOR_NAME* target)                                                               \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first < target->last, "Vector element out of range");                                                                      \
    return target->last - 1;                                                                                                                            \
}                                                                                                                                                       \
                                                                                                                                                        \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_at)(VECTOR_NAME* target, size_t index)                                                               \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first + index < target->last, "Vector element out of range");                                                              \
    return target->first + index;                                                                                                                       \
}                                                                                                                                                       \
                                                                                                                                                        \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_at_const)(const VECTOR_NAME* target, size_t index)                                             \
{                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                                 \
    _C_CUSTOM_ASSERT(target->first + index < target->last, "Vector element out of range");                                                              \
    return target->first + index;                                                                                                                       \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, begin_const)(VECTOR_NAME* target)                                                       \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                                \
    iter.ptr = target->first;                                                                                                                           \
    iter.vec = target;                                                                                                                                  \
    return iter;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, end_const)(VECTOR_NAME* target)                                                         \
{                                                                                                                                                       \
    VECTOR_CONST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                                \
    iter.ptr = target->last;                                                                                                                            \
    iter.vec = target;                                                                                                                                  \
    return iter;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, begin)(VECTOR_NAME* target)                                                                   \
{                                                                                                                                                       \
    VECTOR_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)();                                                            \
    iter.ptr = target->first;                                                                                                                           \
    iter.vec = target;                                                                                                                                  \
    return iter;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, end)(VECTOR_NAME* target)                                                                     \
{                                                                                                                                                       \
    VECTOR_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)();                                                            \
    iter.ptr = target->last;                                                                                                                            \
    iter.vec = target;                                                                                                                                  \
    return iter;                                                                                                                                        \
}                                                                                                                                                       \
                                                                                                                                                        \
static void _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(VECTOR_NAME* target)                                                                        \
{                                                                                                                                                       \
    if (target->last >= target->final)                                                                                                                  \
    {                                                                                                                                                   \
        size_t oldSize = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target);                                                                                   \
        size_t oldCapacity = _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(target);                                                                           \
        size_t newCapacity = oldCapacity + oldCapacity / 2 + 1;                                                                                         \
        target->first = (TYPE*)realloc(target->first, sizeof(TYPE) * newCapacity);                                                                      \
        target->last = target->first + oldSize;                                                                                                         \
        target->final = target->first + newCapacity;                                                                                                    \
    }                                                                                                                                                   \
}                                                                                                                                                       \



// ======================================================================================================================================================
// Vector COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Public macro to define a generic vector for a given type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - The vector API (   `_create`, `_create_capacity`, `_destroy`, `_clear`, `_copy`, `_move`, `_data`, `_size`, `_capacity`, `_empty`,
 *                      `_realloc`, `_realloc_copy`,
 *                      `_push_back`, `_push_back_copy`, `_push_back_move`, `_pop_back`, `_element_front`, `_element_back`, `_element_at`, `_equals`,
 *                      `_begin`, `_end`
 *                  )
 * 
 * @param VECTOR_NAME_PUBLIC_PREFIX     The public name prefix for generated vector (e.g., `MyVec` -> `MyVec_create`, etc.).
 * @param TYPE                          Type stored in the vector.
 */
#define DEFINE_GENERIC_VECTOR(                                                                  \
    VECTOR_NAME_PUBLIC_PREFIX,                                                                  \
    TYPE                                                                                        \
)                                                                                               \
                                                                                                \
_DEFINE_GENERIC_VECTOR_DATA(                                                                    \
    VECTOR_NAME_PUBLIC_PREFIX,                                                                  \
    TYPE                                                                                        \
)                                                                                               \
                                                                                                \
_DEFINE_GENERIC_VECTOR_ITERATORS(                                                               \
    _C_PUBLIC_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, ConstIterator),                                 \
    _C_PUBLIC_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, Iterator),                                      \
    VECTOR_NAME_PUBLIC_PREFIX,                                                                  \
    TYPE                                                                                        \
)                                                                                               \
                                                                                                \
DEFINE_GENERIC_RANGE_UTILS(                                                                     \
    _C_PRIVATE_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, RangeUtils),                                   \
    TYPE                                                                                        \
)                                                                                               \
                                                                                                \
_DEFINE_GENERIC_VECTOR_IMPL(                                                                    \
    VECTOR_NAME_PUBLIC_PREFIX,                                                                  \
    _C_PUBLIC_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, ConstIterator), /*same as above*/               \
    _C_PUBLIC_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, Iterator),      /*same as above*/               \
    _C_PRIVATE_MEMBER(VECTOR_NAME_PUBLIC_PREFIX, RangeUtils),   /*same as above*/               \
    TYPE                                                                                        \
)                                                                                               \


#endif  // C_VECTOR_H