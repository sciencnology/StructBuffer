#include "struct_defines.hpp"
#include <cassert>

// g++ example.cpp -g --std=c++2b

/**
 * @brief: 传入任意一个对象，对其进行序列化和反序列化操作，并检查数据是否一致
*/
void TestOneStruct(auto& origin_obj) {
    std::string serialized_str = structbuf::serializer::SaveToString(origin_obj);
    std::decay_t<decltype(origin_obj)> dest_obj;
    structbuf::deserializer::ParseFromSV(dest_obj, serialized_str);
    assert (dest_obj == origin_obj);
}

int main() {
    // 可以直接序列化标准库容器对象
    std::vector<std::string> std_vec {"he", "llo", "wor", "ld"};
    TestOneStruct(std_vec);

    // 序列化自定义类型
    SimpleStruct simple {42, 3.14};
    TestOneStruct(simple);

    ComplicatedStruct complicated {{1,2,3}, {"hello","world"}, {simple,simple,simple}, {1.23,simple,{4.56}}};
    TestOneStruct(complicated);

    TemplatedNestedStruct<int, int> templated {simple, complicated, {8,8}};
    TestOneStruct(templated);

    NonAggregateStruct non_aggregate(1, 2.0);
    TestOneStruct(non_aggregate);
    return 0;
}