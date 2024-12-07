/****************************************************************
 * Project Name: xinglugu-project
 * File Pig.h
 * File Function: Class representing a pig on the farm
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#ifndef PIG_H
#define PIG_H

#include "Animal.h"

class Pig : public Animal
{
public:
    // ���캯��
    Pig();

    // ����������
    virtual ~Pig();

    static Pig* create();
    virtual bool init() override;

    // ʵ�ֲ�������
    virtual void produce() override;

    // ������з���
    void oink(); // �����

    // ��������
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // ���Ʒ���
    void heal(int amount);

    bool isWalking_ = false; // �Ƿ����ƶ�״̬
};

#endif // PIG_H