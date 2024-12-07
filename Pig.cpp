/****************************************************************
 * Project Name: xinglugu-project
 * File Pig.cpp
 * File Function: Implementation of Pig class
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#include "Pig.h"

USING_NS_CC;

bool Pig::init() {
    // ���ø���� initWithFile ����������Դ
    if (!Sprite::initWithFile("Pig_walk1.png")) 
    
    {
        CCLOG("Failed to load Pig.png");
        return false;
    }

    // ��ʼ������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Pig* Pig::create() {
    Pig* pig = new Pig();
    if (pig && pig->init()) {
        pig->autorelease();
        return pig;
    }
    delete pig;
    return nullptr;
}

Pig::Pig() {
    // ��ʼ���������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
}

Pig::~Pig() {
    // ������Դ������У�
}

void Pig::produce() {
    if (health_ > 0) {
        // ʵ����Ĳ����߼��������������ϣ�
        CCLOG("Pig has produced fertilizer.");
    }
    else {
        CCLOG("Pig is not healthy enough to produce.");
    }
}

void Pig::oink() {
    CCLOG("Oink!");
    // ������Ӳ�������������߼�
}

void Pig::heal(int amount) {
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Pig has been healed. Health: %d", health_);
}

void Pig::startWalkingAnimation() {
    Vector<SpriteFrame*> frames;

    //// �������� 4 ������ͼƬ��Pig_walk1.png, Pig_walk2.png, Pig_walk3.png, Pig_walk4.png
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));
    //frames.pushBack(SpriteFrame::create("Pig_walk4.png", Rect(0, 0, 32, 32)));

    //// ����Ƿ�ɹ�����ÿһ֡
    //for (int i = 0; i < frames.size(); ++i) {
    //    if (frames.at(i) == nullptr) {
    //        CCLOG("Failed to load frame %d", i + 1);
    //    }
    //}
    auto spriteSheet = "PigWalk.png"; // �����ͼ��Ϊ Pig_walks.png������ Pig_walk1 ~ Pig_walk4
    auto spriteWidth = 32;  // ÿ����ͼ�Ŀ��
    auto spriteHeight = 32; // ÿ����ͼ�ĸ߶�

    // ���ؾ����
    auto texture = Director::getInstance()->getTextureCache()->addImage(spriteSheet);
    if (!texture) {
        CCLOG("Failed to load sprite sheet: %s", spriteSheet);
    }
    else {
        for (int i = 0; i < 4; ++i) { // ������ͼ
            Rect rect(i * spriteWidth, 0, spriteWidth, spriteHeight); // ������ͼ��λ��
            auto frame = SpriteFrame::createWithTexture(texture, rect);
            if (frame) {
                frames.pushBack(frame); // ����ͼ֡���� frames
            }
            else {
                CCLOG("Failed to create frame for index: %d", i);
            }
        }
    }

    // ����Ƿ�ɹ�����ÿһ֡
    for (int i = 0; i < frames.size(); ++i) {
        if (frames.at(i) == nullptr) {
            CCLOG("Failed to load frame %d", i + 1);
        }
        else {
            CCLOG("Loaded frame %d successfully", i + 1);
        }
    }
    // ������������
    Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // ÿ֡ 0.2 ��
    Animate* animate = Animate::create(animation);

    // ����ѭ������
    this->runAction(RepeatForever::create(animate));

    isWalking_ = true;
    CCLOG("Pig walking animation started.");
}

void Pig::stopWalkingAnimation() {
    // ֹͣ���ж�����������ΪĬ�Ͼ�ֹ֡
    this->stopAllActions();
    isWalking_ = false;

    auto idleFrame = SpriteFrame::create("Pig_walk4.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Pig has stopped walking.");
}