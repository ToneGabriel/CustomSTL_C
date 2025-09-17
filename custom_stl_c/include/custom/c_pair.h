#ifndef C_PAIR_H
#define C_PAIR_H


#include "custom/c_utility.h"


#define DEFINE_GENERIC_PAIR(                                                                                \
    PAIR_NAME,                                                                                              \
    TYPE_1,                                                                                                 \
    TYPE_2                                                                                                  \
)                                                                                                           \
                                                                                                            \
typedef struct                                                                                              \
{                                                                                                           \
    TYPE_1 first;                                                                                           \
    TYPE_2 second;                                                                                          \
} PAIR_NAME;                                                                                                \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PAIR_NAME);                                                        \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PAIR_NAME);                                                       \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PAIR_NAME);                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PAIR_NAME);                                                          \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PAIR_NAME);                                                        \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(PAIR_NAME)                                                         \
{                                                                                                           \
    return (PAIR_NAME){                                                                                     \
        .first = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE_1)(),                                             \
        .second = _C_CUSTOM_TYPE_PUBLIC_MEMBER_CREATE(TYPE_2)()                                             \
    };                                                                                                      \
}                                                                                                           \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(PAIR_NAME)                                                        \
{                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != target, "Pair is NULL");                                                       \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE_1)(&target->first);                                           \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_DESTROY(TYPE_2)(&target->second);                                          \
}                                                                                                           \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(PAIR_NAME)                                                           \
{                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "Pair dest is NULL");                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "Pair source is NULL");                                                \
    if (dest == source) return;                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE_1)(&dest->first, &source->first);                                \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_COPY(TYPE_2)(&dest->second, &source->second);                              \
}                                                                                                           \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(PAIR_NAME)                                                           \
{                                                                                                           \
    _C_CUSTOM_ASSERT(NULL != dest, "Pair dest is NULL");                                                    \
    _C_CUSTOM_ASSERT(NULL != source, "Pair source is NULL");                                                \
    if (dest == source) return;                                                                             \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE_1)(&dest->first, &source->first);                                \
    _C_CUSTOM_TYPE_PUBLIC_MEMBER_MOVE(TYPE_2)(&dest->second, &source->second);                              \
}                                                                                                           \
                                                                                                            \
DECLARE_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(PAIR_NAME)                                                         \
{                                                                                                           \
    return  _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE_1)(&left->first, &right->first) &&                     \
            _C_CUSTOM_TYPE_PUBLIC_MEMBER_EQUALS(TYPE_2)(&left->second, &right->second);                     \
}                                                                                                           \


#endif // C_PAIR_H