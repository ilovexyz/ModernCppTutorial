#include <iostream>
#include <vector>
#include <string>

constexpr const char *NL = "\n";

// C++17 fold expressions new feature

template <typename... T>
auto sum(T... args)
{
    return (args + ...);
}

template <typename T, typename... Args>
void push_v(std::vector<T> &v, Args &&...args)
{
    (v.push_back(std::forward<Args>(args)), ...);
}


int main()
{
    std::pair p1{1, "hello"};
    auto [a, b] = p1;
    std::cout << a << NL << b << NL;
    std::cout << sum(1, 2, 3, 4, 5) << NL;
    std::cout << sum(3.1, 2.4, 5.6, 1.6, 5.6) << NL;

    std::vector<float> v;
    push_v(v, 3.4, 1.2, 1.1);

    for (auto &i : v)
    {
        std::cout << i << NL;
    }

    return 0;
}