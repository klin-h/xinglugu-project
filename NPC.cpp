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

//创建 NPC 对象并进行初始化
NPC::NPC(const std::string& name, int health) : Character(name, health) 
{
    dialogueText = "";
    quests = std::vector<QuestInfo>();
}

//获取游戏场景中的所有玩家对象列表,后续完善
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

//初始化以及触摸事件相关的设置
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

//检查是否有玩家进入了交互范围
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

//返回交互的玩家对象
Player* NPC::getInteractingPlayer() {
    return interactingPlayer;
}

//还未实现
bool NPC::shouldGiveQuest(){
    return 0;
}

// NPC类重写的交互方法实现示例，详细实现NPC交互相关信息
void NPC::interact() {
    // 当玩家与NPC交互时，获取当前交互的玩家对象
    Player* interactingPlayer = getInteractingPlayer();
    if (interactingPlayer) {
        // 提供对话内容
        std::string dialogue = getDialogue();
        CCLOG("NPC %s 对玩家说：%s", getName().c_str(), dialogue.c_str());

        // 判断是否满足给予任务的条件（这里简单假设不满足，实际需复杂判断）
        if (shouldGiveQuest()) {
            giveQuest(interactingPlayer);
        }
    }
}

// NPC提供对话内容的方法实现
std::string NPC::getDialogue() {
    return "欢迎来到这里，希望你过得愉快！";
}

// NPC给予任务的方法实现
void NPC::giveQuest(Player* player) {
    CCLOG("NPC %s 给予玩家 %s 一个新任务", getName().c_str(), player->getName().c_str());
    // 这里添加具体的任务设置
}