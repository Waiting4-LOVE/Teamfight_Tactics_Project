#include "goldenMonster.h"

goldenMonster::goldenMonster() {
	type = GoldenMonster;
	maxHealthPoint = 750;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 2;
	name = "GoldenMonster";
	HealthPoint = 750;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.6f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
}

goldenMonster* goldenMonster::createhero() {
	//auto goldenMonster = new goldenMonster();
	//goldenMonster->set(100, 100);
	auto goldenMonster = goldenMonster::create();
	auto temp = Sprite::create("goldenMonster.png");
	temp->setScale(2.5);
	goldenMonster->bloodBar->setBarChangeRate(Point(1, 0));
	goldenMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	goldenMonster->bloodBar->setMidpoint(Point(0, 1));
	goldenMonster->bloodBar->setScaleX(0.22);
	goldenMonster->scheduleUpdate();
	//goldenMonster->addChild(goldenMonster->bloodBar, 2);
	//goldenMonster->picturename = "goldenMonster.png";
	goldenMonster->addChild(temp);

	goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / goldenMonster->speedAttack);
	goldenMonster->autorelease();
	return goldenMonster;
}


void goldenMonster::releaseSkill() {

}

_2star_goldenMonster::_2star_goldenMonster() {
	//填写二星英雄的属性
	type = GoldenMonster;
	maxHealthPoint = 1350;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 2;
	name = "GoldenMonster";
	HealthPoint = 750;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.6f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
}

_2star_goldenMonster* _2star_goldenMonster::createhero() {
	auto _2star_goldenMonster = _2star_goldenMonster::create();
	_2star_goldenMonster->picturename = "";
	_2star_goldenMonster->picturenum = 0;
	_2star_goldenMonster->autorelease();
	return _2star_goldenMonster;
}

_3star_goldenMonster::_3star_goldenMonster() {
	//填写三星英雄的属性
	type = GoldenMonster;
	maxHealthPoint = 2430;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 2;
	name = "GoldenMonster";
	HealthPoint = 750;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.6f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
}

_3star_goldenMonster* _3star_goldenMonster::createhero() {
	auto _3star_goldenMonster = _3star_goldenMonster::create();
	_3star_goldenMonster->autorelease();
	return _3star_goldenMonster;
}