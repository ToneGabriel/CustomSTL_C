#ifndef C_STRING_H
#define C_STRING_H


#include "custom/_c_basic_string.h"
#if _HAS_C11
#   include <wchar.h>
#   include <uchar.h>
#endif  // _HAS_C11


// ======================================================================================================================================================
// String Definition Helpers
// ======================================================================================================================================================

#define DEFINE_STRING()         _DEFINE_BASIC_STRING(String, StringView, CharTraits, char)
#if _HAS_C11
#   define DEFINE_WSTRING()     _DEFINE_BASIC_STRING(WString, WStringView, WCharTraits, wchar_t)
#   define DEFINE_U16STRING()   _DEFINE_BASIC_STRING(U16String, U16StringView, U16CharTraits, char16_t)
#   define DEFINE_U32STRING()   _DEFINE_BASIC_STRING(U32String, U32StringView, U32CharTraits, char32_t)
#endif  // _HAS_C11


#endif  // C_STRING_H