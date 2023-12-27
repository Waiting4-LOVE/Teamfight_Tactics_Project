#include"snowMonster.h"

snowMonster::snowMonster() {
	type = SnowMonster;
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

snowMonster* snowMonster::createhero() {
	//auto snowMonster = new snowMonster();
	//snowMonster->set(100, 100);
	auto snowMonster = snowMonster::create();
	auto temp = Sprite::create("snowMonster.png");
	temp->setScale(2.5);
	snowMonster->bloodBar->setBarChangeRate(Point(1, 0));
	snowMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	snowMonster->bloodBar->setMidpoint(Point(0, 1));
	snowMonster->bloodBar->setScaleX(0.22);
	snowMonster->scheduleUpdate();
	//snowMonster->addChild(snowMonster->bloodBar, 2);
	//snowMonster->picturename = "snowMonster.png";
	snowMonster->addChild(temp);

	snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	//snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / snowMonster->speedAttack);
	snowMonster->autorelease();
	return snowMonster;
}


void snowMonster::releaseSkill() {

}

_2star_snowMonster::_2star_snowMonster() {
	//填写二星英雄的属性
}

_2star_snowMonster* _2star_snowMonster::createhero() {
	auto _2star_snowMonster = _2star_snowMonster::create();
	_2star_snowMonster->picturename = "";
	_2star_snowMonster->picturenum = 0;
	_2star_snowMonster->autorelease();
	return _2star_snowMonster;
}

_3star_snowMonster::_3star_snowMonster() {
	//填写三星英雄的属性
}

_3star_snowMonster* _3star_snowMonster::createhero() {
	auto _3star_snowMonster = _3star_snowMonster::create();
	_3star_snowMonster->autorelease();
	return _3star_snowMonster;
}