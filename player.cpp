/****************************************************************
 * Project Name: xinglugu-project
 * File:player.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "player.h"

USING_NS_CC;


// 玩家类的构造函数实现
Player::Player(const std::string& name, int health) : Character(name, health) {}

bool Player::isTouchOnNPC(NPC* npc) {
    return 0;
};

// 详细实现玩家交互相关信息
void Player::interact() {
    // 获取游戏场景中的玩家对象
    Player* player = GameScene::getInstance()->getAllPlayers()[0];

    // 获取游戏场景中所有的NPC对象列表
    std::vector<NPC*>& allNPCs = GameScene::getInstance()->getAllNPCs();

    // 遍历所有NPC
    for (NPC* npc : allNPCs) {
        cocos2d::Vec2 npcPosition = this->getPosition();
        cocos2d::Vec2 playerPosition = player->getPosition();
        float distance = (npcPosition - playerPosition).length();
    
        if (distance <= 50.0f && isTouchOnNPC(npc)) {
            // 如果满足条件，调用与NPC对话的方法
            talkToNPC(npc);
        }
    }
}

// 玩家打开背包的方法实现，这里模拟弹出背包界面（实际需关联UI系统）
void Player::openBackpack() {
    
}

// 玩家与NPC对话的方法实现，这里简单弹出对话窗口并显示一些对话内容（实际需完善对话系统）
void Player::talkToNPC(NPC* npc) {
    // 创建对话窗口层
    auto dialogLayer = cocos2d::Layer::create();

    // 添加NPC的名字显示
    auto npcNameLabel = cocos2d::Label::createWithTTF(npc->getName(), "xxx.ttf", 24);
    npcNameLabel->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, dialogLayer->getContentSize().height - 30));
    dialogLayer->addChild(npcNameLabel);

    // 模拟获取NPC的对话内容（这里简单硬编码一段对话，实际需从NPC数据中获取）
    std::string dialog = "xxx";
    auto dialogContentLabel = cocos2d::Label::createWithTTF(dialog, "xxx.ttf", 20);
    dialogContentLabel->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, dialogLayer->getContentSize().height / 2));
    dialogLayer->addChild(dialogContentLabel);

    // 添加继续对话按钮（简单示例，点击后可以获取下一句对话等，实际需完善逻辑）
    auto continueButton = cocos2d::ui::Button::create("button_normal.png", "button_pressed.png");
    continueButton->setTitleText("继续");
    continueButton->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, 30));
    continueButton->addClickEventListener([=](cocos2d::Ref* sender) {
        // 这里可以添加获取下一句对话、处理对话分支等逻辑，暂省略
        CCLOG("点击继续对话按钮");
        });

    dialogLayer->addChild(continueButton);


    // 将对话窗口添加到游戏场景中
    auto gameScene = GameScene::getCurrentGameScene();
    gameScene->addChild(dialogLayer);
}

// 玩家触发任务的方法实现
void Player::triggerQuest() {
    // 这里假设通过某种条件判断触发了一个任务，比如和某个特定NPC交互后


    CCLOG("玩家 %s 触发了一个新任务", getName().c_str());
    // 可以在这里进行任务相关的数据初始化、任务目标设置等操作

}