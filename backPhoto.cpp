#include "MainScene.h"
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "back.h"
#include "Constants.h"
#include "backPhoto.h"
USING_NS_CC;
USING_NS_CC::ui;
using namespace Constants;
bool backIsOpen = BackOpen1;
bool backIsProed = BackPro1;
RadioButton* Inventory[backpackCapacity];
Sprite* displayItem;
bool isSelected = 0;

extern backPack* pack1;

void listenSet(Scene* scene, const cocos2d::Size& visibleSize, float tileHeight, float tileWidth) {

    Inventory[0]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {

            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[0]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(0)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 0);
                auto newph = Sprite::create(pack1->bottomSelect(0)->filenameReturn());
                Inventory[0]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);

                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {

                Inventory[0]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(0)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(0);

                auto newph = Sprite::create(pack1->bottomSelect(0)->filenameReturn());
                newph->setScaleX(Inventory[0]->getContentSize().width / 1.3 / (newph->getContentSize().width));
                newph->setScaleY(Inventory[0]->getContentSize().width / 1.3 / (newph->getContentSize().height));

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[0]->getContentSize().width / 2, Inventory[0]->getContentSize().width / 2));
                Inventory[0]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[1]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[1]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(1)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 1);
                auto newph = Sprite::create(pack1->bottomSelect(1)->filenameReturn());
                Inventory[1]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {

                Inventory[1]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(1)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(1);

                auto newph = Sprite::create(pack1->bottomSelect(1)->filenameReturn());
                newph->setScaleX(Inventory[1]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[1]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[1]->getContentSize().width / 2, Inventory[1]->getContentSize().width / 2));
                Inventory[1]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[2]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[2]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(2)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 2);
                auto newph = Sprite::create(pack1->bottomSelect(2)->filenameReturn());
                Inventory[2]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[2]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(2)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(2);

                auto newph = Sprite::create(pack1->bottomSelect(2)->filenameReturn());
                newph->setScaleX(Inventory[2]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[2]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[2]->getContentSize().width / 2, Inventory[2]->getContentSize().width / 2));
                Inventory[2]->addChild(newph, 1, 1);

                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[3]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[3]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(3)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 3);
                auto newph = Sprite::create(pack1->bottomSelect(3)->filenameReturn());
                Inventory[3]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[3]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(3)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(3);

                auto newph = Sprite::create(pack1->bottomSelect(3)->filenameReturn());
                newph->setScaleX(Inventory[3]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[3]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[3]->getContentSize().width / 2, Inventory[3]->getContentSize().width / 2));
                Inventory[3]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[4]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[4]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(4)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 4);
                auto newph = Sprite::create(pack1->bottomSelect(4)->filenameReturn());
                Inventory[4]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[4]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(4)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(4);

                auto newph = Sprite::create(pack1->bottomSelect(4)->filenameReturn());
                newph->setScaleX(Inventory[4]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[4]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[4]->getContentSize().width / 2, Inventory[4]->getContentSize().width / 2));
                Inventory[4]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[5]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[5]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(5)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 5);
                auto newph = Sprite::create(pack1->bottomSelect(5)->filenameReturn());
                Inventory[5]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {

                Inventory[5]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(5)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(5);

                auto newph = Sprite::create(pack1->bottomSelect(5)->filenameReturn());
                newph->setScaleX(Inventory[5]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[5]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[5]->getContentSize().width / 2, Inventory[5]->getContentSize().width / 2));
                Inventory[5]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[6]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[6]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(6)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 6);
                auto newph = Sprite::create(pack1->bottomSelect(6)->filenameReturn());
                Inventory[6]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {

                Inventory[6]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(6)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(6);

                auto newph = Sprite::create(pack1->bottomSelect(6)->filenameReturn());
                newph->setScaleX(Inventory[6]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[6]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[6]->getContentSize().width / 2, Inventory[6]->getContentSize().width / 2));
                Inventory[6]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[7]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[7]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(7)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 1);
                auto newph = Sprite::create(pack1->bottomSelect(7)->filenameReturn());
                Inventory[7]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {

                Inventory[7]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(7)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(7);
                auto newph = Sprite::create(pack1->bottomSelect(7)->filenameReturn());
                newph->setScaleX(Inventory[7]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[7]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[7]->getContentSize().width / 2, Inventory[7]->getContentSize().width / 2));
                Inventory[7]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[8]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[8]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(8)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 8);
                auto newph = Sprite::create(pack1->bottomSelect(8)->filenameReturn());
                Inventory[8]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[8]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(8)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(8);
                auto newph = Sprite::create(pack1->bottomSelect(8)->filenameReturn());
                newph->setScaleX(Inventory[8]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[8]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[8]->getContentSize().width / 2, Inventory[8]->getContentSize().width / 2));
                Inventory[8]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[9]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[9]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(9)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 9);
                auto newph = Sprite::create(pack1->bottomSelect(9)->filenameReturn());
                Inventory[9]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[9]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(9)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(9);
                auto newph = Sprite::create(pack1->bottomSelect(9)->filenameReturn());
                newph->setScaleX(Inventory[9]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[9]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[9]->getContentSize().width / 2, Inventory[9]->getContentSize().width / 2));
                Inventory[9]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[10]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[10]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(0)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 10);
                auto newph = Sprite::create(pack1->bottomSelect(10)->filenameReturn());
                Inventory[10]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[10]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(10)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(10);
                auto newph = Sprite::create(pack1->bottomSelect(10)->filenameReturn());
                newph->setScaleX(Inventory[10]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[10]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[10]->getContentSize().width / 2, Inventory[10]->getContentSize().width / 2));
                Inventory[10]->addChild(newph, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

    Inventory[11]->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
        {
            if (isSelected == 0)
            {
                isSelected = 1;
                Inventory[11]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(11)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOn(1, 11);
                auto newph = Sprite::create(pack1->bottomSelect(11)->filenameReturn());
                Inventory[11]->addChild(newph);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            else {
                Inventory[11]->removeChildByTag(1);
                auto exchangeItem = Sprite::create(pack1->bottomSelect(11)->filenameReturn());
                exchangeItem->setScaleX(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().width);
                exchangeItem->setScaleY(displayItem->getContentSize().width / 1.3 / exchangeItem->getContentSize().height);
                exchangeItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));
                pack1->itemPositionChangeOff(11);
                auto newph = Sprite::create(pack1->bottomSelect(1)->filenameReturn());
                newph->setScaleX(Inventory[11]->getContentSize().width / 1.3 / newph->getContentSize().width);
                newph->setScaleY(Inventory[11]->getContentSize().width / 1.3 / newph->getContentSize().height);

                //图片坐标设置
                newph->setPosition(Vec2(Inventory[11]->getContentSize().width / 2, Inventory[11]->getContentSize().width / 2));
                Inventory[11]->addChild(newph, 1, 1);
                displayItem->removeChildByTag(1);
                displayItem->addChild(exchangeItem, 1, 1);
            }
            break;
        }
        case ui::Widget::TouchEventType::ENDED:
            break;
        default:
            break;
        }
        });

}

void backPhoto(Scene* scene,backPack* pack1,EventDispatcher* _eventDispatcher){
auto visibleSize = Director::getInstance()->getVisibleSize();

Vec2 origin = Director::getInstance()->getVisibleOrigin();

auto keyListener = EventListenerKeyboard::create();

keyListener->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
    {
        switch (code)
        {
        case EventKeyboard::KeyCode::KEY_B:

        {
            if (backIsOpen == BackOpen1) {

                backIsOpen = BackOpen2;
                if (backIsProed == BackPro1) {
                    auto group2 = RadioButtonGroup::create();
                    backIsProed = BackPro2;
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
                        group2->addRadioButton(Inventory[i]);
                        scene->addChild(Inventory[i], invventoryTag + 1 + i, i);


                    }

                    listenSet(scene, visibleSize, tileHeight, tileWidth);
                    for (int i = backpackCapacity / 3; i < backpackCapacity * 2 / 3; i++) {
                        auto Inventory = RadioButton::create("Inventory.png", "Inventory.png");
                        Inventory->setScaleX(tileWidth / Inventory->getContentSize().width);
                        Inventory->setScaleY(tileHeight / Inventory->getContentSize().height);
                        Inventory->setPosition(Vec2(origin.x + tileWidth * (9 + i - 12) - Inventory->getContentSize().width / 2, origin.y + tileHeight * 12 + Inventory->getContentSize().height / 2));
                        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

                        //物品框内物品尺寸设置
                        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
                        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

                        //图片坐标设置
                        packItem->setPosition(Vec2(Inventory->getContentSize().width / 2, Inventory->getContentSize().width / 2));

                        Inventory->addChild(packItem);
                        group2->addRadioButton(Inventory);
                        scene->addChild(Inventory, invventoryTag + 1 + i, i);
                    }

                    for (int i = backpackCapacity * 2 / 3; i < backpackCapacity; i++) {
                        auto Inventory = RadioButton::create("Inventory.png", "Inventory.png");
                        Inventory->setScaleX(tileWidth / Inventory->getContentSize().width);
                        Inventory->setScaleY(tileHeight / Inventory->getContentSize().height);
                        Inventory->setPosition(Vec2(origin.x + tileWidth * (9 + i - 24) - Inventory->getContentSize().width / 2, origin.y + tileHeight * 11 + Inventory->getContentSize().height / 2));
                        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

                        //物品框内物品尺寸设置
                        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
                        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

                        //图片坐标设置
                        packItem->setPosition(Vec2(Inventory->getContentSize().width / 2, Inventory->getContentSize().width / 2));

                        Inventory->addChild(packItem);
                        group2->addRadioButton(Inventory);
                        scene->addChild(Inventory, invventoryTag + 1 + i, i);
                    }
                    displayItem = Sprite::create("Inventory.png");
                    displayItem->setScaleX(tileWidth / displayItem->getContentSize().width);
                    displayItem->setScaleY(tileHeight / displayItem->getContentSize().height);
                    displayItem->setPosition(Vec2(origin.x + tileWidth * (22) - displayItem->getContentSize().width / 2, origin.y + tileHeight * 13 + displayItem->getContentSize().height / 2));

                    auto addItem = Sprite::create("null.png");
                    addItem->setScaleX(tileWidth / (addItem->getContentSize().width));
                    addItem->setScaleY(tileHeight / (addItem->getContentSize().height));
                    addItem->setPosition(Vec2(displayItem->getContentSize().width / 2, displayItem->getContentSize().width / 2));

                    displayItem->addChild(addItem, 1, 1);
                    scene->addChild(displayItem, invventoryTag + 1 + backpackCapacity, 1 + backpackCapacity);

                    scene->addChild(group2);
                    auto botlam = Sprite::create("inventory.png");
                    botlam->setScaleX(tileWidth * 12 / botlam->getContentSize().width);
                    botlam->setScaleY(tileWidth * 4 / botlam->getContentSize().height);
                    botlam->setPosition(Vec2(origin.x + 14.5 * tileWidth - botlam->getContentSize().width / 2, origin.y + tileWidth * 8.5 + botlam->getContentSize().height / 2));
                    scene->addChild(botlam, 38, 36);


                    for (int i = 0; i < 12; i++) {
                        scene->getChildByTag(100 + i)->setVisible(0);
                    }
                }
                else {

                    for (int i = 0; i < backpackCapacity / 3; i++) {
                        scene->getChildByTag(i)->setVisible(1);
                    }
                    for (int i = backpackCapacity / 3; i < backpackCapacity * 2 / 3; i++) {
                        scene->getChildByTag(i)->setVisible(1);
                    }
                    for (int i = backpackCapacity * 2 / 3; i < backpackCapacity; i++) {
                        scene->getChildByTag(i)->setVisible(1);
                    }
                    scene->getChildByTag(1 + backpackCapacity)->setVisible(1);
                    scene->getChildByTag(backpackCapacity)->setVisible(1);
                    for (int i = 0; i < backpackCapacity / 3; i++) {
                        scene->getChildByTag(invventoryTag + i)->setVisible(0);
                    }
                }
            }
            else {
                backIsOpen = 0;
                pack1->itemChangeReset();
                isSelected = 0;
                for (int i = 0; i < backpackCapacity / 3; i++) {
                    scene->getChildByTag(i)->setVisible(0);
                }
                for (int i = backpackCapacity / 3; i < backpackCapacity * 2 / 3; i++) {
                    scene->getChildByTag(i)->setVisible(0);
                }
                for (int i = backpackCapacity * 2 / 3; i < backpackCapacity; i++) {
                    scene->getChildByTag(i)->setVisible(0);
                }
                scene->getChildByTag(1 + backpackCapacity)->setVisible(0);
                scene->getChildByTag(backpackCapacity)->setVisible(0);
                for (int i = 0; i < backpackCapacity / 3; i++) {
                    scene->getChildByTag(100 + i)->setVisible(1);
                }
            }
            break;
        }
        default:
            break;
        }
    });

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, scene);
}

//单选按钮集合
auto ItemBot = RadioButtonGroup::create();

void inventory(Scene* scene,backPack* pack1,const Size& visibleSize, Vec2 origin) {

    float tileWidth = visibleSize.width / 28;  // 每块土地的宽度
    float tileHeight = tileWidth; // 每块土地的高度
    for (int i = 0; i < 12; i++) {
        auto Inventory = RadioButton::create("Inventory.png", "Inventory chosen.png");

        Inventory->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type) {
            switch (type)
            {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
            }
            });
        Inventory->setScaleX(tileWidth / Inventory->getContentSize().width);
        Inventory->setScaleY(tileHeight / Inventory->getContentSize().height);
        Inventory->setPosition(Vec2(origin.x + tileWidth * (9 + i) - Inventory->getContentSize().width / 2, origin.y + tileHeight / 5 + Inventory->getContentSize().height / 2));

        auto packItem = Sprite::create(pack1->bottomSelect(i)->filenameReturn());

        //物品框内物品尺寸设置
        packItem->setScaleX(tileWidth / (packItem->getContentSize().width));
        packItem->setScaleY(tileHeight / (packItem->getContentSize().height));

        //图片坐标设置
        packItem->setPosition(Vec2(Inventory->getContentSize().width / 2, Inventory->getContentSize().width / 2));
        Inventory->addChild(packItem);
        ItemBot->addRadioButton(Inventory);
        scene->addChild(Inventory, invventoryTag, invventoryTag + i);

    }
    scene->addChild(ItemBot);
}
