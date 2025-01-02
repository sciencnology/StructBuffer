#pragma once
#include "../struct_buffer.hpp"

#include <vector>

namespace struct_rpc_benchmark
{
    struct BigVectorOfNumerics
    {
        DEFINE_STRUCT_BUFFER_MEMBERS(double_list, int_list);

        std::vector<double> double_list;
        std::vector<int32_t> int_list;
    };

    struct BigString
    {
        DEFINE_STRUCT_BUFFER_MEMBERS(str);

        std::string str;
    };

    struct BigVectorOfStrigs
    {
        DEFINE_STRUCT_BUFFER_MEMBERS(string_list);

        std::vector<int32_t> string_list;
    };

    struct Item
    {
        DEFINE_STRUCT_BUFFER_MEMBERS(uuid, cnt, ext);

        int32_t uuid = 0;
        int32_t cnt = 0;
        int32_t ext = 0;
    };

    // 模拟游戏开发中拉取玩家背包的数据包
    struct GetBagInfoRsp
    {
        DEFINE_STRUCT_BUFFER_MEMBERS(retcode, item_list);

        int32_t retcode = 0;
        std::vector<Item> item_list;
    };
}
