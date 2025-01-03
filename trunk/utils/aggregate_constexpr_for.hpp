#pragma once
#include <utility>
#include <cstddef>

namespace structbuf
{
namespace aggregate_utils
{
/**
 * @brief: 定义一个能够隐式转换为任何类型的Any类
*/
struct Any {
  template <typename T> operator T();
};

/**
 * @brief: 递归定义不同继承层级的tag类，用于函数重载决议
*/
template <size_t N> struct tag : tag<N - 1> {};
template <> struct tag<0> {};

/**
 * 以下64个size_函数通过SFINAE尝试对某个aggregate的类型T进行构造，并返回能构造的最大成员数量即T的非静态数据成员数量
*/
template <typename T>
constexpr auto size_(tag<64>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 64u;
}
template <typename T>
constexpr auto size_(tag<63>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 63u;
}
template <typename T>
constexpr auto size_(tag<62>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 62u;
}
template <typename T>
constexpr auto size_(tag<61>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 61u;
}
template <typename T>
constexpr auto size_(tag<60>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 60u;
}
template <typename T>
constexpr auto size_(tag<59>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 59u;
}
template <typename T>
constexpr auto size_(tag<58>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 58u;
}
template <typename T>
constexpr auto size_(tag<57>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 57u;
}
template <typename T>
constexpr auto size_(tag<56>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 56u;
}
template <typename T>
constexpr auto size_(tag<55>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 55u;
}
template <typename T>
constexpr auto size_(tag<54>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 54u;
}
template <typename T>
constexpr auto size_(tag<53>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 53u;
}
template <typename T>
constexpr auto size_(tag<52>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 52u;
}
template <typename T>
constexpr auto size_(tag<51>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 51u;
}
template <typename T>
constexpr auto size_(tag<50>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 50u;
}
template <typename T>
constexpr auto size_(tag<49>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 49u;
}
template <typename T>
constexpr auto size_(tag<48>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 48u;
}
template <typename T>
constexpr auto size_(tag<47>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 47u;
}
template <typename T>
constexpr auto size_(tag<46>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 46u;
}
template <typename T>
constexpr auto size_(tag<45>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 45u;
}
template <typename T>
constexpr auto size_(tag<44>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 44u;
}
template <typename T>
constexpr auto size_(tag<43>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 43u;
}
template <typename T>
constexpr auto size_(tag<42>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 42u;
}
template <typename T>
constexpr auto size_(tag<41>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 41u;
}
template <typename T>
constexpr auto size_(tag<40>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 40u;
}
template <typename T>
constexpr auto size_(tag<39>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 39u;
}
template <typename T>
constexpr auto size_(tag<38>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 38u;
}
template <typename T>
constexpr auto size_(tag<37>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 37u;
}
template <typename T>
constexpr auto size_(tag<36>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 36u;
}
template <typename T>
constexpr auto size_(tag<35>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 35u;
}
template <typename T>
constexpr auto size_(tag<34>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 34u;
}
template <typename T>
constexpr auto size_(tag<33>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 33u;
}
template <typename T>
constexpr auto size_(tag<32>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 32u;
}
template <typename T>
constexpr auto size_(tag<31>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 31u;
}
template <typename T>
constexpr auto size_(tag<30>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 30u;
}
template <typename T>
constexpr auto size_(tag<29>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 29u;
}
template <typename T>
constexpr auto size_(tag<28>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 28u;
}
template <typename T>
constexpr auto size_(tag<27>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 27u;
}
template <typename T>
constexpr auto size_(tag<26>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 26u;
}
template <typename T>
constexpr auto size_(tag<25>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 25u;
}
template <typename T>
constexpr auto size_(tag<24>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 24u;
}
template <typename T>
constexpr auto size_(tag<23>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 23u;
}
template <typename T>
constexpr auto size_(tag<22>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 22u;
}
template <typename T>
constexpr auto size_(tag<21>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 21u;
}
template <typename T>
constexpr auto size_(tag<20>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 20u;
}
template <typename T>
constexpr auto size_(tag<19>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 19u;
}
template <typename T>
constexpr auto size_(tag<18>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 18u;
}
template <typename T>
constexpr auto size_(tag<17>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 17u;
}
template <typename T>
constexpr auto size_(tag<16>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 16u;
}
template <typename T>
constexpr auto size_(tag<15>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 15u;
}
template <typename T>
constexpr auto size_(tag<14>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 14u;
}
template <typename T>
constexpr auto size_(tag<13>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 13u;
}
template <typename T>
constexpr auto size_(tag<12>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 12u;
}
template <typename T>
constexpr auto size_(tag<11>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 11u;
}
template <typename T>
constexpr auto size_(tag<10>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 10u;
}
template <typename T>
constexpr auto size_(tag<9>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 9u;
}
template <typename T>
constexpr auto size_(tag<8>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 8u;
}
template <typename T>
constexpr auto size_(tag<7>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 7u;
}
template <typename T>
constexpr auto size_(tag<6>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 6u;
}
template <typename T>
constexpr auto size_(tag<5>) -> decltype(T{Any{}, Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 5u;
}
template <typename T>
constexpr auto size_(tag<4>) -> decltype(T{Any{}, Any{}, Any{}, Any{}}, 0u) {
  return 4u;
}
template <typename T>
constexpr auto size_(tag<3>) -> decltype(T{Any{}, Any{}, Any{}}, 0u) {
  return 3u;
}
template <typename T>
constexpr auto size_(tag<2>) -> decltype(T{Any{}, Any{}}, 0u) {
  return 2u;
}
template <typename T> 
constexpr auto size_(tag<1>) -> decltype(T{Any{}}, 0u) {
  return 1u;
}
template <typename T> 
constexpr auto size_(tag<0>) -> decltype(T{}, 0u) {
  return 0u;
}

template <typename T> 
constexpr size_t size() { return size_<T>(tag<64>{}); }

/**
 * @brief: 对args中的每一个参数调用一次f
*/
template <typename F, typename... Args>
void expand_args(F&& f, Args&&... args) {
    (f(std::forward<Args>(args)), ...);
}

/**
 * @brief: 首先调用size<T>()得到T的成员变量数量，随后用对应数量的结构化绑定拿到每个成员变量的引用，并使用expand_args将其展开给函数f
*/
template <typename T, typename F> 
void constexpr_for(T &v, F&& f) {
  if constexpr (size<T>() == 64u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64);
  }   if constexpr (size<T>() == 63u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63);
  }   if constexpr (size<T>() == 62u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62);
  }   if constexpr (size<T>() == 61u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61);
  }   if constexpr (size<T>() == 60u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60);
  }   if constexpr (size<T>() == 59u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59);
  }   if constexpr (size<T>() == 58u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58);
  }   if constexpr (size<T>() == 57u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57);
  }   if constexpr (size<T>() == 56u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56);
  }   if constexpr (size<T>() == 55u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55);
  }   if constexpr (size<T>() == 54u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54);
  }   if constexpr (size<T>() == 53u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53);
  }   if constexpr (size<T>() == 52u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52);
  }   if constexpr (size<T>() == 51u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51);
  }   if constexpr (size<T>() == 50u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50);
  }   if constexpr (size<T>() == 49u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49);
  }   if constexpr (size<T>() == 48u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48);
  }   if constexpr (size<T>() == 47u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47);
  }   if constexpr (size<T>() == 46u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46);
  }   if constexpr (size<T>() == 45u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45);
  }   if constexpr (size<T>() == 44u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44);
  }   if constexpr (size<T>() == 43u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43);
  }   if constexpr (size<T>() == 42u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42);
  }   if constexpr (size<T>() == 41u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41);
  }   if constexpr (size<T>() == 40u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40);
  }   if constexpr (size<T>() == 39u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39);
  }   if constexpr (size<T>() == 38u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38);
  }   if constexpr (size<T>() == 37u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37);
  }   if constexpr (size<T>() == 36u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36);
  }   if constexpr (size<T>() == 35u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35);
  }   if constexpr (size<T>() == 34u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34);
  }   if constexpr (size<T>() == 33u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33);
  }   if constexpr (size<T>() == 32u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32);
  }   if constexpr (size<T>() == 31u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31);
  }   if constexpr (size<T>() == 30u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30);
  }   if constexpr (size<T>() == 29u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29);
  }   if constexpr (size<T>() == 28u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28);
  }   if constexpr (size<T>() == 27u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27);
  }   if constexpr (size<T>() == 26u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26);
  }   if constexpr (size<T>() == 25u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25);
  }   if constexpr (size<T>() == 24u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24);
  }   if constexpr (size<T>() == 23u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23);
  }   if constexpr (size<T>() == 22u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22);
  }   if constexpr (size<T>() == 21u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21);
  }   if constexpr (size<T>() == 20u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20);
  }   if constexpr (size<T>() == 19u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19);
  }   if constexpr (size<T>() == 18u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18);
  }   if constexpr (size<T>() == 17u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17);
  }   if constexpr (size<T>() == 16u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16);
  }   if constexpr (size<T>() == 15u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15);
  }   if constexpr (size<T>() == 14u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14);
  }   if constexpr (size<T>() == 13u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13);
  }   if constexpr (size<T>() == 12u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12);
  }   if constexpr (size<T>() == 11u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11);
  }   if constexpr (size<T>() == 10u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9, _10] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10);
  }   if constexpr (size<T>() == 9u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8, _9] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8, _9);
  }   if constexpr (size<T>() == 8u) {
    auto &[_1, _2, _3, _4, _5, _6, _7, _8] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7, _8);
  }   if constexpr (size<T>() == 7u) {
    auto &[_1, _2, _3, _4, _5, _6, _7] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6, _7);
  }   if constexpr (size<T>() == 6u) {
    auto &[_1, _2, _3, _4, _5, _6] = v;
    expand_args(f, _1, _2, _3, _4, _5, _6);
  }   if constexpr (size<T>() == 5u) {
    auto &[_1, _2, _3, _4, _5] = v;
    expand_args(f, _1, _2, _3, _4, _5);
  }   if constexpr (size<T>() == 4u) {
    auto &[_1, _2, _3, _4] = v;
    expand_args(f, _1, _2, _3, _4);
  }   if constexpr (size<T>() == 3u) {
    auto &[_1, _2, _3] = v;
    expand_args(f, _1, _2, _3);
  }   if constexpr (size<T>() == 2u) {
    auto &[_1, _2] = v;
    expand_args(f, _1, _2);
  }   if constexpr (size<T>() == 1u) {
    auto &[_1] = v;
    expand_args(f, _1);
  }
}
}
}

