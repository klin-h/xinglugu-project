/****************************************************************
 * Project Name: xinglugu-project
 * File Chicken.h
 * File Function: Class representing a chicken on the farm
 * Author: Gao wenhao
 * Update Date: 2024.12.6
 * License:
 ****************************************************************/
#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"

class Chicken : public Animal
{
public:
    // ���캯��
    Chicken();

    // ����������
    virtual ~Chicken();

    static Chicken* create();
    virtual bool init() override;

    // ʵ�ֲ�������
    virtual void produce() override;

    // �������з���
    void cluck(); // ������

    // ��������
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // ���Ʒ���
    void heal(int amount);

    bool isWalking_ = false; // �Ƿ����ƶ�״̬
};

#endif // CHICKEN_H