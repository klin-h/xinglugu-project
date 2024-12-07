/****************************************************************
 * Project Name: xinglugu-project
 * File Cow.cpp
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#include "Cow.h"

USING_NS_CC;
bool Cow::init() {
    // ���ø���� initWithFile ����������Դ
    if (!Sprite::initWithFile("Cow.png")) 
    {
        CCLOG("Failed to load Cow.png");
        return false;
    }

    // ��ʼ������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;

    return true;
}

Cow* Cow::create() {
    Cow* cow = new Cow();
    if (cow && cow->init()) {
        cow->autorelease();
        return cow;
    }
    delete cow;
    return nullptr;
}

Cow::Cow()
{
    // ��ʼ��ţ������
    hunger_ = Constants::kDefaultAnimalHunger;
    mood_ = Constants::kDefaultAnimalMood;
    health_ = Constants::kDefaultAnimalHealth;
    
}

Cow::~Cow()
{
    // ������Դ������У�
}

void Cow::produce()
{
    if (health_ > 0) {
        // ʵ��ţ�Ĳ����߼�
        CCLOG("Cow has produced milk.");
        // ���磬����ţ�̿��
    }
    else {
        CCLOG("Cow is not healthy enough to produce milk.");
    }
}

void Cow::moo()
{
    CCLOG("Moo!");
    // ������Ӳ���ţ���������߼�
}

void Cow::heal(int amount)
{
    health_ += amount;
    if (health_ > Constants::kDefaultAnimalHealth) health_ = Constants::kDefaultAnimalHealth;
    CCLOG("Cow has been healed. Health: %d", health_);
}

void Cow::startWalkingAnimation() {

    Vector<SpriteFrame*> frames;

    // �������� 4 ������ͼƬ��Cow_walk1.png, Cow_walk2.png, Cow_walk3.png, Cow_walk4.png
   
        frames.pushBack(SpriteFrame::create("Cow_walk1.png", Rect(0, 0, 32, 32))); // ����ÿ��ͼƬ�Ĵ�СΪ 32x32
        frames.pushBack(SpriteFrame::create("Cow_walk2.png", Rect(0, 0, 32, 32)));
        frames.pushBack(SpriteFrame::create("Cow_walk3.png", Rect(0, 0, 32, 32)));
        frames.pushBack(SpriteFrame::create("Cow_walk1.png", Rect(0, 0, 32, 32)));

        // ����Ƿ�ɹ�����ÿһ֡
        for (int i = 0; i < frames.size(); ++i) {
            if (frames.at(i) == nullptr) {
                CCLOG("Failed to load frame %d", i + 1);
            }
        }

        

        // ������������
        Animation* animation = Animation::createWithSpriteFrames(frames, 0.2f); // ÿ֡ 0.2 ��
        Animate* animate = Animate::create(animation);

        //// ����ѭ������
        this->runAction(RepeatForever::create(animate));

        CCLOG("Cow walking animation started.");
    
}

//void Cow::moveTo(const Vec2& targetPosition, float duration) {
//    //// ����һ�� MoveTo ����
//    //auto moveToAction = MoveTo::create(duration, targetPosition);
//
//    //// ���һ���ص���ȷ���ƶ���ɺ���Խ���һЩ����
//    //auto callback = CallFunc::create([this]() {
//    //    CCLOG("Cow has moved to the target position.");
//    //    });
//
//    //// �������ж������ƶ� + �ص���
//    //this->runAction(Sequence::create(moveToAction, callback, nullptr));
//    // 
//    //this->startWalkingAnimation();
//
//    //// �����ƶ�����
//    //auto moveAction = MoveTo::create(duration, targetPosition);
//
//    //// �ƶ���ɺ�ֹͣ�����Ļص�
//    //auto stopAnimation = CallFunc::create([this]() {
//    //    this->stopWalkingAnimation();
//    //    });
//
//    //// ���ƶ���ֹͣ�����Ķ�����ϳ�����
//    //auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);
//
//    //// ���ж���
//    //this->runAction(sequence);
//    float distance = this->getPosition().distance(targetPosition);
//
//    // ���ݾ�����ٶȼ����ƶ�����ʱ��
//    duration = distance / Constants::kAnimalMoveSpeed;
//
//    // �������߶���
//    this->startWalkingAnimation();
//
//    // �����ƶ�����
//    auto moveAction = MoveTo::create(duration, targetPosition);
//
//    // �ƶ���ɺ�ֹͣ�����Ļص�
//    auto stopAnimation = CallFunc::create([this]() {
//        this->stopWalkingAnimation();
//        });
//
//    // ���ƶ���ֹͣ�����Ķ�����ϳ�����
//    auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);
//
//    // ���ж���
//    this->runAction(sequence);
//}
//
//void Cow::moveBy(const Vec2& offset, float duration) {
//    // ����һ�� MoveBy ����
//    auto moveByAction = MoveBy::create(duration, offset);
//
//    // ���һ���ص���ȷ���ƶ���ɺ���Խ���һЩ����
//    auto callback = CallFunc::create([this]() {
//        CCLOG("Cow has moved by the offset.");
//        });
//
//    // �������ж������ƶ� + �ص���
//    this->runAction(Sequence::create(moveByAction, callback, nullptr));
//}

//void Cow::moveToSequence(const std::vector<Vec2>& positions, float durationPerMove) {
//    // ��������Ŀ��λ�������Ƿ�Ϊ��
//    if (positions.empty()) {
//        CCLOG("No positions provided for moveToSequence.");
//        return;
//    }
//
//    // ����һ�����飬���ڴ洢���еĶ���
//    Vector<FiniteTimeAction*> actions;
//
//    // ����Ŀ��λ�����飬Ϊÿ��Ŀ�괴��һ�� MoveTo ����
//    for (const auto& targetPosition : positions) {
//        auto moveToAction = MoveTo::create(durationPerMove, targetPosition);
//        actions.pushBack(moveToAction);
//    }
//
//    // ���һ���ص����������ִ��
//    auto callback = CallFunc::create([this]() {
//        CCLOG("Cow has finished all movements.");
//        });
//    actions.pushBack(callback);
//
//    // �������ж���
//    auto sequence = Sequence::create(actions);
//
//    // ���ж�������
//    this->runAction(sequence);
//}

//void Cow::moveToSequence(const std::vector<Vec2>& positions, float durationPerMove) {
//    if (positions.empty()) {
//        CCLOG("No positions provided for moveToSequence.");
//        return;
//    }
//
//    // ����һ�������������ڴ洢�����ƶ�����
//    Vector<FiniteTimeAction*> actions;
//
//    // ���ƶ���ʼʱ�������߶���
//    auto startWalking = CallFunc::create([this]() {
//        if (!isWalking_) {
//            this->startWalkingAnimation();
//        }
//        });
//    actions.pushBack(startWalking);
//
//    // ��������Ŀ��λ�ã���� MoveTo ����
//    for (const auto& targetPosition : positions) {
//        auto moveToAction = MoveTo::create(durationPerMove, targetPosition);
//        actions.pushBack(moveToAction);
//    }
//
//    // ���ƶ�����ʱֹͣ���߶���
//    auto stopWalking = CallFunc::create([this]() {
//        this->stopWalkingAnimation();
//        });
//    actions.pushBack(stopWalking);
//
//    // ����һ�����ж���������
//    auto sequence = Sequence::create(actions);
//    this->runAction(sequence);
//}

void Cow::stopWalkingAnimation() {
    // ֹͣ���ж�����������ΪĬ�Ͼ�ֹ֡
    this->stopAllActions();
    isWalking_ = false;

    
    auto idleFrame = SpriteFrame::create("Cow_walk1.png", Rect(0, 0, this->getContentSize().width, this->getContentSize().height));
    if (idleFrame) {
        this->setSpriteFrame(idleFrame);
    }

    CCLOG("Cow has stopped walking.");
}