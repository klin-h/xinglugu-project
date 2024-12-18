#include "Timer.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
Timer1::Timer1() : days_elapsed(0), season("Spring") {
    // ��ʼ����ʼʱ��Ϊ��ǰʱ��
    start_time = std::chrono::steady_clock::now();
}

// ��ȡ�ѹ�ȥ������
int Timer1::getDaysElapsed() const {
    return days_elapsed;
}

// ��ȡ��ǰ����
std::string Timer1::getSeason() const {
    return season;
}

// ���¼�ʱ���������ѹ���������鼾�ڸ���
void Timer1::update() {
    // ��ȡ��ǰʱ��
    auto now = std::chrono::steady_clock::now();
    // �����ѹ�ȥ������
    std::chrono::duration<double> elapsed_seconds = now - start_time;

    // �����ѹ�ȥ������
    int new_days_elapsed = static_cast<int>(elapsed_seconds.count() / 1440);  // 1440�� ����� 1��

    // ������������仯
    if (new_days_elapsed > days_elapsed) {
        days_elapsed = new_days_elapsed;

        // ÿ����30���������
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
                season = "Spring";  // �����ǰ�Ƕ��������»ص�����
            }

            // ���¿�ʼ��ʱ
            start_time = std::chrono::steady_clock::now();
        }
    }
}

