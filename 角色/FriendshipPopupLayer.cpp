#include "FriendshipPopupLayer.h"

// ����FriendshipPopupLayerʵ���ĺ���ʵ��
FriendshipPopupLayer* FriendshipPopupLayer::create() {
    FriendshipPopupLayer* layer = new FriendshipPopupLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

// ��ʼ������ʵ�֣�����������ʾ����ľ������ݺ���ʽ
bool FriendshipPopupLayer::initWithText(const std::string& text) {
    if (!Layer::init()) {
        return false;
    }

    // �����������飬�����������һ����Ϊpopup_background.png��ͼƬ��Ϊ��ʾ����ı���ͼƬ����ɸ���ʵ���滻
    backgroundSprite = cocos2d::Sprite::create("popup_background.png");
    backgroundSprite->setPosition(this->getContentSize() / 2);
    this->addChild(backgroundSprite);

    // �����ı���ǩ�������ı����ݡ�������ֺŵȣ�������������ļ���Ϊyour_font.ttf���������ʵ���滻
    textLabel = cocos2d::Label::createWithTTF(text, "fonts/your_font.ttf", 24);
    textLabel->setPosition(backgroundSprite->getContentSize() / 2);
    backgroundSprite->addChild(textLabel);

    // �����رհ�ť��ʹ�����Ų�ͬ״̬��ͼƬ�������Ͱ���״̬�����������ͼƬ��Ϊclose_button_normal.png��close_button_pressed.png���ɰ����滻
    cocos2d::MenuItemImage* closeButton = cocos2d::MenuItemImage::create(
        "close_button_normal.png",
        "close_button_pressed.png",
        CC_CALLBACK_1(FriendshipPopupLayer::onCloseCallback, this)
    );
    closeButton->setPosition(backgroundSprite->getContentSize().width - closeButton->getContentSize().width / 2,
        closeButton->getContentSize().height / 2);

    // �����˵�����ӹرհ�ť���˵����ڹ���ť�Ƚ���Ԫ���ڽ����ϵĲ��ֺ���Ӧ�߼�
    cocos2d::Menu* menu = cocos2d::Menu::create(closeButton, nullptr);
    menu->setPosition(cocos2d::Vec2::ZERO);
    backgroundSprite->addChild(menu);

    return true;
}

// �رհ�ť����Ļص�����ʵ�֣������Ƴ���ʾ����ͼ��
void FriendshipPopupLayer::onCloseCallback(cocos2d::Ref* sender) {
    this->removeFromParent();
}