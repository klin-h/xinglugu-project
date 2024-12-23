#ifndef FRIENDSHIP_POPUP_LAYER_H
#define FRIENDSHIP_POPUP_LAYER_H

#include "cocos2d.h"

class FriendshipPopupLayer : public cocos2d::Layer {
public:
    static FriendshipPopupLayer* create();  // ���ڴ�����ͼ��ʵ���ľ�̬��������
    bool initWithText(const std::string& text);  // ��ʼ���������������ڴ��벢������ʾ�ı�����
    void onCloseCallback(cocos2d::Ref* sender);  // �رհ�ť����Ļص���������

private:
    cocos2d::Sprite* backgroundSprite;  // ������ʾ�����ľ���ָ�룬��Ϊ��ʾ����ı���
    cocos2d::Label* textLabel;  // ������ʾ��ʾ�ı��ı�ǩָ��
};

#endif // FRIENDSHIP_POPUP_LAYER_H
