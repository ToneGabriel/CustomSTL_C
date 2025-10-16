#ifndef C_UNORDERED_MAP_H
#define C_UNORDERED_MAP_H


#include "custom/_c_hash_table.h"


/**
 * @brief Define a generic unordered map and iterators for given key and mapped types with all required dependencies.
 * @param UNORDERED_MAP_NAME_PUBLIC_PREFIX  The public name prefix for generated unordered map (e.g., `MyUMap` -> `MyUMap_create`, etc.).
 * @param KEY_TYPE                          Typedef for key stored in the unordered map.
 * @param MAP_TYPE                          Typedef for mapped value stored in the unordered map.
 */
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