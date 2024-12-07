/****************************************************************
 * Project Name: xinglugu-project
 * File:player.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef PLAYER_H
#define PLAYER_H


#include "Character.h"
#include "NPC.h"
#include "GameScenePlayer.h"
#include "ui/CocosGUI.h"
class NPC;

class Player : public Character {
public:
    Player(const std::string& name, int health);

    bool isTouchOnNPC(NPC* npc) ;

    // 重写交互方法，实现玩家特有的交互逻辑
    void interact() override;

    // 玩家打开背包的方法
    void openBackpack();

    // 玩家与NPC对话的方法
    void talkToNPC(NPC* npc);

    // 触发任务的方法
    void triggerQuest();


};

#endif
