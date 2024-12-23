#include "WheelGame.h"
#include "backPhoto.h"
#include <random>
#include <ctime>

USING_NS_CC;

float rest = 0; // 全局变量用于存储上一次的角度

WheelGame* WheelGame::create() {
    WheelGame* ret = new WheelGame();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool WheelGame::init() {
    // 获取窗口的大小
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // 初始化转盘精灵
    wheel = Sprite::create("wheel.png"); // 使用你的转盘图像
    wheel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(wheel);

    // 初始化随机数生成器
    std::random_device rd; // 获取随机数种子
    randomEngine = std::mt19937(rd()); // 初始化随机数引擎
    distribution = std::uniform_int_distribution<>(0, 9); // 设置分布范围

    // 初始化状态
    isSpinning = false;
    rotationSpeed = 0;
    totalRotation = 0;

    // 创建旋转按钮
    spinButton = MenuItemImage::create(
        "spin_button_normal.png", // 正常状态下的按钮图像
        "spin_button_clicked.png", // 点击状态下的按钮图像
        CC_CALLBACK_1(WheelGame::onSpinButtonClicked, this));

    spinButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));

    auto menu = Menu::create(spinButton, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);

    return true;
}

void WheelGame::onSpinButtonClicked(Ref* sender) {
    if (!isSpinning) {
        spinWheel();
    }
}

void WheelGame::spinWheel() {
    isSpinning = true;

    // 将上一次的角度加到新的旋转速度上
    rotationSpeed = 50.0f + rest; // 设置初始旋转速度
    totalRotation = rest; // 从上一次的角度开始

    // 更新旋转逻辑的调度
    this->schedule(CC_SCHEDULE_SELECTOR(WheelGame::updateWheel), 0.016f);
}

void WheelGame::updateWheel(float dt) {
    if (rotationSpeed > 0) {
        // 更新转盘的旋转
        wheel->setRotation(wheel->getRotation() + rotationSpeed);
        totalRotation += rotationSpeed;

        // 减小速度（简单的减速逻辑）
        rotationSpeed *= 0.95f; // 逐渐减速

        // 使用随机数生成器生成一个随机数
        float ran = distribution(randomEngine);
        totalRotation += ran;

        // 停止旋转时的逻辑
        if (rotationSpeed < 0.1f) {
            isSpinning = false;
            this->unschedule(CC_SCHEDULE_SELECTOR(WheelGame::updateWheel));

            // 根据转盘的总旋转角度判断胜负
            float finalAngle = fmod(totalRotation, 360.0f); // 获取最终的角度（0-360）
            CCLOG("Final Angle: %f", finalAngle);

            // 将角度分为两个区域
            if (finalAngle > 90.0f && finalAngle < 270.0f) {
                CCLOG("Success!");
                moneyChange(100, 0); // 加钱
            }
            else {
                CCLOG("Failed!");
                moneyChange(100, 1); // 扣钱
            }
            rest = finalAngle; // 更新 rest 为当前的 finalAngle
        }
    }
}
