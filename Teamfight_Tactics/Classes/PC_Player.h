#pragma once
#include"cocos2d.h"
#include"Equipment.h"
#include"equipmentFile.h"
#include"ShopLayer.h"

USING_NS_CC;

class PC_Player {
public:
	hero* pcSoldHero(); //PC卖英雄
	int pcJudgeMoneyUsage(); //PC决定金币使用方式
	bool CheckHeroUpgrade(); //检查是否能升星
	bool CheckFightArrLimit(); //检查PC的英雄是否能塞满战斗区，不能则买棋子
	void CheckBuyExp(); //检查是否与敌方exp相差过大，若过大则买经验
	bool CheckGoldInterest(); //检查是否靠近利息点
	bool CheckHighFeeHero(); //买高费英雄
	bool pcBuyHero(int selected); //PC买英雄
	void pcCreateBattleArray(); //选英雄上场：星数优先原则
	void pcEquipment(); //快速随机装备
	void refresh(littleHero& lh); //更新

	friend class GameScene;
};

extern PC_Player pc_player;