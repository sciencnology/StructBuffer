#include "compare.hpp"

// /usr/bin/g++-13 main.cpp struct.pb.cc --std=c++20 -O2 -lprotobuf -I../../trunk

int main()
{
    // benchmark::CompareBigVectorOfInts();
    benchmark::CompareBigStrings();
    // benchmark::CompareGetBagInfoRsp();
    return 0;
}