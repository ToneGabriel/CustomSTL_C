#ifndef C_QUEUE_H
#define C_QUEUE_H


#include "custom/c_list.h"


// ======================================================================================================================================================
// Queue Implementation
// ======================================================================================================================================================

#define _DEFINE_GENERIC_QUEUE_IMPL(                                                                             \
    QUEUE_NAME,                                                                                                 \
    QUEUE_LIST_HELPER_NAME,                                                                                     \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
typedef struct                                                                                                  \
{                                                                                                               \
    QUEUE_LIST_HELPER_NAME list;                                                                                \
} QUEUE_NAME;                                                                                                   \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(QUEUE_NAME);                                                           \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(QUEUE_NAME);                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(QUEUE_NAME);                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(QUEUE_NAME);                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(QUEUE_NAME);                                                           \
                                                                                                                \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, clear)(QUEUE_NAME* target);                                    \
static size_t       _C_PUBLIC_MEMBER(QUEUE_NAME, size)(const QUEUE_NAME* target);                               \
static bool         _C_PUBLIC_MEMBER(QUEUE_NAME, empty)(const QUEUE_NAME* target);                              \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert)(QUEUE_NAME* target);                                   \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert_copy)(QUEUE_NAME* target, const TYPE* item);            \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert_move)(QUEUE_NAME* target, TYPE* item);                  \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, pop)(QUEUE_NAME* target);                                      \
static TYPE*        _C_PUBLIC_MEMBER(QUEUE_NAME, peek)(QUEUE_NAME* target);                                     \
static const TYPE*  _C_PUBLIC_MEMBER(QUEUE_NAME, peek_const)(const QUEUE_NAME* target);                         \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(QUEUE_NAME)                                                            \
{                                                                                                               \
    return (QUEUE_NAME){                                                                                        \
        .list = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(QUEUE_LIST_HELPER_NAME)()                                   \
    };                                                                                                          \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(QUEUE_NAME)                                                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(QUEUE_LIST_HELPER_NAME)(&target->list);                                \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(QUEUE_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Queue dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Queue source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(QUEUE_LIST_HELPER_NAME)(&dest->list, &source->list);                      \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(QUEUE_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Queue dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Queue source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(QUEUE_LIST_HELPER_NAME)(&dest->list, &source->list);                      \
}                                                                                                               \
                                                                                                                \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(QUEUE_NAME)                                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != left, "Queue left is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != right, "Queue right is NULL");                                                     \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(QUEUE_LIST_HELPER_NAME)(&left->list, &right->list);              \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, clear)(QUEUE_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, clear)(&target->list);                                             \
}                                                                                                               \
                                                                                                                \
static size_t _C_PUBLIC_MEMBER(QUEUE_NAME, size)(const QUEUE_NAME* target)                                      \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, size)(&target->list);                                       \
}                                                                                                               \
                                                                                                                \
static bool _C_PUBLIC_MEMBER(QUEUE_NAME, empty)(const QUEUE_NAME* target)                                       \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, empty)(&target->list);                                      \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert)(QUEUE_NAME* target)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back)(&target->list);                                         \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert_copy)(QUEUE_NAME* target, const TYPE* item)                     \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back_copy)(&target->list, item);                              \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert_move)(QUEUE_NAME* target, TYPE* item)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back_move)(&target->list, item);                              \
}                                                                                                               \
                                                                                                                \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, pop)(QUEUE_NAME* target)                                               \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, pop_front)(&target->list);                                         \
}                                                                                                               \
                                                                                                                \
static TYPE* _C_PUBLIC_MEMBER(QUEUE_NAME, peek)(QUEUE_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, element_front)(&target->list);                              \
}                                                                                                               \
                                                                                                                \
static const TYPE* _C_PUBLIC_MEMBER(QUEUE_NAME, peek_const)(const QUEUE_NAME* target)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, element_front_const)(&target->list);                        \
}                                                                                                               \


// ======================================================================================================================================================
// Queue COMPLETE Definition
// ======================================================================================================================================================

/**
 * @brief Fully defines a queue for a given type with all required dependencies.
 * @param QUEUE_NAME_PUBLIC_PREFIX      Public prefix (e.g. `MyQueue` → `MyQueue_create`)
 * @param TYPE                          The element type stored in the queue
 */
#define DEFINE_GENERIC_QUEUE(                                                                                   \
    QUEUE_NAME_PUBLIC_PREFIX,                                                                                   \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
DEFINE_GENERIC_LIST(                                                                                            \
    _C_PRIVATE_MEMBER(QUEUE_NAME_PUBLIC_PREFIX, List),                                                          \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
_DEFINE_GENERIC_QUEUE_IMPL(                                                                                     \
    QUEUE_NAME_PUBLIC_PREFIX,                                                                                   \
    _C_PRIVATE_MEMBER(QUEUE_NAME_PUBLIC_PREFIX, List), /*same as above*/                                        \
    TYPE                                                                                                        \
)                                                                                                               \


#endif // C_QUEUE_H