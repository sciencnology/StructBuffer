#pragma once
#include <iostream>
#include <chrono>

/**
 * @brief: 泛型的计时类，生命周期结束时自动统计毫秒级时间差，并调用注册的回调函数
*/
template <typename Callback>
class TimerRaii
{
public:
    TimerRaii(Callback&& callback)
        : start_time_(std::chrono::high_resolution_clock::now()), callback_(callback) {}

    ~TimerRaii()
    {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end_time - start_time_;
        callback_(duration.count());
    }

private:
    std::chrono::high_resolution_clock::time_point start_time_;
    Callback callback_;
};
