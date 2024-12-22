/****************************************************************
 * Project Name: xinglugu-project
 * File initAnimalScene.h
 * File Function: init Animal on Scene
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#ifndef __WALKING_CHARACTER_H__
#define __WALKING_CHARACTER_H__

#include "cocos2d.h"
#include "Cow.h"
#include "Pig.h"
#include "Constants.h"

USING_NS_CC;
void setupAnimal(Scene* scene);
void cleanupAnimals(Scene* scene, std::vector<Animal*>& animalGrid);
#endif // __WALKING_CHARACTER_H__
