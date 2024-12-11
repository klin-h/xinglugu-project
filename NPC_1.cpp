/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC_1.cpp
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#include "NPC_1.h"
#include "Walking.h"
#include"string"

NPC_1::NPC_1() {
   

    sprite = nullptr;

    keyboardListener = nullptr;

}

NPC_1::~NPC_1() {
    CC_SAFE_RELEASE_NULL(sprite);

    
    CC_SAFE_RELEASE_NULL(keyboardListener);
}

NPC_1* NPC_1::create() {
    NPC_1* npc = new NPC_1();
    if (npc && npc->init()) {
        npc->autorelease();
        return npc;
    }
    CC_SAFE_DELETE(npc);
    return nullptr;
}

void NPC_1::setup(const Size& visibleSize, Vec2 origin) {
    sprite = Sprite::create("resources/SYN/Abigailf1.png");  
    if (sprite) {
        CCLOG("NPC_1 sprite loaded successfully");
    }
    else {
        CCLOG("Failed to load NPC_1 sprite image");
    }
    if (sprite) {
        Vec2 pos;
        pos.x = visibleSize.width / 2-8;
        pos.y = visibleSize.height / 2-8;
        position = pos;
        sprite->setPosition(position);
        this->addChild(sprite);  
    }
}


void NPC_1::movebyfour(NPC_1* P) {
    keyboardListener = EventListenerKeyboard::create();  
    if (keyboardListener) {
        Point Endposition;
       

        keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_UP_ARROW:  // 如果按向上箭头键
                Character::Moving(P->sprite, 1);
                Endposition == this->sprite->getPosition();
                break;
            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:  // 如果按向下箭头键
                Character::Moving(P->sprite, 0); 
                Endposition == this->sprite->getPosition();
                break;
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:  // 如果按向左箭头键
                Character::Moving(P->sprite, 2);  
                Endposition == this->sprite->getPosition();
                break;
            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:  // 如果按向右箭头键
                Character::Moving(P->sprite, 3);
                Endposition == this->sprite->getPosition();
                break;
            default:
                break;
            }
            };

       
        Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keyboardListener, 1);


    }

}


void NPC_1::testAddNPC_1(const Size& visibleSize, Vec2 origin) {
    // 创建NPC_1对象实例
    auto myNpc = NPC_1::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin);
    myNpc->movebyfour(myNpc);


}