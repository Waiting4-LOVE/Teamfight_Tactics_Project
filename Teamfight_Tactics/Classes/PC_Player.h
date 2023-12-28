#pragma once
#include"cocos2d.h"
#include"Equipment.h"
#include"equipmentFile.h"
#include"ShopLayer.h"

USING_NS_CC;

class PC_Player {
public:
	hero* pcSoldHero(); //PC��Ӣ��
	int pcJudgeMoneyUsage(); //PC�������ʹ�÷�ʽ
	bool CheckHeroUpgrade(); //����Ƿ�������
	bool CheckFightArrLimit(); //���PC��Ӣ���Ƿ�������ս������������������
	void CheckBuyExp(); //����Ƿ���з�exp������������������
	bool CheckGoldInterest(); //����Ƿ񿿽���Ϣ��
	bool CheckHighFeeHero(); //��߷�Ӣ��
	bool pcBuyHero(int selected); //PC��Ӣ��
	void pcCreateBattleArray(); //ѡӢ���ϳ�����������ԭ��
	void pcEquipment(); //�������װ��
	void refresh(littleHero& lh); //����

	friend class GameScene;
};

extern PC_Player pc_player;