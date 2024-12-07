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


// �����Ĺ��캯��ʵ��
Player::Player(const std::string& name, int health) : Character(name, health) {}

bool Player::isTouchOnNPC(NPC* npc) {
    return 0;
};

// ��ϸʵ����ҽ��������Ϣ
void Player::interact() {
    // ��ȡ��Ϸ�����е���Ҷ���
    Player* player = GameScene::getInstance()->getAllPlayers()[0];

    // ��ȡ��Ϸ���������е�NPC�����б�
    std::vector<NPC*>& allNPCs = GameScene::getInstance()->getAllNPCs();

    // ��������NPC
    for (NPC* npc : allNPCs) {
        cocos2d::Vec2 npcPosition = this->getPosition();
        cocos2d::Vec2 playerPosition = player->getPosition();
        float distance = (npcPosition - playerPosition).length();
    
        if (distance <= 50.0f && isTouchOnNPC(npc)) {
            // �������������������NPC�Ի��ķ���
            talkToNPC(npc);
        }
    }
}

// ��Ҵ򿪱����ķ���ʵ�֣�����ģ�ⵯ���������棨ʵ�������UIϵͳ��
void Player::openBackpack() {
    
}

// �����NPC�Ի��ķ���ʵ�֣�����򵥵����Ի����ڲ���ʾһЩ�Ի����ݣ�ʵ�������ƶԻ�ϵͳ��
void Player::talkToNPC(NPC* npc) {
    // �����Ի����ڲ�
    auto dialogLayer = cocos2d::Layer::create();

    // ���NPC��������ʾ
    auto npcNameLabel = cocos2d::Label::createWithTTF(npc->getName(), "xxx.ttf", 24);
    npcNameLabel->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, dialogLayer->getContentSize().height - 30));
    dialogLayer->addChild(npcNameLabel);

    // ģ���ȡNPC�ĶԻ����ݣ������Ӳ����һ�ζԻ���ʵ�����NPC�����л�ȡ��
    std::string dialog = "xxx";
    auto dialogContentLabel = cocos2d::Label::createWithTTF(dialog, "xxx.ttf", 20);
    dialogContentLabel->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, dialogLayer->getContentSize().height / 2));
    dialogLayer->addChild(dialogContentLabel);

    // ��Ӽ����Ի���ť����ʾ�����������Ի�ȡ��һ��Ի��ȣ�ʵ���������߼���
    auto continueButton = cocos2d::ui::Button::create("button_normal.png", "button_pressed.png");
    continueButton->setTitleText("����");
    continueButton->setPosition(cocos2d::Vec2(dialogLayer->getContentSize().width / 2, 30));
    continueButton->addClickEventListener([=](cocos2d::Ref* sender) {
        // ���������ӻ�ȡ��һ��Ի�������Ի���֧���߼�����ʡ��
        CCLOG("��������Ի���ť");
        });

    dialogLayer->addChild(continueButton);


    // ���Ի�������ӵ���Ϸ������
    auto gameScene = GameScene::getCurrentGameScene();
    gameScene->addChild(dialogLayer);
}

// ��Ҵ�������ķ���ʵ��
void Player::triggerQuest() {
    // �������ͨ��ĳ�������жϴ�����һ�����񣬱����ĳ���ض�NPC������


    CCLOG("��� %s ������һ��������", getName().c_str());
    // �������������������ص����ݳ�ʼ��������Ŀ�����õȲ���

}