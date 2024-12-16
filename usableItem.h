/****************************************************************
 * Project Name: xinglugu-project
 * File Name:usableItem.h
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
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

//������Ϊ��ʵ��switch�ж��ַ�������Ĺ���


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

//����----��Ʒ����Item
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

	std::string name;

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

	bool isSoldAble();

	virtual Item* create() {
		Item* null = new Item();
		return null;
	}

	virtual int moneyToSell();

	virtual void leftKeyFunction();

	virtual void rightKeyFunction();
};

//����----����Fishpotatoseed
class Fish : public Item {
public:
	int quality;
	enum class SeedKind {
		null,
		blowfish,//����
		tuna,//��ǹ��
		sardine,//ɳ����
		largemouthbass,//�������
		smallmouthbass,//С������
		salmon,//����
		sunfish,//������
		carp,//����
		catfish//����
	};

	SeedKind currentSeed = SeedKind::null;

	void rightKeyFunction();

	int moneyToSell();

	Fish(std::string fishName)
	{
		itemtype = ItemType::fish;
		name = fishName;
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

		switch (hash_1(fishName.c_str())) {
		case hash_compile_time("blowfish"):
			currentSeed = SeedKind::blowfish;//ȷ��������Ʒ
			pictureName = "blowfish.png";//�����ļ���
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

	static Fish* create(std::string fishName) {
		Fish* newFish = new Fish(fishName);
		return newFish;
	}
};

//����----������Seed
class Seed : public Item {
public:
	enum class SeedKind {
		null,
		parsnipseed,//���������
		greenbeanseed,//�ඹ����
		cauliflowerseed,//��Ҭ������
		potatoseed,//��������
		tulipbulbsseed,//���������
		cabbageseed,//���Ĳ���
		bluejazzseed,//����ʿ����
		garlicseed,//��������
		riceseedlingseed,//��������
		melonseed,//�������
		tomatoseed,//��������
		blueburryseed,//��ݮ����
		chilipepperseed,//��������
		wheatseed,//С������
		turnipseed,//�ܲ�����
		poppiesseed,//�������
		summersequinsseed,//�ļ���Ƭ����
		hopseed,//ơ�ƻ�����
		cornseed,//��������
		sunflowerseed,//���տ�����
		redleafcabbageseed,//��Ҷ���Ĳ�����
		eggplantseed,//��������
		pumpkinseed,//�Ϲ�����
		chinesecabbageseed,//С�ײ�����
		yamseed,//ɽҩ����
		cranberriesseed,//��Խݮ����
		rosefairyseed,//õ����������
		amaranthseed,//�Ȳ�����
		grapeseed,//��������
		artichokeseed, //���ʼ�����
		cherrysaplings,//ӣ��������
		apricotsaplings,//��������
		orangesaplings,//����������
		peachsaplings,//��������
		pomegranatesaplings,//ʯ��������
		applesaplings,//ƻ��������
		springseed,//��������
		grassseed,//����
	};

	SeedKind currentSeed = SeedKind::null;

	int moneyToSell();

	Seed(std::string fishName)
	{
		itemtype = ItemType::seed;
		name = fishName;
		quantity = 1;
		switch (hash_1(fishName.c_str())) {
		case hash_compile_time("parsnipseed"):
			currentSeed = SeedKind::parsnipseed;//ȷ��������Ʒ
			pictureName = "parsnipseed.png";//�����ļ���
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
		case hash_compile_time("cherrysaplings"):
			currentSeed = SeedKind::cherrysaplings;
			pictureName = "cherrysaplings.png";
			break;
		case hash_compile_time("apricotsaplings"):
			currentSeed = SeedKind::apricotsaplings;
			pictureName = "apricotsaplings.png";
			break;
		case hash_compile_time("orangesaplings"):
			currentSeed = SeedKind::orangesaplings;
			pictureName = "orangesaplings.png";
			break;
		case hash_compile_time("peachsaplings"):
			currentSeed = SeedKind::peachsaplings;
			pictureName = "peachsaplings.png";
			break;
		case hash_compile_time("pomegranatesaplings"):
			currentSeed = SeedKind::pomegranatesaplings;
			pictureName = "pomegranatesaplings.png";
			break;
		case hash_compile_time("applesaplings"):
			currentSeed = SeedKind::applesaplings;
			pictureName = "applesaplings.png";
			break;
		default:
			break;
		}
	}

	static Seed* create(std::string fishName) {
		Seed* newSeed = new Seed(fishName);
		return newSeed;
	}
};

//����----������Tool
class Tool : public Item {
public:
	enum class ToolKind {
		null,
		axe,//��
		wateringcan,//��ˮ��
		sickle,//����
		pickaxe,//��
		hoe,//��
		copperaxe,//ͭ��
		copperwateringcan,//ͭ��ˮ��
		copperpickaxe,//ͭ��
		copperhoe,//ͭ��
		ironaxe,//����
		ironwateringcan,//����ˮ��
		ironpickaxe,//����
		ironhoe,//����
		goldaxe,//��
		goldwateringcan,//��ˮ��
		goldpickaxe,//���
		goldhoe,//���
		rustysword,//����Ľ�
		bonesword,//�ǽ�
		woodensign,//ľ��
		woodfence,//ľդ��
		gate,//����
		woodpath,//ľ��
		cobblestonepath,//ʯ��
		torch,//���
		chest,//����
		furnace,//��¯
		stonesign,//ʯ��
		sprinkle,//ˮ��ͷ
		scarecrow,//������
		bait,//���
		cherrybomb,//ӣ��ը��
		staircase,//¥��
		campfire,//����
		grassseedformulation,
		rice,
		sugar,//��
		barleyflour,//�����
		oil,//��
		vinegar,//��
		flowers,//��
		basicfertilizer,//��������
		seniorfertilizer,//���׷���
		basicremainingsoil,//����ʪ��
		seniorremainingsoil,//����ʪ��
	};

	ToolKind currentSeed = ToolKind::null;

	void leftKeyFunction();

	void rightKeyFunction();

	Tool(std::string toolName)
	{
		itemtype = ItemType::tool;
		name = toolName;
		pictureName = "null.png";
		quantity = 1;
		switch (hash_1(toolName.c_str())) {
		case hash_compile_time("axe"):
			currentSeed = ToolKind::axe;//ȷ��������Ʒ
			pictureName = "axe.png";//�����ļ���
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
		case hash_compile_time("copperaxe"):
			currentSeed = ToolKind::copperaxe;
			pictureName = "copperaxe.png";
			break;
		case hash_compile_time("copperwateringcan"):
			currentSeed = ToolKind::copperwateringcan;
			pictureName = "copperwateringcan.png";
			break;
		case hash_compile_time("copperpickaxe"):
			currentSeed = ToolKind::copperpickaxe;
			pictureName = "copperpickaxe.png";
			break;
		case hash_compile_time("copperhoe"):
			currentSeed = ToolKind::copperhoe;
			pictureName = "copperhoe.png";
			break;
		case hash_compile_time("ironaxe"):
			currentSeed = ToolKind::ironaxe;
			pictureName = "ironaxe.png";
			break;
		case hash_compile_time("ironwateringcan"):
			currentSeed = ToolKind::ironwateringcan;
			pictureName = "ironwateringcan.png";
			break;
		case hash_compile_time("ironpickaxe"):
			currentSeed = ToolKind::ironpickaxe;
			pictureName = "ironpickaxe.png";
		case hash_compile_time("ironhoe"):
			currentSeed = ToolKind::ironhoe;
			pictureName = "ironhoe.png";
			break;
		case hash_compile_time("goldaxe"):
			currentSeed = ToolKind::goldaxe;
			pictureName = "goldaxe.png";
			break;
		case hash_compile_time("goldwateringcan"):
			currentSeed = ToolKind::goldwateringcan;
			pictureName = "goldwateringcan.png";
			break;
		case hash_compile_time("goldhoe"):
			currentSeed = ToolKind::goldhoe;
			pictureName = "goldhoe.png";
			break;
		case hash_compile_time("goldpickaxe"):
			currentSeed = ToolKind::goldpickaxe;
			pictureName = "goldpickaxe.png";
			break;
		case hash_compile_time("rustysword"):
			currentSeed = ToolKind::rustysword;
			pictureName = "rustysword.png";
			break;
		case hash_compile_time("bonesword"):
			currentSeed = ToolKind::bonesword;
			pictureName = "bonesword.png";
			break;
		case hash_compile_time("woodensign"):
			currentSeed = ToolKind::woodensign;
			pictureName = "woodensign.png";
			break;
		case hash_compile_time("woodfence"):
			currentSeed = ToolKind::woodfence;
			pictureName = "woodfence.png";
		break;
		case hash_compile_time("gate"):
				currentSeed = ToolKind::gate;
			pictureName = "gate.png";
			break;
		case hash_compile_time("woodpath"):
			currentSeed = ToolKind::woodpath;
			pictureName = "woodpath.png";
			break;
		case hash_compile_time("grassseedformulation"):
			currentSeed = ToolKind::grassseedformulation;
			pictureName = "grassseedformulation.png";
			break;
		case hash_compile_time("rice"):
			currentSeed = ToolKind::rice;
			pictureName = "rice.png";
			break;
		case hash_compile_time("sugar"):
			currentSeed = ToolKind::sugar;
			pictureName = "sugar.png";
			break;
		case hash_compile_time("barleyflour"):
			currentSeed = ToolKind::barleyflour;
			pictureName = "barleyflour.png";
			break;
		case hash_compile_time("oil"):
			currentSeed = ToolKind::oil;
			pictureName = "oil.png";
			break;
		case hash_compile_time("vinegar"):
			currentSeed = ToolKind::vinegar;
			pictureName = "vinegar.png";
			break;
		case hash_compile_time("flowers"):
			currentSeed = ToolKind::flowers;
			pictureName = "flowers.png";
			break;
		case hash_compile_time("basicfertilizer"):
			currentSeed = ToolKind::basicfertilizer;
			pictureName = "basicfertilizer.png";
			break;
		case hash_compile_time("seniorfertilizer"):
			currentSeed = ToolKind::seniorfertilizer;
			pictureName = "seniorfertilizer.png";
			break;
		case hash_compile_time("basicremainingsoil"):
			currentSeed = ToolKind::basicremainingsoil;
			pictureName = "basicremainingsoil.png";
			break;
		case hash_compile_time("seniorremainingsoil"):
			currentSeed = ToolKind::seniorremainingsoil;
			pictureName = "seniorremainingsoil.png";
			break;
		default:
			break;
		}
	}
	static Tool* create(std::string toolName) {
		Tool* newTool = new Tool(toolName);
		return newTool;
	}
};

//����----��ʵ��Fruit
class Fruit : public Item {
public:
	int quality;
	enum class fruitKind {
		null,
		parsnip,//�����
		greenbean,//�ඹ
		cauliflower,//��Ҭ��
		potato,//����
		tulipbulbs,//�����
		cabbage,//���Ĳ�
		bluejazz,//����ʿ
		garlic,//����
		riceseedling,//ˮ��
		melon,//���
		tomato,//����
		blueburry,//��ݮ
		chilipepper,//����
		wheat,//С��
		turnip,//�ܲ�
		poppies,//���
		summersequins,//�ļ���Ƭ
		hop,//ơ�ƻ�
		corn,//����
		sunflower,//���տ�
		redleafcabbage,//��Ҷ���Ĳ�
		eggplant,//����
		pumpkin,//�Ϲ�
		chinesecabbage,//С�ײ�
		yam,//ɽҩ
		cranberries,//��Խݮ
		rosefairy,//õ������
		amaranth,//
		grape,//����
		artichoke,//
		rice,//�׷�
		cherry,//ӣ��
		apricot,//��
		orange,//����
		peach,//����
		pomegranate,//ʯ��
		apple,//ƻ��
		wildhorseradish,//Ұ����
		daffodil,//ˮ�ɻ�
		leek,//�²�
		Dandelion//�ѹ�Ӣ
	};

	fruitKind currentSeed = fruitKind::null;

	void rightKeyFunction();

	int moneyToSell();

	Fruit(std::string fishName)
	{
		itemtype = ItemType::fruit;
		name = fishName;
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

		switch (hash_1(fishName.c_str())) {
		case hash_compile_time("parsnip"):
			currentSeed = fruitKind::parsnip;//ȷ��������Ʒ
			pictureName = "parsnip.png";//�����ļ���
			break;
		case hash_compile_time("greenbean"):
			currentSeed = fruitKind::greenbean;
			pictureName = "greenbean.png";
			break;
		case hash_compile_time("cauliflower"):
			currentSeed = fruitKind::cauliflower;
			pictureName = "cauliflower.png";
			break;
		case hash_compile_time("potato"):
			currentSeed = fruitKind::potato;
			pictureName = "potato.png";
			break;
		case hash_compile_time("tulipbulbs"):
			currentSeed = fruitKind::tulipbulbs;
			pictureName = "tulipbulbs.png";
			break;
		case hash_compile_time("cabbage"):
			currentSeed = fruitKind::cabbage;
			pictureName = "cabbage.png";
			break;
		case hash_compile_time("bluejazz"):
			currentSeed = fruitKind::bluejazz;
			pictureName = "bluejazz.png";
			break;
		case hash_compile_time("garlic"):
			currentSeed = fruitKind::garlic;
			pictureName = "garlic.png";
			break;
		case hash_compile_time("riceseedling"):
			currentSeed = fruitKind::riceseedling;
			pictureName = "riceseedling.png";
			break;
		case hash_compile_time("melon"):
			currentSeed = fruitKind::melon;
			pictureName = "melon.png";
			break;
		case hash_compile_time("tomato"):
			currentSeed = fruitKind::tomato;
			pictureName = "tomato.png";
			break;
		case hash_compile_time("blueburry"):
			currentSeed = fruitKind::blueburry;
			pictureName = "blueburry.png";
			break;
		case hash_compile_time("chilipepper"):
			currentSeed = fruitKind::chilipepper;
			pictureName = "chilipepper.png";
			break;
		case hash_compile_time("wheat"):
			currentSeed = fruitKind::wheat;
			pictureName = "wheat.png";
			break;
		case hash_compile_time("turnip"):
			currentSeed = fruitKind::turnip;
			pictureName = "turnip.png";
			break;
		case hash_compile_time("poppies"):
			currentSeed = fruitKind::poppies;
			pictureName = "poppies.png";
			break;
		case hash_compile_time("summersequins"):
			currentSeed = fruitKind::summersequins;
			pictureName = "summersequins.png";
			break;
		case hash_compile_time("hop"):
			currentSeed = fruitKind::hop;
			pictureName = "hop.png";
			break;
		case hash_compile_time("corn"):
			currentSeed = fruitKind::corn;
			pictureName = "corn.png";
			break;
		case hash_compile_time("sunflower"):
			currentSeed = fruitKind::sunflower;
			pictureName = "sunflower.png";
			break;
		case hash_compile_time("redleafcabbage"):
			currentSeed = fruitKind::redleafcabbage;
			pictureName = "redleafcabbage.png";
			break;
		case hash_compile_time("eggplant"):
			currentSeed = fruitKind::eggplant;
			pictureName = "eggplant.png";
			break;
		case hash_compile_time("pumpkin"):
			currentSeed = fruitKind::pumpkin;
			pictureName = "pumpkin.png";
			break;
		case hash_compile_time("chinesecabbage"):
			currentSeed = fruitKind::chinesecabbage;
			pictureName = "chinesecabbage.png";
			break;
		case hash_compile_time("yam"):
			currentSeed = fruitKind::yam;
			pictureName = "yam.png";
			break;
		case hash_compile_time("cranberries"):
			currentSeed = fruitKind::cranberries;
			pictureName = "cranberries.png";
			break;
		case hash_compile_time("rosefairy"):
			currentSeed = fruitKind::rosefairy;
			pictureName = "rosefairy.png";
			break;
		case hash_compile_time("amaranth"):
			currentSeed = fruitKind::amaranth;
			pictureName = "amaranth.png";
			break;
		case hash_compile_time("grape"):
			currentSeed = fruitKind::grape;
			pictureName = "grape.png";
			break;
		case hash_compile_time("artichoke"):
			currentSeed = fruitKind::artichoke;
			pictureName = "artichoke.png";
			break;
		default:
			break;
		}
	}

	static Fruit* create(std::string fishName) {
		Fruit* newFruit = new Fruit(fishName);
		return newFruit;
	}
};

//����----�����Ʒ��AnimalProduct
class AnimalProduct : public Item {
public:
	enum class AnimalProductKind {
		null,
		egg,//��
		bigegg,//��
		brownegg,//�ص�
		brownbigegg,//���ص�
		goldegg,//��
		duckegg,//Ѽ��
		duckfeather,//Ѽë
		animalfeather,//����ë
		rabbitleg,//����
		milk,//ţ��
		largemilk,//��ƿţ��
		goatmilk,//����
		largegoatmilk,//��ƿ����
		truffles,//��¶
		honey,//����
		bugmeat//����
	};

	AnimalProductKind currentProduct = AnimalProductKind::null;

	void rightKeyFunction();

	int moneyToSell();

	AnimalProduct(std::string fishName)
	{
		itemtype = ItemType::animalproduct;
		name = fishName;
		quantity = 1;
		switch (hash_1(fishName.c_str())) {
		case hash_compile_time("egg"):
			currentProduct = AnimalProductKind::egg;//ȷ��������Ʒ
			pictureName = "egg.png";//�����ļ���
			break;
		case hash_compile_time("bigegg"):
			currentProduct = AnimalProductKind::bigegg;//ȷ��������Ʒ
			pictureName = "bigegg.png";//�����ļ���
			break;
		case hash_compile_time("brownegg"):
			currentProduct = AnimalProductKind::brownegg;//ȷ��������Ʒ
			pictureName = "brownegg.png";//�����ļ���
			break;
		case hash_compile_time("brownbigegg"):
			currentProduct = AnimalProductKind::brownbigegg;//ȷ��������Ʒ
			pictureName = "brownbigegg.png";//�����ļ���
			break;
		case hash_compile_time("goldegg"):
			currentProduct = AnimalProductKind::goldegg;//ȷ��������Ʒ
			pictureName = "goldegg.png";//�����ļ���
			break;
		case hash_compile_time("duckegg"):
			currentProduct = AnimalProductKind::duckegg;//ȷ��������Ʒ
			pictureName = "duckegg.png";//�����ļ���
			break;
		case hash_compile_time("duckfeather"):
			currentProduct = AnimalProductKind::duckfeather;//ȷ��������Ʒ
			pictureName = "duckfeather.png";//�����ļ���
			break;
		case hash_compile_time("animalfeather"):
			currentProduct = AnimalProductKind::animalfeather;//ȷ��������Ʒ
			pictureName = "animalfeather.png";//�����ļ���
			break;
		case hash_compile_time("rabbitleg"):
			currentProduct = AnimalProductKind::rabbitleg;//ȷ��������Ʒ
			pictureName = "rabbitleg.png";//�����ļ���
			break;
		case hash_compile_time("milk"):
			currentProduct = AnimalProductKind::milk;//ȷ��������Ʒ
			pictureName = "milk.png";//�����ļ���
			break;
		case hash_compile_time("largemilk"):
			currentProduct = AnimalProductKind::largemilk;//ȷ��������Ʒ
			pictureName = "largemilk.png";//�����ļ���
			break;
		case hash_compile_time("goatmilk"):
			currentProduct = AnimalProductKind::goatmilk;//ȷ��������Ʒ
			pictureName = "goatmilk.png";//�����ļ���
			break;
		case hash_compile_time("largegoatmilk"):
			currentProduct = AnimalProductKind::largegoatmilk;//ȷ��������Ʒ
			pictureName = "goatmilk.png";//�����ļ���
			break;
		case hash_compile_time("Truffles"):
			currentProduct = AnimalProductKind::truffles;//ȷ��������Ʒ
			pictureName = "Truffles.png";//�����ļ���
			break;
		case hash_compile_time("honey"):
			currentProduct = AnimalProductKind::honey;//ȷ��������Ʒ
			pictureName = "honey.png";//�����ļ���
			break;
		case hash_compile_time("bugmeat"):
			currentProduct = AnimalProductKind::bugmeat;//ȷ��������Ʒ
			pictureName = "bugmeat.png";//�����ļ���
			break;
		}
	}

	static AnimalProduct* create(std::string fishName) {
		AnimalProduct* newFruit = new AnimalProduct(fishName);
		return newFruit;
	}
};

//����----������terial
class terial : public Item {
public:
	enum class terialKind {
		null,
		wood,//ľͷ
		stone,//ʯͷ
		sap,//��Һ
		copperore,//ͭ��
		ironore,//����
		goldore,//����
		copperbar,//ͭ��
		ironbar,//����
		goldbar,//��
		coal,//ú̿
		fibre,//��ά
	};

	terialKind currentProduct = terialKind::null;

	int moneyToSell();

	terial(std::string fishName)
	{
		itemtype = ItemType::terial;
		name = fishName;
		quantity = 1;
		switch (hash_1(fishName.c_str())) {
		case hash_compile_time("wood"):
			currentProduct = terialKind::wood;//ȷ��������Ʒ
			pictureName = "wood.png";//�����ļ���
			break;
		case hash_compile_time("stone"):
			currentProduct = terialKind::stone;//ȷ��������Ʒ
			pictureName = "stone.png";//�����ļ���
			break;
		case hash_compile_time("sap"):
			currentProduct = terialKind::sap;//ȷ��������Ʒ
			pictureName = "sap.png";//�����ļ���
			break;
		case hash_compile_time("copperore"):
			currentProduct = terialKind::copperore;//ȷ��������Ʒ
			pictureName = "copperore.png";//�����ļ���
			break;
		case hash_compile_time("ironore"):
			currentProduct = terialKind::ironore;//ȷ��������Ʒ
			pictureName = "ironoree.png";//�����ļ���
			break;
		case hash_compile_time("goldore"):
			currentProduct = terialKind::goldore;//ȷ��������Ʒ
			pictureName = "goldore.png";//�����ļ���
			break;
		case hash_compile_time("copperbar"):
			currentProduct = terialKind::copperbar;//ȷ��������Ʒ
			pictureName = "copperbar.png";//�����ļ���
			break;
		case hash_compile_time("ironbar"):
			pictureName = "ironbar.png";//�����ļ���
			currentProduct = terialKind::ironbar;//ȷ��������Ʒ
			break;
		case hash_compile_time("goldbar"):
			currentProduct = terialKind::goldbar;//ȷ��������Ʒ
			pictureName = "goldbar.png";//�����ļ���
			break;
		case hash_compile_time("coal"):
			currentProduct = terialKind::coal;//ȷ��������Ʒ
			pictureName = "coal.png";//�����ļ���
			break;
		case hash_compile_time("fibre"):
			currentProduct = terialKind::fibre;//ȷ��������Ʒ
			pictureName = "fibre.png";//�����ļ���
			break;
		}
	}

	static terial* create(char const* fishName) {
		terial* newFruit = new terial(fishName);
		return newFruit;
	}
};

#endif