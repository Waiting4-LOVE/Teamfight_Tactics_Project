#include"iceFire.h"

iceFire::iceFire() {
	type = IceFire;
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

iceFire* iceFire::createhero() {
	//auto iceFire = new iceFire();
	//iceFire->set(100, 100);
	auto iceFire = iceFire::create();
	auto temp = Sprite::create("iceFire.png");
	temp->setScale(2.5);
	iceFire->bloodBar->setBarChangeRate(Point(1, 0));
	iceFire->bloodBar->setType(ProgressTimer::Type::BAR);
	iceFire->bloodBar->setMidpoint(Point(0, 1));
	iceFire->bloodBar->setScaleX(0.22);
	iceFire->scheduleUpdate();
	//iceFire->addChild(iceFire->bloodBar, 2);
	//iceFire->picturename = "iceFire.png";
	iceFire->addChild(temp);

	iceFire->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	//iceFire->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / iceFire->speedAttack);
	iceFire->autorelease();
	return iceFire;
}


void iceFire::releaseSkill() {

}

_2star_iceFire::_2star_iceFire() {
	//填写二星英雄的属性
}

_2star_iceFire* _2star_iceFire::createhero() {
	auto _2star_iceFire = _2star_iceFire::create();
	_2star_iceFire->picturename = "";
	_2star_iceFire->picturenum = 0;
	_2star_iceFire->autorelease();
	return _2star_iceFire;
}

_3star_iceFire::_3star_iceFire() {
	//填写三星英雄的属性
}

_3star_iceFire* _3star_iceFire::createhero() {
	auto _3star_iceFire = _3star_iceFire::create();
	_3star_iceFire->autorelease();
	return _3star_iceFire;
}