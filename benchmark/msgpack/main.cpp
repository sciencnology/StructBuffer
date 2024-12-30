#include "compare.hpp"

int main() {
    benchmark::CompareGetBagInfoRsp();
    benchmark::CompareBigString();
    benchmark::CompareStdContainers();
    return 0;
}
