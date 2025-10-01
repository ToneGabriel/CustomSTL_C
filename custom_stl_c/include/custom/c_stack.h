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
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(STACK_NAME);                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(STACK_NAME);                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(STACK_NAME);                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(STACK_NAME);                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(STACK_NAME);                                                           \
                                                                                                                \
static void         _C_PUBLIC_MEMBER(STACK_NAME, clear)(STACK_NAME* target);                                    \
static size_t       _C_PUBLIC_MEMBER(STACK_NAME, size)(const STACK_NAME* target);                               \
static bool         _C_PUBLIC_MEMBER(STACK_NAME, empty)(const STACK_NAME* target);                              \
static void         _C_PUBLIC_MEMBER(STACK_NAME, insert)(STACK_NAME* target);                                   \
static void         _C_PUBLIC_MEMBER(STACK_NAME, insert_copy)(STACK_NAME* target, const TYPE* item);            \
static void         _C_PUBLIC_MEMBER(STACK_NAME, insert_move)(STACK_NAME* target, TYPE* item);                  \
static void         _C_PUBLIC_MEMBER(STACK_NAME, pop)(STACK_NAME* target);                                      \
static TYPE*        _C_PUBLIC_MEMBER(STACK_NAME, peek)(STACK_NAME* target);                                     \
                                                                                                                \
/**                                                                                                             \
 * @brief Creates a new stack. Initialize internal vector.                                                      \
 * @return A new instance of STACK_NAME.                                                                        \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(STACK_NAME)                                                            \
{                                                                                                               \
    return (STACK_NAME){                                                                                        \
        .vec = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(STACK_VECTOR_HELPER_NAME)()                                  \
    };                                                                                                          \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Destroys the stack and its internal data.                                                             \
 * @param target Pointer to the stack.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(STACK_NAME)                                                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(STACK_VECTOR_HELPER_NAME)(&target->vec);                               \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Copies contents of one stack to another.                                                              \
 * @param dest Destination stack pointer.                                                                       \
 * @param source Source stack pointer.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(STACK_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(STACK_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Move contents of one stack to another.                                                                \
 * @param dest Destination stack pointer.                                                                       \
 * @param source Source stack pointer.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(STACK_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(STACK_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks whether two stacks are equal by comparing each element.                                        \
 * @param left Left-hand side pointer to a stack.                                                               \
 * @param right Right-hand side pointer to a stack.                                                             \
 * @return `true` if equal, `false` otherwise.                                                                  \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(STACK_NAME)                                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != left, "Stack left is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != right, "Stack right is NULL");                                                     \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(STACK_VECTOR_HELPER_NAME)(&left->vec, &right->vec);              \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Clears all elements from the stack without destroying it.                                             \
 * @param target Pointer to the stack.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, clear)(STACK_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, clear)(&target->vec);                                            \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns the number of elements in the stack.                                                          \
 * @param target Pointer to the stack.                                                                          \
 * @return The number of elements.                                                                              \
 */                                                                                                             \
static size_t _C_PUBLIC_MEMBER(STACK_NAME, size)(const STACK_NAME* target)                                      \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, size)(&target->vec);                                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks if the stack is empty.                                                                         \
 * @param target Pointer to the stack.                                                                          \
 * @return `true` if empty, `false` otherwise.                                                                  \
 */                                                                                                             \
static bool _C_PUBLIC_MEMBER(STACK_NAME, empty)(const STACK_NAME* target)                                       \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, empty)(&target->vec);                                     \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new default element into the stack.                                                         \
 * @param target Pointer to the stack.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert)(STACK_NAME* target)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back)(&target->vec);                                        \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new element into the stack.                                                                 \
 * @param target Pointer to the stack.                                                                          \
 * @param item Pointer to the element to copy insert.                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert_copy)(STACK_NAME* target, const TYPE* item)                     \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back_copy)(&target->vec, item);                             \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new element into the stack.                                                                 \
 * @param target Pointer to the stack.                                                                          \
 * @param item Pointer to the element to move insert.                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert_move)(STACK_NAME* target, TYPE* item)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back_move)(&target->vec, item);                             \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Removes the top element (last inserted) from the stack.                                               \
 * @param target Pointer to the stack.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(STACK_NAME, pop)(STACK_NAME* target)                                               \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, pop_back)(&target->vec);                                         \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns a pointer to the top element (last inserted) of the stack.                                    \
 * @param target Pointer to the stack.                                                                          \
 * @return Pointer to the top element.                                                                          \
 */                                                                                                             \
static TYPE* _C_PUBLIC_MEMBER(STACK_NAME, peek)(STACK_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, element_back)(&target->vec);                              \
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
 *                  `_insert`, `_insert_copy`, `_insert_move`, `_pop`, `_peek`, `_equals`
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