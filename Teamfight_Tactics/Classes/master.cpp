#include"master.h"

master::master() {
	type = Master;
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

master* master::createhero() {
	//auto master = new master();
	//master->set(100, 100);
	auto master = master::create();
	auto temp = Sprite::create("master.png");
	temp->setScale(2.5);
	master->bloodBar->setBarChangeRate(Point(1, 0));
	master->bloodBar->setType(ProgressTimer::Type::BAR);
	master->bloodBar->setMidpoint(Point(0, 1));
	master->bloodBar->setScaleX(0.22);
	master->scheduleUpdate();
	//master->addChild(master->bloodBar, 2);
	//master->picturename = "master.png";
	master->addChild(temp);

	master->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	//master->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / master->speedAttack);
	master->autorelease();
	return master;
}


void master::releaseSkill() {

}

_2star_master::_2star_master() {
	//填写二星英雄的属性
}

_2star_master* _2star_master::createhero() {
	auto _2star_master = _2star_master::create();
	_2star_master->picturename = "";
	_2star_master->picturenum = 0;
	_2star_master->autorelease();
	return _2star_master;
}

_3star_master::_3star_master() {
	//填写三星英雄的属性
}

_3star_master* _3star_master::createhero() {
	auto _3star_master = _3star_master::create();
	_3star_master->autorelease();
	return _3star_master;
}