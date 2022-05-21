#pragma once
#include <functional>

// class形式的Finally
class CFinally final
{
private:
    std::function<void()> m_action;  // 缺点：多了一个成员变量，影响性能
public:
    explicit CFinally(std::function<void()> action) : m_action(std::move(action))
    {
    }

    ~CFinally()
    {
        m_action();
    }
};

// function形式的Finally
template <typename Fn>
auto FFinally(Fn action)
{
    class FinallyImp
    {
    public:
        Fn m_action; // 直接引用原始函数对象，没有性能损失
        explicit FinallyImp(Fn action) : m_action(std::move(action))
        {
        }

        ~FinallyImp()
        {
            m_action();
        }
    };
    return FinallyImp(std::move(action));
}

// 使用宏简化调用流程
#define FINALLY FINALLY_internal_1(__LINE__)
#define FINALLY_internal_1(line) FINALLY_internal_2(line)
#define FINALLY_internal_2(line) auto finally_##line = FFinally
