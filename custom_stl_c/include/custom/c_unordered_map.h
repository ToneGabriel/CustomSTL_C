#ifndef C_UNORDERED_MAP_H
#define C_UNORDERED_MAP_H


#include "custom/_c_hash_table.h"


#define DEFINE_GENERIC_UNORDERED_MAP(                                                                                                                                   \
    UMAP_NAME_PUBLIC_PREFIX,                                                                                                                                            \
    KEY_TYPE,                                                                                                                                                           \
    MAP_TYPE                                                                                                                                                            \
)                                                                                                                                                                       \
                                                                                                                                                                        \
DEFINE_GENERIC_PAIR(                                                                                                                                                    \
    _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair),                                                                                                            \
    KEY_TYPE,                                                                                                                                                           \
    MAP_TYPE                                                                                                                                                            \
)                                                                                                                                                                       \
                                                                                                                                                                        \
_DEFINE_GENERIC_HASH_TABLE(                                                                                                                                             \
    UMAP_NAME_PUBLIC_PREFIX,                                                                                                                                            \
    KEY_TYPE,                                                                                                                                                           \
    MAP_TYPE,                                                                                                                                                           \
    _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair) /* same as above */                                                                                         \
)                                                                                                                                                                       \
                                                                                                                                                                        \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(UMAP_NAME_PUBLIC_PREFIX, KEY_TYPE, _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair)   /* same as above */)        \
{                                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != value, "Value is NULL");                                                                                                                   \
    return &value->first;                                                                                                                                               \
}                                                                                                                                                                       \
                                                                                                                                                                        \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(UMAP_NAME_PUBLIC_PREFIX, MAP_TYPE, _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair)   /* same as above */)        \
{                                                                                                                                                                       \
    _C_CUSTOM_ASSERT(NULL != value, "Value is NULL");                                                                                                                   \
    return &value->second;                                                                                                                                              \
}                                                                                                                                                                       \


#endif  // C_UNORDERED_MAP_H