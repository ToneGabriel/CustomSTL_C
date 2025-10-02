#ifndef _C_HASH_TABLE_H
#define _C_HASH_TABLE_H

#include <math.h>           // for ceilf
#include <stdio.h>

#include "custom/c_list.h"
#include "custom/c_vector.h"
#include "custom/c_pair.h"


// ======================================================================================================================================================
// HashTable Const and Normal Iterator
// ======================================================================================================================================================

#define _DEFINE_GENERIC_HASH_TABLE_ITERATORS(                                                                                                       \
    HASH_TABLE_CONST_ITERATOR_NAME,                                                                                                                 \
    HASH_TABLE_ITERATOR_NAME,                                                                                                                       \
    LIST_CONST_ITERATOR_NAME,                                                                                                                       \
    LIST_ITERATOR_NAME,                                                                                                                             \
    VAL_TYPE                                                                                                                                        \
)                                                                                                                                                   \
                                                                                                                                                    \
typedef LIST_CONST_ITERATOR_NAME    HASH_TABLE_CONST_ITERATOR_NAME;                                                                                 \
typedef LIST_ITERATOR_NAME          HASH_TABLE_ITERATOR_NAME;                                                                                       \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_CONST_ITERATOR_NAME);                                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_ITERATOR_NAME);                                                                                 \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_CONST_ITERATOR_NAME);                                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_ITERATOR_NAME);                                                                                \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_CONST_ITERATOR_NAME);                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_ITERATOR_NAME);                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_CONST_ITERATOR_NAME);                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_ITERATOR_NAME);                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_CONST_ITERATOR_NAME);                                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME);                                                                                 \
                                                                                                                                                    \
static void                             _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, pre_increment)(HASH_TABLE_CONST_ITERATOR_NAME* target);    \
static void                             _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_increment)(HASH_TABLE_ITERATOR_NAME* target);                \
                                                                                                                                                    \
static HASH_TABLE_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, post_increment)(HASH_TABLE_CONST_ITERATOR_NAME* target);   \
static HASH_TABLE_ITERATOR_NAME         _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_increment)(HASH_TABLE_ITERATOR_NAME* target);               \
                                                                                                                                                    \
static void                             _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, pre_decrement)(HASH_TABLE_CONST_ITERATOR_NAME* target);    \
static void                             _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_decrement)(HASH_TABLE_ITERATOR_NAME* target);                \
                                                                                                                                                    \
static HASH_TABLE_CONST_ITERATOR_NAME   _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, post_decrement)(HASH_TABLE_CONST_ITERATOR_NAME* target);   \
static HASH_TABLE_ITERATOR_NAME         _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_decrement)(HASH_TABLE_ITERATOR_NAME* target);               \
                                                                                                                                                    \
static const VAL_TYPE*                  _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, dereference)(HASH_TABLE_CONST_ITERATOR_NAME* target);      \
static VAL_TYPE*                        _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, dereference)(HASH_TABLE_ITERATOR_NAME* target);                  \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_CONST_ITERATOR_NAME)                                                                            \
{                                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_CONST_ITERATOR_NAME)();                                                                         \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_ITERATOR_NAME)                                                                                  \
{                                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME)();                                                                               \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_CONST_ITERATOR_NAME)                                                                           \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_CONST_ITERATOR_NAME)(target);                                                                         \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_ITERATOR_NAME)                                                                                 \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_ITERATOR_NAME)(target);                                                                               \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_CONST_ITERATOR_NAME)                                                                              \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_CONST_ITERATOR_NAME)(dest, source);                                                                      \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_ITERATOR_NAME)                                                                                    \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_ITERATOR_NAME)(dest, source);                                                                            \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_CONST_ITERATOR_NAME)                                                                              \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_CONST_ITERATOR_NAME)(dest, source);                                                                      \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_ITERATOR_NAME)                                                                                    \
{                                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_ITERATOR_NAME)(dest, source);                                                                            \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_CONST_ITERATOR_NAME)                                                                            \
{                                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_CONST_ITERATOR_NAME)(left, right);                                                              \
}                                                                                                                                                   \
                                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME)                                                                                  \
{                                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_ITERATOR_NAME)(left, right);                                                                    \
}                                                                                                                                                   \
                                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, pre_increment)(HASH_TABLE_CONST_ITERATOR_NAME* target)                                 \
{                                                                                                                                                   \
    _C_PUBLIC_MEMBER(LIST_CONST_ITERATOR_NAME, pre_increment)(target);                                                                              \
}                                                                                                                                                   \
                                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_increment)(HASH_TABLE_ITERATOR_NAME* target)                                             \
{                                                                                                                                                   \
    _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_increment)(target);                                                                                    \
}                                                                                                                                                   \
                                                                                                                                                    \
static HASH_TABLE_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, post_increment)(HASH_TABLE_CONST_ITERATOR_NAME* target)      \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_CONST_ITERATOR_NAME, post_increment)(target);                                                                      \
}                                                                                                                                                   \
                                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_increment)(HASH_TABLE_ITERATOR_NAME* target)                        \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_increment)(target);                                                                            \
}                                                                                                                                                   \
                                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, pre_decrement)(HASH_TABLE_CONST_ITERATOR_NAME* target)                                 \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_CONST_ITERATOR_NAME, pre_decrement)(target);                                                                       \
}                                                                                                                                                   \
                                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_decrement)(HASH_TABLE_ITERATOR_NAME* target)                                             \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_decrement)(target);                                                                             \
}                                                                                                                                                   \
                                                                                                                                                    \
static HASH_TABLE_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, post_decrement)(HASH_TABLE_CONST_ITERATOR_NAME* target)      \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_CONST_ITERATOR_NAME, post_decrement)(target);                                                                      \
}                                                                                                                                                   \
                                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_decrement)(HASH_TABLE_ITERATOR_NAME* target)                        \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_decrement)(target);                                                                            \
}                                                                                                                                                   \
                                                                                                                                                    \
static const VAL_TYPE* _C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, dereference)(HASH_TABLE_CONST_ITERATOR_NAME* target)                        \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_CONST_ITERATOR_NAME, dereference)(target);                                                                         \
}                                                                                                                                                   \
                                                                                                                                                    \
static VAL_TYPE* _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, dereference)(HASH_TABLE_ITERATOR_NAME* target)                                          \
{                                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, dereference)(target);                                                                               \
}                                                                                                                                                   \


// ======================================================================================================================================================
// HashTable Implementation
// ======================================================================================================================================================

#define _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)     _C_PRIVATE_MEMBER(HASH_TABLE_NAME, extract_key)
#define _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)     _C_PRIVATE_MEMBER(HASH_TABLE_NAME, extract_map)

#define _DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME, KEY_TYPE, VAL_TYPE)             \
static const KEY_TYPE* _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(const VAL_TYPE* value)   \

#define _DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME, MAP_TYPE, VAL_TYPE)             \
static const MAP_TYPE* _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(const VAL_TYPE* value)   \


#define _HASH_TABLE_MAX_LOAD_FACTOR 0.75F
#define _HASH_TABLE_DEFAULT_NOBUCKETS 8


#define _DEFINE_GENERIC_HASH_TABLE_IMPL(                                                                                                                                                \
    HASH_TABLE_NAME,                                                                                                                                                                    \
    HASH_TABLE_LIST_VAL_TYPE_NAME,                                                                                                                                                      \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME,                                                                                                                                                 \
    HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME,                                                                                                                                         \
    HASH_TABLE_CONST_ITERATOR_NAME,                                                                                                                                                     \
    HASH_TABLE_ITERATOR_NAME,                                                                                                                                                           \
    KEY_TYPE,                                                                                                                                                                           \
    MAP_TYPE,                                                                                                                                                                           \
    VAL_TYPE                                                                                                                                                                            \
)                                                                                                                                                                                       \
                                                                                                                                                                                        \
typedef struct                                                                                                                                                                          \
{                                                                                                                                                                                       \
    HASH_TABLE_LIST_VAL_TYPE_NAME _elems;                                                                                                                                               \
    HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME _buckets;                                                                                                                                \
} HASH_TABLE_NAME;                                                                                                                                                                      \
                                                                                                                                                                                        \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME, KEY_TYPE, VAL_TYPE);    /* Defined later by umap and uset */                                                            \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME, MAP_TYPE, VAL_TYPE);    /* Defined later by umap and uset */                                                            \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_NAME);                                                                                                                              \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_NAME);                                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_NAME);                                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_NAME);                                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_NAME);                                                                                                                              \
                                                                                                                                                                                        \
static void                                 _C_PUBLIC_MEMBER(HASH_TABLE_NAME, clear)(HASH_TABLE_NAME* target);                                                                          \
static size_t                               _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(const HASH_TABLE_NAME* target);                                                                     \
static size_t                               _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(const HASH_TABLE_NAME* target);                                                             \
static size_t                               _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_size)(const HASH_TABLE_NAME* target, size_t index);                                                \
static size_t                               _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);                                              \
static bool                                 _C_PUBLIC_MEMBER(HASH_TABLE_NAME, empty)(const HASH_TABLE_NAME* target);                                                                    \
static float                                _C_PUBLIC_MEMBER(HASH_TABLE_NAME, load_factor)(const HASH_TABLE_NAME* target);                                                              \
static float                                _C_PUBLIC_MEMBER(HASH_TABLE_NAME, max_load_factor)(const HASH_TABLE_NAME* target);                                                          \
static void                                 _C_PUBLIC_MEMBER(HASH_TABLE_NAME, rehash)(HASH_TABLE_NAME* target, size_t nobuckets);                                                       \
static bool                                 _C_PUBLIC_MEMBER(HASH_TABLE_NAME, contains)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);                                            \
static HASH_TABLE_CONST_ITERATOR_NAME       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin_const)(const HASH_TABLE_NAME* target);                                                              \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin)(HASH_TABLE_NAME* target);                                                                          \
static HASH_TABLE_CONST_ITERATOR_NAME       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end_const)(const HASH_TABLE_NAME* target);                                                                \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(HASH_TABLE_NAME* target);                                                                            \
static HASH_TABLE_CONST_ITERATOR_NAME       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find_const)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);                                          \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find)(HASH_TABLE_NAME* target, const KEY_TYPE* key);                                                      \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, emplace)(HASH_TABLE_NAME* target, VAL_TYPE* item);                                                        \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase)(HASH_TABLE_NAME* target, const KEY_TYPE* key);                                                     \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase_iterator_const)(HASH_TABLE_NAME* target, HASH_TABLE_CONST_ITERATOR_NAME* where);                    \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase_iterator)(HASH_TABLE_NAME* target, HASH_TABLE_ITERATOR_NAME* where);                                \
static HASH_TABLE_ITERATOR_NAME             _C_PUBLIC_MEMBER(HASH_TABLE_NAME, emplace_key_map)(HASH_TABLE_NAME* target, const KEY_TYPE* key, const MAP_TYPE* item);                     \
static const MAP_TYPE*                      _C_PUBLIC_MEMBER(HASH_TABLE_NAME, element_at_const)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);                                    \
static MAP_TYPE*                            _C_PUBLIC_MEMBER(HASH_TABLE_NAME, element_at)(HASH_TABLE_NAME* target, const KEY_TYPE* key);                                                \
                                                                                                                                                                                        \
static HASH_TABLE_LIST_VAL_TYPE_NODE_NAME*  _C_PRIVATE_MEMBER(HASH_TABLE_NAME, find_helper)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);                                        \
static void                                 _C_PRIVATE_MEMBER(HASH_TABLE_NAME, map_and_link_node)(HASH_TABLE_NAME* target, size_t index, HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* node);     \
static void                                 _C_PRIVATE_MEMBER(HASH_TABLE_NAME, force_rehash)(HASH_TABLE_NAME* target, size_t nbuckets);                                                 \
static void                                 _C_PRIVATE_MEMBER(HASH_TABLE_NAME, rehash_if_overload)(HASH_TABLE_NAME* target);                                                            \
static size_t                               _C_PRIVATE_MEMBER(HASH_TABLE_NAME, min_load_factor_buckets)(const HASH_TABLE_NAME* target, size_t size);                                    \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_NAME)                                                                                                                               \
{                                                                                                                                                                                       \
    HASH_TABLE_NAME ret = (HASH_TABLE_NAME){                                                                                                                                            \
        ._elems = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_LIST_VAL_TYPE_NAME)(),                                                                                                 \
        ._buckets = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME)()                                                                                   \
    };                                                                                                                                                                                  \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME, force_rehash)(&ret, _HASH_TABLE_DEFAULT_NOBUCKETS);                                                                                              \
    return ret;                                                                                                                                                                         \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_NAME)                                                                                                                              \
{                                                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_LIST_VAL_TYPE_NAME)(&target->_elems);                                                                                               \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME)(&target->_buckets);                                                                                \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_NAME)                                                                                                                                 \
{                                                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_LIST_VAL_TYPE_NAME)(&dest->_elems, &source->_elems);                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME)(&dest->_buckets, &source->_buckets);                                                                  \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_NAME)                                                                                                                                 \
{                                                                                                                                                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_LIST_VAL_TYPE_NAME)(&dest->_elems, &source->_elems);                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME)(&dest->_buckets, &source->_buckets);                                                                  \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_NAME)                                                                                                                               \
{                                                                                                                                                                                       \
    if (_C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(left) != _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(right)) return false;                                                                  \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* right_current_node = right->_elems.head->next;                                                                                                  \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* right_head_node = right->_elems.head;                                                                                                           \
    while (right_current_node != right_head_node)                                                                                                                                       \
    {                                                                                                                                                                                   \
        HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* left_found_node =                                                                                                                           \
            _C_PRIVATE_MEMBER(HASH_TABLE_NAME, find_helper)(left, _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(&right_current_node->value));                                 \
        if (left_found_node == left->_elems.head ||                                                                                                                                     \
            !_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(MAP_TYPE)(                                                                                                                             \
                _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(&left_found_node->value),                                                                                       \
                _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(&right_current_node->value))) return false;                                                                     \
        right_current_node = right_current_node->next;                                                                                                                                  \
    }                                                                                                                                                                                   \
    return true;                                                                                                                                                                        \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(HASH_TABLE_NAME, clear)(HASH_TABLE_NAME* target)                                                                                                           \
{                                                                                                                                                                                       \
    _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, clear)(&target->_elems);                                                                                                            \
    size_t vec_size = _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, size)(&target->_buckets);                                                                            \
    for (size_t i = 0; i < vec_size; ++i)                                                                                                                                               \
    {                                                                                                                                                                                   \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, i)->first = 0;                                                                      \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, i)->second = NULL;                                                                  \
    }                                                                                                                                                                                   \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(const HASH_TABLE_NAME* target)                                                                                                    \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, size)(&target->_elems);                                                                                                      \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(const HASH_TABLE_NAME* target)                                                                                            \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, size)(&target->_buckets);                                                                                       \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_size)(const HASH_TABLE_NAME* target, size_t index)                                                                               \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at_const)(&target->_buckets, index)->first;                                                             \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(const HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                                             \
{                                                                                                                                                                                       \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_HASH(KEY_TYPE)(key) % _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(target);                                                                  \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static bool _C_PUBLIC_MEMBER(HASH_TABLE_NAME, empty)(const HASH_TABLE_NAME* target)                                                                                                     \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, empty)(&target->_elems);                                                                                                     \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static float _C_PUBLIC_MEMBER(HASH_TABLE_NAME, load_factor)(const HASH_TABLE_NAME* target)                                                                                              \
{                                                                                                                                                                                       \
    return  (float)(_C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(target)) /                                                                                                                  \
            (float)(_C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(target));                                                                                                           \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static float _C_PUBLIC_MEMBER(HASH_TABLE_NAME, max_load_factor)(const HASH_TABLE_NAME* target)                                                                                          \
{                                                                                                                                                                                       \
    return _HASH_TABLE_MAX_LOAD_FACTOR;                                                                                                                                                 \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static void _C_PUBLIC_MEMBER(HASH_TABLE_NAME, rehash)(HASH_TABLE_NAME* target, size_t nobuckets)                                                                                        \
{                                                                                                                                                                                       \
    /* don't violate bucket_count >= size / max_load_factor */                                                                                                                          \
    size_t min_load_factor = _C_PRIVATE_MEMBER(HASH_TABLE_NAME, min_load_factor_buckets)(target, _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(target));                                      \
    size_t new_bucket_count = min_load_factor > nobuckets ? min_load_factor : nobuckets;                                                                                                \
    if (new_bucket_count > _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(target))                                                                                                     \
        _C_PRIVATE_MEMBER(HASH_TABLE_NAME, force_rehash)(target, new_bucket_count);                                                                                                     \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static bool _C_PUBLIC_MEMBER(HASH_TABLE_NAME, contains)(const HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                                             \
{                                                                                                                                                                                       \
    HASH_TABLE_CONST_ITERATOR_NAME it_found = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find_const)(target, key);                                                                               \
    HASH_TABLE_CONST_ITERATOR_NAME it_end = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end_const)(target);                                                                                       \
    return !_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_CONST_ITERATOR_NAME)(&it_found, &it_end);                                                                                    \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin_const)(const HASH_TABLE_NAME* target)                                                                     \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, begin_const)(&target->_elems);                                                                                               \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin)(HASH_TABLE_NAME* target)                                                                                       \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, begin)(&target->_elems);                                                                                                     \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end_const)(const HASH_TABLE_NAME* target)                                                                       \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, end_const)(&target->_elems);                                                                                                 \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(HASH_TABLE_NAME* target)                                                                                         \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, end)(&target->_elems);                                                                                                       \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_CONST_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find_const)(const HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                 \
{                                                                                                                                                                                       \
    HASH_TABLE_CONST_ITERATOR_NAME it = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_CONST_ITERATOR_NAME)();                                                                          \
    it.node = _C_PRIVATE_MEMBER(HASH_TABLE_NAME, find_helper)(target, key);                                                                                                             \
    it.list = &target->_elems;                                                                                                                                                          \
    return it;                                                                                                                                                                          \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find)(HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                                   \
{                                                                                                                                                                                       \
    HASH_TABLE_ITERATOR_NAME it = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_ITERATOR_NAME)();                                                                                      \
    it.node = _C_PRIVATE_MEMBER(HASH_TABLE_NAME, find_helper)(target, key);                                                                                                             \
    it.list = &target->_elems;                                                                                                                                                          \
    return it;                                                                                                                                                                          \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, emplace)(HASH_TABLE_NAME* target, VAL_TYPE* item)                                                                     \
{                                                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != target, "Hash Table is NULL");                                                                                                                             \
    const KEY_TYPE* new_key = _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(item);                                                                                            \
    HASH_TABLE_ITERATOR_NAME it = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find)(target, new_key);                                                                                             \
    HASH_TABLE_ITERATOR_NAME it_end = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(target);                                                                                                   \
    if (!_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME)(&it, &it_end))                                                                                                   \
    {                                                                                                                                                                                   \
        /* found - do nothing and return iterator to found item */                                                                                                                      \
    }                                                                                                                                                                                   \
    else                                                                                                                                                                                \
    {                                                                                                                                                                                   \
        /* not found - create it */                                                                                                                                                     \
        HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* new_node = _C_PUBLIC_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NODE_NAME, create_ptr)();                                                              \
        new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VAL_TYPE)();                                                                                                              \
        _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(VAL_TYPE)(&new_node->value, item);                                                                                                            \
        /* map and link new node */                                                                                                                                                     \
        _C_PRIVATE_MEMBER(HASH_TABLE_NAME, rehash_if_overload)(target);                                                                                                                 \
        _C_PRIVATE_MEMBER(HASH_TABLE_NAME, map_and_link_node)(target, _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(target, new_key), new_node);                                            \
        /* update return iterator */                                                                                                                                                    \
        it.node = new_node;                                                                                                                                                             \
        it.list = &target->_elems;                                                                                                                                                      \
    }                                                                                                                                                                                   \
    return it;                                                                                                                                                                          \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase)(HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                                  \
{                                                                                                                                                                                       \
    HASH_TABLE_ITERATOR_NAME it_found = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find)(target, key);                                                                                           \
    HASH_TABLE_ITERATOR_NAME it_end = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(target);                                                                                                   \
    if (_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME)(&it_found, &it_end)) return it_found;                                                                             \
    size_t index = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(target, key);                                                                                                              \
    if (it_found.node == _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second)    /* is the starting node in bucket */            \
    {                                                                                                                                                                                   \
        if (1 == _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first) /* is the only node in bucket */                            \
            _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second = NULL;                                                          \
        else                                                                                                                                                                            \
            _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second = it_found.node->next;                                           \
    }                                                                                                                                                                                   \
    --_C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first;                                                                        \
    return it_end;  /* TODO - return list erase */                                                                                                                                      \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase_iterator_const)(HASH_TABLE_NAME* target, HASH_TABLE_CONST_ITERATOR_NAME* where)                                 \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase)(                                                                                                                                    \
                target,                                                                                                                                                                 \
                _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(_C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, dereference)(where)));                                         \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase_iterator)(HASH_TABLE_NAME* target, HASH_TABLE_ITERATOR_NAME* where)                                             \
{                                                                                                                                                                                       \
    return _C_PUBLIC_MEMBER(HASH_TABLE_NAME, erase)(                                                                                                                                    \
                target,                                                                                                                                                                 \
                _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(_C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, dereference)(where)));                                               \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, emplace_key_map)(HASH_TABLE_NAME* target, const KEY_TYPE* key, const MAP_TYPE* item)                                  \
{                                                                                                                                                                                       \
    VAL_TYPE val = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(VAL_TYPE)();                                                                                                                     \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(KEY_TYPE)((KEY_TYPE*)(_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(&val)), key);                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(MAP_TYPE)((MAP_TYPE*)(_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(&val)), item);                                                      \
    return _C_PUBLIC_MEMBER(HASH_TABLE_NAME, emplace)(target, &val);                                                                                                                    \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static const MAP_TYPE* _C_PUBLIC_MEMBER(HASH_TABLE_NAME, element_at_const)(const HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                          \
{                                                                                                                                                                                       \
    HASH_TABLE_CONST_ITERATOR_NAME it_found = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find_const)(target, key);                                                                               \
    HASH_TABLE_CONST_ITERATOR_NAME it_end = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end_const)(target);                                                                                       \
    if (_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_CONST_ITERATOR_NAME)(&it_found, &it_end)) return NULL;                                                                           \
    return _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(_C_PUBLIC_MEMBER(HASH_TABLE_CONST_ITERATOR_NAME, dereference)(&it_found));                                           \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static MAP_TYPE* _C_PUBLIC_MEMBER(HASH_TABLE_NAME, element_at)(HASH_TABLE_NAME* target, const KEY_TYPE* key)                                                                            \
{                                                                                                                                                                                       \
    HASH_TABLE_ITERATOR_NAME it_found = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, find)(target, key);                                                                                           \
    HASH_TABLE_ITERATOR_NAME it_end = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(target);                                                                                                   \
    if (_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME)(&it_found, &it_end)) return NULL;                                                                                 \
    return (MAP_TYPE*)(_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(HASH_TABLE_NAME)(_C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, dereference)(&it_found)));                                    \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* _C_PRIVATE_MEMBER(HASH_TABLE_NAME, find_helper)(const HASH_TABLE_NAME* target, const KEY_TYPE* key)                                          \
{                                                                                                                                                                                       \
    size_t remaining_nodes =                                                                                                                                                            \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at_const)(                                                                                                 \
                                                &target->_buckets,                                                                                                                      \
                                                _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(target, key))->first;                                                                         \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* current_node =                                                                                                                                  \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at_const)(                                                                                                 \
                                                &target->_buckets,                                                                                                                      \
                                                _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(target, key))->second;                                                                        \
    while ( remaining_nodes &&                                                                                                                                                          \
            !_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(KEY_TYPE)(_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(&current_node->value), key))                                         \
    {                                                                                                                                                                                   \
        current_node = current_node->next;                                                                                                                                              \
        --remaining_nodes;                                                                                                                                                              \
    }                                                                                                                                                                                   \
    if (0 == remaining_nodes) return target->_elems.head;   /* not found - return list head */                                                                                          \
    return current_node;                                                                                                                                                                \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static void _C_PRIVATE_MEMBER(HASH_TABLE_NAME, map_and_link_node)(HASH_TABLE_NAME* target, size_t index, HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* node)                                      \
{                                                                                                                                                                                       \
    if (0 == _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first)                                                                 \
    {                                                                                                                                                                                   \
        /* link last */                                                                                                                                                                 \
        _C_PRIVATE_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, link_node_before)(                                                                                                             \
                                &target->_elems,                                                                                                                                        \
                                target->_elems.head,                                                                                                                                    \
                                node);                                                                                                                                                  \
    }                                                                                                                                                                                   \
    else                                                                                                                                                                                \
    {                                                                                                                                                                                   \
        /* link before the first one in bucket */                                                                                                                                       \
        _C_PRIVATE_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, link_node_before)(                                                                                                             \
                                &target->_elems,                                                                                                                                        \
                                _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second,                                             \
                                node);                                                                                                                                                  \
    }                                                                                                                                                                                   \
    ++_C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first;                                                                        \
    _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second = node;                                                                  \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static void _C_PRIVATE_MEMBER(HASH_TABLE_NAME, force_rehash)(HASH_TABLE_NAME* target, size_t nbuckets)                                                                                  \
{                                                                                                                                                                                       \
    _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, realloc)(&target->_buckets, nbuckets);                                                                                 \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* current_node = target->_elems.head->next;                                                                                                       \
    HASH_TABLE_LIST_VAL_TYPE_NODE_NAME* head_node = target->_elems.head;                                                                                                                \
    while (current_node != head_node)                                                                                                                                                   \
    {                                                                                                                                                                                   \
        /* remap node */                                                                                                                                                                \
        size_t index = _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(target, _HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(HASH_TABLE_NAME)(&current_node->value));                                \
        if (0 == _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first)                                                             \
        {                                                                                                                                                                               \
            /* do nothing - no need to relink, bucket is empty */                                                                                                                       \
        }                                                                                                                                                                               \
        else                                                                                                                                                                            \
        {                                                                                                                                                                               \
            /* relink node before the first one in bucket */                                                                                                                            \
            _C_PRIVATE_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, unlink_node)(&target->_elems, current_node);                                                                               \
            _C_PRIVATE_MEMBER(HASH_TABLE_LIST_VAL_TYPE_NAME, link_node_before)(                                                                                                         \
                                    &target->_elems,                                                                                                                                    \
                                    _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second,                                         \
                                    current_node);                                                                                                                                      \
        }                                                                                                                                                                               \
        /* update bucket */                                                                                                                                                             \
        ++_C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->first;                                                                    \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_PAIR_COUNT_NODE_PTR_NAME, element_at)(&target->_buckets, index)->second = current_node;                                                      \
        /* next node */                                                                                                                                                                 \
        current_node = current_node->next;                                                                                                                                              \
    }                                                                                                                                                                                   \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static void _C_PRIVATE_MEMBER(HASH_TABLE_NAME, rehash_if_overload)(HASH_TABLE_NAME* target)                                                                                             \
{                                                                                                                                                                                       \
    if ((float)(_C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(target) + 1) /                                                                                                                  \
        (float)(_C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(target)) > _C_PUBLIC_MEMBER(HASH_TABLE_NAME, max_load_factor)(target))                                                  \
        _C_PRIVATE_MEMBER(HASH_TABLE_NAME, force_rehash)(target, 2 * _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(target));                                                          \
}                                                                                                                                                                                       \
                                                                                                                                                                                        \
static size_t _C_PRIVATE_MEMBER(HASH_TABLE_NAME, min_load_factor_buckets)(const HASH_TABLE_NAME* target, size_t size)                                                                   \
{                                                                                                                                                                                       \
    return (size_t)(ceilf((float)size) / _C_PUBLIC_MEMBER(HASH_TABLE_NAME, max_load_factor)(target));                                                                                   \
}                                                                                                                                                                                       \


// ======================================================================================================================================================
// HashTable COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Public macro to define a generic HashTable and iterators for given key, map, value types with all required dependencies.
 * @brief Used in c_unordered_map and c_unordered_set. Don't use it alone!
 * @param HASH_TABLE_NAME_PUBLIC_PREFIX     The public name prefix for generated list (e.g., `MyMap` -> `MyMap_create`, etc.).
 * @param KEY_TYPE                          Typedef used as key.
 * @param MAP_TYPE                          Typedef used as mapped value.
 * @param VAL_TYPE                          Typedef used as stored value (map has pair of key and map, set has only key).
 */
#define _DEFINE_GENERIC_HASH_TABLE(                                                                                                 \
    HASH_TABLE_NAME_PUBLIC_PREFIX,                                                                                                  \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_LIST(                                                                                                                \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList),                                                                    \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(                                                                                                 \
    _C_PRIVATE_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList), DoubleNode)*, /* generated from ValueList */     \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, bucket_node_ptr_t)                                                             \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(                                                                                                 \
    size_t,                                                                                                                         \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, bucket_count_t)                                                                \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_PAIR(                                                                                                                \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, CountNodePtrPair),                                                             \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, bucket_count_t),  /* same as above */                                          \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, bucket_node_ptr_t)  /* same as above */                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_VECTOR(                                                                                                              \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, BucketVector),                                                                 \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, CountNodePtrPair)                                                              \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE_ITERATORS(                                                                                               \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ConstIterator),                                                                 \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, Iterator),                                                                      \
    _C_PUBLIC_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList), ConstIterator),   /* generated from ValueList */  \
    _C_PUBLIC_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList), Iterator),        /* generated from ValueList */  \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE_IMPL(                                                                                                    \
    HASH_TABLE_NAME_PUBLIC_PREFIX,                                                                                                  \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList),                                /* same as above */                 \
    _C_PRIVATE_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ValueList), DoubleNode), /* generated from ValueList */      \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, BucketVector),                             /* same as above */                 \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, ConstIterator),                             /* same as above */                 \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, Iterator),                                  /* same as above */                 \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \


#endif  // _C_HASH_TABLE_H