#ifndef __PLANTING_SYSTEM_H__
#define __PLANTING_SYSTEM_H__

#include "cocos2d.h"
#include "Crop.h"
#include <vector>

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
