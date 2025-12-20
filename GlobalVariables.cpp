/****************************************************************
 * Project Name: xinglugu-project
 * File Name: GlobalVariables.cpp
 * File Function: 旧全局变量定义 - 为了向后兼容而保留
 * Author: AI Assistant
 * Update Date: 2024.12.20
 * License:
 ****************************************************************/

#include "GlobalVariables.h"

// 旧全局变量定义 - 为了兼容性保留
// 应该使用 ServiceLocator 代替这些全局变量
cocos2d::Scene* g_sharedScene = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXone = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXtwo = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXthree = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXfour = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXcurrent = nullptr;
int g_time = 0;
std::vector<Animal*> animalGrid;
