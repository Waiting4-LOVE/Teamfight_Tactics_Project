
#pragma once
#include "cocos2d.h"
#include <unordered_map>
using namespace cocos2d;

class myDatabase {
public:
	void insertData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //插入数据
	void updataData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //更新位置
	void delData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos); //删除数据
	int getnum();//数据个数
	Vec2 getVec2(Sprite*& sp);
	std::vector<Sprite*>d_sprite;
private:
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2> heroData;
}static database;
