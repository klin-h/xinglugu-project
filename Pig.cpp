/****************************************************************
 * Project Name: xinglugu-project
 * File Pig.cpp
 * File Function: Implementation of Pig class
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#include "Pig.h"

USING_NS_CC;

bool Pig::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Pig_walk1.png")) 
    
    {
        CCLOG("Failed to load Pig.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Pig* Pig::create() {
    Pig* pig = new Pig();
    if (pig && pig->init()) {
        pig->autorelease();
        return pig;
    }
    delete pig;
    return nullptr;
}

Pig::Pig() {
    // 初始化猪的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Pig::~Pig() {
    // 清理资源（如果有）
}

void Pig::produce() {
    if (health_ > 0) {
        // 实现猪的产出逻辑（例如猪肉或肥料）
        CCLOG("Pig has produced fertilizer.");
    }
    else {
        CCLOG("Pig is not healthy enough to produce.");
    }
}

void Pig::oink() {
    CCLOG("Oink!");
    // 可以添加播放猪叫声音的逻辑
}

void Pig::heal(int amount) {
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Pig has been healed. Health: %d", health_);
}

void Pig::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    //// 假设你有 4 张行走图片：Pig_walk1.png, Pig_walk2.png, Pig_walk3.png, Pig_walk4.png
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));

    //// 检查是否成功加载每一帧
    //for (int i = 0; i < frames.size(); ++i) {
    //    if (frames.at(i) == nullptr) {
    //        CCLOG("Failed to load frame %d", i + 1);
    //    }
    //}
    auto spriteSheet = "PigWalk.png"; // 假设大图名为 Pig_walks.png，包含 Pig_walk1 ~ Pig_walk4
    auto spriteWidth = 32;  // 每张子图的宽度
    auto spriteHeight = 32; // 每张子图的高度

    // 加载精灵表
    auto texture = Director::getInstance()->getTextureCache()->addImage(spriteSheet);
    if (!texture) {
        CCLOG("Failed to load sprite sheet: %s", spriteSheet);
    }
    else {
        for (int i = 0; i < 4; ++i) { // 遍历子图
            Rect rect(i * spriteWidth, 0, spriteWidth, spriteHeight); // 计算子图的位置
            auto frame = SpriteFrame::createWithTexture(texture, rect);
            if (frame) {
                frames.pushBack(frame); // 将子图帧加入 frames
            }
            else {
                CCLOG("Failed to create frame for index: %d", i);
            }
        }
    }

    // 检查是否成功加载每一帧
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
        else {
            CCLOG("Loaded frame %d successfully", i + 1);
        }
    }
    // 创建动画对象
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // 每帧 0.2 秒
    Animate* animate = Animate::create(animation);

    // 无限循环动画
    this->runAction(RepeatForever::create(animate));

    isWalking_ = true;
    CCLOG("Pig walking animation started.");
}

void Pig::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Pig_walk4.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Pig has stopped walking.");
}


USING_NS_CC;

bool Sheep::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Sheep_walk1.png")) {
        CCLOG("Failed to load Sheep.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Sheep* Sheep::create() {
    Sheep* sheep = new Sheep();
    if (sheep && sheep->init()) {
        sheep->autorelease();
        return sheep;
    }
    delete sheep;
    return nullptr;
}

Sheep::Sheep() {
    // 初始化羊的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Sheep::~Sheep() {
    // 清理资源（如果有）
}

void Sheep::produce() {
    if (health_ > 0) {
        // 实现羊的产出逻辑（例如羊毛）
        CCLOG("Sheep has produced wool.");
    }
    else {
        CCLOG("Sheep is not healthy enough to produce.");
    }
}

void Sheep::bleat() {
    CCLOG("Baa!");
    // 可以添加播放羊叫声音的逻辑
}

void Sheep::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    // 假设你有 4 张行走图片：Sheep_walk1.png, Sheep_walk2.png, Sheep_walk3.png, Sheep_walk4.png
    /*frames.pushBack(SpriteFrame::create("Sheep_walk1.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Sheep_walk2.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Sheep_walk3.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Sheep_walk4.png", Rect(0, 0, 32, 32)));

    if (frames.size() == 0) {
        CCLOG("Failed to load walking frames for Sheep!");
        return;
    }*/

    auto spriteSheet = "Sheep01.png"; // 假设大图名为 Pig_walks.png，包含 Pig_walk1 ~ Pig_walk4
    auto spriteWidth = 32;  // 每张子图的宽度
    auto spriteHeight = 32; // 每张子图的高度

    // 加载精灵表
    auto texture = Director::getInstance()->getTextureCache()->addImage(spriteSheet);
    if (!texture) {
        CCLOG("Failed to load sprite sheet: %s", spriteSheet);
    }
    else {
        for (int i = 0; i < 4; ++i) { // 遍历子图
            Rect rect(i * spriteWidth, 0, spriteWidth, spriteHeight); // 计算子图的位置
            auto frame = SpriteFrame::createWithTexture(texture, rect);
            if (frame) {
                frames.pushBack(frame); // 将子图帧加入 frames
            }
            else {
                CCLOG("Failed to create frame for index: %d", i);
            }
        }
    }

    // 检查是否成功加载每一帧
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
        else {
            CCLOG("Loaded frame %d successfully", i + 1);
        }
    }

    // 创建一个动画并播放
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f);  // 每帧0.2秒
    Animate* animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));  // 无限循环播放
}

void Sheep::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Sheep_walk1.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Pig has stopped walking.");
}


bool Dog::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Dog_walk1.png")) {
        CCLOG("Failed to load Dog.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Dog* Dog::create() {
    Dog* dog = new Dog();
    if (dog && dog->init()) {
        dog->autorelease();
        return dog;
    }
    delete dog;
    return nullptr;
}

Dog::Dog() {
    // 初始化狗的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Dog::~Dog() {
    // 清理资源（如果有）
}

void Dog::produce() {
    if (health_ > 0) {
        // 实现狗的产出逻辑（例如看门）
        CCLOG("Dog has barked and protected the farm.");
    }
    else {
        CCLOG("Dog is not healthy enough to protect.");
    }
}

void Dog::bark() {
    CCLOG("Woof!");
    // 可以添加播放狗叫声音的逻辑
}

void Dog::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    // 假设你有 4 张行走图片：Dog_walk1.png, Dog_walk2.png, Dog_walk3.png, Dog_walk4.png
    frames.pushBack(SpriteFrame::create("Dog_walk1.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Dog_walk2.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Dog_walk3.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Dog_walk4.png", Rect(0, 0, 32, 32)));

    if (frames.size() == 0) {
        CCLOG("Failed to load walking frames for Dog!");
        return;
    }

    // 创建一个动画并播放
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f);  // 每帧0.2秒
    Animate* animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));  // 无限循环播放
}

// 构造函数
Rabbit::Rabbit() {
    // 初始化兔子的属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

// 析构函数
Rabbit::~Rabbit() {
    // 清理资源（如果有）
}

// 初始化函数
bool Rabbit::init() {
    // 调用父类的 initWithFile 方法加载资源
    if (!Sprite::initWithFile("Rabbit_walk1.png")) {
        CCLOG("Failed to load Rabbit_walk1.png");
        return false;
    }

    // 初始化属性
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

// 创建 Rabbit 实例
Rabbit* Rabbit::create() {
    Rabbit* rabbit = new (std::nothrow) Rabbit();
    if (rabbit && rabbit->init()) {
        rabbit->autorelease();
        return rabbit;
    }
    delete rabbit;
    return nullptr;
}

// 实现 produce 函数
void Rabbit::produce() {
    if (health_ > 0) {
        // 实现兔子的产出逻辑（例如兔毛）
        CCLOG("Rabbit has produced wool.");
    }
    else {
        CCLOG("Rabbit is not healthy enough to produce.");
    }
}

// 兔子跳跃
void Rabbit::hop() {
    CCLOG("Rabbit hops!");
    // 可以添加播放跳跃动作或声音的逻辑
}

// 启动行走动画
void Rabbit::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    // 假设你有 4 张行走图片：Rabbit_walk1.png, Rabbit_walk2.png, Rabbit_walk3.png, Rabbit_walk4.png
    /*
    frames.pushBack(SpriteFrame::create("Rabbit_walk1.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Rabbit_walk2.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Rabbit_walk3.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Rabbit_walk4.png", Rect(0, 0, 32, 32)));

    if (frames.size() == 0) {
        CCLOG("Failed to load walking frames for Rabbit!");
        return;
    }
    */

    auto spriteSheet = "Rabbit01.png"; // 假设大图名为 Rabbit01.png，包含 Rabbit_walk1 ~ Rabbit_walk4
    auto spriteWidth = 32;  // 每张子图的宽度
    auto spriteHeight = 32; // 每张子图的高度

    // 加载精灵表
    auto texture = Director::getInstance()->getTextureCache()->addImage(spriteSheet);
    if (!texture) {
        CCLOG("Failed to load sprite sheet: %s", spriteSheet);
    }
    else {
        for (int i = 0; i < 4; ++i) { // 遍历子图
            Rect rect(i * spriteWidth, 0, spriteWidth, spriteHeight); // 计算子图的位置
            auto frame = SpriteFrame::createWithTexture(texture, rect);
            if (frame) {
                frames.pushBack(frame); // 将子图帧加入 frames
            }
            else {
                CCLOG("Failed to create frame for index: %d", i);
            }
        }
    }

    // 检查是否成功加载每一帧
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
        else {
            CCLOG("Loaded frame %d successfully", i + 1);
        }
    }

    // 创建一个动画并播放
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.1f);  // 每帧0.2秒
    Animate* animate = Animate::create(animation);
    this->runAction(RepeatForever::create(animate));  // 无限循环播放

    isWalking_ = true;
    CCLOG("Rabbit walking animation started.");
}

// 停止行走动画
void Rabbit::stopWalkingAnimation() {
    // 停止所有动画，并设置为默认静止帧
    this->stopAllActions();
    isWalking_ = false;

    auto texture = Director::getInstance()->getTextureCache()->addImage("Rabbit01.png");
    if (texture) {
        auto idleFrame = SpriteFrame::createWithTexture(texture, Rect(0, 0, 32, 32)); // 假设静止帧为第一帧
        if (idleFrame) {
            this->setSpriteFrame(idleFrame);
        }
    }

    CCLOG("Rabbit has stopped walking.");
}

