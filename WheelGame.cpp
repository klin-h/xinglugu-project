#include "WheelGame.h"
#include "backPhoto.h"
#include <random>
#include <ctime>

USING_NS_CC;

float rest = 0; // ȫ�ֱ������ڴ洢��һ�εĽǶ�

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
    // ��ȡ���ڵĴ�С
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // ��ʼ��ת�̾���
    wheel = Sprite::create("wheel.png"); // ʹ�����ת��ͼ��
    wheel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(wheel);

    // ��ʼ�������������
    std::random_device rd; // ��ȡ���������
    randomEngine = std::mt19937(rd()); // ��ʼ�����������
    distribution = std::uniform_int_distribution<>(0, 9); // ���÷ֲ���Χ

    // ��ʼ��״̬
    isSpinning = false;
    rotationSpeed = 0;
    totalRotation = 0;

    // ������ת��ť
    spinButton = MenuItemImage::create(
        "spin_button_normal.png", // ����״̬�µİ�ťͼ��
        "spin_button_clicked.png", // ���״̬�µİ�ťͼ��
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

    // ����һ�εĽǶȼӵ��µ���ת�ٶ���
    rotationSpeed = 50.0f + rest; // ���ó�ʼ��ת�ٶ�
    totalRotation = rest; // ����һ�εĽǶȿ�ʼ

    // ������ת�߼��ĵ���
    this->schedule(CC_SCHEDULE_SELECTOR(WheelGame::updateWheel), 0.016f);
}

void WheelGame::updateWheel(float dt) {
    if (rotationSpeed > 0) {
        // ����ת�̵���ת
        wheel->setRotation(wheel->getRotation() + rotationSpeed);
        totalRotation += rotationSpeed;

        // ��С�ٶȣ��򵥵ļ����߼���
        rotationSpeed *= 0.95f; // �𽥼���

        // ʹ�����������������һ�������
        float ran = distribution(randomEngine);
        totalRotation += ran;

        // ֹͣ��תʱ���߼�
        if (rotationSpeed < 0.1f) {
            isSpinning = false;
            this->unschedule(CC_SCHEDULE_SELECTOR(WheelGame::updateWheel));

            // ����ת�̵�����ת�Ƕ��ж�ʤ��
            float finalAngle = fmod(totalRotation, 360.0f); // ��ȡ���յĽǶȣ�0-360��
            CCLOG("Final Angle: %f", finalAngle);

            // ���Ƕȷ�Ϊ��������
            if (finalAngle > 90.0f && finalAngle < 270.0f) {
                CCLOG("Success!");
                moneyChange(100, 0); // ��Ǯ
            }
            else {
                CCLOG("Failed!");
                moneyChange(100, 1); // ��Ǯ
            }
            rest = finalAngle; // ���� rest Ϊ��ǰ�� finalAngle
        }
    }
}