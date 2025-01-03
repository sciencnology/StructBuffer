#pragma once
#include "../struct_buffer.hpp"
#include <tuple>

/**
 * @brief: 符合std::aggregate_v的自定义结构体可以直接序列化
*/
struct SimpleStruct
{
    // 可以在数据类中自由添加任何成员函数,不会影响数据序列化,e.g:
    bool operator==(const SimpleStruct&) const  = default;
    double avg() {
        return double_member / int_member;
    }

    int32_t int_member = 0;
    double double_member = 0.0;
    std::string str_member;
};

struct ComplicatedStruct
{
    bool operator==(const ComplicatedStruct&) const  = default;
    std::vector<int32_t> int_vec;
    std::vector<std::string> str_vec;
    std::vector<SimpleStruct> struct_vec;
    std::tuple<double, SimpleStruct, std::tuple<float>> complicated_tuple;
};

template <typename... Args>
struct TemplatedNestedStruct
{
    bool operator==(const TemplatedNestedStruct&) const  = default;
    SimpleStruct simple_struct;
    ComplicatedStruct complicated_struct;
    std::tuple<Args...> templated_data;
};

/**
 * 对于非aggregate类型（比如存在私有变量或者自定义构造函数）的类，需要使用DEFINE_STRUCT_BUFFER_MEMBERS注册所有成员
*/
struct NonAggregateStruct
{
private:
    int int_member = 0;
    double double_member = 0.0;

public:
    NonAggregateStruct() = default;
    NonAggregateStruct(int i, double d): int_member(i), double_member(d) {}
    bool operator==(const NonAggregateStruct&) const  = default;
    DEFINE_STRUCT_BUFFER_MEMBERS(int_member, double_member);
};
