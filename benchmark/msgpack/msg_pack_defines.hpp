#pragma once
#include <msgpack.hpp>
#include <vector>
#include <string>
#include <tuple>

namespace msg_pack_benchmark
{
    struct BigVectorOfNumerics
    {
        MSGPACK_DEFINE(double_list, int_list);

        std::vector<double> double_list;
        std::vector<int32_t> int_list;
    };

    struct BigString
    {
        MSGPACK_DEFINE(str);

        std::string str;
    };

    struct BigVectorOfStrigs
    {
        MSGPACK_DEFINE(string_list);

        std::vector<int32_t> string_list;
    };

    struct Item
    {
        MSGPACK_DEFINE(uuid, cnt, ext);

        int32_t uuid = 0;
        int32_t cnt = 0;
        int32_t ext = 0;
    };

    struct GetBagInfoRsp
    {
        MSGPACK_DEFINE(retcode, item_list);

        int32_t retcode = 0;
        std::vector<Item> item_list;
    };
}

