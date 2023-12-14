#ifndef __LITTLE_HERO_SPRITE_HPP__
#define __LITTLE_HERO_SPRITE_HPP__

#include "cocos2d.h"
#include <math.h>
USING_NS_CC;

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in littleHero.cpp\n");
}

class littleHero :public Sprite {
public:
	littleHero();
	~littleHero() = 0;
	bool Create(char* filename, int recover); //创建小小英雄并将其放置到舞台上
	void hurt(int delBlood); //受到伤害，减少血量
	void addCoins(int num); //增加金币
	void delCoins(int num); //减少金币
	void addExp(int exp); //增加经验
	void move(Vec2 curPos); //移动小小英雄状态
	bool dead(); //死亡
	void test(); //测试函数
protected:
	Sprite* sp;
	Vec2 m_pos; //当前位置
	int m_maxBlood = 100; //最大血量
	int m_blood; //当前血量，初始为100,
	const int m_moveSpeed = 30; //移动速度
	const int m_upExp = 100; //升级需要的经验值
	int m_coins; //金币
	int m_exp; //经验值
	int m_level; //等级
	int m_recover; //回血量
};

littleHero::littleHero() :m_blood(100), m_moveSpeed(30), m_coins(0), m_exp(0), m_level(1){  }

bool littleHero::Create(char* filename, int recover) {
	this->sp = Sprite::create(filename);
	if (sp == nullptr) problemLoading(filename);
	else {
		auto visibleSize = Director::getInstance()->getVisibleSize();
		this->m_pos = Director::getInstance()->getVisibleOrigin();
		sp->setPosition(Vec2(visibleSize.width / 2 + m_pos.x, visibleSize.height / 2 + m_pos.y)); //放到中间位置
		this->addChild(sp, 0); //加到树中
		this->m_recover = recover;
	}
	return true;
}

void littleHero::hurt(int delBlood) {
	this->m_blood -= delBlood;
}

void littleHero::addCoins(int num) {
	this->m_coins += num;
}

void littleHero::delCoins(int num) {
	this->m_coins -= num;
}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	if (this->m_exp > this->m_upExp) {
		this->m_exp -= this->m_upExp;
		this->m_level++;
	} //升级
}

void littleHero::move(Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //计算移动距离
	double moveSec = dis / this->m_moveSpeed; //得到运动时间
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->sp->runAction(moveTo);
}

bool littleHero::dead() {
	return this->m_blood <= 0;
}

void littleHero::test() {
	printf("==================================\n");
	printf("当前血量：%d\n", this->m_blood);
	printf("当前金币：%d\n", this->m_coins);
	printf("当前经验：%d\n", this->m_exp);
	printf("当前等级：%d\n", this->m_level);
	printf("当前回血量：%d\n", this->m_recover);
	printf("==================================\n");
}
#endif //__LITTLE_HERO_SPRITE_HPP__

