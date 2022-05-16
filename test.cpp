#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

struct A
{
    int x;
    double y;
    char z[5];
};

int main()
{
    A a1 = {1, 3.4, "John"};
    A a2 = {2, 5.4, "Alic"};
    A a3 = {5, 8.4, "Jac"};

    // 删除map元素时，其他元素的地址不变
    std::map<int, A> map_a;
    map_a.insert(std::make_pair(a1.x, a1));
    map_a.insert(std::make_pair(a2.x, a2));
    map_a.insert(std::make_pair(a3.x, a3));

    A *pa3 = &map_a[5];
    std::cout << pa3 << ":" << pa3->z << std::endl;
    map_a.erase(2);
    std::cout << pa3 << ":" << pa3->z << std::endl;
    std::cout << &map_a[5] << ":" << map_a[5].z << std::endl;

    // 删除vector元素，其他元素的地址会发生变化
    std::vector<A> va;
    va.push_back(a1);
    va.push_back(a2);
    va.push_back(a2);
    va.push_back(a3);

    pa3 = &va[2];

    std::cout << pa3 << ":" << pa3->z << ", " << va.size() << std::endl;
    va.erase(std::remove_if(va.begin(), va.end(), [](auto &&item)
                            { return item.x == 2; }),
                            va.end());

    pa3->z[0] = 'K';
    A *pa2 = &va[1];
    std::cout << pa3 << ":" << pa3->z << ", " << va.size() << std::endl;
    std::cout << pa2 << ":" << pa2->z << ", " << va.size() << std::endl;
    return 0;
}