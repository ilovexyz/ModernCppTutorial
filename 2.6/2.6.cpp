// fold-expression in c++17
#include <iostream>

template <typename... T>
auto func(T... t)
{
    return (t + ...) / sizeof...(t);
}

int main()
{
    std::cout << func(1, 2, 3, 4.0) << std::endl;
    return 0;
}

// g++ -o 2.6.exe .\2.6.cpp -std=c++17
