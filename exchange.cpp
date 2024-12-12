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
	case 18://春日野种
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

//合成物品
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
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 1://GreenBean青豆
				if (Back->moneyOut() >= 60)
					return 1;
				else
					return 0;
			case 2://cauliflower花椰菜
				if (Back->moneyOut() >= 80)
					return 1;
				else
					return 0;
			case 3://potato土豆
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 4://Tulip bulbs郁金香球茎
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 5://cabbage甘蓝
				if (Back->moneyOut() >= 70)
					return 1;
				else
					return 0;
			case 6://Blue Jazz 蓝爵士
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 7://Garlic大蒜
				if(Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 8://rice seedling稻苗
				if (Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 9://grass seed草籽
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 10://grass seed formulation草籽配方
				if (Back->moneyOut() >= 1000)
					return 1;
				else
					return 0;
			case 11://sugar 糖
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 12://barley flour 大麦粉
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 13://rice 大米
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 14://oil 油
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 15://vinegar 醋
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer初级肥料
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer高級肥料
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil初级保湿土壤
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil高级保湿土壤
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 20://Cherry saplings樱桃树苗
				if (Back->moneyOut() >= 3400)
					return 1;
				else
					return 0;
			case 21://Apricot saplings杏子树苗
				if (Back->moneyOut() >= 2000)
					return 1;
				else
					return 0;
			case 22://Orange saplings橙子树苗
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 23://Peach saplings桃子树苗
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplings石榴树苗
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 25://Apple saplings苹果树苗
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 26://flowers 花束
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
