/****************************************************************
 * Project Name: xinglugu-project
 * File: PlantingStrategy.cpp
 * File Function: 种植策略类实现
 * Author: Refactored with Strategy Pattern
 * Update Date: 2024.12
 * License:
 ****************************************************************/
#include "PlantingStrategy.h"
#include "../背包功能/back.h"
#include "../种植功能/PlantingSystem.h"
#include "../GlobalVariables.h"
#include "cocos2d.h"

USING_NS_CC;

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================

PlantingStrategy::PlantingStrategy() {
}

PlantingStrategy::~PlantingStrategy() {
}

bool PlantingStrategy::canUseTool(const std::string& toolName) const {
    // 种植策略适用于所有种子类型的工具
    return isSeed(toolName);
}

bool PlantingStrategy::isSeed(const std::string& toolName) const {
    // 判断是否为种子（根据项目中的命名规则，种子通常以"seed"结尾）
    // 这里可以根据实际项目的种子命名规则进行调整
    // 当前实现检查是否为已知的种子类型
    if (toolName == "parsnipseed") {
        return true;
    }
    // 可以在这里添加更多种子类型的判断
    // 例如：if (toolName == "cauliflowerseed") return true;
    
    return false;
}

std::string PlantingStrategy::getCropNameFromSeed(const std::string& seedName) const {
    // 根据种子名称获取对应的作物名称
    // 这个映射关系需要根据项目的实际种子命名规则来定义
    if (seedName == "parsnipseed") {
        return "cauliflower"; // 根据原代码，parsnipseed种植的是cauliflower
    }
    // 可以在这里添加更多映射关系
    
    // 默认返回种子名称（去除"seed"后缀）
    if (seedName.length() > 4 && seedName.substr(seedName.length() - 4) == "seed") {
        return seedName.substr(0, seedName.length() - 4);
    }
    return seedName;
}

bool PlantingStrategy::execute(const Vec2& tileCoord, 
                               TMXTiledMap* map, 
                               backPack* pack,
                               const Vec2& clickPosition) {
    if (!map || !pack) {
        CCLOG("PlantingStrategy::execute - Invalid parameters");
        return false;
    }
    
    // 检查当前手持工具是否为种子
    std::string currentTool = pack->handInItemOut();
    if (!canUseTool(currentTool)) {
        CCLOG("PlantingStrategy::execute - Tool '%s' cannot be used for planting", currentTool.c_str());
        return false;
    }
    
    // 检查是否有有效的点击位置
    if (clickPosition == Vec2::ZERO) {
        CCLOG("PlantingStrategy::execute - Invalid click position");
        return false;
    }
    
    // 检查土地状态（需要在farmland图层上有可种植的土地）
    TMXLayer* farmlandLayer = map->getLayer("farmland");
    if (!farmlandLayer) {
        CCLOG("PlantingStrategy::execute - Farmland layer not found!");
        return false;
    }
    
    int gid = farmlandLayer->getTileGIDAt(tileCoord);
    if (gid <= 0) {
        CCLOG("PlantingStrategy::execute - No suitable land at this location for planting.");
        return false;
    }
    
    // 获取作物的名称和参数（根据原代码逻辑）
    std::string cropName = getCropNameFromSeed(currentTool);
    float growthTime = 360.0f; // 默认生长时间（可根据种子类型调整）
    std::string spriteFile = "cauliflower_seed.png"; // 默认精灵文件（可根据种子类型调整）
    
    // 尝试从场景中获取已存在的PlantingSystem，避免重复创建
    PlantingSystem* plantingSystem = nullptr;
    if (g_sharedScene) {
        // 查找场景中是否已存在PlantingSystem
        plantingSystem = dynamic_cast<PlantingSystem*>(g_sharedScene->getChildByTag(999));
        if (!plantingSystem) {
            // 如果不存在，创建新的PlantingSystem
            plantingSystem = PlantingSystem::create();
            if (plantingSystem && plantingSystem->init()) {
                plantingSystem->setTag(999); // 设置标签以便后续查找
                g_sharedScene->addChild(plantingSystem, 4); // 添加植物系统到场景中
                CCLOG("PlantingStrategy::execute - Created new PlantingSystem");
            } else {
                CCLOG("PlantingStrategy::execute - Failed to create PlantingSystem");
                return false;
            }
        } else {
            CCLOG("PlantingStrategy::execute - Reusing existing PlantingSystem");
        }
    } else {
        CCLOG("PlantingStrategy::execute - g_sharedScene is null");
        return false;
    }
    
    // 执行种植操作
    if (plantingSystem) {
        bool success = plantingSystem->plantCrop(cropName, growthTime, spriteFile, clickPosition);
        if (success) {
            CCLOG("PlantingStrategy::execute - Planted crop '%s' at (%d, %d)", 
                  cropName.c_str(),
                  static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
            return true;
        } else {
            CCLOG("PlantingStrategy::execute - Failed to plant crop '%s'", cropName.c_str());
            return false;
        }
    }
    
    return false;
}

