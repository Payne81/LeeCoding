# Language Usability Enhancements

### 常量(const)

1. 使用nullptr: 有些编译器会将 `NULL` 定义为 `((void*)0)`，有些则会直接将其定义为 `0`。nullptr 的类型为 nullptr_t.
2. C++11 提供了 `constexpr` 让用户显式的声明函数或对象构造函数在编译期会成为常量表达式，这个关键字明确的告诉编译器应该去验证 `len_foo` 在编译期就应该是一个常量表达式。

