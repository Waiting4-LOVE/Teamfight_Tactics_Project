#include"ghost.h"

ghost::ghost() {
	type = Ghost;
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

ghost* ghost::createhero() {
	//auto ghost = new ghost();
	//ghost->set(100, 100);
	auto ghost = ghost::create();
	auto temp = Sprite::create("ghost.png");
	temp->setScale(2.5);
	ghost->bloodBar->setBarChangeRate(Point(1, 0));
	ghost->bloodBar->setType(ProgressTimer::Type::BAR);
	ghost->bloodBar->setMidpoint(Point(0, 1));
	ghost->bloodBar->setScaleX(0.22);
	ghost->scheduleUpdate();
	//ghost->addChild(ghost->bloodBar, 2);
	//ghost->picturename = "ghost.png";
	ghost->addChild(temp);

	ghost->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	//ghost->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / ghost->speedAttack);
	ghost->autorelease();
	return ghost;
}


void ghost::releaseSkill() {

}

_2star_ghost::_2star_ghost() {
	//填写二星英雄的属性
}

_2star_ghost* _2star_ghost::createhero() {
	auto _2star_ghost = _2star_ghost::create();
	_2star_ghost->picturename = "";
	_2star_ghost->picturenum = 0;
	_2star_ghost->autorelease();
	return _2star_ghost;
}

_3star_ghost::_3star_ghost() {
	//填写三星英雄的属性
}

_3star_ghost* _3star_ghost::createhero() {
	auto _3star_ghost = _3star_ghost::create();
	_3star_ghost->autorelease();
	return _3star_ghost;
}