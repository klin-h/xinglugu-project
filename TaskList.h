#include "cocos2d.h"

// ����ṹ��
struct Task {
    std::string taskDescription;  // ��������
    int targetItemCount;          // Ŀ���ռ���Ʒ����
    int rewardDescription; // ����������
    bool completed;               // �����Ƿ����
};