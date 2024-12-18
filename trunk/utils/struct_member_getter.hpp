#pragma once
#include <cstddef>
#include <utility>
#include <type_traits>

#include "flag_classes.h"

namespace structbuf
{
    namespace reflext_utils
    {
        template <typename T, std::size_t N>
        constexpr bool test_size_valid()
        {
            using ReturnType = decltype(std::declval<T>().template Get<N>());
            return !std::is_same_v<flag_classes::MemberEnd, std::remove_reference_t<ReturnType>>;
        }

        template <typename T, size_t N = 0>
        constexpr auto member_count()
        {
            if constexpr (!test_size_valid<T, N>())
            {
                return N;
            }
            else
            {
                return member_count<T, N + 1>();
            }
        }
    }
}