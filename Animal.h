/****************************************************************
 * Project Name: xinglugu-project
 * FileAnimal.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include "Constants.h"
#include "cocos2d.h"
#include "WalkingCharacter.h"

class Animal : public cocos2d::Sprite
{
public:
    // ���캯��
    Animal();

    // ������������ȷ�������������������ȷ����
    virtual ~Animal();

    // ι������ķ���
    void feed();

    // �������������麯������Ҫ��������ʵ��
    virtual void produce() = 0;

    // ��ȡ������
    int getHunger() const;

    // ���ü�����
    void setHunger(int value);

    // ��ȡ����
    int getMood() const;

    // ��������
    void setMood(int value);

    // ��ȡѪ��
    int getHealth() const;

    // ����Ѫ��
    void setHealth(int value);

    // ͨ�÷���
    void moveTo(const cocos2d::Vec2& targetPosition);              // �ƶ���ָ��λ��
    void moveToSequence(const std::vector<cocos2d::Vec2>& positions); // �����ƶ������λ��
    virtual void startWalkingAnimation();  // �������߶������麯�������������д��
    virtual void stopWalkingAnimation();   // ֹͣ���߶������麯�������������д��

    //void toggleMovement(); // �л��ƶ�״̬
    //void stopMovement();   // ֹͣ�ƶ�
    //void resumeMovement(); // �ָ��ƶ�

    //void moveRandomly();

  /*  virtual bool init() override;*/

protected:
    int hunger_ = Constants::kDefaultAnimalHunger;    // Ĭ�ϼ�����
    int mood_ = Constants::kDefaultAnimalMood;        // Ĭ������
    int health_ = Constants::kDefaultAnimalHealth;    // Ĭ��Ѫ��
    WalkingCharacter* walkingCharacterNode = nullptr;

    //bool isMoving_;                      // ��ǰ�Ƿ����ƶ�
    //std::vector<cocos2d::Vec2> path_;    // ��ǰ���ƶ�·��
    //size_t currentTargetIndex_;          // ·���еĵ�ǰλ������
};

#endif // ANIMAL_H