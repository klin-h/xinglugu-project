#pragma once
#ifndef CROP_H
#define CROP_H

#include "cocos2d.h"

class Crop : public cocos2d::Node {
public:
    // ����״̬ö��
    enum class State {
        SEED,      // ����
        GROWING,   // �ɳ���
        HARVESTABLE // ���ջ�
    };
    // ���캯��
    Crop(const std::string& cropName, float growthTime, const std::string& spriteFile);

    // ��������
    static Crop* create(const std::string& cropName, float growthTime, const std::string& spriteFile);

    // ��������״̬
    void update(float deltaTime);

    // ��ȡ����״̬
    State getState() const;

    // ��ȡ��������
    const std::string& getName() const;

private:
    std::string name;       // ��������
    float growthTime;       // �ɳ�ʱ�䣨�룩
    float currentTime;      // ��ǰ����ʱ��
    State state;            // ��ǰ״̬

    cocos2d::Sprite* sprite; // ���ﾫ��
};

#endif 