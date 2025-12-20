/****************************************************************
 * Project Name: xinglugu-project
 * File: WateringStrategy.h
 * File Function: 浇水策略类定义
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#ifndef WATERING_STRATEGY_H
#define WATERING_STRATEGY_H

#include "InteractionStrategy.h"

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================
// 
// 浇水策略：处理使用水壶(wateringcan)进行土地浇水的交互逻辑
// 封装了原来分散在ScenceTouch.cpp中的waterLand相关逻辑
// ============================================================

class WateringStrategy : public InteractionStrategy {
public:
    WateringStrategy();
    virtual ~WateringStrategy();
    
    // 实现接口方法
    virtual bool execute(const cocos2d::Vec2& tileCoord, 
                        cocos2d::TMXTiledMap* map, 
                        backPack* pack,
                        const cocos2d::Vec2& clickPosition = cocos2d::Vec2::ZERO) override;
    
    virtual std::string getStrategyName() const override { return "WateringStrategy"; }
    
    virtual bool canUseTool(const std::string& toolName) const override;

private:
    // 执行土地浇水操作（从ScenceTouch.cpp中提取的逻辑）
    void waterLand(const cocos2d::Vec2& tileCoord, 
                  cocos2d::TMXTiledMap* map, 
                  const std::string& layerName);
};

#endif // WATERING_STRATEGY_H

