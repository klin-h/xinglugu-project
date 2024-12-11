/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#include "Character.h"

USING_NS_CC;

void Character::stopMoving(Sprite* sprite)
{
	sprite->stopAllActions();
}


void Character::Moving(Sprite* sprite, int direction)
{
	CCLOG("����Character::Moving������ sprite: %p, direction: %d", sprite, direction);
	switch (direction) {
	case 0: {
		sprite->runAction(Walking::createAnimation("Abigail", "f"));
		runAction(MoveTo::create(0.5f, this->getPosition() + Vec2(0, -16)));
		break;
	}
	case 1: {
		sprite->runAction(Walking::createAnimation("Abigail", "b"));
		runAction(MoveTo::create(0.5f, this->getPosition() + Vec2(0, 16)));
		break;
	}
	case 2: {
		sprite->runAction(Walking::createAnimation("Abigail", "l"));
		runAction(MoveTo::create(0.5f, this->getPosition() + Vec2(-16, 0)));
		break;
	}
	case 3: {
		sprite->runAction(Walking::createAnimation("Abigail", "r"));
		runAction(MoveTo::create(0.5f, this->getPosition() + Vec2(16, 0)));
		break;
	}
	}

}

