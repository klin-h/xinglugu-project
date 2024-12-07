#ifndef __ITEMOUT_H_
#define __ITEMOUT_H_
#include "usableItem.h"
#include "Constants.h"
class SoldBox {
private:
	int singleDayProfit = 0;
	Item* itemInput[maxnum];
	int itemnum[maxnum];
	int itemList;
	int numList;

public:
	
	//构造函数
	SoldBox() {
		itemList = listInit;
		numList = listInit;
	}
	
	//把东西放入售卖箱
	bool singleDayInput(Item* itemToSell,int num);
	
	//取出东西
	Item* itemSingleOut();
    
	//每日总结,清空箱子
	int dayProfitOut();
};



#endif

