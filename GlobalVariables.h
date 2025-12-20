// ============================================================
// DEPRECATED: 此文件已被 ServiceLocator 模式重构
// 仅为了向后兼容而保留
// 
// 迁移指南：
// g_sharedScene      → ServiceLocator::getInstance().getScene()
// g_sharedTMXone     → ServiceLocator::getInstance().getTMXMap("map1")
// g_sharedTMXtwo     → ServiceLocator::getInstance().getTMXMap("map2")
// g_sharedTMXthree   → ServiceLocator::getInstance().getTMXMap("map3")
// g_sharedTMXfour    → ServiceLocator::getInstance().getTMXMap("map4")
// g_sharedTMXcurrent → ServiceLocator::getInstance().getCurrentTMXMap()
// g_time             → ServiceLocator::getInstance().getGameTime()
// animalGrid         → *ServiceLocator::getInstance().getAnimalGrid()
// ============================================================

#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include "cocos2d.h"
#include "Animal.h"
#include "Constants.h"
#include"PlantingSystem.h"

// 旧全局变量声明 - 保留用于向后兼容
// 新代码应该使用 ServiceLocator
extern cocos2d::Scene* g_sharedScene;
extern cocos2d::TMXTiledMap* g_sharedTMXone;
extern cocos2d::TMXTiledMap* g_sharedTMXtwo;
extern cocos2d::TMXTiledMap* g_sharedTMXthree;
extern cocos2d::TMXTiledMap* g_sharedTMXcurrent;
extern int g_time;
extern cocos2d::TMXTiledMap* g_sharedTMXfour;
extern std::vector<Animal*> animalGrid;

#endif // GLOBALVARIABLES_H
