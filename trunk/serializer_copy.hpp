#pragma once

#include <string_view>
#include <cstdint>
#include <cstring>
#include "utils/trait_helper.h"
#include "utils/constexpr_for.hpp"
#include "utils/struct_member_getter.hpp"
#include "utils/flag_classes.h"
namespace structbuf
{
    namespace serializer
    {
        inline constexpr uint32_t SIZE_EXPAND_RATIO = 4;

        // forward declare
        template <typename T>
        std::string SaveToString(const T &src);

        template <typename T>
            requires std::is_arithmetic_v<T>
        std::string SaveTostringNumeric(const T &src)
        {
            std::string ret(sizeof(T), '\0');
            std::memcpy(&ret[0], &src, sizeof(T));
            return ret;
        }

        template <typename T>
            requires trait_helper::is_one_of_v<T, std::string>
        std::string SaveToStringString(const T &src)
        {
            size_t size = src.size();
            std::string ret(sizeof(size_t) + size, '\0');
            std::memcpy(&ret[0], &size, sizeof(size));
            std::memcpy(&ret[sizeof(size)], src.data(), size);
            return ret;
        }

        template <typename T>
            requires trait_helper::is_specialization_of_v<T, std::vector>
        std::string SaveToStringVector(const T &src)
        {
            using value_type = T::value_type;
            std::string ret;
            if constexpr (std::is_trivially_copyable_v<value_type>)
            {
                size_t size = src.size() * sizeof(value_type);
                ret.resize(sizeof(size_t) + size);
                std::memcpy(&ret[0], &size, sizeof(size));
                std::memcpy(&ret[sizeof(size)], src.data(), size);
            }
            else
            {
                ret.reserve(sizeof(size_t) + SIZE_EXPAND_RATIO * src.size() * sizeof(value_type));
                ret.resize(sizeof(size_t));
                for (const auto &elem : src)
                {
                    ret.append(SaveToString(elem));
                }

                size_t size = ret.size() - sizeof(size_t);
                std::memcpy(&ret[0], &size, sizeof(size));
                ret.shrink_to_fit();
            }
            return ret;
        }

        template <typename T>
            requires requires { T::data_struct_flag; }
        std::string SaveToStringStruct(const T &src)
        {
            std::string ret;
            if constexpr (std::is_trivially_copyable_v<T>)
            {
                ret.resize(sizeof(T));
                std::memcpy(&ret[0], &src, sizeof(T));
            }
            else
            {
                ret.reserve(SIZE_EXPAND_RATIO * sizeof(T));
                ret.resize(sizeof(size_t));
                constexpr_for<0, reflext_utils::member_count<T>()>([&ret, &src]<size_t I>()
                                                                   { ret.append(SaveToString(src.template Get<I>())); });
                size_t size = ret.size() - sizeof(size_t);
                std::memcpy(&ret[0], &size, sizeof(size));
                ret.shrink_to_fit();
            }
            return ret;
        }

        template <typename T>
        std::string SaveToString(const T &src)
        {
            if constexpr (std::is_arithmetic_v<T>)
            {
                return SaveTostringNumeric(src);
            }
            if constexpr (trait_helper::is_one_of_v<T, std::string>)
            {
                return SaveToStringString(src);
            }
            if constexpr (trait_helper::is_specialization_of_v<T, std::vector>)
            {
                return SaveToStringVector(src);
            }
            if constexpr (requires { T::data_struct_flag; })
            {
                return SaveToStringStruct(src);
            }
        }
    }
}
