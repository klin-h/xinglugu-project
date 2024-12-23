/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.h
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.7
 * License:
 ****************************************************************/
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Constants.h"
#include "cocos2d.h"
#include "Walking.h"
class Player;


// �����ö��
enum class Direction {
    f,
    b,
    l,
    r
};

enum class AnimationState {
    IDLE,
    WALKING,
    RUNNING,
    INTERACTING
};

class Character : public Node
{
public:

    Character()
        : name("DefaultCharacter"),
        health(Constants::OriginHealth),
        animationState(AnimationState::IDLE) {}

    Character(const std::string& name, int health)
        : name(name),
        health(Constants::OriginHealth),
        animationState(AnimationState::IDLE) {}


    //��ɫ�ƶ�
    void Moving(Sprite* sprite, int direction, float t);
    void MovingContenly(Sprite* sprite, int direction, float t);
    //��ɫֹͣ�ƶ�
    void stopMoving(Sprite* sprite);

    //��ɫֹͣһ�ж���
    void stop();

    // ��ȡ��ɫ����
    std::string getName() { return name; }

    // ���ý�ɫ����
    void setName(int newName) { name = newName; }

    // ��ȡ��ɫ����ֵ
    int getHealth() const { return health; }

    // ���ý�ɫ����ֵ
    void setHealth(int newHealth) { health = newHealth; }

    // ��ȡ����״̬
    AnimationState getAnimationState() const { return animationState; }

    // ���ö���״̬
    void setAnimationState(AnimationState newState) { animationState = newState; }


  

    std::string name;
protected:
    
    int health;
    AnimationState animationState;
};

#endif 