/****************************************************************
 * Project Name: xinglugu-project
 * File exchange.h
 * File Function: Shop subsystem classes (craftTable, Pierre, BlackSmith)
 * Author: Li Siyuan
 * Update Date: 2024.12.4
 * License:
 * 
 * ============================================================
 * Refactored with Facade Pattern (外观模式重构)
 * ============================================================
 * 
 * This file contains:
 * 1. Subsystem classes (craftTable, Pierre, BlackSmith)
 * 2. ShopFacade class - provides unified interface for all shops
 * 
 * The ShopFacade class implements the Facade Pattern by encapsulating
 * the complexity of different shop interfaces and providing a unified,
 * simplified interface for clients.
 * 
 * While subsystem classes remain functional for backward compatibility,
 * new code should preferably use ShopFacade for a simpler interface.
 * 
 ****************************************************************/
#ifndef __EXCHANGE_H_
#define __EXCHANGE_H_
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include"back.h"
#include"Constants.h"
#include"usableItem.h"
#include <string>
#include <sstream>
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

// ============================================================
// Refactored with Facade Pattern (外观模式重构)
// ============================================================
// ShopFacade Class - Unified Interface for All Shops
// ============================================================

/**
 * @enum ShopType
 * @brief Enumeration of available shop types in the game
 * 
 * Part of Facade Pattern: Provides a unified way to identify shops
 */
enum class ShopType {
    CRAFT_TABLE,    // 合成台 - Crafting workbench
    PIERRE,         // 皮埃尔商店 - Pierre's seed shop
    BLACKSMITH      // 铁匠铺 - Blacksmith shop
};

/**
 * @struct ShopResult
 * @brief Unified result structure for all shop operations
 * 
 * Part of Facade Pattern: Standardizes return values across all shop operations
 */
struct ShopResult {
    bool success;           // Whether the operation succeeded
    Item* item;             // The item obtained (if any)
    std::string message;    // Description or error message
    int cost;               // Money spent (for purchases)
    
    // Default constructor
    ShopResult() : success(false), item(nullptr), message(""), cost(0) {}
    
    // Convenience constructor for success case
    ShopResult(bool succ, Item* itm, const std::string& msg, int c = 0)
        : success(succ), item(itm), message(msg), cost(c) {}
};

/**
 * @class ShopFacade
 * @brief Facade class that provides unified interface for all shop subsystems
 * 
 * This class implements the Facade Pattern by:
 * 1. Encapsulating craftTable, Pierre, and BlackSmith classes
 * 2. Providing simplified methods for common operations
 * 3. Handling the complexity of different shop interfaces internally
 * 
 * Usage Example:
 * @code
 *   ShopFacade* shop = new ShopFacade(backpack);
 *   shop->setSeason(1); // Spring
 *   
 *   // Check if can afford
 *   if (shop->canAfford(ShopType::PIERRE, 0)) {
 *       // Purchase item
 *       ShopResult result = shop->purchaseItem(ShopType::PIERRE, 0);
 *       if (result.success) {
 *           // Item automatically added to backpack
 *       }
 *   }
 *   
 *   // Craft item
 *   if (shop->canAfford(ShopType::CRAFT_TABLE, 0)) {
 *       ShopResult result = shop->craftItem(0);
 *       if (result.success) {
 *           // Item crafted and added to backpack
 *       }
 *   }
 * @endcode
 */
class ShopFacade {
private:
    // ============================================================
    // Subsystem instances (encapsulated by Facade)
    // ============================================================
    craftTable* m_craftTable;      // 合成台子系统
    Pierre* m_pierreShop;          // 皮埃尔商店子系统
    BlackSmith* m_blacksmithShop;  // 铁匠铺子系统
    
    // Player's backpack reference
    backPack* m_backpack;
    
    // Current game season (affects Pierre's shop inventory)
    int m_currentSeason;
    
    // Crafting table grade
    int m_craftTableGrade;
    
    // ============================================================
    // Private helper methods
    // ============================================================
    
    /**
     * @brief Internal method to purchase from Pierre's shop
     * @param itemId The item ID to purchase
     * @return ShopResult with operation result
     */
    ShopResult purchaseFromPierre(int itemId);
    
    /**
     * @brief Internal method to purchase from Blacksmith
     * @param itemId The item ID to purchase
     * @return ShopResult with operation result
     */
    ShopResult purchaseFromBlacksmith(int itemId);
    
    /**
     * @brief Internal method to craft item at crafting table
     * @param itemId The item ID to craft
     * @return ShopResult with operation result
     */
    ShopResult craftFromTable(int itemId);
    
public:
    // ============================================================
    // Constructors and Destructor
    // ============================================================
    
    /**
     * @brief Constructor for ShopFacade
     * @param backpack Pointer to player's backpack (required)
     * @param craftGrade Initial crafting table grade (default: 1)
     * @param season Initial season (default: 1 = Spring)
     */
    ShopFacade(backPack* backpack, int craftGrade = 1, int season = 1);
    
    /**
     * @brief Destructor - cleans up subsystem instances
     */
    ~ShopFacade();
    
    // ============================================================
    // Unified Public Interface (Facade Pattern Core)
    // ============================================================
    
    /**
     * @brief Purchase an item from specified shop
     * 
     * This is the main unified interface for purchasing items.
     * It handles all the complexity of different shop interfaces internally.
     * 
     * @param shopType The type of shop to purchase from
     * @param itemId The item ID to purchase
     * @return ShopResult containing success status, item, and message
     * 
     * @note For CRAFT_TABLE, use craftItem() instead
     */
    ShopResult purchaseItem(ShopType shopType, int itemId);
    
    /**
     * @brief Craft an item at the crafting table
     * 
     * Unified interface for crafting. Handles material checking,
     * material consumption, and item creation internally.
     * 
     * @param itemId The item ID to craft
     * @return ShopResult containing success status, crafted item, and message
     */
    ShopResult craftItem(int itemId);
    
    /**
     * @brief Check if player can afford an item/crafting
     * 
     * Unified affordability check across all shop types.
     * For CRAFT_TABLE: checks if player has required materials
     * For PIERRE/BLACKSMITH: checks if player has enough money
     * 
     * @param shopType The type of shop
     * @param itemId The item ID to check
     * @return true if player can afford, false otherwise
     */
    bool canAfford(ShopType shopType, int itemId);
    
    /**
     * @brief Get the price of an item
     * 
     * @param shopType The type of shop
     * @param itemId The item ID
     * @return Price in gold, or -1 if not applicable (e.g., crafting)
     */
    int getItemPrice(ShopType shopType, int itemId);
    
    /**
     * @brief Get the name of an item
     * 
     * @param shopType The type of shop
     * @param itemId The item ID
     * @param includeExtension Whether to include file extension (.png)
     * @return Item name string
     */
    std::string getItemName(ShopType shopType, int itemId, bool includeExtension = false);
    
    /**
     * @brief Get crafting recipe description
     * 
     * Only applicable for CRAFT_TABLE items.
     * 
     * @param itemId The item ID
     * @return Recipe string (e.g., "25 wood, 10 stone")
     */
    std::string getCraftRecipe(int itemId);
    
    // ============================================================
    // Configuration Methods
    // ============================================================
    
    /**
     * @brief Set the current game season
     * 
     * Season affects Pierre's shop inventory and prices.
     * 
     * @param season Season number (1=Spring, 2=Summer, 3=Fall, 4=Winter)
     */
    void setSeason(int season);
    
    /**
     * @brief Get the current season
     * @return Current season number
     */
    int getSeason() const;
    
    /**
     * @brief Set crafting table grade
     * 
     * Higher grades may unlock more crafting recipes.
     * 
     * @param grade The grade level
     */
    void setCraftTableGrade(int grade);
    
    /**
     * @brief Get crafting table grade
     * @return Current grade level
     */
    int getCraftTableGrade() const;
    
    /**
     * @brief Get player's current money
     * @return Current money amount
     */
    int getPlayerMoney() const;
    
    // ============================================================
    // Utility Methods
    // ============================================================
    
    /**
     * @brief Get shop type name as string (for debugging/logging)
     * @param shopType The shop type
     * @return Shop name string
     */
    static std::string getShopTypeName(ShopType shopType);
};
// ============================================================

#endif  
