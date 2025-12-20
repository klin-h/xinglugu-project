#include "PlantingSystem.h"
#include "Land.h"
#include "back.h"
#include "backPhoto.h"

using namespace cocos2d;

// ============================================================
// Refactored with Object Pool Pattern (对象池模式重构)
// ============================================================
// CropPool 类实现
// ============================================================

CropPool* CropPool::s_instance = nullptr;

CropPool::CropPool() {
    m_availableCrops.reserve(DEFAULT_POOL_SIZE);
    m_activeCrops.reserve(DEFAULT_POOL_SIZE);
}

CropPool::~CropPool() {
    clear();
}

CropPool* CropPool::getInstance() {
    if (s_instance == nullptr) {
        s_instance = new (std::nothrow) CropPool();
    }
    return s_instance;
}

Crop* CropPool::acquire(const std::string& cropName, float growthTime, const std::string& spriteFile) {
    Crop* crop = nullptr;
    
    // 尝试从可用池中获取对象
    if (!m_availableCrops.empty()) {
        crop = m_availableCrops.back();
        m_availableCrops.pop_back();
        
        // 重置对象状态
        crop->reset(cropName, growthTime, spriteFile);
    } else {
        // 池为空，创建新对象
        crop = Crop::create(cropName, growthTime, spriteFile);
        if (!crop) {
            CCLOG("Failed to create crop in pool");
            return nullptr;
        }
        // 保留引用，防止被自动释放（对象池管理生命周期）
        crop->retain();
    }
    
    // 设置对象为激活状态
    crop->setActive(true);
    
    // 添加到使用中列表
    m_activeCrops.push_back(crop);
    
    return crop;
}

void CropPool::release(Crop* crop) {
    if (crop == nullptr) {
        return;
    }
    
    // 从使用中列表中移除
    auto it = std::find(m_activeCrops.begin(), m_activeCrops.end(), crop);
    if (it != m_activeCrops.end()) {
        m_activeCrops.erase(it);
    }
    
    // 设置对象为非激活状态
    crop->setActive(false);
    
    // 从父节点移除（如果还在场景中）
    if (crop->getParent()) {
        crop->removeFromParent();
    }
    
    // 归还到可用池中
    m_availableCrops.push_back(crop);
}

void CropPool::preload(int count, const std::string& defaultCropName, 
                       float defaultGrowthTime, const std::string& defaultSpriteFile) {
    for (int i = 0; i < count; ++i) {
        Crop* crop = Crop::create(defaultCropName, defaultGrowthTime, defaultSpriteFile);
        if (crop) {
            // 保留引用，防止被自动释放（对象池管理生命周期）
            crop->retain();
            crop->setActive(false);
            m_availableCrops.push_back(crop);
        }
    }
    CCLOG("Preloaded %d crops into pool", count);
}

int CropPool::getAvailableCount() const {
    return static_cast<int>(m_availableCrops.size());
}

int CropPool::getActiveCount() const {
    return static_cast<int>(m_activeCrops.size());
}

void CropPool::clear() {
    // 清理可用池中的对象
    for (auto* crop : m_availableCrops) {
        if (crop) {
            // 释放对象池持有的引用
            crop->release();
        }
    }
    m_availableCrops.clear();
    
    // 清理使用中的对象
    for (auto* crop : m_activeCrops) {
        if (crop) {
            // 释放对象池持有的引用
            crop->release();
        }
    }
    m_activeCrops.clear();
}

// ============================================================

// 初始化
bool PlantingSystem::init() {
    if (!Node::init()) {
        return false;
    }

    // 每帧更新
    schedule([this](float delta) { update(delta); }, "update_key");

    // 订阅全局事件：天数推进与季节变化（Observer 模式）
    auto& bus = GameEventDispatcher::instance();
    handleDayPassed = bus.subscribe(GameEventType::DayPassed, [this](const GameEvent& evt) {
        int days = evt.payload.at("days").asInt();
        // 简化示例：按天刷新作物生长（此处可扩展成长倍率）
        for (auto* crop : crops) {
            if (crop) {
                crop->update(1.0f); // 每天推进一次生长 tick
            }
        }
        CCLOG("[PlantingSystem] DayPassed event received: %d", days);
    });

    handleSeasonChanged = bus.subscribe(GameEventType::SeasonChanged, [this](const GameEvent& evt) {
        std::string season = evt.payload.at("current").asString();
        // 简化示例：根据季节调整作物生长速度或滤除不适作物
        for (auto* crop : crops) {
            if (crop && season == "Winter") {
                // 冬季减缓生长：少量推进
                crop->update(0.2f);
            }
        }
        CCLOG("[PlantingSystem] SeasonChanged to %s", season.c_str());
    });

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

void PlantingSystem::onExit() {
    Node::onExit();
    auto& bus = GameEventDispatcher::instance();
    if (handleDayPassed != -1) {
        bus.unsubscribe(GameEventType::DayPassed, handleDayPassed);
        handleDayPassed = -1;
    }
    if (handleSeasonChanged != -1) {
        bus.unsubscribe(GameEventType::SeasonChanged, handleSeasonChanged);
        handleSeasonChanged = -1;
    }
}

// 种植作物
bool PlantingSystem::plantCrop(const std::string& cropName, float growthTime, const std::string& spriteFile, const cocos2d::Vec2& position) {
    // ============================================================
    // Refactored with Object Pool Pattern (对象池模式重构)
    // ============================================================
    // 使用对象池获取作物对象，而非直接创建
    Crop* crop = CropPool::getInstance()->acquire(cropName, growthTime, spriteFile);
    // ============================================================
    
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
                // ============================================================
                // Refactored with Object Pool Pattern (对象池模式重构)
                // ============================================================
                // 归还作物到对象池，而非直接删除
                CropPool::getInstance()->release(crop);
                // ============================================================
                
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
