#include "WalkingCharacter.h"

USING_NS_CC;

// ������������ѭCocos2d-x�Ĵ�������淶
WalkingCharacter* WalkingCharacter::create() {
    WalkingCharacter* ret = new (std::nothrow) WalkingCharacter();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    else {
        delete ret;
        return nullptr;
    }
}

// ��ʼ������
bool WalkingCharacter::init() {
    if (!Node::init()) {
        return false;
    }

    // ������ɫ���飬�Ȳ���������ͼƬ������ͨ������֡������ͼƬ
    _characterSprite = Sprite::create();
    if (_characterSprite) {
        this->addChild(_characterSprite);
    }

    // ��ʼ��ʱ������ͼƬ·�����ȴ��ⲿ����setImagePath������
    _currentFrameIndex = 0;
    return true;
}

// ����������������ͼƬ·��������֡
void WalkingCharacter::setImagePath(const std::string& imagePath) {
    loadWalkFramesFromImage(imagePath);
    playWalkAnimationOnce();
}

// �Ӹ���ͼƬ·��������·����֡������ƴͼ�������һ�㶼���߻��ܵĶ�������һ��ƴͼ��
void WalkingCharacter::loadWalkFramesFromImage(const std::string& imagePath) {
    // ʹ��TextureCache��ȡ������������Ա����ظ�������ͬ�����������
    auto texture = Director::getInstance()->getTextureCache()->addImage(imagePath);

    // ��������ͼƬ����һ����ÿ��ͼƬ��С��ͬ���ɸ���ʵ���������������㷽ʽ��
    Size frameSize = Size(texture->getContentSize().width / 4, texture->getContentSize().height);

    // ѭ����ȡ����ͼƬ��Ϊ����֡
    for (int i = 0; i < 4; ++i) {
        Rect rect(i * frameSize.width, 0, frameSize.width, frameSize.height);
        auto spriteFrame = SpriteFrame::createWithTexture(texture, rect);
        _walkFrames.pushBack(spriteFrame);
    }
}

// ������·������ʵ��ֻ����һ����ģ����һ��
void WalkingCharacter::playWalkAnimationOnce() {
    // ����һ��������������һЩ����
    auto animation = Animation::create();
    animation->setDelayPerUnit(0.2f);  // ÿ֡���ʱ�䣬������·�ٶȣ��ɸ���ʵ�ʵ���

    // ��֮ǰ���غõ�֡��ӵ�����������
    for (const auto& frame : _walkFrames) {
        animation->addSpriteFrame(frame);
    }

    // ����һ����������������ǰ�洴���Ķ�������
    auto animateAction = Animate::create(animation);

    // ����һ���ص������������ڶ����������ִ��
    auto callbackAction = CallFunc::create([this]() {
        
        _characterSprite->stopAllActions();
        // ����������󣬽���ǰ֡��������Ϊ0���Ա��´β��Ŷ���ʱ�ӵ�һ֡��ʼ
        _currentFrameIndex = 0;
        });

    // ʹ��˳������ϣ��Ȳ��Ŷ���������Ȼ��ִ�лص���������
    auto sequenceAction = Sequence::create(animateAction, callbackAction, nullptr);

    // �ý�ɫ����ִ��˳�������
    _characterSprite->runAction(sequenceAction);
}

// ʵ�ֻ�ȡ��ɫ����ĺ��������ֲ��䣬��Ϊ�߼����Ǽ򵥷��س�Ա����_characterSprite��ָ��
cocos2d::Sprite* WalkingCharacter::getCharacterSprite() {
    return _characterSprite;
}