#ifndef __EQUIPMENT_LAYER_H__
#define __EQUIPMENT_LAYER_H__

#include"cocos2d.h"
#include"equipmentFile.h"
#include"littleHero.h"
#include"GameData.h"
#include "resource.h"

class EquipmentLayer:public cocos2d::Layer {
public:
    //EquipmentLayer();
    static EquipmentLayer* createSelectLayer();

    virtual bool init();

	/************选择装备函数**************/
	Equipment* equipmentCreate(int select);
	void eptSelect();
	void refresh(littleHero& lh);
	void select1(cocos2d::Ref* pSender);
	void select2(cocos2d::Ref* pSender);
	void select3(cocos2d::Ref* pSender);
	void select4(cocos2d::Ref* pSender);

    Vec2 eptInSelectPos[4] = { Vec2(1650, 1000),Vec2(1800,1000),Vec2(1650,700),Vec2(1800,700) };

    CREATE_FUNC(EquipmentLayer);
};
extern littleHero MyLittleHero, player2data;
#endif
