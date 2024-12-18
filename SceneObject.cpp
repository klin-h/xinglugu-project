#include "SceneObject.h"
#include "tree.h"
//#include "Rock.h"
//#include "Grass.h"

USING_NS_CC;

 //��̬��������
std::vector<SceneObject::Point> SceneObject::treePositions;
std::vector<SceneObject::Point> SceneObject::rockPositions;
std::vector<SceneObject::Point> SceneObject::grassPositions;

// ������굽��Ӧ�� vector
void SceneObject::addObjectPosition(ObjectType type, const SceneObject:: Point& position) {
    switch (type) {
        case ObjectType::Tree:
            treePositions.push_back(position);
            break;
        case ObjectType::Rock:
            rockPositions.push_back(position);
            break;
        case ObjectType::Grass:
            grassPositions.push_back(position);
            break;
    }
}

void  SceneObject::setpoint() {
    SceneObject::Point p1(5,5);
    addObjectPosition(ObjectType::Tree,p1);
    SceneObject::Point p2(3, 3);
    addObjectPosition(ObjectType::Tree, p2);
    SceneObject::Point p3(1,8);
   addObjectPosition(ObjectType::Tree, p3);
}

// ��ʼ�����г�������
void SceneObject::initSceneObject(cocos2d::Node* parentNode, float tileWidth, float tileHeight, std::vector<SceneObject*>& objectGrid) {
    SceneObject::setpoint();
    for (const auto& position : treePositions) {
        auto tree = createObject(ObjectType::Tree, tileWidth, tileHeight, position);
        if (tree) {
            parentNode->addChild(tree);
            objectGrid.push_back(tree);
        }
    }

    /*for (const auto& position : rockPositions) {
        auto rock = createObject(ObjectType::Rock, tileWidth, tileHeight, position);
        if (rock) {
            parentNode->addChild(rock);
            objectGrid.push_back(rock);
        }
    }

    for (const auto& position : grassPositions) {
        auto grass = createObject(ObjectType::Grass, tileWidth, tileHeight, position);
        if (grass) {
            parentNode->addChild(grass);
            objectGrid.push_back(grass);
        }
    }*/
}

SceneObject* SceneObject::createObject(ObjectType type, float tileWidth, float tileHeight, const Point& position) {
    SceneObject* object = nullptr;

     //������Ӧ���͵Ķ���
    switch (type) {
        case ObjectType::Tree:
            object = Tree::create("tree.png");
            break;
       /* case ObjectType::Rock:
            object = Rock::create("rock.png");
            break;
        case ObjectType::Grass:
            object = Grass::create("grass.png");
            break;*/
    }

    if (object) {
         //����ê��Ϊ���½�
        object->setAnchorPoint(cocos2d::Vec2(0, 0));

         //�������ű���
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