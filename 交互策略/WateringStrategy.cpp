/****************************************************************
 * Project Name: xinglugu-project
 * File: WateringStrategy.cpp
 * File Function: 浇水策略类实现
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#include "WateringStrategy.h"
#include "../背包功能/back.h"
#include "cocos2d.h"

USING_NS_CC;

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================

WateringStrategy::WateringStrategy() {
}

WateringStrategy::~WateringStrategy() {
}

bool WateringStrategy::canUseTool(const std::string& toolName) const {
    // 浇水策略只适用于水壶(wateringcan)
    return toolName == "wateringcan";
}

bool WateringStrategy::execute(const Vec2& tileCoord, 
                               TMXTiledMap* map, 
                               backPack* pack,
                               const Vec2& clickPosition) {
    if (!map || !pack) {
        CCLOG("WateringStrategy::execute - Invalid parameters");
        return false;
    }
    
    // 检查当前手持工具是否为水壶
    std::string currentTool = pack->handInItemOut();
    if (!canUseTool(currentTool)) {
        CCLOG("WateringStrategy::execute - Tool '%s' cannot be used for watering", currentTool.c_str());
        return false;
    }
    
    // 检查土地状态是否为未浇水状态（farm_land_unwater）
    TMXLayer* farmlandLayer = map->getLayer("farmland");
    if (!farmlandLayer) {
        CCLOG("WateringStrategy::execute - Farmland layer not found!");
        return false;
    }
    
    int gid = farmlandLayer->getTileGIDAt(tileCoord);
    if (gid <= 0) {
        CCLOG("WateringStrategy::execute - No tile at this location in farmland layer.");
        return false;
    }
    
    Value propertiesValue = map->getPropertiesForGID(gid);
    if (propertiesValue.getType() == Value::Type::MAP) {
        ValueMap properties = propertiesValue.asValueMap();
        auto typeIter = properties.find("type");
        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
            std::string type = typeIter->second.asString();
            
            // 只有当土地类型为未浇水状态时才执行浇水操作
            if (type == "farm_land_unwater") {
                bool success = waterLand(tileCoord, map, "landmateri");
                if (success) {
                    CCLOG("WateringStrategy::execute - Land watered at (%d, %d)", 
                          static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
                    return true;
                } else {
                    CCLOG("WateringStrategy::execute - Failed to water land at (%d, %d)", 
                          static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
                    return false;
                }
            } else {
                CCLOG("WateringStrategy::execute - Land type '%s' is not suitable for watering", type.c_str());
                return false;
            }
        }
    }
    
    CCLOG("WateringStrategy::execute - No valid 'type' property found in farmland layer.");
    return false;
}

bool WateringStrategy::waterLand(const Vec2& tileCoord, 
                                 TMXTiledMap* map, 
                                 const std::string& layerName) {
    // 从ScenceTouch.cpp中提取的waterLand逻辑
    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("WateringStrategy::waterLand - Layer 'farmland' not found!");
        return false;
    }
    
    // 获取素材图层
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("WateringStrategy::waterLand - Layer '%s' not found!", layerName.c_str());
        return false;
    }
    
    // 从素材图层中获取 (1, 0) 的 GID（浇水后的土地）
    Vec2 materialTileCoord(1, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("WateringStrategy::waterLand - No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return false;
    }
    
    // 在目标图层中设置新的 GID
    targetLayer->setTileGID(materialGID, tileCoord);
    
    CCLOG("WateringStrategy::waterLand - Watered land at (%d, %d) in 'farmland' layer with tile from '%s' layer at (1, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
    
    return true;
}

