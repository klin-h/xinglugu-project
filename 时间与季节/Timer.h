#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer1 {
public:
    // 构造函数，初始化计时器
    Timer1();

    // 获取已过去的天数
    int getDaysElapsed() const;

    // 获取当前季节
    std::string getSeason() const;

    // 更新计时器，检查是否达到新的天数和季节
    void update();


private:
    std::chrono::steady_clock::time_point start_time;  // 系统启动时间
    int days_elapsed;  // 已过去的天数
    std::string season;  // 当前季节
};

#endif // TIMER_H
