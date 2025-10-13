#ifndef C_STRING_H
#define C_STRING_H


#if _HAS_C11
#   include <wchar.h>
#   include <uchar.h>
#endif  // _HAS_C11
#include "custom/_c_basic_string.h"


#define DEFINE_STRING() _DEFINE_BASIC_STRING(String, char)

#if _HAS_C11
#   define DEFINE_WSTRING()     _DEFINE_BASIC_STRING(WString, wchar_t)
#   define DEFINE_U16STRING()   _DEFINE_BASIC_STRING(U16String, char16_t)
#   define DEFINE_U32STRING()   _DEFINE_BASIC_STRING(U32String, char32_t)
#endif  // _HAS_C11


#endif  // C_STRING_H