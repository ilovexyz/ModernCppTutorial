// if-switch
#include <vector>
#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, double, std::string> f()
{
    return std::make_tuple(1, 3.2, "hello");
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4};
    // c++17: declare local variable in if statement
    if (const std::vector<int>::iterator iter = std::find(v.begin(), v.end(), 2);
        iter != v.end())
    {
        *iter = 4;
    }

    for (auto iter : v)
    {
        std::cout << iter << std::endl;
    }

    // c++17: structured binding
    auto [x, y, z] = f();
    std::cout << x << "," << y << "," << z << std::endl;
    return 0;
}
