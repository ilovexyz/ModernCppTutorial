#include <iostream>
#include <memory>
#include <type_traits>
#include "share.h"

class Test
{
public:
    Test(int, int) {}
};

template <typename Concrete, typename... Ts>
std::unique_ptr<Concrete> constructArgs(Ts &&...params)
{
    if constexpr (std::is_constructible_v<Concrete, Ts...>) // fixed!
        return std::make_unique<Concrete>(std::forward<Ts>(params)...); // if constexpr好处是如果测试不通过，则对应的代码是不会编译的，但这个特性仅限于模板参数
    else
        return nullptr;
}

template <typename T>
void func(T t)
{
    // for if constexpr,  Only expressions that are dependent on the template parameter used in the condition are not instantiated
    // 也就是说非模板参数和代码依旧会编译，如果不满足条件，依旧报错
    if constexpr (std::is_integral_v<T>)
    {
        // static_assert(sizeof(int) == 100); // even if test failed, this line will still compile failed
    }
    else
    {
        std::cout << t << NL;
    }
}

int main()
{
    func(3);

    auto p = constructArgs<Test>(3, 4, 5); // construct failed, line 16 will not instantiated
    std::cout << (p ? 1 : 0) << NL;
    return 0;
}