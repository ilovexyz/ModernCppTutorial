#include <chrono>
#include <mutex>
#include <shared_mutex>
#include <iostream>

std::mutex mx;
std::shared_mutex smx;

constexpr int N = 100'000'000;

int main()
{
    auto t1 = std::chrono::steady_clock::now();
    for (int i = 0; i != N; i++)
    {
        std::unique_lock<std::mutex> l{ mx };
    }
    auto t2 = std::chrono::steady_clock::now();
    for (int i = 0; i != N; i++)
    {
        std::unique_lock<std::shared_mutex> l{ smx };
    }
    auto t3 = std::chrono::steady_clock::now();

    auto d1 = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    auto d2 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);

    std::cout << "mutex " << d1.count() << "s;  shared_mutex " << d2.count() << "s\n";
    std::cout << "mutex " << sizeof(mx) << " bytes;  shared_mutex " << sizeof(smx) << " bytes \n";
}
