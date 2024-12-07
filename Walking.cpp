/****************************************************************
 * Project Name: xinglugu-project
 * File Name:Walking.cpp
 * File Function: walk
 * Author:Sun Yining
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#include "Walking.h"
#include "cocos2d.h"

USING_NS_CC;


Animate* Walking::createAnimation(const std::string& name, const std::string& direction)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();

	std::string strPlistName = name + "/" + name + ".plist";
	std::string strPhotoName = name + "/" + name + ".png";

	cache->addSpriteFramesWithFile(strPlistName, strPhotoName);
	Vector<SpriteFrame*> frameVec;
	SpriteFrame* frame = nullptr;

	for (int ix = 1; ix <= 4; ix++)
	{
		frame = cache->getSpriteFrameByName(name + direction + Value(ix).asString() + ".png");
		if (frame == nullptr)
		{
			break;
		}
		frameVec.pushBack(frame);
		
	}
	Animation* animation = Animation::createWithSpriteFrames(frameVec, 1.0f / 5, -1);//帧的更换速度为0.2秒
	Animate* animate = Animate::create(animation);
	return animate;
}