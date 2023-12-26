#include"hero2.h"


darkKnight::darkKnight() {
	type = Hero2;
	maxHealthPoint = 100;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao ai shui jiao";
	HealthPoint = 100;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.5;
	distanceAttack = 5;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

hero2* hero2::createhero() {
	//auto Hero1 = new hero1();
	//Hero1->set(100, 100);
	auto hero2 = hero2::create();
	auto temp = Sprite::create("hero2.png");
	temp->setScale(0.22);
	hero2->bloodBar->setBarChangeRate(Point(1, 0));
	hero2->bloodBar->setType(ProgressTimer::Type::BAR);
	hero2->bloodBar->setMidpoint(Point(0, 1));
	hero2->bloodBar->setScaleX(0.22);
	hero2->scheduleUpdate();
	//hero1->addChild(hero1->bloodBar, 2);
	//hero1->picturename = "hero1.png";
	hero2->addChild(temp);

	hero2->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	hero2->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1.0f / hero2->speedAttack);
	hero2->autorelease();
	return hero2;
}


void hero2::releaseSkill() {

}

_2star_hero2::_2star_hero2() {
	//填写二星英雄的属性
}

_2star_hero2* _2star_hero2::createhero() {
	auto _2star_hero2 = _2star_hero2::create();
	_2star_hero2->picturename = "";
	_2star_hero2->picturenum = 0;
	_2star_hero2->autorelease();
	return _2star_hero2;
}

_3star_hero2::_3star_hero2() {
	//填写三星英雄的属性
}

_3star_hero2* _3star_hero2::createhero() {
	auto _3star_hero2 = _3star_hero2::create();
	_3star_hero2->autorelease();
	return _3star_hero2;
}