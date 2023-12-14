#include "database.h"

void myDatabase::insertData(cocos2d::Sprite* sp, cocos2d::Vec2 pos) {
	this->heroData.insert({ sp,pos });
}

void myDatabase::updataData(cocos2d::Sprite* sp, cocos2d::Vec2 pos) {
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2>::iterator it;
	it = this->heroData.find(sp);
	(*it).second = pos;
}

void myDatabase::delData(cocos2d::Sprite* sp, cocos2d::Vec2 pos) {
	this->heroData.erase(sp);
}