# Language Usability Enhancements

### 常量(const)

1. 使用nullptr: 有些编译器会将 `NULL` 定义为 `((void*)0)`，有些则会直接将其定义为 `0`。nullptr 的类型为 nullptr_t.
2. C++11 提供了 `constexpr` 让用户显式的声明函数或对象构造函数在编译期会成为常量表达式。

### 变量及其初始化

1. if/switch变量声明强化: 可以在if/switch中定义临时变量，如:

   ```c++
   if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
       itr != vec.end()) {
       *itr = 4;
   }
   ```

2. 初始化列表

   定义了初始化列表类型initializer_list:

   ```c++
   #include <initializer_list>
   #include <vector>
   class MagicFoo {
   public:
       std::vector<int> vec;
       MagicFoo(std::initializer_list<int> list) {
           for (std::initializer_list<int>::iterator it = list.begin();
                it != list.end(); ++it)
               vec.push_back(*it);
       }
   };
   int main() {
       // after C++11
       MagicFoo magicFoo = {1, 2, 3, 4, 5};
       std::cout << "magicFoo: ";
       for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) std::cout << *it << std::endl;
   }
   ```

3. 结构化绑定

   C++11/14提供了多返回值的功能(std::tuple)。C++17提供了自动的类型推导。

   ```c++
   #include <iostream>
   #include <tuple>
   
   std::tuple<int, double, std::string> f() {
       return std::make_tuple(1, 2.3, "456");
   }
   
   int main() {
       auto [x, y, z] = f();
       std::cout << x << ", " << y << ", " << z << std::endl;
       return 0;
   }
   ```

### 类型推导

1. decltype

   ```c++
   // decltype(表达式)
   if (std::is_same<decltype(x), decltype(z)>::value)
       std::cout << "type z == type x" << std::endl;
   ```

2. auto(编译期解决还是运行时判断？)

3. 尾返回类型推导