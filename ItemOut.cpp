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
		itemInput[++itemList]=itemToSell;
		itemnum[++numList]=num;
	}
}

//ȡ������
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

//ÿ���ܽ�,�������
int SoldBox::dayProfitOut() {
	int DayOut = singleDayProfit;
	singleDayProfit = 0;
	itemList = listInit;
	numList = listInit;
	return DayOut;
}