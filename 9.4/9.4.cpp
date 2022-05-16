#include <iostream>
#include <cstddef>

// C++11新关键字：alignof, alignas
struct S
{
    char a;
    int b;
    double c;
    long long d;
};

struct alignas(std::max_align_t) AlignedS
{
    char a;
    int b;
    double c;
    long long d;
};

int main()
{
    std::cout << alignof(S) << ", " << sizeof(S) << ", " << offsetof(AlignedS, d) << std::endl;
    std::cout << alignof(AlignedS) << ", " << sizeof(AlignedS) << ", " << offsetof(AlignedS, d) << std::endl;
    return 0;
}