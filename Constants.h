/****************************************************************
 * Project Name: xinglugu-project
 * File Name:constants.h
 * File Function: const define
 * Author:all
 * Update Date:12.4
 * License:
 ****************************************************************/
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {// 使用时要加命名空间
    // 地图相关常量
    constexpr int MAP_BACKGROUND_LAYER_Z_ORDER = 0; // 地图背景层 z-order
    constexpr int kAnimalLayerZOrder = 1;

    // 动物相关默认值
    constexpr int kDefaultAnimalHunger = 100;    // 默认饥饿度
    constexpr int kDefaultAnimalMood = 100;      // 默认心情
    constexpr int kDefaultAnimalHealth = 100;    // 默认健康值
    constexpr float kAnimalMoveSpeed = 30.0f; // 动物每秒移动的像素距离  
    //物品类定义时，格式转换使用
    constexpr int primeZ = 0x100000001B3ull;
    constexpr int basisZ = 0xCBF29CE484222325ull;

    //背包栏切换控制量
    const bool BackOpen1 = 0;
    const bool BackOpen2 = 1;
    const bool BackPro1 = 0;
    const bool BackPro2 = 1;
    const int invventoryTag = 100;
   
    //物品数量的加减使用
    constexpr bool wayOfAdd = 0;
    constexpr bool wayOfDecrease = 1;

    //背包中的限定量
    constexpr int backpackCapacity = 36;
    constexpr int moneyInitialize = 500;
    constexpr int grade1 = 0;
    constexpr int grade2 = 0;
    constexpr int grade3 = 0;

    //合成台限定量
    constexpr int amountOfWoodForWoodenSign = 25;
    constexpr int amountOfWoodForWoodFence = 2;
    constexpr int amountOfWoodForGate = 10;
    constexpr int amountOfFibreForGrassStarter = 10;
    constexpr int amountOfWoodForWoodPath = 1;
    constexpr int amountOfStoneForCobblestonePath = 1;
    constexpr int amountOfWoodForTorch = 1;
    constexpr int amountOfSapForTorch = 2;
    constexpr int amountOfSapForBasicFertilizer = 2;
    constexpr int amountOfWoodForChest = 50; 
    constexpr int amountOfStoneForFurnace = 25;
    constexpr int amountOfCopperOreForFurnace = 20;
    constexpr int amountOfStoneForStoneSign = 25;
    constexpr int amountOfIronBarForSprinkle = 1;
    constexpr int amountOfCopperBarForSprinkle = 1;
    constexpr int amountOfStoneForBasicRetainingSoil = 2;
    constexpr int amountOfWoodForScareCrow = 50;
    constexpr int amountOfCoalForScareCrow = 1;
    constexpr int amountOfFibreForScareCrow = 20; 
    constexpr int amountOfBugmeatForBait = 1;

    //出售栈相关变量
    constexpr int maxnum = 200;
    constexpr int listInit = -1;
}
#endif // CONSTANTS_H
