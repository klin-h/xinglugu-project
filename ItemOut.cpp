/****************************************************************
 * Project Name: xinglugu-project
 * File Name:ItemOut.cpp
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
 * License:
 ****************************************************************/
#include "ItemOut.h"
#include "cocos2d.h"
#include "Constants.h"
#include "Timer.h"
USING_NS_CC;

//把东西放入售卖箱
bool SoldBox::singleDayInput(Item* itemToSell, int num) {

	if (itemToSell->itemtype == ItemType::tool || itemToSell->itemtype == ItemType::null)
		return 0;
	else {
		Timer1* season = new Timer1;
		if(itemToSell->itemtype==ItemType::fish){
			Fish* fish = Fish::create(itemToSell->nameBack());
			singleDayProfit += num * fish->moneyToSell(season->getSeason());
		}
		if (itemToSell->itemtype == ItemType::seed) {
			Seed* seed = Seed::create(itemToSell->nameBack());
			singleDayProfit += num * seed->moneyToSell(season->getSeason());
		}
		if (itemToSell->itemtype == ItemType::fruit) {
			Fruit* fruit = Fruit::create(itemToSell->nameBack());
			singleDayProfit += num * fruit->moneyToSell(season->getSeason());
		}
		if (itemToSell->itemtype == ItemType::animalproduct) {
			AnimalProduct* animal = AnimalProduct::create(itemToSell->nameBack());
			singleDayProfit += num * animal->moneyToSell();
		}
		if (itemToSell->itemtype == ItemType::terial) {
			terial* animal = terial::create(itemToSell->nameBack());
			singleDayProfit += num * animal->moneyToSell();
		}
		itemInput[++itemList] = itemToSell;
		itemnum[++numList] = num;
		return 1;
	}
}

//取出东西
Item* SoldBox::itemSingleOut() {
	if (itemList < 0) {
		Item* item0 = new Item();
		return item0;
	}
	else {
		Item* list1 = itemInput[itemList];
		Timer1* season = new Timer1;
		if (itemInput[itemList]->itemtype == ItemType::fish) {
			Fish* fish = Fish::create(itemInput[itemList]->nameBack());
			singleDayProfit -= itemnum[numList] * fish->moneyToSell(season->getSeason());
		}
		if (itemInput[itemList]->itemtype == ItemType::seed) {
			Seed* seed = Seed::create(itemInput[itemList]->nameBack());
			singleDayProfit -= itemnum[numList] * seed->moneyToSell(season->getSeason());
		}
		if (itemInput[itemList]->itemtype == ItemType::fruit) {
			Fruit* fruit = Fruit::create(itemInput[itemList]->nameBack());
			singleDayProfit -= itemnum[numList] * fruit->moneyToSell(season->getSeason());
		}
		if (itemInput[itemList]->itemtype == ItemType::animalproduct) {
			AnimalProduct* animal = AnimalProduct::create(itemInput[itemList]->nameBack());
			singleDayProfit -= itemnum[numList] * animal->moneyToSell();
		}
		itemList--;
		numList--;
		return list1;
	}
}

//顶部数量
int SoldBox::topNumOut() {
	if (numList < 0) {
		CCLOG("it is empty");
		return 0;
	}
	else
		return itemnum[numList];
}

//顶部物品
Item* SoldBox::topItemOut() {
	if (numList < 0) {
		CCLOG("it is empty");
		return 0;
	}
	else
		return itemInput[itemList];
}

//每日总结,清空箱子
int SoldBox::dayProfitOut() {
	int DayOut = singleDayProfit;
	singleDayProfit = 0;
	itemList = listInit;
	numList = listInit;
	return DayOut;
}

//判断是否为空
bool SoldBox::isBoxEmpty() {
	if (numList == listInit)
		return 0;
	else
		return 1;
}
