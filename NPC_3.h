#ifndef NPC_3_H
#define NPC_3_H

#include "NPC.h"
#include "NPC_1.h"
#include "cocos2d.h"
#include "TaskList.h"


USING_NS_CC;
class NPC_1;
class NPC_3 : public NPC {
public:
    NPC_3();
    virtual ~NPC_3();

    static NPC_3* create();
    void setup(const Size& visibleSize, Vec2 origin);
    void update(float dt);  
    void testAddNPC_3(const Size& visibleSize, Vec2 origin);  
    Sprite* sprite;

   
    // 处理鼠标点击事件的函数声明，将在.cpp文件中实现具体逻辑来响应点击并输出日志
    void onMouseClicked(cocos2d::Event* event);

    bool hasFriendshipWithNPC_1() const;  
    void updateFriendshipStatus();
    
    void generateTask();
    bool checkTaskCompletion(int itemCount);
    void giveReward();
    std::vector<Task> taskList;  

private:
    Vec2 position;
    Vec2 targetPosition; 
    float speed;  
    int friendshipLevel;
    cocos2d::EventListenerMouse* mouseListener;
    bool isFriendWithNPC_1;
};

#endif // NPC_3_H