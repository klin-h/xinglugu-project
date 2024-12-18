#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "cocos2d.h"

class Tree;

class SceneObject : public cocos2d::Sprite {
public:
    enum class ObjectType {
        Tree,
        Rock,
        Grass,
        // ������������
    };
    struct Point {
        int x;
        int y;

        Point(int xVal, int yVal) : x(xVal), y(yVal) {}
    };

    struct InteractResult {
        SceneObject::ObjectType type; // ��Ʒ����
        int quantity;                // ��һ�õ���Դ����
        bool success;                // �Ƿ�ɹ�����

        InteractResult(SceneObject::ObjectType t, int q, bool s)
            : type(t), quantity(q), success(s) {}
    };

    // ��ʼ����������
    static void initSceneObject(cocos2d::Node* parentNode, float tileWidth, float tileHeight, std::vector<SceneObject*>& objectGrid);

    // �����������
    static void addObjectPosition(ObjectType type, const Point& position);

    virtual InteractResult interact() = 0;

private:
    // �洢��ͬ�������������
    static std::vector<Point> treePositions;
    static std::vector<Point> rockPositions;
    static std::vector<Point> grassPositions;
   
    // ������������
    static SceneObject* createObject(ObjectType type, float tileWidth, float tileHeight, const Point& position);
    static void setpoint();
};

#endif // SCENEOBJECT_H