#include "Crop.h"
using namespace cocos2d;
//构造函数
Crop::Crop(const std::string& cropName, float growthTime, const std::string& spriteFile)
    : name(cropName), growthTime(growthTime), currentTime(0.0f), state(State::SEED) {

    sprite = Sprite::create(spriteFile);
    if (sprite) {
        this->addChild(sprite);
    }
}
// 创建作物
Crop* Crop::create(const std::string& cropName, float growthTime, const std::string& spriteFile) {
    Crop* crop = new (std::nothrow) Crop(cropName, growthTime, spriteFile);
    if (crop && crop->init()) {
        crop->autorelease();//将 crop 的引用计数减少，将其添加到自动释放池中
        return crop;
    }
    CC_SAFE_DELETE(crop);//如果 crop 创建失败或 init() 返回 false，安全地删除 crop 对象以释放内存
    return nullptr;
}

//更新作物生长时间，每秒调用一次
void Crop::update(float deltaTime) {
    if (state == State::SEED) {
        currentTime += deltaTime;
        if (currentTime >= 60.0f) {
            state = State::GROWING;
            if (name == "cauliflower") {
                Crop::changeSpriteTexture("cauliflower_growing.png");
            }
            else if (name == "parsnip") {
                Crop::changeSpriteTexture("parsnip_growing.png");
            }
        }
    }
    else if (state == State::GROWING) {
        currentTime += deltaTime;
        if (currentTime >= growthTime) {
            state = State::HARVESTABLE; // 成长完成
            if (name == "cauliflower") {
                Crop::changeSpriteTexture("cauliflower_harvest.png");
            }
            else if (name == "parsnip") {
                Crop::changeSpriteTexture("parsnip_harvest.png");
            }
        }
    }
}

// 获取作物状态
Crop::State Crop::getState() const {
    return state;
}
// 获取作物名称
const std::string& Crop::getName() const {
    return name;
}

Sprite* Crop::getSprite() const {
    return sprite; // 返回精灵指针
}

void Crop::changeSpriteTexture(const std::string& newSpriteFile) {
    // 使用新的纹理更新精灵
    auto newTexture = cocos2d::Director::getInstance()->getTextureCache()->addImage(newSpriteFile);

    if (newTexture) {
        sprite->setTexture(newTexture); // 更换纹理
        CCLOG("B");
    }
    else {
        // 处理纹理加载失败的情况
        CCLOG("Failed to load texture: %s", newSpriteFile.c_str());
    }
}
bool Crop::isTouched(const cocos2d::Vec2& touchPosition) const {
    if (sprite) {
        auto boundingBox = sprite->getBoundingBox(); // 获取精灵的边界框
        return boundingBox.containsPoint(touchPosition); // 判断触摸点是否在边界框内
    }
    return false;
}
