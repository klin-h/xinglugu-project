#ifndef MAPCONTROL_H
#define MAPCONTROL_H

#include "cocos2d.h"
#include <vector>
#include "SceneTouch.h"
#include "Constants.h"
#include "WalkingCharacter.h"


using namespace cocos2d;

// ��ͼ������
class MapControl {
public:
    // ���캯��
    MapControl(Node* parent, float mapScale, const std::vector<std::string>& mapFiles);

    // �л���ͼ
    void switchMap(size_t mapIndex, const Vec2& spawnPoint);

    // ���浱ǰ��ͼ״̬
    void saveCurrentMapState();

    // �ָ���ͼ״̬
    void restoreMapState(size_t mapIndex);

    // ��������Ƿ�����Ļ��Χ��
    bool isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize);

    // ��ȡ��ǰ��ͼ
    TMXTiledMap* getCurrentMap() const;

private:
    TMXTiledMap* currentMap; // ��ǰ��ͼ
    std::vector<TMXTiledMap*> maps; // �������е�ͼָ��
    size_t currentMapIndex; // ��ǰ��ͼ����
    Node* parentNode; // ���ڵ�
    float mapScale; // ��ͼ���ű���
};

#endif // MAPCONTROL_H