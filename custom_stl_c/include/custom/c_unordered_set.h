#ifndef C_UNORDERED_SET_H
#define C_UNORDERED_SET_H


#include "custom/_c_hash_table.h"


/**
 * @brief Public macro to define a generic unordered set and iterators for given key and mapped types with all required dependencies.
 * @param VECTOR_NAME_PUBLIC_PREFIX     The public name prefix for generated unordered set (e.g., `MyUSet` -> `MyUSet_create`, etc.).
 * @param KEY_TYPE                      Typedef for key stored in the unordered set. (also the mapped value type)
 */
#define DEFINE_GENERIC_UNORDERED_SET(                                                           \
    USET_NAME_PUBLIC_PREFIX,                                                                    \
    KEY_TYPE                                                                                    \
)                                                                                               \
                                                                                                \
_DEFINE_GENERIC_HASH_TABLE(                                                                     \
    USET_NAME_PUBLIC_PREFIX,                                                                    \
    KEY_TYPE,                                                                                   \
    KEY_TYPE,                                                                                   \
    KEY_TYPE                                                                                    \
)                                                                                               \
                                                                                                \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_KEY(USET_NAME_PUBLIC_PREFIX, KEY_TYPE, KEY_TYPE)     \
{                                                                                               \
    _C_CUSTOM_ASSERT(NULL != value, "Value is NULL");                                           \
    return value;                                                                               \
}                                                                                               \
                                                                                                \
_DECLARE_HASH_TABLE_PRIVATE_MEMBER_EXTRACT_MAP(USET_NAME_PUBLIC_PREFIX, KEY_TYPE, KEY_TYPE)     \
{                                                                                               \
    _C_CUSTOM_ASSERT(NULL != value, "Value is NULL");                                           \
    return value;                                                                               \
}                                                                                               \


#endif  // C_UNORDERED_SET_H