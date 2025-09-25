#ifndef C_UNORDERED_MAP_H
#define C_UNORDERED_MAP_H


#include "custom/_c_hash_table.h"


#define DEFINE_GENERIC_UNORDERED_MAP(                                                                                               \
    UMAP_NAME_PUBLIC_PREFIX,                                                                                                        \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
DEFINE_GENERIC_PAIR(                                                                                                                \
    _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair),                                                                        \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE(                                                                                                         \
    UMAP_NAME_PUBLIC_PREFIX,                                                                                                        \
    KEY_TYPE,                                                                                                                       \
    MAP_TYPE,                                                                                                                       \
    _C_PUBLIC_MEMBER(UMAP_NAME_PUBLIC_PREFIX, KeyValuePair)                                                                         \
)                                                                                                                                   \


#endif  // C_UNORDERED_MAP_H