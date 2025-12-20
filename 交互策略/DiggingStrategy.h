/****************************************************************
 * Project Name: xinglugu-project
 * File: DiggingStrategy.h
 * File Function: 挖掘/耕种策略类定义
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#ifndef DIGGING_STRATEGY_H
#define DIGGING_STRATEGY_H

#include "InteractionStrategy.h"

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================
// 
// 挖掘策略：处理使用锄头(hoe)进行土地耕种的交互逻辑
// 封装了原来分散在ScenceTouch.cpp中的cultivateLand相关逻辑
// ============================================================

class DiggingStrategy : public InteractionStrategy {
public:
    DiggingStrategy();
    virtual ~DiggingStrategy();
    
    // 实现接口方法
    virtual bool execute(const cocos2d::Vec2& tileCoord, 
                        cocos2d::TMXTiledMap* map, 
                        backPack* pack,
                        const cocos2d::Vec2& clickPosition = cocos2d::Vec2::ZERO) override;
    
    virtual std::string getStrategyName() const override { return "DiggingStrategy"; }
    
    virtual bool canUseTool(const std::string& toolName) const override;

private:
    // 执行土地耕种操作（从ScenceTouch.cpp中提取的逻辑）
    void cultivateLand(const cocos2d::Vec2& tileCoord, 
                      cocos2d::TMXTiledMap* map, 
                      const std::string& layerName);
};

#endif // DIGGING_STRATEGY_H

