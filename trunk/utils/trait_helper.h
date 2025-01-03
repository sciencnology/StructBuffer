#pragma once
#include <type_traits>
#include <vector>

namespace structbuf
{
    namespace trait_helper
    {
        /**
         * @brief: 提供了几个自定义类型萃取
         * * is_one_of_v<T,U,V,W,...> 判断T是否为后面几种类型之一
         * * is_specialization_of_v<T,Template> 判断T是否为指定模板类型Template的某个实例
         * * is_c_string_v<T> 判断T是否为C风格字符串
        */

        template <typename T, typename... Types>
        inline constexpr bool is_one_of_v = (std::is_same_v<T, Types> || ...);

        // 通用模板：默认不是模板的实例
        template <typename, template <typename...> class>
        struct is_specialization_of : std::false_type
        {
        };

        // 偏特化：当类型是指定模板的实例时
        template <typename... Args, template <typename...> class Template>
        struct is_specialization_of<Template<Args...>, Template> : std::true_type
        {
        };

        // 辅助变量模板
        template <typename T, template <typename...> class Template>
        inline constexpr bool is_specialization_of_v = is_specialization_of<T, Template>::value;


        template <typename T>
        struct is_c_string : std::false_type {};

        // 偏特化用于匹配 const char*
        template <>
        struct is_c_string<const char*> : std::true_type {};

        // 偏特化用于匹配 char*
        template <>
        struct is_c_string<char*> : std::true_type {};

        // 偏特化用于匹配 char 数组
        template <std::size_t N>
        struct is_c_string<const char[N]> : std::true_type {};

        template <std::size_t N>
        struct is_c_string<char[N]> : std::true_type {};

        // 辅助变量模板
        template <typename T>
        constexpr bool is_c_string_v = is_c_string<T>::value;
    }
}