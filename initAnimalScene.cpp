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
#include "Animal.h"
#include "back.h"
#include "backPhoto.h"


USING_NS_CC;
extern backPack* pack1;
std::vector<Animal*> animalGrid;


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
    // 定义每种动物的数量
    const int NUM_COWS = 3;
    const int NUM_PIGS = 3;
    const int NUM_SHEEPS = 2;
    const int NUM_RABBITS = 5;

    // 获取可见区域大小和原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // 定义每种动物的初始位置（确保每只动物的位置不同）
    std::vector<Vec2> cowPositions = {
        Vec2(origin.x + visibleSize.width * 0.3f, origin.y + visibleSize.height * 0.3f),
        Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.4f),
        Vec2(origin.x + visibleSize.width * 0.7f, origin.y + visibleSize.height * 0.3f)
    };

    std::vector<Vec2> pigPositions = {
        Vec2(origin.x + visibleSize.width * 0.4f, origin.y + visibleSize.height * 0.6f),
        Vec2(origin.x + visibleSize.width * 0.6f, origin.y + visibleSize.height * 0.6f),
        Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.7f)
    };

    std::vector<Vec2> sheepPositions = {
        Vec2(origin.x + visibleSize.width * 0.2f, origin.y + visibleSize.height * 0.5f),
        Vec2(origin.x + visibleSize.width * 0.8f, origin.y + visibleSize.height * 0.5f)
    };

    std::vector<Vec2> rabbitPositions = {
        Vec2(origin.x + visibleSize.width * 0.25f, origin.y + visibleSize.height * 0.2f),
        Vec2(origin.x + visibleSize.width * 0.75f, origin.y + visibleSize.height * 0.2f),
        Vec2(origin.x + visibleSize.width * 0.35f, origin.y + visibleSize.height * 0.8f),
        Vec2(origin.x + visibleSize.width * 0.65f, origin.y + visibleSize.height * 0.8f),
        Vec2(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.9f)
    };

    // 初始化牛（Cows）
    for (int i = 0; i < NUM_COWS && i < cowPositions.size(); ++i) {
        auto cow = Cow::create();
        if (!cow) {
            CCLOG("Failed to create cow %d", i + 1);
            continue;
        }

        cow->setPosition(cowPositions[i]);
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
                    pack1->itemAdd(newitem, 2);
                }
                return true; // 消耗事件，停止传播
            }
            return false; // 未点击到牛，继续传播事件
            };

        // 将触摸监听器绑定到事件分发器
        scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, cow);

      
    }

    // 初始化猪（Pigs）
    for (int i = 0; i < NUM_PIGS && i < pigPositions.size(); ++i) {
        auto pig = Pig::create();
        if (!pig) {
            CCLOG("Failed to create pig %d", i + 1);
            continue;
        }

        pig->setPosition(pigPositions[i]);
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
    for (int i = 0; i < NUM_SHEEPS && i < sheepPositions.size(); ++i) {
        auto sheep = Sheep::create();
        if (!sheep) {
            CCLOG("Failed to create sheep %d", i + 1);
            continue;
        }

        sheep->setPosition(sheepPositions[i]);
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
                    pack1->itemAdd(newitem, 2);
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
    for (int i = 0; i < NUM_RABBITS && i < rabbitPositions.size(); ++i) {
        auto rabbit = Rabbit::create();
        if (!rabbit) {
            CCLOG("Failed to create rabbit %d", i + 1);
            continue;
        }

        rabbit->setPosition(rabbitPositions[i]);
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

                // 根据当前工具执行不同逻辑
                std::string currentTool = pack1->handInItemOut();
                if (currentTool == "axe") {
                    rabbit->setHealth(50);
                    if (rabbit->getHealth() == 0) {
                        Item* newitem = AnimalProduct::create("rabbitleg");
                        if (newitem) {
                            pack1->itemAdd(newitem, 1);
                        }
                        removeAnimal(scene, animalGrid, rabbit);
                        CCLOG("Rabbit %d has been removed from the scene.", i + 1);
                    }
                }
                else if (currentTool == "parsnipseed") {
                    rabbit->feed();
                    Item* newitem = AnimalProduct::create("parsnipseed");
                    int posi = pack1->returnPosi(newitem);
                    pack1->itemReduce(newitem, 1);
                    if (pack1->returnPosi(newitem) == -1) {
                        packPosi(posi);
                    }
                    else {
                        numlabel2(pack1->returnPosi(newitem));
                    }
                }
                else {
                    rabbit->stopWalkingAnimation();
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
