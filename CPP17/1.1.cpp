#include <iostream>
#include <map>
#include <iomanip>

template <typename T>
void linePrinter(const T &x)
{
    if constexpr (std::is_integral_v<T>)   // if constexpr - to discard code at compile-time
        std::cout << "num: " << x << std::endl;
    else if constexpr (std::is_floating_point_v<T>) // _v variable templates for type traits
    {
        const auto frac = x - static_cast<long>(x);
        std::cout << std::setprecision(15) << "flt: " << x << ", frac: " << frac << std::endl;
    }
    else if constexpr (std::is_pointer_v<T>)
    {
        std::cout << "ptr, ";
        linePrinter(*x);
    }
    else
        std::cout << x << std::endl;
}

template<typename ...Args>
void printWithInfo(Args ... args)
{
    (linePrinter(args), ...); // fold expression over the comma operator
}

int main()
{
    std::map<std::string, int> mapUsersAge{{"Alex", 45}, {"John", 25}};
    std::map mapcopy{mapUsersAge}; // C++17 feature: Template Argument Deduction for Class Templates
    // or
    auto mapcopy_1{mapUsersAge};

    if (auto [iter, wasAdded] = mapUsersAge.insert_or_assign("John", 26); !wasAdded) // C++17 feature: new insertion function for map, structured binding, init if statement
        std::cout << iter->first << " reassigned...\n";

    for (const auto &[key, value] : mapcopy) // C++17 feature: structured binding in range-based for loop
        std::cout << key << ": " << value << std::endl;

    int x = 3;
    float y = 4.6;
    double z = 1.45678909897;
    printWithInfo(&x, &y, &z, 3.24);

    // auto deduction
    auto a = {1,3};
    // auto b {1,3}; // wrong
    auto c {1}; // correct
    std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(c).name() << std::endl;

    return 0;
}
