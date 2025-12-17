#ifndef TREE_H
#define TREE_H
#include "SceneObject.h"


class Tree : public SceneObject {
public:
    static Tree* create(const std::string& filename);

    InteractResult interact() override; // 实现交互逻辑
    
private:
    Tree() : SceneObject(ObjectType::Tree) {}
};


class Rock : public SceneObject {
public:
    static Rock* create(const std::string& filename);
    InteractResult interact() override;

private:
    Rock() : SceneObject(ObjectType::Rock) {}
};

// Grass 类
class Grass : public SceneObject {
public:
    static Grass* create(const std::string& filename);
    InteractResult interact() override;

private:
    Grass() : SceneObject(ObjectType::Grass) {}
};

// IronOre 类
class IronOre : public SceneObject {
public:
    static IronOre* create(const std::string& filename);
    InteractResult interact() override;

private:
    IronOre() : SceneObject(ObjectType::IronOre) {}
};

// SilverOre 类
class SilverOre : public SceneObject {
public:
    static SilverOre* create(const std::string& filename);
    InteractResult interact() override;

private:
    SilverOre() : SceneObject(ObjectType::SilverOre) {}
};

// GoldOre 类
class GoldOre : public SceneObject {
public:
    static GoldOre* create(const std::string& filename);
    InteractResult interact() override;

private:
    GoldOre() : SceneObject(ObjectType::GoldOre) {}
};

#endif // TREE_H
