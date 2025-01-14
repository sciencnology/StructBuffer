## 背景知识

* [聚合(aggregate)类型](https://en.cppreference.com/w/cpp/language/aggregate_initialization)
* [trivially_copyable](https://en.cppreference.com/w/cpp/types/is_trivially_copyable)
* [结构化绑定](https://en.cppreference.com/w/cpp/language/structured_binding)
* [函数重载决议](https://en.cppreference.com/w/cpp/language/overload_resolution)
* [如何实现一个通用的接收任意参数数量的宏](https://stackoverflow.com/a/1872506)


## 如何遍历自定义结构体成员变量

### step 1. 获取结构体非静态成员变量数量

对于聚合(`aggregate`)类型，可以通过SFINAE和递归继承控制函数重载决议的方式获取结构体非静态成员变量数量，具体操作如下：

1. 首先，我们可以使用初始化列表初始化任何聚合类型变量，如下所示：

```c++
struct Test
{
	int32_t i_member;
	double d_member;
	std::string s_member;
};
Test test {42, 3.14, "structbuffer"};
```

并且注意到在列表初始化过程中可以发生隐式类型转换，因此我们定义一个可以隐式转换到任何类型的类，并尝试用该类去初始化任意一个聚合类型变量：

```c++
struct Any {
  // 类型转换运算符
  template <typename T> operator T();
};

Test test {Any{}, Any{}, Any{}}; // ok
Test test {Any{}, Any{}}; // ok，最后一个字段执行默认初始化
Test test {Any{}, Any{}, Any{}, Any{}} // 编译错误
```

观察上述代码可以得知：对于特定的聚合类，超出字段数量的初始化列表会编译错误，因此可以直接利用SFINAE机制去排除。而对于小于等于字段数量的初始化列表均可以成功编译，因此需要利用函数重载决议进行进一步筛选：

```c++
/**
 * @brief: 递归定义不同继承层级的tag类，用于函数重载决议
*/
template <size_t N> struct tag : tag<N - 1> {};
template <> struct tag<0> {};
```

我们知道，在C++中派生类可以隐式转换为基类。在上述的`tag class`继承链中，如果有一系列重载函数func，其参数类型分别是tag<0>, tag<1>, tag<2>  则调用处传入一个编号较大的tag class（比如tag<64>）会匹配到tag<2>的重载（不同层级的派生类都可以一步一步转换到基类，tag<2>需要执行的转换最少）。

因此只要预先定义若干个对应不同结构体成员数量的内部函数，依赖函数重载决议即可得到正确的字段数量：

```c++
// 这里的decltype内部是个值为0u的逗号表达式。需要T{Any{}, Any{}, Any{}}这个表达式合法才有意义，否则被SFINAE排除
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

// 上面定义了从0到63的size_函数，因此这里传入tag<64>匹配数值最大的合法函数重载
template <typename T> 
constexpr size_t size() { return size_<T>(tag<64>{}); }

cout << size<Test>(); 	// 3
```


### step2： 遍历结构体成员

在C++17中标准库引入了结构化绑定，对于确定字段数量的聚合结构体（或者`array`、`tuple`等）可以直接解包并按顺序对每一个成员变量进行赋值，如下所示：

```c++
int main() {
	Test test {42, 3.14, "structbuffer"};
	auto& [a, b, c] = test;	// 这里的类型推导规则与普通的auto一致
	cout << a;	// 42
	cout << b;	// 3.14
	cout << c;	// "structbuffer"
}
```

(P.S. 当前C++标准只允许确定变量数量的结构化绑定，目前已有提案建议新增可变参数数量（Variadic）的结构化绑定，参考[提案内容](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1061r1.html) 。 如果标准实装，则可以省去step1 的繁琐步骤，直接获取参数包的size即可)

利用step1中获取的字段数量，我们可以轻松写出如下代码遍历结构体：

```c++
/**
 * @brief: f为接收单个参数的可调用对象，对args中的每一个参数调用一次f
*/
template <typename F, typename... Args>
void expand_args(F&& f, Args&&... args) {
    (f(std::forward<Args>(args)), ...);
}

/**
 * @brief: 传入结构体v和可调用对象f，对v的每个成员调用一次f
*/
template <typename T, typename F> 
void constexpr_for(T &v, F&& f) {
  // 省略对size > 4的判断
  if constexpr (size<T>() == 4u) {
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
```


### 扩展：如何遍历非聚合类型

大部分用于数据序列化/反序列化的类型都是聚合类型。对于非聚合类型（具有自定义构造函数、具有非public成员、有虚函数等）需要采用侵入式的方式遍历成员，用法如下：

```c++
struct NonAggregateStruct
{
private:
    int int_member = 0;
    double double_member = 0.0;

public:
    NonAggregateStruct() = default;
    NonAggregateStruct(int i, double d): int_member(i), double_member(d) {}
    bool operator==(const NonAggregateStruct&) const  = default;
    DEFINE_STRUCT_BUFFER_MEMBERS(int_member, double_member);	// 使用宏注册所有需要序列化的成员变量
};
```

上述**​`DEFINE_STRUCT_BUFFER_MEMBERS(int_member, double_member)`​** 宏会展开成如下函数：

```c++
inline static structbuf::flag_classes::DataStructFlag data_struct_flag; // 用于表示该结构体是structbuffer合法结构体的标志
// 定义Get函数，模板参数传入字段序号，返回对应的成员变量的引用
template <size_t N> decltype(auto) Get() 
{ 
if constexpr (0 == N) { return (int_member); } 
if constexpr (1 == N) { return (double_member); } 
if constexpr (1 < N) { return structbuf::flag_classes::MemberEnd{}; } 
} 

template <size_t N> decltype(auto) Get() const 
{ 
if constexpr (0 == N) { return (int_member); } 
if constexpr (1 == N) { return (double_member); } 
if constexpr (1 < N) { return structbuf::flag_classes::MemberEnd{}; } 
}
```

有了上面定义的Get函数，就可以轻松在编译期获取字段数量（从0开始逐渐增大N，判断Get<N>()的返回类型一旦为`structbuf::flag_classes::MemberEnd`这个标志class则说明达到成员数量最大值了）并遍历所有字段了。


## 如何进行序列化和反序列化

为了达到最高的运行时效率，核心优化思路：**提取输入类型的特征调用不同函数，尽量使用memcpy拷贝二进制数据。** 具体实现方式为使用类型萃取提取并匹配序列化的对象类型信息，使用SFINAE针对不同特征的类型完美转发到不同的函数进行处理：

* 数值类型（`is_arithmetic_v`）

  C++中所有的数值类型都是`trivially_copyable`的，因此在不跨平台的情况下可以直接使用memcpy序列化成二进制字节串。
* 字符串类型（`std::string`）

  string本身是复杂类型，但是其底层存储为连续的char数组。通过str.data()获取指向底层数组的指针，结合字符串长度即可memcpy序列化成二进制字节串。
* 列表类型（`std::vector`）

  vector本身也是复杂类型，但是其底层存储为连续的T数组。这里分情况讨论：

  * 如果T本身是trivially_copyable的，则T[]也是trivially_copyable的。只需要使用一个size_t编码总长度，随后直接memcpy将整个T[]拷贝成二进制即可。
  * T本身不是trivially_copyable的，需要遍历vector的每一个元素，对其递归进行编码调用。
* 元组类型（`std::tuple`）

  思路与vector相同。其中遍历tuple可以使用std::apply
* 自定义类型

  思路与vector相同。其中遍历自定义类型采用前文提到的方式

由于序列化的原子类型是数值类型和字符串，其余高级类型均为上述原子类型的组合，因此总可以通过memcpy进行二进制拷贝。特别地，如果一个复杂类型包含任意vector、tuple和自定义类型的递归组合，而其中每个元素的原子类型都不为string（对于数据网络传输和持久化，大部分情况都是这样），则上述规则可以迅速在编译期将其分解为少数几条memcpy语句，极大加快运行速度。