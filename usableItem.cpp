/****************************************************************
 * Project Name: xinglugu-project
 * File Name:constants.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.8
 * License:
 ****************************************************************/
#include"usableItem.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;
//----基类Item

//数量更改函数
void Item::quantityChange(bool way,int amount) {
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
	 case SeedKind::carp:{
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
		 return 10;
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
			 return parsnip1;
			 break;
		 case 2:
			 return parsnip2;
			 break;
		 case 3:
			 return parsnip3;
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
			 return greenbean1;
			 break;
		 case 2:
			 return greenbean2;
			 break;
		 case 3:
			 return greenbean3;
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
			 return cauliflower1;
			 break;
		 case 2:
			 return cauliflower2;
			 break;
		 case 3:
			 return cauliflower3;
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
			 return potato1;
			 break;
		 case 2:
			 return potato2;
			 break;
		 case 3:
			 return potato3;
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
			 return tulipbulbs1;
			 break;
		 case 2:
			 return tulipbulbs2;
			 break;
		 case 3:
			 return tulipbulbs3;
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
			 return cabbage1;
			 break;
		 case 2:
			 return cabbage2;
			 break;
		 case 3:
			 return cabbage3;
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
			 return bluejazz1;
			 break;
		 case 2:
			 return bluejazz2;
			 break;
		 case 3:
			 return bluejazz3;
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
			 return garlic1;
			 break;
		 case 2:
			 return garlic2;
			 break;
		 case 3:
			 return garlic3;
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
			 return riceseedling1;
			 break;
		 case 2:
			 return riceseedling2;
			 break;
		 case 3:
			 return riceseedling3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::tomato: {
		 switch (quality) {
		 case 1:
			 return tomato1;
			 break;
		 case 2:
			 return tomato2;
			 break;
		 case 3:
			 return tomato3;
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
			 return blueburry1;
			 break;
		 case 2:
			 return blueburry2;
			 break;
		 case 3:
			 return blueburry3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::chilipepper: {
		 switch (quality) {
		 case 1:
			 return chilipepper1;
			 break;
		 case 2:
			 return chilipepper2;
			 break;
		 case 3:
			 return chilipepper3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::wheat: {
		 switch (quality) {
		 case 1:
			 return wheat1;
			 break;
		 case 2:
			 return wheat2;
			 break;
		 case 3:
			 return wheat3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::turnip: {
		 switch (quality) {
		 case 1:
			 return turnip1;
			 break;
		 case 2:
			 return turnip2;
			 break;
		 case 3:
			 return turnip3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::poppies: {
		 switch (quality) {
		 case 1:
			 return poppies1;
			 break;
		 case 2:
			 return poppies2;
			 break;
		 case 3:
			 return poppies3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::summersequins: {
		 switch (quality) {
		 case 1:
			 return summersequins1;
			 break;
		 case 2:
			 return summersequins2;
			 break;
		 case 3:
			 return summersequins3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::hop: {
		 switch (quality) {
		 case 1:
			 return hop1;
			 break;
		 case 2:
			 return hop2;
			 break;
		 case 3:
			 return hop3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::corn: {
		 switch (quality) {
		 case 1:
			 return corn1;
			 break;
		 case 2:
			 return corn2;
			 break;
		 case 3:
			 return corn3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::sunflower: {
		 switch (quality) {
		 case 1:
			 return sunflower1;
			 break;
		 case 2:
			 return sunflower2;
			 break;
		 case 3:
			 return sunflower3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::redleafcabbage: {
		 switch (quality) {
		 case 1:
			 return redleafcabbage1;
			 break;
		 case 2:
			 return redleafcabbage2;
			 break;
		 case 3:
			 return redleafcabbage3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::eggplant: {
		 switch (quality) {
		 case 1:
			 return eggplant1;
			 break;
		 case 2:
			 return eggplant2;
			 break;
		 case 3:
			 return eggplant3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::pumpkin: {
		 switch (quality) {
		 case 1:
			 return pumpkin1;
			 break;
		 case 2:
			 return pumpkin2;
			 break;
		 case 3:
			 return pumpkin3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::chinesecabbage: {
		 switch (quality) {
		 case 1:
			 return chinesecabbage1;
			 break;
		 case 2:
			 return chinesecabbage2;
			 break;
		 case 3:
			 return chinesecabbage3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::yam: {
		 switch (quality) {
		 case 1:
			 return yam1;
			 break;
		 case 2:
			 return yam2;
			 break;
		 case 3:
			 return yam3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::cranberries: {

		 switch (quality) {
		 case 1:
			 return cranberries1;
			 break;
		 case 2:
			 return cranberries2;
			 break;
		 case 3:
			 return cranberries3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::rosefairy: {

		 switch (quality) {
		 case 1:
			 return rosefairy1;
			 break;
		 case 2:
			 return rosefairy2;
			 break;
		 case 3:
			 return rosefairy3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::amaranth: {

		 switch (quality) {
		 case 1:
			 return amaranth1;
			 break;
		 case 2:
			 return amaranth2;
			 break;
		 case 3:
			 return amaranth3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::grape: {

		 switch (quality) {
		 case 1:
			 return grape1;
			 break;
		 case 2:
			 return grape2;
			 break;
		 case 3:
			 return grape3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::artichoke: {

		 switch (quality) {
		 case 1:
			 return artichoke1;
			 break;
		 case 2:
			 return artichoke2;
			 break;
		 case 3:
			 return artichoke3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::rice: {

		 switch (quality) {
		 case 1:
			 return rice1;
			 break;
		 case 2:
			 return rice2;
			 break;
		 case 3:
			 return rice3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::cherry: {

		 switch (quality) {
		 case 1:
			 return cherry1;
			 break;
		 case 2:
			 return cherry2;
			 break;
		 case 3:
			 return cherry3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::apricot: {

		 switch (quality) {
		 case 1:
			 return apricot1;
			 break;
		 case 2:
			 return apricot2;
			 break;
		 case 3:
			 return apricot3;
			 break;
		 default:
			 return 0;
			 break;
		 }


	 }
	 case fruitKind::orange: {

		 switch (quality) {
		 case 1:
			 return orange1;
			 break;
		 case 2:
			 return orange2;
			 break;
		 case 3:
			 return orange3;
			 break;
		 default:
			 return 0;
			 break;
		 }

	 }
	 case fruitKind::peach: {

		 switch (quality) {
		 case 1:
			 return peach1;
			 break;
		 case 2:
			 return peach2;
			 break;
		 case 3:
			 return peach3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::pomegranate: {
		 switch (quality) {
		 case 1:
			 return pomegranate1;
			 break;
		 case 2:
			 return pomegranate2;
			 break;
		 case 3:
			 return pomegranate3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::apple: {
		 switch (quality) {
		 case 1:
			 return apple1;
			 break;
		 case 2:
			 return apple2;
			 break;
		 case 3:
			 return apple3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::wildhorseradish: {
		 switch (quality) {
		 case 1:
			 return wildhorseradish1;
			 break;
		 case 2:
			 return wildhorseradish2;
			 break;
		 case 3:
			 return wildhorseradish3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::daffodil: {
		 switch (quality) {
		 case 1:
			 return daffodil1;
			 break;
		 case 2:
			 return daffodil2;
			 break;
		 case 3:
			 return daffodil3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::leek: {
		 switch (quality) {
		 case 1:
			 return leek1;
			 break;
		 case 2:
			 return leek2;
			 break;
		 case 3:
			 return leek3;
			 break;
		 default:
			 return 0;
			 break;
		 }
	 }
	 case fruitKind::Dandelion: {
		 switch (quality) {
		 case 1:
			 return Dandelion1;
			 break;
		 case 2:
			 return Dandelion2;
			 break;
		 case 3:
			 return Dandelion3;
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
