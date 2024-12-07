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
USING_NS_CC;
using namespace Constants;
//�ϳ�̨����

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
	case 5:
	{
		Item* CobblestonePath = terial::create("stone");
		if (Back->matchJudge(CobblestonePath, amountOfStoneForCobblestonePath))
			return 1;
		else
			return 0;
		break;
	}
	case 6:
	{
		Item* Torch1 = terial::create("wood");
		Item* Torch2 = terial::create("sap");
		if (Back->matchJudge(Torch1, amountOfWoodForTorch) && Back->matchJudge(Torch2, amountOfSapForTorch))
			return 1;
		else
			return 0;
		break;
	}
	case 7:
	{
		Item* BasicFertilizer = terial::create("sap");
		if (Back->matchJudge(BasicFertilizer, amountOfSapForBasicFertilizer))
			return 1;
		else
			return 0;
		break;
	}
	case 8:
	{
		Item* Chest = terial::create("wood");
		if (Back->matchJudge(Chest, amountOfWoodForChest))
			return 1;
		else
			return 0;
		break;
	}
	case 9:
	{
		Item* Furnace1 = terial::create("stone");
		Item* Furnace2 = terial::create("copperore");
		if (Back->matchJudge(Furnace1, amountOfStoneForFurnace) && Back->matchJudge(Furnace2, amountOfCopperOreForFurnace))
			return 1;
		else
			return 0;
		break;
	}
	case 10:
	{
		Item* StoneSign = terial::create("stone");
		if (Back->matchJudge(StoneSign, 25))
			return 1;
		else
			return 0;
		break;
	}
	case 11:
	{
		Item* Sprinkle1 = terial::create("ironbar");
		Item* Sprinkle2 = terial::create("copperbar");
		if (Back->matchJudge(Sprinkle1, amountOfIronBarForSprinkle) && Back->matchJudge(Sprinkle2, amountOfCopperBarForSprinkle))
			return 1;
		else
			return 0;
		break;
	}
	case 12:
	{
		Item* BasicRetainingSoil = terial::create("stone");
		if (Back->matchJudge(BasicRetainingSoil, 2))
			return 1;
		else
			return 0;
		break;
	}
	case 13:
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
	case 14:
	{
		Item* Bait = AnimalProduct::create("bugmeat");
		if (Back->matchJudge(Bait, amountOfBugmeatForBait))
			return 1;
		else
			return 0;
		break;
	}
	case 15:
	{
		Item* CherryBomb1 = terial::create("coal");
		Item* CherryBomb2 = terial::create("copperore");
		if (Back->matchJudge(CherryBomb1, 2) && Back->matchJudge(CherryBomb2, 4))
			return 1;
		else
			return 0;
		break;
	}
	case 16:
	{
		Item* StairCase = terial::create("stone");
		if (Back->matchJudge(StairCase, 99))
			return 1;
		else
			return 0;
		break;
	}
	case 17:
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
	case 18:
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

//���Ƿ��������ж�
bool Pierre::isAffordable(backPack* Back, int itemToMake,int season) {
	switch (season) {
	case 1:
		switch (itemToMake) {
			case 0://Parsnip�����
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 1://GreenBean�ඹ
				if (Back->moneyOut() >= 60)
					return 1;
				else
					return 0;
			case 2://cauliflower��Ҭ��
				if (Back->moneyOut() >= 80)
					return 1;
				else
					return 0;
			case 3://potato����
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 4://Tulip bulbs��������
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 5://cabbage����
				if (Back->moneyOut() >= 70)
					return 1;
				else
					return 0;
			case 6://Blue Jazz ����ʿ
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 7://Garlic����
				if(Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 8://rice seedling����
				if (Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 9://grass seed����
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 10://grass seed formulation�����䷽
				if (Back->moneyOut() >= 1000)
					return 1;
				else
					return 0;
			case 11://sugar ��
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 12://barley flour �����
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 13://rice ����
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 14://oil ��
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 15://vinegar ��
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer��������
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer�߼�����
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil������ʪ����
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil�߼���ʪ����
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 20://Cherry saplingsӣ������
				if (Back->moneyOut() >= 3400)
					return 1;
				else
					return 0;
			case 21://Apricot saplings��������
				if (Back->moneyOut() >= 2000)
					return 1;
				else
					return 0;
			case 22://Orange saplings��������
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 23://Peach saplings��������
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplingsʯ������
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 25://Apple saplingsƻ������
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 26://flowers ����
				if (Back->moneyOut() >= 200)
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

//�����̲���

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
	Item* null;
	return null;
}
