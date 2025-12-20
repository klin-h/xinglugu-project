/****************************************************************
 * Project Name: xinglugu-project
 * File:Character.cpp
 * File Function: Refactored Character implementation
 * Author: Sun Yining (Refactored by Copilot)
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#include "Character.h"
#include "交互策略/InteractionStrategy.h" // Refactored with Strategy Pattern

USING_NS_CC;

Character::Character()
    : name("DefaultCharacter"),
    health(Constants::OriginHealth),
    animationState(AnimationState::IDLE),
    m_currentState(nullptr),
    m_interactionStrategy(nullptr) // Refactored with Strategy Pattern
{
    this->scheduleUpdate(); // 启用 update
}

Character::Character(const std::string& name, int health)
    : name(name),
    health(Constants::OriginHealth),
    animationState(AnimationState::IDLE),
    m_currentState(nullptr),
    m_interactionStrategy(nullptr) // Refactored with Strategy Pattern
{
    this->scheduleUpdate(); // 启用 update
}

Character::~Character() {
    if (m_currentState) {
        delete m_currentState;
        m_currentState = nullptr;
    }
    // Refactored with Strategy Pattern: 清理交互策略
    if (m_interactionStrategy) {
        delete m_interactionStrategy;
        m_interactionStrategy = nullptr;
    }
}

// --- 状态模式实现 ---
void Character::changeState(CharacterState* newState) {
    if (m_currentState) {
        m_currentState->exit(this);
        delete m_currentState;
    }
    m_currentState = newState;
    if (m_currentState) {
        m_currentState->enter(this);
    }
}

void Character::update(float dt) {
    if (m_currentState) {
        m_currentState->execute(this, dt);
    }
}

void Character::onKeyPressed(cocos2d::EventKeyboard::KeyCode code) {
    if (m_currentState) {
        m_currentState->handleInput(this, code);
    }
}
// -------------------

void Character::stopMoving(Sprite* sprite)
{
    if(sprite) sprite->stopAllActions();
}

void Character::Moving(Sprite* sprite, int direction,float t)
{
    // CCLOG("进入Character::Moving函数， sprite: %p, direction: %d", sprite, direction);
    if (!sprite) return;
    switch (direction) {
    case 0: {
        sprite->runAction(Walking::createAnimation("Abigail", "f"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(0, -16)));
        break;
    }
    case 1: {
        sprite->runAction(Walking::createAnimation("Abigail", "b"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(0, 16)));
        break;
    }
    case 2: {
        sprite->runAction(Walking::createAnimation("Abigail", "l"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(-16, 0)));
        break;
    }
    case 3: {
        sprite->runAction(Walking::createAnimation("Abigail", "r"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(16, 0)));
        break;
    }
    }
}

void Character::MovingContenly(Sprite* sprite, int direction, float t)
{
    if (!sprite) return;
    switch (direction) {
    case 0: {
        sprite->runAction(Walking::walkingContently(sprite, "Abigail", "f"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(0, -16)));
        break;
    }
    case 1: {
        sprite->runAction(Walking::walkingContently(sprite, "Abigail", "b"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(0, 16)));
        break;
    }
    case 2: {
        sprite->runAction(Walking::walkingContently(sprite, "Abigail", "l"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(-16, 0)));
        break;
    }
    case 3: {
        sprite->runAction(Walking::walkingContently(sprite, "Abigail", "r"));
        runAction(MoveTo::create(t, this->getPosition() + Vec2(16, 0)));
        break;
    }
    }
}

void Character::stop() {
    // 实现停止逻辑
    this->stopAllActions();
}

// ============================================================
// Refactored with Strategy Pattern (策略模式重构)
// ============================================================

void Character::setInteractionStrategy(InteractionStrategy* strategy) {
    // 如果已有策略，先释放
    if (m_interactionStrategy) {
        delete m_interactionStrategy;
    }
    m_interactionStrategy = strategy;
}

bool Character::executeInteraction(const Vec2& tileCoord,
                                  TMXTiledMap* map,
                                  backPack* pack,
                                  const Vec2& clickPosition) {
    if (!m_interactionStrategy) {
        CCLOG("Character::executeInteraction - No interaction strategy set");
        return false;
    }
    
    // 委托给策略对象执行交互
    return m_interactionStrategy->execute(tileCoord, map, pack, clickPosition);
}

// ============================================================
