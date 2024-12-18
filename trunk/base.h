#pragma once
#include "macros.h"

#include <vector>

struct BigVectorOfInts
{
    DEF_DATA_STUCT;
    DEFINE_GET_FUNC_1(int_list);

    std::vector<int32_t> int_list;
};

struct BigStrings
{
    DEF_DATA_STUCT;
    DEFINE_GET_FUNC_1(str_list);

    std::vector<std::string> str_list;
};

struct BigVectorOfStrigs
{
    DEF_DATA_STUCT;
    DEFINE_GET_FUNC_1(string_list);

    std::vector<int32_t> string_list;
};

struct Item
{
    DEF_DATA_STUCT;
    DEFINE_GET_FUNC_3(uuid, cnt, ext);

    int32_t uuid = 0;
    int32_t cnt = 0;
    int32_t ext = 0;
};

struct GetBagInfoRsp
{
    DEF_DATA_STUCT;
    DEFINE_GET_FUNC_3(retcode, msg, item_list);

    int32_t retcode = 0;
    std::string msg;
    std::vector<Item> item_list;
};