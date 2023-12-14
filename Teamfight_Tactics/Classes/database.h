#pragma once
#include "cocos2d.h"
#include <unordered_map>

class myDatabase {
public:
	void insertData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //��������
	void updataData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //����λ��
	void delData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //ɾ������
private:
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2> heroData;
};
