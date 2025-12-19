#ifndef CHARACTER_STATE_H
#define CHARACTER_STATE_H

#include "cocos2d.h"
#include <string>

class Character; // 前向声明

class CharacterState {
public:
    virtual ~CharacterState() {}

    // 进入状态
    virtual void enter(Character* character) = 0;

    // 每帧更新 (AI逻辑、移动更新)
    virtual void execute(Character* character, float dt) = 0;

    // 退出状态
    virtual void exit(Character* character) = 0;

    // 处理输入 (仅玩家控制的角色需要，AI可忽略)
    virtual void handleInput(Character* character, cocos2d::EventKeyboard::KeyCode code) {}
    
    // 获取状态名称
    virtual std::string getStateName() const = 0;
};

#endif // CHARACTER_STATE_H
