#ifndef C_STACK_H
#define C_STACK_H


#include "custom/c_vector.h"


// ======================================================================================================================================================
// Stack Implementation
// ======================================================================================================================================================

#define _DEFINE_GENERIC_STACK_IMPL(                                                                             \
    STACK_NAME,                                                                                                 \
    STACK_VECTOR_HELPER_NAME,                                                                                   \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
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
static const TYPE*  _C_PUBLIC_MEMBER(STACK_NAME, peek_const)(const STACK_NAME* target);                         \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(STACK_NAME)                                                            \
{                                                                                                               \
    return (STACK_NAME){                                                                                        \
        .vec = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(STACK_VECTOR_HELPER_NAME)()                                  \
    };                                                                                                          \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(STACK_NAME)                                                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(STACK_VECTOR_HELPER_NAME)(&target->vec);                               \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(STACK_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(STACK_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                      \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(STACK_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Stack dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Stack source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(STACK_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                      \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(STACK_NAME)                                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != left, "Stack left is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != right, "Stack right is NULL");                                                     \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(STACK_VECTOR_HELPER_NAME)(&left->vec, &right->vec);              \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(STACK_NAME, clear)(STACK_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, clear)(&target->vec);                                            \
}                                                                                                               \
                                                                                                                \
static size_t _C_PUBLIC_MEMBER(STACK_NAME, size)(const STACK_NAME* target)                                      \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, size)(&target->vec);                                      \
}                                                                                                               \
                                                                                                                \
static bool _C_PUBLIC_MEMBER(STACK_NAME, empty)(const STACK_NAME* target)                                       \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, empty)(&target->vec);                                     \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert)(STACK_NAME* target)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back)(&target->vec);                                        \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert_copy)(STACK_NAME* target, const TYPE* item)                     \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back_copy)(&target->vec, item);                             \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(STACK_NAME, insert_move)(STACK_NAME* target, TYPE* item)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, push_back_move)(&target->vec, item);                             \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(STACK_NAME, pop)(STACK_NAME* target)                                               \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, pop_back)(&target->vec);                                         \
}                                                                                                               \
                                                                                                                \
static TYPE* _C_PUBLIC_MEMBER(STACK_NAME, peek)(STACK_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, element_back)(&target->vec);                              \
}                                                                                                               \
                                                                                                                \
static const TYPE* _C_PUBLIC_MEMBER(STACK_NAME, peek_const)(const STACK_NAME* target)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Stack is NULL");                                                          \
    return _C_PUBLIC_MEMBER(STACK_VECTOR_HELPER_NAME, element_back_const)(&target->vec);                        \
}                                                                                                               \


// ======================================================================================================================================================
// Stack COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Fully defines a stack for a given type with all required dependencies.
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