#include "SceneObject.h"
#include "tree.h"


USING_NS_CC;

// 使用 std::map 代替多个独立的 vector，更易于维护
std::map<SceneObject::ObjectType, std::vector<SceneObject::Point>> SceneObject::objectPositions_;

SceneObject::SceneObject(ObjectType type)
    : objectType_(type),
      isInteracted_(false),
      flyweight_(nullptr) {
    // 从工厂获取对应的Flyweight对象
    flyweight_ = &SceneObjectFlyweightFactory::instance().getFlyweight(static_cast<SceneObjectType>(type));
}

// 添加坐标到对应的 map
void SceneObject::addObjectPosition(ObjectType type, const SceneObject::Point& position) {
    objectPositions_[type].push_back(position);
}

void SceneObject::setpoint() {
    SceneObject::Point p1(5, 5);
    addObjectPosition(ObjectType::Tree, p1);
    SceneObject::Point p2(3, 3);
    addObjectPosition(ObjectType::Tree, p2);
    SceneObject::Point p3(1, 8);
    addObjectPosition(ObjectType::Tree, p3);

    // 新增一些矿石的坐标
   /* SceneObject::Point ironOrePos(4, 6);
    addObjectPosition(ObjectType::IronOre, ironOrePos);
    SceneObject::Point silverOrePos(6, 7);
    addObjectPosition(ObjectType::SilverOre, silverOrePos);
    SceneObject::Point goldOrePos(2, 4);
    addObjectPosition(ObjectType::GoldOre, goldOrePos);*/
}

// 初始化所有场景物体
void SceneObject::initSceneObject(cocos2d::Node* parentNode, float tileWidth, float tileHeight, std::vector<SceneObject*>& objectGrid) {
    SceneObject::setpoint();
    
    // 遍历所有对象类型和它们的位置
    for (auto& [objectType, positions] : objectPositions_) {
        for (const auto& position : positions) {
            auto obj = createObject(objectType, tileWidth, tileHeight, position);
            if (obj) {
                parentNode->addChild(obj);
                objectGrid.push_back(obj);
            }
        }
    }
}

SceneObject* SceneObject::createObject(ObjectType type, float tileWidth, float tileHeight, const Point& position) {
    SceneObject* object = nullptr;

    // 创建对应类型的对象
    switch (type) {
        case ObjectType::Tree:
            object = Tree::create("tree.png");
            break;
        case ObjectType::Rock:
            object = Rock::create("rock.png");
            break;
        case ObjectType::Grass:
            object = Grass::create("grass.png");
            break;
        case ObjectType::IronOre:
            object = IronOre::create("iron_ore.png"); // 铁矿石图片
            break;
        case ObjectType::SilverOre:
            object = SilverOre::create("silver_ore.png"); // 银矿石图片
            break;
        case ObjectType::GoldOre:
            object = GoldOre::create("gold_ore.png"); // 金矿石图片
            break;
    }

    if (object) {
        // 设置锚点为左下角
        object->setAnchorPoint(cocos2d::Vec2(0, 0));

        // 计算缩放比例
        float scaleX = tileWidth / object->getContentSize().width;
        float scaleY = tileHeight / object->getContentSize().height;
        object->setScaleX(scaleX);
        object->setScaleY(scaleY);

        float xPos = position.x * tileWidth + tileWidth / 2;
        float yPos = position.y * tileHeight + tileHeight / 2;
        object->setPosition(cocos2d::Vec2(xPos, yPos));
    }

    return object;
}

