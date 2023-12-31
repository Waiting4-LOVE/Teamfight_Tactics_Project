#pragma once
#include"cocos2d.h"
#include"littleHero.h"
#include"hero.h"
#include"HeroLayer.h"
#include"battleMap.h"
USING_NS_CC;

class OnlineGameData {
public:
	//��ȡ��������
	void getData();
	//���л�
	std::string serializeGameData();
	//�����л�
	OnlineGameData deserializeGameData(const std::string& serializedData);
	//ת��Ϊplayer2������
	void toPlayer2Data();
private:
	int m_blood;
	int fightNum, playerNum;//���м���
	std::vector<int> m_ArrayTypes;  // ������ֻ��Ҫ������Ϣ
	std::vector<float> m_ArrayX;//λ��
	std::vector<float> m_ArrayY;
};
extern OnlineGameData onlineGameData;