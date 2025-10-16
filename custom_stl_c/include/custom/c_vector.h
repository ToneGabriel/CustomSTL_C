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
    TYPE* _first;                       \
    TYPE* _last;                        \
    TYPE* _final;                       \
} VECTOR_NAME;                          \


// ======================================================================================================================================================
// Vector Const and Normal Iterator
// ======================================================================================================================================================

#define _DEFINE_GENERIC_VECTOR_ITERATORS(                                                                                                              \
    VECTOR_CONST_ITERATOR_NAME,                                                                                                                        \
    VECTOR_ITERATOR_NAME,                                                                                                                              \
    VECTOR_NAME,                                                                                                                                       \
    TYPE                                                                                                                                               \
)                                                                                                                                                      \
                                                                                                                                                       \
typedef struct                                                                                                                                         \
{                                                                                                                                                      \
    TYPE* _ptr;                                                                                                                                        \
    const VECTOR_NAME* _vec;                                                                                                                           \
} VECTOR_CONST_ITERATOR_NAME, VECTOR_ITERATOR_NAME;                                                                                                    \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME);                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME);                                                                                        \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME);                                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_ITERATOR_NAME);                                                                                       \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME);                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_ITERATOR_NAME);                                                                                          \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME);                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_ITERATOR_NAME);                                                                                          \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME);                                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_ITERATOR_NAME);                                                                                        \
                                                                                                                                                       \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(VECTOR_CONST_ITERATOR_NAME* target);                   \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_increment)(VECTOR_ITERATOR_NAME* target);                               \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(VECTOR_CONST_ITERATOR_NAME* target);                  \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_increment)(VECTOR_ITERATOR_NAME* target);                              \
                                                                                                                                                       \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);    \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);       \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                   \
                                                                                                                                                       \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(VECTOR_CONST_ITERATOR_NAME* target);                   \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_decrement)(VECTOR_ITERATOR_NAME* target);                               \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(VECTOR_CONST_ITERATOR_NAME* target);                  \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_decrement)(VECTOR_ITERATOR_NAME* target);                              \
                                                                                                                                                       \
static void                         _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);    \
static void                         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff);       \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff);                   \
                                                                                                                                                       \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(VECTOR_CONST_ITERATOR_NAME* target);                     \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, dereference)(VECTOR_ITERATOR_NAME* target);                                 \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)                                                                                   \
{                                                                                                                                                      \
    return (VECTOR_CONST_ITERATOR_NAME){                                                                                                               \
        ._ptr = NULL,                                                                                                                                  \
        ._vec = NULL                                                                                                                                   \
    };                                                                                                                                                 \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)                                                                                         \
{                                                                                                                                                      \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                                                          \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME)                                                                                  \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    target->_ptr = NULL;                                                                                                                               \
    target->_vec = NULL;                                                                                                                               \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_ITERATOR_NAME)                                                                                        \
{                                                                                                                                                      \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_CONST_ITERATOR_NAME)(target);                                                                          \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME)                                                                                     \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector Iterator dest is NULL");                                                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "Vector Iterator source is NULL");                                                                                \
    dest->_ptr = source->_ptr;                                                                                                                         \
    dest->_vec = source->_vec;                                                                                                                         \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_ITERATOR_NAME)                                                                                           \
{                                                                                                                                                      \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_CONST_ITERATOR_NAME)(dest, source);                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME)                                                                                     \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector Iterator dest is NULL");                                                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "Vector Iterator source is NULL");                                                                                \
    dest->_ptr = source->_ptr;                                                                                                                         \
    dest->_vec = source->_vec;                                                                                                                         \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_ITERATOR_NAME)                                                                                           \
{                                                                                                                                                      \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_CONST_ITERATOR_NAME)(dest, source);                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME)                                                                                   \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != left, "Vector Iterator left is NULL");                                                                                    \
    _C_CUSTOM_ASSERT(NULL != right, "Vector Iterator right is NULL");                                                                                  \
    return left->_ptr == right->_ptr;                                                                                                                  \
}                                                                                                                                                      \
                                                                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_ITERATOR_NAME)                                                                                         \
{                                                                                                                                                      \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_CONST_ITERATOR_NAME)(left, right);                                                               \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(VECTOR_CONST_ITERATOR_NAME* target)                                            \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    _C_CUSTOM_ASSERT(target->_ptr < target->_vec->_last, "Cannot increment end iterator.");                                                            \
    ++target->_ptr;                                                                                                                                    \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_increment)(VECTOR_ITERATOR_NAME* target)                                                        \
{                                                                                                                                                      \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(target);                                                                               \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(VECTOR_CONST_ITERATOR_NAME* target)                     \
{                                                                                                                                                      \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                         \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_increment)(target);                                                                               \
    return temp;                                                                                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_increment)(VECTOR_ITERATOR_NAME* target)                                       \
{                                                                                                                                                      \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_increment)(target);                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                             \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    _C_CUSTOM_ASSERT(target->_ptr + diff < target->_vec->_last, "Cannot increment end iterator.");                                                     \
    target->_ptr += diff;                                                                                                                              \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                                         \
{                                                                                                                                                      \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(target, diff);                                                                          \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)          \
{                                                                                                                                                      \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                         \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment_by)(&temp, diff);                                                                           \
    return temp;                                                                                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, increment)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                            \
{                                                                                                                                                      \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, increment)(target, diff);                                                                      \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(VECTOR_CONST_ITERATOR_NAME* target)                                            \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    _C_CUSTOM_ASSERT(target->_ptr > target->_vec->_first, "Cannot decrement begin iterator.");                                                         \
    --target->_ptr;                                                                                                                                    \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, pre_decrement)(VECTOR_ITERATOR_NAME* target)                                                        \
{                                                                                                                                                      \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                               \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(VECTOR_CONST_ITERATOR_NAME* target)                     \
{                                                                                                                                                      \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                         \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                               \
    return temp;                                                                                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, post_decrement)(VECTOR_ITERATOR_NAME* target)                                       \
{                                                                                                                                                      \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, post_decrement)(target);                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)                             \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    _C_CUSTOM_ASSERT(target->_ptr + diff > target->_vec->_first, "Cannot decrement begin iterator.");                                                  \
    target->_ptr -= diff;                                                                                                                              \
}                                                                                                                                                      \
                                                                                                                                                       \
static void _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement_by)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                                         \
{                                                                                                                                                      \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(target, diff);                                                                          \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(VECTOR_CONST_ITERATOR_NAME* target, ptrdiff_t diff)          \
{                                                                                                                                                      \
    VECTOR_CONST_ITERATOR_NAME temp = *target;                                                                                                         \
    _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement_by)(&temp, diff);                                                                           \
    return temp;                                                                                                                                       \
}                                                                                                                                                      \
                                                                                                                                                       \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, decrement)(VECTOR_ITERATOR_NAME* target, ptrdiff_t diff)                            \
{                                                                                                                                                      \
    return _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, decrement)(target, diff);                                                                      \
}                                                                                                                                                      \
                                                                                                                                                       \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(VECTOR_CONST_ITERATOR_NAME* target)                                       \
{                                                                                                                                                      \
    _C_CUSTOM_ASSERT(NULL != target, "Vector Iterator is NULL");                                                                                       \
    _C_CUSTOM_ASSERT(target->_ptr < target->_vec->_last, "Cannot dereference end iterator.");                                                          \
    return target->_ptr;                                                                                                                               \
}                                                                                                                                                      \
                                                                                                                                                       \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_ITERATOR_NAME, dereference)(VECTOR_ITERATOR_NAME* target)                                                         \
{                                                                                                                                                      \
    return (TYPE*)(_C_PUBLIC_MEMBER(VECTOR_CONST_ITERATOR_NAME, dereference)(target));                                                                 \
}                                                                                                                                                      \


// ======================================================================================================================================================
// Vector Implementation
// ======================================================================================================================================================

/// @brief Default capacity used in vector _create function
#define GENERIC_VECTOR_DEFAULT_CAPACITY 8


#define _DEFINE_GENERIC_VECTOR_IMPL(                                                                                                        \
    VECTOR_NAME,                                                                                                                            \
    VECTOR_CONST_ITERATOR_NAME,                                                                                                             \
    VECTOR_ITERATOR_NAME,                                                                                                                   \
    VECTOR_RANGE_UTILS_NAME,                                                                                                                \
    TYPE                                                                                                                                    \
)                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_NAME);                                                                                      \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME);                                                                                     \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_NAME);                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_NAME);                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_NAME);                                                                                      \
                                                                                                                                            \
static VECTOR_NAME                  _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(size_t capacity);                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, clear)(VECTOR_NAME* target);                                              \
static size_t                       _C_PUBLIC_MEMBER(VECTOR_NAME, size)(const VECTOR_NAME* target);                                         \
static size_t                       _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(const VECTOR_NAME* target);                                     \
static bool                         _C_PUBLIC_MEMBER(VECTOR_NAME, empty)(const VECTOR_NAME* target);                                        \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, realloc)(VECTOR_NAME* target, size_t capacity);                           \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, realloc_copy)(VECTOR_NAME* target, size_t capacity, const TYPE* item);    \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back)(VECTOR_NAME* target);                                          \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_copy)(VECTOR_NAME* target, const TYPE* item);                   \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_move)(VECTOR_NAME* target, TYPE* item);                         \
static void                         _C_PUBLIC_MEMBER(VECTOR_NAME, pop_back)(VECTOR_NAME* target);                                           \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, data)(VECTOR_NAME* target);                                               \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, cdata)(const VECTOR_NAME* target);                                        \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_front)(VECTOR_NAME* target);                                      \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, celement_front)(const VECTOR_NAME* target);                               \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_back)(VECTOR_NAME* target);                                       \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, celement_back)(const VECTOR_NAME* target);                                \
static TYPE*                        _C_PUBLIC_MEMBER(VECTOR_NAME, element_at)(VECTOR_NAME* target, size_t index);                           \
static const TYPE*                  _C_PUBLIC_MEMBER(VECTOR_NAME, celement_at)(const VECTOR_NAME* target, size_t index);                    \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_NAME, cbegin)(const VECTOR_NAME* target);                                       \
static VECTOR_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(VECTOR_NAME, cend)(const VECTOR_NAME* target);                                         \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_NAME, begin)(VECTOR_NAME* target);                                              \
static VECTOR_ITERATOR_NAME         _C_PUBLIC_MEMBER(VECTOR_NAME, end)(VECTOR_NAME* target);                                                \
                                                                                                                                            \
static void                         _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(VECTOR_NAME* target);                                   \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_NAME)                                                                                       \
{                                                                                                                                           \
    return _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(GENERIC_VECTOR_DEFAULT_CAPACITY);                                                 \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)                                                                                      \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (NULL == target->_first) return;                                                                                                     \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, destroy_range)(target->_first, _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target));                  \
    free(target->_first);                                                                                                                   \
    target->_first = target->_last = target->_final = NULL;                                                                                 \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VECTOR_NAME)                                                                                         \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector dest is NULL");                                                                                  \
    _C_CUSTOM_ASSERT(NULL != source, "Vector source is NULL");                                                                              \
    if (dest == source) return;                                                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(dest);                                                                                \
    if (NULL == source->_first) return;                                                                                                     \
    size_t new_capacity = _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(source);                                                                  \
    size_t new_size = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(source);                                                                          \
    *dest = _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(new_capacity);                                                                   \
    for (size_t i = 0; i < new_size; ++i)                                                                                                   \
        _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(dest->_first + i, source->_first + i);                                                      \
    dest->_last = dest->_first + new_size;                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(VECTOR_NAME)                                                                                         \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "Vector dest is NULL");                                                                                  \
    _C_CUSTOM_ASSERT(NULL != source, "Vector source is NULL");                                                                              \
    if (dest == source) return;                                                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(dest);                                                                                \
    if (NULL == source->_first) return;                                                                                                     \
    *dest = *source;                                                                                                                        \
    source->_first = source->_last = source->_final = NULL;                                                                                 \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(VECTOR_NAME)                                                                                       \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != left, "Vector left is NULL");                                                                                  \
    _C_CUSTOM_ASSERT(NULL != right, "Vector right is NULL");                                                                                \
    if (_C_PUBLIC_MEMBER(VECTOR_NAME, size)(left) !=                                                                                        \
        _C_PUBLIC_MEMBER(VECTOR_NAME, size)(right)) return false;                                                                           \
    size_t s = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(left);                                                                                   \
    for (size_t i = 0; i < s; ++i)                                                                                                          \
        if (!_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE)(left->_first + i, right->_first + i)) return false;                                  \
    return true;                                                                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static VECTOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, create_capacity)(size_t capacity)                                                          \
{                                                                                                                                           \
    size_t new_capacity = capacity > GENERIC_VECTOR_DEFAULT_CAPACITY ? capacity : GENERIC_VECTOR_DEFAULT_CAPACITY;                          \
    TYPE* arr = (TYPE*)malloc(sizeof(TYPE) * new_capacity);                                                                                 \
    return (VECTOR_NAME){                                                                                                                   \
        ._first = arr,                                                                                                                      \
        ._last = arr,                                                                                                                       \
        ._final = arr + new_capacity                                                                                                        \
    };                                                                                                                                      \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, clear)(VECTOR_NAME* target)                                                                       \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (NULL == target->_first) return;                                                                                                     \
    size_t vec_size = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target);                                                                          \
    for (size_t i = 0; i < vec_size; ++i)                                                                                                   \
        _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(target->_first + i);                                                                     \
    target->_last = target->_first;                                                                                                         \
}                                                                                                                                           \
                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, data)(VECTOR_NAME* target)                                                                       \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    return target->_first;                                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, cdata)(const VECTOR_NAME* target)                                                          \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    return target->_first;                                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(VECTOR_NAME, size)(const VECTOR_NAME* target)                                                                \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    return target->_last - target->_first;                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(const VECTOR_NAME* target)                                                            \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    return target->_final - target->_first;                                                                                                 \
}                                                                                                                                           \
                                                                                                                                            \
static bool _C_PUBLIC_MEMBER(VECTOR_NAME, empty)(const VECTOR_NAME* target)                                                                 \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    return target->_last == target->_first;                                                                                                 \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, realloc)(VECTOR_NAME* target, size_t capacity)                                                    \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(target);                                                                              \
    target->_first = (TYPE*)malloc(sizeof(TYPE) * capacity);                                                                                \
    target->_last = target->_final = target->_first + capacity;                                                                             \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, create_range)(target->_first, capacity);                                                      \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, realloc_copy)(VECTOR_NAME* target, size_t capacity, const TYPE* item)                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(VECTOR_NAME)(target);                                                                              \
    target->_first = (TYPE*)malloc(sizeof(TYPE) * capacity);                                                                                \
    target->_last = target->_final = target->_first + capacity;                                                                             \
    _C_PUBLIC_MEMBER(VECTOR_RANGE_UTILS_NAME, create_range_copy)(target->_first, capacity, item);                                           \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back)(VECTOR_NAME* target)                                                                   \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (NULL == target->_first) return;                                                                                                     \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                \
    *target->_last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                           \
    ++target->_last;                                                                                                                        \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_copy)(VECTOR_NAME* target, const TYPE* item)                                            \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (NULL == target->_first) return;                                                                                                     \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                \
    *target->_last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                           \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(target->_last, item);                                                         \
    ++target->_last;                                                                                                                        \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, push_back_move)(VECTOR_NAME* target, TYPE* item)                                                  \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (NULL == target->_first) return;                                                                                                     \
    _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(target);                                                                                \
    *target->_last = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                           \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(target->_last, item);                                                         \
    ++target->_last;                                                                                                                        \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(VECTOR_NAME, pop_back)(VECTOR_NAME* target)                                                                    \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    if (target->_first == target->_last) return;                                                                                            \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(--target->_last);                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_front)(VECTOR_NAME* target)                                                              \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first < target->_last, "Vector element out of range");                                                        \
    return target->_first;                                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, celement_front)(const VECTOR_NAME* target)                                                 \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first < target->_last, "Vector element out of range");                                                        \
    return target->_first;                                                                                                                  \
}                                                                                                                                           \
                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_back)(VECTOR_NAME* target)                                                               \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first < target->_last, "Vector element out of range");                                                        \
    return target->_last - 1;                                                                                                               \
}                                                                                                                                           \
                                                                                                                                            \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, celement_back)(const VECTOR_NAME* target)                                                  \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first < target->_last, "Vector element out of range");                                                        \
    return target->_last - 1;                                                                                                               \
}                                                                                                                                           \
                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, element_at)(VECTOR_NAME* target, size_t index)                                                   \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first + index < target->_last, "Vector element out of range");                                                \
    return target->_first + index;                                                                                                          \
}                                                                                                                                           \
                                                                                                                                            \
static const TYPE* _C_PUBLIC_MEMBER(VECTOR_NAME, celement_at)(const VECTOR_NAME* target, size_t index)                                      \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Vector is NULL");                                                                                     \
    _C_CUSTOM_ASSERT(target->_first + index < target->_last, "Vector element out of range");                                                \
    return target->_first + index;                                                                                                          \
}                                                                                                                                           \
                                                                                                                                            \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, cbegin)(const VECTOR_NAME* target)                                          \
{                                                                                                                                           \
    VECTOR_CONST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                    \
    iter._ptr = target->_first;                                                                                                             \
    iter._vec = target;                                                                                                                     \
    return iter;                                                                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static VECTOR_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, cend)(const VECTOR_NAME* target)                                            \
{                                                                                                                                           \
    VECTOR_CONST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_CONST_ITERATOR_NAME)();                                    \
    iter._ptr = target->_last;                                                                                                              \
    iter._vec = target;                                                                                                                     \
    return iter;                                                                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, begin)(VECTOR_NAME* target)                                                       \
{                                                                                                                                           \
    VECTOR_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)();                                                \
    iter._ptr = target->_first;                                                                                                             \
    iter._vec = target;                                                                                                                     \
    return iter;                                                                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static VECTOR_ITERATOR_NAME _C_PUBLIC_MEMBER(VECTOR_NAME, end)(VECTOR_NAME* target)                                                         \
{                                                                                                                                           \
    VECTOR_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VECTOR_ITERATOR_NAME)();                                                \
    iter._ptr = target->_last;                                                                                                              \
    iter._vec = target;                                                                                                                     \
    return iter;                                                                                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PRIVATE_MEMBER(VECTOR_NAME, realloc_if_full)(VECTOR_NAME* target)                                                            \
{                                                                                                                                           \
    if (target->_last >= target->_final)                                                                                                    \
    {                                                                                                                                       \
        size_t old_size = _C_PUBLIC_MEMBER(VECTOR_NAME, size)(target);                                                                      \
        size_t old_capacity = _C_PUBLIC_MEMBER(VECTOR_NAME, capacity)(target);                                                              \
        size_t new_capacity = old_capacity + old_capacity / 2 + 1;                                                                          \
        target->_first = (TYPE*)realloc(target->_first, sizeof(TYPE) * new_capacity);                                                       \
        target->_last = target->_first + old_size;                                                                                          \
        target->_final = target->_first + new_capacity;                                                                                     \
    }                                                                                                                                       \
}                                                                                                                                           \


// ======================================================================================================================================================
// Vector COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Public macro to define a generic vector and iterators for a given type with all required dependencies.
 * @param VECTOR_NAME_PUBLIC_PREFIX     The public name prefix for generated vector (e.g., `MyVec` -> `MyVec_create`, etc.).
 * @param TYPE                          Typedef stored in the vector.
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