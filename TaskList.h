#include "cocos2d.h"

// ����ṹ��
struct Task {
    std::string taskDescription;  // ��������
    int targetItemCount;          // Ŀ���ռ���Ʒ����
    int currentItemCount;         // ��ǰ�ռ���Ʒ����
    std::string rewardDescription; // ����������
    bool completed;               // �����Ƿ����
};