#ifndef __BACKPHOTO_H_
#define __BACKPHOTO_H_

#include "MainScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "Constants.h"

void listenSet(Scene* scene, const cocos2d::Size& visibleSize, float tileHeight, float tileWidth);

void backPhoto(Scene* scene, backPack* pack1, EventDispatcher* _eventDispatcher);

void ventorySet();

void inventory(Scene* scene, backPack* pack1, const Size& visibleSize, Vec2 origin);

void backItemAddDisplay(int no);
#endif // !__BACKPHOTO_H_
