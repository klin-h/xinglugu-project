/****************************************************************
 * Project Name: xinglugu-project
 * File Name:constants.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.5
 * License:
 ****************************************************************/
#ifndef __USABLE_H_
#define __USABLE_H_
#include<cstring>
#include<ctime>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;
typedef std::uint64_t hash_t;

constexpr hash_t prime = primeZ;
constexpr hash_t basis = basisZ;

//这里是为了实现switch判断字符串加入的功能


constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

enum class ItemType {
	null,
	fish,
	fruit,
	tool,
	terial,
	seed,
	animalproduct
};

//基类----物品总类Item
class Item {
public:

	static hash_t hash_1(char const* str)
	{
		hash_t ret{ basis };

		while (*str) {
			ret ^= *str;
			ret *= prime;
			str++;
		}

		return ret;
	}

	char* name;

	int quantity;

	char* pictureName;



	ItemType itemtype = ItemType::null;
	Item() {
		quantity = 0;
		name = "null";
		pictureName = "null.png";
	}

	char const* filenameReturn();

	void quantityChange(bool way, int amount);

	virtual Item* create() {
		Item* null = new Item();
		return null;
	}

	virtual int moneyToSell();

	virtual void leftKeyFunction();

	virtual void rightKeyFunction();
};

//子类----鱼类Fish
class Fish : public Item {
public:
	int quality;
	enum class SeedKind {
		null,
		blowfish,//河豚
		tuna,//金枪鱼
		sardine,//沙丁鱼
		largemouthbass,//大口鲈鱼
		smallmouthbass,//小口鲈鱼
		salmon,//鲑鱼
		sunfish,//翻车鱼
		carp,//鲤鱼
		catfish//鲶鱼
	};

	SeedKind currentSeed = SeedKind::null;

	void rightKeyFunction();

	int moneyToSell();

	Fish(char const* fishName)
	{
		itemtype = ItemType::fish;
		name = (char*)fishName;
		quantity = 1;
		const int qual = rand() % (100 - 1 + 1) + 1;
		if (qual <= 70)
			quality = 1;
		else {
			if (quality <= 90)
				quality = 2;
			else
				quality = 3;
		}

		switch (hash_1(fishName)) {
			case hash_compile_time("blowfish"):
				currentSeed = SeedKind::blowfish;//确定具体物品
				pictureName = "blowfish.png";//传入文件名
				break;
			case hash_compile_time("tuna"):
				currentSeed = SeedKind::tuna;
				pictureName = "tuna.png";
				break;
			case hash_compile_time("sardine"):
				currentSeed = SeedKind::sardine;
				pictureName = "sardine.png";
				break;
			case hash_compile_time("largemouthbass"):
				currentSeed = SeedKind::largemouthbass;
				pictureName = "largemouthbass.png";
				break;
			case hash_compile_time("smallmouthbass"):
				currentSeed = SeedKind::smallmouthbass;
				pictureName = "smallmouthbass.png";
				break;
			case hash_compile_time("salmon"):
				currentSeed = SeedKind::salmon;
				pictureName = "hoe.png";
				break;
			case hash_compile_time("sunfish"):
				currentSeed = SeedKind::sunfish;
				pictureName = "sunfish.png";
				break;
			case hash_compile_time("carp"):
				currentSeed = SeedKind::carp;
				pictureName = "carp.png";
				break;
			case hash_compile_time("catfish"):
				currentSeed = SeedKind::catfish;
				pictureName = "catfish.png";
				break;
			default:
				break;
		}
	}

	static Fish* create(char const* fishName) {
		Fish* newFish = new Fish(fishName);
		return newFish;
	}
};

//子类----种子类Seed
class Seed : public Item {
public:
	enum class SeedKind {
		null,
		parsnipseed,//防风草种子
		greenbeanseed,//青豆种子
		cauliflowerseed,//花椰菜种子
		potatoseed,//土豆种子
		tulipbulbsseed,//鹅掌楸种子
		cabbageseed,//卷心菜籽
		bluejazzseed,//蓝爵士种子
		garlicseed,//大蒜种子
		riceseedlingseed,//稻苗种子
		melonseed,//甜瓜种子
		tomatoseed,//番茄种子
		blueburryseed,//蓝莓种子
		chilipepperseed,//辣椒种子
		wheatseed,//小麦种子
		turnipseed,//萝卜种子
		poppiesseed,//罂粟种子
		summersequinsseed,//夏季亮片种子
		hopseed,//啤酒花种子
		cornseed,//玉米种子
		sunflowerseed,//向日葵种子
		redleafcabbageseed,//红叶卷心菜种子
		eggplantseed,//茄子种子
		pumpkinseed,//南瓜种子
		chinesecabbageseed,//小白菜种子
		yamseed,//山药种子
		cranberriesseed,//蔓越莓种子
		rosefairyseed,//玫瑰仙子种子
		amaranthseed,//苋菜种子
		grapeseed,//葡萄种子
		artichokeseed, //朝鲜蓟种子
		cherrysaplings,//樱桃树种子
		apricotsaplings,//杏树种子
		orangesaplings,//橙子树种子
		peachsaplings,//桃树种子
		pomegranatesaplings,//石榴树种子
		applesaplings,//苹果树种子
		springseed,//春天杂种
		grassseed,//草籽
	};

	SeedKind currentSeed = SeedKind::null;

	int moneyToSell();

	Seed(char const* fishName)
	{
		itemtype = ItemType::seed;
		name = (char*)fishName;
		quantity = 1;
		switch (hash_1(fishName)) {
			case hash_compile_time("parsnipseed"):
				currentSeed = SeedKind::parsnipseed;//确定具体物品
				pictureName = "parsnipseed.png";//传入文件名
				break;
			case hash_compile_time("greenbeanseed"):
				currentSeed = SeedKind::greenbeanseed;
				pictureName = "greenbeanseed.png";
				break;
			case hash_compile_time("cauliflowerseed"):
				currentSeed = SeedKind::cauliflowerseed;
				pictureName = "cauliflowerseed.png";
				break;
			case hash_compile_time("potatoseed"):
				currentSeed = SeedKind::potatoseed;
				pictureName = "potatoseed.png";
				break;
			case hash_compile_time("tulipbulbsseed"):
				currentSeed = SeedKind::tulipbulbsseed;
				pictureName = "tulipbulbsseed.png";
				break;
			case hash_compile_time("cabbageseed"):
				currentSeed = SeedKind::cabbageseed;
				pictureName = "cabbageseed.png";
				break;
			case hash_compile_time("bluejazzseed"):
				currentSeed = SeedKind::bluejazzseed;
				pictureName = "bluejazzseed.png";
				break;
			case hash_compile_time("garlicseed"):
				currentSeed = SeedKind::garlicseed;
				pictureName = "garlicseed.png";
				break;
			case hash_compile_time("riceseedlingseed"):
				currentSeed = SeedKind::riceseedlingseed;
				pictureName = "riceseedlingseed.png";
				break;
			case hash_compile_time("melonseed"):
				currentSeed = SeedKind::melonseed;
				pictureName = "melonseed.png";
				break;
			case hash_compile_time("tomatoseed"):
				currentSeed = SeedKind::tomatoseed;
				pictureName = "tomatoseed.png";
				break;
			case hash_compile_time("blueburryseed"):
				currentSeed = SeedKind::blueburryseed;
				pictureName = "blueburryseed.png";
				break;
			case hash_compile_time("chilipepperseed"):
				currentSeed = SeedKind::chilipepperseed;
				pictureName = "chilipepperseed.png";
				break;
			case hash_compile_time("wheatseed"):
				currentSeed = SeedKind::wheatseed;
				pictureName = "wheatseed.png";
				break;
			case hash_compile_time("turnipseed"):
				currentSeed = SeedKind::turnipseed;
				pictureName = "turnipseed.png";
				break;
			case hash_compile_time("poppiesseed"):
				currentSeed = SeedKind::poppiesseed;
				pictureName = "poppiesseed.png";
				break;
			case hash_compile_time("summersequinsseed"):
				currentSeed = SeedKind::summersequinsseed;
				pictureName = "summersequinsseed.png";
				break;
			case hash_compile_time("hopseed"):
				currentSeed = SeedKind::hopseed;
				pictureName = "hopseed.png";
				break;
			case hash_compile_time("cornseed"):
				currentSeed = SeedKind::cornseed;
				pictureName = "cornseed.png";
				break;
			case hash_compile_time("sunflowerseed"):
				currentSeed = SeedKind::sunflowerseed;
				pictureName = "sunflowerseed.png";
				break;
			case hash_compile_time("redleafcabbageseed"):
				currentSeed = SeedKind::redleafcabbageseed;
				pictureName = "redleafcabbageseed.png";
				break;
			case hash_compile_time("eggplantseed"):
				currentSeed = SeedKind::eggplantseed;
				pictureName = "eggplantseed.png";
				break;
			case hash_compile_time("pumpkinseed"):
				currentSeed = SeedKind::pumpkinseed;
				pictureName = "pumpkinseed.png";
				break;
			case hash_compile_time("chinesecabbageseed"):
				currentSeed = SeedKind::chinesecabbageseed;
				pictureName = "chinesecabbageseed.png";
				break;
			case hash_compile_time("yamseed"):
				currentSeed = SeedKind::yamseed;
				pictureName = "yamseed.png";
				break;
			case hash_compile_time("cranberriesseed"):
				currentSeed = SeedKind::cranberriesseed;
				pictureName = "cranberriesseed.png";
				break;
			case hash_compile_time("rosefairyseed"):
				currentSeed = SeedKind::rosefairyseed;
				pictureName = "rosefairyseed.png";
				break;
			case hash_compile_time("amaranthseed"):
				currentSeed = SeedKind::amaranthseed;
				pictureName = "amaranthseed.png";
				break;
			case hash_compile_time("grapeseed"):
				currentSeed = SeedKind::grapeseed;
				pictureName = "grapeseed.png";
				break;
			case hash_compile_time("artichokeseed"):
				currentSeed = SeedKind::artichokeseed;
				pictureName = "artichokeseed.png";
				break;
			default:
				break;
		}
	}

	static Seed* create(char const* fishName) {
		Seed* newSeed = new Seed(fishName);
		return newSeed;
	}
};

//子类----工具类Tool
class Tool : public Item {
public:
	enum class ToolKind {
		null,
		axe,//斧
		wateringcan,//浇水壶
		sickle,//镰刀
		pickaxe,//镐
		hoe,//锄
		copperaxe,//铜斧
		copperwateringcan,//铜浇水壶
		copperpickaxe,//铜镐
		copperhoe,//铜锄
		ironaxe,//铁斧
		ironwateringcan,//铁浇水壶
		ironpickaxe,//铁镐
		ironhoe,//铁锄
		goldaxe,//金斧
		goldwateringcan,//金浇水壶
		goldpickaxe,//金镐
		goldhoe,//金锄
		iridiumaxe,//铱斧
		iridiumwateringcan,//铱浇水壶
		iridiumpickaxe,//铱镐
		iridiumhoe,//铱锄
		rustysword,//生锈的剑
		woodsword,//木剑
		machete,//弯刀
		holysword,//圣剑
		bonesword,//骨剑
		infinitesword,//无尽之剑
		woodensign,//木牌
		woodfence,//木栅栏
		gate,//大门
		grassstarter,//草籽
		woodpath,//木径
		cobblestonepath,//石径
		torch,//火把
		chest,//宝箱
		furnace,//熔炉
		stonesign,//石牌
		sprinkle,//水龙头
		scarecrow,//稻草人
		bait,//鱼饵
		cherrybomb,//樱桃炸弹
		staircase,//楼梯
		campfire,//篝火
		sugar,//糖
		barleyflour,//大麦粉
		oil,//油
		vinegar,//醋
		flowers,//花
		basicfertilizer,//基础肥料
		seniorfertilizer,//进阶肥料
		basicremainingsoil,//基础湿土
		seniorremainingsoil,//进阶湿土
	};

	ToolKind currentSeed = ToolKind::null;

	void leftKeyFunction();

	void rightKeyFunction();

	Tool(char const* toolName)
	{
		itemtype = ItemType::tool;
		name = "null";
		pictureName = "null.png";
		quantity = 1;
		switch (hash_1(toolName)) {
			case hash_compile_time("axe"):
				currentSeed = ToolKind::axe;//确定具体物品
				pictureName = "axe.png";//传入文件名
				break;
			case hash_compile_time("wateringcan"):
				currentSeed = ToolKind::wateringcan;
				pictureName = "wateringcan.png";
				break;
			case hash_compile_time("pickaxe"):
				currentSeed = ToolKind::pickaxe;
				pictureName = "pickaxe.png";
				break;
			case hash_compile_time("sickle"):
				currentSeed = ToolKind::sickle;
				pictureName = "sickle.png";
				break;
			case hash_compile_time("hoe"):
				currentSeed = ToolKind::hoe;
				pictureName = "hoe.png";
				break;
			default:
				break;
		}
	}
	static Tool* create(char const* toolName) {
		Tool* newTool = new Tool(toolName);
		return newTool;
	}
};

//子类----果实类Fruit
class Fruit : public Item {
public:
	int quality;
	enum class fruitKind {
		null,
		parsnip,//防风草
		greenbean,//青豆
		cauliflower,//花椰菜
		potato,//土豆
		tulipbulbs,//鹅掌楸
		cabbage,//卷心菜
		bluejazz,//蓝爵士
		garlic,//大蒜
		riceseedling,//水稻
		melon,//甜瓜
		tomato,//番茄
		blueburry,//蓝莓
		chilipepper,//辣椒
		wheat,//小麦
		turnip,//萝卜
		poppies,//罂粟
		summersequins,//夏季亮片
		hop,//啤酒花
		corn,//玉米
		sunflower,//向日葵
		redleafcabbage,//红叶卷心菜
		eggplant,//茄子
		pumpkin,//南瓜
		chinesecabbage,//小白菜
		yam,//山药
		cranberries,//蔓越莓
		rosefairy,//玫瑰仙子
		amaranth,//
		grape,//葡萄
		artichoke,//
		rice,//米饭
		cherry,//樱桃
		apricot,//杏
		orange,//橙子
		peach,//桃子
		pomegranate,//石榴
		apple,//苹果
		wildhorseradish,//野辣根
		daffodil,//水仙花
		leek,//韭菜
		Dandelion//蒲公英
	};

	fruitKind currentSeed = fruitKind::null;

	void rightKeyFunction();

	int moneyToSell();

	Fruit(char const* fishName)
	{
		itemtype = ItemType::fruit;
		name = (char*)fishName;
		quantity = 1;
		int qual = rand() % (100 - 1 + 1) + 1;
		if (qual <= 70)
			quality = 1;
		else {
			if (quality <= 90)
				quality = 2;
			else
				quality = 3;
		}
	}

	static Fruit* create(char const* fishName) {
		Fruit* newFruit = new Fruit(fishName);
		return newFruit;
	}
};

//子类----动物产品类AnimalProduct
class AnimalProduct : public Item {
public:
	enum class AnimalProductKind {
		null,
		egg,//蛋
		bigegg,//大蛋
		brownegg,//棕蛋
		brownbigegg,//大棕蛋
		goldegg,//金蛋
		duckegg,//鸭蛋
		duckfeather,//鸭毛
		animalfeather,//动物毛
		rabbitleg,//兔腿
		milk,//牛奶
		largemilk,//大瓶牛奶
		goatmilk,//羊奶
		largegoatmilk,//大瓶羊奶
		Truffles,//松露
		honey,//蜂蜜
		bugmeat//虫肉
	};

	AnimalProductKind currentProduct = AnimalProductKind::null;

	void rightKeyFunction();

	int moneyToSell();

	AnimalProduct(char const* fishName)
	{
		itemtype = ItemType::animalproduct;
		name = (char*)fishName;
		quantity = 1;
	}

	static AnimalProduct* create(char const* fishName) {
		AnimalProduct* newFruit = new AnimalProduct(fishName);
		return newFruit;
	}
};

//子类----材料类terial
class terial : public Item {
public:
	enum class terialKind {
		null,
		wood,//木头
		stone,//石头
		sap,//树液
		copperore,//铜粒
		ironore,//铁粒
		goldore,//金粒
		copperbar,//铜锭
		ironbar,//铁锭
		goldbar,//金锭
		coal,//煤炭
		fibre,//纤维
	};

	terialKind currentProduct = terialKind::null;

	int moneyToSell();

	terial(char const* fishName)
	{
		itemtype = ItemType::terial;
		name = (char*)fishName;
		quantity = 1;
	}

	static terial* create(char const* fishName) {
		terial* newFruit = new terial(fishName);
		return newFruit;
	}
};

#endif
