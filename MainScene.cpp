/****************************************************************
 * Project Name: xinglugu-project
 * File Name:MainScene.cpp
 * File Function: init the Scene
 * Author:All
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
#include "SceneTouch.h"
#include "Constants.h"
USING_NS_CC;
USING_NS_CC::ui;


//背包创建
backPack* pack1 = backPack::create();

Scene* MainScene::createScene() {
    return MainScene::create();
}


bool MainScene::init() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
  // 加载 TMX 地图

    auto glview = Director::getInstance()->getOpenGLView();
    glview->setDesignResolutionSize(Constants::kMapWidth, Constants::kMapLength, ResolutionPolicy::SHOW_ALL);

    // 确保内容缩放因子为 1.0
    Director::getInstance()->setContentScaleFactor(1.0f);

    // 创建并添加地图
    auto map = TMXTiledMap::create("nf.tmx");
    map->setAnchorPoint(Vec2(0, 0)); // 左下角对齐
    map->setPosition(Vec2(0, 0));
    map->setScale(1.0f); // 确保地图未被缩放
    this->addChild(map, Constants::MAP_BACKGROUND_LAYER_Z_ORDER, "map");

    if (!map) {
        CCLOG("Failed to load TMX map.tmx");
        return false;
    }

    
    inventory(this, pack1, visibleSize, origin);

    //setupAnimal(this);// 创建动物
    
    //setupWalkingCharacter(visibleSize, origin);

    auto touchListener = EventListenerTouchOneByOne::create();

    
   // backPack* localPack = pack1;
    touchListener->onTouchBegan = [map](Touch* touch, Event* event) {
        return onTouchBegan(touch, event, map, pack1);
        };

    // 将监听器添加到事件分发器中
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    return true;
}

//单选按钮集合


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




