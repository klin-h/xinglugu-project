#ifndef SCENEOBJECT_FLYWEIGHT_H
#define SCENEOBJECT_FLYWEIGHT_H

#include "cocos2d.h"
#include <unordered_map>
#include <memory>
#include <string>

enum class SceneObjectType {
    Tree,
    Rock,
    Grass,
    IronOre,
    SilverOre,
    GoldOre,
};

/**
 * 享元模式中的共享对象
 * 包含不会随实例变化的固有属性
 */
struct SceneObjectFlyweight {
    std::string idleTexture;       // 初始贴图
    std::string interactedTexture; // 交互后的贴图
    int dropQuantity;              // 掉落数量
    std::string objectName;        // 对象名称（用于日志）
};

/**
 * 享元工厂
 * 负责创建和缓存共享的Flyweight对象
 */
class SceneObjectFlyweightFactory {
public:
    static SceneObjectFlyweightFactory& instance();

    /**
     * 获取指定类型的Flyweight对象
     */
    const SceneObjectFlyweight& getFlyweight(SceneObjectType type);

    /**
     * 注册自定义的Flyweight配置（便于扩展）
     */
    void registerFlyweight(SceneObjectType type, const SceneObjectFlyweight& flyweight);

private:
    SceneObjectFlyweightFactory();
    void registerDefaultFlyweights();

    std::unordered_map<int, SceneObjectFlyweight> cache_;
};

#endif // SCENEOBJECT_FLYWEIGHT_H
