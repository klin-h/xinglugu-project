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

    // ��д����������ʵ��������еĽ����߼�
    void interact() override;

    // ��Ҵ򿪱����ķ���
    void openBackpack();

    // �����NPC�Ի��ķ���
    void talkToNPC(NPC* npc);

    // ��������ķ���
    void triggerQuest();


};

#endif
