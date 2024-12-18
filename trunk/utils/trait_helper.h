#pragma once
#include <type_traits>
#include <vector>

namespace structbuf
{
    namespace trait_helper
    {
        template <typename T, typename... Types>
        inline constexpr bool is_one_of_v = (std::is_same_v<T, Types> || ...);

        template <typename T>
        struct is_std_vector : std::false_type
        {
        };

        template <typename T, typename Alloc>
        struct is_std_vector<std::vector<T, Alloc>> : std::true_type
        {
        };

        template <typename T>
        inline constexpr bool is_std_vector_v = is_std_vector<T>::value;
    }
}