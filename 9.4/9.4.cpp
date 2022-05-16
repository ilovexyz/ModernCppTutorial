#include <iostream>
#include <cstddef>

// C++11新关键字：alignof, alignas
struct A
{
    char a;
    short b;
    int c;
};

struct alignas(std::max_align_t) AlignedA
{
    char a;
    short b;
    int c;
};


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
    std::cout << alignof(A) << ", " << sizeof(A) << ", " << offsetof(A, c) << std::endl;  // 4, 8, 4
    std::cout << alignof(AlignedA) << ", " << sizeof(AlignedA) << ", " << offsetof(AlignedA, c) << std::endl; // 16, 16, 4

    std::cout << alignof(S) << ", " << sizeof(S) << ", " << offsetof(S, d) << std::endl; // 8, 24, 16
    std::cout << alignof(AlignedS) << ", " << sizeof(AlignedS) << ", " << offsetof(AlignedS, d) << std::endl; // 16, 32, 16
    return 0;
}