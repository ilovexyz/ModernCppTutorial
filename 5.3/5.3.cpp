#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> a = std::make_unique<int>(3);
    // std::unique_ptr<int> b = a; // wrong, unique ptr can not be copyed
    std::unique_ptr<int> c = std::move(a); // move copyed
    std::unique_ptr<int> d(std::move(c)); // move constructed
    if (!a)
    {
        std::cout << "a is empty" << std::endl;
    }
    if (!c)
    {
        std::cout << "c is empty" << std::endl;
    }
    if (d)
    {
        std::cout << "d is not empty: " <<  *d << std::endl;
    }
    return 0;
}