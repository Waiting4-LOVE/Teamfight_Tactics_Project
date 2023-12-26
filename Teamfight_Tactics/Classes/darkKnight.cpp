#include "darkKnight.h"

darkKnight::darkKnight() {
	type = DarkKnight;
	maxHealthPoint = 100;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao don't know";
	HealthPoint = 100;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.7f;
	distanceAttack = 225;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

darkKnight* darkKnight::createhero() {
	//auto darkKnight = new darkKnight();
	//darkKnight->set(100, 100);
	auto darkKnight = darkKnight::create();
	auto temp = Sprite::create("darkKnight.png");
	temp->setScale(0.22);
	darkKnight->bloodBar->setBarChangeRate(Point(1, 0));
	darkKnight->bloodBar->setType(ProgressTimer::Type::BAR);
	darkKnight->bloodBar->setMidpoint(Point(0, 1));
	darkKnight->bloodBar->setScaleX(0.22);
	darkKnight->scheduleUpdate();
	//darkKnight->addChild(hero1->bloodBar, 2);
	//darkKnight->picturename = "hero1.png";
	darkKnight->addChild(temp);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / darkKnight->speedAttack);
	darkKnight->autorelease();
	return darkKnight;
}


void darkKnight::releaseSkill() {

}

_2star_darkKnight::_2star_darkKnight() {
	//填写二星英雄的属性
}

_2star_darkKnight* _2star_darkKnight::createhero() {
	auto _2star_darkKnight = _2star_darkKnight::create();
	_2star_darkKnight->picturename = "";
	_2star_darkKnight->picturenum = 0;
	_2star_darkKnight->autorelease();
	return _2star_darkKnight;
}

_3star_darkKnight::_3star_darkKnight() {
	//填写三星英雄的属性
}

_3star_darkKnight* _3star_darkKnight::createhero() {
	auto _3star_darkKnight = _3star_darkKnight::create();
	_3star_darkKnight->autorelease();
	return _3star_darkKnight;
}