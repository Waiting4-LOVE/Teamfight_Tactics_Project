#pragma once
#include"cocos2d.h"
#include"littleHero.h"
#include"hero.h"
#include"HeroLayer.h"
#include"battleMap.h"
USING_NS_CC;

class OnlineGameData {
public:
	//获取本机数据
	void getData();
	//序列化
	std::string serializeGameData();
	//反序列化
	OnlineGameData deserializeGameData(const std::string& serializedData);
	//转化为player2的数据
	void toPlayer2Data();
private:
	int m_blood;
	int fightNum, playerNum;//各有几人
	std::vector<int> m_ArrayTypes;  // 假设你只需要类型信息
	std::vector<float> m_ArrayX;//位置
	std::vector<float> m_ArrayY;
};
extern OnlineGameData onlineGameData;