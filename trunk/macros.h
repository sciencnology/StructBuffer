#pragma once
#include <string>
#include "utils/flag_classes.h"

#define DEF_DATA_STUCT inline static structbuf::flag_classes::DataStructFlag data_struct_flag;

#define GET_FUNC_HEAD()  \
    template <size_t N>  \
    decltype(auto) Get() \
    {

#define GET_FUNC_HEAD_CONST()  \
    template <size_t N>        \
    decltype(auto) Get() const \
    {

#define GET_FUNC_TAIL(max_index)                     \
    if constexpr (max_index < N)                     \
    {                                                \
        return structbuf::flag_classes::MemberEnd{}; \
    }                                                \
    }

#define GET_FUNC_BODY_1(_1) \
    if constexpr (0 == N)   \
    {                       \
        return (_1);        \
    }
#define DEFINE_GET_FUNC_1(_1) \
    GET_FUNC_HEAD()           \
    GET_FUNC_BODY_1(_1)       \
    GET_FUNC_TAIL(0)          \
    GET_FUNC_HEAD_CONST()     \
    GET_FUNC_BODY_1(_1)       \
    GET_FUNC_TAIL(0)
#define GET_FUNC_BODY_2(_1, _2) \
    GET_FUNC_BODY_1(_1)         \
    if constexpr (1 == N)       \
    {                           \
        return (_2);            \
    }
#define DEFINE_GET_FUNC_2(_1, _2) \
    GET_FUNC_HEAD()               \
    GET_FUNC_BODY_2(_1, _2)       \
    GET_FUNC_TAIL(1)              \
    GET_FUNC_HEAD_CONST()         \
    GET_FUNC_BODY_2(_1, _2)       \
    GET_FUNC_TAIL(1)
#define GET_FUNC_BODY_3(_1, _2, _3) \
    GET_FUNC_BODY_2(_1, _2)         \
    if constexpr (2 == N)           \
    {                               \
        return (_3);                \
    }
#define DEFINE_GET_FUNC_3(_1, _2, _3) \
    GET_FUNC_HEAD()                   \
    GET_FUNC_BODY_3(_1, _2, _3)       \
    GET_FUNC_TAIL(2)                  \
    GET_FUNC_HEAD_CONST()             \
    GET_FUNC_BODY_3(_1, _2, _3)       \
    GET_FUNC_TAIL(2)
#define GET_FUNC_BODY_4(_1, _2, _3, _4) \
    GET_FUNC_BODY_3(_1, _2, _3)         \
    if constexpr (3 == N)               \
    {                                   \
        return (_4);                    \
    }
#define DEFINE_GET_FUNC_4(_1, _2, _3, _4) \
    GET_FUNC_HEAD()                       \
    GET_FUNC_BODY_4(_1, _2, _3, _4)       \
    GET_FUNC_TAIL(3)                      \
    GET_FUNC_HEAD_CONST()                 \
    GET_FUNC_BODY_4(_1, _2, _3, _4)       \
    GET_FUNC_TAIL(3)
