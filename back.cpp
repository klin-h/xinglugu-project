/****************************************************************
 * Project Name: xinglugu-project
 * File back.cpp
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.8
 * License:
 ****************************************************************/
#include"back.h"
#include"cocos2d.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;


//背包初始化
void backPack::init() {//初始化
	for (int i = 0; i < backpackCapacity/3; i++) {
		positionIsAccessible[i] = 1;
	}
	for (int i = backpackCapacity / 3; i < backpackCapacity ; i++) {
		positionIsAccessible[i] = 0;
	}

}

//物品转移的开始，选择物品
void backPack::itemPositionChangeOn(bool isLeftKey,int position) {
	if (position < 0 || position >= 36)
		return;
	else {
		if (isLeftKey == 1) {
			numToTransmit = boxNum[position];
			boxNum[position] = 0;
			itemToTransmit = box[position];
			Item* nullitem = new Item( );
			box[position] = nullitem;
		}
		else {
			numToTransmit++;
			boxNum[position]--;
			if (rightKeyCount == 0) {
				itemToTransmit = box[position];
				rightKeyCount++;
			}
			if (boxNum[position] == 0)
			{
				auto nullitem = new Item();
				box[position] = nullitem;
			}
		}
	}
}

//转移的结束，放置
void backPack::itemPositionChangeOff(int position) {
	if (position < 0 || position >= 36)
		return;
	else {
		rightKeyCount = 0;
		Item* sub1 = box[position];
		int sub2 = boxNum[position];
		box[position] = itemToTransmit;
		boxNum[position] = numToTransmit;
		itemToTransmit = sub1;
		numToTransmit = sub2;
	}
}

void backPack::itemChangeReset() {
	Item* item0 = new Item();
	itemToTransmit = item0;
	numToTransmit = 0;
}
//返回特定位置的物品
Item* backPack::bottomSelect(int NoX) {
	if (NoX < 0 || NoX >= backpackCapacity)
	{
		Item* itemnull = new Item();
		return itemnull;
	}
	else {
		return box[NoX];
	}
}

//背包升级
bool backPack::upgrade() {
	if (grade == 0)
	{
		grade++;
		for (int i = backpackCapacity / 3; i < backpackCapacity*2 / 3; i++) {
			positionIsAccessible[i] = 1;
		}
		return 1;
	}
	else {
		if (grade == 1)
		{
			grade++;
			for (int i = backpackCapacity * 2 / 3; i < backpackCapacity ; i++) {
				positionIsAccessible[i] = 1;
			}
			return 1;
		}
		else {
			return 0;
		}
	}
}

//物品的添加
bool backPack::itemAdd(Item* itemIn) {
	int ring = 0,posi=0;
	bool isAlreadyInside = 0, isAlreadyFull = 0;
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (box[i]->name == itemIn->name) {
			isAlreadyInside = 1;
			posi = i;
			break;
		}
	}
	if (isAlreadyInside == 1) {
		boxNum[posi]+=itemIn->quantity;
	}
	else {
		while (boxNum[ring] != 0) {
			ring++;
		}
		if (ring < grade * (backpackCapacity / 3) + backpackCapacity / 3) {
			box[ring] = itemIn;
			boxNum[ring] += itemIn->quantity;
		}
		else
			isAlreadyFull = 1;
	}
	if (isAlreadyFull == 0)
		return 0;
	else
		return 1;
}

//判断是否有指定数量的指定物品
bool backPack::matchJudge(Item* itemToMatch, int numToMatch) {
	bool isMatchAble = 0;
	int ring = 0;
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (boxNum[i] == 0)
			continue;
		else {
			if (box[i]->name == itemToMatch->name)
			{
				if(boxNum[i]>=numToMatch)
					isMatchAble = 1;
			}
		}
	}
	if (isMatchAble == 0)
		return 0;
	else
		return 1;
}

//物品减少
void backPack::itemReduce(Item* itemToMatch, int numToMatch) {
	for (int i = 0; i < grade * (backpackCapacity / 3) + backpackCapacity / 3; i++) {
		if (box[i]->name == itemToMatch->name)
		{
			boxNum[i] -= numToMatch;
		 }
	}
}

//钱的增减
//ways：1--减 0--增
void backPack::moneyChange(int addAmount,bool ways) {
	if (ways == wayOfAdd)
		money += addAmount;
	else
		money -= addAmount;
}

//返回钱的值
int backPack::moneyOut() {
	return money;
}
