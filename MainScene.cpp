/****************************************************************
 * Project Name: xinglugu-project
 * File Name:MainScene.cpp
 * File Function: init the Scene
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/


#include "MainScene.h"
//#include "SimpleAudioEngine.h"
#include "Cow.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "backPhoto.h"
#include "Constants.h"
USING_NS_CC;
USING_NS_CC::ui;


//背包创建
backPack* pack1 = backPack::create();

Scene* MainScene::createScene() {
    return MainScene::create();
}


bool MainScene::init() {
    if (!Scene::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // 加载 TMX 地图
   
    //auto map = TMXTiledMap::create("farm_map03.tmx");
    auto map = TMXTiledMap::create("nf.tmx");
    

    if (!map) {
        CCLOG("Failed to load TMX file:farm_map01.tmx");
        return false;
    }
   
    // 将地图添加到场景
    this->addChild(map, Constants:: MAP_BACKGROUND_LAYER_Z_ORDER, "map");

    // 设置地图位置（让地图居中显示）
   
    map->setPosition(Vec2(
        (visibleSize.width - map->getContentSize().width) / 2,
        (visibleSize.height - map->getContentSize().height) / 2
    ));

    inventory(this,pack1,visibleSize, origin);

    setupAnimal(this);// 创建动物

    //setupWalkingCharacter(visibleSize, origin);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}


void MainScene::onEnter() {
    Scene::onEnter();
    backPhoto(this,pack1,_eventDispatcher);
}



void MainScene::setupWalkingCharacter(const Size& visibleSize, Vec2 origin) {
  
    // 创建WalkingCharacter实例并添加到当前场景中
    auto walkingCharacterNode = WalkingCharacter::create();
    walkingCharacterNode->setVisible(true);  // 确保节点可见
    this->addChild(walkingCharacterNode);

    // 通过接口设置WalkingCharacter的图片路径，这里先用一只兔子测试，可根据实际需求修改
    walkingCharacterNode->setImagePath("rabbit_test.png");
    //walkingCharacterNode->setImagePath("Cow_move.png");
    // 直接使用之前已经定义好的visibleSize和origin变量
    // 获取画面中心位置坐标
    Vec2 centerPosition = Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // 设置WalkingCharacter的位置为画面中心位置
    walkingCharacterNode->setPosition(centerPosition);

    // 获取角色精灵（假设WalkingCharacter类中有获取精灵的方法）
    auto characterSprite = walkingCharacterNode->getCharacterSprite();
        if (characterSprite) {
      // 创建移动动作，让角色先向右移动200像素，用时3秒
        auto moveRightAction = MoveBy::create(3.0f, Vec2(200, 0));
        // 再向下移动100像素，用时2秒
        auto moveDownAction = MoveBy::create(2.0f, Vec2(0, -100));
        // 创建动作序列，先执行向右移动，再执行向下移动
        auto sequenceAction = Sequence::create(moveRightAction, moveDownAction, nullptr);
        // 让角色精灵循环执行该动作序列，实现循环移动
        characterSprite->runAction(RepeatForever::create(sequenceAction));

    }
}

bool MainScene::onTouchBegan(Touch* touch, Event* event) {
    // 获取触摸点的屏幕坐标
    Vec2 touchLocation = touch->getLocation();

    // 获取 TMX 地图
    auto node = this->getChildByName("map");
    auto map = dynamic_cast<cocos2d::TMXTiledMap*>(node); // 动态类型转换

   
    if (!map) {
        CCLOG("TMX map not found!");
        return false;
    }

    // 将触摸点从屏幕坐标转换为地图节点坐标
    Vec2 mapLocation = map->convertToNodeSpace(touchLocation);

    // 获取图块的网格坐标（基于图块尺寸）
    int tileX = static_cast<int>(mapLocation.x / map->getTileSize().width);
    int tileY = static_cast<int>((map->getMapSize().height * map->getTileSize().height - mapLocation.y) / map->getTileSize().height);

    // 检查坐标是否超出地图范围
    if (tileX < 0 || tileX >= map->getMapSize().width || tileY < 0 || tileY >= map->getMapSize().height) {
        CCLOG("Touch is outside the map bounds!");
        return false;
    }

    // dubug 工具，log当前tmx中包括的所有图层名字，解开注释就能用
  /*  auto allLayers = map->getChildren();
    for (const auto& child : allLayers) {
        auto layer = dynamic_cast<TMXLayer*>(child);
        if (layer) {
            CCLOG("Found layer: %s", layer->getLayerName().c_str());
        }
    }*/

    //*****************这里tmx文件里面读不到"soil"？*****************
    
    //遍历图块层，注意这里有顺序要求，先遍历的在前  
    //auto layer = map->getLayer("soil");//获取图块层, "soil" 这里添加图层名
    //if (!layer) {
    //    CCLOG("Layer 'soil' not found!");
    //    return false;
    //}
    //// 获取图块的 GID
    //int gid = layer->getTileGIDAt(Vec2(tileX, tileY));// 获取图块的 GID,若无图块，返回0
    //if (gid > 0) {
    //    CCLOG("Touched tile GID: %d", gid); 
    //    return true;     
    //}
    //else {
    //    CCLOG("No tile at this location.");
    //}
   
    auto layer = map->getLayer("basic");
    if (!layer) {
        CCLOG("Layer 'basic' not found!");
        return false;
    }
   
    int gid = layer->getTileGIDAt(Vec2(tileX, tileY));
    if (gid > 0) {
        CCLOG("Touched tile GID: %d", gid);
        /****************************************************************
       // 添加具体交互逻辑，通过上面得到的GID访问土块属性，当前只输出GID
       如：
      //auto properties = map->getPropertiesForGID(gid).asValueMap();// 获取图块的自定义属性
      //CCLOG("Touched tile GID: %d", gid);
      //if (!properties.empty()) {
      //    CCLOG("Tile properties:");
      //    for (const auto& property : properties) {
      //        CCLOG("  %s: %s", property.first.c_str(), property.second.asString().c_str());
      //    }
      //}
      //else {
      //    CCLOG("No properties for this tile.");
      //}
     ****************************************************************/
        return true;
    }
    else {
        CCLOG("No tile at this location.");
    }

    return true;
}


