#include"wildBoar.h"

wildBoar::wildBoar() {
	type = WildBoar;
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
	distanceAttack = 5;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

wildBoar* wildBoar::createhero() {
	//auto wildBoar = new wildBoar();
	//wildBoar->set(100, 100);
	auto wildBoar = wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	wildBoar->bloodBar->setBarChangeRate(Point(1, 0));
	wildBoar->bloodBar->setType(ProgressTimer::Type::BAR);
	wildBoar->bloodBar->setMidpoint(Point(0, 1));
	wildBoar->bloodBar->setScaleX(0.22);
	wildBoar->scheduleUpdate();
	//wildBoar->addChild(wildBoar->bloodBar, 2);
	//wildBoar->picturename = "wildBoarpng";
	wildBoar->addChild(temp);

	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / wildBoar->speedAttack);
	wildBoar->autorelease();
	return wildBoar;
}


void wildBoar::releaseSkill() {

}

_2star_wildBoar::_2star_wildBoar() {
	//填写二星英雄的属性
}

_2star_wildBoar* _2star_wildBoar::createhero() {
	auto _2star_wildBoar = _2star_wildBoar::create();
	_2star_wildBoar->picturename = "";
	_2star_wildBoar->picturenum = 0;
	_2star_wildBoar->autorelease();
	return _2star_wildBoar;
}

_3star_wildBoar::_3star_wildBoar() {
	//填写三星英雄的属性
}

_3star_wildBoar* _3star_wildBoar::createhero() {
	auto _3star_wildBoar = _3star_wildBoar::create();
	_3star_wildBoar->autorelease();
	return _3star_wildBoar;
}