#ifndef C_UTILITY_H
#define C_UTILITY_H


#include "custom/_c_stlcore.h"


#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)      static TYPE _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)()
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)     static void _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(TYPE* target)
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)        static void _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(TYPE* dest, const TYPE* source)
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)        static void _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(TYPE* dest, TYPE* source)
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE)      static bool _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE)(const TYPE* left, const TYPE* right)
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_LESS(TYPE)        static bool _C_CUSTOM_TYPE_PUBLIC_MEMBER_LESS(TYPE)(const TYPE* left, const TYPE* right)
#define DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_GREATER(TYPE)     static bool _C_CUSTOM_TYPE_PUBLIC_MEMBER_GREATER(TYPE)(const TYPE* left, const TYPE* right)


#define DEFINE_DEFAULT_TYPE_PUBLIC_MEMBERS(TYPE, ALIAS)                                                             \
typedef TYPE ALIAS;                                                                                                 \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(ALIAS)                                                                     \
{                                                                                                                   \
    return (ALIAS){0};                                                                                              \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(ALIAS)                                                                    \
{                                                                                                                   \
    /*Empty*/                                                                                                       \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(ALIAS)                                                                       \
{                                                                                                                   \
    *dest = *source;                                                                                                \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(ALIAS)                                                                       \
{                                                                                                                   \
    *dest = *source;                                                                                                \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(ALIAS)                                                                     \
{                                                                                                                   \
    return *left == *right;                                                                                         \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_LESS(ALIAS)                                                                       \
{                                                                                                                   \
    return *left < *right;                                                                                          \
}                                                                                                                   \
                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_GREATER(ALIAS)                                                                    \
{                                                                                                                   \
    return *left > *right;                                                                                          \
}                                                                                                                   \


// =====================================================================================================================


/**
 * @def DEFINE_GENERIC_SWAP_FUNCTION
 * @brief Defines a generic swap function for a given type.
 *
 * This macro instantiates:
 * 
 * - The swap API (`_do_swap`)
 * 
 * @param SWAP_FUNC_NAME_PREFIX Prefix for the generated swap function name.
 * @param TYPE The data type of elements to be swapped.
 */
#define DEFINE_GENERIC_SWAP_FUNCTION(                                                   \
    SWAP_FUNC_NAME_PREFIX,                                                              \
    TYPE                                                                                \
)                                                                                       \
                                                                                        \
static void _C_PUBLIC_MEMBER(SWAP_FUNC_NAME_PREFIX, do_swap)(TYPE* left, TYPE* right)   \
{                                                                                       \
    TYPE temp;                                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(&temp, left);                               \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(left, right);                               \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(right, &temp);                              \
}                                                                                       \


// =====================================================================================================================


/**
 * @def _DEFINE_GENERIC_HEAPIFY_FUNCTIONS_IMPL
 * @brief Internal macro to define heapify up and down operations for generic types.
 *
 * @param HEAP_ADJUST_NAME Name prefix for heapify functions.
 * @param HEAP_ADJUST_SWAP_HELPER_NAME Swap helper prefix used inside heapify.
 * @param TYPE The data type stored in the heap.
 * @param TYPE_REF_COMPARE_FUNC A comparison function taking two pointers to TYPE.
 */
#define _DEFINE_GENERIC_HEAPIFY_FUNCTIONS_IMPL(                                                                 \
    HEAP_ADJUST_NAME,                                                                                           \
    HEAP_ADJUST_SWAP_HELPER_NAME,                                                                               \
    TYPE,                                                                                                       \
    TYPE_REF_COMPARE_FUNC                                                                                       \
)                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(HEAP_ADJUST_NAME, heapify_up)(TYPE* arr, size_t arr_size, size_t idx);             \
static void _C_PUBLIC_MEMBER(HEAP_ADJUST_NAME, heapify_down)(TYPE* arr, size_t arr_size, size_t idx);           \
                                                                                                                \
/**                                                                                                             \
 * @brief Adjusts the heap upwards to restore the heap property.                                                \
 * @param arr Pointer to the heap array.                                                                        \
 * @param arr_size Total number of elements in the array.                                                       \
 * @param idx Index of the newly inserted element to heapify.                                                   \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(HEAP_ADJUST_NAME, heapify_up)(TYPE* arr, size_t arr_size, size_t idx)              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != arr, "Heap array is NULL");                                                        \
    _C_CUSTOM_ASSERT(idx < arr_size, "Heap index is greater than array size");                                  \
    while (idx > 0 && TYPE_REF_COMPARE_FUNC(&arr[idx], &arr[(idx - 1) / 2]))                                    \
    {                                                                                                           \
        _C_PUBLIC_MEMBER(HEAP_ADJUST_SWAP_HELPER_NAME, do_swap)(&arr[idx], &arr[(idx - 1) / 2]);                \
        idx = (idx - 1) / 2;                                                                                    \
    }                                                                                                           \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Adjusts the heap downwards to restore the heap property.                                              \
 * @param arr Pointer to the heap array.                                                                        \
 * @param arr_size Total number of elements in the array.                                                       \
 * @param idx Index of the newly inserted element to heapify.                                                   \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(HEAP_ADJUST_NAME, heapify_down)(TYPE* arr, size_t arr_size, size_t idx)            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != arr, "Heap array is NULL");                                                        \
    _C_CUSTOM_ASSERT(idx < arr_size, "Heap index is greater than array size");                                  \
    size_t smallest, left, right;                                                                               \
    while (idx < arr_size)                                                                                      \
    {                                                                                                           \
        smallest = idx;                                                                                         \
        left = 2 * idx + 1;                                                                                     \
        right = 2 * idx + 2;                                                                                    \
        if (left < arr_size && TYPE_REF_COMPARE_FUNC(&arr[left], &arr[smallest]))                               \
            smallest = left;                                                                                    \
        if (right < arr_size && TYPE_REF_COMPARE_FUNC(&arr[right], &arr[smallest]))                             \
            smallest = right;                                                                                   \
        if (smallest == idx) return;                                                                            \
        _C_PUBLIC_MEMBER(HEAP_ADJUST_SWAP_HELPER_NAME, do_swap)(&arr[idx], &arr[smallest]);                     \
        idx = smallest;                                                                                         \
    }                                                                                                           \
}                                                                                                               \


/**
 * @def DEFINE_GENERIC_HEAPIFY_FUNCTIONS
 * @brief Public macro to define heapify operations for a type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - A `PRIVATE_Swap` helper for heap operations
 * 
 * - The heapify API (`_heapify_up`, `_heapify_down`)
 * 
 * @param HEAP_ADJUST_NAME_PUBLIC_PREFIX Public name prefix for heapify functions.
 * @param TYPE The data type in the heap.
 * @param TYPE_REF_COMPARE_FUNC A comparison function used for heap ordering.
 */
#define DEFINE_GENERIC_HEAPIFY_FUNCTIONS(                                                                               \
    HEAP_ADJUST_NAME_PUBLIC_PREFIX,                                                                                     \
    TYPE,                                                                                                               \
    TYPE_REF_COMPARE_FUNC                                                                                               \
)                                                                                                                       \
                                                                                                                        \
DEFINE_GENERIC_SWAP_FUNCTION(                                                                                           \
    _C_PRIVATE_MEMBER(HEAP_ADJUST_NAME_PUBLIC_PREFIX, Swap),                                                            \
    TYPE                                                                                                                \
)                                                                                                                       \
                                                                                                                        \
_DEFINE_GENERIC_HEAPIFY_FUNCTIONS_IMPL(                                                                                 \
    HEAP_ADJUST_NAME_PUBLIC_PREFIX,                                                                                     \
    _C_PRIVATE_MEMBER(HEAP_ADJUST_NAME_PUBLIC_PREFIX, Swap), /*same as above*/                                          \
    TYPE,                                                                                                               \
    TYPE_REF_COMPARE_FUNC                                                                                               \
)                                                                                                                       \


#endif  // C_UTILITY_H