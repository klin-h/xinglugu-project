/****************************************************************
 * Project Name: xinglugu-project
 * File initAnimalScene.cpp
 * File Function: init Animal on Scene
 * Author:Gao wenhao
 * Update Date:2024.12.5
 * License:
 ****************************************************************/

#include"initAnimalScene.h"

USING_NS_CC;


void setupAnimal(Scene* scene) {
    auto cow = Cow::create();
    auto pig = Pig::create();
    if (!pig) {
        CCLOG("Fail to creat pig");
        return;
    }
   
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    cow->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2
    ));
    pig->setPosition(Vec2(
        origin.x + visibleSize.width / 2 +10,
        origin.y + visibleSize.height / 2+ 10
    ));

    scene->addChild(cow, Constants::kAnimalLayerZOrder);
    // ��������ƶ��߼�
    cow->schedule([cow, visibleSize, origin](float) {
        if (!cow->getNumberOfRunningActions()) { // �����ǰû������ִ�е��ƶ�����
            // �������Ŀ��λ��
            float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
            float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
            Vec2 targetPosition(targetX, targetY);// �ƶ���Ŀ��λ��                      
            cow->moveTo(targetPosition);

        }
        }, 0.1f, "cow_random_move"); // ÿ 0.1 ����һ��

    // Ϊ Cow ��Ӵ���������

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [cow](Touch* touch, Event* event) -> bool {
        Vec2 touchLocation = touch->getLocation(); // ��ȡ����λ��
        if (cow->getBoundingBox().containsPoint(cow->getParent()->convertToNodeSpace(touchLocation))) {
            CCLOG("This is a cow"); // ��ӡ�����Ϣ
            cow->moo();
            cow->stopWalkingAnimation();
            
            return true; // �����¼���ֹͣ����
        }
        return false; // δ�����ţ�����������¼�
        };

    // �������������󶨵��¼��ַ���
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, cow);

    scene->addChild(pig, Constants::kAnimalLayerZOrder);

    // ��������ƶ��߼�
    pig->schedule([pig, visibleSize, origin](float) {
        if (!pig->getNumberOfRunningActions()) { // �����ǰû������ִ�е��ƶ�����
            // �������Ŀ��λ��
            float targetX = origin.x + CCRANDOM_0_1() * visibleSize.width;
            float targetY = origin.y + CCRANDOM_0_1() * visibleSize.height;
            Vec2 targetPosition(targetX, targetY);// �ƶ���Ŀ��λ��                      
            pig->moveTo(targetPosition);

        }
        }, 0.1f, "cow_random_move"); // ÿ 0.1 ����һ��

    // Ϊ Cow ��Ӵ���������
    
    auto touchListener_pig = EventListenerTouchOneByOne::create();
    touchListener_pig->onTouchBegan = [pig](Touch* touch, Event* event) -> bool {
        Vec2 touchLocation = touch->getLocation(); // ��ȡ����λ��
        if (pig->getBoundingBox().containsPoint(pig->getParent()->convertToNodeSpace(touchLocation))) {
            CCLOG("This is a pig"); // ��ӡ�����Ϣ
            pig->oink();
            pig->stopWalkingAnimation();
          
            return true; // �����¼���ֹͣ����
        }
        return false; // δ�����ţ�����������¼�
        };

    // �������������󶨵��¼��ַ���
    scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener_pig, pig);
}

