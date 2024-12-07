#ifndef WALKING_CHARACTER_H
#define WALKING_CHARACTER_H

#include "cocos2d.h"

class WalkingCharacter : public cocos2d::Node {
public:
    static WalkingCharacter* create();
    virtual bool init();
    // ��������ͼƬ·��
    void setImagePath(const std::string& imagePath);
    cocos2d::Sprite* getCharacterSprite();
private:
    cocos2d::Sprite* _characterSprite;  // �����ɫ�ľ���
    cocos2d::Vector<cocos2d::SpriteFrame*> _walkFrames;  // ���ڴ洢��ɫ��·������֡��ͼƬ��
    int _currentFrameIndex;  // ��ǰ��ʾ��֡����
    void loadWalkFramesFromImage(const std::string& imagePath);  // �Ӹ���ͼƬ·��������·����֡������ƴͼ�����
    void playWalkAnimationOnce();  // ������·����һ�Σ�����ʵ�ֽ�ɫ��һ���Ĺ��ܣ���cpp�ļ��еĶ�Ӧ����ƥ��
};

#endif