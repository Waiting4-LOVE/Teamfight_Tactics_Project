#pragma once
#include "cocos2d.h"
#include <unordered_map>

class myDatabase {
public:
	void insertData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //插入数据
	void updataData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //更新位置
	void delData(cocos2d::Sprite* sp, cocos2d::Vec2 pos); //删除数据
private:
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2> heroData;
};
