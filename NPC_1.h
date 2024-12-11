/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC_1.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.11
 * License:
 ****************************************************************/
#ifndef NPC_1_H
#define NPC_1_H

#include "NPC.h"
#include "cocos2d.h"

USING_NS_CC;

class NPC_1 : public NPC {
public:

    NPC_1(); 
    virtual ~NPC_1();  

    void setup(const Size& visibleSize, Vec2 origin);  
    static NPC_1* create();
    void movebyfour(NPC_1* P); 

   
    Sprite* sprite;
    void testAddNPC_1(const Size& visibleSize, Vec2 origin);
private:
    
    Vec2 position;  
    EventListenerKeyboard* keyboardListener;  
};

#endif // NPC_1_H