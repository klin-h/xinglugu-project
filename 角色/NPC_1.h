#ifndef NPC_1_H
#define NPC_1_H

#include "cocos2d.h"
#include "MapControl.h"
#include "NPC.h" // 确保包含 NPC 定义

USING_NS_CC;

class NPC_1 : public NPC {
public:
    NPC_1();
    virtual ~NPC_1();

    static NPC_1* create();
    void setup(const Size& visibleSize, Vec2 origin);
    
    // --- 重构：移除 movebyfour，改为 setupInputListener ---
    // void movebyfour(NPC_1* P, TMXTiledMap* map); // 已废弃
    void setupInputListener();
    
    // 供 State 调用的具体移动执行方法
    void executeMove(Vec2 direction);
    // ---------------------------------------------------

    cocos2d::Vec2 getPosition();
    char getDirection();

    void moveUp(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveDown(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveLeft(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void moveRight(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize);
    void checkAround(const Vec2& Endposition, TMXTiledMap* currentMap, MapControl* mapControl);
    
    MapControl* mapControl;
    Sprite* sprite;
   
    static bool isNear3(std::string);  // 判断是否靠近 NPC3
    void testAddNPC_1(const Size& visibleSize, Vec2 origin, TMXTiledMap* map, Scene* scene);
    Vec2 mapposition;

private:
    Scene* scene;
    Vec2 position; // 注意：Character 也有 position (Node::getPosition)，这里可能是逻辑坐标
    EventListenerKeyboard* keyboardListener;
};

#endif // NPC_1_H
