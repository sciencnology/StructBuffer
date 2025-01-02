#pragma once
#include "../struct_buffer.hpp"

/**
 * 目前支持的类型列表
 * * 数值类型，包括所有整型和浮点类型
 * * 字符串，即std::string
 * * 列表，即std::vector
 * * 元组，即std::tuple
 * * 自定义结构体
*/

/**
 * @brief: 简单数值类型结构体
*/
struct SimpleStruct
{
    // 在DEFINE_STRUCT_BUFFER_MEMBERS中传入所有需要序列化的成员变量
    DEFINE_STRUCT_BUFFER_MEMBERS(int_member, double_member);

    // 可以在数据类中自由添加任何成员函数,不会影响数据序列化,e.g:
    bool operator==(const SimpleStruct&) const  = default;
    double avg() {
        return double_member / int_member;
    }

    int32_t int_member = 0;
    double double_member = 0.0;
};

/**
 * @brief: 字符串类型结构体
*/
struct StringsStruct
{
    DEFINE_STRUCT_BUFFER_MEMBERS(string_member_1, string_member_2);
    bool operator==(const StringsStruct&) const  = default;
    std::string string_member_1;
    std::string string_member_2;
};

/**
 * @brief: 数组类型结构体
*/
struct VectorStruct
{
    DEFINE_STRUCT_BUFFER_MEMBERS(int_vec, struct_vec);
    bool operator==(const VectorStruct&) const  = default;
    std::vector<int32_t> int_vec;
    std::vector<SimpleStruct> struct_vec;   // 数组元素可以是任何合法类型
};

/**
 * @brief: 嵌套类型结构体，可以任意嵌套任何合法类型
*/
struct NestedStruct
{
    DEFINE_STRUCT_BUFFER_MEMBERS(simple_struct, strings_struct, vector_struct);
    bool operator==(const NestedStruct&) const  = default;
    SimpleStruct simple_struct;
    StringsStruct strings_struct;
    VectorStruct vector_struct;
};

/**
 * @brief: 支持（可变）模板结构体
*/
template <typename... Args>
struct TemplatedCommonStruct
{
    DEFINE_STRUCT_BUFFER_MEMBERS(data);
    bool operator==(const TemplatedCommonStruct<Args...>&) const  = default;
    std::tuple<Args...> data;
};