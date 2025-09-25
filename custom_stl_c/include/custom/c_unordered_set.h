#ifndef C_UNORDERED_SET_H
#define C_UNORDERED_SET_H


#include "custom/_c_hash_table.h"


#define DEFINE_GENERIC_UNORDERED_SET(                                                                                               \
    USET_NAME_PUBLIC_PREFIX,                                                                                                        \
    KEY_TYPE                                                                                                                        \
)                                                                                                                                   \
                                                                                                                                    \
_DEFINE_GENERIC_HASH_TABLE(                                                                                                         \
    USET_NAME_PUBLIC_PREFIX,                                                                                                        \
    KEY_TYPE,                                                                                                                       \
    KEY_TYPE,                                                                                                                       \
    KEY_TYPE                                                                                                                        \
)                                                                                                                                   \


#endif  // C_UNORDERED_SET_H