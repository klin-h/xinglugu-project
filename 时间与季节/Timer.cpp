#include "Timer.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

Timer1& Timer1::getInstance() {
    static Timer1 instance;
    return instance;
}

Timer1::Timer1() : days_elapsed(0), season("Spring") {
    // 初始化开始时间为当前时间
    start_time = std::chrono::steady_clock::now();
}

// 获取已过去的天数
int Timer1::getDaysElapsed() const {
    return days_elapsed;
}

// 获取当前季节
std::string Timer1::getSeason() const {
    return season;
}

// 更新计时器：计算已过天数并检查季节更替
void Timer1::update() {
    // 获取当前时间
    auto now = std::chrono::steady_clock::now();
    // 计算已过去的秒数
    std::chrono::duration<double> elapsed_seconds = now - start_time;

    // 计算已过去的天数
    int new_days_elapsed = static_cast<int>(elapsed_seconds.count() / 1440);  // 1440秒 换算成 1天

    // 如果天数发生变化
    if (new_days_elapsed > days_elapsed) {
        days_elapsed = new_days_elapsed;

        // 每经过30天更换季节
        if (days_elapsed >= 30) {
            if (season == "Spring") {
                season = "Summer";
            }
            else if (season == "Summer") {
                season = "Fall";
            }
            else if (season == "Fall") {
                season = "Winter";
            }
            else {
                season = "Spring";  // 如果当前是冬季，重新回到春季
            }

            // 重新开始计时
            start_time = std::chrono::steady_clock::now();
        }
    }
}

