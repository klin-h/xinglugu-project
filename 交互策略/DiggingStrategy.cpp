/****************************************************************
 * Project Name: xinglugu-project
 * File: DiggingStrategy.cpp
 * File Function: 挖掘/耕种策略类实现
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#include "DiggingStrategy.h"
#include "../背包功能/back.h"
#include "cocos2d.h"

USING_NS_CC;

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================

DiggingStrategy::DiggingStrategy() {
}

DiggingStrategy::~DiggingStrategy() {
}

bool DiggingStrategy::canUseTool(const std::string& toolName) const {
    // 挖掘策略只适用于锄头(hoe)
    return toolName == "hoe";
}

bool DiggingStrategy::execute(const Vec2& tileCoord, 
                              TMXTiledMap* map, 
                              backPack* pack,
                              const Vec2& clickPosition) {
    if (!map || !pack) {
        CCLOG("DiggingStrategy::execute - Invalid parameters");
        return false;
    }
    
    // 检查当前手持工具是否为锄头
    std::string currentTool = pack->handInItemOut();
    if (!canUseTool(currentTool)) {
        CCLOG("DiggingStrategy::execute - Tool '%s' cannot be used for digging", currentTool.c_str());
        return false;
    }
    
    // 执行土地耕种操作
    cultivateLand(tileCoord, map, "landmateri");
    CCLOG("DiggingStrategy::execute - Land cultivated at (%d, %d)", 
          static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    
    return true;
}

void DiggingStrategy::cultivateLand(const Vec2& tileCoord, 
                                    TMXTiledMap* map, 
                                    const std::string& layerName) {
    // 从ScenceTouch.cpp中提取的cultivateLand逻辑
    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("DiggingStrategy::cultivateLand - Layer 'farmland' not found!");
        return;
    }
    
    // 获取素材图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("DiggingStrategy::cultivateLand - Layer '%s' not found!", layerName.c_str());
        return;
    }
    
    // 从素材图层中获取 (0, 0) 的 GID
    Vec2 materialTileCoord(0, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("DiggingStrategy::cultivateLand - No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }
    
    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);
    
    CCLOG("DiggingStrategy::cultivateLand - Cultivated land at (%d, %d) in 'farmland' layer with tile from '%s' layer at (0, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
}

