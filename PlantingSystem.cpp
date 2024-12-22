#include "PlantingSystem.h"
#include "Land.h"
#include "back.h"
#include "backPhoto.h"

using namespace cocos2d;

// 初始化
bool PlantingSystem::init() {
    if (!Node::init()) {
        return false;
    }

    // 每帧更新
    schedule([this](float delta) { update(delta); }, "update_key");

    // 创建触摸事件监听器
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [this](Touch* touch, Event* event) {
        Vec2 touchLocation = touch->getLocation(); // 获取触摸位置
        harvestCrop(touchLocation); // 尝试收获作物
        CCLOG("a");
        return true; // 表示事件已处理
        };

    // 将触摸监听器添加到事件调度器
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

// 种植作物
bool PlantingSystem::plantCrop(const std::string& cropName, float growthTime, const std::string& spriteFile, const cocos2d::Vec2& position) {
    Crop* crop = Crop::create(cropName, growthTime, spriteFile);
    if (crop) {
        crop->setPosition(position);
        crops.push_back(crop);
        this->addChild(crop);
        return true; // 成功种植
    }
    return false; // 种植失败
}

void PlantingSystem::update(float deltaTime) {
    // 更新所有作物状态
    for (Crop* crop : crops) {
        crop->update(deltaTime);
    }
}

void PlantingSystem::harvestCrop(cocos2d::Vec2 touchPosition) {
    for (auto it = crops.begin(); it != crops.end(); ) {
        Crop* crop = *it;
        if (crop->getState() == Crop::State::HARVESTABLE) {
            CCLOG("Checking crop: %s", crop->getName().c_str());

            // 使用 Crop 类中定义的 isTouched 方法
            if (crop->isTouched(touchPosition) || pack1->handInItemOut() == "null") {
                CCLOG("Harvesting crop: %s", crop->getName().c_str());
                // 添加收获物品到背包
                if (crop->getName() == "cauliflower") {
                    Item* item0 = Fruit::create("cauliflower");
                    pack1->itemAdd(item0, 1);
                    CCLOG("1");
                }
                else if (crop->getName() == "parsnip") {
                    Item* item0 = Fruit::create("parsnip");
                    pack1->itemAdd(item0, 1);
                }
                // 有效的点击，进行收获
                this->removeChild(crop); // 从场景中移除作物
                it = crops.erase(it); // 从容器中删除作物


                // 进行其他收获逻辑，比如增加资源等
                continue; // 继续下一个作物
            }
            else {
                CCLOG("Touch not within crop bounding box.");
            }
        }
        ++it; // 继续下一个作物
    }
}
