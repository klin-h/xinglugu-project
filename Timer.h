#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer1 {
public:
    // ���캯������ʼ����ʱ��
    Timer1();

    // ��ȡ�ѹ�ȥ������
    int getDaysElapsed() const;

    // ��ȡ��ǰ����
    std::string getSeason() const;

    // ���¼�ʱ��������Ƿ�ﵽ�µ������ͼ���
    void update();


private:
    std::chrono::steady_clock::time_point start_time;  // ϵͳ����ʱ��
    int days_elapsed;  // �ѹ�ȥ������
    std::string season;  // ��ǰ����
};

#endif // TIMER_H