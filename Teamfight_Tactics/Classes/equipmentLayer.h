#ifndef __EQUIPMENT_LAYER_H__
#define __EQUIPMENT_LAYER_H__
#pragma once
#include"cocos2d.h"
#include"equipmentFile.h"
#include"littleHero.h"
#include"GameData.h"

class EquipmentLayer:public cocos2d::Layer {
public:
    //EquipmentLayer();
    static EquipmentLayer* createSelectLayer();

    virtual bool init();
    void update(float dt);

    Vec2 eptInSelectPos[4] = { Vec2(730, 500),Vec2(915,500),Vec2(730,200),Vec2(915,200) };

    CREATE_FUNC(EquipmentLayer);
};
extern littleHero MyLittleHero, player2data;
#endif
