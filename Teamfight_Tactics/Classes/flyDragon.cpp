#include"flyDragon.h"

flyDragon::flyDragon() {
	type = FlyDragon;
	maxHealthPoint = 700;
	maxBluePoint = 30;
	maxShieldPoint = 100;
	fee = 4;
	name = "FlyDragon";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 30;
	defenceMagic = 30;
}

flyDragon* flyDragon::createhero() {
	//auto flyDragon = new flyDragon();
	//flyDragon->set(100, 100);
	auto flyDragon = flyDragon::create();
	auto temp = Sprite::create("flyDragon.png");
	temp->setScale(2.5);
	flyDragon->bloodBar->setBarChangeRate(Point(1, 0));
	flyDragon->bloodBar->setType(ProgressTimer::Type::BAR);
	flyDragon->bloodBar->setMidpoint(Point(0, 1));
	flyDragon->bloodBar->setScaleX(0.22);
	flyDragon->scheduleUpdate();
	//flyDragon->addChild(flyDragon->bloodBar, 2);
	//flyDragon->picturename = "flyDragon.png";
	flyDragon->addChild(temp);

	flyDragon->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	flyDragon->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / flyDragon->speedAttack);
	flyDragon->autorelease();
	return flyDragon;
}


void flyDragon::releaseSkill() {

}

_2star_flyDragon::_2star_flyDragon() {
	//填写二星英雄的属性
	type = FlyDragon;
	maxHealthPoint = 1260;
	maxBluePoint = 30;
	maxShieldPoint = 100;
	fee = 4;
	name = "FlyDragon";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 30;
	defenceMagic = 30;
}

_2star_flyDragon* _2star_flyDragon::createhero() {
	auto _2star_flyDragon = _2star_flyDragon::create();
	_2star_flyDragon->picturename = "";
	_2star_flyDragon->picturenum = 0;
	_2star_flyDragon->autorelease();
	return _2star_flyDragon;
}

_3star_flyDragon::_3star_flyDragon() {
	//填写三星英雄的属性
	type = FlyDragon;
	maxHealthPoint = 2268;
	maxBluePoint = 30;
	maxShieldPoint = 100;
	fee = 4;
	name = "FlyDragon";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 30;
	defenceMagic = 30;
}

_3star_flyDragon* _3star_flyDragon::createhero() {
	auto _3star_flyDragon = _3star_flyDragon::create();
	_3star_flyDragon->autorelease();
	return _3star_flyDragon;
}