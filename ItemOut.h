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
	
	//���캯��
	SoldBox() {
		itemList = listInit;
		numList = listInit;
	}
	
	//�Ѷ�������������
	bool singleDayInput(Item* itemToSell,int num);
	
	//ȡ������
	Item* itemSingleOut();
    
	//ÿ���ܽ�,�������
	int dayProfitOut();
};



#endif

