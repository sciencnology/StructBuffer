#pragma once

#include <iostream>
#include <format>

#include "base.h"
#include "struct.pb.h"
#include "serializer.hpp"
#include "deserializer.hpp"
#include "utils/timer.hpp"

namespace benchmark
{
    template <typename PBType, typename SBType, uint32_t repeat_times = 20>
    inline void TestAndDisplay(PBType &&pb_obj, SBType &&sb_obj, std::string type_msg)
    {
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

        std::string sb_str;
        {
            TimerRaii timer([type_msg](double milliseconds)
                            { std::cout << std::format("{} of StructBuf serialize timecost {} ms\n", type_msg, milliseconds); });
            for (uint32_t i = 0; i < repeat_times; ++i)
            {
                sb_str.clear();
                sb_str = std::move(structbuf::serializer::SaveToString(sb_obj));
                // structbuf::serializer::SaveToString(sb_obj, sb_str);
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

    inline void CompareBigVectorOfInts()
    {
        proto::BigVectorOfInts pb_obj;
        BigVectorOfInts sb_obj;
        for (uint32_t i = 0; i < 200000; ++i)
        {
            pb_obj.add_int_list(i * 5);
            sb_obj.int_list.emplace_back(i * 5);
        }

        TestAndDisplay(pb_obj, sb_obj, "BigVectorOfInts");
    }

    inline void CompareBigStrings()
    {
        proto::BigStrings pb_obj;
        BigStrings sb_obj;
        std::string tmp;
        for (uint32_t i = 0; i < 2000000; ++i)
        {
            tmp.push_back(char(i));
        }

        for (uint32_t i = 0; i < 2; ++i)
        {
            pb_obj.add_str_list(tmp);
            sb_obj.str_list.emplace_back(tmp);
        }

        TestAndDisplay(pb_obj, sb_obj, "BigStrings");
    }

    inline void CompareGetBagInfoRsp()
    {
        proto::GetBagInfoRsp pb_obj;
        GetBagInfoRsp sb_obj;

        pb_obj.set_retcode(0);
        sb_obj.retcode = 0;

        pb_obj.set_msg("success");
        sb_obj.msg = "success";

        for (int32_t i = 0; i < 50000; ++i)
        {
            proto::Item *pb_item = pb_obj.add_item_list();
            pb_item->set_uuid(10000 + i);
            pb_item->set_cnt(i);
            pb_item->set_ext(5 * i);

            sb_obj.item_list.emplace_back(Item{10000 + i, i, 5 * i});
        }
        TestAndDisplay(pb_obj, sb_obj, "GetBagInfoRsp");

        TestTuple test_tuple;
        std::string ttt = structbuf::serializer::SaveToString(test_tuple);
        structbuf::deserializer::ParseFromSV(test_tuple, ttt);
    }
}