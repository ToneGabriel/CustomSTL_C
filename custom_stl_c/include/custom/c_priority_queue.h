#ifndef C_PRIORITY_QUEUE_H
#define C_PRIORITY_QUEUE_H


#include "custom/c_vector.h"


/**
 * @def _DEFINE_GENERIC_PRIORITY_QUEUE_IMPL
 * @brief Internal macro that defines the complete implementation of a priority queue.
 *
 * This macro generates a full implementation of a min/max heap-based priority queue using a vector as the backing store.
 * The generated queue operates on elements of type `TYPE`, and uses helper macros for heap and vector operations.
 *
 * @param PQ_NAME                   Public-facing name prefix for struct and functions (e.g., `MyPQ` -> `MyPQ_create`, etc.)
 * @param PQ_HEAPIFY_HELPER_NAME    Name prefix of the helper heapify functions (defined beforehand via another macro)
 * @param PQ_VECTOR_HELPER_NAME     Name prefix for the vector implementation used internally (defined beforehand via another macro)
 * @param TYPE                      Type of elements to be stored in the priority queue
 */
#define _DEFINE_GENERIC_PRIORITY_QUEUE_IMPL(                                                                                                \
    PQ_NAME,                                                                                                                                \
    PQ_HEAPIFY_HELPER_NAME,                                                                                                                 \
    PQ_VECTOR_HELPER_NAME,                                                                                                                  \
    TYPE                                                                                                                                    \
)                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @struct PQ_NAME                                                                                                                          \
 * @brief Struct representing the priority queue. Contains the internal vector.                                                             \
 */                                                                                                                                         \
typedef struct                                                                                                                              \
{                                                                                                                                           \
    PQ_VECTOR_HELPER_NAME vec;                                                                                                              \
} PQ_NAME;                                                                                                                                  \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PQ_NAME);                                                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PQ_NAME);                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PQ_NAME);                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PQ_NAME);                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PQ_NAME);                                                                                          \
                                                                                                                                            \
static void     _C_PUBLIC_MEMBER(PQ_NAME, clear)(PQ_NAME* target);                                                                          \
static size_t   _C_PUBLIC_MEMBER(PQ_NAME, size)(const PQ_NAME* target);                                                                     \
static bool     _C_PUBLIC_MEMBER(PQ_NAME, empty)(const PQ_NAME* target);                                                                    \
static void     _C_PUBLIC_MEMBER(PQ_NAME, insert)(PQ_NAME* target);                                                                         \
static void     _C_PUBLIC_MEMBER(PQ_NAME, insert_copy)(PQ_NAME* target, const TYPE* item);                                                  \
static void     _C_PUBLIC_MEMBER(PQ_NAME, insert_move)(PQ_NAME* target, TYPE* item);                                                        \
static void     _C_PUBLIC_MEMBER(PQ_NAME, pop)(PQ_NAME* target);                                                                            \
static TYPE*    _C_PUBLIC_MEMBER(PQ_NAME, peek)(PQ_NAME* target);                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Creates new priority queue. Initialize internal vector.                                                                           \
 * @return A new instance of PQ_NAME.                                                                                                       \
 */                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PQ_NAME)                                                                                           \
{                                                                                                                                           \
    return (PQ_NAME){                                                                                                                       \
        .vec = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PQ_VECTOR_HELPER_NAME)()                                                                 \
    };                                                                                                                                      \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Destroys the priority queue and its internal data.                                                                                \
 * @param target Pointer to the priority queue.                                                                                             \
 */                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PQ_NAME)                                                                                          \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PQ_VECTOR_HELPER_NAME)(&target->vec);                                                              \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Copies contents of one pq to another.                                                                                             \
 * @param dest Destination pq pointer.                                                                                                      \
 * @param source Source pq pointer.                                                                                                         \
 */                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PQ_NAME)                                                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "PQ dest is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != source, "PQ source is NULL");                                                                                  \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PQ_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                                                     \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Move contents of one pq to another.                                                                                               \
 * @param dest Destination pq pointer.                                                                                                      \
 * @param source Source pq pointer.                                                                                                         \
 */                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PQ_NAME)                                                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "PQ dest is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != source, "PQ source is NULL");                                                                                  \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PQ_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                                                     \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Checks whether two pq are equal by comparing each element.                                                                        \
 * @param left Left-hand side pointer to a pq.                                                                                              \
 * @param right Right-hand side pointer to a pq.                                                                                            \
 * @return `true` if equal, `false` otherwise.                                                                                              \
 */                                                                                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PQ_NAME)                                                                                           \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != left, "PQ left is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != right, "PQ right is NULL");                                                                                    \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PQ_VECTOR_HELPER_NAME)(&left->vec, &right->vec);                                             \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Clears all elements from the priority queue without destroying it.                                                                \
 * @param target Pointer to the priority queue.                                                                                             \
 */                                                                                                                                         \
static void _C_PUBLIC_MEMBER(PQ_NAME, clear)(PQ_NAME* target)                                                                               \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, clear)(&target->vec);                                                                           \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Returns the number of elements in the priority queue.                                                                             \
 * @param target Pointer to the priority queue.                                                                                             \
 * @return The number of elements.                                                                                                          \
 */                                                                                                                                         \
static size_t _C_PUBLIC_MEMBER(PQ_NAME, size)(const PQ_NAME* target)                                                                        \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec);                                                                     \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Checks if the priority queue is empty.                                                                                            \
 * @param target Pointer to the priority queue.                                                                                             \
 * @return `true` if empty, `false` otherwise.                                                                                              \
 */                                                                                                                                         \
static bool _C_PUBLIC_MEMBER(PQ_NAME, empty)(const PQ_NAME* target)                                                                         \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, empty)(&target->vec);                                                                    \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Inserts a new default element into the priority queue.                                                                            \
 * Performs a heapify-up after insertion to maintain heap order.                                                                            \
 * @param target Pointer to the priority queue.                                                                                             \
 */                                                                                                                                         \
static void _C_PUBLIC_MEMBER(PQ_NAME, insert)(PQ_NAME* target)                                                                              \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, push_back)(&target->vec);                                                                       \
    _C_PUBLIC_MEMBER(PQ_HEAPIFY_HELPER_NAME, heapify_up)(                                                                                   \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, data)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec) - 1);                                                                   \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Inserts a new element into the priority queue.                                                                                    \
 * Performs a heapify-up after insertion to maintain heap order.                                                                            \
 * @param target Pointer to the priority queue.                                                                                             \
 * @param item Pointer to the element to copy insert.                                                                                       \
 */                                                                                                                                         \
static void _C_PUBLIC_MEMBER(PQ_NAME, insert_copy)(PQ_NAME* target, const TYPE* item)                                                       \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, push_back_copy)(&target->vec, item);                                                            \
    _C_PUBLIC_MEMBER(PQ_HEAPIFY_HELPER_NAME, heapify_up)(                                                                                   \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, data)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec) - 1);                                                                   \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Inserts a new element into the priority queue.                                                                                    \
 * Performs a heapify-up after insertion to maintain heap order.                                                                            \
 * @param target Pointer to the priority queue.                                                                                             \
 * @param item Pointer to the element to move insert.                                                                                       \
 */                                                                                                                                         \
static void _C_PUBLIC_MEMBER(PQ_NAME, insert_move)(PQ_NAME* target, TYPE* item)                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, push_back_move)(&target->vec, item);                                                            \
    _C_PUBLIC_MEMBER(PQ_HEAPIFY_HELPER_NAME, heapify_up)(                                                                                   \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, data)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec) - 1);                                                                   \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Removes the top element (highest priority) from the priority queue.                                                               \
 * Performs a heapify-down after removal to maintain heap order.                                                                            \
 * @param target Pointer to the priority queue.                                                                                             \
 */                                                                                                                                         \
static void _C_PUBLIC_MEMBER(PQ_NAME, pop)(PQ_NAME* target)                                                                                 \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    if (_C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, empty)(&target->vec)) return;                                                               \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(                                                                                                \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, element_at)(&target->vec, 0),                                                               \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, element_at)(&target->vec, _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec) - 1)  \
    );                                                                                                                                      \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, pop_back)(&target->vec);                                                                        \
    _C_PUBLIC_MEMBER(PQ_HEAPIFY_HELPER_NAME, heapify_down)(                                                                                 \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, data)(&target->vec),                                                                        \
        _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec),                                                                        \
        0                                                                                                                                   \
    );                                                                                                                                      \
}                                                                                                                                           \
                                                                                                                                            \
/**                                                                                                                                         \
 * @brief Returns a pointer to the top element (highest priority) of the queue.                                                             \
 * @param target Pointer to the priority queue.                                                                                             \
 * @return Pointer to the top element.                                                                                                      \
 */                                                                                                                                         \
static TYPE* _C_PUBLIC_MEMBER(PQ_NAME, peek)(PQ_NAME* target)                                                                               \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, element_front)(&target->vec);                                                            \
}                                                                                                                                           \


/**
 * @def DEFINE_GENERIC_PRIORITY_QUEUE
 * @brief Fully defines a priority queue for a given type with all required dependencies.
 *
 * This macro instantiates:
 * 
 * - A `PRIVATE_Heap` helper for maintaining priority ordering
 * 
 * - A `PRIVATE_Vector` container for internal storage
 * 
 * - The priority queue API (   `_create`, `_destroy`, `_clear`, `_copy`, `_move`, `_size`, `_empty`,
 *                              `_insert`, `_insert_copy`, `_insert_move`, `_pop`, `_peek`, `_equals`
 *                          )
 *
 * @param PRIORITY_QUEUE_NAME_PUBLIC_PREFIX   Public prefix (e.g. `MyPQ` → `MyPQ_create`)
 * @param TYPE                                The element type stored in the priority queue
 * @param TYPE_REF_COMPARE_FUNC               Function comparing two `TYPE*` (for priority)
 */
#define DEFINE_GENERIC_PRIORITY_QUEUE(                                                                                      \
    PRIORITY_QUEUE_NAME_PUBLIC_PREFIX,                                                                                      \
    TYPE,                                                                                                                   \
    TYPE_REF_COMPARE_FUNC                                                                                                   \
)                                                                                                                           \
                                                                                                                            \
DEFINE_GENERIC_HEAPIFY_FUNCTIONS(                                                                                           \
    _C_PRIVATE_MEMBER(PRIORITY_QUEUE_NAME_PUBLIC_PREFIX, Heap),                                                             \
    TYPE,                                                                                                                   \
    TYPE_REF_COMPARE_FUNC                                                                                                   \
)                                                                                                                           \
                                                                                                                            \
DEFINE_GENERIC_VECTOR(                                                                                                      \
    _C_PRIVATE_MEMBER(PRIORITY_QUEUE_NAME_PUBLIC_PREFIX, Vector),                                                           \
    TYPE                                                                                                                    \
)                                                                                                                           \
                                                                                                                            \
_DEFINE_GENERIC_PRIORITY_QUEUE_IMPL(                                                                                        \
    PRIORITY_QUEUE_NAME_PUBLIC_PREFIX,                                                                                      \
    _C_PRIVATE_MEMBER(PRIORITY_QUEUE_NAME_PUBLIC_PREFIX, Heap), /*same as above*/                                           \
    _C_PRIVATE_MEMBER(PRIORITY_QUEUE_NAME_PUBLIC_PREFIX, Vector), /*same as above*/                                         \
    TYPE                                                                                                                    \
)                                                                                                                           \


#endif // C_PRIORITY_QUEUE_H