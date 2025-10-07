#ifndef C_PRIORITY_QUEUE_H
#define C_PRIORITY_QUEUE_H


#include "custom/c_vector.h"


#define _DEFINE_GENERIC_PRIORITY_QUEUE_IMPL(                                                                                                \
    PQ_NAME,                                                                                                                                \
    PQ_HEAPIFY_HELPER_NAME,                                                                                                                 \
    PQ_VECTOR_HELPER_NAME,                                                                                                                  \
    TYPE                                                                                                                                    \
)                                                                                                                                           \
                                                                                                                                            \
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
static void         _C_PUBLIC_MEMBER(PQ_NAME, clear)(PQ_NAME* target);                                                                      \
static size_t       _C_PUBLIC_MEMBER(PQ_NAME, size)(const PQ_NAME* target);                                                                 \
static bool         _C_PUBLIC_MEMBER(PQ_NAME, empty)(const PQ_NAME* target);                                                                \
static void         _C_PUBLIC_MEMBER(PQ_NAME, insert)(PQ_NAME* target);                                                                     \
static void         _C_PUBLIC_MEMBER(PQ_NAME, insert_copy)(PQ_NAME* target, const TYPE* item);                                              \
static void         _C_PUBLIC_MEMBER(PQ_NAME, insert_move)(PQ_NAME* target, TYPE* item);                                                    \
static void         _C_PUBLIC_MEMBER(PQ_NAME, pop)(PQ_NAME* target);                                                                        \
static TYPE*        _C_PUBLIC_MEMBER(PQ_NAME, peek)(PQ_NAME* target);                                                                       \
static const TYPE*  _C_PUBLIC_MEMBER(PQ_NAME, peek_const)(const PQ_NAME* target);                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PQ_NAME)                                                                                           \
{                                                                                                                                           \
    return (PQ_NAME){                                                                                                                       \
        .vec = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PQ_VECTOR_HELPER_NAME)()                                                                 \
    };                                                                                                                                      \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PQ_NAME)                                                                                          \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PQ_VECTOR_HELPER_NAME)(&target->vec);                                                              \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PQ_NAME)                                                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "PQ dest is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != source, "PQ source is NULL");                                                                                  \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PQ_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                                                     \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PQ_NAME)                                                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "PQ dest is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != source, "PQ source is NULL");                                                                                  \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PQ_VECTOR_HELPER_NAME)(&dest->vec, &source->vec);                                                     \
}                                                                                                                                           \
                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PQ_NAME)                                                                                           \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != left, "PQ left is NULL");                                                                                      \
    _C_CUSTOM_ASSERT(NULL != right, "PQ right is NULL");                                                                                    \
    return _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PQ_VECTOR_HELPER_NAME)(&left->vec, &right->vec);                                             \
}                                                                                                                                           \
                                                                                                                                            \
static void _C_PUBLIC_MEMBER(PQ_NAME, clear)(PQ_NAME* target)                                                                               \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, clear)(&target->vec);                                                                           \
}                                                                                                                                           \
                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(PQ_NAME, size)(const PQ_NAME* target)                                                                        \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, size)(&target->vec);                                                                     \
}                                                                                                                                           \
                                                                                                                                            \
static bool _C_PUBLIC_MEMBER(PQ_NAME, empty)(const PQ_NAME* target)                                                                         \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, empty)(&target->vec);                                                                    \
}                                                                                                                                           \
                                                                                                                                            \
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
static TYPE* _C_PUBLIC_MEMBER(PQ_NAME, peek)(PQ_NAME* target)                                                                               \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, element_front)(&target->vec);                                                            \
}                                                                                                                                           \
                                                                                                                                            \
static const TYPE* _C_PUBLIC_MEMBER(PQ_NAME, peek_const)(const PQ_NAME* target)                                                             \
{                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Priority Queue is NULL");                                                                             \
    return _C_PUBLIC_MEMBER(PQ_VECTOR_HELPER_NAME, element_front_const)(&target->vec);                                                      \
}                                                                                                                                           \


/**
 * @brief Fully defines a priority queue for a given type with all required dependencies.
 * @param PRIORITY_QUEUE_NAME_PUBLIC_PREFIX   Public prefix (e.g. `MyPQ` → `MyPQ_create`)
 * @param TYPE                                The element type stored in the priority queue
 * @param TYPE_REF_COMPARE_FUNC               Comparison function for priority (signature: `bool comp(const TYPE *, const TYPE *)`)
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