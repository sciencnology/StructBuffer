#pragma once

#include <iostream>
#include <format>
#include <random>

#include "../struct_rpc_defines.hpp"
#include "msg_pack_defines.hpp"
#include "utils/timer.hpp"

namespace benchmark
{
    template <typename MsgPackType, typename SBType, uint32_t repeat_times = 20>
    inline void TestAndDisplay(MsgPackType &msg_obj, SBType &sb_obj, std::string type_msg)
    {
        std::string msg_pack_str; 
        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of MsgPack serialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                msg_pack_str.clear();
                msgpack::sbuffer buffer;
                msgpack::pack(buffer, msg_obj);
                msg_pack_str = std::string(buffer.data(), buffer.size());
            }
        }

        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of MsgPack deserialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                msgpack::object_handle oh = msgpack::unpack(msg_pack_str.data(), msg_pack_str.size());
                msgpack::object deserialized_object = oh.get();
                deserialized_object.convert(msg_obj);
            }
        }

        std::string sb_str;
        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of StructBuf serialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                sb_str.clear();
                sb_str = structbuf::serializer::SaveToString(sb_obj);
            }
        }

        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of StructBuf deserialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                structbuf::deserializer::ParseFromSV(sb_obj, sb_str);
            }
        }
    }

    inline void CompareBigString()
    {
        msg_pack_benchmark::BigString msg_obj;
        struct_rpc_benchmark::BigString sb_obj;
        std::string tmp;
        for (uint32_t i = 0; i < 20000000; ++i)
        {
            tmp.push_back(char(i));
        }

        for (uint32_t i = 0; i < 2; ++i)
        {
            msg_obj.str = tmp;
            sb_obj.str = tmp;
        }

        TestAndDisplay(msg_obj, sb_obj, "BigStrings");
    }

    inline void CompareGetBagInfoRsp()
    {
        msg_pack_benchmark::GetBagInfoRsp msg_obj;
        struct_rpc_benchmark::GetBagInfoRsp sb_obj;

        msg_obj.retcode = 0;
        sb_obj.retcode = 0;

        for (int32_t i = 0; i < 50000; ++i)
        {
            msg_obj.item_list.emplace_back(msg_pack_benchmark::Item{10000 + i, i, 5 * i});
            sb_obj.item_list.emplace_back(struct_rpc_benchmark::Item{10000 + i, i, 5 * i});
        }
        TestAndDisplay(msg_obj, sb_obj, "GetBagInfoRsp");
    }

    inline void CompareStdContainers()
    {
        using TestType = std::vector<std::tuple<int32_t, double, std::string, std::tuple<double, float, uint64_t>>>;
        TestType msg_obj, sb_obj;

        const std::string charset = "abcdefghijklmnopqrstuvwxyz"
                                 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                 "0123456789";
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> int_dist(1, 10000);
        std::uniform_real_distribution<> real_dist(1.0, 100000.0);
        auto random_string = [&]() {
            std::string ret;
            int length = int_dist(gen);
            for (size_t i = 0; i < length; ++i) {
                ret += charset[int_dist(gen)];
            }
            return ret;
        };

        for (size_t i = 0; i < 10000; ++i) {
            typename TestType::value_type elem {int_dist(gen), real_dist(gen), random_string(), {real_dist(gen), real_dist(gen), int_dist(gen)}};
            msg_obj.emplace_back(elem);
            sb_obj.emplace_back(elem);
        }

        TestAndDisplay<TestType, TestType, 2>(msg_obj, sb_obj, "CompliactedStdContainer");
    }
}