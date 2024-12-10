/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.cpp
 * File Function: 
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "NPC.h"
USING_NS_CC;

//���� NPC ���󲢽��г�ʼ��
NPC::NPC(const std::string& name, int health) : Character(name, health) 
{
    dialogueText = "";
    quests = std::vector<QuestInfo>();
}

//��ȡ��Ϸ�����е�������Ҷ����б�,��������
std::vector<Player*> getGameScenePlayers() {
    return std::vector<Player*>();
}

Player* getPlayerFromTouchEvent(cocos2d::Touch* touch) {
    cocos2d::Vec2 touchLocation = touch->getLocation();

    auto allPlayers = getGameScenePlayers();

    for (auto player : allPlayers) {
        
        cocos2d::Vec2 playerPosition = player->getPosition();
        cocos2d::Rect playerBoundingBox = player->getBoundingBox();

        if (playerBoundingBox.containsPoint(touchLocation)) {
            return player;
        }
    }

    return nullptr;
}

//��ʼ���Լ������¼���ص�����
NPC::NPC()
    :interactingPlayer(nullptr), isPlayerInRange(false) {
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [=](cocos2d::Touch* touch, cocos2d::Event* event) {

        cocos2d::Vec2 touchLocation = this->convertToNodeSpace(touch->getLocation());
        cocos2d::Rect boundingBox = this->getBoundingBox();
        if (boundingBox.containsPoint(touchLocation)) {
            if (isPlayerInRange) {
                interactingPlayer = getPlayerFromTouchEvent(touch);
                return true;
            }
        }
        return false;
        };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

NPC::~NPC() {
    auto dispatcher = cocos2d::Director::getInstance()->getEventDispatcher();

    auto listenerToRemove = cocos2d::EventListenerTouchOneByOne::create();

    listenerToRemove->setSwallowTouches(true);

    dispatcher->removeEventListener(listenerToRemove);
}

//����Ƿ�����ҽ����˽�����Χ
void NPC::checkPlayerInRange() {
    cocos2d::Vec2 npcPosition = this->getPosition();

    GameScene* currentScene = GameScene::getInstance();

    auto allPlayers = currentScene->getAllPlayers();

    for (auto player : allPlayers) {

        cocos2d::Vec2 playerPosition = player->getPosition();
        float distance = (npcPosition - playerPosition).length();

        if (distance < Constants::INTERACT_DISTANCE) {
            isPlayerInRange = true;
            return;
        }
    }

    isPlayerInRange = false;
}

//���ؽ�������Ҷ���
Player* NPC::getInteractingPlayer() {
    return interactingPlayer;
}

//��δʵ��
bool NPC::shouldGiveQuest(){
    return 0;
}

// NPC����д�Ľ�������ʵ��ʾ������ϸʵ��NPC���������Ϣ
void NPC::interact() {
    // �������NPC����ʱ����ȡ��ǰ��������Ҷ���
    Player* interactingPlayer = getInteractingPlayer();
    if (interactingPlayer) {
        // �ṩ�Ի�����
        std::string dialogue = getDialogue();
        CCLOG("NPC %s �����˵��%s", getName().c_str(), dialogue.c_str());

        // �ж��Ƿ�����������������������򵥼��費���㣬ʵ���踴���жϣ�
        if (shouldGiveQuest()) {
            giveQuest(interactingPlayer);
        }
    }
}

// NPC�ṩ�Ի����ݵķ���ʵ��
std::string NPC::getDialogue() {
    return "��ӭ�������ϣ���������죡";
}

// NPC��������ķ���ʵ��
void NPC::giveQuest(Player* player) {
    CCLOG("NPC %s ������� %s һ��������", getName().c_str(), player->getName().c_str());
    // ������Ӿ������������
}