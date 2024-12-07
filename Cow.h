/****************************************************************
 * Project Name: xinglugu-project
 * File Cow.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/
#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal
{
public:
    // ���캯��
    Cow();

    // ����������
    virtual ~Cow();

    static Cow* create();
    virtual bool init() override;
    // ʵ�ֲ�������
    virtual void produce() override;

    // ţ�����з���
    void moo();

    //void startWalkingAnimation(); //�������߶���
    //void stopWalkingAnimation();
    //void moveToSequence(const std::vector<cocos2d::Vec2>& positions, float durationPerMove);
    //void moveTo(const cocos2d::Vec2& targetPosition, float duration);//�����ƶ�
    //void moveBy(const cocos2d::Vec2& offset, float duration);
    
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // ����ţ�ķ���
    void heal(int amount);
    bool isWalking_ = false;
};

#endif // COW_H