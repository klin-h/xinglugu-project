/****************************************************************
 * Project Name: xinglugu-project
 * File Name:ItemOut.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
 * License:
 ****************************************************************/
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
	bool singleDayInput(Item* itemToSell, int num);

	//ȡ������
	Item* itemSingleOut();

	int topNumOut();

	Item* topItemOut();

	//ÿ���ܽ�,�������
	int dayProfitOut();

	//�ж��Ƿ�Ϊ��
	bool isBoxEmpty();
};



#endif

