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



// NPC�࣬�̳��Խ�ɫ��
class NPC : public Character {
public:
    NPC();
    virtual ~NPC();
    Player *getInteractingPlayer();
    NPC(const std::string& name, int health);
    /*Player *getPlayerFromTouchEvent(cocos2d::Touch* touch);*/

    // ��д����������ʵ��NPC���еĽ����߼�������Ի�����������ȣ�������ϸ��չ����߼�
    void interact() override;

    // NPC�ṩ�Ի����ݵķ���
    std::string getDialogue();

    // NPC��������ķ���
    void giveQuest(Player *player);

    bool shouldGiveQuest();

private:
    Player *interactingPlayer;
    bool isPlayerInRange;
    void checkPlayerInRange();
    
    std::string dialogueText;  // ��¼�Ի����ݵ��ַ�������

    // ʹ�ýṹ������ʾһ������ĸ�������
    struct QuestInfo {
        std::string name;  // ��������
        std::string description;  // ��������
        int difficulty;  // �����Ѷȵȼ�
        bool completed;  // �����Ƿ�����ɣ������ڼ�¼����״̬
    };
    std::vector<QuestInfo> quests;

};

#endif

