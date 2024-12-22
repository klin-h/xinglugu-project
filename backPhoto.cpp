/****************************************************************
* Project Name: xinglugu-project
* File Name:backPhoto.cpp
* File Function: const define
* Author:Li Siyuan
* Update Date:12.21
* License:
****************************************************************/
#include "MainScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "exchange.h"
#include "back.h"
#include "ItemOut.h"
#include "usableItem.h"
#include "Constants.h"
#include "backPhoto.h"
#include "Timer.h"
USING_NS_CC;
USING_NS_CC::ui;
using namespace Constants;
bool backIsOpen = BackOpen1;
bool backIsProed = BackPro1;

bool storeIsStart = 0;
bool storeIsOpen = 0;

bool craftIsStart = 0;
bool craftIsOpen = 0;

bool solditemchosen = 0;

RadioButton* Inventory[backpackCapacity];


RadioButton* soldPosi;

SoldBox* soldbox = new SoldBox();

RadioButton* ventory[backpackCapacity / 3];


void storePhoto(Scene* scene);

void craftPhoto(Scene* scene);

void soldBox(Scene* scene);

Sprite* displayItem;
bool isSelected = 0;

Layer* packLayer;

ScrollView* scrollview;

ScrollView* Craftview;

Sprite* moneyboard;

extern backPack* pack1;

Pierre* storeItem = new Pierre();

craftTable* craftItem = new craftTable(1);

//         
void soldPerform(int posi) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    if (posi < 0 || posi >= backpackCapacity) {
        CCLOG("the posi is unfair!");
        return;
    }
    int num = pack1->posiNumBack(posi);
    Item* item0 = pack1->bottomSelect(posi);

    auto solditem = Sprite::create(item0->filenameReturn());
    if (solditem == nullptr)
        return;
    soldPosi->removeChildByTag(1);
    solditem->setScaleX(tileWidth / 1.3 / (solditem->getContentSize().width));
    solditem->setScaleY(tileHeight / 1.3 / (solditem->getContentSize().height));
    solditem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
    soldPosi->addChild(solditem, 1, 1);
    pack1->itemReduce(pack1->bottomSelect(posi), num);
    Inventory[posi]->removeChildByTag(1);
    auto newitem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
    if (newitem == nullptr)
        return;
    newitem->setScaleX(tileWidth / (newitem->getContentSize().width));
    newitem->setScaleY(tileHeight / (newitem->getContentSize().height));

    //ͼƬ        
    newitem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
    Inventory[posi]->addChild(newitem, 1, 1);
    if (posi < backpackCapacity / 3 && posi >= 0) {

        ventory[posi]->removeChildByTag(1);
        auto sinitem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
        sinitem->setScaleX(tileWidth / (sinitem->getContentSize().width));
        sinitem->setScaleY(tileHeight / (sinitem->getContentSize().height));
        sinitem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
        ventory[posi]->addChild(sinitem, 1, 1);
    }
    soldbox->singleDayInput(item0, num);


}

//        
void soldposiSet() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    soldPosi->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
            {
                if (soldbox->isBoxEmpty() == 0) {
                    CCLOG("box is already empty!");
                    return;
                }
                else {
                    pack1->itemAdd(soldbox->topItemOut(), soldbox->topNumOut());
                    soldbox->itemSingleOut();

                    if (soldbox->isBoxEmpty() == 0)
                    {
                        auto newItem = Sprite::create("null.png");
                        soldPosi->removeChildByTag(1);
                        soldPosi->addChild(newItem, 1, 1);
                        if (newItem == nullptr)
                            return;
                        newItem->setScaleX(tileWidth / 1.3 / (newItem->getContentSize().width));
                        newItem->setScaleY(tileHeight / 1.3 / (newItem->getContentSize().height));
                        newItem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
                    }
                    else {
                        auto newItem = Sprite::create(soldbox->topItemOut()->filenameReturn());
                        soldPosi->removeChildByTag(1);
                        soldPosi->addChild(newItem, 1, 1);
                        if (newItem == nullptr)
                            return;
                        newItem->setScaleX(1 / 1.3);
                        newItem->setScaleY(1 / 1.3);
                        newItem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
                    }

                }
            }
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }


        }
    );
}

//             
void substitute(Widget::TouchEventType type, int posi) {
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (solditemchosen == 1) {
                if (pack1->posiNumBack(posi) != 0)
                {
                    if (pack1->bottomSelect(posi)->isSoldAble())
                        soldPerform(posi);

                }
            }
            else {
                if (isSelected == 0)
                {
                    isSelected = 1;
                    Inventory[posi]->removeChildByTag(1);
                    ventory[posi]->removeChildByTag(1);
                    auto exchangeItem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (exchangeItem == nullptr)
                        return;
                    exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                    exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                    exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                    pack1->itemPositionChangeOn(1, posi);
                    auto newph1 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (newph1 == nullptr)
                        return;
                    auto newph2 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (newph2 == nullptr)
                        return;
                    Inventory[posi]->addChild(newph1, 1, 1);
                    ventory[posi]->addChild(newph2, 1, 1);
                    displayItem->removeChildByTag(1);

                    displayItem->addChild(exchangeItem, 1, 1);
                }
                else {

                    Inventory[posi]->removeChildByTag(1);
                    ventory[posi]->removeChildByTag(1);
                    auto exchangeItem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (exchangeItem == nullptr)
                        return;
                    exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                    exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                    exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                    pack1->itemPositionChangeOff(posi);

                    auto newph1 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    newph1->setScaleX(Inventory[posi]->getContentSize().width / 1.3 / (newph1->getContentSize().width));
                    newph1->setScaleY(Inventory[posi]->getContentSize().width / 1.3 / (newph1->getContentSize().height));
                    if (newph1 == nullptr)
                        return;
                    //ͼƬ        
                    newph1->setPosition(Vec2(Inventory[posi]->getContentSize().width / 2, Inventory[posi]->getContentSize().width / 2));

                    auto newph2 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (newph2 == nullptr)
                        return;
                    newph2->setScaleX(Inventory[posi]->getContentSize().width / 1.3 / (newph2->getContentSize().width));
                    newph2->setScaleY(Inventory[posi]->getContentSize().width / 1.3 / (newph2->getContentSize().height));

                    //ͼƬ        
                    newph2->setPosition(Vec2(Inventory[posi]->getContentSize().width / 2, Inventory[posi]->getContentSize().width / 2));
                    Inventory[posi]->addChild(newph1, 1, 1);
                    ventory[posi]->addChild(newph2, 1, 1);
                    numlabel2(posi);
                    displayItem->removeChildByTag(1);
                    displayItem->addChild(exchangeItem, 1, 1);
                }
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
    }
}

void substitute2(Widget::TouchEventType type, int posi) {
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (solditemchosen == 1) {
                if (pack1->posiNumBack(posi) != 0)
                {
                    if (pack1->bottomSelect(posi)->isSoldAble())
                        soldPerform(posi);

                }
            }
            else {
                if (isSelected == 0)
                {
                    isSelected = 1;
                    Inventory[posi]->removeChildByTag(1);
                    auto exchangeItem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (exchangeItem == nullptr)
                        return;
                    exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                    exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                    exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                    pack1->itemPositionChangeOn(1, posi);
                    auto newph1 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (newph1 == nullptr)
                        return;
                    Inventory[posi]->addChild(newph1, 1, 1);
                    displayItem->removeChildByTag(1);

                    displayItem->addChild(exchangeItem, 1, 1);
                }
                else {

                    Inventory[posi]->removeChildByTag(1);
                    ventory[posi]->removeChildByTag(1);
                    auto exchangeItem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    if (exchangeItem == nullptr)
                        return;
                    exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                    exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                    exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                    pack1->itemPositionChangeOff(posi);

                    auto newph1 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                    newph1->setScaleX(Inventory[posi]->getContentSize().width / 1.3 / (newph1->getContentSize().width));
                    newph1->setScaleY(Inventory[posi]->getContentSize().width / 1.3 / (newph1->getContentSize().height));
                    if (newph1 == nullptr)
                        return;
                    //ͼƬ        
                    newph1->setPosition(Vec2(Inventory[posi]->getContentSize().width / 2, Inventory[posi]->getContentSize().width / 2));
                    Inventory[posi]->addChild(newph1, 1, 1);
                    numlabel2(posi);
                    displayItem->removeChildByTag(1);
                    displayItem->addChild(exchangeItem, 1, 1);
                }
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
    }
}

//          ʵ  
void listenSet() {

    Inventory[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 0);
        });

    Inventory[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 1);
        });

    Inventory[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 2);
        });

    Inventory[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 3);
        });

    Inventory[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 4);
        });

    Inventory[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 5);
        });

    Inventory[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 6);
        });

    Inventory[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 7);
        });

    Inventory[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 8);
        });

    Inventory[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 9);
        });

    Inventory[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 10);
        });

    Inventory[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute(type, 11); });

}

//          ʵ  
void listenSet2() {
    for (int i = 0; i < backpackCapacity / 3; i++) {
        if (Inventory[i + backpackCapacity / 3] == nullptr)
            return;
    }
    Inventory[0 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 0 + backpackCapacity / 3);
        });

    Inventory[1 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 1 + backpackCapacity / 3);
        });

    Inventory[2 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 2 + backpackCapacity / 3);
        });

    Inventory[3 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 3 + backpackCapacity / 3);
        });

    Inventory[4 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 4 + backpackCapacity / 3);
        });

    Inventory[5 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 5 + backpackCapacity / 3);
        });

    Inventory[6 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 6 + backpackCapacity / 3);
        });

    Inventory[7 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 7 + backpackCapacity / 3);
        });

    Inventory[8 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 8 + backpackCapacity / 3);
        });

    Inventory[9 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 9 + backpackCapacity / 3);
        });

    Inventory[10 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 10 + backpackCapacity / 3);
        });

    Inventory[11 + backpackCapacity / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 11 + backpackCapacity / 3); });

}

//          ʵ  
void listenSet3() {

    Inventory[0 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 0 + backpackCapacity * 2 / 3);
        });

    Inventory[1 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 1 + backpackCapacity * 2 / 3);
        });

    Inventory[2 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 2 + backpackCapacity * 2 / 3);
        });

    Inventory[3 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 3 + backpackCapacity * 2 / 3);
        });

    Inventory[4 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 4 + backpackCapacity * 2 / 3);
        });

    Inventory[5 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 5 + backpackCapacity * 2 / 3);
        });

    Inventory[6 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 6 + backpackCapacity * 2 / 3);
        });

    Inventory[7 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 7 + backpackCapacity * 2 / 3);
        });

    Inventory[8 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 8 + backpackCapacity * 2 / 3);
        });

    Inventory[9 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 9 + backpackCapacity * 2 / 3);
        });

    Inventory[10 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 10 + backpackCapacity * 2 / 3);
        });

    Inventory[11 + backpackCapacity * 2 / 3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        substitute2(type, 11 + backpackCapacity * 2 / 3);
        });

}

// ı䱳     λ  
void setScroVisi(bool Set) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    if (Set == 0) {
        packLayer->setPosition(Vec2(visibleSize.width / 3, visibleSize.height / 2));
        packLayer->setVisible(Set);

    }
    else {
        packLayer->setVisible(Set);
        packLayer->setPosition(scrollview->getPositionX() + 3 * tileWidth, scrollview->getPositionY() - scrollview->getContentSize().height / 2);
    }
}

void setCraftVisi(bool Set) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    if (Set == 0) {
        packLayer->setPosition(Vec2(visibleSize.width / 3, visibleSize.height / 2));
        packLayer->setVisible(Set);

    }
    else {
        packLayer->setVisible(Set);
        packLayer->setPosition(Craftview->getPositionX() + 3 * tileWidth, Craftview->getPositionY() - Craftview->getContentSize().height / 2);
    }
}

void numberSet(int posi) {
    ventory[posi]->setSelected(1);
    for (int i = 0; i < backpackCapacity / 3; i++) {
        if (i != posi)
            ventory[i]->setSelected(0);
    }

}

void sethand(int posi) {
    pack1->sethandInItemOut(posi);
}

void initia(Scene* scene);

//         趨
void backPhoto(Scene* scene, backPack* pack1, EventDispatcher* _eventDispatcher) {


    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto keyListener = EventListenerKeyboard::create();

    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;

    for (int i = 0; i < backpackCapacity / 3; i++) {
        Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");

        Inventory[i]->setScaleX(tileWidth / Inventory[i]->getContentSize().width);
        Inventory[i]->setScaleY(tileHeight / Inventory[i]->getContentSize().height);
        Inventory[i]->setPosition(Vec2(origin.x + tileWidth * (9 + i) - Inventory[i]->getContentSize().width / 2, origin.y + tileHeight * 13 + Inventory[i]->getContentSize().height / 2));
        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());



        //  Ʒ      Ʒ ߴ     
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //ͼƬ        
        packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));

        Inventory[i]->addChild(packItem, 1, 1);
    }

    for (int i = 12; i < 36; i++) {
        Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");
    }

    initia(scene);

    keyListener->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
        {
            switch (code)
            {
                case EventKeyboard::KeyCode::KEY_B:

                {
                    if (backIsOpen == BackOpen1) {

                        backIsOpen = BackOpen2;
                        {

                            scene->getChildByTag(30)->setVisible(1);

                            for (int i = 0; i < backpackCapacity / 3; i++) {
                                scene->getChildByTag(invventoryTag + i)->setVisible(0);
                            }
                        }
                    }
                    else {
                        backIsOpen = 0;
                        pack1->itemChangeReset();
                        isSelected = 0;
                        scene->getChildByTag(30)->setVisible(0);

                        for (int i = 0; i < backpackCapacity / 3; i++) {
                            scene->getChildByTag(100 + i)->setVisible(1);
                        }
                    }
                    break;
                }
                case EventKeyboard::KeyCode::KEY_S: {
                    Timer1* time1 = new Timer1();
                    if (storeItem->seasonOut() == time1->getSeason())
                        ;
                    else
                        storeItem->seasonEx(time1->getSeason());
                    if (storeIsStart == 0) {
                        storeIsStart = 1;
                        storeIsOpen = 1;

                        storePhoto(scene);
                    }
                    else {
                        if (storeIsOpen == 1) {
                            storeIsOpen = 0;
                            scrollview->setVisible(0);
                            setScroVisi(0);
                            scene->getChildByTag(60)->setVisible(0);
                            scene->getChildByTag(61)->setVisible(0);
                        }
                        else {
                            storeIsOpen = 1;
                            scrollview->setVisible(1);
                            setScroVisi(1);
                            scene->getChildByTag(60)->setVisible(1);
                            scene->getChildByTag(61)->setVisible(1);
                        }
                    }
                    break;
                }
                case EventKeyboard::KeyCode::KEY_T: {
                    if (solditemchosen == 0) {
                        if (soldPosi == nullptr)
                            ;
                        else
                            soldPosi->removeChildByTag(1);

                        for (int i = 0; i < backpackCapacity / 3; i++)
                        {
                            if (!pack1->bottomSelect(i)->isSoldAble())
                                Inventory[i]->getChildByTag(1)->setOpacity(100);
                        }
                        solditemchosen = 1;
                        soldBox(scene);
                        break;
                    }
                    else {
                        for (int i = 0; i < backpackCapacity / 3; i++)
                        {
                            if (!pack1->bottomSelect(i)->isSoldAble())
                                Inventory[i]->getChildByTag(1)->setOpacity(255);
                        }
                        solditemchosen = 0;
                        soldPosi->setVisible(0);
                        packLayer->setPosition(Vec2(visibleSize.width / 3, visibleSize.height / 2));
                        packLayer->setVisible(0);

                        pack1->moneyChange(soldbox->dayProfitOut(), 0);
                        if (moneyboard->getChildByTag(1) == nullptr)
                            ;
                        else
                            moneyboard->removeChildByTag(1);
                        Label* money = Label::create(pack1->moneyStringOut(), "Comic Sans MS.ttf", 40);
                        money->setColor(Color3B::BLACK);
                        money->setPosition(Vec2(moneyboard->getContentSize().width * 7 / 8 - money->getContentSize().width / 2, money->getContentSize().height / 2));
                        moneyboard->addChild(money, 1, 1);
                    }
                    break;
                }
                case EventKeyboard::KeyCode::KEY_M: {
                    if (craftIsStart == 0) {
                        craftIsStart = 1;
                        craftIsOpen = 1;

                        craftPhoto(scene);
                    }
                    else {
                        if (craftIsOpen == 1) {
                            craftIsOpen = 0;
                            Craftview->setVisible(0);
                            setCraftVisi(0);
                            scene->getChildByTag(70)->setVisible(0);
                            scene->getChildByTag(71)->setVisible(0);
                        }
                        else {
                            craftIsOpen = 1;
                            Craftview->setVisible(1);
                            setCraftVisi(1);
                            scene->getChildByTag(70)->setVisible(1);
                            scene->getChildByTag(71)->setVisible(1);
                        }
                    }
                    break;
                }
                case EventKeyboard::KeyCode::KEY_1: {
                    numberSet(0);
                    sethand(0);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_2: {
                    numberSet(1);
                    sethand(1);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_3: {
                    numberSet(2);
                    sethand(2);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_4: {
                    numberSet(3);
                    sethand(3);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_5: {
                    numberSet(4);
                    sethand(4);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_6: {
                    numberSet(5);
                    sethand(5);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_7: {
                    numberSet(6);
                    sethand(6);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_8: {
                    numberSet(7);
                    sethand(7);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_9: {
                    numberSet(8);
                    sethand(8);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_0: {
                    numberSet(9);
                    sethand(9);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_MINUS: {
                    numberSet(10);
                    sethand(10);
                    break;
                }
                case EventKeyboard::KeyCode::KEY_EQUAL: {
                    numberSet(11);
                    sethand(11);
                    break;
                }
                default:
                    break;
            }
        });

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, scene);

}

//  ѡ  ť    
auto ItemBot = RadioButtonGroup::create();

void ventoryFor(Widget::TouchEventType type, int posi)
{
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
            pack1->sethandInItemOut(posi);
            break;
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
    }
}
//  Ʒ         

//  Ʒ       趨
void ventorySet() {
    ventory[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 0);
        numberSet(0);
        });

    ventory[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 1);
        numberSet(1);
        });

    ventory[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 2);
        numberSet(2);
        });

    ventory[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 3);
        numberSet(3);
        });

    ventory[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 4);
        numberSet(4);
        });

    ventory[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 5);
        numberSet(5);
        });

    ventory[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 6);
        numberSet(6);
        });

    ventory[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 7);
        numberSet(7);
        });

    ventory[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 8);
        numberSet(8);
        });

    ventory[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 9);
        numberSet(9);
        });

    ventory[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 10);
        numberSet(10);
        });

    ventory[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 11);
        numberSet(11);
        });
}

//  Ʒ    ʾ
void inventory(Scene* scene, backPack* pack1, Vec2 origin) {
    ItemBot = RadioButtonGroup::create();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;  // ÿ     صĿ  
    float tileHeight = tileWidth; // ÿ     صĸ߶ 
    for (int i = 0; i < backpackCapacity / 3; i++) {
        ventory[i] = RadioButton::create("Inventory.png", "Inventory chosen.png");


        ventory[i]->setScaleX(tileWidth / ventory[i]->getContentSize().width);
        ventory[i]->setScaleY(tileHeight / ventory[i]->getContentSize().height);
        ventory[i]->setPosition(Vec2(origin.x + tileWidth * (9 + i) - ventory[i]->getContentSize().width / 2, origin.y + tileHeight / 5 + ventory[i]->getContentSize().height / 2));

        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

        //  Ʒ      Ʒ ߴ     
        packItem->setScaleX(tileWidth / 1.3 / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / 1.3 / (packItem->getContentSize().height));

        //ͼƬ        
        packItem->setPosition(Vec2(ventory[i]->getContentSize().width / 2, ventory[i]->getContentSize().width / 2));
        ventory[i]->addChild(packItem, 1, 1);
        ItemBot->addRadioButton(ventory[i]);
        scene->addChild(ventory[i], invventoryTag, invventoryTag + i);

    }
    moneyboard = Sprite::create("moneyBoard.png");
    moneyboard->setScaleX((tileWidth * 6) / (moneyboard->getContentSize().width));
    moneyboard->setScaleY(tileHeight * 4 / (3 * moneyboard->getContentSize().height));
    moneyboard->setPosition(Vec2(origin.x + tileWidth * 28 - moneyboard->getContentSize().width / 2, origin.y + tileHeight * 15 + moneyboard->getContentSize().height / 2));

    Label* money = Label::create(pack1->moneyStringOut(), "Comic Sans MS.ttf", 40);
    money->setColor(Color3B::BLACK);
    money->setPosition(Vec2(moneyboard->getContentSize().width * 7 / 8 - money->getContentSize().width / 2, money->getContentSize().height / 2));
    scene->addChild(moneyboard, invventoryTag, 81);
    moneyboard->addChild(money, 1, 1);
    scene->addChild(ItemBot);
    ventorySet();

}

//      ʼ  
void initia(Scene* scene) {
    packLayer = Layer::create();
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto group2 = RadioButtonGroup::create();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    backIsProed = BackPro2;

    for (int i = 0; i < backpackCapacity / 3; i++) {
        Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");
        packLayer->addChild(Inventory[i]);
        Inventory[i]->setScaleX(tileWidth / Inventory[i]->getContentSize().width);
        Inventory[i]->setScaleY(tileHeight / Inventory[i]->getContentSize().height);
        Inventory[i]->setPosition(Vec2(tileWidth * (i)-Inventory[i]->getContentSize().width / 2, tileHeight * 2 + Inventory[i]->getContentSize().height / 2));
        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());



        //  Ʒ      Ʒ ߴ     
        packItem->setScaleX(tileWidth / 1.3 / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / 1.3 / (packItem->getContentSize().height));

        //ͼƬ        
        packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));
        Inventory[i]->addChild(packItem, 1, 1);
        group2->addRadioButton(Inventory[i]);



    }

    listenSet();
    for (int i = backpackCapacity / 3; i < backpackCapacity * 2 / 3; i++) {
        Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");
        packLayer->addChild(Inventory[i]);
        Inventory[i]->setScaleX(tileWidth / Inventory[i]->getContentSize().width);
        Inventory[i]->setScaleY(tileHeight / Inventory[i]->getContentSize().height);
        Inventory[i]->setPosition(Vec2(tileWidth * ((i + 1) % (backpackCapacity / 3)) - Inventory[i]->getContentSize().width / 2, tileHeight + Inventory[i]->getContentSize().height / 2));
        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

        //  Ʒ      Ʒ ߴ     
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //ͼƬ        
        packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));

        Inventory[i]->addChild(packItem);
        group2->addRadioButton(Inventory[i]);
    }

    for (int i = backpackCapacity * 2 / 3; i < backpackCapacity; i++) {
        Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");
        Inventory[i]->setScaleX(tileWidth / Inventory[i]->getContentSize().width);
        Inventory[i]->setScaleY(tileHeight / Inventory[i]->getContentSize().height);
        Inventory[i]->setPosition(Vec2(tileWidth * ((i + 1) % (backpackCapacity / 3)) - Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().height / 2));
        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

        //  Ʒ      Ʒ ߴ     
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //ͼƬ        
        packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));

        Inventory[i]->addChild(packItem);
        group2->addRadioButton(Inventory[i]);
        packLayer->addChild(Inventory[i]);
    }

    displayItem = Sprite::create("Inventory.png");
    packLayer->addChild(displayItem);
    displayItem->setScaleX(tileWidth / displayItem->getContentSize().width);
    displayItem->setScaleY(tileHeight / displayItem->getContentSize().height);
    displayItem->setPosition(Vec2(tileWidth * (1 + backpackCapacity / 3) - Inventory[1]->getContentSize().width / 2, tileHeight * 2 + Inventory[1]->getContentSize().height / 2));

    auto addItem = Sprite::create("null.png");
    addItem->setScaleX(tileWidth / (addItem->getContentSize().width));
    addItem->setScaleY(tileHeight / (addItem->getContentSize().height));
    addItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));

    displayItem->addChild(addItem, 1, 1);


    scene->addChild(group2);
    packLayer->setPosition(Vec2(visibleSize.width / 3, visibleSize.height / 2));
    scene->addChild(packLayer, 50, 30);
    packLayer->setVisible(0);
}

//      Ʒ    
void backItemAddDisplay(int no) {
    if (no < 0 || no >= backpackCapacity) {
        return;
    }
    else {
        Inventory[no]->removeChildByTag(1);
        ventory[no]->removeChildByTag(1);

        auto newph1 = Sprite::create(pack1->bottomSelect(no)->filenameReturn());
        if (newph1 == nullptr)
            return;
        newph1->setScaleX(Inventory[no]->getContentSize().width / 1.3 / (newph1->getContentSize().width));
        newph1->setScaleY(Inventory[no]->getContentSize().width / 1.3 / (newph1->getContentSize().height));
        //ͼƬ        
        newph1->setPosition(Vec2(Inventory[no]->getContentSize().width / 2, Inventory[no]->getContentSize().width / 2));

        auto newph2 = Sprite::create(pack1->bottomSelect(no)->filenameReturn());
        if (newph2 == nullptr)
            return;
        newph2->setScaleX(ventory[no]->getContentSize().width / 1.3 / (newph2->getContentSize().width));
        newph2->setScaleY(ventory[no]->getContentSize().width / 1.3 / (newph2->getContentSize().height));
        //ͼƬ        
        newph2->setPosition(Vec2(ventory[no]->getContentSize().width / 2, ventory[no]->getContentSize().width / 2));
        Inventory[no]->addChild(newph1, 1, 1);
        ventory[no]->addChild(newph2, 1, 1);

    }
}

//  ͷ        
void arrowSet();

void arrow1Set();

// ̵깦      
void storeSoldSet(Scene* scene);

void storeSoldSet1(Scene* scene);

RadioButton* commodity[30];

RadioButton* Craft[18];

RadioButton* arrowBottom;

RadioButton* arrowTop;

RadioButton* arrowBottom1;

RadioButton* arrowTop1;

// ̵        
void storePhoto(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;

    scrollview = ScrollView::create();

    scrollview->setContentSize(Size(750, 300));
    scrollview->setInnerContainerSize(Size(750, 2250));
    scrollview->setPosition(Vec2(visibleSize.width / 3, visibleSize.height * 1.8 / 3));

    auto layout = Layout::create();
    layout->setContentSize(Size(750, 2250));
    layout->setPosition(Vec2(0, 0));
    for (int i = 0; i < 27; i++) {
        commodity[26 - i] = RadioButton::create("emptyBoard.png", "emptyBoard.png");
        commodity[26 - i]->setScaleX(750 / commodity[26 - i]->getContentSize().width);
        commodity[26 - i]->setScaleY(75 / commodity[26 - i]->getContentSize().height);
        commodity[26 - i]->setPosition(Vec2(layout->getContentSize().width / 2, commodity[26 - i]->getContentSize().height / 4 + 10 + (i + 3) * 75));

        auto goods = Sprite::create(storeItem->itemNameOut(26 - i, 1, 1));
        auto goodsLabel1 = Label::create(storeItem->itemNameOut(26 - i, 1, 0), "Comic Sans MS.ttf", 50);
        auto moneyLabel = Label::create(storeItem->itemMoneyOut(26 - i, 1), "Comic Sans MS.ttf", 50);
        if (moneyLabel == nullptr)
            continue;
        if (goodsLabel1 == nullptr)
            continue;
        goodsLabel1->setColor(Color3B::BLACK);
        moneyLabel->setColor(Color3B::BLACK);
        if (goods == nullptr)
            continue;
        commodity[26 - i]->addChild(goods, 1, 1);
        commodity[26 - i]->addChild(goodsLabel1, 1, 2);
        commodity[26 - i]->addChild(moneyLabel, 1, 3);
        goods->setPosition(Vec2(commodity[26 - i]->getContentSize().width / 20, commodity[26 - i]->getContentSize().height / 2));
        goodsLabel1->setPosition(Vec2(commodity[26 - i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[26 - i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
        moneyLabel->setPosition(Vec2(commodity[26 - i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[26 - i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        layout->addChild(commodity[26 - i]);

    }
    for (int i = 27; i < 30; i++) {
        commodity[i] = RadioButton::create("emptyBoard.png", "emptyBoard.png");
        commodity[i]->setScaleX(750 / commodity[i]->getContentSize().width);
        commodity[i]->setScaleY(75 / commodity[i]->getContentSize().height);
        commodity[i]->setPosition(Vec2(layout->getContentSize().width / 2, commodity[i]->getContentSize().height / 4 + 10 + (i - 27) * 75));
        layout->addChild(commodity[i]);
    }
    arrowBottom = RadioButton::create("arrow1.png", "arrow1.png");
    arrowTop = RadioButton::create("arrow2.png", "arrow2.png");
    scene->addChild(arrowBottom, 150, 60);
    scene->addChild(arrowTop, 150, 61);
    arrowBottom->setPosition(Vec2(scrollview->getPositionX() + scrollview->getContentSize().width + arrowBottom->getContentSize().width / 2, scrollview->getPositionY()));
    arrowTop->setPosition(Vec2(scrollview->getPositionX() + scrollview->getContentSize().width + arrowBottom->getContentSize().width / 2, scrollview->getPositionY() + scrollview->getContentSize().height));
    layout->setVisible(1);
    scrollview->getInnerContainer()->addChild(layout);
    scrollview->setScrollBarEnabled(1);
    scrollview->setDirection(ScrollView::Direction::VERTICAL);
    scrollview->setScrollBarPositionFromCornerForVertical(Vec2(scrollview->getPositionX() + scrollview->getContentSize().width / 2, scrollview->getPositionY() + scrollview->getContentSize().height / 2));

    scene->addChild(scrollview, 150);
    arrowSet();
    storeSoldSet(scene);
    packLayer->setPosition(scrollview->getPositionX() + 3 * tileWidth, scrollview->getPositionY() - scrollview->getContentSize().height / 2);
    packLayer->setVisible(1);
}

void craftPhoto(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;

    Craftview = ScrollView::create();

    Craftview->setContentSize(Size(750, 300));
    Craftview->setInnerContainerSize(Size(750, 1350));
    Craftview->setPosition(Vec2(visibleSize.width / 3, visibleSize.height * 1.8 / 3));

    auto layout = Layout::create();
    layout->setContentSize(Size(750, 1350));
    layout->setPosition(Vec2(0, 0));
    for (int i = 0; i < 18; i++) {
        Craft[17 - i] = RadioButton::create("emptyBoard.png", "emptyBoard.png");
        Craft[17 - i]->setScaleX(750 / Craft[17 - i]->getContentSize().width);
        Craft[17 - i]->setScaleY(75 / Craft[17 - i]->getContentSize().height);
        Craft[17 - i]->setPosition(Vec2(layout->getContentSize().width / 2, Craft[17 - i]->getContentSize().height / 4 + 10 + (i) * 75));

        auto goods = Sprite::create(craftItem->getItem(17 - i)->filenameReturn());
        auto goodsLabel1 = Label::create(craftItem->getItem(17 - i)->name, "Comic Sans MS.ttf", 50);
        auto factorLabel = Label::create(craftItem->factorBack(17 - i), "Comic Sans MS.ttf", 50);
        if (factorLabel == nullptr)
            continue;
        if (goodsLabel1 == nullptr)
            continue;
        goodsLabel1->setColor(Color3B::BLACK);
        factorLabel->setColor(Color3B::BLACK);
        if (goods == nullptr)
            continue;
        Craft[17 - i]->addChild(goods, 1, 1);
        Craft[17 - i]->addChild(goodsLabel1, 1, 2);
        Craft[17 - i]->addChild(factorLabel, 1, 3);
        goods->setPosition(Vec2(Craft[17 - i]->getContentSize().width / 20, Craft[17 - i]->getContentSize().height / 2));
        goodsLabel1->setPosition(Vec2(Craft[17 - i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, Craft[17 - i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
        factorLabel->setPosition(Vec2(Craft[17 - i]->getContentSize().width * 18.5 / 20 - factorLabel->getContentSize().width / 2, Craft[17 - i]->getContentSize().height / 2 + factorLabel->getContentSize().height / 5));
        layout->addChild(Craft[17 - i]);

    }
    arrowBottom1 = RadioButton::create("arrow1.png", "arrow1.png");
    arrowTop1 = RadioButton::create("arrow2.png", "arrow2.png");
    scene->addChild(arrowBottom1, 160, 70);
    scene->addChild(arrowTop1, 160, 71);
    arrowBottom1->setPosition(Vec2(Craftview->getPositionX() + Craftview->getContentSize().width + arrowBottom1->getContentSize().width / 2, Craftview->getPositionY()));
    arrowTop1->setPosition(Vec2(Craftview->getPositionX() + Craftview->getContentSize().width + arrowBottom1->getContentSize().width / 2, Craftview->getPositionY() + Craftview->getContentSize().height));
    layout->setVisible(1);
    Craftview->getInnerContainer()->addChild(layout);
    Craftview->setScrollBarEnabled(1);
    Craftview->setDirection(ScrollView::Direction::VERTICAL);
    Craftview->setScrollBarPositionFromCornerForVertical(Vec2(Craftview->getPositionX() + Craftview->getContentSize().width / 2, Craftview->getPositionY() + Craftview->getContentSize().height / 2));

    scene->addChild(Craftview, 160);
    arrow1Set();
    storeSoldSet1(scene);
    packLayer->setPosition(Craftview->getPositionX() + 3 * tileWidth, Craftview->getPositionY() - Craftview->getContentSize().height / 2);
    packLayer->setVisible(1);
}

float moveMacket = 0.0;

//  ͷ    
void arrowSet() {
    arrowBottom->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        float alltime = 2600.0f;
        float block;
        if (storeItem->seasonOut() == "Spring")
            block = 2300.0f;
        else
            block = 2600.0f;
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                if (moveMacket < block) {
                    moveMacket += 100;
                    scrollview->scrollToPercentVertical(moveMacket * 100.0 / alltime, 0.1, 0);
                }
                else {
                    CCLOG("Already to the Bottom");
                }
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
        });
    arrowTop->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        float alltime = 2600.0f;
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                if (moveMacket >= 100.0) {
                    moveMacket -= 100;
                    scrollview->scrollToPercentVertical(moveMacket * 100.0 / alltime, 0.1, 0);
                }
                else {
                    CCLOG("Already to the Top");
                }
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
        });
}

float moveMacket1 = 0.0;

void arrow1Set() {
    arrowBottom1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        float alltime = 1400.0f;
        float block = 1400.0f;
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                if (moveMacket1 < block) {
                    moveMacket1 += 100;
                    Craftview->scrollToPercentVertical(moveMacket1 * 100.0 / alltime, 0.1, 0);
                }
                else {
                    CCLOG("Already to the Bottom");
                }
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
        });
    arrowTop1->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        float alltime = 1400.0f;
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                if (moveMacket1 >= 100.0) {
                    moveMacket1 -= 100;
                    Craftview->scrollToPercentVertical(moveMacket1 * 100.0 / alltime, 0.1, 0);
                }
                else {
                    CCLOG("Already to the Top");
                }
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
        });
}

//  Ʒ     
void storeSoldFor(Widget::TouchEventType type, int posi, Scene* scene) {
    int seasonNum = 0;
    if (storeItem->seasonOut() == "Spring")
        seasonNum = 1;
    else {
        if (storeItem->seasonOut() == "Summer")
            seasonNum = 2;
        else {
            if (storeItem->seasonOut() == "Fall")
                seasonNum = 3;
            else
                seasonNum = 4;
        }
    }
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN: {
            Item* newitem;
            if (storeItem->isAffordable(pack1, posi, seasonNum)) {
                if (seasonNum == 1) {
                    if ((posi >= 0 && posi <= 9) || (posi >= 20 && posi <= 25))
                        newitem = Seed::create(storeItem->itemNameOut(posi, seasonNum, 0));
                    else
                        newitem = Tool::create(storeItem->itemNameOut(posi, seasonNum, 0));
                }
                else {
                    if ((posi >= 0 && posi <= 12) || (posi >= 23 && posi <= 28))
                        newitem = Seed::create(storeItem->itemNameOut(posi, seasonNum, 0));
                    else
                        newitem = Tool::create(storeItem->itemNameOut(posi, seasonNum, 0));
                }
                moneyChange(storeItem->itemMoneyBack(posi, seasonNum), 1);
                pack1->itemAdd(newitem, 1);
                break;
            }
            else
                break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
    }
}

void CraftFor(Widget::TouchEventType type, int posi, Scene* scene) {
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN: {
            if (craftItem->changeForCraft(pack1, posi)) {
                craftItem->itemDelete(pack1, posi);
                pack1->itemAdd(craftItem->getItem(posi), 1);
            }
            else {
                CCLOG("not able to craft");
            }
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
    }
}



// ̵   Ʒ      
void storeSoldSet(Scene* scene) {
    commodity[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 0, scene);
        });
    commodity[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 1, scene);
        });
    commodity[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 2, scene);
        });
    commodity[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 3, scene);
        });
    commodity[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 4, scene);
        });
    commodity[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 5, scene);
        });
    commodity[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 6, scene);
        });
    commodity[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 7, scene);
        });
    commodity[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 8, scene);
        });
    commodity[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 9, scene);
        });
    commodity[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 10, scene);
        });
    commodity[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 11, scene);
        });
    commodity[12]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 12, scene);
        });
    commodity[13]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 13, scene);
        });
    commodity[14]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 14, scene);
        });
    commodity[15]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 1, scene);
        });
    commodity[16]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 16, scene);
        });
    commodity[17]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 17, scene);
        });
    commodity[18]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 18, scene);
        });
    commodity[19]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 19, scene);
        });
    commodity[20]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 20, scene);
        });
    commodity[21]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 21, scene);
        });
    commodity[22]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 22, scene);
        });
    commodity[23]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 23, scene);
        });
    commodity[24]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 24, scene);
        });
    commodity[25]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 25, scene);
        });
    commodity[26]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 26, scene);
        });

}

void storeSoldSet1(Scene* scene) {
    Craft[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 0, scene);
        });
    Craft[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 1, scene);
        });
    Craft[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 2, scene);
        });
    Craft[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 3, scene);
        });
    Craft[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 4, scene);
        });
    Craft[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 5, scene);
        });
    Craft[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 6, scene);
        });
    Craft[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 7, scene);
        });
    Craft[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 8, scene);
        });
    Craft[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 9, scene);
        });
    Craft[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 10, scene);
        });
    Craft[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 11, scene);
        });
    Craft[12]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 12, scene);
        });
    Craft[13]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 13, scene);
        });
    Craft[14]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 14, scene);
        });
    Craft[15]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 1, scene);
        });
    Craft[16]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 16, scene);
        });
    Craft[17]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        CraftFor(type, 17, scene);
        });
}

//1--    0--  
void moneyChange(int amount, bool way) {
    pack1->moneyChange(amount, way);
    moneyboard->removeChildByTag(1);
    Label* money = Label::create(pack1->moneyStringOut(), "Comic Sans MS.ttf", 40);
    if (money == nullptr)
        return;
    money->setColor(Color3B::BLACK);
    money->setPosition(Vec2(moneyboard->getContentSize().width * 7 / 8 - money->getContentSize().width / 2, money->getContentSize().height / 2));
    moneyboard->addChild(money, 1, 1);
}
//        ʾ
void soldBox(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    packLayer->setPosition(visibleSize.width / 3, visibleSize.height / 3);
    packLayer->setVisible(1);
    soldPosi = RadioButton::create("Inventory.png", "Inventory.png");
    if (soldPosi == nullptr)
        return;
    soldPosi->setScaleX(tileWidth / soldPosi->getContentSize().width);
    soldPosi->setScaleY(tileHeight / soldPosi->getContentSize().height);
    soldPosi->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 3 + 4 * tileHeight));

    auto item0 = Sprite::create("null.png");
    if (item0 == nullptr)
        return;
    soldPosi->addChild(item0, 1, 1);
    item0->setScaleX(tileWidth / (item0->getContentSize().width));
    item0->setScaleY(tileHeight / (item0->getContentSize().height));

    //ͼƬ        
    item0->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));

    scene->addChild(soldPosi, 10, 62);
    soldposiSet();

}

void numlabel(int posi) {
    auto number = Sprite::create("null.png");
    if (number == nullptr)
        return;
    Inventory[posi]->getChildByTag(1)->addChild(number, 1, 2);

}

void numlabel2(int posi) {
    if (pack1->posiNumBack(posi) >= 1) {
        Inventory[posi]->getChildByTag(1)->removeChildByTag(2);
        if (pack1->posiNumBack(posi) > 1) {
            auto number = Label::create(pack1->numStringOut(posi), "Comic Sans MS.ttf", 20);
            if (number == nullptr)
                return;
            Inventory[posi]->getChildByTag(1)->addChild(number, 1, 2);
            number->setColor(Color3B::BLACK);

            number->setPosition(Vec2(Inventory[posi]->getContentSize().width * 0.8 + number->getContentSize().width / 2, number->getContentSize().height / 5));
        }
        if (posi >= 0 && posi < backpackCapacity / 3) {
            ventory[posi]->getChildByTag(1)->removeChildByTag(2);
            if (pack1->posiNumBack(posi) > 1) {
                auto number1 = Label::create(pack1->numStringOut(posi), "Comic Sans MS.ttf", 20);
                if (number1 == nullptr)
                    return;
                ventory[posi]->getChildByTag(1)->addChild(number1, 1, 2);
                number1->setColor(Color3B::BLACK);
                number1->setPosition(Vec2(ventory[posi]->getContentSize().width * 0.8 + number1->getContentSize().width / 2, number1->getContentSize().height / 5));
            }
        }
    }
}

void packPosi(int posi) {
    Inventory[posi]->removeChildByTag(1);

    if (posi >= 0 && posi < backpackCapacity / 3) {
        ventory[posi]->removeChildByTag(1);
    }
}

void storeSeasonEx(std::string season) {
    if (season == "Summer") {
        for (int i = 0; i < 27; i++) {
            commodity[i]->removeChildByTag(1);
            commodity[i]->removeChildByTag(2);
            commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(i, 2, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(i, 2, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(i, 2), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
        for (int i = 27; i < 30; i++) {
            commodity[i]->removeChildByTag(1);
            if (commodity[i]->getChildByTag(2) == nullptr)
                ;
            else
                commodity[i]->removeChildByTag(2);
            if (commodity[i]->getChildByTag(3) == nullptr)
                ;
            else
                commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(56 - i, 2, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(56 - i, 2, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(56 - i, 2), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
    }
    if (season == "Fall") {
        for (int i = 0; i < 27; i++) {
            commodity[i]->removeChildByTag(1);
            commodity[i]->removeChildByTag(2);
            commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(i, 2, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(i, 2, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(i, 2), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
        for (int i = 27; i < 30; i++) {
            commodity[i]->removeChildByTag(1);
            commodity[i]->removeChildByTag(2);
            commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(56 - i, 2, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(56 - i, 2, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(56 - i, 2), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
    }
    if (season == "Winter") {
        ;
    }
    if (season == "Spring") {
        for (int i = 0; i < 27; i++) {
            commodity[i]->removeChildByTag(1);
            commodity[i]->removeChildByTag(2);
            commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(i, 1, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(i, 1, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(i, 1), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
        for (int i = 27; i < 30; i++) {
            commodity[i]->removeChildByTag(1);
            if (commodity[i]->getChildByTag(2) == nullptr)
                ;
            else
                commodity[i]->removeChildByTag(2);
            if (commodity[i]->getChildByTag(3) == nullptr)
                ;
            else
                commodity[i]->removeChildByTag(3);
            auto goods = Sprite::create(storeItem->itemNameOut(56 - i, 1, 1));
            auto goodsLabel1 = Label::create(storeItem->itemNameOut(56 - i, 1, 0), "Comic Sans MS.ttf", 50);
            auto moneyLabel = Label::create(storeItem->itemMoneyOut(56 - i, 1), "Comic Sans MS.ttf", 50);
            if (moneyLabel == nullptr)
                continue;
            if (goodsLabel1 == nullptr)
                continue;
            goodsLabel1->setColor(Color3B::BLACK);
            moneyLabel->setColor(Color3B::BLACK);
            if (goods == nullptr)
                continue;
            commodity[i]->addChild(goods, 1, 1);
            commodity[i]->addChild(goodsLabel1, 1, 2);
            commodity[i]->addChild(moneyLabel, 1, 3);
            goods->setPosition(Vec2(commodity[i]->getContentSize().width / 20, commodity[i]->getContentSize().height / 2));
            goodsLabel1->setPosition(Vec2(commodity[i]->getContentSize().width / 10 + goodsLabel1->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
            moneyLabel->setPosition(Vec2(commodity[i]->getContentSize().width * 18.5 / 20 - moneyLabel->getContentSize().width / 2, commodity[i]->getContentSize().height / 2 + moneyLabel->getContentSize().height / 5));
        }
    }
}
