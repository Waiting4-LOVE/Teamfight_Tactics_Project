#include"elf.h"


elf::elf() {
	type = Elf;
	maxHealthPoint = 700;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 25;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

elf* elf::createhero() {
	//auto elf = new elf();
	//elf->set(100, 100);
	auto elf = elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	elf->bloodBar->setBarChangeRate(Point(1, 0));
	elf->bloodBar->setType(ProgressTimer::Type::BAR);
	elf->bloodBar->setMidpoint(Point(0, 1));
	elf->bloodBar->setScaleX(0.22);
	elf->scheduleUpdate();
	//elf->addChild(elf->bloodBar, 2);
	//elf->picturename = "elf.png";
	elf->addChild(temp);

	elf->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	elf->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / elf->speedAttack);
	elf->autorelease();
	return elf;
}


void elf::releaseSkill() {

}

_2star_elf::_2star_elf() {
	//填写二星英雄的属性
	type = Elf;
	maxHealthPoint = 1260;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 25;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_2star_elf* _2star_elf::createhero() {
	auto _2star_elf = _2star_elf::create();
	_2star_elf->picturename = "";
	_2star_elf->picturenum = 0;
	_2star_elf->autorelease();
	return _2star_elf;
}

_3star_elf::_3star_elf() {
	//填写三星英雄的属性
	type = Elf;
	maxHealthPoint = 2268;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 700;//初始血量为最大血量
	BluePoint = 25;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_3star_elf* _3star_elf::createhero() {
	auto _3star_elf = _3star_elf::create();
	_3star_elf->autorelease();
	return _3star_elf;
}