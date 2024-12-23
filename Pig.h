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
    // 构造函数
    Pig();

    // 虚析构函数
    virtual ~Pig();

    static Pig* create();
    virtual bool init() override;

    // 实现产出方法
    virtual void produce() override;

    // 猪的特有方法
    void oink(); // 猪叫声

    // 动画控制
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 治疗方法
    void heal(int amount);

    bool isWalking_ = false; // 是否在移动状态
};


class Sheep : public Animal {
public:
    // 构造函数和析构函数
    Sheep();
    virtual ~Sheep();

    // 重写父类的纯虚函数 produce
    virtual void produce() override;

    // 羊叫
    void bleat();

    // 启动行走动画
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 创建 Sheep 实例
    static Sheep* create();

    // 初始化函数
    virtual bool init() override;
    bool isWalking_ = false; // 是否在移动状态
};

class Dog : public Animal {
public:
    // 构造函数和析构函数
    Dog();
    virtual ~Dog();

    // 重写父类的纯虚函数 produce
    virtual void produce() override;

    // 狗叫
    void bark();

    // 启动行走动画
    virtual void startWalkingAnimation() override;

    // 创建 Dog 实例
    static Dog* create();

    // 初始化函数
    virtual bool init() override;
};



class Rabbit : public Animal {
public:
    // 构造函数和析构函数
    Rabbit();
    virtual ~Rabbit();

    // 重写父类的纯虚函数 produce
    virtual void produce() override;

    // 兔子跳跃
    void hop();

    // 启动和停止行走动画
    virtual void startWalkingAnimation() override;
    virtual void stopWalkingAnimation() override;

    // 创建 Rabbit 实例
    static Rabbit* create();

    // 初始化函数
    virtual bool init() override;

private:
    bool isWalking_ = false; // 是否在移动状态
};




#endif // PIG_H
