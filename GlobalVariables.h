#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include "cocos2d.h"
#include "Animal.h"
#include "Constants.h"
#include"PlantingSystem.h"

extern cocos2d::Scene* g_sharedScene; // 声明一个全局场景指针
extern cocos2d::TMXTiledMap* g_sharedTMXone;
extern cocos2d::TMXTiledMap* g_sharedTMXtwo;
extern cocos2d::TMXTiledMap* g_sharedTMXthree;
extern cocos2d::TMXTiledMap* g_sharedTMXcurrent;
extern int g_time;
extern cocos2d::TMXTiledMap* g_sharedTMXfour;
extern std::vector<Animal*> animalGrid;
//extern std::shared_ptr<PlantingSystem> plantingSystem;

#endif // GLOBALVARIABLES_H
