#pragma once
#include <type_traits>
#include <vector>

namespace structbuf
{
    namespace trait_helper
    {
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

        // 辅助变量模板（C++17 起）
        template <typename T, template <typename...> class Template>
        inline constexpr bool is_specialization_of_v = is_specialization_of<T, Template>::value;
    }
}