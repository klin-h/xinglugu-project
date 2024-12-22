#pragma once
#ifndef CROP_H
#define CROP_H

#include "cocos2d.h"

class Crop : public cocos2d::Node {
public:
    // 作物状态枚举
    enum class State {
        SEED,      // 种子
        GROWING,   // 成长中
        HARVESTABLE // 可收获
    };
    // 构造函数
    Crop(const std::string& cropName, float growthTime, const std::string& spriteFile);


    // 创建作物
    static Crop* create(const std::string& cropName, float growthTime, const std::string& spriteFile);

    // 更新作物状态
    void update(float deltaTime);

    // 获取作物状态
    State getState() const;

    // 获取作物名称
    const std::string& getName() const;

    //获取精灵
    cocos2d::Sprite* getSprite() const;

    // 添加更换纹理的方法
    void changeSpriteTexture(const std::string& newSpriteFile);
    // 添加触摸检测的方法
    bool isTouched(const cocos2d::Vec2& touchPosition) const;
private:
    std::string name;       // 作物名称
    float growthTime;       // 成长时间（秒）
    float currentTime;      // 当前生长时间
    State state;            // 当前状态

    cocos2d::Sprite* sprite; // 作物精灵
};

#endif 
