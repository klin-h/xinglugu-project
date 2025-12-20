/****************************************************************
 * Project Name: xinglugu-project
 * File Name:MainScene.cpp
 * File Function: init the Scene
 * Author:All
 * Update Date:2024.12.3
 * License:
 ****************************************************************/

#include "MainScene.h"
#include "simpleaudioengine.h"
#include "Cow.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "backPhoto.h"
#include "SceneTouch.h"
#include "Constants.h"
#include"Fishing.h"
#include "GlobalVariables.h"
#include "ServiceLocator.h"


USING_NS_CC;
USING_NS_CC::ui;
using namespace CocosDenshion;

// 注意: 这些全局变量现在已被ServiceLocator管理
// 保留这些以支持向后兼容
cocos2d::Scene* g_sharedScene = nullptr;
cocos2d::TMXTiledMap* g_sharedTMXone = nullptr;
backPack* pack1 = nullptr;  // 全局背包指针

Scene* MainScene::createScene() {
    return MainScene::create();
}


bool MainScene::init() {

    CCLOG("Initializing MainScene...");
    initScheduler();// 在 init 中添加初始化逻辑，确保定时器能正确设置

    auto audio = SimpleAudioEngine::getInstance();
    // set the background music and continuously play it.
    audio->playBackgroundMusic("background.mp3", true);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 加载 TMX 地图

    auto glview = Director::getInstance()->getOpenGLView();
    glview->setDesignResolutionSize(Constants::kMapWidth, Constants::kMapLength, ResolutionPolicy::SHOW_ALL);

    // 确保内容缩放因子为 1.0
    Director::getInstance()->setContentScaleFactor(1.0f);

    // =============== 使用ServiceLocator管理服务 ===============
    // 注册场景服务
    ServiceLocator::getInstance().registerScene(this);
    
    // 为向后兼容性维护全局变量
    g_sharedScene = this;

    // 创建地图
    auto map = TMXTiledMap::create("farm.tmx");  // 假设主地图文件名
    if (!map) {
        CCLOG("Failed to load TMX map.tmx");
        return false;
    }
    
    // 注册所有地图
    ServiceLocator::getInstance().registerTMXMap("map1", map);
    ServiceLocator::getInstance().setCurrentTMXMap("map1");
    g_sharedTMXone = map;  // 向后兼容
    
    // 创建和注册其他地图
    auto map2 = TMXTiledMap::create("forest.tmx");
    if (map2) {
        ServiceLocator::getInstance().registerTMXMap("map2", map2);
    }
    
    auto map3 = TMXTiledMap::create("mine.tmx");
    if (map3) {
        ServiceLocator::getInstance().registerTMXMap("map3", map3);
    }
    
    auto map4 = TMXTiledMap::create("festival.tmx");
    if (map4) {
        ServiceLocator::getInstance().registerTMXMap("map4", map4);
    }
    
    CCLOG("Map Anchor Point: %f, %f", map->getAnchorPoint().x, map->getAnchorPoint().y);
    CCLOG("Map Position: %f, %f", map->getPosition().x, map->getPosition().y);
    CCLOG("Map Scale: %f", map->getScale());
    CCLOG("Map Content Size: %f x %f", map->getContentSize().width, map->getContentSize().height);

    map->setAnchorPoint(Vec2(0, 0)); // 左下角对齐
    map->setPosition(Vec2(0, 0));
    map->setScale(Constants::kScale); // 确保地图未被缩放

    this->addChild(map, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE, "map01");
    if (map2) this->addChild(map2, Constants::MAP_BACKGROUND_LAYER_Z_BASIC, "map02");
    if (map3) this->addChild(map3, Constants::MAP_BACKGROUND_LAYER_Z_MIDDLE, "map03");
    if (map4) this->addChild(map4, Constants::MAP_BACKGROUND_LAYER_Z_MIDDLE, "map04");

    if (map) {
        auto mapSize = map->getMapSize();
        auto tileSize = map->getTileSize();

        CCLOG("Map Size: %f x %f, Tile Size: %f x %f", mapSize.width, mapSize.height, tileSize.width, tileSize.height);

        auto layer = map->getLayer("someLayerName");
        if (layer) {
            CCLOG("Successfully accessed layer.");
        }
        else {
            CCLOG("Failed to access layer. Map might not be fully initialized.");
        }
    }


    // =============== 初始化背包服务 ===============
    if (pack1 == nullptr) {
        pack1 = backPack::create();
        ServiceLocator::getInstance().registerBackpack(pack1);
    }
    
    inventory(this, pack1, origin);

    auto layerfish = Layer::create();
    map->addChild(layerfish,3);
    // 添加钓鱼按钮
    MainScene::addFishingButtonToScene(layerfish, visibleSize);

 
    auto touchListener = EventListenerTouchOneByOne::create();

    touchListener->onTouchBegan = [map](Touch* touch, Event* event) {
        return onTouchBegan(touch, event, map, pack1);
        };
    //npc1可以用键盘控制，可看作玩家

    auto npc1 = NPC_1::create();
    if (npc1) {
        auto scene = ServiceLocator::getInstance().getScene();
        scene->addChild(npc1, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        // 通过创建好的npc1Obj对象来调用testAddNPC_1函数
        npc1->testAddNPC_1(visibleSize, origin, map, this);
        CCLOG("NPC_1 position: (%f, %f)", npc1->getPosition().x, npc1->getPosition().y);
    }


    auto npc3 = NPC_3::create();
    if (npc3) {
        auto scene = ServiceLocator::getInstance().getScene();
        scene->addChild(npc3, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        Vec2 pos;
        pos.x = visibleSize.width / 4 - 8;
        pos.y = visibleSize.height / 2 - 8;
        npc3->testAddNPC_3(visibleSize, origin, "Harvey", pos);
    }
    auto npc2 = NPC_3::create();
    if (npc2) {
        auto map1 = ServiceLocator::getInstance().getTMXMap("map1");
        if (map1) map1->addChild(npc2, Constants::MAP_BACKGROUND_LAYER_Z_ORDER + 10);
        Vec2 pos;
        pos.x = Constants::Haleyinmap_X;
        pos.y = Constants::Haleyinmap_Y;
        npc2->testAddNPC_3(visibleSize, origin, "Haley", pos);


    }

    // 将监听器添加到事件分发器中
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    updateProgressBars(this, g_time);
}

//单选按钮集合

void MainScene::onEnter() {
    Scene::onEnter();
    auto backpack = ServiceLocator::getInstance().getBackpack();
    backPhoto(this, backpack, _eventDispatcher);
    Item* newItem = terial::create("wood");
    if (backpack) {
        backpack->itemAdd(newItem, 1);
    }
}


void MainScene::addFishingButtonToScene(Layer* layer, const Size& visibleSize) {
    // 创建钓鱼按钮
    auto fishingButton = MenuItemImage::create("fishing.png", "fishing.png",
        CC_CALLBACK_1(MainScene::onFishingButtonClicked, this));
    fishingButton->setPosition(32, visibleSize.height / 2); // 将按钮放在

    // 创建菜单并将按钮添加到菜单中
    auto menu = Menu::create(fishingButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu);
}

void MainScene::onFishingButtonClicked(Ref* sender) {
    // 创建钓鱼层
    auto fishingLayer = FishingLayer::createLayer();

    // 获取当前场景并将钓鱼层添加到场景中
    auto runningScene = Director::getInstance()->getRunningScene();
    if (runningScene) {
        runningScene->addChild(fishingLayer, 3); // 确保层级为3，使其显示在其他元素上方
    }
    else {
        CCLOG("Failed to get running scene.");
    }
}

void MainScene::initScheduler() {
    // 设定定时器，每秒调用一次 update 函数
    schedule(CC_SCHEDULE_SELECTOR(MainScene::update), 1.0f, kRepeatForever, 0.0f);
}

void MainScene::update(float dt) {
    // 正确调用外部的 update 函数
    ::update(dt);  // 外部定义的 update 函数
}
