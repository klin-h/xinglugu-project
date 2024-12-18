/****************************************************************
 * Project Name: xinglugu-project
 * File NameAnimal.cpp
 * File Function:
 * Author:Gao wenhao
 * Update Date:2024.12.3
 * License:
 ****************************************************************/
#include "Animal.h"

USING_NS_CC;

Animal::Animal()
    : hunger_(Constants::kDefaultAnimalHunger),
    mood_(Constants::kDefaultAnimalMood),
    health_(Constants::kDefaultAnimalHealth),
    walkingCharacterNode(nullptr)


{
    // �������������һЩͨ�õĳ�ʼ���������Ҫ��
}

Animal::~Animal()
{
    // ������Դ������У�
}

void Animal::feed()
{
    // ʵ��ι���߼�
    hunger_ -= 10;
    if (hunger_ < 0) hunger_ = 0;
    mood_ += 5;
    if (mood_ > 100) mood_ = 100;

    // ���Ը�����Ҫ��Ӹ����߼������������ʾ״̬
    CCLOG("Animal has been fed. Hunger: %d, Mood: %d", hunger_, mood_);
}

int Animal::getHunger() const
{
    return hunger_;
}

void Animal::setHunger(int value)
{
    hunger_ = value;
}

int Animal::getMood() const
{
    return mood_;
}

void Animal::setMood(int value)
{
    mood_ = value;
}

int Animal::getHealth() const
{
    return health_;
}

void Animal::setHealth(int value)
{
    health_ = value;
}

void Animal::moveTo(const Vec2& targetPosition) {
    // �����ƶ�����
    float distance = this->getPosition().distance(targetPosition);

    // ���ݾ�����ٶȼ����ƶ�����ʱ��
    float duration = distance / Constants::kAnimalMoveSpeed;

    // �������߶���
    this->startWalkingAnimation();

    // �����ƶ�����
    auto moveAction = MoveTo::create(duration, targetPosition);

    // �ƶ���ɺ�ֹͣ�����Ļص�
    auto stopAnimation = CallFunc::create([this]() {
        this->stopWalkingAnimation();
        });

    // ���ƶ���ֹͣ�����Ķ�����ϳ�����
    auto sequence = Sequence::create(moveAction, stopAnimation, nullptr);

    // ���ж���
    this->runAction(sequence);
}

void Animal::moveToSequence(const std::vector<Vec2>& positions) {
    Vector<FiniteTimeAction*> actions;

    for (const auto& position : positions) {
        // ����ÿ���ƶ�����
        float distance = this->getPosition().distance(position);

        // ���ݾ�����ٶȼ����ƶ�����ʱ��
        float duration = distance / Constants::kAnimalMoveSpeed;

        // ����ƶ�����
        actions.pushBack(MoveTo::create(duration, position));
    }

    // ���ֹͣ�����Ļص�
    actions.pushBack(CallFunc::create([this]() {
        this->stopWalkingAnimation();
        }));

    // �������߶���
    this->startWalkingAnimation();

    // �����������в�����
    this->runAction(Sequence::create(actions));
}

void Animal::startWalkingAnimation() {
    // Ĭ��ʵ�֣����������д
    CCLOG("Start walking animation (default)");
}

void Animal::stopWalkingAnimation() {
    // Ĭ��ʵ�֣����������д
    CCLOG("Stop walking animation (default)");
}