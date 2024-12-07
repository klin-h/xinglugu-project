#ifndef __LAND_H__
#define __LAND_H__

#include "cocos2d.h"

class Land:public cocos2d::Sprite {
public:
    static float tileSize; //���ڶ�̬������С
    // ���ص�״̬
    enum class State {
        Empty,     // �յ�
        Planted,   // ����ֲ
        Watered,   // �ѽ�ˮ
        Harvested  // ���ջ�
    };

    State state = State::Empty; // Ĭ��״̬Ϊ�յ�

    // ��������
    static Land* create(const std::string& filename);

    // ���ؽ����߼�
    void interact();
    //void adjustScale();
};

#endif // __LAND_H__
