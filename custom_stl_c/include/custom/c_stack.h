#ifndef C_STACK_H
#define C_STACK_H


#include "custom/c_vector.h"


/**
 * @def _DEFINE_GENERIC_STACK_IMPL
 * @brief Internal macro that defines the complete implementation of a stack.
 *
 * The generated stack operates on elements of type `TYPE`.
 * 
 * @param STACK_NAME                Public-facing name prefix for struct and functions (e.g., `MyStack` -> `MyStack_create`, etc.)
 * @param STACK_VECTOR_HELPER_NAME  Name prefix for the vector implementation used internally (defined beforehand via another macro)
 * @param TYPE                      Type of elements to be stored in the stack.
 */
#define _DEFINE_GENERIC_STACK_IMPL(                                                                             \
    STACK_NAME,                                                                                                 \
    STACK_VECTOR_HELPER_NAME,                                                                                   \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @struct STACK_NAME                                                                                           \
 * @brief Struct representing the stack. Contains the internal vector.                                          \
 */                                                                                                             \
typedef struct                                                                                                  \
{                                                                                                               \
    STACK_VECTOR_HELPER_NAME vec;                                                                               \
} STACK_NAME;                                                                                                   \
                                                                                                                \
static STACK_NAME   _C_PUBLIC_MEMBER(STACK_NAME, create)();                                                     \
static void         _C_PUBLIC_MEMBER(STACK_NAME, destroy)(STACK_NAME* stack);                                   \
static void         _C_PUBLIC_MEMBER(STACK_NAME, clear)(STACK_NAME* stack);                                     \
static void         _C_PUBLIC_MEMBER(STACK_NAME, copy)(STACK_NAME* dest, const STACK_NAME* source);             \
static void         _C_PUBLIC_MEMBER(STACK_NAME, move)(STACK_NAME* dest, STACK_NAME* source);                   \
static size_t       _C_PUBLIC_MEMBER(STACK_NAME, size)(STACK_NAME* stack);                                      \
static bool         _C_PUBLIC_MEMBER(STACK_NAME, empty)(STACK_NAME* stack);                                     \
static void         _C_PUBLIC_MEMBER(STACK_NAME, insert)(STACK_NAME* stack, const TYPE* item);                  \
static void         _C_PUBLIC_MEMBER(STACK_NAME, pop)(STACK_NAME* stack);                                       \
static TYPE*        _C_PUBLIC_MEMBER(STACK_NAME, peek)(STACK_NAME* stack);                                      \
static bool         _C_PUBLIC_MEMBER(STACK_NAME, equals)(const STACK_NAME* left, const STACK_NAME* right);      \
                                                                                                                \
/**                                                                                                             \
 * @brief Creates a new stack. Initialize internal vector.                                                      \
 * @return A new instance of STACK_NAME.                                                                        \
 */                                                                                                             \
static STACK_NAME _C_PUBLIC_MEMBER(STACK_NAME, create)()                                                        \
{                                                                                                               \
    STACK_NAME stack = {                                                                                        \
        .vec = _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, create)()                                             \
    };                                                                                                          \
    return stack;                                                                                               \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Destroys the stack and its internal data.                                                             \
 * @param stack Pointer to the stack.                                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, destroy)(STACK_NAME* stack)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, destroy)(&stack->vec);                                           \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Clears all elements from the stack without destroying it.                                             \
 * @param stack Pointer to the stack.                                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, clear)(STACK_NAME* stack)                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, clear)(&stack->vec);                                             \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Copies contents of one stack to another.                                                              \
 * @param dest Destination stack pointer.                                                                       \
 * @param source Source stack pointer.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, copy)(STACK_NAME* dest, const STACK_NAME* source)                      \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, copy)(&dest->vec, &source->vec);                                 \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Move contents of one stack to another.                                                                \
 * @param dest Destination stack pointer.                                                                       \
 * @param source Source stack pointer.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, move)(STACK_NAME* dest, STACK_NAME* source)                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, move)(&dest->vec, &source->vec);                                 \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns the number of elements in the stack.                                                          \
 * @param stack Pointer to the stack.                                                                           \
 * @return The number of elements.                                                                              \
 */                                                                                                             \
static size_t _C_PUBLIC_MEMBER(STACK_NAME, size)(STACK_NAME* stack)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, size)(&stack->vec);                                       \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks if the stack is empty.                                                                         \
 * @param stack Pointer to the stack.                                                                           \
 * @return `true` if empty, `false` otherwise.                                                                  \
 */                                                                                                             \
static bool _C_PUBLIC_MEMBER(STACK_NAME, empty)(STACK_NAME* stack)                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, empty)(&stack->vec);                                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new element into the stack.                                                                 \
 * @param stack Pointer to the stack.                                                                           \
 * @param item Pointer to the element to insert.                                                                \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert)(STACK_NAME* stack, const TYPE* item)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back)(&stack->vec, item);                                   \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Removes the top element (last inserted) from the stack.                                               \
 * @param stack Pointer to the stack.                                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, pop)(STACK_NAME* stack)                                                \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, pop_back)(&stack->vec);                                          \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns a pointer to the top element (last inserted) of the stack.                                    \
 * @param stack Pointer to the stack.                                                                           \
 * @return Pointer to the top element.                                                                          \
 */                                                                                                             \
static TYPE* _C_PUBLIC_MEMBER(STACK_NAME, peek)(STACK_NAME* stack)                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != stack, "Stack is NULL");                                                           \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, element_back)(&stack->vec);                               \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks whether two stacks are equal by comparing each element.                                        \
 * @param left Left-hand side pointer to a stack.                                                               \
 * @param right Right-hand side pointer to a stack.                                                             \
 * @return `true` if equal, `false` otherwise.                                                                  \
 */                                                                                                             \
static bool _C_PUBLIC_MEMBER(STACK_NAME, equals)(const STACK_NAME* left, const STACK_NAME* right)               \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != left, "Stack left is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != right, "Stack right is NULL");                                                     \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, equals)(&left->vec, &right->vec);                         \
}                                                                                                               \


/**
 * @def DEFINE_GENERIC_STACK
 * @brief Fully defines a stack for a given type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - A `PRIVATE_Vector` container for internal storage
 * 
 * - The stack API (`_create`, `_initialize`, `_destroy`, `_clear`, `_copy`, `_move`, `_size`, `_empty`,
 *                  `_insert`, `_pop`, `_peek`, `_equals`
 *                  )
 *
 * @param STACK_NAME_PUBLIC_PREFIX      Public prefix (e.g. `MyStack` → `MyStack_create`)
 * @param TYPE                          The element type stored in the stack
 */
#define DEFINE_GENERIC_STACK(                                                                                       \
    STACK_NAME_PUBLIC_PREFIX,                                                                                       \
    TYPE                                                                                                            \
)                                                                                                                   \
                                                                                                                    \
DEFINE_GENERIC_VECTOR(                                                                                              \
    _C_PRIVATE_MEMBER(STACK_NAME_PUBLIC_PREFIX, Vector),                                                            \
    TYPE                                                                                                            \
)                                                                                                                   \
                                                                                                                    \
_DEFINE_GENERIC_STACK_IMPL(                                                                                         \
    STACK_NAME_PUBLIC_PREFIX,                                                                                       \
    _C_PRIVATE_MEMBER(STACK_NAME_PUBLIC_PREFIX, Vector), /*same as above*/                                          \
    TYPE                                                                                                            \
)                                                                                                                   \


#endif // C_STACK_H