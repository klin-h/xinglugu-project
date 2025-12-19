#ifndef NPC_3_H
#define NPC_3_H

#include "NPC.h"
#include "NPC_1.h"
#include "cocos2d.h"
#include "TaskList.h"
#include "back.h"
#include "Walking.h"
#include "Character.h"

USING_NS_CC;
extern backPack* pack1;
class NPC_1;

class NPC_3 : public NPC {
public:
    NPC_3();
    virtual ~NPC_3();

    static NPC_3* create();
    void setup(const Size& visibleSize, Vec2 origin, std::string name, Vec2 pos);
    
    // update 已在 Character 中声明为 virtual，这里 override
    // 但具体逻辑将委托给 State
    // void update(float dt) override; 

    void testAddNPC_3(const Size& visibleSize, Vec2 origin, std::string name, Vec2 pos);
    Sprite* sprite;

    // --- 供 State 调用的行为接口 ---
    void moveToTarget(float dt);
    void stopMoving();
    bool isTargetReached() const;
    // -----------------------------

    void onMouseClicked_Harvey(cocos2d::Event* event);
    void onMouseClicked_Haley(cocos2d::Event* event);

    void updateFriendshipStatus();
    void updateLoveshipStatus();
    void generateTask();
    bool checkTaskCompletion();
    void giveReward(std::string name);

    void Repairbuildings();
    bool checkRepair();
    void showNotEnoughFlowersAlert();
    void popupmessage(std::string message);
    std::vector<Task> taskList;

    // 公开部分私有变量供 State 使用 (或提供 getter/setter)
    Vec2 position;
    Vec2 targetPosition;
    float speed;

private:
    std::mutex positionMutex;
    std::mutex positionMutey;
    
    cocos2d::EventListenerMouse* mouseListener;
    int friendshipLevel;
    bool isFriendWithNPC_1;
    int loveshipLevel;
    bool isLoveWithNPC_1;
    bool onCollect;
    bool onRepair;
    bool Repaired;
};

#endif // NPC_3_H
