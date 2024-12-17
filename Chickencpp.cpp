/****************************************************************
 * Project Name: xinglugu-project
 * File Chicken.cpp
 * File Function: Implementation of Chicken class
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#include "Chicken.h"

USING_NS_CC;

bool Chicken::init() {
    // ���ø���� initWithFile ����������Դ
    if (!Sprite::initWithFile("Chicken.png")) {
        CCLOG("Failed to load Chicken.png");
        return false;
    }

    // ��ʼ������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Chicken* Chicken::create() {
    Chicken* chicken = new Chicken();
    if (chicken && chicken->init()) {
        chicken->autorelease();
        return chicken;
    }
    delete chicken;
    return nullptr;
}

Chicken::Chicken() {
    // ��ʼ����������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Chicken::~Chicken() {
    // ������Դ������У�
}

void Chicken::produce() {
    if (health_ > 0) {
        // ʵ�ּ��Ĳ����߼�
        CCLOG("Chicken has laid an egg.");
    }
    else {
        CCLOG("Chicken is not healthy enough to lay eggs.");
    }
}

void Chicken::cluck() {
    CCLOG("Cluck cluck!");
    // ������Ӳ��ż����������߼�
}

void Chicken::heal(int amount) {
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Chicken has been healed. Health: %d", health_);
}

void Chicken::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    // �������� 4 ������ͼƬ��Chicken_walk1.png, Chicken_walk2.png, Chicken_walk3.png, Chicken_walk4.png
    frames.pushBack(SpriteFrame::create("Chicken_walk1.png", Rect(0, 0, 32, 32))); // ����ÿ��ͼƬ�Ĵ�СΪ 32x32
    frames.pushBack(SpriteFrame::create("Chicken_walk2.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Chicken_walk3.png", Rect(0, 0, 32, 32)));
    frames.pushBack(SpriteFrame::create("Chicken_walk4.png", Rect(0, 0, 32, 32)));

    // ����Ƿ�ɹ�����ÿһ֡
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
    }

    // ������������
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // ÿ֡ 0.2 ��
    Animate* animate = Animate::create(animation);

    // ����ѭ������
    this->runAction(RepeatForever::create(animate));

    isWalking_ = true;
    CCLOG("Chicken walking animation started.");
}

void Chicken::stopWalkingAnimation() {
    // ֹͣ���ж�����������ΪĬ�Ͼ�ֹ֡
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Chicken_walk1.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Chicken has stopped walking.");
}