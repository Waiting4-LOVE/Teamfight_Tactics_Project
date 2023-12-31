#pragma once
#ifndef __EQUIPMENT_SCENE_H__
#define __EQUIPMENT_SCENE_H__

#include "cocos2d.h"
#include "equipmentLayer.h"
#include "RoundTimer.h"
#include "BattleScene.h"
#include "Definition.h"
USING_NS_CC;

class EquipmentScene :public cocos2d::Scene {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

private:
	/**********计时器及Update**************/

	int MouseToEpt = -1;

	/************选择装备函数**************/
	Equipment* equipmentCreate(int select);
	void eptSelect();
	void refresh(littleHero& lh);
	void select1(cocos2d::Ref* pSender);
	void select2(cocos2d::Ref* pSender);
	void select3(cocos2d::Ref* pSender);
	void select4(cocos2d::Ref* pSender);

	void GotoBattleScene(cocos2d::Ref* pSender)
	{
		auto scene = BattleScene::createScene();
		Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_TIME, scene));
	}

	Vec2 eptInSelectPos[4] = { Vec2(730, 500),Vec2(915,500),Vec2(730,200),Vec2(915,200) };



	CREATE_FUNC(EquipmentScene);
};
#endif