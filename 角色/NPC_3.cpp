#include "NPC_3.h"
#include "NPC_1.h"
#include "ui/CocosGUI.h"
#include "GlobalVariables.h"


NPC_3::NPC_3() : taskList() {
    friendshipLevel = 0;
    isFriendWithNPC_1 = false;
    loveshipLevel = 0;
    isLoveWithNPC_1 = false;
    sprite = nullptr;
    onCollect = false;
    onRepair = false;
    Repaired = false;
    mouseListener = nullptr;
}

NPC_3::~NPC_3() {
    CC_SAFE_RELEASE_NULL(sprite);

    if (mouseListener) {
        Director::getInstance()->getEventDispatcher()->removeEventListener(mouseListener);
        mouseListener = nullptr;
    }
}
NPC_3* NPC_3::create() {
    NPC_3* npc = new NPC_3();
    if (npc && npc->init()) {
        npc->autorelease();
        return npc;
    }
    CC_SAFE_DELETE(npc);
    return nullptr;
}

void NPC_3::setup(const Size& visibleSize, Vec2 origin, std::string name, Vec2 pos) {

    sprite = Sprite::create("resources/SYN/" + name + "f1.png");
    if (sprite) {
        CCLOG("NPC_3 sprite loaded successfully");
    }
    else {
        CCLOG("Failed to load NPC_3 sprite image");
    }
    if (sprite) {
        //    ó ʼλ  
        position = pos;
        sprite->setPosition(position);
        this->addChild(sprite);
    }
    if (name == "Harvey") {
        mouseListener = cocos2d::EventListenerMouse::create();
        if (mouseListener) {
            mouseListener->onMouseDown = CC_CALLBACK_1(NPC_3::onMouseClicked_Harvey, this);
            cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
        }
    }
    else if (name == "Haley") {
        targetPosition.x = Constants::Haleyinmap_X;
        targetPosition.y = Constants::Haleyinmap_Y;
        mouseListener = cocos2d::EventListenerMouse::create();
        if (mouseListener) {
            mouseListener->onMouseDown = CC_CALLBACK_1(NPC_3::onMouseClicked_Haley, this);
            cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
        }
    }
}



//    ڸ   NPC_3λ õĺ   
void NPC_3::update(float dt) {

    Vec2 direction = targetPosition - position;

    if (direction.length() < speed * dt) {
        position = targetPosition;
        sprite->setPosition(position);
        return;
    }

    direction.normalize();

    position += direction * speed * dt;
    sprite->setPosition(position);
}


void NPC_3::testAddNPC_3(const Size& visibleSize, Vec2 origin, std::string name, Vec2 pos) {
    auto myNpc = NPC_3::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin, name, pos);

    myNpc->updateFriendshipStatus();
    myNpc->updateLoveshipStatus();

}



void NPC_3::onMouseClicked_Harvey(cocos2d::Event* event) {

    auto touch = static_cast<cocos2d::EventMouse*>(event)->getMouseButton();
    if (touch == cocos2d::EventMouse::MouseButton::BUTTON_LEFT) {

        cocos2d::Vec2 screenLocation = static_cast<cocos2d::EventMouse*>(event)->getLocation();

        cocos2d::Rect rect_Harvey = cocos2d::Rect(Constants::HARVEYx, Constants::HARVEYy, Constants::Character_width, Constants::Character_height);

        if (rect_Harvey.containsPoint(screenLocation)) {

            if (NPC_1::isNear3("Harvey")) {
                if (!onCollect) {
                    generateTask();
                    onCollect = true;
                }
                else {
                    if (checkTaskCompletion()) {
                        onCollect = 0;
                    }
                }
            }
            updateFriendshipStatus();
        }


    }
    else if (touch == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT) {
        cocos2d::Vec2 screenLocation = static_cast<cocos2d::EventMouse*>(event)->getLocation();

        cocos2d::Rect rect_Harvey = cocos2d::Rect(Constants::HARVEYx, Constants::HARVEYy, Constants::Character_width, Constants::Character_height);

        if (rect_Harvey.containsPoint(screenLocation)) {

            if (NPC_1::isNear3("Harvey")) {
                Item* Flowers = Tool::create("flowers");

                if (pack1->matchJudge(Flowers, 1)) {
                    loveshipLevel++;
                    popupmessage("loveshipLevel added");
                    pack1->itemReduce(Flowers, 1);
                }
                else {
                    showNotEnoughFlowersAlert();

                }
                updateLoveshipStatus();
            }

        }

    }

}
void NPC_3::onMouseClicked_Haley(cocos2d::Event* event) {

    auto touch = static_cast<cocos2d::EventMouse*>(event)->getMouseButton();
    if (touch == cocos2d::EventMouse::MouseButton::BUTTON_LEFT) {

        cocos2d::Vec2 screenLocation = static_cast<cocos2d::EventMouse*>(event)->getLocation();

        cocos2d::Rect rect_Haley = cocos2d::Rect(Constants::HALEYx, Constants::HALEYy, Constants::Character_width, Constants::Character_height);
        cocos2d::Rect rect_House = cocos2d::Rect(Constants::Housex, Constants::Housey, Constants::Housewidth, Constants::Househeight);
        if (rect_Haley.containsPoint(screenLocation)) {
            CCLOG("Haley instance has been clicked!");
            if (NPC_1::isNear3("Haley")) {
                if (!onRepair) {
                    Repairbuildings();
                    onRepair = true;
                }
                else {
                    if (checkRepair()) {
                        onRepair = false;
                    }
                }
            }
            updateFriendshipStatus();
        }
        else if (rect_House.containsPoint(screenLocation)) {

            Repaired = true;
        }


    }
    else if (touch == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT) {
        cocos2d::Vec2 screenLocation = static_cast<cocos2d::EventMouse*>(event)->getLocation();

        cocos2d::Rect rect_Haley = cocos2d::Rect(Constants::HALEYx, Constants::HALEYy, Constants::Character_width, Constants::Character_height);
        if (rect_Haley.containsPoint(screenLocation)) {
            CCLOG("Haley instance has been clicked!");
            if (NPC_1::isNear3("Haley")) {
                Item* Flowers = Tool::create("flowers");
                if (pack1->matchJudge(Flowers, 1) != 0) {
                    loveshipLevel++;
                    popupmessage("loveshipLevel added");
                    pack1->itemReduce(Flowers, 1);
                }
                else {
                    showNotEnoughFlowersAlert();
                }
                updateLoveshipStatus();
            }

        }

    }

}





//          ϵ״̬ ĺ   
void NPC_3::updateFriendshipStatus() {
    if (friendshipLevel >= 10) {
        if (!isFriendWithNPC_1) {
            isFriendWithNPC_1 = true;
            popupmessage(" established a friendly relationship");
        }
    }
    else {
        if (isFriendWithNPC_1) {
            isFriendWithNPC_1 = false;
        }
    }
}
//      ռ   Ʒ      Ϊ        
void NPC_3::generateTask() {

    Task newTask;
    newTask.taskDescription = "TEN POTATOES";
    newTask.targetItemCount = 10;
    newTask.rewardDescription = 50;
    newTask.completed = false;
    taskList.push_back(newTask);

    popupmessage(newTask.taskDescription);
}

//              
bool NPC_3::checkTaskCompletion() {
    for (auto& task : taskList) {
        if (task.taskDescription.find("TEN POTATOES") != std::string::npos) {
            backPack myBackPack;
            Item* PATATOES = Fruit::create("potato");
            if (myBackPack.matchJudge(PATATOES, task.targetItemCount)) {
                myBackPack.itemReduce(PATATOES, task.targetItemCount);
                task.completed = true;
                giveReward("collect");
                return true;
            }
            else {
                popupmessage("Task is not completed.");
                break;
            }
        }
    }
    return false;
}

//           
void NPC_3::giveReward(std::string name) {
    for (auto& task : taskList) {
        if (task.completed) {
            friendshipLevel += 2;

            if (name == "collect") {
                onCollect = false;
            }
            else if (name == "repair") {
                onRepair = false;
            }
            pack1->moneyChange(50, 0);
            popupmessage("friendshipLevel added");

        }
    }
}
//          ʾ
void NPC_3::showNotEnoughFlowersAlert() {

    popupmessage("Your flowers are not enough!");

}


//           ϵ״̬ ĺ   
void NPC_3::updateLoveshipStatus() {
    if (loveshipLevel >= 10) {
        if (!isLoveWithNPC_1) {
            isLoveWithNPC_1 = true;
            popupmessage("You have established a romantic relationship just now");
        }
    }
    else {
        if (isLoveWithNPC_1) {
            isLoveWithNPC_1 = false;
        }
    }
}


// ޽       
void NPC_3::Repairbuildings() {
    Repaired = false;
    Task newTask;
    newTask.taskDescription = "Repair the building";
    newTask.targetItemCount = 0;
    newTask.rewardDescription = 100;
    newTask.completed = false;
    taskList.push_back(newTask);

    popupmessage(newTask.taskDescription);

}

bool NPC_3::checkRepair() {
    for (auto& task : taskList) {
        if (task.taskDescription.find("Repair the building") != std::string::npos) {
            if (Repaired) {
                task.completed = true;
                giveReward("repair");
                popupmessage(" 50  coins and  2 points of friendship level with Haley.");
                return true;
            }
            else {
                popupmessage("Task is not completed.");
                break;
            }
        }
    }
    return false;
}

//  ʾ    
void NPC_3::popupmessage(std::string message) {
    auto bulletinBoardLayer = cocos2d::Layer::create();
    auto taskDescriptionLabel = cocos2d::Label::createWithTTF(message, "fonts/arial.ttf", 24);
    taskDescriptionLabel->setPosition(cocos2d::Vec2(bulletinBoardLayer->getContentSize().width / 2, bulletinBoardLayer->getContentSize().height * 0.6));

    auto backgroundSprite = cocos2d::Sprite::create("background_image.png");
    if (backgroundSprite) {

        backgroundSprite->setPosition(taskDescriptionLabel->getPosition());
        bulletinBoardLayer->addChild(backgroundSprite, -1);
    }
    bulletinBoardLayer->addChild(taskDescriptionLabel);

    auto acceptButton = cocos2d::ui::Button::create("button_normal.png", "button_pressed.png");
    acceptButton->setTitleText("OK");
    acceptButton->setTitleFontSize(18);
    acceptButton->setPosition(cocos2d::Vec2(bulletinBoardLayer->getContentSize().width / 2, bulletinBoardLayer->getContentSize().height * 0.3));
    acceptButton->addTouchEventListener([this, bulletinBoardLayer](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType event) {
        if (event == cocos2d::ui::Widget::TouchEventType::ENDED) {
            bulletinBoardLayer->removeFromParent();
        }
        });
    bulletinBoardLayer->addChild(acceptButton);
    g_sharedScene->addChild(bulletinBoardLayer, INT_MAX);
}




