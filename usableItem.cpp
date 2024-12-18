/****************************************************************
 * Project Name: xinglugu-project
 * File Name:usableItem.cpp
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
 * License:
 ****************************************************************/
#include"usableItem.h"
#include"Constants.h"
#include"Timer.h"
USING_NS_CC;
using namespace Constants;
//----基类Item

//数量更改函数
void Item::quantityChange(bool way, int amount) {
	if (way == wayOfAdd)
		quantity += amount;
	else
		quantity -= amount;
}

//文件名返回
char const* Item::filenameReturn() {
	return pictureName;
}

//物品是否可卖
bool Item::isSoldAble() {
	if (itemtype == ItemType::null || itemtype == ItemType::tool)
		return 0;
	else
		return 1;
}

//物品价值
int Item::moneyToSell() {

	return 0;
}

std::string Item::nameBack() {
	return name;
}

//左键的作用
void Item::leftKeyFunction() {
	;
}

//右键的作用
void Item::rightKeyFunction() {
	;
}

//----子类Fish

//右键 （吃）
void Fish::rightKeyFunction() {
	;
}

//卖钱
int Fish::moneyToSell(std::string season) {
	int outmoney = 0;
	switch (currentSeed) {
	case SeedKind::blowfish:
	{
		switch (quality) {
		case 1:
			outmoney = blowfish1;
			break;
		case 2:
			outmoney = blowfish2;
			break;
		case 3:
			outmoney = blowfish3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::tuna:
	{
		switch (quality) {
		case 1:
			outmoney = tuna1;
			break;
		case 2:
			outmoney = tuna2;
			break;
		case 3:
			outmoney = tuna3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::sardine: {
		switch (quality) {
		case 1:
			outmoney = sardine1;
			break;
		case 2:
			outmoney = sardine2;
			break;
		case 3:
			outmoney = sardine3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::largemouthbass: {
		switch (quality) {
		case 1:
			outmoney = largemouthbass1;
			break;
		case 2:
			outmoney = largemouthbass2;
			break;
		case 3:
			outmoney = largemouthbass3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::smallmouthbass: {
		switch (quality) {
		case 1:
			outmoney = smallmouthbass1;
			break;
		case 2:
			outmoney = smallmouthbass2;
			break;
		case 3:
			outmoney = smallmouthbass3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::sunfish: {
		switch (quality) {
		case 1:
			outmoney = sunfish1;
			break;
		case 2:
			outmoney = sunfish2;
			break;
		case 3:
			outmoney = sunfish3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::salmon: {
		switch (quality) {
		case 1:
			outmoney = salmon1;
			break;
		case 2:
			outmoney = salmon2;
			break;
		case 3:
			outmoney = salmon3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::catfish: {
		switch (quality) {
		case 1:
			outmoney = catfish1;
			break;
		case 2:
			outmoney = catfish2;
			break;
		case 3:
			outmoney = catfish3;
			break;
		default:
			outmoney = 0;
			break;
		}
		break;
	}
	case SeedKind::carp: {
		switch (quality) {
		case 1:
			outmoney = carp1;
			break;
		case 2:
			outmoney = carp2;
			break;
		case 3:
			outmoney = carp3;
			break;
		default:
			outmoney = 0;
			break;
		}
	}
	default:
		outmoney = 0;
		break;
	}
	if (season == "Spring")
		outmoney *= 1;
	else {
		if (season == "Summer")
			outmoney *= 0.6;
		else {
			if (season == "Fall")
				outmoney *= 0.8;
			else
				outmoney *= 1.4;
		}
	}
	return outmoney ;
}

//----子类Seed

 //卖钱
int Seed::moneyToSell(std::string season) {
	int sellmoney=0;
	switch (currentSeed) {
	case SeedKind::parsnipseed:
	{
		if(season=="Spring")
			sellmoney = parsnipseed1;
		else {
			if (season == "Summer")
				sellmoney = parsnipseed1*0.85;
			else {
				if (season == "Fall")
					sellmoney = parsnipseed1 * 0.65;
				else
					sellmoney = parsnipseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::greenbeanseed:
	{
		if (season == "Spring")
			sellmoney = greenbeanseed1;
		else {
			if (season == "Summer")
				sellmoney = greenbeanseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = greenbeanseed1 * 0.65;
				else
					sellmoney = greenbeanseed1 * 0.45;
			}
		}	
		break;
	}
	case SeedKind::cauliflowerseed: {
		if (season == "Spring")
			sellmoney = cauliflowerseed1;
		else {
			if (season == "Summer")
				sellmoney = cauliflowerseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = cauliflowerseed1 * 0.65;
				else
					sellmoney = cauliflowerseed1 * 0.45;
			}
		}
		
		break;
	}
	case SeedKind::potatoseed: {
		if (season == "Spring")
			sellmoney = potatoseed1;
		else {
			if (season == "Summer")
				sellmoney = potatoseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = potatoseed1 * 0.65;
				else
					sellmoney = potatoseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::tulipbulbsseed: {
		if (season == "Spring")
			sellmoney = tulipbulbsseed1;
		else {
			if (season == "Summer")
				sellmoney = tulipbulbsseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = tulipbulbsseed1 * 0.65;
				else
					sellmoney = tulipbulbsseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::cabbageseed: {
		if (season == "Spring")
			sellmoney = cabbageseed1;
		else {
			if (season == "Summer")
				sellmoney = cabbageseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = cabbageseed1 * 0.65;
				else
					sellmoney = cabbageseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::bluejazzseed: {
		if (season == "Spring")
			sellmoney = bluejazzseed1;
		else {
			if (season == "Summer")
				sellmoney = bluejazzseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = bluejazzseed1 * 0.65;
				else
					sellmoney = bluejazzseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::garlicseed: {
		if (season == "Spring")
			sellmoney = garlicseed1;
		else {
			if (season == "Summer")
				sellmoney = garlicseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = garlicseed1 * 0.65;
				else
					sellmoney = garlicseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::riceseedlingseed: {
		if (season == "Spring")
			sellmoney = riceseedlingseed1;
		else {
			if (season == "Summer")
				sellmoney = riceseedlingseed1 * 0.85;
			else {
				if (season == "Fall")
					sellmoney = riceseedlingseed1 * 0.65;
				else
					sellmoney = riceseedlingseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::melonseed: {
		if (season == "Summer")
			sellmoney = melonseed1;
		else {
			if (season == "Fall")
				sellmoney = melonseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = melonseed1 * 0.65;
				else
					sellmoney = melonseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::tomatoseed: {
		if (season == "Summer")
			sellmoney = tomatoseed1;
		else {
			if (season == "Fall")
				sellmoney = tomatoseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = tomatoseed1 * 0.65;
				else
					sellmoney = tomatoseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::blueburryseed: {
		if (season == "Summer")
			sellmoney = blueburryseed1;
		else {
			if (season == "Fall")
				sellmoney = blueburryseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = blueburryseed1 * 0.65;
				else
					sellmoney = blueburryseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::chilipepperseed: {
		if (season == "Summer")
			sellmoney = chilipepperseed1;
		else {
			if (season == "Fall")
				sellmoney = chilipepperseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = chilipepperseed1 * 0.65;
				else
					sellmoney = chilipepperseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::wheatseed: {
		if (season == "Summer")
			sellmoney = wheatseed1;
		else {
			if (season == "Fall")
				sellmoney = wheatseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = wheatseed1 * 0.65;
				else
					sellmoney = wheatseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::turnipseed: {
		if (season == "Summer")
			sellmoney = turnipseed1;
		else {
			if (season == "Fall")
				sellmoney = turnipseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = turnipseed1 * 0.65;
				else
					sellmoney = turnipseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::poppiesseed: {
		if (season == "Summer")
			sellmoney = poppiesseed1;
		else {
			if (season == "Fall")
				sellmoney = poppiesseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = poppiesseed1 * 0.65;
				else
					sellmoney = poppiesseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::summersequinsseed: {
		if (season == "Summer")
			sellmoney = summersequinsseed1;
		else {
			if (season == "Fall")
				sellmoney = summersequinsseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = summersequinsseed1 * 0.65;
				else
					sellmoney = summersequinsseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::hopseed: {
		if (season == "Summer")
			sellmoney = hopseed1;
		else {
			if (season == "Fall")
				sellmoney = hopseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = hopseed1 * 0.65;
				else
					sellmoney = hopseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::cornseed: {
		if (season == "Summer")
			sellmoney = cornseed1;
		else {
			if (season == "Fall")
				sellmoney = cornseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = cornseed1 * 0.65;
				else
					sellmoney = cornseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::sunflowerseed: {
		if (season == "Summer")
			sellmoney = sunflowerseed1;
		else {
			if (season == "Fall")
				sellmoney = sunflowerseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = sunflowerseed1 * 0.65;
				else
					sellmoney = sunflowerseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::redleafcabbageseed: {
		if (season == "Summer")
			sellmoney = redleafcabbageseed1;
		else {
			if (season == "Fall")
				sellmoney = redleafcabbageseed1 * 0.85;
			else {
				if (season == "Spring")
					sellmoney = redleafcabbageseed1 * 0.65;
				else
					sellmoney = redleafcabbageseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::eggplantseed: {
		if (season == "Fall")
			sellmoney = eggplantseed1;
		else {
			if (season == "Spring")
				sellmoney = eggplantseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = eggplantseed1 * 0.65;
				else
					sellmoney = eggplantseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::pumpkinseed: {
		if (season == "Fall")
			sellmoney = pumpkinseed1;
		else {
			if (season == "Spring")
				sellmoney = pumpkinseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = pumpkinseed1 * 0.65;
				else
					sellmoney = pumpkinseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::chinesecabbageseed: {
		if (season == "Fall")
			sellmoney = chinesecabbageseed1;
		else {
			if (season == "Spring")
				sellmoney = chinesecabbageseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = chinesecabbageseed1 * 0.65;
				else
					sellmoney = chinesecabbageseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::yamseed: {
		if (season == "Fall")
			sellmoney = yamseed1;
		else {
			if (season == "Spring")
				sellmoney = yamseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = yamseed1 * 0.65;
				else
					sellmoney = yamseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::cranberriesseed: {
		if (season == "Fall")
			sellmoney = cranberriesseed1;
		else {
			if (season == "Spring")
				sellmoney = cranberriesseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = cranberriesseed1 * 0.65;
				else
					sellmoney = cranberriesseed1 * 0.45;
			}
		}
		break;
	}
	case SeedKind::rosefairyseed: {
		if (season == "Fall")
			sellmoney = rosefairyseed1;
		else {
			if (season == "Spring")
				sellmoney = rosefairyseed1 * 0.85;
			else {
				if (season == "Summer")
					sellmoney = rosefairyseed1 * 0.65;
				else
					sellmoney = rosefairyseed1 * 0.45;
			}
		}
		break;

	case SeedKind::amaranthseed: {
		return amaranthseed1;
		break;
	}
	case SeedKind::grapeseed: {
		return grapeseed1;
		break;
	}
	case SeedKind::artichokeseed: {
		return artichokeseed1;
		break;
	}
	case SeedKind::cherrysaplings: {
		return cherrysaplings1;
		break;
	}
	case SeedKind::apricotsaplings: {
		return apricotsaplings1;
		break;
	}
	case SeedKind::orangesaplings: {
		return orangesaplings1;
		break;
	}
	case SeedKind::peachsaplings: {
		return peachsaplings1;
		break;
	}
	case SeedKind::pomegranatesaplings: {
		return pomegranatesaplings1;
		break;
	}
	case SeedKind::applesaplings: {
		return applesaplings1;
		break;
	}
	case SeedKind::springseed: {
		return springseed1;
		break;
	}
	case SeedKind::grassseed: {
		return grassseed1;
		break;
	}
	}
				
	}
	return sellmoney;
}
//----子类Tool

 //左键功能
void Tool::leftKeyFunction() {
	;
}

//右键功能
void Tool::rightKeyFunction() {

}

//----子类Fruit

//右键（吃）
void Fruit::rightKeyFunction() {
	;
}

//卖钱
int Fruit::moneyToSell(std::string season) {
	int sellmoney = 0;
	switch (currentSeed) {
	case fruitKind::parsnip:
	{
		switch (quality) {
		case 1:
			sellmoney = parsnip1;
			break;
		case 2:
			sellmoney = parsnip2;
			break;
		case 3:
			sellmoney = parsnip3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *=1;
		else {
			if (season == "Summer")
				sellmoney  *= 0.85;
			else {
				if (season == "Fall")
					sellmoney  *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::greenbean:
	{
		switch (quality) {
		case 1:
			sellmoney = greenbean1;
			break;
		case 2:
			sellmoney = greenbean2;
			break;
		case 3:
			sellmoney = greenbean3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::cauliflower: {
		switch (quality) {
		case 1:
			sellmoney = cauliflower1;
			break;
		case 2:
			sellmoney = cauliflower2;
			break;
		case 3:
			sellmoney = cauliflower3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::potato: {
		switch (quality) {
		case 1:
			sellmoney = potato1;
			break;
		case 2:
			sellmoney = potato2;
			break;
		case 3:
			sellmoney = potato3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::tulipbulbs: {
		switch (quality) {
		case 1:
			sellmoney = tulipbulbs1;
			break;
		case 2:
			sellmoney = tulipbulbs2;
			break;
		case 3:
			sellmoney = tulipbulbs3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::cabbage: {
		switch (quality) {
		case 1:
			sellmoney = cabbage1;
			break;
		case 2:
			sellmoney = cabbage2;
			break;
		case 3:
			sellmoney = cabbage3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::bluejazz: {
		switch (quality) {
		case 1:
			sellmoney = bluejazz1;
			break;
		case 2:
			sellmoney = bluejazz2;
			break;
		case 3:
			sellmoney = bluejazz3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::garlic: {
		switch (quality) {
		case 1:
			sellmoney = garlic1;
			break;
		case 2:
			sellmoney = garlic2;
			break;
		case 3:
			sellmoney = garlic3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::riceseedling: {
		switch (quality) {
		case 1:
			sellmoney = riceseedling1;
			break;
		case 2:
			sellmoney = riceseedling2;
			break;
		case 3:
			sellmoney = riceseedling3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::tomato: {
		switch (quality) {
		case 1:
			sellmoney = riceseedling1;
			break;
		case 2:
			sellmoney = riceseedling2;
			break;
		case 3:
			sellmoney = riceseedling3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Spring")
			sellmoney *= 1;
		else {
			if (season == "Summer")
				sellmoney *= 0.85;
			else {
				if (season == "Fall")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::melon: {
		switch (quality) {
		case 1:
			sellmoney = melon1;
			break;
		case 2:
			sellmoney = melon2;
			break;
		case 3:
			sellmoney = melon3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::blueburry: {
		switch (quality) {
		case 1:
			sellmoney = blueburry1;
			break;
		case 2:
			sellmoney = blueburry2;
			break;
		case 3:
			sellmoney = blueburry3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::chilipepper: {
		switch (quality) {
		case 1:
			sellmoney = chilipepper1;
			break;
		case 2:
			sellmoney = chilipepper2;
			break;
		case 3:
			sellmoney = chilipepper3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::wheat: {
		switch (quality) {
		case 1:
			sellmoney = wheat1;
			break;
		case 2:
			sellmoney = wheat2;
			break;
		case 3:
			sellmoney = wheat3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::turnip: {
		switch (quality) {
		case 1:
			sellmoney = turnip1;
			break;
		case 2:
			sellmoney = turnip2;
			break;
		case 3:
			sellmoney = turnip3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::poppies: {
		switch (quality) {
		case 1:
			sellmoney = poppies1;
			break;
		case 2:
			sellmoney = poppies2;
			break;
		case 3:
			sellmoney = poppies3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::summersequins: {
		switch (quality) {
		case 1:
			sellmoney = summersequins1;
			break;
		case 2:
			sellmoney = summersequins2;
			break;
		case 3:
			sellmoney = summersequins3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::hop: {
		switch (quality) {
		case 1:
			sellmoney = hop1;
			break;
		case 2:
			sellmoney = hop2;
			break;
		case 3:
			sellmoney = hop3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::corn: {
		switch (quality) {
		case 1:
			sellmoney = corn1;
			break;
		case 2:
			sellmoney = corn2;
			break;
		case 3:
			sellmoney = corn3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::sunflower: {
		switch (quality) {
		case 1:
			sellmoney = sunflower1;
			break;
		case 2:
			sellmoney = sunflower2;
			break;
		case 3:
			sellmoney = sunflower3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::redleafcabbage: {
		switch (quality) {
		case 1:
			sellmoney = redleafcabbage1;
			break;
		case 2:
			sellmoney = redleafcabbage2;
			break;
		case 3:
			sellmoney = redleafcabbage3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Summer")
			sellmoney *= 1;
		else {
			if (season == "Fall")
				sellmoney *= 0.85;
			else {
				if (season == "Spring")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::eggplant: {
		switch (quality) {
		case 1:
			sellmoney = eggplant1;
			break;
		case 2:
			sellmoney = eggplant2;
			break;
		case 3:
			sellmoney = eggplant3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::pumpkin: {
		switch (quality) {
		case 1:
			sellmoney = pumpkin1;
			break;
		case 2:
			sellmoney = pumpkin2;
			break;
		case 3:
			sellmoney = pumpkin3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::chinesecabbage: {
		switch (quality) {
		case 1:
			sellmoney = chinesecabbage1;
			break;
		case 2:
			sellmoney = chinesecabbage2;
			break;
		case 3:
			sellmoney = chinesecabbage3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::yam: {
		switch (quality) {
		case 1:
			sellmoney = yam1;
			break;
		case 2:
			sellmoney = yam2;
			break;
		case 3:
			sellmoney = yam3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::cranberries: {
		switch (quality) {
		case 1:
			sellmoney = cranberries1;
			break;
		case 2:
			sellmoney = cranberries2;
			break;
		case 3:
			sellmoney = cranberries3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::rosefairy: {
		switch (quality) {
		case 1:
			sellmoney = rosefairy1;
			break;
		case 2:
			sellmoney = rosefairy2;
			break;
		case 3:
			sellmoney = rosefairy3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::amaranth: {
		switch (quality) {
		case 1:
			sellmoney = amaranth1;
			break;
		case 2:
			sellmoney = amaranth2;
			break;
		case 3:
			sellmoney = amaranth3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::grape: {
		switch (quality) {
		case 1:
			sellmoney = grape1;
			break;
		case 2:
			sellmoney = grape2;
			break;
		case 3:
			sellmoney = grape3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::artichoke: {
		switch (quality) {
		case 1:
			sellmoney = artichoke1;
			break;
		case 2:
			sellmoney = artichoke2;
			break;
		case 3:
			sellmoney = artichoke3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::rice: {
		switch (quality) {
		case 1:
			sellmoney = rice1;
			break;
		case 2:
			sellmoney = rice2;
			break;
		case 3:
			sellmoney = rice3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::cherry: {
		switch (quality) {
		case 1:
			sellmoney = cherry1;
			break;
		case 2:
			sellmoney = cherry2;
			break;
		case 3:
			sellmoney = cherry3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::apricot: {
		switch (quality) {
		case 1:
			sellmoney = apricot1;
			break;
		case 2:
			sellmoney = apricot2;
			break;
		case 3:
			sellmoney = apricot3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;

	}
	case fruitKind::orange: {
		switch (quality) {
		case 1:
			sellmoney = orange1;
			break;
		case 2:
			sellmoney = orange2;
			break;
		case 3:
			sellmoney = orange3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;

	}
	case fruitKind::peach: {
		switch (quality) {
		case 1:
			sellmoney = peach1;
			break;
		case 2:
			sellmoney = peach2;
			break;
		case 3:
			sellmoney = peach3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::pomegranate: {
		switch (quality) {
		case 1:
			sellmoney = pomegranate1;
			break;
		case 2:
			sellmoney = pomegranate2;
			break;
		case 3:
			sellmoney = pomegranate3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::apple: {
		switch (quality) {
		case 1:
			sellmoney = apple1;
			break;
		case 2:
			sellmoney = apple2;
			break;
		case 3:
			sellmoney = apple3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::wildhorseradish: {
		switch (quality) {
		case 1:
			sellmoney = wildhorseradish1;
			break;
		case 2:
			sellmoney = wildhorseradish2;
			break;
		case 3:
			sellmoney = wildhorseradish3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::daffodil: {
		switch (quality) {
		case 1:
			sellmoney = daffodil1;
			break;
		case 2:
			sellmoney = daffodil2;
			break;
		case 3:
			sellmoney = daffodil3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::leek: {
		switch (quality) {
		case 1:
			sellmoney = leek1;
			break;
		case 2:
			sellmoney = leek2;
			break;
		case 3:
			sellmoney = leek3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	case fruitKind::Dandelion: {
		switch (quality) {
		case 1:
			sellmoney = Dandelion1;
			break;
		case 2:
			sellmoney = Dandelion2;
			break;
		case 3:
			sellmoney = Dandelion3;
			break;
		default:
			sellmoney = 0;
			break;
		}
		if (season == "Fall")
			sellmoney *= 1;
		else {
			if (season == "Spring")
				sellmoney *= 0.85;
			else {
				if (season == "Summer")
					sellmoney *= 0.65;
				else
					sellmoney *= 0.45;
			}
		}
		break;
	}
	}
	return sellmoney;
}

//----子类AnimalProduct

//右键 （吃）
void AnimalProduct::rightKeyFunction() {
	;
}

//卖钱
int AnimalProduct::moneyToSell() {
	switch (currentProduct) {
	case AnimalProductKind::egg:
		return egg1;
	case AnimalProductKind::bigegg:
		return bigegg1;
	case AnimalProductKind::brownegg:
		return brownegg1;
	case AnimalProductKind::brownbigegg:
		return brownbigegg1;
	case AnimalProductKind::goldegg:
		return goldegg1;
	case AnimalProductKind::duckegg:
		return duckegg1;
	case  AnimalProductKind::duckfeather:
		return duckfeather1;
	case AnimalProductKind::animalfeather:
		return animalfeather1;
	case AnimalProductKind::rabbitleg:
		return rabbitleg1;
	default:
		return 0;
	}
	return 0;
}

//----子类terial

//卖钱
int terial::moneyToSell() {
	switch (currentProduct) {
	case terialKind::wood:
		return wood1;
		break;
	case terialKind::stone:
		return stone1;
		break;
	case terialKind::sap:
		return sap1;
		break;
	case terialKind::coal:
		return coal1;
		break;
	case terialKind::fibre:
		return fibre1;
		break;
	case terialKind::copperore:
		return copperore1;
		break;
	case terialKind::goldore:
		return goldore1;
		break;
	case terialKind::copperbar:
		return copperbar1;
		break;
	case terialKind::ironbar:
		return ironbar1;
		break;
	case terialKind::goldbar:
		return goldbar1;
		break;
	case terialKind::ironore:
		return ironore1;
		break;
	}
	return 0;
}
