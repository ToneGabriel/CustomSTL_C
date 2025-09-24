#ifndef _C_HASH_TABLE_H
#define _C_HASH_TABLE_H


#include "custom/c_utility.h"


#define _DEFINE_GENERIC_HASH_TABLE_IMPL(                                                                                    \
    HASH_TABLE_NAME,                                                                                                        \
    HASH_TABLE_LIST_NAME,                                                                                                   \
    HASH_TABLE_VECTOR_NAME,                                                                                                 \
    HASH_TABLE_ITERATOR_NAME,                                                                                               \
    KEY_TYPE,                                                                                                               \
    MAP_TYPE                                                                                                                \
)                                                                                                                           \
                                                                                                                            \
typedef struct                                                                                                              \
{                                                                                                                           \
    HASH_TABLE_LIST_NAME elems;                                                                                             \
    HASH_TABLE_VECTOR_NAME buckets;                                                                                         \
} HASH_TABLE_NAME;                                                                                                          \
                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(HASH_TABLE_NAME);                                                                  \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(HASH_TABLE_NAME);                                                                 \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(HASH_TABLE_NAME);                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(HASH_TABLE_NAME);                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(HASH_TABLE_NAME);                                                                  \
                                                                                                                            \
static void                     _C_PUBLIC_MEMBER(HASH_TABLE_NAME, clear)(HASH_TABLE_NAME* target);                          \
static size_t                   _C_PUBLIC_MEMBER(HASH_TABLE_NAME, size)(const HASH_TABLE_NAME* target);                     \
static bool                     _C_PUBLIC_MEMBER(HASH_TABLE_NAME, empty)(const HASH_TABLE_NAME* target);                    \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, begin)(HASH_TABLE_NAME* target);                          \
static HASH_TABLE_ITERATOR_NAME _C_PUBLIC_MEMBER(HASH_TABLE_NAME, end)(HASH_TABLE_NAME* target);                            \





#endif  // _C_HASH_TABLE_H