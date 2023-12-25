
#pragma once
#include "cocos2d.h"
#include <unordered_map>
using namespace cocos2d;

class myDatabase {
public:
	void insertData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //��������
	void updataData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //����λ��
	void delData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //ɾ������
	int getnum();//���ݸ���
	Vec2 getVec2(Sprite*& sp);
	std::vector<Sprite*>d_sprite;
private:
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2> heroData;
}static database;
