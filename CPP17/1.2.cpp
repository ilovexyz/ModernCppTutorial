#include <iostream>

// test for const_cast applied on const and constexpr
int main()
{
    // const volatile int x = 3; // use volatile to stop the compiler optimization
    const int x = 3;
    constexpr int y = 4;
    int * xx = const_cast<int*>(&x);
    *xx = 5;

    int * yy = const_cast<int*>(&y);
    *yy = 7;

    std::cout << &x << " " << xx << "\n"; // same address
    std::cout << "x = " << x << "\n"; // still 3 due to compiler optimization
    std::cout << "y = " << y << "\n"; // still 4 due to compiler optimization
    std::cout << "xx = " << *xx << "\n"; // 5
    std::cout << "yy = " << *yy << "\n"; // 7
    
    return 0;
}