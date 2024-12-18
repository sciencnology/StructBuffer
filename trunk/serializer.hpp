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
        // forward declare
        template <typename T>
        constexpr std::string SaveToString(const T &src);

        template <typename T>
        constexpr char *SaveToString(const T &src, char *buf);

        /**
         * @brief 计算一个合法可序列化变量序列化后大小，用于序列化时分配指定大小的string
         */
        template <typename T>
        constexpr size_t GetSerializedSize(const T &src)
        {
            if constexpr (std::is_arithmetic_v<T>)
            {
                return sizeof(T);
            }
            if constexpr (trait_helper::is_one_of_v<T, std::string>)
            {
                return sizeof(size_t) + src.size();
            }
            if constexpr (trait_helper::is_std_vector_v<T>)
            {
                using value_type = T::value_type;
                if constexpr (std::is_trivially_copyable_v<value_type>)
                {
                    return sizeof(size_t) + src.size() * sizeof(value_type);
                }
                else
                {
                    size_t elem_size = 0;
                    for (const auto &elem : src)
                    {
                        elem_size += GetSerializedSize(elem);
                    }
                    return sizeof(size_t) + elem_size;
                }
            }
            if constexpr (requires { T::data_struct_flag; })
            {
                if constexpr (std::is_trivially_copyable_v<T>)
                {
                    return sizeof(T);
                }
                else
                {
                    size_t elem_size = 0;
                    constexpr_for<0, reflext_utils::member_count<T>()>([&elem_size, &src]<size_t I>()
                                                                       { elem_size += GetSerializedSize(src.template Get<I>()); });
                    return sizeof(size_t) + elem_size;
                }
            }
        }

        /**
         * @brief 对数值类型进行序列化
         * 直接以二进制形式进行内存拷贝
         */
        template <typename T>
            requires std::is_arithmetic_v<T>
        constexpr char *SaveTostringNumeric(const T &src, char *buf)
        {
            std::memcpy(buf, &src, GetSerializedSize(src));
            return buf + GetSerializedSize(src);
        }

        /**
         * @brief 对字符串类型进行序列化
         * 使用一个size_t记录字符串的长度，随后直接拷贝字符串内容
         * |size|content|
         */
        template <typename T>
            requires trait_helper::is_one_of_v<T, std::string>
        constexpr char *SaveToStringString(const T &src, char *buf)
        {
            size_t size = src.size();
            std::memcpy(buf, &size, sizeof(size));
            std::memcpy(buf + sizeof(size), src.data(), size);
            return buf + GetSerializedSize(src);
        }

        /**
         * @brief 对列表类型进行序列化
         * 使用一个size_t记录所有列表元素序列化的总长度，随后依次序列化所有列表元素
         * |size|elem1|elem2|elem3|
         */
        template <typename T>
            requires trait_helper::is_std_vector_v<T>
        constexpr char *SaveToStringVector(const T &src, char *buf)
        {
            using value_type = T::value_type;
            if constexpr (std::is_trivially_copyable_v<value_type>)
            {
                size_t size = src.size() * sizeof(value_type);
                std::memcpy(buf, &size, sizeof(size));
                std::memcpy(buf + sizeof(size), src.data(), size);
                return buf + sizeof(size_t) + size;
            }
            else
            {
                char *elem_buf_begin = buf + sizeof(size_t), *size_buf_end = elem_buf_begin;
                for (const auto &elem : src)
                {
                    elem_buf_begin = SaveToString(elem, elem_buf_begin);
                }

                size_t size = elem_buf_begin - size_buf_end;
                std::memcpy(buf, &size, sizeof(size));
                return elem_buf_begin;
            }
        }

        template <typename T>
            requires requires { T::data_struct_flag; }
        constexpr char *SaveToStringStruct(const T &src, char *buf)
        {
            if constexpr (std::is_trivially_copyable_v<T>)
            {
                std::memcpy(buf, &src, sizeof(T));
                return buf + sizeof(T);
            }
            else
            {
                char *elem_buf_begin = buf + sizeof(size_t), *size_buf_end = elem_buf_begin;
                constexpr_for<0, reflext_utils::member_count<T>()>([&elem_buf_begin, &src]<size_t I>()
                                                                   { elem_buf_begin = SaveToString(src.template Get<I>(), elem_buf_begin); });
                size_t size = elem_buf_begin - size_buf_end;
                std::memcpy(buf, &size, sizeof(size));
                return elem_buf_begin;
            }
        }

        template <typename T>
        constexpr char *SaveToString(const T &src, char *buf)
        {
            if constexpr (std::is_arithmetic_v<T>)
            {
                return SaveTostringNumeric(src, buf);
            }
            else if constexpr (trait_helper::is_one_of_v<T, std::string>)
            {
                return SaveToStringString(src, buf);
            }
            else if constexpr (trait_helper::is_std_vector_v<T>)
            {
                return SaveToStringVector(src, buf);
            }
            else if constexpr (requires { T::data_struct_flag; })
            {
                return SaveToStringStruct(src, buf);
            }
            else
            {
                static_assert(false, "this type cannot be serialized");
            }
        }

        template <typename T>
        constexpr std::string SaveToString(const T &src)
        {
            size_t size = GetSerializedSize(src);
            std::string ret(size, '\0');
            SaveToString(src, ret.data());
            return ret;
        }
    }
}
