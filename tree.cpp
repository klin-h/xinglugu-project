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
    CCLOG("Tree was interacted with!"); 
    this->setTexture("tree_chopped.png"); // 改变树的纹理
    //this->setTexture("land_empty.png");
    return InteractResult(ObjectType::Tree, 5, true); // 玩家获得 5 单位木材
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
    CCLOG("Rock was interacted with!");
    this->setTexture("rock_broken.png"); // 改变岩石的纹理
    return InteractResult(ObjectType::Rock, 10, true); // 玩家获得 10 单位岩石
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
    CCLOG("Grass was interacted with!");
    this->setTexture("grass_harvested.png"); // 改变草的纹理
    return InteractResult(ObjectType::Grass, 2, true); // 玩家获得 2 单位草
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
    CCLOG("IronOre was interacted with!");
    this->setTexture("iron_ore_mined.png"); // 改变铁矿石的纹理
    return InteractResult(ObjectType::IronOre, 15, true); // 玩家获得 15 单位铁矿石
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
    CCLOG("SilverOre was interacted with!");
    this->setTexture("silver_ore_mined.png"); // 改变银矿石的纹理
    return InteractResult(ObjectType::SilverOre, 20, true); // 玩家获得 20 单位银矿石
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
    CCLOG("GoldOre was interacted with!");
    this->setTexture("gold_ore_mined.png"); // 改变金矿石的纹理
    return InteractResult(ObjectType::GoldOre, 25, true); // 玩家获得 25 单位金矿石
}
