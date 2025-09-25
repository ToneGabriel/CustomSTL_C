#ifndef _C_HASH_TABLE_H
#define _C_HASH_TABLE_H


#include "custom/c_list.h"
#include "custom/c_vector.h"
#include "custom/c_pair.h"


#define _DEFINE_GENERIC_HASH_TABLE_ITERATOR(                                                                                        \
    HASH_TABLE_ITERATOR_NAME,                                                                                                       \
    LIST_ITERATOR_NAME,                                                                                                             \
    TYPE                                                                                                                            \
)                                                                                                                                   \
                                                                                                                                    \
typedef LIST_ITERATOR_NAME HASH_TABLE_ITERATOR_NAME;                                                                                \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_ITERATOR_NAME);                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_ITERATOR_NAME);                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_ITERATOR_NAME);                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_ITERATOR_NAME);                                                                   \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME);                                                                 \
                                                                                                                                    \
static void                     _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_increment)(HASH_TABLE_ITERATOR_NAME* iter);          \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_increment)(HASH_TABLE_ITERATOR_NAME* iter);         \
static void                     _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_decrement)(HASH_TABLE_ITERATOR_NAME* iter);          \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_decrement)(HASH_TABLE_ITERATOR_NAME* iter);         \
static TYPE*                    _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, deref)(HASH_TABLE_ITERATOR_NAME* iter);                  \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_ITERATOR_NAME)                                                                  \
{                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME)();                                                               \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_ITERATOR_NAME)                                                                 \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_ITERATOR_NAME)(target);                                                               \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_ITERATOR_NAME)                                                                    \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_ITERATOR_NAME)(dest, source);                                                            \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_ITERATOR_NAME)                                                                    \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_ITERATOR_NAME)(dest, source);                                                            \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_ITERATOR_NAME)                                                                  \
{                                                                                                                                   \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_ITERATOR_NAME)(left, right);                                                    \
}                                                                                                                                   \
                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_increment)(HASH_TABLE_ITERATOR_NAME* iter)                               \
{                                                                                                                                   \
    _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_increment)(iter);                                                                      \
}                                                                                                                                   \
                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_increment)(HASH_TABLE_ITERATOR_NAME* iter)          \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_increment)(iter);                                                              \
}                                                                                                                                   \
                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, pre_decrement)(HASH_TABLE_ITERATOR_NAME* iter)                               \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_decrement)(iter);                                                               \
}                                                                                                                                   \
                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, post_decrement)(HASH_TABLE_ITERATOR_NAME* iter)          \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_decrement)(iter);                                                              \
}                                                                                                                                   \
                                                                                                                                    \
static TYPE* _C_PUBLIC_MEMBER(HASH_TABLE_ITERATOR_NAME, deref)(HASH_TABLE_ITERATOR_NAME* iter)                                      \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, deref)(iter);                                                                       \
}                                                                                                                                   \





#define _DEFINE_GENERIC_HASH_TABLE_IMPL(                                                                                            \
    HASH_TABLE_NAME,                                                                                                                \
    HASH_TABLE_LIST_NAME,                                                                                                           \
    HASH_TABLE_VECTOR_NAME,                                                                                                         \
    HASH_TABLE_ITERATOR_NAME,                                                                                                       \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
typedef struct                                                                                                                      \
{                                                                                                                                   \
    HASH_TABLE_LIST_NAME elems;                                                                                                     \
    HASH_TABLE_VECTOR_NAME buckets;                                                                                                 \
} HASH_TABLE_NAME;                                                                                                                  \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_NAME);                                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_NAME);                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_NAME);                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_NAME);                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_NAME);                                                                          \
                                                                                                                                    \
static void                         _C_PUBLIC_MEMBER(HASH_TABLE_NAME, clear)(HASH_TABLE_NAME* target);                              \
static size_t                       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(const HASH_TABLE_NAME* target);                         \
static size_t                       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(const HASH_TABLE_NAME* target);                 \
static size_t                       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_size)(const HASH_TABLE_NAME* target, size_t index);    \
static size_t                       _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket)(const HASH_TABLE_NAME* target, const KEY_TYPE* key);  \
static bool                         _C_PUBLIC_MEMBER(HASH_TABLE_NAME, empty)(const HASH_TABLE_NAME* target);                        \
static float                        _C_PUBLIC_MEMBER(HASH_TABLE_NAME, load_factor)(const HASH_TABLE_NAME* target);                  \
static HASH_TABLE_ITERATOR_NAME     _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin)(HASH_TABLE_NAME* target);                              \
static HASH_TABLE_ITERATOR_NAME     _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(HASH_TABLE_NAME* target);                                \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_NAME)                                                                           \
{                                                                                                                                   \
    return (HASH_TABLE_NAME){                                                                                                       \
        .elems = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_LIST_NAME)(),                                                       \
        .buckets = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_VECTOR_NAME)()                                                    \
    };                                                                                                                              \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_NAME)                                                                          \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_LIST_NAME)(&target->elems);                                                     \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_VECTOR_NAME)(&target->buckets);                                                 \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_NAME)                                                                             \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_LIST_NAME)(&dest->elems, &source->elems);                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_VECTOR_NAME)(&dest->buckets, &source->elems);                                      \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_NAME)                                                                             \
{                                                                                                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_LIST_NAME)(&dest->elems, &source->elems);                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_VECTOR_NAME)(&dest->buckets, &source->elems);                                      \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_NAME)                                                                           \
{                                                                                                                                   \
    return false;   /* TODO */                                                                                                      \
}                                                                                                                                   \
                                                                                                                                    \
static void _C_PUBLIC_MEMBER(HASH_TABLE_NAME, clear)(HASH_TABLE_NAME* target)                                                       \
{                                                                                                                                   \
    _C_PUBLIC_MEMBER(HASH_TABLE_LIST_NAME, clear)(&target->elems);                                                                  \
    size_t size = _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_NAME, size)(&target->buckets);                                                 \
    for (size_t i = 0; i < size; ++i)                                                                                               \
    {                                                                                                                               \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_NAME, element_at)(&target->buckets, i)->first = 0;                                       \
        _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_NAME, element_at)(&target->buckets, i)->second = NULL;                                   \
    }                                                                                                                               \
}                                                                                                                                   \
                                                                                                                                    \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(const HASH_TABLE_NAME* target)                                                \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_NAME, size)(&target->elems);                                                            \
}                                                                                                                                   \
                                                                                                                                    \
static size_t _C_PUBLIC_MEMBER(HASH_TABLE_NAME, bucket_count)(const HASH_TABLE_NAME* target)                                        \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(HASH_TABLE_VECTOR_NAME, size)(&target->buckets);                                                        \
}                                                                                                                                   \
                                                                                                                                    \
static bool _C_PUBLIC_MEMBER(HASH_TABLE_NAME, empty)(const HASH_TABLE_NAME* target)                                                 \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_NAME, empty)(&target->elems);                                                           \
}                                                                                                                                   \
                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin)(HASH_TABLE_NAME* target)                                   \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_NAME, begin)(&target->elems);                                                           \
}                                                                                                                                   \
                                                                                                                                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(HASH_TABLE_NAME* target)                                     \
{                                                                                                                                   \
    return _C_PUBLIC_MEMBER(HASH_TABLE_LIST_NAME, end)(&target->elems);                                                             \
}                                                                                                                                   \
                                                                                                                                    \





#define _DEFINE_GENERIC_HASH_TABLE(                                                                                                 \
    HASH_TABLE_NAME_PUBLIC_PREFIX,                                                                                                  \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_PAIR(                                                                                                                \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, KeyValuePair),                                                                  \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_LIST(                                                                                                                \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList),                                                                     \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, KeyValuePair)                                                                   \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(                                                                                                 \
    _C_PRIVATE_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList), DoubleNode)*, /* generated from IterList */       \
    _C_PRIVATE_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList), DoubleNode_ptr)                                   \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_PAIR(                                                                                                                \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, CountNodePair),                                                                \
    size_t,                                                                                                                         \
    _C_PRIVATE_MEMBER(_C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList), DoubleNode_ptr)  /* same as above */              \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_VECTOR(                                                                                                              \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, BucketVector),                                                                 \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, CountNodePair)                                                                 \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE_ITERATOR(                                                                                                \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, Iterator),                                                                      \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList_Iterator),    /* generated from IterList */                           \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, KeyValuePair)                                                                   \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE_IMPL(                                                                                                    \
    HASH_TABLE_NAME_PUBLIC_PREFIX,                                                                                                  \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, IterList),                                                                     \
    _C_PRIVATE_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, BucketVector),                                                                 \
    _C_PUBLIC_MEMBER(HASH_TABLE_NAME_PUBLIC_PREFIX, Iterator),                                                                      \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    VAL_TYPE                                                                                                                        \
)                                                                                                                                   \



#endif  // _C_HASH_TABLE_H