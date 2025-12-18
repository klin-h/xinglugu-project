#ifndef __PLANTING_SYSTEM_H__
#define __PLANTING_SYSTEM_H__

#include "cocos2d.h"
#include "Crop.h"
#include <vector>
#include <string>
#include <algorithm>

// ============================================================
// Refactored with Object Pool Pattern (对象池模式重构)
// ============================================================
// 
// Purpose: 通过对象池模式优化作物对象的创建和销毁，减少内存分配开销
// 解决频繁种植/收获作物时的性能问题
// ============================================================

// 对象池类：管理作物对象的复用
class CropPool {
public:
    // 获取单例实例
    static CropPool* getInstance();
    
    // 从池中获取作物对象（如果池空则创建新的）
    Crop* acquire(const std::string& cropName, float growthTime, const std::string& spriteFile);
    
    // 归还作物对象到池中（而非销毁）
    void release(Crop* crop);
    
    // 预加载指定数量的作物对象到池中
    void preload(int count, const std::string& defaultCropName = "parsnip", 
                 float defaultGrowthTime = 120.0f, const std::string& defaultSpriteFile = "parsnip_seed.png");
    
    // 获取池状态信息
    int getAvailableCount() const;
    int getActiveCount() const;
    
    // 清空对象池
    void clear();

private:
    CropPool();
    ~CropPool();
    CropPool(const CropPool&) = delete;
    CropPool& operator=(const CropPool&) = delete;
    
    std::vector<Crop*> m_availableCrops;  // 可用对象池
    std::vector<Crop*> m_activeCrops;      // 使用中的对象
    static const int DEFAULT_POOL_SIZE = 20;
    static CropPool* s_instance;
};
// ============================================================

class PlantingSystem : public cocos2d::Node {
public:
    virtual bool init();

    bool plantCrop(const std::string& cropName, float growthTime, const std::string& spriteFileconst, const cocos2d::Vec2& position);
    void harvestCrop(cocos2d::Vec2 touchPosition);
    void update(float deltaTime);

    CREATE_FUNC(PlantingSystem);

private:
    std::vector<Crop*> crops; // 存储作物的容器
};

#endif // __PLANTING_SYSTEM_H__
