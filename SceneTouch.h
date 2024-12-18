/****************************************************************
 * Project Name: xinglugu-project
 * File SceneTouch.h
 * File Function: Handle touch events to access tile properties.
 * Author: Gao Wenhao
 * Update Date: 2024.12.9
 * License:
 ****************************************************************/
#ifndef SCENE_TOUCH_H
#define SCENE_TOUCH_H

#include "cocos2d.h"
#include "back.h"
USING_NS_CC;

// �������������ڴ������¼��������Ӧͼ������
bool onTouchBegan(Touch* touch, Event* event, TMXTiledMap* map, backPack* pack);

Vec2 calculateTileCoordinate(const Vec2& touchLocation, TMXTiledMap* map);
#endif // SCENE_TOUCH_H