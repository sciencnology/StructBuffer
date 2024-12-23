#include <any>
#include <iostream>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>
#include <format>

namespace trait_utils
{
    template <typename T>
    concept is_vector_v = std::is_same_v<std::remove_cv_t<T>, std::vector<typename std::remove_reference_t<T>::value_type>>;

};

template <typename T>
    requires std::is_arithmetic_v<T>
size_t Test(const T &src)
{
    return sizeof(T);
}

template <typename T>
    requires std::is_same_v<T, std::string>
size_t Test(const T &src)
{
    return src.size();
}

template <typename T>
    requires trait_utils::is_vector_v<T>
size_t Test(const T &src)
{
    size_t ret = 0;
    for (const auto &elem : src)
    {
        ret += Test(elem);
    }
    return ret;
}

int main()
{
    using namespace std;
    vector<vector<vector<double>>> tmp_vec{{{}, {{}}}};
    std::cout << std::format("{}\n", Test(tmp_vec));
}
