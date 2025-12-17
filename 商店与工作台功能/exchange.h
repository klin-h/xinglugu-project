/****************************************************************
 * Project Name: xinglugu-project
 * File exchange.h
 * File Function: Shop subsystem classes (craftTable, Pierre, BlackSmith)
 * Author: Li Siyuan
 * Update Date: 2024.12.4
 * License:
 * 
 * ============================================================
 * Note: This file contains subsystem classes that are encapsulated
 * by the Facade Pattern implementation in ShopFacade.h/cpp
 * 
 * Refactored with Facade Pattern (外观模式重构)
 * ============================================================
 * 
 * These classes (craftTable, Pierre, BlackSmith) form the subsystem
 * that is wrapped by ShopFacade class. While these classes remain
 * functional for backward compatibility, new code should preferably
 * use ShopFacade for a simpler and more unified interface.
 * 
 * See ShopFacade.h for the facade implementation.
 * 
 ****************************************************************/
#ifndef __EXCHANGE_H_
#define __EXCHANGE_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include"back.h"
#include"Constants.h"
USING_NS_CC;
using namespace Constants;

// ============================================================
// Subsystem Class: craftTable (合成台)
// Part of Facade Pattern - encapsulated by ShopFacade
// ============================================================

/**
 * @class craftTable
 * @brief Crafting workbench subsystem class
 * 
 * This class handles item crafting functionality.
 * It is encapsulated by ShopFacade as part of the Facade Pattern.
 * 
 * @note For new code, consider using ShopFacade::craftItem() instead
 *       of directly calling craftTable methods.
 */
class craftTable {
public:
	int grade;
	craftTable(int yourGrade) {
		grade = yourGrade;
	}
	void gradeExchange(int newGrade) {
		grade = newGrade;
	}
	bool changeForCraft(backPack* Back, int itemToMake);
	Item* getItem( int itemToMake);
	void itemDelete(backPack* Back, int itemToMake);
	std::string factorBack(int itemToMake);
};

// ============================================================
// Subsystem Class: Pierre (皮埃尔商店)
// Part of Facade Pattern - encapsulated by ShopFacade
// ============================================================

/**
 * @class Pierre
 * @brief Pierre's seed and supplies shop subsystem class
 * 
 * This class handles purchasing seeds and farming supplies.
 * It is encapsulated by ShopFacade as part of the Facade Pattern.
 * 
 * @note For new code, consider using ShopFacade::purchaseItem(ShopType::PIERRE, itemId)
 *       instead of directly calling Pierre methods.
 */
class Pierre {
private:
	std::string season;
public:
	Pierre() {
		season = "Spring";
	}
	bool isAffordable(backPack* Back, int itemToMake, int season);

	std::string itemMoneyOut(int posi, int season);

	int itemMoneyBack(int posi, int season);

	Item* getItem(backPack* Back, int itemToMake, int season);

	std::string itemNameOut(int no, int season, bool choise);

	void seasonEx(std::string season);

	std::string seasonOut();
};
// ============================================================
// Subsystem Class: BlackSmith (铁匠铺)
// Part of Facade Pattern - encapsulated by ShopFacade
// ============================================================

/**
 * @class BlackSmith
 * @brief Blacksmith shop subsystem class for tools and ores
 * 
 * This class handles purchasing ores and upgrading tools.
 * It is encapsulated by ShopFacade as part of the Facade Pattern.
 * 
 * @note For new code, consider using ShopFacade::purchaseItem(ShopType::BLACKSMITH, itemId)
 *       instead of directly calling BlackSmith methods.
 */
class BlackSmith {
public:
	BlackSmith() {
		;
	}
	bool isAffordable(backPack* Back, int itemToMaken);
	Item* getItem(backPack* Back, int itemToMake);
};

#endif  
