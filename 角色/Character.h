/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.h
 * File Function: Refactored Character class with State Pattern
 * Author:Gao wenhao (Refactored by Copilot)
 * Update Date:2024.12.7
 * License:
 ****************************************************************/
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Constants.h"
#include "cocos2d.h"
#include "Walking.h"
#include "CharacterState.h" // 引入状态接口

class Player;

// 方向的枚举
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

class Character : public cocos2d::Node
{
public:

    Character();
    Character(const std::string& name, int health);
    virtual ~Character(); // 虚析构函数

    // --- 状态模式核心方法 ---
    void changeState(CharacterState* newState);
    CharacterState* getCurrentState() const { return m_currentState; }
    
    // 重写 Node 的 update 方法，委托给状态处理
    virtual void update(float dt) override;
    
    // 处理按键输入，委托给状态处理
    virtual void onKeyPressed(cocos2d::EventKeyboard::KeyCode code);
    // -----------------------

    //角色移动
    void Moving(cocos2d::Sprite* sprite, int direction, float t);
    void MovingContenly(cocos2d::Sprite* sprite, int direction, float t);
    //角色停止移动
    void stopMoving(cocos2d::Sprite* sprite);

    //角色停止一切动作
    void stop();

    // 获取角色名称
    std::string getName() { return name; }

    // 设置角色名称
    void setName(std::string newName) { name = newName; } // Fixed int to string based on usage

    // 获取角色生命值
    int getHealth() const { return health; }

    // 设置角色生命值
    void setHealth(int newHealth) { health = newHealth; }

    // 获取动画状态
    AnimationState getAnimationState() const { return animationState; }

    // 设置动画状态
    void setAnimationState(AnimationState newState) { animationState = newState; }

    std::string name;

protected:
    CharacterState* m_currentState; // 当前状态指针
    
    int health;
    AnimationState animationState;
};

#endif
