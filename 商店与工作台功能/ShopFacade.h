/****************************************************************
 * Project Name: xinglugu-project
 * File Name: ShopFacade.h
 * File Function: Shop system facade - provides unified interface for all shops
 * Author: [Refactored]
 * Update Date: 2024.12
 * License:
 * 
 * ============================================================
 * Refactored with Facade Pattern (外观模式重构)
 * ============================================================
 * 
 * Purpose:
 * This class implements the Facade Pattern to provide a unified,
 * simplified interface for the shop subsystem, which includes:
 * - craftTable (合成台)
 * - Pierre (皮埃尔商店)
 * - BlackSmith (铁匠铺)
 * 
 * Benefits:
 * 1. Simplified client interface - clients only need to know ShopFacade
 * 2. Reduced coupling - clients don't depend on subsystem classes
 * 3. Better encapsulation - shop implementation details are hidden
 * 4. Easier maintenance - changes to subsystems don't affect clients
 * 
 * Before Refactoring:
 * - Clients needed to interact with craftTable, Pierre, BlackSmith directly
 * - Each shop had different interfaces and parameters
 * - Client code was complex and repetitive
 * 
 * After Refactoring:
 * - Clients use unified ShopFacade interface
 * - All shop operations follow consistent patterns
 * - Error handling and validation are centralized
 * 
 ****************************************************************/

#ifndef __SHOP_FACADE_H__
#define __SHOP_FACADE_H__

#include "cocos2d.h"
#include "exchange.h"
#include "back.h"
#include "usableItem.h"
#include <string>

USING_NS_CC;

// ============================================================
// Refactored with Facade Pattern - Enums and Structures
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

// ============================================================
// Refactored with Facade Pattern - Main Facade Class
// ============================================================

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

#endif // __SHOP_FACADE_H__

