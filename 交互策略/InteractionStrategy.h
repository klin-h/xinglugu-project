/****************************************************************
 * Project Name: xinglugu-project
 * File: InteractionStrategy.h
 * File Function: 交互策略模式接口定义
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#ifndef INTERACTION_STRATEGY_H
#define INTERACTION_STRATEGY_H

#include "cocos2d.h"
#include <string>

class backPack; // 前向声明

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================
// 
// 目的：将角色与对象交互的行为逻辑（挖掘、浇水、种植）从分散的条件判断
// 中提取出来，封装为独立的策略类，提高代码的可扩展性和可维护性
// 
// 交互策略接口：定义了所有交互策略必须实现的方法
// ============================================================

class InteractionStrategy {
public:
    virtual ~InteractionStrategy() {}
    
    // 执行交互操作
    // @param tileCoord 瓦片坐标
    // @param map 地图对象
    // @param pack 背包对象（用于获取当前手持物品）
    // @param clickPosition 点击位置（用于种植时确定作物位置）
    // @return 交互是否成功
    virtual bool execute(const cocos2d::Vec2& tileCoord, 
                        cocos2d::TMXTiledMap* map, 
                        backPack* pack,
                        const cocos2d::Vec2& clickPosition = cocos2d::Vec2::ZERO) = 0;
    
    // 获取策略名称（用于调试和日志）
    virtual std::string getStrategyName() const = 0;
    
    // 检查当前策略是否适用于给定的工具
    // @param toolName 工具名称（如"hoe", "wateringcan", "parsnipseed"等）
    // @return 是否适用
    virtual bool canUseTool(const std::string& toolName) const = 0;
};

#endif // INTERACTION_STRATEGY_H

