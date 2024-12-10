/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef NPC_H
#define NPC_H


#include "Character.h"
#include "player.h"
#include "GameScenePlayer.h"
#include "ui/CocosGUI.h"
#include <vector>



// NPC类，继承自角色类
class NPC : public Character {
public:
    NPC();
    virtual ~NPC();
    Player *getInteractingPlayer();
    NPC(const std::string& name, int health);
    /*Player *getPlayerFromTouchEvent(cocos2d::Touch* touch);*/

    // 重写交互方法，实现NPC特有的交互逻辑，比如对话、给予任务等，这里详细扩展相关逻辑
    void interact() override;

    // NPC提供对话内容的方法
    std::string getDialogue();

    // NPC给予任务的方法
    void giveQuest(Player *player);

    bool shouldGiveQuest();

private:
    Player *interactingPlayer;
    bool isPlayerInRange;
    void checkPlayerInRange();
    
    std::string dialogueText;  // 记录对话内容的字符串变量

    // 使用结构体来表示一个任务的各项属性
    struct QuestInfo {
        std::string name;  // 任务名称
        std::string description;  // 任务描述
        int difficulty;  // 任务难度等级
        bool completed;  // 任务是否已完成，可用于记录任务状态
    };
    std::vector<QuestInfo> quests;

};

#endif

