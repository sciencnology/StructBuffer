#pragma once

#include <string_view>
#include <cstdint>
#include <cstring>

#include "utils/trait_helper.h"
#include "utils/constexpr_for.hpp"
#include "utils/struct_member_getter.hpp"
#include "utils/flag_classes.h"
#include "utils/aggregate_constexpr_for.hpp"

namespace structbuf
{
    namespace deserializer
    {
        /**
         * @brief 接收一个代表某不定长结构编码结果的string_view，可以解析其每个组成部分
        */
        struct SVParser
        {
            std::string_view sv;
            size_t cur_pos = 0;
            constexpr SVParser(std::string_view sv) : sv(sv) {}
            constexpr bool End()
            {
                return cur_pos >= sv.size();
            }
            constexpr std::string_view GetNext()
            {
                if (End())
                {
                    return "";
                }
                size_t next_size = 0;
                std::string_view length_sv = sv.substr(cur_pos, sizeof(next_size));
                std::memcpy(&next_size, length_sv.data(), length_sv.size());
                next_size += sizeof(next_size);
                std::string_view ret = sv.substr(cur_pos, next_size);
                cur_pos += next_size;
                return ret;
            }
            std::vector<std::string_view> GetAllParts()
            {
                std::vector<std::string_view> ret;
                while (!End())
                {
                    ret.emplace_back(GetNext());
                }
                return ret;
            }
        };

        // forward declare
        template <typename T>
        constexpr std::string_view InnerParseFromSV(T &dest, std::string_view sv);

        template <typename T>
            requires std::is_arithmetic_v<std::decay_t<T>>
        constexpr std::string_view ParseFromSVNumeric(T &dest, std::string_view sv)
        {
            std::memcpy(&dest, sv.data(), sizeof(T));
            return sv.substr(sizeof(T));
        }

        template <typename T>
            requires trait_helper::is_one_of_v<std::decay_t<T>, std::string>
        constexpr std::string_view ParseFromSVString(T &dest, std::string_view sv)
        {
            size_t str_size = 0;
            std::memcpy(&str_size, sv.data(), sizeof(size_t));

            dest = std::string(sv.substr(sizeof(size_t), str_size));
            return sv.substr(sizeof(size_t) + str_size);
        }

        template <typename T>
            requires trait_helper::is_specialization_of_v<std::decay_t<T>, std::vector>
        constexpr std::string_view ParseFromSVVector(T &dest, std::string_view sv)
        {
            using value_type = T::value_type;
            size_t vec_size = 0;
            std::memcpy(&vec_size, sv.data(), sizeof(size_t));
            std::string_view data_sv = sv.substr(sizeof(size_t), vec_size);
            if constexpr (std::is_trivially_copyable_v<value_type>)
            {
                dest.resize(vec_size / sizeof(value_type));
                std::memcpy(dest.data(), data_sv.data(), vec_size);
            }
            else
            {
                SVParser sv_parser(data_sv);
                while (!sv_parser.End())
                {
                    auto &next = dest.emplace_back();
                    InnerParseFromSV<value_type>(next, sv_parser.GetNext());
                }
            }
            return sv.substr(sizeof(size_t) + vec_size);
        }

        template <typename T>
            requires trait_helper::is_specialization_of_v<std::decay_t<T>, std::tuple>
        constexpr std::string_view ParseFromSVTuple(T &dest, std::string_view sv)
        {
            if constexpr (std::is_trivially_copyable_v<T>)
            {
                std::memcpy(&dest, sv.data(), sizeof(T));
                return sv.substr(sizeof(T));
            }
            else
            {
                size_t total_size = 0;
                std::memcpy(&total_size, sv.data(), sizeof(size_t));
                std::string_view data_sv = sv.substr(sizeof(size_t), total_size);
                constexpr_for<0, std::tuple_size_v<T>>([&dest, &data_sv]<size_t I>()
                                                       { data_sv = InnerParseFromSV(std::get<I>(dest), data_sv); });
                return sv.substr(sizeof(size_t) + total_size);
            }
        }

        template <typename T>
            requires std::is_aggregate_v<std::decay_t<T>>
        constexpr std::string_view ParseFromSVAggregate(T &dest, std::string_view sv)
        {
            if constexpr (std::is_trivially_copyable_v<T>)
            {
                std::memcpy(&dest, sv.data(), sizeof(T));
                return sv.substr(sizeof(T));
            }
            else
            {
                size_t struct_size = 0;
                std::memcpy(&struct_size, sv.data(), sizeof(size_t));
                std::string_view data_sv = sv.substr(sizeof(size_t), struct_size);

                aggregate_utils::constexpr_for(dest, [&dest, &data_sv](auto&& v) { data_sv = InnerParseFromSV(v, data_sv); });

                return sv.substr(sizeof(size_t) + struct_size);
            }
        }

        template <typename T>
            requires requires { T::data_struct_flag; }
        constexpr std::string_view ParseFromSVStruct(T &dest, std::string_view sv)
        {
            if constexpr (std::is_trivially_copyable_v<T>)
            {
                std::memcpy(&dest, sv.data(), sizeof(T));
                return sv.substr(sizeof(T));
            }
            else
            {
                size_t struct_size = 0;
                std::memcpy(&struct_size, sv.data(), sizeof(size_t));
                std::string_view data_sv = sv.substr(sizeof(size_t), struct_size);
                constexpr_for<0, reflext_utils::member_count<T>()>([&dest, &data_sv]<size_t I>()
                                                                   { data_sv = InnerParseFromSV(dest.template Get<I>(), data_sv); });
                return sv.substr(sizeof(size_t) + struct_size);
            }
        }

        template <typename T>
        constexpr std::string_view InnerParseFromSV(T &dest, std::string_view sv)
        {
            if constexpr (std::is_arithmetic_v<std::decay_t<T>>)
            {
                return ParseFromSVNumeric(dest, sv);
            }
            else if constexpr (trait_helper::is_one_of_v<std::decay_t<T>, std::string>)
            {
                return ParseFromSVString(dest, sv);
            }
            else if constexpr (trait_helper::is_specialization_of_v<std::decay_t<T>, std::vector>)
            {
                return ParseFromSVVector(dest, sv);
            }
            else if constexpr (trait_helper::is_specialization_of_v<std::decay_t<T>, std::tuple>)
            {
                return ParseFromSVTuple(dest, sv);
            }
            else if constexpr (std::is_aggregate_v<std::decay_t<T>>)
            {
                return ParseFromSVAggregate(dest, sv);
            }
            else if constexpr (requires { T::data_struct_flag; })
            {
                return ParseFromSVStruct(dest, sv);
            }
            else
            {
                static_assert(false, "this type cannot be deserialized");
            }
        }

        template <typename T>
        constexpr void ParseFromSV(T &dest, std::string_view sv)
        {
            InnerParseFromSV(dest, sv);
        }
    }
}