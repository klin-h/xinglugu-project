/****************************************************************
 * Project Name: xinglugu-project
 * File Name: ServiceLocator.h
 * File Function: Service Locator Pattern - 集中管理全局服务
 * Author: AI Assistant
 * Update Date: 2024.12.20
 * License:
 ****************************************************************/

#ifndef SERVICE_LOCATOR_H
#define SERVICE_LOCATOR_H

#include "cocos2d.h"
#include <unordered_map>
#include <vector>
#include <string>

// 前置声明
class Animal;
class backPack;

/**
 * @class ServiceLocator
 * @brief 服务定位器模式实现 - 集中管理全局服务
 * 
 * 该单例类管理以下关键服务：
 * - Scene 服务（主游戏场景）
 * - TMXMap 服务（支持多个命名地图）
 * - Backpack 服务（背包管理）
 * - AnimalGrid 服务（动物网格）
 * - GameTime 服务（游戏时间）
 */
class ServiceLocator {
public:
    /**
     * @brief 获取单例实例
     */
    static ServiceLocator& getInstance();

    // ========== Scene 服务 ==========
    /**
     * @brief 注册场景
     */
    void registerScene(cocos2d::Scene* scene);
    
    /**
     * @brief 获取场景
     */
    cocos2d::Scene* getScene();

    // ========== TMXMap 服务 ==========
    /**
     * @brief 注册命名地图
     * @param name 地图名称（如 "map1", "map2", "mine" 等）
     * @param map TMXTiledMap 指针
     */
    void registerTMXMap(const std::string& name, cocos2d::TMXTiledMap* map);
    
    /**
     * @brief 获取指定名称的地图
     * @param name 地图名称
     * @return 地图指针，如果未找到返回 nullptr
     */
    cocos2d::TMXTiledMap* getTMXMap(const std::string& name);
    
    /**
     * @brief 获取当前活跃地图
     */
    cocos2d::TMXTiledMap* getCurrentTMXMap();
    
    /**
     * @brief 设置当前活跃地图
     * @param name 地图名称
     */
    void setCurrentTMXMap(const std::string& name);
    
    /**
     * @brief 获取当前活跃地图名称
     */
    std::string getCurrentMapName() const;

    // ========== Backpack 服务 ==========
    /**
     * @brief 注册背包
     */
    void registerBackpack(backPack* pack);
    
    /**
     * @brief 获取背包
     */
    backPack* getBackpack();

    // ========== AnimalGrid 服务 ==========
    /**
     * @brief 注册动物网格
     */
    void registerAnimalGrid(std::vector<Animal*>* grid);
    
    /**
     * @brief 获取动物网格
     */
    std::vector<Animal*>* getAnimalGrid();

    // ========== GameTime 服务 ==========
    /**
     * @brief 设置游戏时间
     */
    void setGameTime(int time);
    
    /**
     * @brief 获取游戏时间
     */
    int getGameTime() const;

    // ========== 服务管理 ==========
    /**
     * @brief 清空所有已注册的服务
     */
    void clear();

private:
    // 私有构造和析构，禁止复制和赋值
    ServiceLocator();
    ~ServiceLocator();
    ServiceLocator(const ServiceLocator&) = delete;
    ServiceLocator& operator=(const ServiceLocator&) = delete;

    // 成员变量
    cocos2d::Scene* m_scene;
    std::unordered_map<std::string, cocos2d::TMXTiledMap*> m_tmxMaps;
    std::string m_currentMapName;
    backPack* m_backpack;
    std::vector<Animal*>* m_animalGrid;
    int m_gameTime;
};

#endif // SERVICE_LOCATOR_H
