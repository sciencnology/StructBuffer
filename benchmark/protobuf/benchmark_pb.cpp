#include "struct.pb.h"
#include <vector>
#include <format>
#include "../../trunk/utils/timer.hpp"
#include "../../trunk/base.h"

// /usr/bin/g++-13 benchmark_pb.cpp struct.pb.cc --std=c++20 -O2 -lprotobuf
int main()
{
    proto::BigVectorOfInts pb_obj;
    std::string pb_str;
    std::vector<int32_t> data_vec;
    for (uint32_t i = 0; i < 1000000; ++i)
    {
        pb_obj.add_int_list(i * 5);
        data_vec.emplace_back(i * 5);
    }

    {
        TimerRaii timer([](double milliseconds)
                        { std::cout << std::format("100w int list serialize timecost {} ms\n", milliseconds); });
        for (int i = 0; i < 20; ++i)
        {
            pb_obj.SerializeToString(&pb_str);
        }
        std::cout << std::format("pb str size {}\n", pb_str.size());
    }

    {
        TimerRaii timer([](double milliseconds)
                        { std::cout << std::format("100w int list serialize timecost {} ms\n", milliseconds); });
        for (int i = 0; i < 20; ++i)
        {
            pb_str.resize(1000000 * sizeof(int32_t));
            std::memcpy(pb_str.data(), data_vec.data(), pb_str.size());
        }
        std::cout << std::format("struct str size {}\n", pb_str.size());
    }

    return 0;
}