#include "Land.h"
USING_NS_CC;

// �������ض���
Land* Land::create(const std::string& filename) {
    Land* land = new (std::nothrow) Land();
    if (land && land->initWithFile(filename)) {
        land->autorelease();
        return land;
    }
    CC_SAFE_DELETE(land);
    return nullptr;
}

// ���صĽ����߼�
void Land::interact() {
    switch (state) {
        case State::Empty:
            state = State::Planted;
            this->setTexture("land_planted.png");
            //adjustScale();  // �������ű���
            break;
        case State::Planted:
            state = State::Watered;
            this->setTexture("land_watered.png");
            //adjustScale();  // �������ű���
            break;
        case State::Watered:
            state = State::Harvested;
            this->setTexture("land_empty.png");
            //adjustScale();  // �������ű���
            break;
        case State::Harvested:
            state = State::Empty;
            // ����Ҫ��������ʱ������ adjustScale
            break;
    }
}
//void Land::adjustScale() {
//    auto textureSize = this->getContentSize();
//    float scaleX = tileSize / textureSize.width;
//    float scaleY = tileSize / textureSize.height;
//    this->setScaleX(scaleX);
//    this->setScaleY(scaleY);
//}