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
//合成台部分

//物品对应数字
//0--木牌
//1--木栅栏
//2--大门
//3--草籽
//4--木径
//5--石径
//6--火把
//7--基础肥料
//8--宝箱
//9--熔炉
//10--石牌
//11--水龙头 
//12--基础湿土
//13--稻草人
//14--鱼饵
//15--樱桃炸弹
//16--阶梯
//17--篝火
//18--春日野种
//对物品是否可合成的判断
bool craftTable::changeForCraft(backPack* Back,int itemToMake) {
	switch (itemToMake) {
	case 0://木牌
	{
		Item* WoodenSign = terial::create("wood");
		if (Back->matchJudge(WoodenSign, amountOfWoodForWoodenSign))
			return 1;
		else
			return 0;
		break;
	}
	case 1://木栅栏
	{
		Item* WoodFence = terial::create("wood");
		if (Back->matchJudge(WoodFence, amountOfWoodForWoodFence))
			return 1;
		else
			return 0;
		break;
	}
	case 2://大门
	{
		Item* Gate = terial::create("wood");
		if (Back->matchJudge(Gate, amountOfWoodForGate))
			return 1;
		else
			return 0;
		break;
	}
	case 3://草籽
	{
		Item* GrassStarter = terial::create("fibre");
		if (Back->matchJudge(GrassStarter, amountOfFibreForGrassStarter))
			return 1;
		else
			return 0;
		break;
	}
	case 4://木径
	{
		Item* WoodPath = terial::create("wood");
		if (Back->matchJudge(WoodPath, amountOfWoodForWoodPath))
			return 1;
		else
			return 0;
		break;
	}
	case 5://石径
	{
		Item* CobblestonePath = terial::create("stone");
		if (Back->matchJudge(CobblestonePath, amountOfStoneForCobblestonePath))
			return 1;
		else
			return 0;
		break;
	}
	case 6://火把
	{
		Item* Torch1 = terial::create("wood");
		Item* Torch2 = terial::create("sap");
		if (Back->matchJudge(Torch1, amountOfWoodForTorch) && Back->matchJudge(Torch2, amountOfSapForTorch))
			return 1;
		else
			return 0;
		break;
	}
	case 7://基础肥料
	{
		Item* BasicFertilizer = terial::create("sap");
		if (Back->matchJudge(BasicFertilizer, amountOfSapForBasicFertilizer))
			return 1;
		else
			return 0;
		break;
	}
	case 8://宝箱
	{
		Item* Chest = terial::create("wood");
		if (Back->matchJudge(Chest, amountOfWoodForChest))
			return 1;
		else
			return 0;
		break;
	}
	case 9://熔炉
	{
		Item* Furnace1 = terial::create("stone");
		Item* Furnace2 = terial::create("copperore");
		if (Back->matchJudge(Furnace1, amountOfStoneForFurnace) && Back->matchJudge(Furnace2, amountOfCopperOreForFurnace))
			return 1;
		else
			return 0;
		break;
	}
	case 10://石牌
	{
		Item* StoneSign = terial::create("stone");
		if (Back->matchJudge(StoneSign, 25))
			return 1;
		else
			return 0;
		break;
	}
	case 11://水龙头 
	{
		Item* Sprinkle1 = terial::create("ironbar");
		Item* Sprinkle2 = terial::create("copperbar");
		if (Back->matchJudge(Sprinkle1, amountOfIronBarForSprinkle) && Back->matchJudge(Sprinkle2, amountOfCopperBarForSprinkle))
			return 1;
		else
			return 0;
		break;
	}
	case 12://基础湿土
	{
		Item* BasicRetainingSoil = terial::create("stone");
		if (Back->matchJudge(BasicRetainingSoil, 2))
			return 1;
		else
			return 0;
		break;
	}
	case 13://稻草人
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
	case 14://鱼饵
	{
		Item* Bait = AnimalProduct::create("bugmeat");
		if (Back->matchJudge(Bait, amountOfBugmeatForBait))
			return 1;
		else
			return 0;
		break;
	}
	case 15://樱桃炸弹
	{
		Item* CherryBomb1 = terial::create("coal");
		Item* CherryBomb2 = terial::create("copperore");
		if (Back->matchJudge(CherryBomb1, 2) && Back->matchJudge(CherryBomb2, 4))
			return 1;
		else
			return 0;
		break;
	}
	case 16://阶梯
	{
		Item* StairCase = terial::create("stone");
		if (Back->matchJudge(StairCase, 99))
			return 1;
		else
			return 0;
		break;
	}
	case 17://篝火
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
	default:
		break;
	}
}

//合成物品
Item* craftTable::getItem(int itemToMake) {
	switch (itemToMake) {
	case 0:
	{
		Item* WoodenSign = Tool::create("woodsign");
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
		Item* GrassStarter = Seed::create("grassseed");
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
		Item* CobblestonePath = Tool::create("stonepath");
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
		Item* Furnace = Tool::create("furnance");
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
	default:
		Item* init = new Item;
		return init;
		break;
	}
}

void craftTable::itemDelete(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://木牌
	{
		Item* WoodenSign = terial::create("wood");
		int posi0 = Back->returnPosi(WoodenSign);
		Back->itemReduce(WoodenSign, amountOfWoodForWoodenSign);
		if (Back->returnPosi(WoodenSign) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(WoodenSign));
		}
		break;
	}
	case 1://木栅栏
	{
		Item* WoodFence = terial::create("wood");
		int posi0 = Back->returnPosi(WoodFence);
		Back->itemReduce(WoodFence, amountOfWoodForWoodFence);
		if (Back->returnPosi(WoodFence) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(WoodFence));
		}
		break;
	}
	case 2://大门
	{
		Item* Gate = terial::create("wood");
		int posi0 = Back->returnPosi(Gate);
		Back->itemReduce(Gate, amountOfWoodForGate);
		if (Back->returnPosi(Gate) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Gate));
		}
		break;
	}
	case 3://草籽
	{
		Item* GrassStarter = terial::create("fibre");
		int posi0 = Back->returnPosi(GrassStarter);
		Back->itemReduce(GrassStarter, amountOfFibreForGrassStarter);
		if (Back->returnPosi(GrassStarter) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(GrassStarter));
		}
		break;
	}
	case 4://木径
	{
		Item* WoodPath = terial::create("wood");
		int posi0 = Back->returnPosi(WoodPath);
		Back->itemReduce(WoodPath, amountOfWoodForWoodPath);
		if (Back->returnPosi(WoodPath) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(WoodPath));
		}
		break;
	}
	case 5://石径
	{
		Item* CobblestonePath = terial::create("stone");
		int posi0 = Back->returnPosi(CobblestonePath);
		Back->itemReduce(CobblestonePath, amountOfStoneForCobblestonePath);
		if (Back->returnPosi(CobblestonePath) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(CobblestonePath));
		}
		break;
	}
	case 6://火把
	{
		Item* Torch1 = terial::create("wood");
		Item* Torch2 = terial::create("sap");
		int posi0 = Back->returnPosi(Torch1);
		int posi1 = Back->returnPosi(Torch2);
		Back->itemReduce(Torch1, amountOfWoodForTorch);
		Back->itemReduce(Torch2, amountOfSapForTorch);
		if (Back->returnPosi(Torch1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Torch1));
		}
		if (Back->returnPosi(Torch2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(Torch2));
		}
		break;
	}
	case 7://基础肥料
	{
		Item* BasicFertilizer = terial::create("sap");
		int posi0 = Back->returnPosi(BasicFertilizer);
		Back->itemReduce(BasicFertilizer, amountOfSapForBasicFertilizer);
		if (Back->returnPosi(BasicFertilizer) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(BasicFertilizer));
		}
		break;
	}
	case 8://宝箱
	{
		Item* Chest = terial::create("wood");
		int posi0 = Back->returnPosi(Chest);
		Back->itemReduce(Chest, amountOfWoodForChest);
		if (Back->returnPosi(Chest) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Chest));
		}
		break;
	}
	case 9://熔炉
	{
		Item* Furnace1 = terial::create("stone");
		Item* Furnace2 = terial::create("copperore");
		int posi0 = Back->returnPosi(Furnace1);
		int posi1 = Back->returnPosi(Furnace2);
		Back->itemReduce(Furnace1, amountOfStoneForFurnace); 
		Back->itemReduce(Furnace2, amountOfCopperOreForFurnace);
		if (Back->returnPosi(Furnace1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Furnace1));
		}
		if (Back->returnPosi(Furnace2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(Furnace2));
		}
		break;
	}
	case 10://石牌
	{
		Item* StoneSign = terial::create("stone");
		Back->itemReduce(StoneSign, 25);
		if (Back->returnPosi(StoneSign) == -1)
		{
			packPosi(Back->returnPosi(StoneSign));
		}
		else {
			numlabel2(Back->returnPosi(StoneSign));
		}
		break;
	}
	case 11://水龙头 
	{
		Item* Sprinkle1 = terial::create("ironbar");
		Item* Sprinkle2 = terial::create("copperbar");
		int posi0 = Back->returnPosi(Sprinkle1);
		int posi1 = Back->returnPosi(Sprinkle2);
		Back->itemReduce(Sprinkle1, amountOfIronBarForSprinkle);
		Back->itemReduce(Sprinkle2, amountOfCopperBarForSprinkle);
		if (Back->returnPosi(Sprinkle1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Sprinkle1));
		}
		if (Back->returnPosi(Sprinkle2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(Sprinkle2));
		}
		break;
	}
	case 12://基础湿土
	{
		Item* BasicRetainingSoil = terial::create("stone");
		int posi0 = Back->returnPosi(BasicRetainingSoil);
		Back->itemReduce(BasicRetainingSoil, 2);
		if (Back->returnPosi(BasicRetainingSoil) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(BasicRetainingSoil));
		}
		break;
	}
	case 13://稻草人
	{
		Item* ScareCrow1 = terial::create("wood");
		Item* ScareCrow2 = terial::create("coal");
		Item* ScareCrow3 = terial::create("fibre");
		int posi0 = Back->returnPosi(ScareCrow1);
		int posi1 = Back->returnPosi(ScareCrow2);
		int posi2 = Back->returnPosi(ScareCrow3);
		Back->itemReduce(ScareCrow1, amountOfWoodForScareCrow);
		Back->itemReduce(ScareCrow2, amountOfCoalForScareCrow);
		Back->itemReduce(ScareCrow3, amountOfFibreForScareCrow);
		if (Back->returnPosi(ScareCrow1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(ScareCrow1));
		}
		if (Back->returnPosi(ScareCrow2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(ScareCrow2));
		}
		if (Back->returnPosi(ScareCrow3) == -1)
		{
			packPosi(posi2);
		}
		else {
			numlabel2(Back->returnPosi(ScareCrow3));
		}
		break;
	}
	case 14://鱼饵
	{
		Item* Bait = AnimalProduct::create("bugmeat");
		int posi0 = Back->returnPosi(Bait);
		Back->itemReduce(Bait, amountOfBugmeatForBait);
		if (Back->returnPosi(Bait) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(Bait));
		}
		break;
	}
	case 15://樱桃炸弹
	{
		Item* CherryBomb1 = terial::create("coal");
		Item* CherryBomb2 = terial::create("copperore");
		int posi0 = Back->returnPosi(CherryBomb1);
		int posi1 = Back->returnPosi(CherryBomb2);
		Back->itemReduce(CherryBomb1, 2);
		Back->itemReduce(CherryBomb2, 4);
		if (Back->returnPosi(CherryBomb1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(CherryBomb1));
		}
		if (Back->returnPosi(CherryBomb2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(CherryBomb2));
		}
		break;
	}
	case 16://阶梯
	{
		Item* StairCase = terial::create("stone");
		int posi0 = Back->returnPosi(StairCase);
		Back->itemReduce(StairCase, 99);
		if (Back->returnPosi(StairCase) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(StairCase));
		}
		break;
	}
	case 17://篝火
	{
		Item* CampFire1 = terial::create("stone");
		Item* CampFire2 = terial::create("wood");
		Item* CampFire3 = terial::create("fibre");
		int posi0 = Back->returnPosi(CampFire1);
		int posi1 = Back->returnPosi(CampFire2);
		int posi2 = Back->returnPosi(CampFire3);
		Back->itemReduce(CampFire1, 10);
		Back->itemReduce(CampFire2, 10);
		Back->itemReduce(CampFire3, 10);
		if (Back->returnPosi(CampFire1) == -1)
		{
			packPosi(posi0);
		}
		else {
			numlabel2(Back->returnPosi(CampFire1));
		}
		if (Back->returnPosi(CampFire2) == -1)
		{
			packPosi(posi1);
		}
		else {
			numlabel2(Back->returnPosi(CampFire2));
		}
		if (Back->returnPosi(CampFire3) == -1)
		{
			packPosi(posi2);
		}
		else {
			numlabel2(Back->returnPosi(CampFire3));
		}
		break;
	}
	default:
		break;
	}
}

std::string craftTable::factorBack(int itemToMake) {
	switch (itemToMake) {
	case 0:
	{
		return "25 wood";
		break;
	}
	case 1:
	{
		return "2 wood";
		break;
	}
	case 2:
	{
		return "10 wood";
		break;
	}
	case 3:
	{
		return "10 fibre";
		break;
	}
	case 4:
	{
		return "1 wood";
		break;
	}
	case 5:
	{
		return "1 stone";
		break;
	}
	case 6:
	{
		return "1 wood,1 sap";
		break;
	}
	case 7:
	{
		return "2 sap";
		break;
	}
	case 8:
	{
		return "50 wood";
		break;
	}
	case 9:
	{
		return "25 stone,20 copperore";
		break;
	}
	case 10:
	{
		return "25 stone";
		break;
	}
	case 11:
	{
		return "1 ironbar,1 copperbar";
		break;
	}
	case 12:
	{
		return "2 stone";
		break;
	}
	case 13:
	{
		return "50 wood,1 coal,20 fibre";
		break;
	}
	case 14:
	{
		return "1 bugmeat";
		break;
	}
	case 15:
	{
		return "2 coal,4 copperore";
		break;
	}
	case 16:
	{
		return "99 stone";
		break;
	}
	case 17:
	{
		return "10 stone,10 wood,10 fibre";
		break;
	}
	default:
		return "0";
		break;
	}
}
//Pierre商店部分

//物品对应数字
// season 1：
//   0--防风草
//   1--青豆
//   2--花椰菜
//   3--土豆
//   4--郁金香球茎
//   5--甘蓝
//   6--蓝爵士
//   7--大蒜
//   8--稻苗  
//   9--草籽
//   10--草籽配方
//   11--糖
//   12--大麦粉
//   13--大米
//   14--油
//   15--醋
//   16--初级肥料
//   17--高級肥料
//   18--初级保湿土壤
//   19--高级保湿土壤
//   20--樱桃树苗
//   21--杏子树苗
//   22--橙子树苗
//   23--桃子树苗
//   24--石榴树苗
//   25--苹果树苗
//   26--花束
// season 2：
//   0--甜瓜
//   1--西红柿
//   2--蓝莓
//   3--辣椒
//   4--小麦
//   5--萝卜
//   6--虞美人
//   7--夏季亮片
//   8--啤酒花
//   9--玉米
//   10--向日葵
//   11--红叶卷心菜
//   12--草籽
//   13--草籽配方
//   14--糖
//   15--大麦粉
//   16--大米
//   17--油
//   18--醋
//   19--初级肥料
//   20--高級肥料
//   21--初级保湿土壤
//   22--高级保湿土壤
//   23--樱桃树苗
//   24--杏子树苗
//   25--橙子树苗
//   26--桃子树苗
//   27--石榴树苗
//   28--苹果树苗
//   29--花束
// // season 3：
//   0--茄子
//   1--玉米
//   2--南瓜
//   3--小白菜
//   4--山药
//   5--蔓越莓
//   6--向日葵
//   7--玫瑰仙子
//   8--苋菜
//   9--葡萄
//   10--小麦
//   11--洋蓟
//   12--草籽
//   13--草籽配方
//   14--糖
//   15--大麦粉
//   16--大米
//   17--油
//   18--醋
//   19--初级肥料
//   20--高級肥料
//   21--初级保湿土壤
//   22--高级保湿土壤
//   23--樱桃树苗
//   24--杏子树苗
//   25--橙子树苗
//   26--桃子树苗
//   27--石榴树苗
//   28--苹果树苗
//   29--花束
//对是否买得起的判断
bool Pierre::isAffordable(backPack* Back, int itemToMake,int season) {
	switch (season) {
	case 1:
		switch (itemToMake) {
			case 0://Parsnip防风草
				if (Back->moneyOut() >= parsnipseed1)
					return 1;
				else
					return 0;
			case 1://GreenBean青豆
				if (Back->moneyOut() >= greenbeanseed1)
					return 1;
				else
					return 0;
			case 2://cauliflower花椰菜
				if (Back->moneyOut() >= cauliflowerseed1)
					return 1;
				else
					return 0;
			case 3://potato土豆
				if (Back->moneyOut() >= potatoseed1)
					return 1;
				else
					return 0;
			case 4://Tulip bulbs郁金香球茎
				if (Back->moneyOut() >= tulipbulbsseed1)
					return 1;
				else
					return 0;
			case 5://cabbage甘蓝
				if (Back->moneyOut() >= cabbageseed1)
					return 1;
				else
					return 0;
			case 6://Blue Jazz 蓝爵士
				if (Back->moneyOut() >= bluejazzseed1)
					return 1;
				else
					return 0;
			case 7://Garlic大蒜
				if(Back->moneyOut() >= garlicseed1)
					return 1;
				else
					return 0;
			case 8://rice seedling稻苗
				if (Back->moneyOut() >= riceseedlingseed1)
					return 1;
				else
					return 0;
			case 9://grass seed草籽
				if (Back->moneyOut() >= grassseed1)
					return 1;
				else
					return 0;
			case 10://grass seed formulation草籽配方
				if (Back->moneyOut() >= 5)
					return 1;
				else
					return 0;
			case 11://sugar 糖
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 12://barley flour 大麦粉
				if (Back->moneyOut() >= 25)
					return 1;
				else
					return 0;
			case 13://rice 大米
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 14://oil 油
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 15://vinegar 醋
				if (Back->moneyOut() >= 15)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer初级肥料
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer高級肥料
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil初级保湿土壤
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil高级保湿土壤
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 20://Cherry saplings樱桃树苗
				if (Back->moneyOut() >= cherrysaplings1)
					return 1;
				else
					return 0;
			case 21://Apricot saplings杏子树苗
				if (Back->moneyOut() >= apricotsaplings1)
					return 1;
				else
					return 0;
			case 22://Orange saplings橙子树苗
				if (Back->moneyOut() >= orangesaplings1)
					return 1;
				else
					return 0;
			case 23://Peach saplings桃子树苗
				if (Back->moneyOut() >= peachsaplings1)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplings石榴树苗
				if (Back->moneyOut() >= pomegranatesaplings1)
					return 1;
				else
					return 0;
			case 25://Apple saplings苹果树苗
				if (Back->moneyOut() >= applesaplings1)
					return 1;
				else
					return 0;
			case 26://flowers 花束
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
		case 0://melon甜瓜
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 1://tomato西红柿
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 2://blueburry蓝莓
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 3://chili pepper辣椒
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 4://wheat小麦
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 5://turnip萝卜
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 6://Poppies 虞美人
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 7://Summer sequins夏季亮片
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 8://hop 啤酒花
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 9://corn玉米
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 10://sunflower向日葵
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 11://Red leaf cabbage红叶卷心菜
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 12://grass seed草籽
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation草籽配方
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar 糖
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour 大麦粉
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice 大米
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil 油
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar 醋
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer初级肥料
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer高級肥料
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil初级保湿土壤
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil高级保湿土壤
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplings樱桃树苗
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplings杏子树苗
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings橙子树苗
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplings桃子树苗
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplings石榴树苗
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplings苹果树苗
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers 花束
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
		case 0://eggplant茄子
			if (Back->moneyOut() >= 20)
				return 1;
			else
				return 0;
		case 1://corn玉米
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 2://pumpkin南瓜
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 3://Chinese cabbage小白菜
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 4://yam山药
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 5://Cranberries蔓越莓
			if (Back->moneyOut() >= 240)
				return 1;
			else
				return 0;
		case 6://sunflower 向日葵
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 7://Rose Fairy玫瑰仙子
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 8://amaranth苋菜
			if (Back->moneyOut() >= 70)
				return 1;
			else
				return 0;
		case 9://grape葡萄
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 10://wheat小麦
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 11://artichoke洋蓟
			if (Back->moneyOut() >= 30)
				return 1;
			else
				return 0;
		case 12://grass seed草籽
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation草籽配方
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar 糖
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour 大麦粉
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice 大米
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil 油
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar 醋
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer初级肥料
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer高級肥料
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil初级保湿土壤
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil高级保湿土壤
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplings樱桃树苗
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplings杏子树苗
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings橙子树苗
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplings桃子树苗
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplings石榴树苗
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplings苹果树苗
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers 花束
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
		case 0://melon甜瓜
			return "80";
			break;
		case 1://tomato西红柿
			return "50";
			break;
		case 2://blueburry蓝莓
			return "80";
			break;
		case 3://chili pepper辣椒
			return "40";
			break;
		case 4://wheat小麦
			return "10";
			break;
		case 5://turnip萝卜
			return "40";
			break;
		case 6://Poppies 虞美人
			return "100";
			break;
		case 7://Summer sequins夏季亮片
			return "50";
			break;
		case 8://hop 啤酒花
			return "60";
			break;
		case 9://corn玉米
			return "150";
			break;
		case 10://sunflower向日葵
			return "200";
			break;
		case 11://Red leaf cabbage红叶卷心菜
			return "50";
			break;
		case 12://grass seed草籽
			return "5";
			break;
		case 13://grass seed formulation草籽配方
			return "50";
			break;
		case 14://sugar 糖
			return "20";
			break;
		case 15://barley flour 大麦粉
			return "25";
			break;
		case 16://rice 大米
			return "50";
			break;
		case 17://oil 油
			return "20";
			break;
		case 18://vinegar 醋
			return "15";
			break;
		case 19://Basic Fertilizer初级肥料
			return "30";
			break;
		case 20://Senior Fertilizer高級肥料
			return "50";
			break;
		case 21://Basic remaining soil初级保湿土壤
			return "50";
			break;
		case 22://Senior remaining soil高级保湿土壤
			return "100";
			break;
		case 23://Cherry saplings樱桃树苗
			return "10";
			break;
		case 24://Apricot saplings杏子树苗
			return "15";
			break;
		case 25://Orange saplings橙子树苗
			return "25";
			break;
		case 26://Peach saplings桃子树苗
			return "35";
			break;
		case 27://Pomegranate saplings石榴树苗
			return "55";
			break;
		case 28://Apple saplings苹果树苗
			return "55";
			break;
		case 29://flowers 花束
			return "50";
			break;
		default:
			return 0;
		}
	}
	case 3: {
		switch (posi) {
		case 0://eggplant茄子
			return "20";
			break;
		case 1://corn玉米
			return "150";
			break;
		case 2://pumpkin南瓜
			return "100";
			break;
		case 3://Chinese cabbage小白菜
			return "50";
			break;
		case 4://yam山药
			return "60";
			break;
		case 5://Cranberries蔓越莓
			return "240";
			break;
		case 6://sunflower 向日葵
			return "200";
			break;
		case 7://Rose Fairy玫瑰仙子
			return "200";
			break;
		case 8://amaranth苋菜
			return "70";
			break;
		case 9://grape葡萄
			return "60";
			break;
		case 10://wheat小麦
			return "10";
			break;
		case 11://artichoke洋蓟
			return "30";
			break;
		case 12://grass seed草籽
			return "5";
			break;
		case 13://grass seed formulation草籽配方
			return "50";
			break;
		case 14://sugar 糖
			return "20";
			break;
		case 15://barley flour 大麦粉
			return "25";
			break;
		case 16://rice 大米
			return "50";
			break;
		case 17://oil 油
			return "20";
			break;
		case 18://vinegar 醋
			return "15";
			break;
		case 19://Basic Fertilizer初级肥料
			return "30";
			break;
		case 20://Senior Fertilizer高級肥料
			return "50";
			break;
		case 21://Basic remaining soil初级保湿土壤
			return "50";
			break;
		case 22://Senior remaining soil高级保湿土壤
			return "100";
			break;
		case 23://Cherry saplings樱桃树苗
			return "10";
			break;
		case 24://Apricot saplings杏子树苗
			return "15";
			break;
		case 25://Orange saplings橙子树苗
			return "25";
			break;
		case 26://Peach saplings桃子树苗
			return "35";
			break;
		case 27://Pomegranate saplings石榴树苗
			return "55";
			break;
		case 28://Apple saplings苹果树苗
			return "55";
			break;
		case 29://flowers 花束
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

//买下物品
Item* Pierre::getItem(backPack* Back, int itemToMake, int season) {
	switch (season){
	case 1:
		switch (itemToMake) {
		case 0://Parsnip防风草
		{
			Item* Parsnip = Seed::create("parsnipseed");
			return Parsnip;
		}
		case 1://GreenBean青豆
		{
			Item* GreenBean = Seed::create("greenbean");
			return GreenBean;
		}
		case 2://cauliflower花椰菜
		{
			Item* Cauliflower = Seed::create("cauliflower");
			return Cauliflower;
		}
		case 3://potato土豆
		{
			Item* Potato = Seed::create("potato");
			return Potato;
		}
		case 4://Tulip bulbs郁金香球茎
		{
			Item* TulipBulbs = Seed::create("tulipbulbs");
			return TulipBulbs;
		}
		case 5://cabbage甘蓝
		{
			Item* Cabbage = Seed::create("cabbage");
			return Cabbage;
		}
		case 6://Blue Jazz 蓝爵士
		{
			Item* BlueJazz = Seed::create("bluejazz");
			return BlueJazz;
		}
		case 7://Garlic大蒜
		{
			Item* Garlic = Seed::create("garlic");
			return Garlic;
		}
		case 8://rice seedling稻苗
		{
			Item* RiceSeedling = Seed::create("riceseedling");
			return RiceSeedling;
		}
		case 9://grass seed草籽
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 10://grass seed formulation草籽配方
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 11://sugar 糖
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 12://barley flour 大麦粉
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 13://rice 大米
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 14://oil 油
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 15://vinegar 醋
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 16://Basic Fertilizer初级肥料
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 17://Senior Fertilizer高級肥料
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 18://Basic remaining soil初级保湿土壤
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 19://Senior remaining soil高级保湿土壤
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 20://Cherry saplings樱桃树苗
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 21://Apricot saplings杏子树苗
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 22://Orange saplings橙子树苗
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 23://Peach saplings桃子树苗
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 24://Pomegranate saplings石榴树苗
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 25://Apple saplings苹果树苗
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 26://flowers 花束
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
		case 0://melon甜瓜
		{
			Item* Melon = Seed::create("melonseed");
			return Melon;
		}
		case 1://tomato西红柿
		{
			Item* Tomato = Seed::create("tomatoseed");
			return Tomato;
		}
		case 2://blueburry蓝莓
		{
			Item* Blueburry = Seed::create("blueburryseed");
			return Blueburry;
		}
		case 3://chili pepper辣椒
		{
			Item* ChiliPepper = Seed::create("chilipepperseed");
			return ChiliPepper;
		}
		case 4://wheat小麦
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 5://turnip萝卜
		{
			Item* Turnip = Seed::create("turnipseed");
			return Turnip;
		}
		case 6://Poppies 虞美人
		{
			Item* Poppies = Seed::create("poppiesseed");
			return Poppies;
		}
		case 7://Summer sequins夏季亮片
		{
			Item* SummerSequins = Seed::create("summersequinsseed");
			return SummerSequins;
		}
		case 8://hop 啤酒花
		{
			Item* Hop = Seed::create("hopseed");
			return Hop;
		}
		case 9://corn玉米
		{
			Item* Corn = Seed::create("cornseedseed");
			return Corn;
		}
		case 10://sunflower向日葵
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 11://Red leaf cabbage红叶卷心菜
		{
			Item* RedLeafCabbage = Seed::create("redleafcabbageseed");
			return RedLeafCabbage;
		}
		case 12://grass seed草籽
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 13://grass seed formulation草籽配方
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar 糖
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour 大麦粉
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice 大米
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil 油
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar 醋
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer初级肥料
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer高級肥料
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil初级保湿土壤
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil高级保湿土壤
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplings樱桃树苗
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplings杏子树苗
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings橙子树苗
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplings桃子树苗
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplings石榴树苗
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplings苹果树苗
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers 花束
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
		case 0://eggplant茄子
		{
			Item* Eggplant = Seed::create("eggplantseed");
			return Eggplant;
		}
		case 1://corn玉米
		{
			Item* Corn = Seed::create("cornseed");
			return Corn;
		}
		case 2://pumpkin南瓜
		{
			Item* Pumpkin = Seed::create("pumpkinseed");
			return Pumpkin;
		}
		case 3://Chinese cabbage小白菜
		{
			Item* ChineseCabbage = Seed::create("chinesecabbageseed");
			return ChineseCabbage;
		}
		case 4://yam山药
		{
			Item* Yam = Seed::create("yamseed");
			return Yam;
		}
		case 5://Cranberries蔓越莓
		{
			Item* Cranberries = Seed::create("cranberriesseed");
			return Cranberries;
		}
		case 6://sunflower 向日葵
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 7://Rose Fairy玫瑰仙子
		{
			Item* RoseFairy = Seed::create("rosefairyseed");
			return RoseFairy;
		}
		case 8://amaranth苋菜
		{
			Item* Amaranth = Seed::create("amaranthseed");
			return Amaranth;
		}
		case 9://grape葡萄
		{
			Item* Grape = Seed::create("grapeseed");
			return Grape;
		}
		case 10://wheat小麦
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 11://artichoke洋蓟
		{
			Item* Artichoke = Seed::create("artichokeseed");
			return Artichoke;
		}
		case 12://grass seed草籽
		{
			Item* GrassSeed = Seed::create("grassseedseed");
			return GrassSeed;
		}
		case 13://grass seed formulation草籽配方
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar 糖
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour 大麦粉
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice 大米
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil 油
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar 醋
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer初级肥料
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer高級肥料
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil初级保湿土壤
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil高级保湿土壤
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplings樱桃树苗
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplings杏子树苗
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings橙子树苗
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplings桃子树苗
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplings石榴树苗
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplings苹果树苗
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers 花束
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

void Pierre::seasonEx(std::string season0) {
	season = season0;
	storeSeasonEx( season0);
}

std::string Pierre::seasonOut() {
	return season;
}

//铁匠铺部分

//物品对应数字
//  0--铜矿石
//  1--铁矿石
//  2--煤炭
//  3--黄金矿石
//  4--铜斧
//  5--铜水壶
//  6--铜镐
//  7--铜锄
//  8--铁斧
//  9--铁水壶
//  10--铁镐
//  11--铁锄
//  12--金斧
//  13--金水壶
//  14--金镐
//  15--金锄
//  16--铱斧
//  17--铱水壶
//  18--铱镐
//  19--铱锄
//对是否买得起的判断
bool BlackSmith::isAffordable(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore 铜矿石
	{
		if (Back->moneyOut() >= 75)
			return 1;
		else
			return 0;
	}
	case 1://iron ore 铁矿石
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 2://coal 煤炭
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 3://gold ore 黄金矿石
	{
		if (Back->moneyOut() >= 400)
			return 1;
		else
			return 0;
	}
	case 4://copper axe铜斧
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 5://copper wateringcan 铜水壶
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 6://copper pickaxe 铜镐
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 7://copper hoe 铜锄
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 8://iron axe 铁斧
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 9://iron wateringcan 铁水壶
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 10://iron pickaxe 铁镐
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 11://iron hoe 铁锄
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 12://gold axe 金斧
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 13://gold wateringcan 金水壶
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 14://gold pickaxe 金镐
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 15://gold hoe 金锄
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 16://iridium axe 铱斧
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 17://iridium wateringcan 铱水壶
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 18://iridium pickaxe 铱镐
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 19://iridium hoe 铱锄
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	}
	return 0;
}

//买下物品
Item* getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore 铜矿石
	{
		Item* CopperOre = terial::create("copperore");
		return CopperOre;
	}
	case 1://iron ore 铁矿石
	{
		Item* IronOre = terial::create("ironore");
		return IronOre;
	}
	case 2://coal 煤炭
	{
		Item* Coal = terial::create("coal");
		return Coal;
	}
	case 3://gold ore 黄金矿石
	{
		Item* GoldOre = terial::create("goldore");
		return GoldOre;
	}
	case 4://copper axe铜斧
	{
		Item* CopperAxe = Tool::create("copperaxe");
		return CopperAxe;
	}
	case 5://copper wateringcan 铜水壶
	{
		Item* CopperWateringcan = Tool::create("copperwateringcan");
		return CopperWateringcan;
	}
	case 6://copper pickaxe 铜镐
	{
		Item* CopperPickaxe = Tool::create("copperpickaxe");
		return CopperPickaxe;
	}
	case 7://copper hoe 铜锄
	{
		Item* CopperHoe = Tool::create("copperhoe");
		return CopperHoe;
	}
	case 8://iron axe 铁斧
	{
		Item* IronAxe = Tool::create("ironaxe");
		return IronAxe;
	}
	case 9://iron wateringcan 铁水壶
	{
		Item* IronWateringcan = Tool::create("ironwateringcan");
		return IronWateringcan;
	}
	case 10://iron pickaxe 铁镐
	{
		Item* IronPickaxe = Tool::create("ironpickaxe");
		return IronPickaxe;
	}
	case 11://iron hoe 铁锄
	{
		Item* IronHoe = Tool::create("ironhoe");
		return IronHoe;
	}
	case 12://gold axe 金斧
	{
		Item* GoldAxe = Tool::create("goldaxe");
		return GoldAxe;
	}
	case 13://gold wateringcan 金水壶
	{
		Item* GoldWateringcan = Tool::create("goldwateringcan");
		return GoldWateringcan;
	}
	case 14://gold pickaxe 金镐
	{
		Item* GoldPickaxe = Tool::create("goldpickaxe");
		return GoldPickaxe;
	}
	case 15://gold hoe 金锄
	{
		Item* GoldHoe= Tool::create("goldhoe");
		return GoldHoe;
	}
	case 16://iridium axe 铱斧
	{
		Item* IridiumAxe = Tool::create("iridiumaxe");
		return IridiumAxe;
	}
	case 17://iridium wateringcan 铱水壶
	{
		Item* IridiumWateringcan = Tool::create("iridiumwateringcan");
		return IridiumWateringcan;
	}
	case 18://iridium pickaxe 铱镐
	{
		Item* IridiumPickaxe = Tool::create("iridiumpickaxe");
		return IridiumPickaxe;
	}
	case 19://iridium hoe 铱锄
	{
		Item* IridiumHoe = Tool::create("iridiumhoe");
		return IridiumHoe;
	}
	}
	Item* null=new Item();
	return null;
}

// ============================================================
// Refactored with Facade Pattern (外观模式重构)
// ============================================================
// ShopFacade Class Implementation
// ============================================================

// ============================================================
// Constructor and Destructor
// ============================================================

/**
 * @brief Constructor - Initializes all subsystem instances
 * 
 * Refactored with Facade Pattern:
 * The facade creates and manages all subsystem objects internally,
 * hiding this complexity from the client.
 */
ShopFacade::ShopFacade(backPack* backpack, int craftGrade, int season)
    : m_backpack(backpack)
    , m_currentSeason(season)
    , m_craftTableGrade(craftGrade)
{
    // Initialize subsystem instances
    // These are encapsulated and not exposed to clients
    m_craftTable = new craftTable(craftGrade);
    m_pierreShop = new Pierre();
    m_blacksmithShop = new BlackSmith();
    
    // Set initial season for Pierre's shop
    std::string seasonStr;
    switch (season) {
        case 1: seasonStr = "Spring"; break;
        case 2: seasonStr = "Summer"; break;
        case 3: seasonStr = "Fall"; break;
        case 4: seasonStr = "Winter"; break;
        default: seasonStr = "Spring"; break;
    }
    m_pierreShop->seasonEx(seasonStr);
    
    CCLOG("[ShopFacade] Initialized with craftGrade=%d, season=%d", craftGrade, season);
}

/**
 * @brief Destructor - Cleans up subsystem instances
 */
ShopFacade::~ShopFacade() {
    // Clean up subsystem instances
    if (m_craftTable) {
        delete m_craftTable;
        m_craftTable = nullptr;
    }
    if (m_pierreShop) {
        delete m_pierreShop;
        m_pierreShop = nullptr;
    }
    if (m_blacksmithShop) {
        delete m_blacksmithShop;
        m_blacksmithShop = nullptr;
    }
    
    CCLOG("[ShopFacade] Destroyed");
}

// ============================================================
// Unified Public Interface Implementation
// Refactored with Facade Pattern
// ============================================================

/**
 * @brief Purchase item - Main unified interface
 * 
 * Refactored with Facade Pattern:
 * Before: Client needed to know which shop class to use and call different methods
 * After: Client uses single purchaseItem() method with shop type parameter
 */
ShopResult ShopFacade::purchaseItem(ShopType shopType, int itemId) {
    CCLOG("[ShopFacade] purchaseItem called - shopType=%s, itemId=%d", 
          getShopTypeName(shopType).c_str(), itemId);
    
    ShopResult result;
    
    // Validate backpack
    if (!m_backpack) {
        result.success = false;
        result.message = "Error: Backpack is null";
        CCLOG("[ShopFacade] Error: Backpack is null");
        return result;
    }
    
    // Delegate to appropriate shop based on type
    // This is the core of Facade Pattern - hiding complexity
    switch (shopType) {
        case ShopType::PIERRE:
            result = purchaseFromPierre(itemId);
            break;
            
        case ShopType::BLACKSMITH:
            result = purchaseFromBlacksmith(itemId);
            break;
            
        case ShopType::CRAFT_TABLE:
            // Crafting should use craftItem() method
            result.success = false;
            result.message = "Use craftItem() method for crafting";
            CCLOG("[ShopFacade] Warning: Use craftItem() for CRAFT_TABLE");
            break;
            
        default:
            result.success = false;
            result.message = "Unknown shop type";
            CCLOG("[ShopFacade] Error: Unknown shop type");
            break;
    }
    
    return result;
}

/**
 * @brief Craft item at crafting table
 * 
 * Refactored with Facade Pattern:
 * Before: Client needed to call changeForCraft(), getItem(), itemDelete() separately
 * After: Single craftItem() call handles everything
 */
ShopResult ShopFacade::craftItem(int itemId) {
    CCLOG("[ShopFacade] craftItem called - itemId=%d", itemId);
    
    return craftFromTable(itemId);
}

/**
 * @brief Check if player can afford item
 * 
 * Refactored with Facade Pattern:
 * Before: Client needed to call different methods for different shops
 * - craftTable::changeForCraft()
 * - Pierre::isAffordable()
 * - BlackSmith::isAffordable()
 * After: Single canAfford() method handles all cases
 */
bool ShopFacade::canAfford(ShopType shopType, int itemId) {
    if (!m_backpack) {
        CCLOG("[ShopFacade] canAfford: Backpack is null");
        return false;
    }
    
    bool result = false;
    
    switch (shopType) {
        case ShopType::CRAFT_TABLE:
            // Check if materials are available
            result = m_craftTable->changeForCraft(m_backpack, itemId);
            break;
            
        case ShopType::PIERRE:
            // Check if money is sufficient
            result = m_pierreShop->isAffordable(m_backpack, itemId, m_currentSeason);
            break;
            
        case ShopType::BLACKSMITH:
            // Check if money is sufficient
            result = m_blacksmithShop->isAffordable(m_backpack, itemId);
            break;
            
        default:
            result = false;
            break;
    }
    
    CCLOG("[ShopFacade] canAfford: shopType=%s, itemId=%d, result=%s",
          getShopTypeName(shopType).c_str(), itemId, result ? "true" : "false");
    
    return result;
}

/**
 * @brief Get item price
 * 
 * Refactored with Facade Pattern:
 * Before: Client needed to call Pierre::itemMoneyBack() with season parameter
 * After: Single getItemPrice() handles all cases, season managed internally
 */
int ShopFacade::getItemPrice(ShopType shopType, int itemId) {
    switch (shopType) {
        case ShopType::PIERRE:
            return m_pierreShop->itemMoneyBack(itemId, m_currentSeason);
            
        case ShopType::BLACKSMITH:
            // BlackSmith doesn't have a direct price query method
            // Return -1 to indicate need to check documentation
            return -1;
            
        case ShopType::CRAFT_TABLE:
            // Crafting doesn't have money cost
            return 0;
            
        default:
            return -1;
    }
}

/**
 * @brief Get item name
 * 
 * Refactored with Facade Pattern:
 * Provides unified way to get item names across all shop types
 */
std::string ShopFacade::getItemName(ShopType shopType, int itemId, bool includeExtension) {
    switch (shopType) {
        case ShopType::PIERRE:
            return m_pierreShop->itemNameOut(itemId, m_currentSeason, includeExtension);
            
        case ShopType::CRAFT_TABLE:
            // For craft table, we can derive name from the item
            {
                // Get item to extract name (note: this creates a temporary item)
                Item* tempItem = m_craftTable->getItem(itemId);
                if (tempItem) {
                    std::string name = tempItem->name;
                    if (includeExtension) {
                        name += ".png";
                    }
                    // Don't delete tempItem here as it might be used elsewhere
                    return name;
                }
                return "unknown";
            }
            
        case ShopType::BLACKSMITH:
            // BlackSmith items - return based on itemId
            // TODO: Implement proper item name lookup for BlackSmith
            return "blacksmith_item_" + std::to_string(itemId);
            
        default:
            return "unknown";
    }
}

/**
 * @brief Get crafting recipe
 * 
 * Refactored with Facade Pattern:
 * Wraps craftTable::factorBack() for consistency
 */
std::string ShopFacade::getCraftRecipe(int itemId) {
    return m_craftTable->factorBack(itemId);
}

// ============================================================
// Configuration Methods Implementation
// ============================================================

void ShopFacade::setSeason(int season) {
    m_currentSeason = season;
    
    // Update Pierre's shop season
    std::string seasonStr;
    switch (season) {
        case 1: seasonStr = "Spring"; break;
        case 2: seasonStr = "Summer"; break;
        case 3: seasonStr = "Fall"; break;
        case 4: seasonStr = "Winter"; break;
        default: seasonStr = "Spring"; break;
    }
    m_pierreShop->seasonEx(seasonStr);
    
    CCLOG("[ShopFacade] Season set to %d (%s)", season, seasonStr.c_str());
}

int ShopFacade::getSeason() const {
    return m_currentSeason;
}

void ShopFacade::setCraftTableGrade(int grade) {
    m_craftTableGrade = grade;
    m_craftTable->gradeExchange(grade);
    CCLOG("[ShopFacade] Craft table grade set to %d", grade);
}

int ShopFacade::getCraftTableGrade() const {
    return m_craftTableGrade;
}

int ShopFacade::getPlayerMoney() const {
    if (m_backpack) {
        return m_backpack->moneyOut();
    }
    return 0;
}

// ============================================================
// Private Helper Methods Implementation
// Refactored with Facade Pattern
// ============================================================

/**
 * @brief Internal implementation for Pierre's shop purchase
 * 
 * Encapsulates the complexity of:
 * 1. Checking affordability
 * 2. Getting price
 * 3. Deducting money
 * 4. Getting item
 * 5. Adding to backpack
 */
ShopResult ShopFacade::purchaseFromPierre(int itemId) {
    ShopResult result;
    
    // Step 1: Check if affordable
    if (!m_pierreShop->isAffordable(m_backpack, itemId, m_currentSeason)) {
        result.success = false;
        result.message = "Not enough money to purchase from Pierre's shop";
        CCLOG("[ShopFacade] Pierre purchase failed: Not enough money");
        return result;
    }
    
    // Step 2: Get price
    int price = m_pierreShop->itemMoneyBack(itemId, m_currentSeason);
    
    // Step 3: Get item
    Item* item = m_pierreShop->getItem(m_backpack, itemId, m_currentSeason);
    if (!item) {
        result.success = false;
        result.message = "Failed to get item from Pierre's shop";
        CCLOG("[ShopFacade] Pierre purchase failed: Item is null");
        return result;
    }
    
    // Step 4: Add to backpack
    if (!m_backpack->itemAdd(item, 1)) {
        result.success = false;
        result.message = "Backpack is full";
        CCLOG("[ShopFacade] Pierre purchase failed: Backpack full");
        // Note: Item was created but not added - potential memory leak in original code
        return result;
    }
    
    // Step 5: Deduct money
    m_backpack->moneyChange(price, false);  // false = subtract
    
    // Success
    result.success = true;
    result.item = item;
    result.cost = price;
    result.message = "Successfully purchased from Pierre's shop";
    
    CCLOG("[ShopFacade] Pierre purchase success: itemId=%d, cost=%d", itemId, price);
    
    return result;
}

/**
 * @brief Internal implementation for Blacksmith purchase
 * 
 * Encapsulates the complexity of:
 * 1. Checking affordability
 * 2. Getting item
 * 3. Deducting money
 * 4. Adding to backpack
 */
ShopResult ShopFacade::purchaseFromBlacksmith(int itemId) {
    ShopResult result;
    
    // Step 1: Check if affordable
    if (!m_blacksmithShop->isAffordable(m_backpack, itemId)) {
        result.success = false;
        result.message = "Not enough money to purchase from Blacksmith";
        CCLOG("[ShopFacade] Blacksmith purchase failed: Not enough money");
        return result;
    }
    
    // Step 2: Get item
    Item* item = m_blacksmithShop->getItem(m_backpack, itemId);
    if (!item) {
        result.success = false;
        result.message = "Failed to get item from Blacksmith";
        CCLOG("[ShopFacade] Blacksmith purchase failed: Item is null");
        return result;
    }
    
    // Step 3: Add to backpack
    if (!m_backpack->itemAdd(item, 1)) {
        result.success = false;
        result.message = "Backpack is full";
        CCLOG("[ShopFacade] Blacksmith purchase failed: Backpack full");
        return result;
    }
    
    // Step 4: Deduct money (prices are hardcoded in BlackSmith::isAffordable)
    // We need to get the price from the hardcoded values
    int price = 0;
    switch (itemId) {
        case 0: price = 75; break;      // copper ore
        case 1: price = 150; break;     // iron ore
        case 2: price = 150; break;     // coal
        case 3: price = 400; break;     // gold ore
        case 4: case 5: case 6: case 7: price = 2000; break;  // copper tools
        case 8: case 9: case 10: case 11: price = 5000; break; // iron tools
        case 12: case 13: case 14: case 15: price = 10000; break; // gold tools
        case 16: case 17: case 18: case 19: price = 25000; break; // iridium tools
        default: price = 0; break;
    }
    
    m_backpack->moneyChange(price, false);  // false = subtract
    
    // Success
    result.success = true;
    result.item = item;
    result.cost = price;
    result.message = "Successfully purchased from Blacksmith";
    
    CCLOG("[ShopFacade] Blacksmith purchase success: itemId=%d, cost=%d", itemId, price);
    
    return result;
}

/**
 * @brief Internal implementation for crafting
 * 
 * Encapsulates the complexity of:
 * 1. Checking materials availability
 * 2. Deleting required materials
 * 3. Creating crafted item
 * 4. Adding to backpack
 * 
 * Before Facade Pattern, client code needed to:
 * @code
 *   craftTable* table = new craftTable(1);
 *   if (table->changeForCraft(backpack, itemId)) {
 *       Item* item = table->getItem(itemId);
 *       table->itemDelete(backpack, itemId);
 *       backpack->itemAdd(item, 1);
 *   }
 * @endcode
 * 
 * After Facade Pattern, client code is simply:
 * @code
 *   ShopResult result = shopFacade->craftItem(itemId);
 * @endcode
 */
ShopResult ShopFacade::craftFromTable(int itemId) {
    ShopResult result;
    
    // Step 1: Check if materials are available
    if (!m_craftTable->changeForCraft(m_backpack, itemId)) {
        result.success = false;
        result.message = "Not enough materials to craft";
        std::string recipe = m_craftTable->factorBack(itemId);
        result.message += " (Required: " + recipe + ")";
        CCLOG("[ShopFacade] Craft failed: Not enough materials for itemId=%d", itemId);
        return result;
    }
    
    // Step 2: Get the crafted item
    Item* item = m_craftTable->getItem(itemId);
    if (!item) {
        result.success = false;
        result.message = "Failed to create crafted item";
        CCLOG("[ShopFacade] Craft failed: Item creation returned null");
        return result;
    }
    
    // Step 3: Delete required materials
    m_craftTable->itemDelete(m_backpack, itemId);
    
    // Step 4: Add crafted item to backpack
    if (!m_backpack->itemAdd(item, 1)) {
        result.success = false;
        result.message = "Backpack is full, cannot add crafted item";
        CCLOG("[ShopFacade] Craft failed: Backpack full");
        // Note: Materials already deleted, item created but not added
        // This is a limitation of the original design
        return result;
    }
    
    // Success
    result.success = true;
    result.item = item;
    result.cost = 0;  // Crafting has no gold cost
    result.message = "Successfully crafted item";
    
    CCLOG("[ShopFacade] Craft success: itemId=%d", itemId);
    
    return result;
}

// ============================================================
// Utility Methods Implementation
// ============================================================

std::string ShopFacade::getShopTypeName(ShopType shopType) {
    switch (shopType) {
        case ShopType::CRAFT_TABLE:
            return "CraftTable";
        case ShopType::PIERRE:
            return "Pierre";
        case ShopType::BLACKSMITH:
            return "BlackSmith";
        default:
            return "Unknown";
    }
}

// ============================================================