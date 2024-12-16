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
USING_NS_CC;

//�Ѷ�������������
bool SoldBox::singleDayInput(Item* itemToSell, int num) {
	if (itemToSell->itemtype == ItemType::tool || itemToSell->itemtype == ItemType::null)
		return 0;
	else {
		singleDayProfit += num * itemToSell->moneyToSell();
		itemInput[++itemList] = itemToSell;
		itemnum[++numList] = num;
		return 1;
	}
}

//ȡ������
Item* SoldBox::itemSingleOut() {
	if (itemList < 0) {
		Item* item0 = new Item();
		return item0;
	}
	else {
		Item* list1 = itemInput[itemList];
		singleDayProfit -= itemnum[numList] * itemInput[itemList]->moneyToSell();
		itemList--;
		numList--;
		return list1;
	}
}

//��������
int SoldBox::topNumOut() {
	if (numList < 0) {
		CCLOG("it is empty");
		return 0;
	}
	else
		return itemnum[numList];
}

//������Ʒ
Item* SoldBox::topItemOut() {
	if (numList < 0) {
		CCLOG("it is empty");
		return 0;
	}
	else
		return itemInput[itemList];
}

//ÿ���ܽ�,�������
int SoldBox::dayProfitOut() {
	int DayOut = singleDayProfit;
	singleDayProfit = 0;
	itemList = listInit;
	numList = listInit;
	return DayOut;
}

//�ж��Ƿ�Ϊ��
bool SoldBox::isBoxEmpty() {
	if (numList == listInit)
		return 0;
	else
		return 1;
}