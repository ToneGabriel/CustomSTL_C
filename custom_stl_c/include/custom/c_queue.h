#ifndef C_QUEUE_H
#define C_QUEUE_H


#include "custom/c_list.h"


/**
 * @def _DEFINE_GENERIC_QUEUE_IMPL
 * @brief Internal macro that defines the complete implementation of a FIFO queue.
 *
 * The generated queue operates on elements of type `TYPE`.
 * 
 * @param QUEUE_NAME                Public-facing name prefix for struct and functions (e.g., `MyStack` -> `MyStack_create`, etc.)
 * @param QUEUE_LIST_HELPER_NAME    Name prefix for the list implementation used internally (defined beforehand via another macro)
 * @param TYPE                      Type of elements to be stored in the queue.
 */
#define _DEFINE_GENERIC_QUEUE_IMPL(                                                                             \
    QUEUE_NAME,                                                                                                 \
    QUEUE_LIST_HELPER_NAME,                                                                                     \
    TYPE                                                                                                        \
)                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @struct QUEUE_NAME                                                                                           \
 * @brief Struct representing the queue. Contains the internal list.                                            \
 */                                                                                                             \
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
static size_t       _C_PUBLIC_MEMBER(QUEUE_NAME, size)(QUEUE_NAME* target);                                     \
static bool         _C_PUBLIC_MEMBER(QUEUE_NAME, empty)(QUEUE_NAME* target);                                    \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert)(QUEUE_NAME* target);                                   \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert_copy)(QUEUE_NAME* target, const TYPE* item);            \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, insert_move)(QUEUE_NAME* target, TYPE* item);                  \
static void         _C_PUBLIC_MEMBER(QUEUE_NAME, pop)(QUEUE_NAME* target);                                      \
static TYPE*        _C_PUBLIC_MEMBER(QUEUE_NAME, peek)(QUEUE_NAME* target);                                     \
                                                                                                                \
/**                                                                                                             \
 * @brief Creates a new queue. Initialize internal list.                                                        \
 * @return A new instance of QUEUE_NAME.                                                                        \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(QUEUE_NAME)                                                            \
{                                                                                                               \
    return (QUEUE_NAME){                                                                                        \
        .list = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(QUEUE_LIST_HELPER_NAME)()                                   \
    };                                                                                                          \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Destroys the queue and its internal data.                                                             \
 * @param target Pointer to the queue.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(QUEUE_NAME)                                                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(QUEUE_LIST_HELPER_NAME)(&target->list);                                \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Copies contents of one queue to another.                                                              \
 * @param dest Destination queue pointer.                                                                       \
 * @param source Source queue pointer.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(QUEUE_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Queue dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Queue source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(QUEUE_LIST_HELPER_NAME)(&dest->list, &source->list);                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Move contents of one queue to another.                                                                \
 * @param dest Destination queue pointer.                                                                       \
 * @param source Source queue pointer.                                                                          \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(QUEUE_NAME)                                                              \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != dest, "Queue dest is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != source, "Queue source is NULL");                                                   \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(QUEUE_LIST_HELPER_NAME)(&dest->list, &source->list);                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks whether two queues are equal by comparing each element.                                        \
 * @param left Left-hand side pointer to a queue.                                                               \
 * @param right Right-hand side pointer to a queue.                                                             \
 * @return `true` if equal, `false` otherwise.                                                                  \
 */                                                                                                             \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(QUEUE_NAME)                                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != left, "Queue left is NULL");                                                       \
    _C_CUSTOM_ASSERT(NULL != right, "Queue right is NULL");                                                     \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(QUEUE_LIST_HELPER_NAME)(&left->list, &right->list);              \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Clears all elements from the queue without destroying it.                                             \
 * @param target Pointer to the queue.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, clear)(QUEUE_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, clear)(&target->list);                                             \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns the number of elements in the queue.                                                          \
 * @param target Pointer to the queue.                                                                          \
 * @return The number of elements.                                                                              \
 */                                                                                                             \
static size_t _C_PUBLIC_MEMBER(QUEUE_NAME, size)(QUEUE_NAME* target)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, size)(&target->list);                                       \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Checks if the queue is empty.                                                                         \
 * @param target Pointer to the queue.                                                                          \
 * @return `true` if empty, `false` otherwise.                                                                  \
 */                                                                                                             \
static bool _C_PUBLIC_MEMBER(QUEUE_NAME, empty)(QUEUE_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, empty)(&target->list);                                      \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new default element into the queue.                                                         \
 * @param target Pointer to the queue.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert)(QUEUE_NAME* target)                                            \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back)(&target->list);                                         \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new element into the queue.                                                                 \
 * @param target Pointer to the queue.                                                                          \
 * @param item Pointer to the element to copy insert.                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert_copy)(QUEUE_NAME* target, const TYPE* item)                     \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back_copy)(&target->list, item);                              \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Inserts a new element into the queue.                                                                 \
 * @param target Pointer to the queue.                                                                          \
 * @param item Pointer to the element to move insert.                                                           \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, insert_move)(QUEUE_NAME* target, TYPE* item)                           \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, push_back_move)(&target->list, item);                              \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Removes the first element from the queue.                                                             \
 * @param target Pointer to the queue.                                                                          \
 */                                                                                                             \
static void _C_PUBLIC_MEMBER(QUEUE_NAME, pop)(QUEUE_NAME* target)                                               \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, pop_front)(&target->list);                                         \
}                                                                                                               \
                                                                                                                \
/**                                                                                                             \
 * @brief Returns a pointer to the first element of the queue.                                                  \
 * @param target Pointer to the queue.                                                                          \
 * @return Pointer to the top element.                                                                          \
 */                                                                                                             \
static TYPE* _C_PUBLIC_MEMBER(QUEUE_NAME, peek)(QUEUE_NAME* target)                                             \
{                                                                                                               \
    _C_CUSTOM_ASSERT(NULL != target, "Queue is NULL");                                                          \
    return _C_PUBLIC_MEMBER(QUEUE_LIST_HELPER_NAME, element_front)(&target->list);                              \
}                                                                                                               \


/**
 * @def DEFINE_GENERIC_QUEUE
 * @brief Fully defines a queue for a given type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - A `PRIVATE_List` container for internal storage
 * 
 * - The queue API (`_create`, `_destroy`, `_clear`, `_copy`, `_move`, `_size`, `_empty`,
 *                  `_insert`, `_insert_copy`, `_insert_move`, `_pop`, `_peek`, `_equals`
 *                  )
 *
 * @param STACK_NAME_PUBLIC_PREFIX      Public prefix (e.g. `MyQueue` → `MyQueue_create`)
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