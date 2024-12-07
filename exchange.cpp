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
//ºÏ³ÉÌ¨²¿·Ö

//¶ÔÎïÆ·ÊÇ·ñ¿ÉºÏ³ÉµÄÅÐ¶Ï
bool craftTable::changeForCraft(backPack* Back,int itemToMake) {
	switch (itemToMake) {
	case 0://Ä¾ÅÆ
	{
		Item* WoodenSign = terial::create("wood");
		if (Back->matchJudge(WoodenSign, amountOfWoodForWoodenSign))
			return 1;
		else
			return 0;
		break;
	}
	case 1://Ä¾Õ¤À¸
	{
		Item* WoodFence = terial::create("wood");
		if (Back->matchJudge(WoodFence, amountOfWoodForWoodFence))
			return 1;
		else
			return 0;
		break;
	}
	case 2://´óÃÅ
	{
		Item* Gate = terial::create("wood");
		if (Back->matchJudge(Gate, amountOfWoodForGate))
			return 1;
		else
			return 0;
		break;
	}
	case 3://²Ý×Ñ
	{
		Item* GrassStarter = terial::create("fibre");
		if (Back->matchJudge(GrassStarter, amountOfFibreForGrassStarter))
			return 1;
		else
			return 0;
		break;
	}
	case 4://Ä¾¾¶
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

//ºÏ³ÉÎïÆ·
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

//PierreÉÌµê²¿·Ö

//¶ÔÊÇ·ñÂòµÃÆðµÄÅÐ¶Ï
bool Pierre::isAffordable(backPack* Back, int itemToMake,int season) {
	switch (season) {
	case 1:
		switch (itemToMake) {
			case 0://Parsnip·À·ç²Ý
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 1://GreenBeanÇà¶¹
				if (Back->moneyOut() >= 60)
					return 1;
				else
					return 0;
			case 2://cauliflower»¨Ò¬²Ë
				if (Back->moneyOut() >= 80)
					return 1;
				else
					return 0;
			case 3://potatoÍÁ¶¹
				if (Back->moneyOut() >= 50)
					return 1;
				else
					return 0;
			case 4://Tulip bulbsÓô½ðÏãÇò¾¥
				if (Back->moneyOut() >= 20)
					return 1;
				else
					return 0;
			case 5://cabbage¸ÊÀ¶
				if (Back->moneyOut() >= 70)
					return 1;
				else
					return 0;
			case 6://Blue Jazz À¶¾ôÊ¿
				if (Back->moneyOut() >= 30)
					return 1;
				else
					return 0;
			case 7://Garlic´óËâ
				if(Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 8://rice seedlingµ¾Ãç
				if (Back->moneyOut() >= 40)
					return 1;
				else
					return 0;
			case 9://grass seed²Ý×Ñ
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 10://grass seed formulation²Ý×ÑÅä·½
				if (Back->moneyOut() >= 1000)
					return 1;
				else
					return 0;
			case 11://sugar ÌÇ
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 12://barley flour ´óÂó·Û
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 13://rice ´óÃ×
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 14://oil ÓÍ
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 15://vinegar ´×
				if (Back->moneyOut() >= 200)
					return 1;
				else
					return 0;
			case 16://Basic Fertilizer³õ¼¶·ÊÁÏ
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 17://Senior Fertilizer¸ß¼‰·ÊÁÏ
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 18://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
				if (Back->moneyOut() >= 100)
					return 1;
				else
					return 0;
			case 19://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
				if (Back->moneyOut() >= 150)
					return 1;
				else
					return 0;
			case 20://Cherry saplingsÓ£ÌÒÊ÷Ãç
				if (Back->moneyOut() >= 3400)
					return 1;
				else
					return 0;
			case 21://Apricot saplingsÐÓ×ÓÊ÷Ãç
				if (Back->moneyOut() >= 2000)
					return 1;
				else
					return 0;
			case 22://Orange saplings³È×ÓÊ÷Ãç
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 23://Peach saplingsÌÒ×ÓÊ÷Ãç
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 24://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
				if (Back->moneyOut() >= 6000)
					return 1;
				else
					return 0;
			case 25://Apple saplingsÆ»¹ûÊ÷Ãç
				if (Back->moneyOut() >= 4000)
					return 1;
				else
					return 0;
			case 26://flowers »¨Êø
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
		case 0://melonÌð¹Ï
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 1://tomatoÎ÷ºìÊÁ
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 2://blueburryÀ¶Ý®
			if (Back->moneyOut() >= 80)
				return 1;
			else
				return 0;
		case 3://chili pepperÀ±½·
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 4://wheatÐ¡Âó
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 5://turnipÂÜ²·
			if (Back->moneyOut() >= 40)
				return 1;
			else
				return 0;
		case 6://Poppies ÓÝÃÀÈË
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 7://Summer sequinsÏÄ¼¾ÁÁÆ¬
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 8://hop Æ¡¾Æ»¨
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 9://cornÓñÃ×
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 10://sunflowerÏòÈÕ¿û
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 11://Red leaf cabbageºìÒ¶¾íÐÄ²Ë
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 12://grass seed²Ý×Ñ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation²Ý×ÑÅä·½
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ÌÇ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour ´óÂó·Û
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ´óÃ×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ÓÍ
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ´×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers »¨Êø
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
		case 0://eggplantÇÑ×Ó
			if (Back->moneyOut() >= 20)
				return 1;
			else
				return 0;
		case 1://cornÓñÃ×
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 2://pumpkinÄÏ¹Ï
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 3://Chinese cabbageÐ¡°×²Ë
			if (Back->moneyOut() >= 50)
				return 1;
			else
				return 0;
		case 4://yamÉ½Ò©
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 5://CranberriesÂûÔ½Ý®
			if (Back->moneyOut() >= 240)
				return 1;
			else
				return 0;
		case 6://sunflower ÏòÈÕ¿û
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 7://Rose FairyÃµ¹åÏÉ×Ó
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 8://amaranthÜÈ²Ë
			if (Back->moneyOut() >= 70)
				return 1;
			else
				return 0;
		case 9://grapeÆÏÌÑ
			if (Back->moneyOut() >= 60)
				return 1;
			else
				return 0;
		case 10://wheatÐ¡Âó
			if (Back->moneyOut() >= 10)
				return 1;
			else
				return 0;
		case 11://artichokeÑó¼»
			if (Back->moneyOut() >= 30)
				return 1;
			else
				return 0;
		case 12://grass seed²Ý×Ñ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 13://grass seed formulation²Ý×ÑÅä·½
			if (Back->moneyOut() >= 1000)
				return 1;
			else
				return 0;
		case 14://sugar ÌÇ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 15://barley flour ´óÂó·Û
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 16://rice ´óÃ×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 17://oil ÓÍ
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 18://vinegar ´×
			if (Back->moneyOut() >= 200)
				return 1;
			else
				return 0;
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 100)
				return 1;
			else
				return 0;
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
			if (Back->moneyOut() >= 150)
				return 1;
			else
				return 0;
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
			if (Back->moneyOut() >= 3400)
				return 1;
			else
				return 0;
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 2000)
				return 1;
			else
				return 0;
		case 25://Orange saplings³È×ÓÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
			if (Back->moneyOut() >= 6000)
				return 1;
			else
				return 0;
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
			if (Back->moneyOut() >= 4000)
				return 1;
			else
				return 0;
		case 29://flowers »¨Êø
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

//ÂòÏÂÎïÆ·
Item* Pierre::getItem(backPack* Back, int itemToMake, int season) {
	switch (season){
	case 1:
		switch (itemToMake) {
		case 0://Parsnip·À·ç²Ý
		{
			Item* Parsnip = Seed::create("parsnipseed");
			return Parsnip;
		}
		case 1://GreenBeanÇà¶¹
		{
			Item* GreenBean = Seed::create("greenbean");
			return GreenBean;
		}
		case 2://cauliflower»¨Ò¬²Ë
		{
			Item* Cauliflower = Seed::create("cauliflower");
			return Cauliflower;
		}
		case 3://potatoÍÁ¶¹
		{
			Item* Potato = Seed::create("potato");
			return Potato;
		}
		case 4://Tulip bulbsÓô½ðÏãÇò¾¥
		{
			Item* TulipBulbs = Seed::create("tulipbulbs");
			return TulipBulbs;
		}
		case 5://cabbage¸ÊÀ¶
		{
			Item* Cabbage = Seed::create("cabbage");
			return Cabbage;
		}
		case 6://Blue Jazz À¶¾ôÊ¿
		{
			Item* BlueJazz = Seed::create("bluejazz");
			return BlueJazz;
		}
		case 7://Garlic´óËâ
		{
			Item* Garlic = Seed::create("garlic");
			return Garlic;
		}
		case 8://rice seedlingµ¾Ãç
		{
			Item* RiceSeedling = Seed::create("riceseedling");
			return RiceSeedling;
		}
		case 9://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 10://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 11://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 12://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 13://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 14://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 15://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 16://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 17://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 18://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 19://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 20://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 21://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 22://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 23://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 24://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 25://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 26://flowers »¨Êø
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
		case 0://melonÌð¹Ï
		{
			Item* Melon = Seed::create("melonseed");
			return Melon;
		}
		case 1://tomatoÎ÷ºìÊÁ
		{
			Item* Tomato = Seed::create("tomatoseed");
			return Tomato;
		}
		case 2://blueburryÀ¶Ý®
		{
			Item* Blueburry = Seed::create("blueburryseed");
			return Blueburry;
		}
		case 3://chili pepperÀ±½·
		{
			Item* ChiliPepper = Seed::create("chilipepperseed");
			return ChiliPepper;
		}
		case 4://wheatÐ¡Âó
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 5://turnipÂÜ²·
		{
			Item* Turnip = Seed::create("turnipseed");
			return Turnip;
		}
		case 6://Poppies ÓÝÃÀÈË
		{
			Item* Poppies = Seed::create("poppiesseed");
			return Poppies;
		}
		case 7://Summer sequinsÏÄ¼¾ÁÁÆ¬
		{
			Item* SummerSequins = Seed::create("summersequinsseed");
			return SummerSequins;
		}
		case 8://hop Æ¡¾Æ»¨
		{
			Item* Hop = Seed::create("hopseed");
			return Hop;
		}
		case 9://cornÓñÃ×
		{
			Item* Corn = Seed::create("cornseedseed");
			return Corn;
		}
		case 10://sunflowerÏòÈÕ¿û
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 11://Red leaf cabbageºìÒ¶¾íÐÄ²Ë
		{
			Item* RedLeafCabbage = Seed::create("redleafcabbageseed");
			return RedLeafCabbage;
		}
		case 12://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseed");
			return GrassSeed;
		}
		case 13://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers »¨Êø
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
		case 0://eggplantÇÑ×Ó
		{
			Item* Eggplant = Seed::create("eggplantseed");
			return Eggplant;
		}
		case 1://cornÓñÃ×
		{
			Item* Corn = Seed::create("cornseed");
			return Corn;
		}
		case 2://pumpkinÄÏ¹Ï
		{
			Item* Pumpkin = Seed::create("pumpkinseed");
			return Pumpkin;
		}
		case 3://Chinese cabbageÐ¡°×²Ë
		{
			Item* ChineseCabbage = Seed::create("chinesecabbageseed");
			return ChineseCabbage;
		}
		case 4://yamÉ½Ò©
		{
			Item* Yam = Seed::create("yamseed");
			return Yam;
		}
		case 5://CranberriesÂûÔ½Ý®
		{
			Item* Cranberries = Seed::create("cranberriesseed");
			return Cranberries;
		}
		case 6://sunflower ÏòÈÕ¿û
		{
			Item* Sunflower = Seed::create("sunflowerseed");
			return Sunflower;
		}
		case 7://Rose FairyÃµ¹åÏÉ×Ó
		{
			Item* RoseFairy = Seed::create("rosefairyseed");
			return RoseFairy;
		}
		case 8://amaranthÜÈ²Ë
		{
			Item* Amaranth = Seed::create("amaranthseed");
			return Amaranth;
		}
		case 9://grapeÆÏÌÑ
		{
			Item* Grape = Seed::create("grapeseed");
			return Grape;
		}
		case 10://wheatÐ¡Âó
		{
			Item* Wheat = Seed::create("wheatseed");
			return Wheat;
		}
		case 11://artichokeÑó¼»
		{
			Item* Artichoke = Seed::create("artichokeseed");
			return Artichoke;
		}
		case 12://grass seed²Ý×Ñ
		{
			Item* GrassSeed = Seed::create("grassseedseed");
			return GrassSeed;
		}
		case 13://grass seed formulation²Ý×ÑÅä·½
		{
			Item* GrassSeedFormulation = Tool::create("grassseedformulation");
			return GrassSeedFormulation;
		}
		case 14://sugar ÌÇ
		{
			Item* Sugar = Tool::create("sugar");
			return Sugar;
		}
		case 15://barley flour ´óÂó·Û
		{
			Item* BarleyFlour = Tool::create("barleyflour");
			return BarleyFlour;
		}
		case 16://rice ´óÃ×
		{
			Item* Rice = Tool::create("rice");
			return Rice;
		}
		case 17://oil ÓÍ
		{
			Item* Oil = Tool::create("oil");
			return Oil;
		}
		case 18://vinegar ´×
		{
			Item* Vinegar = Tool::create("vinegar");
			return Vinegar;
		}
		case 19://Basic Fertilizer³õ¼¶·ÊÁÏ
		{
			Item* BasicFertilizer = Tool::create("basicfertilizer");
			return BasicFertilizer;
		}
		case 20://Senior Fertilizer¸ß¼‰·ÊÁÏ
		{
			Item* SeniorFertilizer = Tool::create("seniorfertilizer");
			return SeniorFertilizer;
		}
		case 21://Basic remaining soil³õ¼¶±£ÊªÍÁÈÀ
		{
			Item* BasicRemainingSoil = Tool::create("basicremainingsoil");
			return BasicRemainingSoil;
		}
		case 22://Senior remaining soil¸ß¼¶±£ÊªÍÁÈÀ
		{
			Item* SeniorRemainingSoil = Tool::create("seniorremainingsoil");
			return SeniorRemainingSoil;
		}
		case 23://Cherry saplingsÓ£ÌÒÊ÷Ãç
		{
			Item* CherrySaplings = Seed::create("cherrysaplings");
			return CherrySaplings;
		}
		case 24://Apricot saplingsÐÓ×ÓÊ÷Ãç
		{
			Item* ApricotSaplings = Seed::create("apricotsaplings");
			return ApricotSaplings;
		}
		case 25://Orange saplings³È×ÓÊ÷Ãç
		{
			Item* OrangeSaplings = Seed::create("orangesaplings");
			return OrangeSaplings;
		}
		case 26://Peach saplingsÌÒ×ÓÊ÷Ãç
		{
			Item* PeachSaplings = Seed::create("peachsaplings");
			return PeachSaplings;
		}
		case 27://Pomegranate saplingsÊ¯ÁñÊ÷Ãç
		{
			Item* PomegranateSaplings = Seed::create("pomegranatesaplings");
			return PomegranateSaplings;
		}
		case 28://Apple saplingsÆ»¹ûÊ÷Ãç
		{
			Item* AppleSaplings = Seed::create("applesaplings");
			return AppleSaplings;
		}
		case 29://flowers »¨Êø
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

//Ìú½³ÆÌ²¿·Ö

//¶ÔÊÇ·ñÂòµÃÆðµÄÅÐ¶Ï
bool BlackSmith::isAffordable(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore Í­¿óÊ¯
	{
		if (Back->moneyOut() >= 75)
			return 1;
		else
			return 0;
	}
	case 1://iron ore Ìú¿óÊ¯
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 2://coal ÃºÌ¿
	{
		if (Back->moneyOut() >= 150)
			return 1;
		else
			return 0;
	}
	case 3://gold ore »Æ½ð¿óÊ¯
	{
		if (Back->moneyOut() >= 400)
			return 1;
		else
			return 0;
	}
	case 4://copper axeÍ­¸«
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 5://copper wateringcan Í­Ë®ºø
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 6://copper pickaxe Í­¸ä
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 7://copper hoe Í­³ú
	{
		if (Back->moneyOut() >= 2000)
			return 1;
		else
			return 0;
	}
	case 8://iron axe Ìú¸«
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 9://iron wateringcan ÌúË®ºø
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 10://iron pickaxe Ìú¸ä
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 11://iron hoe Ìú³ú
	{
		if (Back->moneyOut() >= 5000)
			return 1;
		else
			return 0;
	}
	case 12://gold axe ½ð¸«
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 13://gold wateringcan ½ðË®ºø
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 14://gold pickaxe ½ð¸ä
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 15://gold hoe ½ð³ú
	{
		if (Back->moneyOut() >= 10000)
			return 1;
		else
			return 0;
	}
	case 16://iridium axe Ò¿¸«
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 17://iridium wateringcan Ò¿Ë®ºø
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 18://iridium pickaxe Ò¿¸ä
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	case 19://iridium hoe Ò¿³ú
	{
		if (Back->moneyOut() >= 25000)
			return 1;
		else
			return 0;
	}
	}
	return 0;
}

//ÂòÏÂÎïÆ·
Item* getItem(backPack* Back, int itemToMake) {
	switch (itemToMake) {
	case 0://copper ore Í­¿óÊ¯
	{
		Item* CopperOre = terial::create("copperore");
		return CopperOre;
	}
	case 1://iron ore Ìú¿óÊ¯
	{
		Item* IronOre = terial::create("ironore");
		return IronOre;
	}
	case 2://coal ÃºÌ¿
	{
		Item* Coal = terial::create("coal");
		return Coal;
	}
	case 3://gold ore »Æ½ð¿óÊ¯
	{
		Item* GoldOre = terial::create("goldore");
		return GoldOre;
	}
	case 4://copper axeÍ­¸«
	{
		Item* CopperAxe = Tool::create("copperaxe");
		return CopperAxe;
	}
	case 5://copper wateringcan Í­Ë®ºø
	{
		Item* CopperWateringcan = Tool::create("copperwateringcan");
		return CopperWateringcan;
	}
	case 6://copper pickaxe Í­¸ä
	{
		Item* CopperPickaxe = Tool::create("copperpickaxe");
		return CopperPickaxe;
	}
	case 7://copper hoe Í­³ú
	{
		Item* CopperHoe = Tool::create("copperhoe");
		return CopperHoe;
	}
	case 8://iron axe Ìú¸«
	{
		Item* IronAxe = Tool::create("ironaxe");
		return IronAxe;
	}
	case 9://iron wateringcan ÌúË®ºø
	{
		Item* IronWateringcan = Tool::create("ironwateringcan");
		return IronWateringcan;
	}
	case 10://iron pickaxe Ìú¸ä
	{
		Item* IronPickaxe = Tool::create("ironpickaxe");
		return IronPickaxe;
	}
	case 11://iron hoe Ìú³ú
	{
		Item* IronHoe = Tool::create("ironhoe");
		return IronHoe;
	}
	case 12://gold axe ½ð¸«
	{
		Item* GoldAxe = Tool::create("goldaxe");
		return GoldAxe;
	}
	case 13://gold wateringcan ½ðË®ºø
	{
		Item* GoldWateringcan = Tool::create("goldwateringcan");
		return GoldWateringcan;
	}
	case 14://gold pickaxe ½ð¸ä
	{
		Item* GoldPickaxe = Tool::create("goldpickaxe");
		return GoldPickaxe;
	}
	case 15://gold hoe ½ð³ú
	{
		Item* GoldHoe= Tool::create("goldhoe");
		return GoldHoe;
	}
	case 16://iridium axe Ò¿¸«
	{
		Item* IridiumAxe = Tool::create("iridiumaxe");
		return IridiumAxe;
	}
	case 17://iridium wateringcan Ò¿Ë®ºø
	{
		Item* IridiumWateringcan = Tool::create("iridiumwateringcan");
		return IridiumWateringcan;
	}
	case 18://iridium pickaxe Ò¿¸ä
	{
		Item* IridiumPickaxe = Tool::create("iridiumpickaxe");
		return IridiumPickaxe;
	}
	case 19://iridium hoe Ò¿³ú
	{
		Item* IridiumHoe = Tool::create("iridiumhoe");
		return IridiumHoe;
	}
	}
	Item* null;
	return null;
}
