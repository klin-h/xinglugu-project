#ifndef __WHEEL_GAME_H__
#define __WHEEL_GAME_H__

#include "cocos2d.h"
#include <random>
class WheelGame : public cocos2d::Node {
public:
    // 创建转盘游戏的实例
    static WheelGame* create();

    // 初始化转盘玩家
    virtual bool init() override;

    // 处理按钮点击事件
    void onSpinButtonClicked(cocos2d::Ref* sender);

    // 启动转盘
    void spinWheel();

    // 更新转盘状态
    void updateWheel(float dt);

private:
    cocos2d::Sprite* wheel;          // 转盘精灵
    cocos2d::MenuItemImage* spinButton; // 旋转按钮
    bool isSpinning;                 // 是否正在旋转
    float rotationSpeed;             // 旋转速度
    float totalRotation;             // 总旋转角度
    std::mt19937 randomEngine; // 随机数引擎
    std::uniform_int_distribution<> distribution; // 均匀分布
};

#endif // __WHEEL_GAME_H__
