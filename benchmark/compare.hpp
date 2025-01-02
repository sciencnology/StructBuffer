#pragma once

#include <iostream>
#include <format>
#include <random>

#include "struct_rpc_defines.hpp"
#include "msgpack/msg_pack_defines.hpp"
#include "protobuf/struct.pb.h"
#include "../trunk/utils/timer.hpp"

namespace benchmark
{
    template <typename MsgPackType, typename PBType, typename SBType, uint32_t repeat_times = 20>
    inline void TestAndDisplay(MsgPackType &msg_obj, PBType &pb_obj, SBType &sb_obj, std::string type_msg)
    {
        // 序列化和反序列化MsgPack结构体
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

        // 序列化和反序列化ProtoBuf结构体
        std::string pb_str;
        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of ProtoBuf serialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                pb_str.clear();
                pb_obj.SerializeToString(&pb_str);
            }
        }
        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of ProtoBuf deserialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                pb_obj.ParseFromString(pb_str);
            }
        }

        // 序列化和反序列化StructBuffer结构体
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

    inline void CompareBigVectorOfNumerics()
    {
        msg_pack_benchmark::BigVectorOfNumerics msg_obj;
        struct_rpc_benchmark::BigVectorOfNumerics sb_obj;
        proto::BigVectorOfNumerics pb_obj;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> real_dist(1.0, 100000.0);
        for (size_t i = 0; i < 500000; ++i) {
            double elem = real_dist(gen);
            msg_obj.double_list.emplace_back(elem);
            sb_obj.double_list.emplace_back(elem);
            pb_obj.add_double_list(elem);
        }
        std::uniform_int_distribution<> int_dist(1, 10000);
        for (size_t i = 0; i < 500000; ++i) {
            int32_t elem = int_dist(gen);
            msg_obj.int_list.emplace_back(elem);
            sb_obj.int_list.emplace_back(elem);
            pb_obj.add_int_list(elem);
        }

        TestAndDisplay(msg_obj, pb_obj, sb_obj, "BigVectorOfNumerics");
    }

    inline void CompareBigString()
    {
        msg_pack_benchmark::BigString msg_obj;
        struct_rpc_benchmark::BigString sb_obj;
        proto::BigString pb_obj;
        std::string tmp;
        for (uint32_t i = 0; i < 20000000; ++i)
        {
            tmp.push_back(char(i));
        }

        msg_obj.str = tmp;
        sb_obj.str = tmp;
        pb_obj.set_str(tmp);

        TestAndDisplay(msg_obj, pb_obj, sb_obj, "BigStrings");
    }

    inline void CompareGetBagInfoRsp()
    {
        msg_pack_benchmark::GetBagInfoRsp msg_obj;
        struct_rpc_benchmark::GetBagInfoRsp sb_obj;
        proto::GetBagInfoRsp pb_obj;

        msg_obj.retcode = 0;
        sb_obj.retcode = 0;
        pb_obj.set_retcode(0);

        for (int32_t i = 0; i < 50000; ++i)
        {
            msg_obj.item_list.emplace_back(msg_pack_benchmark::Item{10000 + i, i, 5 * i});
            sb_obj.item_list.emplace_back(struct_rpc_benchmark::Item{10000 + i, i, 5 * i});

            proto::Item* item_ptr = pb_obj.add_item_list();
            item_ptr->set_uuid(10000 + i);
            item_ptr->set_cnt(i);
            item_ptr->set_ext(5 * i);
            
        }
        TestAndDisplay(msg_obj, pb_obj, sb_obj, "GetBagInfoRsp");
    }

    inline void CompareStdContainers()
    {
        using TestType = std::vector<std::tuple<int32_t, double, std::string, std::tuple<double, float, uint64_t>>>;
        TestType msg_obj, sb_obj;
        proto::ComplicatedContainer pb_obj;

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
            std::string random_str =  random_string();
            typename TestType::value_type elem {int_dist(gen), real_dist(gen), random_str, {real_dist(gen), real_dist(gen), int_dist(gen)}};
            msg_obj.emplace_back(elem);
            sb_obj.emplace_back(elem);

            auto* member_item = pb_obj.add_mem_list();
            member_item->set_mem1(int_dist(gen));
            member_item->set_mem2(real_dist(gen));
            member_item->set_mem3(random_str);
            auto* inner_ptr = member_item->mutable_mem4();
            inner_ptr->set_mem1(real_dist(gen));
            inner_ptr->set_mem2(real_dist(gen));
            inner_ptr->set_mem3(int_dist(gen));
        }

        TestAndDisplay<TestType, decltype(pb_obj), TestType, 2>(msg_obj, pb_obj, sb_obj, "CompliactedStdContainer");
    }
}