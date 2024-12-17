/****************************************************************
 * Project Name: xinglugu-project
 * File Name:Walking.h
 * File Function: walk
 * Author:Sun Yining
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#ifndef __WALKING_H__
#define __WALKING_H__

#include "cocos2d.h"

using namespace cocos2d;

class Walking
{
public:

	/* ������ɫ��������ʱ�Ķ��� */
	static Animate* createAnimation(const std::string& name, const std::string& direction);
	static Action* Walking::walkingContently(Sprite* targetSprite, const std::string& name, const std::string& direction);
	
};

#endif
