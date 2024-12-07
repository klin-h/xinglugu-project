#include "ItemOut.h"
#include "cocos2d.h"
#include "Constants.h"
USING_NS_CC;

//把东西放入售卖箱
bool SoldBox::singleDayInput(Item* itemToSell, int num) {
	if (itemToSell->itemtype == ItemType::tool || itemToSell->itemtype == ItemType::null)
		return 0;
	else {
		singleDayProfit += num * itemToSell->moneyToSell();
		itemInput[++itemList]=itemToSell;
		itemnum[++numList]=num;
	}
}

//取出东西
Item* SoldBox::itemSingleOut() {
	if (itemList < 0) {
		Item* item0 = new Item();
		return item0;
	}
	else {
		itemInput[itemList]->quantityChange(0,itemnum[numList]-1);
		Item* list1 = itemInput[itemList];
		itemList--;
		numList--;
		return list1;
	}
}

//每日总结,清空箱子
int SoldBox::dayProfitOut() {
	int DayOut = singleDayProfit;
	singleDayProfit = 0;
	itemList = listInit;
	numList = listInit;
	return DayOut;
}