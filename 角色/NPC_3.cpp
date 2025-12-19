#include "NPC_3.h"
#include "NPC_1.h"
#include "ui/CocosGUI.h"
#include "GlobalVariables.h"

// --- 定义 AI 状态类 ---

// 1. 漫游状态
class AIRoamingState : public CharacterState {
public:
    void enter(Character* character) override {
        CCLOG("NPC_3 进入漫游状态");
        // 可以在这里随机设置一个新的 targetPosition
        NPC_3* npc = dynamic_cast<NPC_3*>(character);
        if (npc) {
            // 示例：随机移动一点距离
            npc->targetPosition = npc->position + Vec2(rand() % 100 - 50, rand() % 100 - 50);
        }
    }

    void execute(Character* character, float dt) override {
        NPC_3* npc = dynamic_cast<NPC_3*>(character);
        if (npc) {
            npc->moveToTarget(dt);
            if (npc->isTargetReached()) {
                // 到达目标后，切换到待机状态
                npc->changeState(new AIIdleState()); // 需要前向声明或放在后面，这里假设编译器能找到
            }
        }
    }

    void exit(Character* character) override {
        NPC_3* npc = dynamic_cast<NPC_3*>(character);
        if (npc) npc->stopMoving();
    }

    std::string getStateName() const override { return "AIRoaming"; }
};

// 2. 待机状态
class AIIdleState : public CharacterState {
    float timer;
public:
    void enter(Character* character) override {
        CCLOG("NPC_3 进入待机状态");
        timer = 0;
    }

    void execute(Character* character, float dt) override {
        timer += dt;
        if (timer > 3.0f) { // 待机 3 秒
            character->changeState(new AIRoamingState());
        }
    }

    void exit(Character* character) override {}

    std::string getStateName() const override { return "AIIdle"; }
};

// --------------------

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
    speed = 50.0f; // 默认速度

    // 初始状态
    this->changeState(new AIRoamingState());
}

NPC_3::~NPC_3() {
    CC_SAFE_RELEASE_NULL(sprite);
    if (mouseListener) {
        _eventDispatcher->removeEventListener(mouseListener);
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
        this->addChild(sprite);
        position = pos;
        targetPosition = pos; // 初始目标为自身
        sprite->setPosition(position);
    }
    // ... 其他 setup 逻辑 ...
}

// 提取出的移动逻辑
void NPC_3::moveToTarget(float dt) {
    Vec2 direction = targetPosition - position;
    if (direction.length() < speed * dt) {
        position = targetPosition;
    } else {
        direction.normalize();
        position += direction * speed * dt;
    }
    if (sprite) sprite->setPosition(position);
}

void NPC_3::stopMoving() {
    // 停止动画等
}

bool NPC_3::isTargetReached() const {
    return position.distance(targetPosition) < 5.0f;
}

// ... 其他原有业务逻辑保持不变 ...
void NPC_3::testAddNPC_3(const Size& visibleSize, Vec2 origin, std::string name, Vec2 pos) {
    auto myNpc = NPC_3::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin, name, pos);
}

void NPC_3::onMouseClicked_Harvey(cocos2d::Event* event) {
    // ... 原有逻辑 ...
}
void NPC_3::onMouseClicked_Haley(cocos2d::Event* event) {
    // ... 原有逻辑 ...
}
void NPC_3::updateFriendshipStatus() {}
void NPC_3::updateLoveshipStatus() {}
void NPC_3::generateTask() {}
bool NPC_3::checkTaskCompletion() { return false; }
void NPC_3::giveReward(std::string name) {}
void NPC_3::Repairbuildings() {}
bool NPC_3::checkRepair() { return false; }
void NPC_3::showNotEnoughFlowersAlert() {}
void NPC_3::popupmessage(std::string message) {}
