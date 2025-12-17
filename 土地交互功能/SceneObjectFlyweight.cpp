#include "SceneObjectFlyweight.h"

USING_NS_CC;

SceneObjectFlyweightFactory& SceneObjectFlyweightFactory::instance() {
    static SceneObjectFlyweightFactory factory;
    return factory;
}

SceneObjectFlyweightFactory::SceneObjectFlyweightFactory() {
    registerDefaultFlyweights();
}

void SceneObjectFlyweightFactory::registerDefaultFlyweights() {
    // 注册所有默认的Flyweight对象
    cache_[static_cast<int>(SceneObjectType::Tree)] = {
        "tree.png",
        "tree_chopped.png",
        5,
        "Tree"
    };

    cache_[static_cast<int>(SceneObjectType::Rock)] = {
        "rock.png",
        "rock_broken.png",
        10,
        "Rock"
    };

    cache_[static_cast<int>(SceneObjectType::Grass)] = {
        "grass.png",
        "grass_harvested.png",
        2,
        "Grass"
    };

    cache_[static_cast<int>(SceneObjectType::IronOre)] = {
        "iron_ore.png",
        "iron_ore_mined.png",
        15,
        "IronOre"
    };

    cache_[static_cast<int>(SceneObjectType::SilverOre)] = {
        "silver_ore.png",
        "silver_ore_mined.png",
        20,
        "SilverOre"
    };

    cache_[static_cast<int>(SceneObjectType::GoldOre)] = {
        "gold_ore.png",
        "gold_ore_mined.png",
        25,
        "GoldOre"
    };
}

const SceneObjectFlyweight& SceneObjectFlyweightFactory::getFlyweight(SceneObjectType type) {
    auto it = cache_.find(static_cast<int>(type));
    if (it != cache_.end()) {
        return it->second;
    }
    // 如果未找到，返回第一个（Tree作为默认值，实际应该处理错误）
    static SceneObjectFlyweight defaultFlyweight = {"error.png", "error.png", 0, "Error"};
    return defaultFlyweight;
}

void SceneObjectFlyweightFactory::registerFlyweight(SceneObjectType type, const SceneObjectFlyweight& flyweight) {
    cache_[static_cast<int>(type)] = flyweight;
}
