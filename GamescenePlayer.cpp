/****************************************************************
 * Project Name: xinglugu-project
 * File:GamescenePlayer.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "GameScenePlayer.h"

GameScene* GameScene::instance = nullptr;
// ��ȡ��Ϸ��������ʵ��
GameScene* GameScene::getInstance() {
    if (instance == nullptr) {
        cocos2d::Scene* tempScene = GameScene::create();  
        instance = dynamic_cast<GameScene*>(tempScene);
        if (instance == nullptr) {
            CCLOG("������Ϸ����ʵ��ʧ�ܻ�������ת������");
        }
    }
    return instance;
}


GameScene* GameScene::getCurrentGameScene() {
    return getInstance();
}

// ������Ϸ��������
void GameScene::destroyInstance() {
    CC_SAFE_DELETE(instance);
    instance = nullptr;
}


GameScene::GameScene() {}

GameScene::~GameScene() {}

// �����Ҷ�����Ϸ�����еĺ���ʵ�֣���Ӽ���߼�
void GameScene::addPlayer(Player* player) {
    if (player != nullptr) {
        players.push_back(player);
    }
    else {
        CCLOG("������ӿ�ָ����Ҷ�����Ӳ�����Ч");
    }
}

// ��ȡ��Ϸ������������Ҷ���ĺ���ʵ�֣�����const���÷�ֹ�ⲿ���޸�
 std::vector<Player*>& GameScene::getAllPlayers() {
    return players;
}

 void GameScene::addNPC(NPC* npc) {
     npcs.push_back(npc);
 }

 // ��ȡ��Ϸ����������NPC����ĺ���ʵ��
 std::vector<NPC*>& GameScene::getAllNPCs() {
     return npcs;
 }