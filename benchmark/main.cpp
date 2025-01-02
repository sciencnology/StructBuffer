#include "compare.hpp"

// g++ ./main.cpp ./protobuf/struct.pb.cc --std=c++20 -I/home/uranus/lwh_dev/msgpack-c-cpp_master/include -I/home/uranus/protobuf/include -lprotobuf -L/home/uranus/protobuf/lib

int main() {
    benchmark::CompareGetBagInfoRsp();
    benchmark::CompareBigString();
    benchmark::CompareStdContainers();
    benchmark::CompareBigVectorOfNumerics();
    return 0;
}
