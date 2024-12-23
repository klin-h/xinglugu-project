/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC.h
 * File Function:
 * Author: Sun Yining
 * Update Date: 2024.12.7
 * License:
 ****************************************************************/
#ifndef NPC_H
#define NPC_H


#include "Character.h"

#include "GameScenePlayer.h"
#include "ui/CocosGUI.h"
#include <vector>



// NPC�࣬�̳��Խ�ɫ��
class NPC : public Character {
public:
    NPC();
    virtual ~NPC();
   
    NPC(const std::string& name, int health);
   
    // NPC�ṩ�Ի����ݵķ���
    std::string getDialogue();

private:
   
    bool isPlayerInRange;
   
    
    std::string dialogueText;  // ��¼�Ի����ݵ��ַ�������

    // ʹ�ýṹ������ʾһ������ĸ�������
    struct QuestInfo {
        std::string name;  // ��������
        std::string description;  // ��������
        int difficulty;  // �����Ѷȵȼ�
        bool completed;  // �����Ƿ�����ɣ������ڼ�¼����״̬
    };
    std::vector<QuestInfo> quests;

};

#endif

