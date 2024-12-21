#ifndef __WHEEL_GAME_H__
#define __WHEEL_GAME_H__

#include "cocos2d.h"
#include <random>
class WheelGame : public cocos2d::Node {
public:
    // ����ת����Ϸ��ʵ��
    static WheelGame* create();

    // ��ʼ��ת�����
    virtual bool init() override;

    // ����ť����¼�
    void onSpinButtonClicked(cocos2d::Ref* sender);

    // ����ת��
    void spinWheel();

    // ����ת��״̬
    void updateWheel(float dt);

private:
    cocos2d::Sprite* wheel;          // ת�̾���
    cocos2d::MenuItemImage* spinButton; // ��ת��ť
    bool isSpinning;                 // �Ƿ�������ת
    float rotationSpeed;             // ��ת�ٶ�
    float totalRotation;             // ����ת�Ƕ�
    std::mt19937 randomEngine; // ���������
    std::uniform_int_distribution<> distribution; // ���ȷֲ�
};

#endif // __WHEEL_GAME_H__
