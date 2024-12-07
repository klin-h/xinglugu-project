/****************************************************************
 * Project Name: xinglugu-project
 * File Name:constants.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.4
 * License:
 ****************************************************************/
#include"usableItem.h"
#include"Constants.h"
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

//物品价值
int Item::moneyToSell() {
	return 0;
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
int Fish::moneyToSell() {
	switch (currentSeed) {
		case SeedKind::blowfish:
		{
			switch (quality) {
				case 1:
					return 200;
					break;
				case 2:
					return 250;
					break;
				case 3:
					return 300;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::tuna:
		{
			switch (quality) {
				case 1:
					return 100;
					break;
				case 2:
					return 125;
					break;
				case 3:
					return 150;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::sardine: {
			switch (quality) {
				case 1:
					return 40;
					break;
				case 2:
					return 50;
					break;
				case 3:
					return 60;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::largemouthbass: {
			switch (quality) {
				case 1:
					return 100;
					break;
				case 2:
					return 125;
					break;
				case 3:
					return 150;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::smallmouthbass: {
			switch (quality) {
				case 1:
					return 50;
					break;
				case 2:
					return 62;
					break;
				case 3:
					return 75;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::sunfish: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::salmon: {
			switch (quality) {
				case 1:
					return 75;
					break;
				case 2:
					return 93;
					break;
				case 3:
					return 112;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::catfish: {
			switch (quality) {
				case 1:
					return 200;
					break;
				case 2:
					return 250;
					break;
				case 3:
					return 300;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case SeedKind::carp: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		default:
			return 0;
			break;
	}
	return 0;
}

//----子类Seed

 //卖钱
int Seed::moneyToSell() {
	switch (currentSeed) {
		case SeedKind::parsnipseed:
		{
			return 10;
			break;
		}
		case SeedKind::greenbeanseed:
		{
			return 30;
			break;
		}
		case SeedKind::cauliflowerseed: {
			return 40;
			break;
		}
		case SeedKind::potatoseed: {
			return 20;
			break;
		}
		case SeedKind::tulipbulbsseed: {
			return 10;
			break;
		}
		case SeedKind::cabbageseed: {
			return 50;
			break;
		}
		case SeedKind::bluejazzseed: {
			return 25;
			break;
		}
		case SeedKind::garlicseed: {
			return 30;
			break;
		}
		case SeedKind::riceseedlingseed: {
			return 40;
			break;
		}
		case SeedKind::melonseed: {
			return 15;
			break;
		}
		case SeedKind::tomatoseed: {
			return 25;
			break;
		}
		case SeedKind::blueburryseed: {
			return 10;
			break;
		}
		case SeedKind::chilipepperseed: {
			return 20;
			break;
		}
		case SeedKind::wheatseed: {
			return 30;
			break;
		}
		case SeedKind::turnipseed: {
			return 30;
			break;
		}
		case SeedKind::poppiesseed: {
			return 10;
			break;
		}
		case SeedKind::summersequinsseed: {
			return 10;
			break;
		}
		case SeedKind::hopseed: {
			return 40;
			break;
		}
		case SeedKind::cornseed: {
			return 20;
			break;
		}
		case SeedKind::sunflowerseed: {
			return 30;
			break;
		}
		case SeedKind::redleafcabbageseed: {
			return 15;
			break;
		}
		case SeedKind::eggplantseed: {
			return 25;
			break;
		}
		case SeedKind::pumpkinseed: {
			return 55;
			break;
		}
		case SeedKind::chinesecabbageseed: {
			return 15;
			break;
		}
		case SeedKind::yamseed: {
			return 30;
			break;
		}
		case SeedKind::cranberriesseed: {
			return 15;
			break;
		}
		case SeedKind::rosefairyseed: {
			return 35;
			break;

		case SeedKind::amaranthseed: {
			return 20;
			break;
		}
		default:
			return 0;
			break;
		}
		case SeedKind::grapeseed: {
			return 40;
			break;
		}
		case SeedKind::artichokeseed: {
			return 10;
			break;
		}
		case SeedKind::cherrysaplings: {
			return 10;
			break;
		}
		case SeedKind::apricotsaplings: {
			return 15;
			break;
		}
		case SeedKind::orangesaplings: {
			return 25;
			break;
		}
		case SeedKind::peachsaplings: {
			return 35;
			break;
		}
		case SeedKind::pomegranatesaplings: {
			return 55;
			break;
		}
		case SeedKind::applesaplings: {
			return 55;
			break;
		}
		case SeedKind::springseed: {
			return 65;
			break;
		}
		case SeedKind::grassseed: {
			return 5;
			break;
		}
	}
	return 0;
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
int Fruit::moneyToSell() {
	switch (currentSeed) {
		case fruitKind::parsnip:
		{
			switch (quality) {
				case 1:
					return 200;
					break;
				case 2:
					return 250;
					break;
				case 3:
					return 300;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::greenbean:
		{
			switch (quality) {
				case 1:
					return 200;
					break;
				case 2:
					return 250;
					break;
				case 3:
					return 300;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::cauliflower: {
			switch (quality) {
				case 1:
					return 40;
					break;
				case 2:
					return 50;
					break;
				case 3:
					return 60;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::potato: {
			switch (quality) {
				case 1:
					return 100;
					break;
				case 2:
					return 125;
					break;
				case 3:
					return 150;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::tulipbulbs: {
			switch (quality) {
				case 1:
					return 50;
					break;
				case 2:
					return 62;
					break;
				case 3:
					return 75;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::cabbage: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::bluejazz: {
			switch (quality) {
				case 1:
					return 75;
					break;
				case 2:
					return 93;
					break;
				case 3:
					return 112;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::garlic: {
			switch (quality) {
				case 1:
					return 200;
					break;
				case 2:
					return 250;
					break;
				case 3:
					return 300;
					break;
				default:
					return 0;
					break;
			}
			break;
		}
		case fruitKind::riceseedling: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::tomato: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}

		case fruitKind::melon: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		default:
			return 0;
			break;
		}
		case fruitKind::blueburry: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::chilipepper: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::wheat: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::turnip: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::poppies: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::summersequins: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::hop: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::corn: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::sunflower: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::redleafcabbage: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::eggplant: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::pumpkin: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::chinesecabbage: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::yam: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::cranberries: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::rosefairy: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::amaranth: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::grape: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::artichoke: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::rice: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::cherry: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::apricot: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}


		}
		case fruitKind::orange: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}

		}
		case fruitKind::peach: {

			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::pomegranate: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::apple: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::wildhorseradish: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::daffodil: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::leek: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
		case fruitKind::Dandelion: {
			switch (quality) {
				case 1:
					return 30;
					break;
				case 2:
					return 37;
					break;
				case 3:
					return 45;
					break;
				default:
					return 0;
					break;
			}
		}
	}
	return 0;
}

//----子类AnimalProduct

//右键 （吃）
void AnimalProduct::rightKeyFunction() {
	;
}

//卖钱
int AnimalProduct::moneyToSell() {
	return 0;
}

//----子类terial

//卖钱
int terial::moneyToSell() {
	switch (currentProduct) {
		case terialKind::wood:
			return 5;
			break;
		case terialKind::stone:
			return 5;
			break;
		case terialKind::sap:
			return 10;
			break;
		case terialKind::coal:
			return 20;
			break;
		case terialKind::fibre:
			return 15;
			break;
		case terialKind::copperore:
			return 20;
			break;
		case terialKind::goldore:
			return 50;
			break;
		case terialKind::copperbar:
			return 80;
			break;
		case terialKind::ironbar:
			return 120;
			break;
		case terialKind::goldbar:
			return 140;
			break;
		case terialKind::ironore:
			return 30;
			break;
	}
	return 0;
}