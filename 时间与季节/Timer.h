#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer1 {
public:
    static Timer1& getInstance();

    // 获取已过去的天数
    int getDaysElapsed() const;

    // 获取当前季节
    std::string getSeason() const;

    // 更新计时器，检查是否达到新的天数和季节
    void update();


private:
    Timer1();
    Timer1(const Timer1&) = delete;
    Timer1& operator=(const Timer1&) = delete;

private:
    std::chrono::steady_clock::time_point start_time;  // 系统启动时间
    int days_elapsed;  // 已过去的天数
    std::string season;  // 当前季节
};

#endif // TIMER_H

