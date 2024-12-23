/****************************************************************
 * Project Name: xinglugu-project
 * File:GamescenePlayer.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef GAMESCENEPLAYER_H
#define GAMESCENEPLAYER_H


#include "cocos2d.h"
#include "NPC.h"
class Player;
class NPC;


class GameScene : public cocos2d::Scene {
public:
    // ��ȡ��Ϸ��������ʵ��
    static GameScene* getInstance();

    // ������Ϸ��������ʵ��
    static void destroyInstance();
    static GameScene* getCurrentGameScene();

    // �����Ҷ�����Ϸ�����еĺ���
    void addPlayer(Player* player);
    std::vector<Player*>& getAllPlayers();
    void addNPC(NPC* npc);
    std::vector<NPC*>& getAllNPCs();

private:
    // �洢����ʵ���ľ�ָ̬��
    static GameScene* instance ;

    
    std::vector<Player*> players;
    std::vector<NPC*> npcs;
    
    GameScene();
    virtual ~GameScene();

    // ��ֹ��������͸�ֵ������ȷ��������Ψһ��
    GameScene(const GameScene&) = delete;
    GameScene& operator=(const GameScene&) = delete;
};

#endif