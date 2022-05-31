#include "SpinLock.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int main()
{
    int count = 0;
    SpinLock lock;

    constexpr size_t THREAD_NUM = 10;
    constexpr size_t LOOP_NUM = 1000000;

    std::vector<std::thread> ts;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < THREAD_NUM; i++)
    {
        ts.emplace_back(std::move(std::thread([&]{
            for (size_t j = 0; j < LOOP_NUM; j++)
            {
                lock.lock();
                count++;
                lock.unlock();
            }
            
        })));
    }

    for (size_t i = 0; i < THREAD_NUM; i++)
    {
        ts[i].join();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto d = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << count << std::endl;
    std::cout << "Time used: " << d.count() << " ms" << std::endl;
    return 0;
}