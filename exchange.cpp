/****************************************************************
 * Project Name: xinglugu-project
 * File exchange.cpp
 * File Function:
 * Author:Li Siyuan
 * Update Date:2024.12.4
 * License:
 ****************************************************************/
#include"exchange.h"
#include"cocos2d.h"
#include"back.h"
#include"usableItem.h"
#include"Constants.h"
#include"backPhoto.h"
USING_NS_CC;
using namespace Constants;
//�ϳ�̨����

//��Ʒ��Ӧ����
//0--ľ��
//1--ľդ��
//2--����
//3--����
//4--ľ��
//5--ʯ��
//6--���
//7--��������
//8--����
//9--��¯
//10--ʯ��
//11--ˮ��ͷ 
//12--����ʪ��
//13--������
//14--���
//15--ӣ��ը��
//16--����
//17--����
//18--����Ұ��
//����Ʒ�Ƿ�ɺϳɵ��ж�
bool craftTable::changeForCraft(backPack* Back,int itemToMake) {
	switch (itemToMake) {
	case 0://ľ��
	{
		Item* WoodenSign = terial::create("wood");
		if (Back->matchJudge(WoodenSign, amountOfWoodForWoodenSign))
			return 1;
		else
			return 0;
		break;
	}
	case 1://ľդ��
	{
		Item* WoodFence = terial::create("wood");
		if (Back->matchJudge(WoodFence, amountOfWoodForWoodFence))
			return 1;
		else
			return 0;
		break;
	}
	case 2://����
	{
		Item* Gate = terial::create("wood");
		if (Back->matchJudge(Gate, amountOfWoodForGate))
			return 1;
		else
			return 0;
		break;
	}
	case 3://����
	{
		Item* GrassStarter = terial::create("fibre");
		if (Back->matchJudge(GrassStarter, amountOfFibreForGrassStarter))
			return 1;
		else
			return 0;
		break;
	}
	case 4://ľ��
	{
		Item* WoodPath = terial::create("wood");
		if (Back->matchJudge(WoodPath, amountOfWoodForWoodPath))
			return 1;
		else
			return 0;
		break;
	}
	case 5://ʯ��
	{
		Item* CobblestonePath = terial::create("stone");
		if (Back->matchJudge(CobblestonePath, amountOfStoneForCobblestonePath))
			return 1;
		else
			return 0;
		break;
	}
	case 6://���
	{
		Item* Torch1 = terial::create("wood");
		Item* Torch2 = terial::create("sap");
		if (Back->matchJudge(Torch1, amountOfWoodForTorch) && Back->matchJudge(Torch2, amountOfSapForTorch))
			return 1;
		else
			return 0;
		break;
	}
	case 7://��������
	{
		Item* BasicFertilizer = terial::create("sap");
		if (Back->matchJudge(BasicFertilizer, amountOfSapForBasicFertilizer))
			return 1;
		else
			return 0;
		break;
	}
	case 8://����
	{
		Item* Chest = terial::create("wood");
		if (Back->matchJudge(Chest, amountOfWoodForChest))
			return 1;
		else
			return 0;
		break;
	}
	case 9://��¯
	{
		Item* Furnace1 = terial::create("stone");
		Item* Furnace2 = terial::create("copperore");
		if (Back->matchJudge(Furnace1, amountOfStoneForFurnace) && Back->matchJudge(Furnace2, amountOfCopperOreForFurnace))
			return 1;
		else
			return 0;
		break;
	}
	case 10://ʯ��
	{
		Item* StoneSign = terial::create("stone");
		if (Back->matchJudge(StoneSign, 25))
			return 1;
		else
			return 0;
		break;
	}
	case 11://ˮ��ͷ 
	{
		Item* Sprinkle1 = terial::create("ironbar");
		Item* Sprinkle2 = terial::create("copperbar");
		if (Back->matchJudge(Sprinkle1, amountOfIronBarForSprinkle) && Back->matchJudge(Sprinkle2, amountOfCopperBarForSprinkle))
			return 1;
		else
			return 0;
		break;
	}
	case 12://����ʪ��
	{
		Item* BasicRetainingSoil = terial::create("stone");
		if (Back->matchJudge(BasicRetainingSoil, 2))
			return 1;
		else
			return 0;
		break;
	}
	case 13://������
	{
		Item* ScareCrow1 = terial::create("wood");
		Item* ScareCrow2 = terial::create("coal");
		Item* ScareCrow3 = terial::create("fibre");
		if (Back->matchJudge(ScareCrow1, amountOfWoodForScareCrow) && Back->matchJudge(ScareCrow2, amountOfCoalForScareCrow) && Back->matchJudge(ScareCrow3, amountOfFibreForScareCrow))
			return 1;
		else
			return 0;
		break;
	}
	case 14://���
	{
		Item* Bait = AnimalProduct::create("bugmeat");
		if (Back->matchJudge(Bait, amountOfBugmeatForBait))
			return 1;
		else
			return 0;
		break;
	}
	case 15://ӣ��ը��
	{
		Item* CherryBomb1 = terial::create("coal");
		Item* CherryBomb2 = terial::create("copperore");
		if (Back->matchJudge(CherryBomb1, 2) && Back->matchJudge(CherryBomb2, 4))
			return 1;
		else
			return 0;
		break;
	}
	case 16://����
	{
		Item* StairCase = terial::create("stone");
		if (Back->matchJudge(StairCase, 99))
			return 1;
		else
			return 0;
		break;
	}
	case 17://����
	{
		Item* CampFire1 = terial::create("stone");
		Item* CampFire2 = terial::create("wood");
		Item* CampFire3 = terial::create("fibre");
		if (Back->matchJudge(CampFire1, 10) && Back->matchJudge(CampFire2, 10) && Back->matchJudge(CampFire3, 10))
			return 1;
		else
			return 0;
		break;
	}
	case 18://����Ұ��
	{
		Item* SpringSeed1 = Fruit::create("wildhorseradish");
		Item* SpringSeed2 = Fruit::create("daffodil");
		Item* SpringSeed3 = Fruit::create("leek");
		Item* SpringSeed4 = Fruit::create("Dandelion");

		if (Back->matchJudge(SpringSeed1, 1) && Back->matchJudge(SpringSeed2, 1) && Back->matchJudge(SpringSeed3, 1) && Back->matchJudge(SpringSeed4, 1))
			return 1;
		else
			return 0;
		break;
	}
	default:
		break;
	}
}

//�ϳ���Ʒ
Item* craftTable::getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0:
	{
		Item* WoodenSign = Tool::create("woodensign");
		return WoodenSign;
		break;
	}
	case 1:
	{
		Item* WoodFence = Tool::create("woodfence");
		return WoodFence;
		break;
	}
	case 2:
	{
		Item* Gate = Tool::create("gate");
		return Gate;
		break;
	}
	case 3:
	{
		Item* GrassStarter = Tool::create("grassstarter");
		return GrassStarter;
		break;
	}
	case 4:
	{
		Item* WoodPath = Tool::create("woodpath");
		return WoodPath;
		break;
	}
	case 5:
	{
		Item* CobblestonePath = Tool::create("cobblestonepath");
		return CobblestonePath;
		break;
	}
	case 6:
	{
		Item* Torch = Tool::create("torch");
		return Torch;
		break;
	}
	case 7:
	{
		Item* BasicFertilizer = Tool::create("basicfertilizer");
		return BasicFertilizer;
		break;
	}
	case 8:
	{
		Item* Chest = Tool::create("chest");
		return Chest;
		break;
	}
	case 9:
	{
		Item* Furnace = Tool::create("furnace");
		return Furnace;
		break;
	}
	case 10:
	{
		Item* StoneSign = Tool::create("stonesign");
		return StoneSign;
		break;
	}
	case 11:
	{
		Item* Sprinkle = Tool::create("sprinkle");
		return Sprinkle;
		break;
	}
	case 12:
	{
		Item* BasicRetainingSoil = Tool::create("basicretainingsoil");
		return BasicRetainingSoil;
		break;
	}
	case 13:
	{
		Item* ScareCrow = Tool::create("scarecrow");
		return ScareCrow;
		break;
	}
	case 14:
	{
		Item* Bait = Tool::create("bait");
		return Bait;
		break;
	}
	case 15:
	{
		Item* CherryBomb = Tool::create("cherrybomb");
		return CherryBomb;
		break;
	}
	case 16:
	{
		Item* StairCase = Tool::create("staircase");
		return StairCase;
		break;
	}
	case 17:
	{
		Item* CampFire = Tool::create("campfire");
		return CampFire;
		break;
	}
	case 18:
	{
		Item* SpringSeed = Tool::create("springseed");
		return SpringSeed;
		break;
	}
	default:
		Item* SpringSeed = Tool::create("init");
		return SpringSeed;
		break;
	}
}

//Pierre�̵겿��

//��Ʒ��Ӧ����
// season 1��
//   0--�����
//   1--�ඹ
//   2--��Ҭ��
//   3--����
//   4--��������
//   5--����
//   6--����ʿ
//   7--����
//   8--����  
//   9--����
//   10--�����䷽
//   11--��
//   12--�����
//   13--����
//   14--��
//   15--��
//   16--��������
//   17--�߼�����
//   18--������ʪ����
//   19--�߼���ʪ����
//   20--ӣ������
//   21--��������
//   22--��������
//   23--��������
//   24--ʯ������
//   25--ƻ������
//   26--����
// season 2��
//   0--���
//   1--������
//   2--��ݮ
//   3--����
//   4--С��
//   5--�ܲ�
//   6--������
//   7--�ļ���Ƭ
//   8--ơ�ƻ�
//   9--����
//   10--���տ�
//   11--��Ҷ���Ĳ�
//   12--����
//   13--�����䷽
//   14--��
//   15--�����
//   16--����
//   17--��
//   18--��
//   19--��������
//   20--�߼�����
//   21--������ʪ����
//   22--�߼���ʪ����
//   23--ӣ������
//   24--��������
//   25--��������
//   26--��������
//   27--ʯ������
//   28--ƻ������
//   29--����
// // season 3��
//   0--����
//   1--����
//   2--�Ϲ�
//   3--С�ײ�
//   4--ɽҩ
//   5--��Խݮ
//   6--���տ�
//   7--õ������
//   8--�Ȳ�
//   9--����
//   10--С��
//   11--��
//   12--����
//   13--�����䷽
//   14--��
//   15--�����
//   16--����
//   17--��
//   18--��
//   19--��������
//   20--�߼�����
//   21--������ʪ����
//   22--�߼���ʪ����
//   23--ӣ������
//   24--��������
//   25--��������
//   26--��������
//   27--ʯ������
//   28--ƻ������
//   29--����
//���Ƿ��������ж�
bool Pierre::isAffordable(backPack* Back, int itemToMake,int season) {
	switch (season) {
	case 1:
		switch (itemToMake) {
			case 0://Parsnip�����
				if (Back->moneyOut() >= parsnipseed1)
					return 1;
				else
					return 0;
			case 1://GreenBean�ඹ
				if (Back->moneyOut() >= greenbeanseed1)
					return 1;
				else
					return 0;
			case 2://cauliflower��Ҭ��
				if (Back->moneyOut() >= cauliflowerseed1)
					return 1;
				else
					return 0;
			case 3://potato����
				if (Back->moneyOut() >= potatoseed1)
					return 1;
				else
					return 0;
			case 4://Tulip bulbs��������
				if (Back->moneyOut() >= tulipbulbsseed1)
					return 1;
				else
					return 0;
			case 5://cabbage����
				if (Back->moneyOut() >= cabbageseed1)
					return 1;
				else
					return 0;
			case 6://Blue Jazz ����ʿ
				if (Back->moneyOut() >= bluejazzseed1)
					return 1;
				else
					return 0;
			case 7://Garlic����
				if(Back->moneyOut() >= garlicseed1)
					return 1;
				else
					return 0;
			case 8://rice seedling����
				if (Back->moneyOut() >= riceseedlingseed1)
					return 1;
				else
					return 0;
			case 9://grass seed����
				if (Back->moneyOut() >= grassseed1)
					return 1;
				else
					return 0;
			case 10://grass seed formulation�����䷽
				if (Back->moneyOut() >= 5)
					return 1;
				else
					return 0;
			case 11://sugar ��
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 12://barley flour �����
				if (Back->moneyOut() >= 25)
					return 1;
				else
					return 0;
			case 13://rice ����
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 14://oil ��
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 15://vinegar ��
				if (Back->moneyOut() >= 15)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer��������
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer�߼�����
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil������ʪ����
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil�߼���ʪ����
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 20://Cherry saplingsӣ������
				if (Back->moneyOut() >= cherrysaplings1)
					return 1;
				else
					return 0;
			case 21://Apricot saplings��������
				if (Back->moneyOut() >= apricotsaplings1)
					return 1;
				else
					return 0;
			case 22://Orange saplings��������
				if (Back->moneyOut() >= orangesaplings1)
					return 1;
				else
					return 0;
			case 23://Peach saplings��������
				if (Back->moneyOut() >= peachsaplings1)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplingsʯ������
				if (Back->moneyOut() >= pomegranatesaplings1)
					return 1;
				else
					return 0;
			case 25://Apple saplingsƻ������
				if (Back->moneyOut() >= applesaplings1)
					return 1;
				else
					return 0;
			case 26://flowers ����
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			default:
				return 0;
		}
		break;
	case 2:
		switch (itemToMake) {
		case 0://melon���
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 1://tomato������
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 2://blueburry��ݮ
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 3://chili pepper����
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 4://wheatС��
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 5://turnip�ܲ�
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 6://Poppies ������
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 7://Summer sequins�ļ���Ƭ
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 8://hop ơ�ƻ�
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 9://corn����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 10://sunflower���տ�
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 11://Red leaf cabbage��Ҷ���Ĳ�
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 12://grass seed����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation�����䷽
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ��
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour �����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ����
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ��
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ��
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer��������
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer�߼�����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil������ʪ����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil�߼���ʪ����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsӣ������
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplings��������
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings��������
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplings��������
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsʯ������
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsƻ������
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers ����
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		default:
			return 0;
		}
		break;
	case 3:
		switch (itemToMake) {
		case 0://eggplant����
			if (Back->moneyOut() >= 20)
				return 1;
			else
				return 0;
		case 1://corn����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 2://pumpkin�Ϲ�
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 3://Chinese cabbageС�ײ�
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 4://yamɽҩ
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 5://Cranberries��Խݮ
			if (Back->moneyOut() >= 240)
				return 1;
			else
				return 0;
		case 6://sunflower ���տ�
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 7://Rose Fairyõ������
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 8://amaranth�Ȳ�
			if (Back->moneyOut() >= 70)
				return 1;
			else
				return 0;
		case 9://grape����
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 10://wheatС��
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 11://artichoke��
			if (Back->moneyOut() >= 30)
				return 1;
			else
				return 0;
		case 12://grass seed����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation�����䷽
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ��
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour �����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ����
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ��
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ��
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer��������
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer�߼�����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil������ʪ����
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil�߼���ʪ����
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsӣ������
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplings��������
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings��������
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplings��������
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsʯ������
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsƻ������
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers ����
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		default:
			return 0;
		}
		break;
	}
	return 0;
}

std::string Pierre::itemMoneyOut(int posi,int season) {
	switch (season) {
	case 1:
	{
		switch (posi) {
		case 0:
			return "10";
			break;
		case 1:
			return "30";
			break;
		case 2:
			return "40";
			break;
		case 3:
			return "20";
			break;
		case 4:
			return "10";
			break;
		case 5:
			return "50";
			break;
		case 6:
			return "25";
			break;
		case 7:
			return "30";
			break;
		case 8:
			return "40";
			break;
		case 9:
			return "5";
			break;
		case 10:
			return "50";
			break;
		case 11:
			return "20";
			break;
		case 12:
			return "25";
			break;
		case 13:
			return "50";
			break;
		case 14:
			return "20";
			break;
		case 15:
			return "15";
			break;
		case 16:
			return "30";
			break;
		case 17:
			return "50";
			break;
		case 18:
			return "50";
			break;
		case 19:
			return "100";
			break;
		case 20:
			return "10";
			break;
		case 21:
			return "15";
			break;
		case 22:
			return "25";
			break;
		case 23:
			return "35";
			break;
		case 24:
			return "55";
			break;
		case 25:
			return "55";
			break;
		case 26:
			return "50";
			break;
		}
	}
	case 2: {
		switch (posi) {
		case 0://melon���
			return "80";
			break;
		case 1://tomato������
			return "50";
			break;
		case 2://blueburry��ݮ
			return "80";
			break;
		case 3://chili pepper����
			return "40";
			break;
		case 4://wheatС��
			return "10";
			break;
		case 5://turnip�ܲ�
			return "40";
			break;
		case 6://Poppies ������
			return "100";
			break;
		case 7://Summer sequins�ļ���Ƭ
			return "50";
			break;
		case 8://hop ơ�ƻ�
			return "60";
			break;
		case 9://corn����
			return "150";
			break;
		case 10://sunflower���տ�
			return "200";
			break;
		case 11://Red leaf cabbage��Ҷ���Ĳ�
			return "50";
			break;
		case 12://grass seed����
			return "5";
			break;
		case 13://grass seed formulation�����䷽
			return "50";
			break;
		case 14://sugar ��
			return "20";
			break;
		case 15://barley flour �����
			return "25";
			break;
		case 16://rice ����
			return "50";
			break;
		case 17://oil ��
			return "20";
			break;
		case 18://vinegar ��
			return "15";
			break;
		case 19://Basic Fertilizer��������
			return "30";
			break;
		case 20://Senior Fertilizer�߼�����
			return "50";
			break;
		case 21://Basic remaining soil������ʪ����
			return "50";
			break;
		case 22://Senior remaining soil�߼���ʪ����
			return "100";
			break;
		case 23://Cherry saplingsӣ������
			return "10";
			break;
		case 24://Apricot saplings��������
			return "15";
			break;
		case 25://Orange saplings��������
			return "25";
			break;
		case 26://Peach saplings��������
			return "35";
			break;
		case 27://Pomegranate saplingsʯ������
			return "55";
			break;
		case 28://Apple saplingsƻ������
			return "55";
			break;
		case 29://flowers ����
			return "50";
			break;
		default:
			return 0;
		}
	}
	case 3: {
		switch (posi) {
		case 0://eggplant����
			return "20";
			break;
		case 1://corn����
			return "150";
			break;
		case 2://pumpkin�Ϲ�
			return "100";
			break;
		case 3://Chinese cabbageС�ײ�
			return "50";
			break;
		case 4://yamɽҩ
			return "60";
			break;
		case 5://Cranberries��Խݮ
			return "240";
			break;
		case 6://sunflower ���տ�
			return "200";
			break;
		case 7://Rose Fairyõ������
			return "200";
			break;
		case 8://amaranth�Ȳ�
			return "70";
			break;
		case 9://grape����
			return "60";
			break;
		case 10://wheatС��
			return "10";
			break;
		case 11://artichoke��
			return "30";
			break;
		case 12://grass seed����
			return "5";
			break;
		case 13://grass seed formulation�����䷽
			return "50";
			break;
		case 14://sugar ��
			return "20";
			break;
		case 15://barley flour �����
			return "25";
			break;
		case 16://rice ����
			return "50";
			break;
		case 17://oil ��
			return "20";
			break;
		case 18://vinegar ��
			return "15";
			break;
		case 19://Basic Fertilizer��������
			return "30";
			break;
		case 20://Senior Fertilizer�߼�����
			return "50";
			break;
		case 21://Basic remaining soil������ʪ����
			return "50";
			break;
		case 22://Senior remaining soil�߼���ʪ����
			return "100";
			break;
		case 23://Cherry saplingsӣ������
			return "10";
			break;
		case 24://Apricot saplings��������
			return "15";
			break;
		case 25://Orange saplings��������
			return "25";
			break;
		case 26://Peach saplings��������
			return "35";
			break;
		case 27://Pomegranate saplingsʯ������
			return "55";
			break;
		case 28://Apple saplingsƻ������
			return "55";
			break;
		case 29://flowers ����
			return "50";
			break;
		default:
			return 0;
		}
	}

	default:
		return 0;
		break;
	}
	return 0;
}

int Pierre::itemMoneyBack(int posi, int season) {
	switch (season) {
	case 1:
	{
		switch (posi) {
		case 0:
			return parsnipseed1;
			break;
		case 1:
			return greenbeanseed1;
			break;
		case 2:
			return cauliflowerseed1;
			break;
		case 3:
			return potatoseed1;
			break;
		case 4:
			return tulipbulbsseed1;
			break;
		case 5:
			return cabbageseed1;
			break;
		case 6:
			return bluejazzseed1;
			break;
		case 7:
			return garlicseed1;
			break;
		case 8:
			return riceseedlingseed1;
			break;
		case 9:
			return grassseed1;
			break;
		case 10:
			return 5;
			break;
		case 11:
			return 20;
			break;
		case 12:
			return 25;
			break;
		case 13:
			return 50;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 15;
			break;
		case 16:
			return 30;
			break;
		case 17:
			return 50;
			break;
		case 18:
			return 50;
			break;
		case 19:
			return 100;
			break;
		case 20:
			return cherrysaplings1;
			break;
		case 21:
			return apricotsaplings1;
			break;
		case 22:
			return orangesaplings1;
			break;
		case 23:
			return peachsaplings1;
			break;
		case 24:
			return pomegranatesaplings1;
			break;
		case 25:
			return applesaplings1;
			break;
		case 26:
			return 50;
			break;
		}
	}
	case 2:
	{
		switch (posi) {
		case 0:
			return melonseed1;
			break;
		case 1:
			return tomatoseed1;
			break;
		case 2:
			return blueburryseed1;
			break;
		case 3:
			return chilipepperseed1;
			break;
		case 4:
			return wheatseed1;
			break;
		case 5:
			return turnipseed1;
			break;
		case 6:
			return poppiesseed1;
			break;
		case 7:
			return summersequinsseed1;
			break;
		case 8:
			return hopseed1;
			break; 
		case 9:
			return cornseed1;
			break;
		case 10:
			return sunflowerseed1;
			break;
		case 11:
			return redleafcabbageseed1;
			break;
		case 12:
			return grassseed1;
			break;
		case 13:
			return 5;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 25;
			break;
		case 16:
			return 50;
			break;
		case 17:
			return 20;
			break;
		case 18:
			return 15;
			break;
		case 19:
			return 30;
			break;
		case 20:
			return 50;
			break;
		case 21:
			return 50;
			break;
		case 22:
			return 100;
			break;
		case 23:
			return cherrysaplings1;
			break;
		case 24:
			return apricotsaplings1;
			break;
		case 25:
			return orangesaplings1;
			break;
		case 26:
			return peachsaplings1;
			break;
		case 27:
			return pomegranatesaplings1;
			break;
		case 28:
			return applesaplings1;
			break;
		case 29:
			return 50;
			break;
		}
	}
	case 3:
	{
		switch (posi) {
		case 0:
			return eggplant1;
			break;
		case 1:
			return corn1;
			break;
		case 2:
			return pumpkin1;
			break;
		case 3:
			return chinesecabbage1;
			break;
		case 4:
			return yam1;
			break;
		case 5:
			return cranberries1;
			break;
		case 6:
			return sunflower1;
			break;
		case 7:
			return rosefairy1;
			break;
		case 8:
			return amaranth1;
			break;
		case 9:
			return grape1;
			break;
		case 10:
			return wheat1;
			break;
		case 11:
			return artichoke1;
			break;
		case 12:
			return grassseed1;
			break;
		case 13:
			return 5;
			break;
		case 14:
			return 20;
			break;
		case 15:
			return 25;
			break;
		case 16:
			return 50;
			break;
		case 17:
			return 20;
			break;
		case 18:
			return 15;
			break;
		case 19:
			return 30;
			break;
		case 20:
			return 50;
			break;
		case 21:
			return 50;
			break;
		case 22:
			return 100;
			break;
		case 23:
			return cherrysaplings1;
			break;
		case 24:
			return apricotsaplings1;
			break;
		case 25:
			return orangesaplings1;
			break;
		case 26:
			return peachsaplings1;
			break;
		case 27:
			return pomegranatesaplings1;
			break;
		case 28:
			return applesaplings1;
			break;
		case 29:
			return 50;
			break;
		}
	}
	default:
		return 0;
		break;
	}
	return 0;
}

std::string Pierre::itemNameOut(int no, int season,bool choise) {
	std::string outItem;
	switch (season) {
	case 1: {
		switch (no) {
		case 0:
			outItem="parsnipseed";
			break;
		case 1:
			outItem = "greenbeanseed";
			break;
		case 2:
			outItem = "cauliflowerseed";
			break;
		case 3:
			outItem = "potatoseed";
			break;
		case 4:
			outItem = "tulipbulbsseed";
			break;
		case 5:
			outItem = "cabbageseed";
			break;
		case 6:
			outItem = "bluejazzseed";
			break;
		case 7:
			outItem = "garlicseed";
			break;
		case 8:
			outItem = "riceseedlingseed";
			break;
		case 9:
			outItem = "grassseed";
			break;
		case 10:
			outItem = "grassseedformulation";
			break;
		case 11:
			outItem = "sugar";
			break;
		case 12:
			outItem = "barleyflour";
			break;
		case 13:
			outItem = "rice";
			break;
		case 14:
			outItem = "oil";
			break;
		case 15:
			outItem = "vinegar";
			break;
		case 16:
			outItem = "basicfertilizer";
			break;
		case 17:
			outItem = "seniorfertilizer";
			break;
		case 18:
			outItem = "basicremainingsoil";
			break;
		case 19:
			outItem = "seniorremainingsoil";
			break;
		case 20:
			outItem = "cherrysaplings";
			break;
		case 21:
			outItem = "apricotsaplings";
			break;
		case 22:
			outItem = "orangesaplings";
			break;
		case 23:
			outItem = "peachsaplings";
			break;
		case 24:
			outItem = "pomegranatesaplings";
			break;
		case 25:
			outItem = "applesaplings";
			break;
		case 26:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	case 2: {
		switch (no) {
		case 0:
			outItem = "melonseed";
			break;
		case 1:
			outItem = "tomatoseed";
			break;
		case 2:
			outItem = "blueburryseed";
			break;
		case 3:
			outItem = "chilipepperseed";
			break;
		case 4:
			outItem = "wheatseed";
			break;
		case 5:
			outItem = "turnipseed";
			break;
		case 6:
			outItem = "poppiesseed";
			break;
		case 7:
			outItem = "summersequinsseed";
			break;
		case 8:
			outItem = "hopseed"; 
			break;
		case 9:
			outItem = "cornseed";
			break;
		case 10:
			outItem = "sunflowerseed";
			break;
		case 11:
			outItem = "redleafcabbageseed";
			break;
		case 12:
			outItem = "grassseed";
			break;
		case 13:
			outItem = "grassseedformulation";
			break;
		case 14:
			outItem = "sugar";
			break;
		case 15:
			outItem = "barleyflour";
			break;
		case 16:
			outItem = "rice";
			break;
		case 17:
			outItem = "oil";
			break;
		case 18:
			outItem = "vinegar";
			break;
		case 19:
			outItem = "basicfertilizer";
			break;
		case 20:
			outItem = "seniorfertilizer";
			break;
		case 21:
			outItem = "basicremainingsoil";
			break;
		case 22:
			outItem = "seniorremainingsoil";
			break;
		case 23:
			outItem = "cherrysaplings";
			break;
		case 24:
			outItem = "apricotsaplings";
			break;
		case 25:
			outItem = "orangesaplings";
			break;
		case 26:
			outItem = "peachsaplings";
			break;
		case 27:
			outItem = "pomegranatesaplings";
			break;
		case 28:
			outItem = "applesaplings";
			break;
		case 29:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	case 3: {
		switch (no) {
		case 0:
			outItem = "eggplantseed";
			break;
		case 1:
			outItem = "cornseed";
			break;
		case 2:
			outItem = "pumpkinseed";
			break;
		case 3:
			outItem = "chinesecabbageseed";
			break;
		case 4:
			outItem = "yamseed";
			break;
		case 5:
			outItem = "cranberriesseed";
			break;
		case 6:
			outItem = "sunflowerseed";
			break;
		case 7:
			outItem = "rosefairyseed";
			break;
		case 8:
			outItem = "amaranthseed";
			break;
		case 9:
			outItem = "grapeseed";
			break;
		case 10:
			outItem = "wheatseed";
			break;
		case 11:
			outItem = "artichokeseed";
			break;
		case 12:
			outItem = "grassseed";
			break;
		case 13:
			outItem = "grassseedformulation";
			break;
		case 14:
			outItem = "sugar";
			break;
		case 15:
			outItem = "barleyflour";
			break;
		case 16:
			outItem = "rice";
			break;
		case 17:
			outItem = "oil";
			break;
		case 18:
			outItem = "vinegar";
			break;
		case 19:
			outItem = "basicfertilizer";
			break;
		case 20:
			outItem = "seniorfertilizer";
			break;
		case 21:
			outItem = "basicremainingsoil";
			break;
		case 22:
			outItem = "seniorremainingsoil";
			break;
		case 23:
			outItem = "cherrysaplings";
			break;
		case 24:
			outItem = "apricotsaplings";
			break;
		case 25:
			outItem = "orangesaplings";
			break;
		case 26:
			outItem = "peachsaplings";
			break;
		case 27:
			outItem = "pomegranatesaplings";
			break;
		case 28:
			outItem = "applesaplings";
			break;
		case 29:
			outItem = "flowers";
			break;
		default:
			outItem = "null";
			break;
		}
		break;
	}
	default:
		break;
	}
	if (choise == 0)
		return outItem;
	else
		return outItem + ".png";
}

//������Ʒ
Item* Pierre::getItem(backPack* Back, int itemToMake, int season) {
	switch (season){
	case 1:
		switch (itemToMake) {
		case 0://Parsnip�����
		{
			Item* Parsnip = Seed::create("parsnipseed");
			return Parsnip;
		}
		case 1://GreenBean�ඹ
		{
			Item* GreenBean = Seed::create("greenbean");
			return GreenBean;
		}
		case 2://cauliflower��Ҭ��
		{
			Item* Cauliflower = Seed::create("cauliflower");
			return Cauliflower;
		}
		case 3://potato����
		{
			Item* Potato = Seed::create("potato");
			return Potato;
		}
		case 4://Tulip bulbs��������
		{
			Item* TulipBulbs = Seed::create("tulipbulbs");
			return TulipBulbs;
		}
		case 5://cabbage����
		{
			Item* Cabbage = Seed::create("cabbage");
			return Cabbage;
		}
		case 6://Blue Jazz ����ʿ
		{
			Item* BlueJazz = Seed::create("bluejazz");
			return BlueJazz;
		}
		case 7://Garlic����
		{
			Item* Garlic = Seed::create("garlic");
			return Garlic;
		}
		case 8://rice seedling����
		{
			Item* RiceSeedling = Seed::create("riceseedling");
			return RiceSeedling;
		}
		case 9://grass seed����
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 10://grass seed formulation�����䷽
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 11://sugar ��
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 12://barley flour �����
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 13://rice ����
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 14://oil ��
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 15://vinegar ��
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 16://Basic Fertilizer��������
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 17://Senior Fertilizer�߼�����
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 18://Basic remaining soil������ʪ����
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 19://Senior remaining soil�߼���ʪ����
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 20://Cherry saplingsӣ������
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 21://Apricot saplings��������
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 22://Orange saplings��������
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 23://Peach saplings��������
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 24://Pomegranate saplingsʯ������
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 25://Apple saplingsƻ������
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 26://flowers ����
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	case 2:
		switch (itemToMake) {
		case 0://melon���
		{
			Item* Melon = Seed::create("melonseed");
			return Melon;
		}
		case 1://tomato������
		{
			Item* Tomato = Seed::create("tomatoseed");
			return Tomato;
		}
		case 2://blueburry��ݮ
		{
			Item* Blueburry = Seed::create("blueburryseed");
			return Blueburry;
		}
		case 3://chili pepper����
		{
			Item* ChiliPepper = Seed::create("chilipepperseed");
			return ChiliPepper;
		}
		case 4://wheatС��
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 5://turnip�ܲ�
		{
			Item* Turnip = Seed::create("turnipseed");
			return Turnip;
		}
		case 6://Poppies ������
		{
			Item* Poppies = Seed::create("poppiesseed");
			return Poppies;
		}
		case 7://Summer sequins�ļ���Ƭ
		{
			Item* SummerSequins = Seed::create("summersequinsseed");
			return SummerSequins;
		}
		case 8://hop ơ�ƻ�
		{
			Item* Hop = Seed::create("hopseed");
			return Hop;
		}
		case 9://corn����
		{
			Item* Corn = Seed::create("cornseedseed");
			return Corn;
		}
		case 10://sunflower���տ�
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 11://Red leaf cabbage��Ҷ���Ĳ�
		{
			Item* RedLeafCabbage = Seed::create("redleafcabbageseed");
			return RedLeafCabbage;
		}
		case 12://grass seed����
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 13://grass seed formulation�����䷽
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ��
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour �����
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ����
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ��
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ��
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer��������
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer�߼�����
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil������ʪ����
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil�߼���ʪ����
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsӣ������
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplings��������
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings��������
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplings��������
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsʯ������
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsƻ������
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers ����
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	case 3:
		switch (itemToMake) {
		case 0://eggplant����
		{
			Item* Eggplant = Seed::create("eggplantseed");
			return Eggplant;
		}
		case 1://corn����
		{
			Item* Corn = Seed::create("cornseed");
			return Corn;
		}
		case 2://pumpkin�Ϲ�
		{
			Item* Pumpkin = Seed::create("pumpkinseed");
			return Pumpkin;
		}
		case 3://Chinese cabbageС�ײ�
		{
			Item* ChineseCabbage = Seed::create("chinesecabbageseed");
			return ChineseCabbage;
		}
		case 4://yamɽҩ
		{
			Item* Yam = Seed::create("yamseed");
			return Yam;
		}
		case 5://Cranberries��Խݮ
		{
			Item* Cranberries = Seed::create("cranberriesseed");
			return Cranberries;
		}
		case 6://sunflower ���տ�
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 7://Rose Fairyõ������
		{
			Item* RoseFairy = Seed::create("rosefairyseed");
			return RoseFairy;
		}
		case 8://amaranth�Ȳ�
		{
			Item* Amaranth = Seed::create("amaranthseed");
			return Amaranth;
		}
		case 9://grape����
		{
			Item* Grape = Seed::create("grapeseed");
			return Grape;
		}
		case 10://wheatС��
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 11://artichoke��
		{
			Item* Artichoke = Seed::create("artichokeseed");
			return Artichoke;
		}
		case 12://grass seed����
		{
			Item* GrassSeed = Seed::create("grassseedseed");
			return GrassSeed;
		}
		case 13://grass seed formulation�����䷽
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ��
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour �����
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ����
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ��
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ��
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer��������
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer�߼�����
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil������ʪ����
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil�߼���ʪ����
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsӣ������
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplings��������
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings��������
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplings��������
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsʯ������
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsƻ������
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers ����
		{
			Item* Flowers = Tool::create("flowers");
			return Flowers;
		}
		default:
			return 0;
		}
		break;
	}
	Item* null;
	return null;
}

void Pierre::seasonEx(int season0) {
	season = season0;
	storeSeasonEx( season0);
}

int Pierre::seasonOut() {
	return season;
}

//�����̲���

//��Ʒ��Ӧ����
//  0--ͭ��ʯ
//  1--����ʯ
//  2--ú̿
//  3--�ƽ��ʯ
//  4--ͭ��
//  5--ͭˮ��
//  6--ͭ��
//  7--ͭ��
//  8--����
//  9--��ˮ��
//  10--����
//  11--����
//  12--��
//  13--��ˮ��
//  14--���
//  15--���
//  16--ҿ��
//  17--ҿˮ��
//  18--ҿ��
//  19--ҿ��
//���Ƿ��������ж�
bool BlackSmith::isAffordable(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore ͭ��ʯ
	{
		if (Back->moneyOut() >= 75)
			return 1;
		else
			return 0;
	}
	case 1://iron ore ����ʯ
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 2://coal ú̿
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 3://gold ore �ƽ��ʯ
	{
		if (Back->moneyOut() >= 400)
			return 1;
		else
			return 0;
	}
	case 4://copper axeͭ��
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 5://copper wateringcan ͭˮ��
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 6://copper pickaxe ͭ��
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 7://copper hoe ͭ��
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 8://iron axe ����
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 9://iron wateringcan ��ˮ��
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 10://iron pickaxe ����
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 11://iron hoe ����
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 12://gold axe ��
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 13://gold wateringcan ��ˮ��
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 14://gold pickaxe ���
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 15://gold hoe ���
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 16://iridium axe ҿ��
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 17://iridium wateringcan ҿˮ��
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 18://iridium pickaxe ҿ��
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 19://iridium hoe ҿ��
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	}
	return 0;
}

//������Ʒ
Item* getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore ͭ��ʯ
	{
		Item* CopperOre = terial::create("copperore");
		return CopperOre;
	}
	case 1://iron ore ����ʯ
	{
		Item* IronOre = terial::create("ironore");
		return IronOre;
	}
	case 2://coal ú̿
	{
		Item* Coal = terial::create("coal");
		return Coal;
	}
	case 3://gold ore �ƽ��ʯ
	{
		Item* GoldOre = terial::create("goldore");
		return GoldOre;
	}
	case 4://copper axeͭ��
	{
		Item* CopperAxe = Tool::create("copperaxe");
		return CopperAxe;
	}
	case 5://copper wateringcan ͭˮ��
	{
		Item* CopperWateringcan = Tool::create("copperwateringcan");
		return CopperWateringcan;
	}
	case 6://copper pickaxe ͭ��
	{
		Item* CopperPickaxe = Tool::create("copperpickaxe");
		return CopperPickaxe;
	}
	case 7://copper hoe ͭ��
	{
		Item* CopperHoe = Tool::create("copperhoe");
		return CopperHoe;
	}
	case 8://iron axe ����
	{
		Item* IronAxe = Tool::create("ironaxe");
		return IronAxe;
	}
	case 9://iron wateringcan ��ˮ��
	{
		Item* IronWateringcan = Tool::create("ironwateringcan");
		return IronWateringcan;
	}
	case 10://iron pickaxe ����
	{
		Item* IronPickaxe = Tool::create("ironpickaxe");
		return IronPickaxe;
	}
	case 11://iron hoe ����
	{
		Item* IronHoe = Tool::create("ironhoe");
		return IronHoe;
	}
	case 12://gold axe ��
	{
		Item* GoldAxe = Tool::create("goldaxe");
		return GoldAxe;
	}
	case 13://gold wateringcan ��ˮ��
	{
		Item* GoldWateringcan = Tool::create("goldwateringcan");
		return GoldWateringcan;
	}
	case 14://gold pickaxe ���
	{
		Item* GoldPickaxe = Tool::create("goldpickaxe");
		return GoldPickaxe;
	}
	case 15://gold hoe ���
	{
		Item* GoldHoe= Tool::create("goldhoe");
		return GoldHoe;
	}
	case 16://iridium axe ҿ��
	{
		Item* IridiumAxe = Tool::create("iridiumaxe");
		return IridiumAxe;
	}
	case 17://iridium wateringcan ҿˮ��
	{
		Item* IridiumWateringcan = Tool::create("iridiumwateringcan");
		return IridiumWateringcan;
	}
	case 18://iridium pickaxe ҿ��
	{
		Item* IridiumPickaxe = Tool::create("iridiumpickaxe");
		return IridiumPickaxe;
	}
	case 19://iridium hoe ҿ��
	{
		Item* IridiumHoe = Tool::create("iridiumhoe");
		return IridiumHoe;
	}
	}
	Item* null=new Item();
	return null;
}
