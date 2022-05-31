#pragma once
#include <atomic>

// C++11 version of spinlock, see reference from https://rigtorp.se/spinlock/
class SpinLock final
{
private:
    std::atomic_bool m_lock{false};

public:
    void lock()
    {
        for (;;)
        {
            // Optimistically assume the lock is free on the first try
            if (!m_lock.exchange(true, std::memory_order_acquire))
            {
                break;
            }
            while (m_lock.load(std::memory_order_relaxed))
            {
// yield thread if necessary
#if _MSC_VER
                _mm_pause();
#else
                __builtin_ia32_pause();
#endif
            }
        }
    }

    bool try_lock()
    {
        // First do a relaxed load to check if lock is free in order to prevent
        // unnecessary cache misses if someone does while(!try_lock())
        return !m_lock.load(std::memory_order_relaxed) &&
               !m_lock.exchange(true, std::memory_order_acquire);
    }

    void unlock()
    {
        m_lock.store(false, std::memory_order_release);
    }

    SpinLock() = default;
    SpinLock(const SpinLock &rhs) = delete;
    SpinLock(SpinLock &&rhs) = delete;
    SpinLock &operator=(const SpinLock &rhs) = delete;
    SpinLock &operator=(SpinLock &&rhs) = delete;
};
