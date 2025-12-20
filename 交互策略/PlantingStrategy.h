/****************************************************************
 * Project Name: xinglugu-project
 * File: PlantingStrategy.h
 * File Function: 种植策略类定义
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#ifndef PLANTING_STRATEGY_H
#define PLANTING_STRATEGY_H

#include "InteractionStrategy.h"

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================
// 
// 种植策略：处理使用种子进行作物种植的交互逻辑
// 封装了原来分散在ScenceTouch.cpp中的plantCrop相关逻辑
// ============================================================

class PlantingStrategy : public InteractionStrategy {
public:
    PlantingStrategy();
    virtual ~PlantingStrategy();
    
    // 实现接口方法
    virtual bool execute(const cocos2d::Vec2& tileCoord, 
                        cocos2d::TMXTiledMap* map, 
                        backPack* pack,
                        const cocos2d::Vec2& clickPosition = cocos2d::Vec2::ZERO) override;
    
    virtual std::string getStrategyName() const override { return "PlantingStrategy"; }
    
    virtual bool canUseTool(const std::string& toolName) const override;

private:
    // 判断是否为种子类型的工具
    bool isSeed(const std::string& toolName) const;
    
    // 根据种子名称获取作物名称（例如：parsnipseed -> cauliflower）
    std::string getCropNameFromSeed(const std::string& seedName) const;
};

#endif // PLANTING_STRATEGY_H

