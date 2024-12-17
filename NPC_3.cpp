#include "NPC_3.h"
#include "NPC_1.h"


NPC_3::NPC_3() {
    friendshipLevel = 0;
    isFriendWithNPC_1 = false;
    sprite = nullptr;
    mouseListener = nullptr;  // 初始化mouseListener指针为nullptr
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

void NPC_3::setup(const Size& visibleSize, Vec2 origin) {
    sprite = Sprite::create("resources/SYN/Abigailf1.png");  
    if (sprite) {
        CCLOG("NPC_3 sprite loaded successfully");
    }
    else {
        CCLOG("Failed to load NPC_3 sprite image");
    }
    if (sprite) {
        // 设置初始位置
        Vec2 pos;
        pos.x = visibleSize.width / 4-8;
        pos.y = 2 * visibleSize.height / 4-8;
        position = pos;
        sprite->setPosition(position);
        this->addChild(sprite);
    }
   
    mouseListener = cocos2d::EventListenerMouse::create();
    if (mouseListener) {
        mouseListener->onMouseDown = CC_CALLBACK_1(NPC_3::onMouseClicked, this);
        cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
    }
}
    

// 用于更新NPC_3位置的函数
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


void NPC_3::testAddNPC_3(const Size& visibleSize, Vec2 origin) {
    auto myNpc = NPC_3::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin);
    myNpc->updateFriendshipStatus();
}

Vec2 Endposition3;

void NPC_3::onMouseClicked(cocos2d::Event* event) {
    auto touch = static_cast<cocos2d::EventMouse*>(event)->getMouseButton();
    if (touch == cocos2d::EventMouse::MouseButton::BUTTON_LEFT) {  
       
       cocos2d::Vec2 screenLocation = static_cast<cocos2d::EventMouse*>(event)->getLocation();
       CCLOG(": (%f, %f)", screenLocation.x, screenLocation.y);
        cocos2d::Rect rect = cocos2d::Rect(Constants::HARVEYx, Constants::HARVEYy, Constants::HARVEY_width, Constants::HARVEY_height);
       
        if (rect.containsPoint(screenLocation)) {
            CCLOG("NPC_3 instance has been clicked!");
            if (NPC_1::isNear3()) {
                friendshipLevel++;
                CCLOG(": friendshipLevel added");
                updateFriendshipStatus();
                CCLOG(": friendshipLevel:(%d)",friendshipLevel);
           }
            else {
                CCLOG(": not near");
            }
        }
        else {
            CCLOG("Mouse click is outside of NPC_3's bounds.");
        }

    }
}



// 判断是否与NPC_1建立友谊关系的函数
bool NPC_3::hasFriendshipWithNPC_1() const {
    return isFriendWithNPC_1;
}

// 更新友谊关系状态的函数
void NPC_3::updateFriendshipStatus() {
    if (friendshipLevel >= 10) {
        if (!isFriendWithNPC_1) {
            isFriendWithNPC_1 = true;
            CCLOG("NPC_3 and NPC_1 have established a friendship!");
        }
    }
    else {
        if (isFriendWithNPC_1) {
            isFriendWithNPC_1 = false;
            CCLOG("NPC_3 and NPC_1's friendship has ended due to low friendship level.");
        }
    }
}
// 生成任务函数
void NPC_3::generateTask() {
    
    Task newTask;
    newTask.taskDescription = "收集 10 个苹果";
    newTask.targetItemCount = 10;
    newTask.currentItemCount = 0;
    newTask.rewardDescription = "50 金币和一把新锄头";
    newTask.completed = false;
    taskList.push_back(newTask);
   
    auto bulletinBoardLayer = cocos2d::Layer::create();

    
    auto taskDescriptionLabel = cocos2d::Label::createWithTTF(newTask.taskDescription, "fonts/arial.ttf", 24);
    taskDescriptionLabel->setPosition(cocos2d::Vec2(bulletinBoardLayer->getContentSize().width / 2, bulletinBoardLayer->getContentSize().height * 0.6));
    bulletinBoardLayer->addChild(taskDescriptionLabel);

    
    auto acceptButton = cocos2d::ui::Button::create("buttons/accept_normal.png", "buttons/accept_pressed.png");
    acceptButton->setTitleText("接受任务");
    acceptButton->setTitleFontSize(18);
    acceptButton->setPosition(cocos2d::Vec2(bulletinBoardLayer->getContentSize().width / 2, bulletinBoardLayer->getContentSize().height * 0.3));
    acceptButton->addTouchEventListener([this, &newTask, bulletinBoardLayer](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType event) {
        if (event == cocos2d::ui::Widget::TouchEventType::ENDED) {
           
            taskList.push_back(newTask);
            
            bulletinBoardLayer->removeFromParent();
        }
        });
    bulletinBoardLayer->addChild(acceptButton);

    
    g_sharedScene->addChild(bulletinBoardLayer, INT_MAX);
}

// 检查任务完成情况函数
bool NPC_3::checkTaskCompletion(int itemCount) {
    for (auto& task : taskList) {
        if (task.taskDescription.find("收集苹果") != std::string::npos) {
            task.currentItemCount += itemCount;
            if (task.currentItemCount >= task.targetItemCount) {
                task.completed = true;
                return true;
            }
        }
    }
    return false;
}

// 给予任务奖励函数
void NPC_3::giveReward() {
    for (auto& task : taskList) {
        if (task.completed) {
            // 添加奖励物品
            
            CCLOG("NPC_1 获得奖励: %s", task.rewardDescription.c_str());
            
        }
    }
}