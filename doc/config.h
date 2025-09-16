#ifndef CONFIG_H
#define CONFIG_H


// For dynamic libraries
#ifdef _WIN32
#   ifdef CUSTOM_CMAKE_DLL_EXPORT_MODE
#       define DLL_ATTR __declspec(dllexport)
#   else
#       define DLL_ATTR __declspec(dllimport)
#   endif
#else   // no _WIN32
#   define DLL_ATTR
#endif  // _WIN32


// Need extern "C" when linking to this from C++ project
#ifdef __cplusplus
#   define EXTERN_C extern "C"
#else
#   define EXTERN_C
#endif  // __cplusplus

#endif  // CONFIG_H
