// constexpr
#include <iostream>

constexpr int fibonacci(const int n)
{
    if (n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    std::cout << fibonacci(10) << std::endl;
    return 0;
}
