#ifndef TREE_H
#define TREE_H
#include "SceneObject.h"


class Tree : public SceneObject {
public:
    static Tree* create(const std::string& filename);

    InteractResult interact() override; // 实现交互逻辑
    
private:

};


class Rock : public SceneObject {
public:
    static Rock* create(const std::string& filename);
    InteractResult interact() override;
};

// Grass 类
class Grass : public SceneObject {
public:
    static Grass* create(const std::string& filename);
    InteractResult interact() override;
};

// IronOre 类
class IronOre : public SceneObject {
public:
    static IronOre* create(const std::string& filename);
    InteractResult interact() override;
};

// SilverOre 类
class SilverOre : public SceneObject {
public:
    static SilverOre* create(const std::string& filename);
    InteractResult interact() override;
};

// GoldOre 类
class GoldOre : public SceneObject {
public:
    static GoldOre* create(const std::string& filename);
    InteractResult interact() override;
};

#endif // TREE_H
