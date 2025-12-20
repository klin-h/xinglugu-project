/****************************************************************
 * Project Name: xinglugu-project
 * File initAnimalScene.cpp
 * File Function: init Animal on Scene
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#include"initAnimalScene.h"
#include "SceneObject.h"
#include "AnimalFactory.h"
#include "Cow.h"
#include "Pig.h"
#include "Animal.h"
#include "back.h"
#include "backPhoto.h"
#include "cocos2d.h"
#include "json/document.h"
#include "json/error/en.h"
#include "ServiceLocator.h"

USING_NS_CC;
extern backPack* pack1;

// ============================================================
// 重构说明: 动物网格现在由ServiceLocator管理
// 不再使用全局 std::vector<Animal*> animalGrid
// ============================================================

// A simple description of where and which animal should spawn.
struct AnimalSpawnSpec {
    AnimalType type;
    cocos2d::Vec2 position;
};

static AnimalType animalTypeFromString(const std::string& typeString, bool& ok) {
    ok = true;
    if (typeString == "cow") {
        return AnimalType::Cow;
    }
    if (typeString == "pig") {
        return AnimalType::Pig;
    }
    if (typeString == "sheep") {
        return AnimalType::Sheep;
    }
    if (typeString == "rabbit") {
        return AnimalType::Rabbit;
    }
    if (typeString == "chicken") {
        return AnimalType::Chicken;
    }
    if (typeString == "dog") {
        return AnimalType::Dog;
    }
    ok = false;
    return AnimalType::Cow;
}

static std::vector<AnimalSpawnSpec> loadSpawnSpecsFromConfig(const cocos2d::Size& visibleSize, const cocos2d::Vec2& origin) {
    std::vector<AnimalSpawnSpec> specs;
    auto fileUtils = FileUtils::getInstance();
    const std::string path = "config/animal_spawn_config.json";
    if (!fileUtils->isFileExist(path)) {
        return specs;
    }
    const auto jsonContent = fileUtils->getStringFromFile(path);
    rapidjson::Document doc;
    doc.Parse(jsonContent.c_str());
    if (doc.HasParseError() || !doc.IsArray()) {
        CCLOG("Failed to parse animal spawn config: %s", rapidjson::GetParseError_En(doc.GetParseError()));
        return specs;
    }
    for (const auto& entry : doc.GetArray()) {
        if (!entry.IsObject()) {
            continue;
        }
        if (!entry.HasMember("type") || !entry.HasMember("x") || !entry.HasMember("y")) {
            continue;
        }
        if (!entry["type"].IsString() || !entry["x"].IsNumber() || !entry["y"].IsNumber()) {
            continue;
        }
        bool ok = false;
        AnimalType type = animalTypeFromString(entry["type"].GetString(), ok);
        if (!ok) {
            continue;
        }
        float rx = entry["x"].GetFloat();
        float ry = entry["y"].GetFloat();
        rx = std::clamp(rx, 0.0f, 1.0f);
        ry = std::clamp(ry, 0.0f, 1.0f);
        const cocos2d::Vec2 position(origin.x + visibleSize.width * rx, origin.y + visibleSize.height * ry);
        specs.push_back({ type, position });
    }
    return specs;
}

static std::vector<AnimalSpawnSpec> makeDefaultSpawnSpecs(const cocos2d::Size& visibleSize, const cocos2d::Vec2& origin) {
    std::vector<AnimalSpawnSpec> specs;
    const std::vector<std::pair<AnimalType, std::vector<std::pair<float, float>>>> templateRatios = {
        { AnimalType::Cow, { {0.3f, 0.3f}, {0.5f, 0.4f}, {0.7f, 0.3f} } },
        { AnimalType::Pig, { {0.4f, 0.6f}, {0.6f, 0.6f}, {0.5f, 0.7f} } },
        { AnimalType::Sheep, { {0.2f, 0.5f}, {0.8f, 0.5f} } },
        { AnimalType::Rabbit, { {0.25f, 0.2f}, {0.75f, 0.2f}, {0.35f, 0.8f}, {0.65f, 0.8f}, {0.5f, 0.9f} } },
    };
    for (const auto& [type, ratios] : templateRatios) {
        for (const auto& [rx, ry] : ratios) {
            const cocos2d::Vec2 position(origin.x + visibleSize.width * rx, origin.y + visibleSize.height * ry);
            specs.push_back({ type, position });
        }
    }
    return specs;
}

static std::vector<AnimalSpawnSpec> filterSpecs(const std::vector<AnimalSpawnSpec>& allSpecs, AnimalType type) {
    std::vector<AnimalSpawnSpec> result;
    for (const auto& spec : allSpecs) {
        if (spec.type == type) {
            result.push_back(spec);
        }
    }
    return result;
}


void removeAnimal(Scene* scene, std::vector<Animal*>& animalGrid, Animal* animal) {
    if (animal) {
        animal->removeFromParentAndCleanup(true);
        CCLOG("Animal has been removed from the scene.");

        auto it = std::find(animalGrid.begin(), animalGrid.end(), animal);
        if (it != animalGrid.end()) {
            animalGrid.erase(it);
            CCLOG("Animal has been removed from animalGrid.");
        }
        else {
            CCLOG("Animal was not found in animalGrid.");
        }
    }
}

void setupAnimal(Scene* scene) {
    // 获取可见区域大小和原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    // =============== 使用ServiceLocator初始化动物网格 ===============
    // 如果尚未注册，则创建和注册一个新的动物网格
    auto animalGridPtr = ServiceLocator::getInstance().getAnimalGrid();
    if (!animalGridPtr) {
        // 创建一个新的动物网格并注册到ServiceLocator
        static std::vector<Animal*> globalAnimalGrid;
        ServiceLocator::getInstance().registerAnimalGrid(&globalAnimalGrid);
        animalGridPtr = &globalAnimalGrid;
    }
    
    std::vector<Animal*>& animalGrid = *animalGridPtr;

    // Try loading spawn specs from configuration, fallback to built-in defaults.
    auto spawnSpecs = loadSpawnSpecsFromConfig(visibleSize, origin);
    if (spawnSpecs.empty()) {
        spawnSpecs = makeDefaultSpawnSpecs(visibleSize, origin);
    }

    auto cowSpecs = filterSpecs(spawnSpecs, AnimalType::Cow);
    auto pigSpecs = filterSpecs(spawnSpecs, AnimalType::Pig);
    auto sheepSpecs = filterSpecs(spawnSpecs, AnimalType::Sheep);
    auto rabbitSpecs = filterSpecs(spawnSpecs, AnimalType::Rabbit);

    // 初始化牛（Cows）
    for (size_t i = 0; i < cowSpecs.size(); ++i) {
        auto cow = static_cast<Cow*>(AnimalFactory::create(cowSpecs[i].type));
        if (!cow) {
            CCLOG("Failed to create cow %d", i + 1);
            continue;
        }

        cow->setPosition(cowSpecs[i].position);
        scene->addChild(cow, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);
        animalGrid.push_back(cow);

        // 启动随机移动逻辑
        std::string scheduleName = "cow_random_move_" + std::to_string(i);
        cow->schedule([cow, visibleSize, origin](float) {
            if (!cow->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
                // 随机生成目标位置
                float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
                float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
                Vec2 targetPosition(targetX, targetY); // 移动到目标位置
                cow->moveTo(targetPosition);
            }
            }, 0.1f, scheduleName); // 每 0.1 秒检查一次

        // 为 Cow 添加触摸监听器
        auto touchListener = EventListenerTouchOneByOne::create();
        touchListener->onTouchBegan = [cow, i](Touch* touch, Event* event) -> bool {
            Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
            if (cow->getBoundingBox().containsPoint(cow->getParent()->convertToNodeSpace(touchLocation))) {
                CCLOG("This is cow %d", i + 1); // 打印点击信息
                cow->moo();
                cow->stopWalkingAnimation();

                Item* newitem = AnimalProduct::create("milk");
                if (newitem) {
                    auto backpack = ServiceLocator::getInstance().getBackpack();
                    if (backpack) {
                        backpack->itemAdd(newitem, 2);
                    }
                }
                return true; // 消耗事件，停止传播
            }
            return false; // 未点击到牛，继续传播事件
            };

        // 将触摸监听器绑定到事件分发器
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, cow);

      
    }

    // 初始化猪（Pigs）
    for (size_t i = 0; i < pigSpecs.size(); ++i) {
        auto pig = static_cast<Pig*>(AnimalFactory::create(pigSpecs[i].type));
        if (!pig) {
            CCLOG("Failed to create pig %d", i + 1);
            continue;
        }

        pig->setPosition(pigSpecs[i].position);
        scene->addChild(pig, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);
        animalGrid.push_back(pig);

        // 启动随机移动逻辑
        std::string scheduleName = "pig_random_move_" + std::to_string(i);
        pig->schedule([pig, visibleSize, origin](float) {
            if (!pig->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
                // 随机生成目标位置
                float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
                float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
                Vec2 targetPosition(targetX, targetY); // 移动到目标位置
                pig->moveTo(targetPosition);
            }
            }, 0.1f, scheduleName); // 每 0.1 秒检查一次

        // 为 Pig 添加触摸监听器
        auto touchListener_pig = EventListenerTouchOneByOne::create();
        touchListener_pig->onTouchBegan = [pig, i](Touch* touch, Event* event) -> bool {
            Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
            if (pig->getBoundingBox().containsPoint(pig->getParent()->convertToNodeSpace(touchLocation))) {
                CCLOG("This is pig %d", i + 1); // 打印点击信息
                pig->oink();
                pig->stopWalkingAnimation();
                return true; // 消耗事件，停止传播
            }
            return false; // 未点击到猪，继续传播事件
            };

        // 将触摸监听器绑定到事件分发器
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener_pig, pig);

        // 启动猪的行走动画
     
    }

    // 初始化羊（Sheeps）
    for (size_t i = 0; i < sheepSpecs.size(); ++i) {
        auto sheep = static_cast<Sheep*>(AnimalFactory::create(sheepSpecs[i].type));
        if (!sheep) {
            CCLOG("Failed to create sheep %d", i + 1);
            continue;
        }

        sheep->setPosition(sheepSpecs[i].position);
        scene->addChild(sheep, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);
        animalGrid.push_back(sheep);

        // 启动随机移动逻辑
        std::string scheduleName = "sheep_random_move_" + std::to_string(i);
        sheep->schedule([sheep, visibleSize, origin](float) {
            if (!sheep->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
                // 随机生成目标位置
                float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
                float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
                Vec2 targetPosition(targetX, targetY); // 移动到目标位置
                sheep->moveTo(targetPosition);
            }
            }, 0.1f, scheduleName); // 每 0.1 秒检查一次

        // 为 Sheep 添加触摸监听器
        auto touchListener_sheep = EventListenerTouchOneByOne::create();
        touchListener_sheep->onTouchBegan = [sheep, i](Touch* touch, Event* event) -> bool {
            Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
            if (sheep->getBoundingBox().containsPoint(sheep->getParent()->convertToNodeSpace(touchLocation))) {
                CCLOG("This is sheep %d", i + 1); // 打印点击信息
               
                Item* newitem = AnimalProduct::create("animalfeather");
                if (newitem) {
                    auto backpack = ServiceLocator::getInstance().getBackpack();
                    if (backpack) {
                        backpack->itemAdd(newitem, 2);
                    }
                }
                sheep->stopWalkingAnimation();
                return true; // 消耗事件，停止传播
            }
            return false; // 未点击到羊，继续传播事件
            };

        // 将触摸监听器绑定到事件分发器
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener_sheep, sheep);

        // 启动羊的行走动画
       
    }

    // 初始化兔子（Rabbits）
    for (size_t i = 0; i < rabbitSpecs.size(); ++i) {
        auto rabbit = static_cast<Rabbit*>(AnimalFactory::create(rabbitSpecs[i].type));
        if (!rabbit) {
            CCLOG("Failed to create rabbit %d", i + 1);
            continue;
        }

        rabbit->setPosition(rabbitSpecs[i].position);
        scene->addChild(rabbit, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);
        animalGrid.push_back(rabbit);

        // 启动随机移动逻辑
        std::string scheduleName = "rabbit_random_move_" + std::to_string(i);
        rabbit->schedule([rabbit, visibleSize, origin](float) {
            CCLOG("Rabbit schedule lambda called.");
            if (!rabbit->getNumberOfRunningActions()) { // 如果当前没有正在执行的移动动作
                // 随机生成目标位置
                float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
                float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
                Vec2 targetPosition(targetX, targetY); // 移动到目标位置
                rabbit->moveTo(targetPosition);
                CCLOG("Rabbit moving to: (%f, %f)", targetX, targetY);
            }
            }, 0.1f, scheduleName); // 每 0.1 秒检查一次

        // 为 Rabbit 添加触摸监听器
        auto touchListener_rabbit = EventListenerTouchOneByOne::create();
        touchListener_rabbit->onTouchBegan = [rabbit, i, scene](Touch* touch, Event* event) -> bool {
            Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
            if (rabbit->getBoundingBox().containsPoint(rabbit->getParent()->convertToNodeSpace(touchLocation))) {
                CCLOG("This is rabbit %d", i + 1); // 打印点击信息
                rabbit->hop(); // 调用 Rabbit 类的 hop 方法
                rabbit->stopWalkingAnimation();

                auto backpack = ServiceLocator::getInstance().getBackpack();
                if (backpack) {
                    // 根据当前工具执行不同逻辑
                    std::string currentTool = backpack->handInItemOut();
                    if (currentTool == "axe") {
                        rabbit->setHealth(50);
                        if (rabbit->getHealth() == 0) {
                            Item* newitem = AnimalProduct::create("rabbitleg");
                            if (newitem) {
                                backpack->itemAdd(newitem, 1);
                            }
                            auto animalGridPtr = ServiceLocator::getInstance().getAnimalGrid();
                            if (animalGridPtr) {
                                removeAnimal(scene, *animalGridPtr, rabbit);
                            }
                            CCLOG("Rabbit %d has been removed from the scene.", i + 1);
                        }
                    }
                    else if (currentTool == "parsnipseed") {
                        rabbit->feed();
                        Item* newitem = AnimalProduct::create("parsnipseed");
                        int posi = backpack->returnPosi(newitem);
                        backpack->itemReduce(newitem, 1);
                        if (backpack->returnPosi(newitem) == -1) {
                            packPosi(posi);
                        }
                        else {
                            numlabel2(backpack->returnPosi(newitem));
                        }
                    }
                    else {
                        rabbit->stopWalkingAnimation();
                    }
                }

                return true; // 消耗事件，停止传播
            }
            return false; // 未点击到兔子，继续传播事件
            };

        // 将触摸监听器绑定到事件分发器
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener_rabbit, rabbit);

        // 启动兔子的行走动画
      
    }
}

void cleanupAnimals(Scene* scene, std::vector<Animal*>& animalGrid) {
    for (auto& animal : animalGrid) {
        if (animal) {
            // 停止所有动作
            animal->stopAllActions();

            // 停止所有调度的回调
            animal->unscheduleAllCallbacks();

            // 从父节点（场景）中移除精灵，并进行清理
            animal->removeFromParentAndCleanup(true);
        }
    }

    // 清空对象向量，移除所有悬挂的指针
    animalGrid.clear();

    CCLOG("All animals have been cleaned up.");
}

