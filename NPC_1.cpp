/****************************************************************
 * Project Name: xinglugu-project
 * File:NPC_1.cpp
 * File Function:
 * Author: Sun Yining Gao Wenhao
 * Update Date: 2024.12.15
 * License:
 ****************************************************************/
#include "NPC_1.h"
#include "Walking.h"
#include"string"
#include "Constants.h"
#include "MapControl.h"
#include "ui/CocosGUI.h"
#include "GlobalVariables.h"

Vec2 convertToScreenOrigin(const Vec2& position, const Size& visibleSize) {
    // ԭ��ת����ʽ
    float x = position.x + (visibleSize.width / 2 - 8);
    float y = -position.y + (visibleSize.height / 2 - 8) - 16;

    return Vec2(x, y);
}


void NPC_1::moveUp(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x, tileCoord.y - 1); // �����ƶ� y-1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 1);
        Endposition.y -= movelength;
        npc_1_d = 'b';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 1);
                Endposition.y -= movelength;
                npc_1_d = 'b';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 1);
            Endposition.y -= movelength;
            npc_1_d = 'b';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 1);
        Endposition.y -= movelength;
        npc_1_d = 'b';
    }
}
void NPC_1::moveDown(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x, tileCoord.y + 1); // �����ƶ� y+1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 0);
        Endposition.y += movelength;
        npc_1_d = 'f';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 0);
                Endposition.y += movelength;
                npc_1_d = 'f';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 0);
            Endposition.y += movelength;
            npc_1_d = 'f';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 0);
        Endposition.y += movelength;
        npc_1_d = 'f';
    }
}
void NPC_1::moveLeft(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x - 1, tileCoord.y); // �����ƶ� x-1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 2);
        Endposition.x -= movelength;
        npc_1_d = 'l';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 2);
                Endposition.x -= movelength;
                npc_1_d = 'l';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 2);
            Endposition.x -= movelength;
            npc_1_d = 'l';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 2);
        Endposition.x -= movelength;
        npc_1_d = 'l';
    }
}
void NPC_1::moveRight(Vec2& Endposition, TMXTiledMap* map, float movelength, Sprite* sprite, char& npc_1_d, Size visibleSize) {
    Vec2 currentPosition = Endposition;
    CCLOG("NPC Current screen position: (%f, %f)", currentPosition.x, currentPosition.y);
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
    CCLOG("NPC Screen coordinate: (%f, %f)", screenCoord.x, screenCoord.y);
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, map);

    if (tileCoord == Vec2(-1, -1)) {
        CCLOG("Current position is outside the map bounds.");
        return;
    }
    CCLOG("Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);

    Vec2 targetTileCoord = Vec2(tileCoord.x + 1, tileCoord.y); // �����ƶ� x+1
    CCLOG("Target tile coordinate: (%f, %f)", targetTileCoord.x, targetTileCoord.y);

    TMXLayer* pathLayer = map->getLayer("path");
    if (!pathLayer) {
        CCLOG("Path layer not found!");
        return;
    }

    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    if (gid <= 0) {
        CCLOG("GID is invalid or no tile at (%f, %f). Moving anyway.", targetTileCoord.x, targetTileCoord.y);
        Character::Moving(sprite, 3);
        Endposition.x += movelength;
        npc_1_d = 'r';
        return;
    }

    Value properties = map->getPropertiesForGID(gid);
    if (properties.getType() == Value::Type::MAP) {
        ValueMap propertiesMap = properties.asValueMap();
        auto walkableIter = propertiesMap.find("walkable");

        if (walkableIter != propertiesMap.end()) {
            std::string walkableStr = walkableIter->second.asString();
            bool walkable = (walkableStr == "true");
            if (walkable) {
                Character::Moving(sprite, 3);
                Endposition.x += movelength;
                npc_1_d = 'r';
            }
            else {
                CCLOG("Cannot move: Target tile at (%f, %f) is not walkable.", targetTileCoord.x, targetTileCoord.y);
            }
        }
        else {
            CCLOG("No 'walkable' property. Moving anyway.");
            Character::Moving(sprite, 3);
            Endposition.x += movelength;
            npc_1_d = 'r';
        }
    }
    else {
        CCLOG("No properties for GID %d. Moving anyway.", gid);
        Character::Moving(sprite, 3);
        Endposition.x += movelength;
        npc_1_d = 'r';
    }
}

NPC_1::NPC_1() {


    sprite = nullptr;

    keyboardListener = nullptr;
    scene = nullptr;
}

NPC_1::~NPC_1() {
    CC_SAFE_RELEASE_NULL(sprite);


    CC_SAFE_RELEASE_NULL(keyboardListener);
}

NPC_1* NPC_1::create() {
    NPC_1* npc = new NPC_1();
    if (npc && npc->init()) {
        npc->autorelease();
        return npc;
    }
    CC_SAFE_DELETE(npc);
    return nullptr;
}

void NPC_1::setup(const Size& visibleSize, Vec2 origin) {
    sprite = Sprite::create("resources/SYN/Abigailf1.png");
    sprite->setScale(Constants::kScale);
    if (sprite) {
        CCLOG("NPC_1 sprite loaded successfully");
    }
    else {
        CCLOG("Failed to load NPC_1 sprite image");
    }
    if (sprite) {
        Vec2 pos;
        pos.x = visibleSize.width / 2 - 8;
        pos.y = visibleSize.height / 2 - 8;
        position = pos;
        sprite->setPosition(position);
        this->addChild(sprite);
        CCLOG("Current screen position: (%f, %f)", pos.x, pos.y);
    }
}

bool isPlayerWithinScreen(const Vec2& position, const Vec2& direction, const Size& visibleSize, const TMXTiledMap* map, float scale) {
    // �������ź�ĵ�ͼ�ߴ�
    Size mapSize = map->getMapSize();
    Size tileSize = map->getTileSize();
    Size mapContentSize = Size(mapSize.width * tileSize.width, mapSize.height * tileSize.height) * scale;
    Vec2 currentPosition = position;
    Vec2 screenCoord = convertToScreenOrigin(currentPosition, visibleSize);
    // ���������ƶ����Ŀ��λ��
    Vec2 targetPosition = screenCoord + direction;

    // ���Ŀ��λ���Ƿ�������Ļ��Χ��
    if (targetPosition.x < 0 || targetPosition.x >= visibleSize.width ||
        targetPosition.y < 0 || targetPosition.y >= visibleSize.height) {
        CCLOG("Player will move out of the screen bounds. Movement blocked.");
        return false;
    }

    // ���Ŀ��λ���Ƿ����ڵ�ͼ��Χ��
    if (targetPosition.x < 0 || targetPosition.x >= mapContentSize.width ||
        targetPosition.y < 0 || targetPosition.y >= mapContentSize.height) {
        CCLOG("Player will move out of the map bounds. Movement blocked.");
        return false;
    }

    return true;
}



void NPC_1::checkAround(const Vec2& Endposition, TMXTiledMap* currentMap, MapControl* mapControl) {
    if (!currentMap) return;
    //Vec2 currentPosition = Endposition;
    Size visibleSize = Director::getInstance()->getVisibleSize(); 
    Vec2 screenCoord = convertToScreenOrigin(Endposition, visibleSize);
   
    Vec2 tileCoord = calculateTileCoordinate(screenCoord, currentMap);
    // ��ȡ��Ƭ��С
    Size tileSize = currentMap->getTileSize();
    CCLOG("CkeckAr::Converted tile coordinate: (%f, %f)", tileCoord.x, tileCoord.y);
    // ����������ת��Ϊ��Ƭ����
    int playerTileX = tileCoord.x;
    int playerTileY = tileCoord.y;

    // ������������������Ƭ������
    Vec2 directions[] = {
        Vec2(0, 1),  // ��
        Vec2(0, -1), // ��
        Vec2(-1, 0), // ��
        Vec2(1, 0)   // ��
    };
   
    if (abs(playerTileX-3)<2 || abs(playerTileY - 5) < 2) {
        CCLOG("Switchto mine map");
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("Switch mine  Map?");
        button->setTitleFontSize(24);
        button->setPosition(Vec2(600,400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE+1);

        // ��ʱ���Ƴ���ť
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // �������ü���
            }, 1.0f, "removeButtonKey");

        // ��ť����¼�
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");

            TMXTiledMap* currentmap;
            TMXTiledMap* aimmap;
            if (g_sharedTMXcurrent == g_sharedTMXone) {
                aimmap= g_sharedTMXtwo;
            }
            else if (g_sharedTMXcurrent == g_sharedTMXtwo) {
                aimmap = g_sharedTMXone;
            }
            else {
                aimmap = g_sharedTMXone;
            }
            // �����µ�ͼ������
            g_sharedTMXtwo ->setPosition(Vec2(0, 0)); // ���õ�ͼ��ʼλ��Ϊ��Ļ���½�
            g_sharedTMXtwo->setScale(currentMap->getScale()); // ���ֺ͵�ǰ��ͼ��ͬ�����ű���
           
            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // ��ӵ����ڵ���
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;
            button->removeFromParent();
            button->release(); // �������ü���
            g_sharedScene->unschedule("removeButtonKey"); // ȡ����ʱ��
            });
       
    }

    if (abs(playerTileX - 78) < 2 && abs(playerTileY - 9) < 2) {
        CCLOG("Switch map");
        auto button = ui::Button::create("button_normal.png", "button_pressed.png");
        button->setTitleText("Switch to forest Map?");
        button->setTitleFontSize(24);
        button->setPosition(Vec2(600, 400));
        button->retain();
        //this->addChild(button,2);
        //this->addChild(button, 2);
        g_sharedScene->addChild(button, Constants::MAP_BACKGROUND_LAYER_Z_SURFACE + 1);

        // ��ʱ���Ƴ���ť
        g_sharedScene->scheduleOnce([button](float) {
            if (button && button->getParent()) {
                CCLOG("Button removed after 3 seconds");
                button->removeFromParent();
            }
            button->release(); // �������ü���
            }, 1.0f, "removeButtonKey");

        // ��ť����¼�
        button->addClickEventListener([=](Ref* sender) {
            CCLOG("Press");

            TMXTiledMap* currentmap;
            TMXTiledMap* aimmap;
            if (g_sharedTMXcurrent == g_sharedTMXone) {
                aimmap = g_sharedTMXthree;
            }
            else if (g_sharedTMXcurrent == g_sharedTMXthree) {
                aimmap = g_sharedTMXone;
            }
            else {
                aimmap = g_sharedTMXone;
            }
            // �����µ�ͼ������
            g_sharedTMXtwo->setPosition(Vec2(0, 0)); // ���õ�ͼ��ʼλ��Ϊ��Ļ���½�
            g_sharedTMXtwo->setScale(currentMap->getScale()); // ���ֺ͵�ǰ��ͼ��ͬ�����ű���

            /*g_sharedTMXcurrent = g_sharedTMXtwo;*/
            // ��ӵ����ڵ���
            g_sharedTMXcurrent->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_BASIC);
            aimmap->setLocalZOrder(Constants::MAP_BACKGROUND_LAYER_Z_SURFACE);
            g_sharedTMXcurrent = aimmap;
            button->removeFromParent();
            button->release(); // �������ü���
            g_sharedScene->unschedule("removeButtonKey"); // ȡ����ʱ��
            });

    }
    // �����������ҵ���Ƭ
    //for (const auto& direction : directions) {
    //    Vec2 targetTileCoord = Vec2(playerTileX, playerTileY) + direction;

    //    // ���Ŀ����Ƭ�Ƿ��ڵ�ͼ��Χ��
    //    if (targetTileCoord.x < 0 || targetTileCoord.y < 0 ||
    //        targetTileCoord.x >= currentMap->getMapSize().width ||
    //        targetTileCoord.y >= currentMap->getMapSize().height) {
    //        continue;
    //    }

    //    // ��ȡĿ����Ƭ�� GID
    //    TMXLayer* pathLayer = currentMap->getLayer("trigger"); // �滻Ϊ����������
    //    if (!pathLayer) {
    //        CCLOG("Trigger layer not found!");
    //        continue;
    //    }

    //    int gid = pathLayer->getTileGIDAt(targetTileCoord);
    //    if (gid <= 0) continue;

    //    // ��ȡĿ����Ƭ������
    //    Value properties = currentMap->getPropertiesForGID(gid);
    //    if (properties.getType() == Value::Type::MAP) {
    //        ValueMap propertiesMap = properties.asValueMap();
    //        auto targetMapIter = propertiesMap.find("targetMap");
    //        auto spawnXIter = propertiesMap.find("spawnX");
    //        auto spawnYIter = propertiesMap.find("spawnY");

    //        if (targetMapIter != propertiesMap.end() &&
    //            spawnXIter != propertiesMap.end() &&
    //            spawnYIter != propertiesMap.end()) {
    //            // ��ʾ��ťѯ������Ƿ��л���ͼ
                //auto button = ui::Button::create("button_normal.png", "button_pressed.png");
                //button->setTitleText("Switch Map?");
                //button->setTitleFontSize(24);
                //button->setPosition(playerSprite->getPosition() + Vec2(0, 50)); // ��ť��ʾ�������Ϸ�
                //parent->addChild(button);

                //// ��ť����¼�
                //button->addClickEventListener([=](Ref* sender) {
                //    // �л���ͼ
                //    std::string targetMap = targetMapIter->second.asString();
                //    Vec2 spawnPoint(spawnXIter->second.asFloat(), spawnYIter->second.asFloat());
                //    mapControl->switchMap(targetMap, spawnPoint, playerSprite);

                //    // �Ƴ���ť
                //    button->removeFromParent();
                //    });

    //            return; // �ҵ�һ��������������Ƭ���������
    //        }
    //    }
    //}

    CCLOG("No valid tile found around the player.");
}

Point Endposition;
char npc_1_d = 'f';
void NPC_1::movebyfour(NPC_1* P, TMXTiledMap* map) {
    keyboardListener = EventListenerKeyboard::create();
    float movelength = 16 * (Constants::kScale);
   
    if (keyboardListener) {
        Size visibleSize = Director::getInstance()->getVisibleSize(); // ��ȡ��Ļ�ɼ��ߴ�
        keyboardListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
            Vec2 currentPosition;
            Vec2 screenCoord;
            Vec2 direction;
            switch (keyCode) {
                case EventKeyboard::KeyCode::KEY_UP_ARROW:
                    direction = Vec2(0, movelength); // �����ƶ�
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveUp(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                    direction = Vec2(0, -movelength); // �����ƶ�
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveDown(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                    direction = Vec2(-movelength, 0); // �����ƶ�
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveLeft(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                    direction = Vec2(movelength, 0); // �����ƶ�
                    if (isPlayerWithinScreen(Endposition, direction, visibleSize, g_sharedTMXcurrent, g_sharedTMXcurrent->getScale())) {
                        moveRight(Endposition, g_sharedTMXcurrent, movelength, sprite, npc_1_d, visibleSize);
                    } 
                    checkAround(Endposition, g_sharedTMXcurrent, mapControl);
                    break;

                default:
                    break;
            }
            };


        Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keyboardListener, 1);


    }
   
   
}


void NPC_1::testAddNPC_1(const Size& visibleSize, Vec2 origin, TMXTiledMap* map, Scene* mainscene) {
    // ����NPC_1����ʵ��
    auto myNpc = NPC_1::create();
    myNpc->setVisible(true);
    this->addChild(myNpc);
    myNpc->setup(visibleSize, origin);
    myNpc->movebyfour(myNpc,map);
    
    if (!mainscene) {
        CCLOG("MainScene pointer is null!");
        return;
    }

    this->scene = mainscene;

}

cocos2d::Vec2 NPC_1::getPosition() {
    return Endposition;
}

char NPC_1::getDirection() {
    return npc_1_d;
}