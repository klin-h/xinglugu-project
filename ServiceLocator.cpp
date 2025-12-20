/****************************************************************
 * Project Name: xinglugu-project
 * File Name: ServiceLocator.cpp
 * File Function: Service Locator Pattern 实现
 * Author: AI Assistant
 * Update Date: 2024.12.20
 * License:
 ****************************************************************/

#include "ServiceLocator.h"

USING_NS_CC;

// 单例实例获取
ServiceLocator& ServiceLocator::getInstance() {
    static ServiceLocator instance;
    return instance;
}

// 构造函数
ServiceLocator::ServiceLocator()
    : m_scene(nullptr),
      m_backpack(nullptr),
      m_animalGrid(nullptr),
      m_gameTime(0),
      m_currentMapName("") {
    CCLOG("ServiceLocator: Initialized");
}

// 析构函数
ServiceLocator::~ServiceLocator() {
    CCLOG("ServiceLocator: Destroyed");
}

// ========== Scene 服务实现 ==========

void ServiceLocator::registerScene(cocos2d::Scene* scene) {
    if (scene == nullptr) {
        CCLOG("Warning: Attempting to register a null scene");
        return;
    }
    m_scene = scene;
    CCLOG("ServiceLocator: Scene registered");
}

cocos2d::Scene* ServiceLocator::getScene() {
    if (m_scene == nullptr) {
        CCLOG("Warning: Scene not registered");
    }
    return m_scene;
}

// ========== TMXMap 服务实现 ==========

void ServiceLocator::registerTMXMap(const std::string& name, cocos2d::TMXTiledMap* map) {
    if (map == nullptr) {
        CCLOG("Warning: Attempting to register null map '%s'", name.c_str());
        return;
    }
    m_tmxMaps[name] = map;
    CCLOG("ServiceLocator: Map '%s' registered", name.c_str());
    
    // 如果这是第一个地图，设置为当前地图
    if (m_currentMapName.empty()) {
        m_currentMapName = name;
        CCLOG("ServiceLocator: Map '%s' set as current", name.c_str());
    }
}

cocos2d::TMXTiledMap* ServiceLocator::getTMXMap(const std::string& name) {
    auto it = m_tmxMaps.find(name);
    if (it == m_tmxMaps.end()) {
        CCLOG("Warning: Map '%s' not found in registry", name.c_str());
        return nullptr;
    }
    return it->second;
}

cocos2d::TMXTiledMap* ServiceLocator::getCurrentTMXMap() {
    if (m_currentMapName.empty()) {
        CCLOG("Warning: No current map set");
        return nullptr;
    }
    return getTMXMap(m_currentMapName);
}

void ServiceLocator::setCurrentTMXMap(const std::string& name) {
    auto map = getTMXMap(name);
    if (map == nullptr) {
        CCLOG("Warning: Cannot set current map to '%s' - map not found", name.c_str());
        return;
    }
    m_currentMapName = name;
    CCLOG("ServiceLocator: Current map switched to '%s'", name.c_str());
}

std::string ServiceLocator::getCurrentMapName() const {
    return m_currentMapName;
}

// ========== Backpack 服务实现 ==========

void ServiceLocator::registerBackpack(backPack* pack) {
    if (pack == nullptr) {
        CCLOG("Warning: Attempting to register a null backpack");
        return;
    }
    m_backpack = pack;
    CCLOG("ServiceLocator: Backpack registered");
}

backPack* ServiceLocator::getBackpack() {
    if (m_backpack == nullptr) {
        CCLOG("Warning: Backpack not registered");
    }
    return m_backpack;
}

// ========== AnimalGrid 服务实现 ==========

void ServiceLocator::registerAnimalGrid(std::vector<Animal*>* grid) {
    if (grid == nullptr) {
        CCLOG("Warning: Attempting to register a null animal grid");
        return;
    }
    m_animalGrid = grid;
    CCLOG("ServiceLocator: Animal grid registered");
}

std::vector<Animal*>* ServiceLocator::getAnimalGrid() {
    if (m_animalGrid == nullptr) {
        CCLOG("Warning: Animal grid not registered");
    }
    return m_animalGrid;
}

// ========== GameTime 服务实现 ==========

void ServiceLocator::setGameTime(int time) {
    m_gameTime = time;
    // 不频繁打印日志，避免刷屏
}

int ServiceLocator::getGameTime() const {
    return m_gameTime;
}

// ========== 服务管理 ==========

void ServiceLocator::clear() {
    m_scene = nullptr;
    m_tmxMaps.clear();
    m_currentMapName.clear();
    m_backpack = nullptr;
    m_animalGrid = nullptr;
    m_gameTime = 0;
    CCLOG("ServiceLocator: All services cleared");
}
