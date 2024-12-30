#include "struct_defines.hpp"
#include <cassert>

// g++ example.cpp -g --std=c++2b

void TestOneStruct(auto& origin_obj) {
    std::string serialized_str = structbuf::serializer::SaveToString(origin_obj);
    std::decay_t<decltype(origin_obj)> dest_obj;
    structbuf::deserializer::ParseFromSV(dest_obj, serialized_str);
    assert (dest_obj == origin_obj);
}

int main() {
    SimpleStruct simple {42, 3.14};
    TestOneStruct(simple);

    StringsStruct strings {"this is a string", "this is another string"};
    TestOneStruct(strings);

    VectorStruct vectors {{1,2,3,114514}, {simple,simple,simple,simple}};
    TestOneStruct(vectors);

    NestedStruct nested {simple, strings, vectors};
    TestOneStruct(nested);

    TemplatedCommonStruct<int, double, std::tuple<float, std::string>, NestedStruct> templated {{42, 1.198, {0.10, "teststring"}, nested}};
    TestOneStruct(templated);
}