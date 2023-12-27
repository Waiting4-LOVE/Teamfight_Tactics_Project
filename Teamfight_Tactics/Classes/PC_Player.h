#pragma once
#include"cocos2d.h"
#include"Equipment.h"
#include"equipmentFile.h"
#include"ShopLayer.h"

USING_NS_CC;

class PC_Player {
public:
	hero* pcSoldHero(); //PC��Ӣ��
private:
	int pcJudgeMoneyUsage(); //PC�������ʹ�÷�ʽ
	bool CheckHeroUpgrade(); //����Ƿ�������
	bool CheckFightArrLimit(); //���PC��Ӣ���Ƿ�������ս������������������
	void CheckBuyExp(); //����Ƿ���з�exp������������������
	int CheckGoldInterest(); //����Ƿ񿿽���Ϣ��
	bool CheckHighFeeHero(); //��߷�Ӣ��
	bool pcBuyHero(int j); //PC��Ӣ��
	void pcCreateBattleArray(); //ѡӢ���ϳ�����������ԭ��
	void pcEquipment(); //�������װ��
	void refresh(littleHero& lh); //����

	friend class GameScene;
};

extern PC_Player pc_player;