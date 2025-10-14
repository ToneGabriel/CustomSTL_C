#ifndef _C_BASIC_STRING_H
#define _C_BASIC_STRING_H


#include "custom/c_utility.h"
#include "custom/_c_char_traits.h"


// ======================================================================================================================================================
// Basic String Implementation
// ======================================================================================================================================================

#define _DEFINE_BASIC_STRING_IMPL(                                      \
    BASIC_STRING_PUBLIC_PREFIX,                                         \
    CHAR_TYPE_TRAITS_NAME,                                              \
    CHAR_TYPE                                                           \
)
// TODO


// ======================================================================================================================================================
// Basic String COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Public macro to define a generic basic string and iterators for a given char type with all required dependencies.
 * @param BASIC_STRING_PUBLIC_PREFIX    The public name prefix for generated string (e.g., `String` -> `String_create`, etc.).
 * @param CHAR_TYPE                     Char type stored in the string.
 */
#define _DEFINE_BASIC_STRING(                                                           \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_GENERIC_CHAR_TRAITS(                                                            \
    _C_PRIVATE_MEMBER(BASIC_STRING_PUBLIC_PREFIX, CharTraits),                          \
    CHAR_TYPE                                                                           \
)                                                                                       \
                                                                                        \
_DEFINE_BASIC_STRING_IMPL(                                                              \
    BASIC_STRING_PUBLIC_PREFIX,                                                         \
    _C_PRIVATE_MEMBER(BASIC_STRING_PUBLIC_PREFIX, CharTraits),  /*same as above*/       \
    CHAR_TYPE                                                                           \
)                                                                                       \


#endif  // _C_BASIC_STRING_H