/****************************************************************
 * Project Name: xinglugu-project
 * File Name:backPhoto.cpp
 * File Function: const define
 * Author:Li Siyuan
 * Update Date:12.12
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
USING_NS_CC;
USING_NS_CC::ui;
using namespace Constants;
bool backIsOpen = BackOpen1;
bool backIsProed = BackPro1;

bool storeIsStart = 0;
bool storeIsOpen = 0;

bool solditemchosen = 0;

RadioButton* Inventory[backpackCapacity];

RadioButton* soldPosi;

SoldBox* soldbox = new SoldBox();

RadioButton* ventory[backpackCapacity / 3];


void storePhoto(Scene* scene);

void soldBox(Scene* scene);

Sprite* displayItem;
bool isSelected = 0;

Layer* packLayer;

ScrollView* scrollview;

extern backPack* pack1;

//售卖箱操作
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
    solditem->setScaleX(tileWidth / (solditem->getContentSize().width));
    solditem->setScaleY(tileHeight / (solditem->getContentSize().height));
    solditem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
    pack1->itemReduce(pack1->bottomSelect(posi), num);
    Inventory[posi]->removeChildByTag(1);
    auto newitem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
    if (newitem == nullptr)
        return;
    newitem->setScaleX(tileWidth / (newitem->getContentSize().width));
    newitem->setScaleY(tileHeight / (newitem->getContentSize().height));

    //图片坐标设置
    newitem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
    Inventory[posi]->addChild(newitem, 1, 1);
    if (posi < backpackCapacity / 3&&posi>=0) {
        
        ventory[posi]->removeChildByTag(1);
        auto sinitem = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
        sinitem->setScaleX(tileWidth / (sinitem->getContentSize().width));
        sinitem->setScaleY(tileHeight / (sinitem->getContentSize().height));
        sinitem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
        ventory[posi]->addChild(sinitem, 1, 1);
    }
    soldbox->singleDayInput(item0,num );
    soldPosi->removeChildByTag(1);
    soldPosi->addChild(solditem, 1, 1);
}

//卖格功能设计
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
                pack1->itemAdd(soldbox->itemSingleOut(), soldbox->topNumOut());
                soldPosi->removeChildByTag(1);
                if (soldbox->topItemOut() == nullptr)
                    break;
                auto newItem = Sprite::create(soldbox->topItemOut()->filenameReturn());
                if (newItem == nullptr)
                    return;
                newItem->setScaleX(tileWidth / (newItem->getContentSize().width));
                newItem->setScaleY(tileHeight / (newItem->getContentSize().height));
                newItem->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));
                soldPosi->addChild(newItem, 1, 1);
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

//背包栏功能替代
void substitute(Widget::TouchEventType type,int posi) {
    switch (type)
    {
    case ui::Widget::TouchEventType::BEGAN:
    {
        if (solditemchosen == 1) {
            if (pack1->posiNumBack(posi) != 0)
            {
                if(pack1->bottomSelect(posi)->isSoldAble())
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
                //图片坐标设置
                newph1->setPosition(Vec2(Inventory[posi]->getContentSize().width / 2, Inventory[posi]->getContentSize().width / 2));

                auto newph2 = Sprite::create(pack1->bottomSelect(posi)->filenameReturn());
                if (newph2 == nullptr)
                    return;
                newph2->setScaleX(Inventory[posi]->getContentSize().width / 1.3 / (newph2->getContentSize().width));
                newph2->setScaleY(Inventory[posi]->getContentSize().width / 1.3 / (newph2->getContentSize().height));

                //图片坐标设置
                newph2->setPosition(Vec2(Inventory[posi]->getContentSize().width / 2, Inventory[posi]->getContentSize().width / 2));
                Inventory[posi]->addChild(newph1, 1, 1);
                ventory[posi]->addChild(newph2, 1, 1);
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

//背包栏功能实现
void listenSet(Scene* scene, const cocos2d::Size& visibleSize, float tileHeight, float tileWidth) {

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

//改变背包层的位置
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

//各键功能设定
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



        //物品框内物品尺寸设置
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //图片坐标设置
        packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));

        Inventory[i]->addChild(packItem, 1, 1);
    }

    keyListener->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
        {
            switch (code)
            {
            case EventKeyboard::KeyCode::KEY_B:

            {
                if (backIsOpen == BackOpen1) {

                    backIsOpen = BackOpen2;
                    if (backIsProed == BackPro1) {
                        packLayer = Layer::create();
                        auto group2 = RadioButtonGroup::create();
                        float tileWidth = visibleSize.width / 28;
                        float tileHeight = tileWidth;
                        backIsProed = BackPro2;

                        for (int i = 0; i < backpackCapacity / 3; i++) {
                            Inventory[i] = RadioButton::create("Inventory.png", "Inventory.png");
                            packLayer->addChild(Inventory[i]);
                            Inventory[i]->setScaleX(tileWidth / Inventory[i]->getContentSize().width);
                            Inventory[i]->setScaleY(tileHeight / Inventory[i]->getContentSize().height);
                            Inventory[i]->setPosition(Vec2( tileWidth * (i) - Inventory[i]->getContentSize().width / 2,tileHeight * 2 + Inventory[i]->getContentSize().height / 2));
                            auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());



                            //物品框内物品尺寸设置
                            packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
                            packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

                            //图片坐标设置
                            packItem->setPosition(Vec2(Inventory[i]->getContentSize().width / 2, Inventory[i]->getContentSize().width / 2));

                            Inventory[i]->addChild(packItem, 1, 1);
                            group2->addRadioButton(Inventory[i]);
                            


                        }

                        listenSet(scene, visibleSize, tileHeight, tileWidth);
                        for (int i = backpackCapacity / 3; i < backpackCapacity * 2 / 3; i++) {
                            auto Inventory = RadioButton::create("Inventory.png", "Inventory.png");
                            packLayer->addChild(Inventory);
                            Inventory->setScaleX(tileWidth / Inventory->getContentSize().width);
                            Inventory->setScaleY(tileHeight / Inventory->getContentSize().height);
                            Inventory->setPosition(Vec2(tileWidth * ((i + 1)% (backpackCapacity / 3)) - Inventory->getContentSize().width / 2, tileHeight + Inventory->getContentSize().height / 2));
                            auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

                            //物品框内物品尺寸设置
                            packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
                            packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

                            //图片坐标设置
                            packItem->setPosition(Vec2(Inventory->getContentSize().width / 2, Inventory->getContentSize().width / 2));

                            Inventory->addChild(packItem);
                            group2->addRadioButton(Inventory);
                        }

                        for (int i = backpackCapacity * 2 / 3; i < backpackCapacity; i++) {
                            auto Inventory = RadioButton::create("Inventory.png", "Inventory.png");
                            Inventory->setScaleX(tileWidth / Inventory->getContentSize().width);
                            Inventory->setScaleY(tileHeight / Inventory->getContentSize().height);
                            Inventory->setPosition(Vec2(tileWidth * ((i + 1) % (backpackCapacity / 3)) - Inventory->getContentSize().width / 2, Inventory->getContentSize().height / 2));
                            auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

                            //物品框内物品尺寸设置
                            packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
                            packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

                            //图片坐标设置
                            packItem->setPosition(Vec2(Inventory->getContentSize().width / 2, Inventory->getContentSize().width / 2));

                            Inventory->addChild(packItem);
                            group2->addRadioButton(Inventory);
                            packLayer->addChild(Inventory);
                        }
                        displayItem = Sprite::create("Inventory.png");
                        packLayer->addChild(displayItem);
                        displayItem->setScaleX(tileWidth / displayItem->getContentSize().width);
                        displayItem->setScaleY(tileHeight / displayItem->getContentSize().height);
                        displayItem->setPosition(Vec2(tileWidth* (1+backpackCapacity/3)-Inventory[1]->getContentSize().width / 2, tileHeight*2  + Inventory[1]->getContentSize().height / 2));

                        auto addItem = Sprite::create("null.png");
                        addItem->setScaleX(tileWidth / (addItem->getContentSize().width));
                        addItem->setScaleY(tileHeight / (addItem->getContentSize().height));
                        addItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));

                        displayItem->addChild(addItem, 1, 1);
                        

                        scene->addChild(group2);
                        packLayer->setPosition(Vec2(visibleSize.width/3,visibleSize.height/2));
                        scene->addChild(packLayer,50,30);
                        for (int i = 0; i < 12; i++) {
                            scene->getChildByTag(100 + i)->setVisible(0);
                        }
                    }
                    else {

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
                }
            }
            default:
                break;
            }
        });
        
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, scene);
}

//单选按钮集合
auto ItemBot = RadioButtonGroup::create();

//物品栏功能替代
void ventoryFor(Widget::TouchEventType type,int posi) {
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

//物品栏功能设定
void ventorySet() {
    ventory[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 0);
        });

    ventory[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 1);
        });

    ventory[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 2);
        });

    ventory[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 3);
        });

    ventory[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 4);
        });

    ventory[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 5);
        });

    ventory[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 6);
        });

    ventory[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 7);
        });

    ventory[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 8);
        });

    ventory[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 9);
        });

    ventory[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 10);
        });

    ventory[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        ventoryFor(type, 11);
        });
}

//物品栏显示
void inventory(Scene* scene,backPack* pack1,const Size& visibleSize, Vec2 origin) {

    float tileWidth = visibleSize.width / 28;  // 每块土地的宽度
    float tileHeight = tileWidth; // 每块土地的高度
    for (int i = 0; i < 12; i++) {
        ventory[i] = RadioButton::create("Inventory.png", "Inventory chosen.png");

       
        ventory[i]->setScaleX(tileWidth / ventory[i]->getContentSize().width);
        ventory[i]->setScaleY(tileHeight / ventory[i]->getContentSize().height);
        ventory[i]->setPosition(Vec2(origin.x + tileWidth * (9 + i) - ventory[i]->getContentSize().width / 2, origin.y + tileHeight / 5 + ventory[i]->getContentSize().height / 2));

        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

        //物品框内物品尺寸设置
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //图片坐标设置
        packItem->setPosition(Vec2(ventory[i]->getContentSize().width / 2, ventory[i]->getContentSize().width / 2));
        ventory[i]->addChild(packItem,1,1);
        ItemBot->addRadioButton(ventory[i]);
        scene->addChild(ventory[i], invventoryTag, invventoryTag + i);

    }
    auto moneyboard = Sprite::create("moneyBoard.png");
    moneyboard->setScaleX((tileWidth *6) / ( moneyboard->getContentSize().width));
    moneyboard->setScaleY(tileHeight*4 / (3*moneyboard->getContentSize().height));
    moneyboard->setPosition(Vec2(origin.x + tileWidth * 28 - moneyboard->getContentSize().width / 2, origin.y + tileHeight * 15 + moneyboard->getContentSize().height / 2));
    
    Label* money = Label::create(pack1->moneyStringOut(), "Comic Sans MS.ttf", 13);
    money->setColor(Color3B::BLACK);
    money->setPosition(Vec2(origin.x + tileWidth * 28 - moneyboard->getContentSize().width *1.3/ 4, origin.y + tileHeight * 15 + moneyboard->getContentSize().height / 2));
    scene->addChild(moneyboard, invventoryTag);
    scene->addChild(money, invventoryTag+1);
    scene->addChild(ItemBot);
    ventorySet();

}

//背包物品更新
void backItemAddDisplay(int no) {
    if (no < 0 || no >= backpackCapacity) {
        return;
    }
    else {
        Inventory[no]->removeChildByTag(1);
        ventory[no]->removeChildByTag(1);
        
        auto newph1 = Sprite::create(pack1->bottomSelect(no)->filenameReturn());
        newph1->setScaleX(Inventory[no]->getContentSize().width / 1.3 / (newph1->getContentSize().width));
        newph1->setScaleY(Inventory[no]->getContentSize().width / 1.3 / (newph1->getContentSize().height));
        //图片坐标设置
        newph1->setPosition(Vec2(Inventory[no]->getContentSize().width / 2, Inventory[no]->getContentSize().width / 2));

        auto newph2 = Sprite::create(pack1->bottomSelect(no)->filenameReturn());
        newph2->setScaleX(ventory[no]->getContentSize().width / 1.3 / (newph2->getContentSize().width));
        newph2->setScaleY(ventory[no]->getContentSize().width / 1.3 / (newph2->getContentSize().height));
        //图片坐标设置
        newph2->setPosition(Vec2(ventory[no]->getContentSize().width / 2, ventory[no]->getContentSize().width / 2));
        Inventory[no]->addChild(newph1, 1, 1);
        ventory[no]->addChild(newph2, 1, 1);
    }
}

//箭头设置声明
void arrowSet();

//商店功能设置
void storeSoldSet();

RadioButton* commodity[30];

RadioButton* arrowBottom;

RadioButton* arrowTop;

//商店界面设置
void storePhoto(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;

    scrollview = ScrollView::create();
    Pierre* storeItem=new Pierre();
    scrollview->setContentSize(Size(250, 100));
    scrollview->setInnerContainerSize(Size(250, 675));
    scrollview->setPosition(Vec2(128,192));

    auto layout = Layout::create();
    layout->setContentSize(Size(250, 675));
    layout->setPosition(Vec2(0,0));
    for (int i = 0; i < 27; i++) {
        commodity[26-i] = RadioButton::create("emptyBoard.png", "emptyBoard.png");
        commodity[26-i]->setScaleX(250 / commodity[26-i]->getContentSize().width);
        commodity[26-i]->setScaleY(25 / commodity[26-i]->getContentSize().height);
        commodity[26-i]->setPosition(Vec2(layout->getContentSize().width / 2, commodity[26-i]->getContentSize().height / 4 + i * 25));

        auto goods = Sprite::create(storeItem->itemNameOut(26-i, 1,1));
        auto goodsLabel1 = Label::create(storeItem->itemNameOut(26 - i, 1,0) , "Comic Sans MS.ttf", 20);
        auto moneyLabel = Label::create(storeItem->itemMoneyOut(26 - i, 1), "Comic Sans MS.ttf", 20);
        if (moneyLabel == nullptr)
            continue;
        if (goodsLabel1 == nullptr)
            continue;
        goodsLabel1->setColor(Color3B::BLACK);
        moneyLabel->setColor(Color3B::BLACK);
        if (goods == nullptr)
            continue;
        commodity[26-i]->addChild(goods,1,1);
        commodity[26 - i]->addChild(goodsLabel1, 1, 2);
        commodity[26 - i]->addChild(moneyLabel, 1, 3);
        goods->setPosition(Vec2(commodity[26 - i]->getContentSize().width / 20, commodity[26 - i]->getContentSize().height / 2));
        goodsLabel1->setPosition(Vec2(commodity[26 - i]->getContentSize().width / 10+goodsLabel1->getContentSize().width/2, commodity[26 - i]->getContentSize().height / 2 + goodsLabel1->getContentSize().height / 5));
        moneyLabel->setPosition(Vec2(commodity[26 - i]->getContentSize().width*18.5/20-moneyLabel->getContentSize().width/2, commodity[26 - i]->getContentSize().height / 2+moneyLabel->getContentSize().height/5));
        layout->addChild(commodity[26-i]);

    }
    arrowBottom = RadioButton::create("arrow1.png", "arrow1.png");
    arrowTop = RadioButton::create("arrow2.png","arrow2.png");
    scene->addChild(arrowBottom,30,60);
    scene->addChild(arrowTop,30,61);
    arrowBottom->setPosition(Vec2(scrollview->getPositionX() + scrollview->getContentSize().width + arrowBottom->getContentSize().width/2, scrollview->getPositionY() ));
    arrowTop->setPosition(Vec2(scrollview->getPositionX() + scrollview->getContentSize().width + arrowBottom->getContentSize().width / 2, scrollview->getPositionY()+scrollview->getContentSize().height));
    layout->setVisible(1);
    scrollview->getInnerContainer()->addChild(layout);
    scrollview->setScrollBarEnabled(1);
    scrollview->setDirection(ScrollView::Direction::VERTICAL);
    scrollview->setScrollBarPositionFromCornerForVertical(Vec2(scrollview->getPositionX()+scrollview->getContentSize().width/2, scrollview->getPositionY() + scrollview->getContentSize().height / 2));
    
    scene->addChild(scrollview,50);
    arrowSet();
    storeSoldSet();
    packLayer->setPosition(scrollview->getPositionX()+3*tileWidth, scrollview->getPositionY() - scrollview->getContentSize().height / 2 );
    packLayer->setVisible(1);
}

float moveMacket = 0.0;

//箭头设置
void arrowSet() {
    arrowBottom->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            if (moveMacket < 2300.0) {
                moveMacket += 100;
                scrollview->scrollToPercentVertical(moveMacket / 23.0, 0.1, 0);   
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
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            if (moveMacket >= 100.0) {
                moveMacket -= 100;
                scrollview->scrollToPercentVertical(moveMacket / 23.0, 0.1, 0);
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

Pierre* pierre = new Pierre();

//商品栏替代
void storeSoldFor(Widget::TouchEventType type,int posi) {
    switch (type)
    {
    case ui::Widget::TouchEventType::BEGAN: {
        Item* newitem = Seed::create(pierre->itemNameOut(posi,1,0));
        pack1->itemAdd(newitem, 1);
        break;
    }
    case ui::Widget::TouchEventType::ENDED:
        break;
    default:
        break;
    }
}

//商店商品栏设置
void storeSoldSet(){
    commodity[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 0);
        });
    commodity[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 1);
        });
    commodity[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 2);
        });
    commodity[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 3);
        });
    commodity[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 4);
        });
    commodity[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 5);
        });
    commodity[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 6);
        });
    commodity[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 7);
        });
    commodity[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 8);
        });
    commodity[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 9);
        });
    commodity[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 10);
        });
    commodity[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 11);
        });
    commodity[12]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 12);
        });
    commodity[13]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 13);
        });
    commodity[14]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 14);
        });
    commodity[15]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 15);
        });
    commodity[16]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 16);
        });
    commodity[17]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 17);
        });
    commodity[18]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 18);
        });
    commodity[19]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 19);
        });
    commodity[20]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 20);
        });
    commodity[21]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 21);
        });
    commodity[22]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 22);
        });
    commodity[23]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 23);
        });
    commodity[24]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 24);
        });
    commodity[25]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 25);
        });
    commodity[26]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        storeSoldFor(type, 26);
        });
}

//质物栏显示
void soldBox(Scene* scene) {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    float tileWidth = visibleSize.width / 28;
    float tileHeight = tileWidth;
    packLayer->setPosition(visibleSize.width/3,visibleSize.height/3);
    packLayer->setVisible(1);
    soldPosi = RadioButton::create("Inventory.png","Inventory.png");
    if (soldPosi == nullptr)
        return;
    soldPosi->setScaleX(tileWidth / soldPosi->getContentSize().width);
    soldPosi->setScaleY(tileHeight / soldPosi->getContentSize().height);
    soldPosi->setPosition(Vec2(visibleSize.width/2, visibleSize.height / 3 + 4 * tileHeight));

    auto item0 = Sprite::create("null.png");
    if (item0 == nullptr)
        return;
    soldPosi->addChild(item0, 1, 1);
    item0->setScaleX(tileWidth / (item0->getContentSize().width));
    item0->setScaleY(tileHeight / (item0->getContentSize().height));

    //图片坐标设置
    item0->setPosition(Vec2(soldPosi->getContentSize().width / 2, soldPosi->getContentSize().width / 2));

    scene->addChild(soldPosi, 10, 62);
    soldposiSet();
   
}
