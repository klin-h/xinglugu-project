/****************************************************************
 * Project Name: xinglugu-project
 * File Name:MainScene.h
 * File Function: Main class define 
 * Author: All
 * Update Date:2024.12.3
 * License:
 ****************************************************************/

#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Land.h"
#include "SceneObject.h"
#include "WalkingCharacter.h"
#include "Constants.h"
#include"initAnimalScene.h"
#include "NPC_1.h"
#include "NPC_3.h"
#include "startScene.h"
class MainScene : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void onEnter();
   
   
    void setupWalkingCharacter(const cocos2d::Size& visibleSize, cocos2d::Vec2 origin);
    // 初始化触摸监听器
    void MainScene::addFishingButtonToScene(Layer* layer, const Size& visibleSize);
    void MainScene::onFishingButtonClicked(Ref* sender);
    // 实现 CREATE_FUNC 宏
    CREATE_FUNC(MainScene);

    //bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);// 触摸事件监听器

    cocos2d::EventListenerCustom* interactListener;

private:
    std::vector<Land*> landGrid; 
    std::vector<SceneObject*> objectGrid; 
};

#endif // __MAIN_SCENE_H__
