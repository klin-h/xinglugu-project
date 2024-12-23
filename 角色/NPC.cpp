/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.cpp
 * File Function: 
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#include "NPC.h"
#include "NPC_1.h"

USING_NS_CC;

//���� NPC ���󲢽��г�ʼ��
NPC::NPC(const std::string& name, int health) : Character(name, health) 
{
    dialogueText = "";
    quests = std::vector<QuestInfo>();
}




//��ʼ���Լ������¼���ص�����
NPC::NPC()
    : isPlayerInRange(false)
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        cocos2d::Vec2 touchLocation = this->convertToNodeSpace(touch->getLocation());
        cocos2d::Rect boundingBox = this->getBoundingBox();
        if (boundingBox.containsPoint(touchLocation)) {
            // ����NPC_1����ҽ�ɫ��ͨ���ж�ʵ��������ȷ���Ƿ�Ϊ��ҽ���
            if (dynamic_cast<NPC_1*>(this) != nullptr) {
                // ������������ҽ�ɫ������ʼʱ�ľ����߼�������򿪽����˵���
                return true;
            }
            else {
                // ���ڷ���ҽ�ɫ��NPC��NPC_2��NPC_3�ȣ������������Ӧ�����߼���������ʾ��ʾ��Ϣ��
                return false;
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


