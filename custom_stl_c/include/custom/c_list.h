#ifndef C_LIST_H
#define C_LIST_H


#include "custom/_c_node.h"
#include "custom/c_utility.h"


#define _DEFINE_GENERIC_LIST_DATA(      \
    LIST_NAME,                          \
    NODE_NAME                           \
)                                       \
                                        \
typedef struct                          \
{                                       \
    size_t size;                        \
    NODE_NAME* head;                    \
} LIST_NAME;                            \


#define _DEFINE_GENERIC_LIST_ITERATOR(                                                                                              \
    LIST_ITERATOR_NAME,                                                                                                             \
    LIST_NAME,                                                                                                                      \
    NODE_NAME,                                                                                                                      \
    TYPE                                                                                                                            \
)                                                                                                                                   \
                                                                                                                                    \
typedef struct                                                                                                                      \
{                                                                                                                                   \
    NODE_NAME* node;                                                                                                                \
    LIST_NAME* list;                                                                                                                \
} LIST_ITERATOR_NAME;                                                                                                               \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME);                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_ITERATOR_NAME);                                                                      \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_ITERATOR_NAME);                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_ITERATOR_NAME);                                                                         \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_ITERATOR_NAME);                                                                       \
                                                                                                                                    \
static void                 _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_increment)(LIST_ITERATOR_NAME* iter);                          \
static LIST_ITERATOR_NAME   _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_increment)(LIST_ITERATOR_NAME* iter);                         \
static void                 _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_decrement)(LIST_ITERATOR_NAME* iter);                          \
static LIST_ITERATOR_NAME   _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_decrement)(LIST_ITERATOR_NAME* iter);                         \
static TYPE*                _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, deref)(LIST_ITERATOR_NAME* iter);                                  \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME)                                                                        \
{                                                                                                                                   \
    return (LIST_ITERATOR_NAME){                                                                                                    \
        .node = NULL,                                                                                                               \
        .list = NULL                                                                                                                \
    };                                                                                                                              \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_ITERATOR_NAME)                                                                       \
{                                                                                                                                   \
    target->node = NULL;                                                                                                            \
    target->list = NULL;                                                                                                            \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_ITERATOR_NAME)                                                                          \
{                                                                                                                                   \
    dest->node = source->node;                                                                                                      \
    dest->list = source->list;                                                                                                      \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_ITERATOR_NAME)                                                                          \
{                                                                                                                                   \
    dest->node = source->node;                                                                                                      \
    dest->list = source->list;                                                                                                      \
}                                                                                                                                   \
                                                                                                                                    \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_ITERATOR_NAME)                                                                        \
{                                                                                                                                   \
    return left->node == right->node;                                                                                               \
}                                                                                                                                   \
                                                                                                                                    \
static void _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_increment)(LIST_ITERATOR_NAME* iter)                                           \
{                                                                                                                                   \
    _C_CUSTOM_ASSERT(iter->node != iter->list->head, "Cannot increment end iterator.");                                             \
    iter->node = iter->node->next;                                                                                                  \
}                                                                                                                                   \
                                                                                                                                    \
static LIST_ITERATOR_NAME _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_increment)(LIST_ITERATOR_NAME* iter)                            \
{                                                                                                                                   \
    LIST_ITERATOR_NAME temp = *iter;                                                                                                \
    _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_increment)(iter);                                                                      \
    return temp;                                                                                                                    \
}                                                                                                                                   \
                                                                                                                                    \
static void _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_decrement)(LIST_ITERATOR_NAME* iter)                                           \
{                                                                                                                                   \
    _C_CUSTOM_ASSERT(iter->node != iter->list->head->next, "Cannot decrement begin iterator.");                                     \
    iter->node = iter->node->prev;                                                                                                  \
}                                                                                                                                   \
                                                                                                                                    \
static LIST_ITERATOR_NAME _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, post_decrement)(LIST_ITERATOR_NAME* iter)                            \
{                                                                                                                                   \
    LIST_ITERATOR_NAME temp = *iter;                                                                                                \
    _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, pre_decrement)(iter);                                                                      \
    return temp;                                                                                                                    \
}                                                                                                                                   \
                                                                                                                                    \
static TYPE* _C_PUBLIC_MEMBER(LIST_ITERATOR_NAME, deref)(LIST_ITERATOR_NAME* iter)                                                  \
{                                                                                                                                   \
    _C_CUSTOM_ASSERT(iter->node != iter->list->head, "Cannot dereference end iterator.");                                           \
    return &iter->node->value;                                                                                                      \
}                                                                                                                                   \


#define _DEFINE_GENERIC_LIST_IMPL(                                                                                                                          \
    LIST_NAME,                                                                                                                                              \
    LIST_ITERATOR_NAME,                                                                                                                                     \
    NODE_NAME,                                                                                                                                              \
    TYPE                                                                                                                                                    \
)                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_NAME);                                                                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_NAME);                                                                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_NAME);                                                                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_NAME);                                                                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_NAME);                                                                                                        \
                                                                                                                                                            \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, clear)(LIST_NAME* target);                                                                          \
static size_t               _C_PUBLIC_MEMBER(LIST_NAME, size)(const LIST_NAME* target);                                                                     \
static bool                 _C_PUBLIC_MEMBER(LIST_NAME, empty)(const LIST_NAME* target);                                                                    \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_back)(LIST_NAME* target);                                                                      \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_back_copy)(LIST_NAME* target, const TYPE* item);                                               \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_back_move)(LIST_NAME* target, TYPE* item);                                                     \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_front)(LIST_NAME* target);                                                                     \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_front_copy)(LIST_NAME* target, const TYPE* item);                                              \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, push_front_move)(LIST_NAME* target, TYPE* item);                                                    \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, pop_back)(LIST_NAME* target);                                                                       \
static void                 _C_PUBLIC_MEMBER(LIST_NAME, pop_front)(LIST_NAME* target);                                                                      \
static TYPE*                _C_PUBLIC_MEMBER(LIST_NAME, element_front)(LIST_NAME* target);                                                                  \
static TYPE*                _C_PUBLIC_MEMBER(LIST_NAME, element_back)(LIST_NAME* target);                                                                   \
static LIST_ITERATOR_NAME   _C_PUBLIC_MEMBER(LIST_NAME, begin)(LIST_NAME* target);                                                                          \
static LIST_ITERATOR_NAME   _C_PUBLIC_MEMBER(LIST_NAME, end)(LIST_NAME* target);                                                                            \
                                                                                                                                                            \
static void                 _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(LIST_NAME* target, NODE_NAME* before, NODE_NAME* node);                          \
static void                 _C_PRIVATE_MEMBER(LIST_NAME, unlink_node)(LIST_NAME* target, NODE_NAME* node);                                                  \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_NAME)                                                                                                         \
{                                                                                                                                                           \
    NODE_NAME* new_head = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();    /*head value remains uninitialized*/                                                \
    new_head->next = new_head->prev = new_head;                                                                                                             \
    return (LIST_NAME){                                                                                                                                     \
        .size = 0,                                                                                                                                          \
        .head = new_head                                                                                                                                    \
    };                                                                                                                                                      \
}                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_NAME)                                                                                                        \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    if (NULL == target->head) return;                                                                                                                       \
    _C_PUBLIC_MEMBER(LIST_NAME, clear)(target);                                                                                                             \
    _C_PUBLIC_MEMBER(NODE_NAME, destroy_ptr)(target->head);                                                                                                 \
    target->size = 0;                                                                                                                                       \
    target->head = NULL;                                                                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(LIST_NAME)                                                                                                           \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "List dest is NULL");                                                                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "List source is NULL");                                                                                                \
    if (dest == source) return;                                                                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_NAME)(dest);                                                                                                  \
    if (NULL == source->head) return;                                                                                                                       \
    *dest = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_NAME)();                                                                                               \
    for (NODE_NAME* temp = source->head->next; dest->size < source->size; temp = temp->next)                                                                \
        _C_PUBLIC_MEMBER(LIST_NAME, push_back_copy)(dest, &temp->value);                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(LIST_NAME)                                                                                                           \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "List dest is NULL");                                                                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "List source is NULL");                                                                                                \
    if (dest == source) return;                                                                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(LIST_NAME)(dest);                                                                                                  \
    if (NULL == source->head) return;                                                                                                                       \
    *dest = *source;                                                                                                                                        \
    source->size = 0;                                                                                                                                       \
    source->head = NULL;                                                                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(LIST_NAME)                                                                                                         \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != left, "List left is NULL");                                                                                                    \
    _C_CUSTOM_ASSERT(NULL != right, "List right is NULL");                                                                                                  \
    if (left->size != right->size) return false;                                                                                                            \
    NODE_NAME* currentLeft = left->head->next;                                                                                                              \
    NODE_NAME* currentRight = right->head->next;                                                                                                            \
    for (/* Empty */; currentLeft != left->head; currentLeft = currentLeft->next, currentRight = currentRight->next)                                        \
        if (!_C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE)(&currentLeft->value, &currentRight->value)) return false;                                            \
    return true;                                                                                                                                            \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, clear)(LIST_NAME* target)                                                                                           \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    while (target->size)                                                                                                                                    \
        _C_PUBLIC_MEMBER(LIST_NAME, pop_back)(target);                                                                                                      \
}                                                                                                                                                           \
                                                                                                                                                            \
static size_t _C_PUBLIC_MEMBER(LIST_NAME, size)(const LIST_NAME* target)                                                                                    \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    return target->size;                                                                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
static bool _C_PUBLIC_MEMBER(LIST_NAME, empty)(const LIST_NAME* target)                                                                                     \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    return 0 == target->size;                                                                                                                               \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_back)(LIST_NAME* target)                                                                                       \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head, new_node);                                                                         \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_back_copy)(LIST_NAME* target, const TYPE* item)                                                                \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(&new_node->value, item);                                                                      \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head, new_node);                                                                         \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_back_move)(LIST_NAME* target, TYPE* item)                                                                      \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(&new_node->value, item);                                                                      \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head, new_node);                                                                         \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_front)(LIST_NAME* target)                                                                                      \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head->next, new_node);                                                                   \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_front_copy)(LIST_NAME* target, const TYPE* item)                                                               \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE)(&new_node->value, item);                                                                      \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head->next, new_node);                                                                   \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, push_front_move)(LIST_NAME* target, TYPE* item)                                                                     \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    NODE_NAME* new_node = _C_PUBLIC_MEMBER(NODE_NAME, create_ptr)();                                                                                        \
    new_node->value = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE)();                                                                                          \
    if (NULL != item) _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE)(&new_node->value, item);                                                                      \
    _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(target, target->head->next, new_node);                                                                   \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, pop_back)(LIST_NAME* target)                                                                                        \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    if (0 == target->size) return;                                                                                                                          \
    NODE_NAME* junk_node = target->head->prev;                                                                                                              \
    _C_PRIVATE_MEMBER(LIST_NAME, unlink_node)(target, junk_node);                                                                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(&junk_node->value);                                                                                          \
    _C_PUBLIC_MEMBER(NODE_NAME, destroy_ptr)(junk_node);                                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PUBLIC_MEMBER(LIST_NAME, pop_front)(LIST_NAME* target)                                                                                       \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    if (0 == target->size) return;                                                                                                                          \
    NODE_NAME* junk_node = target->head->next;                                                                                                              \
    _C_PRIVATE_MEMBER(LIST_NAME, unlink_node)(target, junk_node);                                                                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE)(&junk_node->value);                                                                                          \
    _C_PUBLIC_MEMBER(NODE_NAME, destroy_ptr)(junk_node);                                                                                                    \
}                                                                                                                                                           \
                                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(LIST_NAME, element_front)(LIST_NAME* target)                                                                                  \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    _C_CUSTOM_ASSERT(target->size != 0, "List is empty");                                                                                                   \
    return &target->head->next->value;                                                                                                                      \
}                                                                                                                                                           \
                                                                                                                                                            \
static TYPE* _C_PUBLIC_MEMBER(LIST_NAME, element_back)(LIST_NAME* target)                                                                                   \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    _C_CUSTOM_ASSERT(target->size != 0, "List is empty");                                                                                                   \
    return &target->head->prev->value;                                                                                                                      \
}                                                                                                                                                           \
                                                                                                                                                            \
static LIST_ITERATOR_NAME _C_PUBLIC_MEMBER(LIST_NAME, begin)(LIST_NAME* target)                                                                             \
{                                                                                                                                                           \
    LIST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME)();                                                                    \
    iter.node = target->head->next;                                                                                                                         \
    iter.list = target;                                                                                                                                     \
    return iter;                                                                                                                                            \
}                                                                                                                                                           \
                                                                                                                                                            \
static LIST_ITERATOR_NAME _C_PUBLIC_MEMBER(LIST_NAME, end)(LIST_NAME* target)                                                                               \
{                                                                                                                                                           \
    LIST_ITERATOR_NAME iter = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(LIST_ITERATOR_NAME)();                                                                    \
    iter.node = target->head;                                                                                                                               \
    iter.list = target;                                                                                                                                     \
    return iter;                                                                                                                                            \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PRIVATE_MEMBER(LIST_NAME, link_node_before)(LIST_NAME* target, NODE_NAME* before, NODE_NAME* node)                                           \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    node->prev = before->prev;                                                                                                                              \
    node->next = before;                                                                                                                                    \
    before->prev->next = node;                                                                                                                              \
    before->prev = node;                                                                                                                                    \
    ++target->size;                                                                                                                                         \
}                                                                                                                                                           \
                                                                                                                                                            \
static void _C_PRIVATE_MEMBER(LIST_NAME, unlink_node)(LIST_NAME* target, NODE_NAME* node)                                                                   \
{                                                                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "List is NULL");                                                                                                       \
    node->prev->next = node->next;                                                                                                                          \
    node->next->prev = node->prev;                                                                                                                          \
    node->next = node->prev = NULL;                                                                                                                         \
    --target->size;                                                                                                                                         \
}                                                                                                                                                           \


#define DEFINE_GENERIC_LIST(                                                                                            \
    LIST_NAME_PUBLIC_PREFIX,                                                                                            \
    TYPE                                                                                                                \
)                                                                                                                       \
                                                                                                                        \
DEFINE_GENERIC_DOUBLE_NODE(                                                                                             \
    _C_PRIVATE_MEMBER(LIST_NAME_PUBLIC_PREFIX, DoubleNode),                                                             \
    TYPE                                                                                                                \
)                                                                                                                       \
                                                                                                                        \
_DEFINE_GENERIC_LIST_DATA(                                                                                              \
    LIST_NAME_PUBLIC_PREFIX,                                                                                            \
    _C_PRIVATE_MEMBER(LIST_NAME_PUBLIC_PREFIX, DoubleNode)                                                              \
)                                                                                                                       \
                                                                                                                        \
_DEFINE_GENERIC_LIST_ITERATOR(                                                                                          \
    _C_PUBLIC_MEMBER(LIST_NAME_PUBLIC_PREFIX, Iterator),                                                                \
    LIST_NAME_PUBLIC_PREFIX,                                                                                            \
    _C_PRIVATE_MEMBER(LIST_NAME_PUBLIC_PREFIX, DoubleNode), /*same as above*/                                           \
    TYPE                                                                                                                \
)                                                                                                                       \
                                                                                                                        \
_DEFINE_GENERIC_LIST_IMPL(                                                                                              \
    LIST_NAME_PUBLIC_PREFIX,                                                                                            \
    _C_PUBLIC_MEMBER(LIST_NAME_PUBLIC_PREFIX, Iterator), /*same as above*/                                              \
    _C_PRIVATE_MEMBER(LIST_NAME_PUBLIC_PREFIX, DoubleNode), /*same as above*/                                           \
    TYPE                                                                                                                \
)                                                                                                                       \


#endif  // C_LIST_H