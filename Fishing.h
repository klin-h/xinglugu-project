#ifndef __FISHING_H__
#define __FISHING_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class FishingLayer : public Layer
{
public:
    // �������������
    FishingLayer();
    virtual ~FishingLayer();

    // ���� FishingLayer ʵ��
    static FishingLayer* createLayer();

    // ��ʼ�� FishingLayer
    virtual bool init();

    // �����������
    void startFishing();

    // ���½�����
    void updateProgressBar(float dt);

    // ��ť����¼�����ʼ����
    void onFishingButtonClicked(Ref* sender);

    // ����ɹ���Ĵ���
    void onFishCaught();

    // ����ʧ�ܺ�Ĵ���
    void onFishMissed();

private:
    ProgressTimer* m_progressBar;   // ������
    Label* m_infoLabel;             // ��Ϣ��ǩ
    MenuItemImage* m_startButton;   // ��ʼ���㰴ť
    bool m_isFishingInProgress;     // �Ƿ����ڵ���
    float m_fishingProgress;        // �������
};

#endif // __FISHING_H__