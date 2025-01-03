#pragma once
#include "../struct_buffer.hpp"

#include <vector>

namespace struct_rpc_benchmark
{
    struct BigVectorOfNumerics
    {
        std::vector<double> double_list;
        std::vector<int32_t> int_list;
    };

    struct BigString
    {
        std::string str;
    };

    struct BigVectorOfStrigs
    {
        std::vector<int32_t> string_list;
    };

    struct Item
    {
        int32_t uuid = 0;
        int32_t cnt = 0;
        int32_t ext = 0;
    };

    // 模拟游戏开发中拉取玩家背包的数据包
    struct GetBagInfoRsp
    {
        int32_t retcode = 0;
        std::vector<Item> item_list;
    };
}
