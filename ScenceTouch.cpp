/****************************************************************
 * Project Name: xinglugu-project
 * File SceneTouch.cpp
 * File Function: Handle touch events to access tile properties.
 * Author: Gao Wenhao
 * Update Date: 2024.12.9
 * License: 
 ****************************************************************/

#include "SceneTouch.h"
#include "cocos2d.h"

using namespace cocos2d;


void replaceTileWithLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

void cultivateLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

void waterLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName);

bool onTouchBegan(Touch* touch, Event* event, cocos2d::TMXTiledMap* map, backPack* pack) {
    // ��ȡ����λ�ã���Ļ���꣩
    Vec2 touchLocation = touch->getLocation();
    CCLOG("Touch location (screen): (%f, %f)", touchLocation.x, touchLocation.y);

    // ��ȡ��ͼ����ʼλ��
    Vec2 mapStartPosition = map->getPosition();
    CCLOG("Map start position: (%f, %f)", mapStartPosition.x, mapStartPosition.y);

    // ��ͼ�����ű�����Ĭ��Ϊ 1.0��
    float mapScale = map->getScale();
    CCLOG("Map scale: %f", mapScale);

    // ��ȡ��ͼ���߼���Ƭ��С�͵�ͼ�ߴ�
    Size tileSize = map->getTileSize();
    CCLOG("Tile size (logical): %f x %f pixels", tileSize.width, tileSize.height);
    Size mapSize = map->getMapSize();
    CCLOG("Map size: %f x %f tiles", mapSize.width, mapSize.height);

    // ������Ƭ��С��ʵ����Ⱦ�ߴ磨�������ű�����
    float adjustedTileWidth = tileSize.width * mapScale;
    float adjustedTileHeight = tileSize.height * mapScale;
    CCLOG("Tile size (actual): %f x %f pixels", adjustedTileWidth, adjustedTileHeight);

    // �����������Ļ����ת��Ϊ����ڵ�ͼ������
    Vec2 mapLocation = touchLocation - mapStartPosition;
    CCLOG("Converted map location (relative to map): (%f, %f)", mapLocation.x, mapLocation.y);

    // ȷ���������ڵ�ͼ��Χ��
    if (mapLocation.x < 0 || mapLocation.y < 0 ||
        mapLocation.x >= mapSize.width * adjustedTileWidth ||
        mapLocation.y >= mapSize.height * adjustedTileHeight) {
        CCLOG("Touch location is outside the map.");
        return false;
    }

    // ���㴥�������ڵ���Ƭ����
    int tileX = static_cast<int>(mapLocation.x / adjustedTileWidth);
    int tileY = static_cast<int>((mapSize.height * adjustedTileHeight - mapLocation.y) / adjustedTileHeight);
    CCLOG("Tile coordinates: (%d, %d)", tileX, tileY);
    Vec2 tileCoord(tileX, tileY);
    // ��ȡ��Ƭ�� GID

    // �ȼ�����¼��Ƿ�����path�㣨������������㣩
    TMXLayer* layer = map->getLayer("path"); // �滻Ϊ���ͼ����
    if (!layer) {
        CCLOG("Layer not found!");
        return false;
    }
    
    int gid = layer->getTileGIDAt(Vec2(tileX, tileY));
    if (gid <= 0) {
        CCLOG("No tile at this location.");
        return false;
    }
    CCLOG("GID %d",gid );
    // �����Ƭ����
   
    Value propertiesValue = map->getPropertiesForGID(gid);
  
    if (propertiesValue.getType() == Value::Type::MAP) {
        ValueMap properties = propertiesValue.asValueMap();

        // �������Բ���ӡ������Ϣ
        for (const auto& property : properties) {
            CCLOG("Property key: %s, value: %s", property.first.c_str(), property.second.asString().c_str());
        }

        // ��ȡ type ����
        auto typeIter = properties.find("type");
        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
            std::string type = typeIter->second.asString();

            // ��ȡ walkable ���� (�����Ҫ������Ӷ����߼�����ǰʾ����δ�õ�)
            //auto walkableIter = properties.find("walkable");
            //bool walkable = false; // Ĭ��ֵ
            //if (walkableIter != properties.end() && walkableIter->second.getType() == Value::Type::BOOLEAN) {
            //    walkable = walkableIter->second.asBool();
            //}

            // �жϹ��ߺ� type ����
            std::string currentTool = pack->handInItemOut(); // ��ȡ��ǰ����
            if (type == "stone" && currentTool == "pickaxe") {
                CCLOG("Breaking stone with pickaxe");
                replaceTileWithLand(tileCoord, map, "grb");

                // �򱳰������Ʒ
                return true;
            }
            else if (type == "branch" && currentTool == "axe") {
                CCLOG("Chopping branch with axe");
                replaceTileWithLand(tileCoord, map, "grb");
                // �򱳰������Ʒ
                return true;
            }
            else if (type == "grass" && currentTool == "sickle") {
                CCLOG("Cutting grass with sickle");
                replaceTileWithLand(tileCoord, map, "grb");
                // �򱳰������Ʒ
                return true;
            }
            else if (type == "empty" && currentTool == "hoe") {
                cultivateLand(tileCoord, map, "landmateri");
                CCLOG("The object has been moved");
                return true;
               
            }
            else {
                CCLOG("Tool does not match type or no valid type found");
                if (type != "empty") {
                    return true;
                }
            }
        }
        else {
            CCLOG("No valid 'type' property found or type is not a string");
        }
    }
    else {
        CCLOG("Properties for GID %d are not of type MAP or do not exist", gid);
    }
   
    // �ڼ�����¼��Ƿ��������ز�
    layer = map->getLayer("farmland"); 
    if (!layer) {
        CCLOG("Layer farm land not found!");
        return false;
    }
    std::string currentTool = pack->handInItemOut(); // ��ȡ��ǰ����
    gid = layer->getTileGIDAt(Vec2(tileX, tileY));

    if (gid <= 0) {
        CCLOG("No tile at this location.");
        if (currentTool == "hoe") {
            cultivateLand(tileCoord, map, "landmateri");
            CCLOG("cultivate the Land");
        }
        return false;
    }
   
    Value propertiesValuetwo = map->getPropertiesForGID(gid);
    // ȷ�����Դ��ڲ����� ValueMap ����
    if (propertiesValuetwo.getType() == Value::Type::MAP) {
        ValueMap properties = propertiesValuetwo.asValueMap();

        // �������Բ���ӡ������Ϣ
        for (const auto& property : properties) {
            CCLOG("Property key: %s, value: %s", property.first.c_str(), property.second.asString().c_str());
        }

        // ��ȡ type ����
        auto typeIter = properties.find("type");
        if (typeIter != properties.end() && typeIter->second.getType() == Value::Type::STRING) {
            std::string type = typeIter->second.asString();
            // �жϹ��ߺ� type ����
            //std::string currentTool = pack->handInItemOut(); // ��ȡ��ǰ����
            if (type == "farm_land_unwater" && currentTool == "wateringcan") {
                CCLOG("Watering land");
                waterLand(tileCoord, map, "landmateri");
                return true;
            }
            else if (currentTool == "hoe") {
                cultivateLand(tileCoord, map, "landmateri");
                return true;
                CCLOG("cultivate the Land");
            }
            else {
                CCLOG("Tool does not match type or no valid type found");
            }
        }

    }
    else {
        CCLOG("Properties for GID %d are not of type MAP or do not exist", gid);      
    }


    return true;
}

void replaceTileWithLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {
    // ��ȡҪ���滻��ͼ�㣨�̶�Ϊ "path"��
    Vec2 materialTileCoord(5,0);
    auto targetLayer = map->getLayer("path");
    if (!targetLayer) {
        CCLOG("Layer 'path' not found!");
        return;
    }

    // ��ȡ�滻�ز����ڵ�ͼ��
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // ���ز�ͼ���л�ȡ�滻�زĵ� GID
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // ��Ŀ��ͼ���������µ� GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);

    targetLayer->setTileGID(materialGID, tileCoord);

    // ��ȡĿ��ͼ���ж�Ӧλ�õ� Sprite
    auto tileSprite = targetLayer->getTileAt(tileCoord);
    if (tileSprite) {
        // ����͸����Ϊ 0
        tileSprite->setOpacity(0);
        CCLOG("Set opacity of tile at (%d, %d) to 0.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }
    else {
        CCLOG("No sprite found at (%d, %d) in 'path' layer.",
            static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y));
    }

    CCLOG("Replaced tile at (%d, %d) in 'path' layer with tile from '%s' layer at (%d, %d), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), materialGID);
}

void cultivateLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {
    
    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("Layer 'farmland' not found!");
        return;
    }

    // ��ȡ�ز�ͼ��
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // ���ز�ͼ���л�ȡ (0, 0) �� GID
    Vec2 materialTileCoord(0, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // ��Ŀ��ͼ���������µ� GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Cultivated land at (%d, %d) in 'path' layer with tile from '%s' layer at (0, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
}

void waterLand(const Vec2& tileCoord, TMXTiledMap* map, const std::string& layerName) {

    auto targetLayer = map->getLayer("farmland");
    if (!targetLayer) {
        CCLOG("Layer 'farmland' not found!");
        return;
    }

    // ��ȡ�ز�ͼ��
    auto materialLayer = map->getLayer(layerName);
    if (!materialLayer) {
        CCLOG("Layer '%s' not found!", layerName.c_str());
        return;
    }

    // ���ز�ͼ���л�ȡ (0, 0) �� GID
    Vec2 materialTileCoord(1, 0);
    int materialGID = materialLayer->getTileGIDAt(materialTileCoord);
    if (materialGID == 0) {
        CCLOG("No tile found at (%d, %d) in layer '%s'",
            static_cast<int>(materialTileCoord.x), static_cast<int>(materialTileCoord.y), layerName.c_str());
        return;
    }

    // ��Ŀ��ͼ���������µ� GID
    targetLayer->setTileGID(materialGID, tileCoord);

    CCLOG("Water land at (%d, %d) in 'path' layer with tile from '%s' layer at (0, 0), GID: %d",
        static_cast<int>(tileCoord.x), static_cast<int>(tileCoord.y),
        layerName.c_str(), materialGID);
}