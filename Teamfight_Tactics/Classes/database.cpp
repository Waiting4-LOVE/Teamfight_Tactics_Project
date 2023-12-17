#include "database.h"
#include <algorithm>

void myDatabase::insertData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos) {
	this->heroData.insert({ sp,pos });
	this->d_sprite.push_back(sp);
}

void myDatabase::updataData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos) {
	std::unordered_map<cocos2d::Sprite*, cocos2d::Vec2>::iterator it;
	it = this->heroData.find(sp);
	(*it).second = pos;
}

void myDatabase::delData(cocos2d::Sprite*& sp, cocos2d::Vec2 pos) {
	this->heroData.erase(sp);
	this->d_sprite.erase(std::find(this->d_sprite.begin(), this->d_sprite.end(), sp));
}

int myDatabase::getnum() {
	return heroData.size();
}

Vec2  myDatabase::getVec2(Sprite*& sp) {
	return this->heroData[sp];
}