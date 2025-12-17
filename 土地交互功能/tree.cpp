#include "tree.h"
USING_NS_CC;

Tree* Tree::create(const std::string& filename) {
    Tree* tree = new (std::nothrow) Tree();
    if (tree && tree->initWithFile(filename)) {
        tree->autorelease();
        return tree;
    }
    CC_SAFE_DELETE(tree);
    return nullptr;
}


SceneObject::InteractResult Tree::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据，而不是硬编码
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}

Rock* Rock::create(const std::string& filename) {
    Rock* rock = new (std::nothrow) Rock();
    if (rock && rock->initWithFile(filename)) {
        rock->autorelease();
        return rock;
    }
    CC_SAFE_DELETE(rock);
    return nullptr;
}

SceneObject::InteractResult Rock::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}

// Grass 类实现
Grass* Grass::create(const std::string& filename) {
    Grass* grass = new (std::nothrow) Grass();
    if (grass && grass->initWithFile(filename)) {
        grass->autorelease();
        return grass;
    }
    CC_SAFE_DELETE(grass);
    return nullptr;
}

SceneObject::InteractResult Grass::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}

// IronOre 类实现
IronOre* IronOre::create(const std::string& filename) {
    IronOre* ironOre = new (std::nothrow) IronOre();
    if (ironOre && ironOre->initWithFile(filename)) {
        ironOre->autorelease();
        return ironOre;
    }
    CC_SAFE_DELETE(ironOre);
    return nullptr;
}

SceneObject::InteractResult IronOre::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}

// SilverOre 类实现
SilverOre* SilverOre::create(const std::string& filename) {
    SilverOre* silverOre = new (std::nothrow) SilverOre();
    if (silverOre && silverOre->initWithFile(filename)) {
        silverOre->autorelease();
        return silverOre;
    }
    CC_SAFE_DELETE(silverOre);
    return nullptr;
}

SceneObject::InteractResult SilverOre::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}

// GoldOre 类实现
GoldOre* GoldOre::create(const std::string& filename) {
    GoldOre* goldOre = new (std::nothrow) GoldOre();
    if (goldOre && goldOre->initWithFile(filename)) {
        goldOre->autorelease();
        return goldOre;
    }
    CC_SAFE_DELETE(goldOre);
    return nullptr;
}

SceneObject::InteractResult GoldOre::interact() {
    CCLOG("%s was interacted with!", flyweight_->objectName.c_str());
    // 使用 Flyweight 中的共享数据
    this->setTexture(flyweight_->interactedTexture);
    return InteractResult(objectType_, flyweight_->dropQuantity, true);
}
