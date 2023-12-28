#include"gargomon.h"

gargomon::gargomon() {
	type = Gargomon;
	maxHealthPoint = 10000;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao don't know";
	HealthPoint = 100000;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

gargomon* gargomon::createhero() {
	//auto gargomon = new gargomon();
	//gargomon->set(100, 100);
	auto gargomon = gargomon::create();
	auto temp = Sprite::create("gargomon.png");
	temp->setScale(2.5);
	gargomon->bloodBar->setBarChangeRate(Point(1, 0));
	gargomon->bloodBar->setType(ProgressTimer::Type::BAR);
	gargomon->bloodBar->setMidpoint(Point(0, 1));
	gargomon->bloodBar->setScaleX(0.22);
	gargomon->scheduleUpdate();
	//gargomon->addChild(gargomon->bloodBar, 2);
	//gargomon->picturename = "gargomon.png";
	gargomon->addChild(temp);

	gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / gargomon->speedAttack);
	gargomon->autorelease();
	return gargomon;
}


void gargomon::releaseSkill() {

}

_2star_gargomon::_2star_gargomon() {
	//填写二星英雄的属性
}

_2star_gargomon* _2star_gargomon::createhero() {
	auto _2star_gargomon = _2star_gargomon::create();
	_2star_gargomon->picturename = "";
	_2star_gargomon->picturenum = 0;
	_2star_gargomon->autorelease();
	return _2star_gargomon;
}

_3star_gargomon::_3star_gargomon() {
	//填写三星英雄的属性
}

_3star_gargomon* _3star_gargomon::createhero() {
	auto _3star_gargomon = _3star_gargomon::create();
	_3star_gargomon->autorelease();
	return _3star_gargomon;
}