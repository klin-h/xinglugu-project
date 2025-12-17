#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "cocos2d.h"
#include "SceneObjectFlyweight.h"
#include <memory>
#include <map>

class Tree;

class SceneObject : public cocos2d::Sprite {
public:
    enum class ObjectType {
        Tree,
        Rock,
        Grass,
        IronOre,   // 新增：铁矿石
        SilverOre, // 新增：银矿石
        GoldOre,   // 新增：金矿石
        // 其他物体类型
    };

    struct Point {
        int x;
        int y;

        Point(int xVal, int yVal) : x(xVal), y(yVal) {}
    };

    struct InteractResult {
        SceneObject::ObjectType type;
        int quantity;
        bool success;

        InteractResult(SceneObject::ObjectType t, int q, bool s)
            : type(t), quantity(q), success(s) {}
    };

    // 初始化场景物体
    static void initSceneObject(cocos2d::Node* parentNode, float tileWidth, float tileHeight, std::vector<SceneObject*>& objectGrid);

    // 添加物体坐标
    static void addObjectPosition(ObjectType type, const Point& position);

    virtual InteractResult interact() = 0;

protected:
    // 外部状态：由每个实例独立保存
    ObjectType objectType_;
    bool isInteracted_;
    const SceneObjectFlyweight* flyweight_;

    // 构造函数
    SceneObject(ObjectType type);

private:
    // 存储不同类型物体的坐标
    static std::map<ObjectType, std::vector<Point>> objectPositions_;

    // 创建具体物体
    static SceneObject* createObject(ObjectType type, float tileWidth, float tileHeight, const Point& position);
    static void setpoint();
};



#endif // SCENEOBJECT_H
