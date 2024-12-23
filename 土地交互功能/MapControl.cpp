#include "MapControl.h"
#include "ui/CocosGUI.h"
#include "WheelGame.h"
#include "GlobalVariables.h"
#include "Animal.h"
#include"initAnimalScene.h"

MapControl::MapControl(Node* parent, float scale, const std::vector<std::string>& mapFiles)
    : parentNode(parent), mapScale(scale), currentMap(nullptr), currentMapIndex(0) {
    // 初始化地图
    for (const auto& mapFile : mapFiles) {
        TMXTiledMap* newMap = TMXTiledMap::create(mapFile);
        if (!newMap) {
            CCLOG("Failed to load map: %s", mapFile.c_str());
            continue;
        }
        //newMap->setScale(mapScale);
        newMap->setVisible(false); // 默认隐藏
        parentNode->addChild(newMap, 0);
        maps.push_back(newMap);
    }

    // 设置初始地图
    if (!maps.empty()) {
        currentMap = maps[0];
        currentMap->setVisible(true);
        currentMapIndex = 0;
        CCLOG("Initialized MapControl with %zu maps", maps.size());
    }
}

void MapControl::switchMap(size_t mapIndex, const Vec2& spawnPoint) {
    // 检查地图索引是否合法
    if (mapIndex >= maps.size()) {
        CCLOG("Invalid map index: %zu", mapIndex);
        return;
    }

    // 保存当前地图状态
    saveCurrentMapState();

    // 隐藏当前地图
    if (currentMap) {
        currentMap->setVisible(false);
    }

    // 切换到新地图
    currentMap = maps[mapIndex];
    currentMap->setVisible(true);
    currentMapIndex = mapIndex;

    // 恢复新地图状态
    restoreMapState(mapIndex);

    CCLOG("Switched to map index: %zu", mapIndex);
}

void MapControl::saveCurrentMapState() {
    if (!currentMap) return;

    // 此处可以扩展保存瓦片或其他状态的逻辑
    CCLOG("Saved current map state for map index: %zu", currentMapIndex);
}

void MapControl::restoreMapState(size_t mapIndex) {
    if (mapIndex >= maps.size()) {
        CCLOG("Invalid map index for restoring state: %zu", mapIndex);
        return;
    }

    // 此处可以扩展恢复瓦片或其他状态的逻辑
    CCLOG("Restored map state for map index: %zu", mapIndex);
}

bool MapControl::isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize) {
    Vec2 targetPosition = position + direction;

    if (targetPosition.x < 0 || targetPosition.x > visibleSize.width ||
        targetPosition.y < 0 || targetPosition.y > visibleSize.height) {
        CCLOG("Player will move out of screen bounds.");
        return false;
    }

    return true;
}

TMXTiledMap* MapControl::getCurrentMap() const {
    return currentMap;
}


// 定义一天和一年的持续时间（以秒为单位）
const float SECONDS_PER_DAY = 60.0f;     // 60秒代表一天
const float SECONDS_PER_YEAR = 3600.0f;  // 3600秒代表一年

void updateProgressBars(Scene* scene, float g_time) {
  
    const std::string DAY_PROGRESS_NAME = "dayProgressBar";
    const std::string YEAR_PROGRESS_NAME = "yearProgressBar";

    // 获取可见区域大小和原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // 计算场景的中心点
    Vec2 center = Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

    /**
     * 初始化当天进度条
     * 如果进度条尚未创建，则创建并添加到场景中
     */
    ProgressTimer* dayProgressBar = dynamic_cast<ProgressTimer*>(scene->getChildByName(DAY_PROGRESS_NAME));
    if (!dayProgressBar) {
        // 创建进度条背景
        auto dayBgSprite = Sprite::create("day_progress_bg.png");
        if (!dayBgSprite) {
            CCLOG("Failed to load day_progress_bg.png");
            return;
        }

        // 创建 ProgressTimer
        dayProgressBar = ProgressTimer::create(dayBgSprite);
        dayProgressBar->setType(ProgressTimer::Type::BAR);
        dayProgressBar->setBarChangeRate(Vec2(1, 0)); // 水平进度条
        dayProgressBar->setMidpoint(Vec2(0, 0));      // 从左到右
        dayProgressBar->setPercentage(0);             // 初始化为0%

        // 设置位置：中心上方50像素
        dayProgressBar->setPosition(center + Vec2(0, 50));
        dayProgressBar->setName(DAY_PROGRESS_NAME);
        scene->addChild(dayProgressBar, 10); // Z-order根据需要调整
    }

    /**
     * 初始化季节进度条
     * 如果进度条尚未创建，则创建并添加到场景中
     */
    ProgressTimer* yearProgressBar = dynamic_cast<ProgressTimer*>(scene->getChildByName(YEAR_PROGRESS_NAME));
    if (!yearProgressBar) {
        // 创建进度条背景
        auto yearBgSprite = Sprite::create("season_progress_bg.png");
        if (!yearBgSprite) {
            CCLOG("Failed to load season_progress_bg.png");
            return;
        }

        // 创建 ProgressTimer
        yearProgressBar = ProgressTimer::create(yearBgSprite);
        yearProgressBar->setType(ProgressTimer::Type::BAR);
        yearProgressBar->setBarChangeRate(Vec2(1, 0)); // 水平进度条
        yearProgressBar->setMidpoint(Vec2(0, 0));      // 从左到右
        yearProgressBar->setPercentage(0);             // 初始化为0%

        // 设置位置：中心下方50像素
        yearProgressBar->setPosition(center + Vec2(0, -50));
        yearProgressBar->setName(YEAR_PROGRESS_NAME);
        scene->addChild(yearProgressBar, 10); // Z-order根据需要调整
    }

    // 计算一天和一年的进度百分比
    float dayProgress = fmod(g_time, SECONDS_PER_DAY) / SECONDS_PER_DAY * 100.0f;
    float yearProgress = fmod(g_time, SECONDS_PER_YEAR) / SECONDS_PER_YEAR * 100.0f;

    // 更新当天进度条的百分比
    if (dayProgressBar) {
        dayProgressBar->setPercentage(dayProgress);
    }
    else {
        CCLOG("dayProgressBar not found in the scene.");
    }

    // 更新季节进度条的百分比
    if (yearProgressBar) {
        yearProgressBar->setPercentage(yearProgress);
    }
    else {
        CCLOG("yearProgressBar not found in the scene.");
    }
}


bool initBrightnessOverlay(Scene* scene) {

   
    const std::string OVERLAY_NAME = "brightnessOverlay";

    // 检查覆盖层是否已经存在
    if (scene->getChildByName(OVERLAY_NAME)) {
        CCLOG("Brightness overlay already initialized.");
        return false;
    }

    // 获取可见区域大小和原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // 创建黑色覆盖层，初始透明度为0（完全透明）
    auto overlay = LayerColor::create(Color4B(0, 0, 0, 0),
        visibleSize.width,
        visibleSize.height);
    if (!overlay) {
        CCLOG("Failed to create brightnessOverlay");
        return false;
    }

    // 设置覆盖层的位置为场景的左下角
    overlay->setPosition(Vec2::ZERO);
    overlay->setName(OVERLAY_NAME);
    scene->addChild(overlay, 100); // Z-order为100，确保在最上层

    return true;
}

void update(float dt) {

    static int time = 0;
    static int time2 = 0;
    //CCLOG("This function is called every second.");
    g_time++;
    //CCLOG("game time", g_time++);
    const std::string OVERLAY_NAME = "brightnessOverlay";
    const float MAX_OPACITY = 128.0f; // 最大透明度（0-255）

   
    auto overlay = dynamic_cast<LayerColor*>(g_sharedScene->getChildByName(OVERLAY_NAME));
    if (!overlay) {
        // 如果覆盖层不存在，尝试初始化
        if (!initBrightnessOverlay(g_sharedScene)) {
            CCLOG("Failed to initialize brightnessOverlay");
            return;
        }
        overlay = dynamic_cast<LayerColor*>(g_sharedScene->getChildByName(OVERLAY_NAME));
        if (!overlay) {
            CCLOG("Brightness overlay could not be created.");
            return;
        }
    }

    // 计算当前一天的进度（0.0 - 1.0）
    float currentDayTime = fmod(g_time, SECONDS_PER_DAY);
    float dayProgress = currentDayTime / SECONDS_PER_DAY;

    // 计算覆盖层的透明度
    float opacity = dayProgress * MAX_OPACITY; // 0到MAX_OPACITY

    // 设置覆盖层的透明度
    overlay->setOpacity(static_cast<GLubyte>(opacity));


    if (g_time> Constants::kCelebrationTime &&time==0) {
        time++;
        if (g_sharedTMXcurrent== g_sharedTMXthree) {
            cleanupAnimals(g_sharedScene, animalGrid);
        }
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("The celebration begins,go to  celebration?");
        button->setTitleFontSize(14);
        button->setPosition(Vec2(600, 400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);

        // 定时器移除按钮
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // 减少引用计数
            }, 5.0f, "removeButtonKey");

        // 按钮点击事件
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");

            
            TMXTiledMap* aimmap = g_sharedTMXfour;
          
            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // 添加到父节点中
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;

            auto wheelGame = WheelGame::create();
            g_sharedScene->addChild(wheelGame, 3);

            button->removeFromParent();
            button->release(); // 减少引用计数
            g_sharedScene->unschedule("removeButtonKey"); // 取消定时器
            });
    }

    if (g_time >2*( Constants::kCelebrationTime) && time2==0) {
        time2++;
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("The celebration ends,go to  celebration?");
        button->setTitleFontSize(14);
        button->setPosition(Vec2(600, 400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);

        // 定时器移除按钮
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // 减少引用计数
            }, 5.0f, "removeButtonKey");

        // 按钮点击事件
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");


            TMXTiledMap* aimmap = g_sharedTMXone;

            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // 添加到父节点中
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;

            button->removeFromParent();
            button->release(); // 减少引用计数
            g_sharedScene->unschedule("removeButtonKey"); // 取消定时器
            });
    }
   
    // 在这里添加更多逻辑
}
