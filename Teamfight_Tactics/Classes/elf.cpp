#include"elf.h"


elf::elf() {
	type = Elf;
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
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 1;
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

void elf::attack(float dt)
{
	if (attackTarget != NULL && !die())
	{
		float  distance = sqrt((attackTarget->getPosition().x - getPosition().x)  //获得距离
			* (attackTarget->getPosition().x - getPosition().x) +
			(attackTarget->getPosition().y - getPosition().y)
			* (attackTarget->getPosition().y - getPosition().y));
		if (distance < distanceAttack * oneLattice * 2)                           //小于攻击距离则开始攻击
		{
			isMove = 0;
			shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void elf::releaseSkill() {

}

_2star_elf::_2star_elf() {
	//填写二星英雄的属性
	type = _2star_Elf;
	maxHealthPoint = 1260;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 1260;//初始血量为最大血量
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
	star = 2;
}

_2star_elf* _2star_elf::createhero() {
	auto _2star_elf = _2star_elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	_2star_elf->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_elf->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_elf->bloodBar->setMidpoint(Point(0, 1));
	_2star_elf->bloodBar->setScaleX(0.22);
	_2star_elf->scheduleUpdate();
	//elf->addChild(elf->bloodBar, 2);
	_2star_elf->picturename = "elf.png";
	_2star_elf->addChild(temp);

	_2star_elf->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_2star_elf->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_elf->speedAttack);
	_2star_elf->autorelease();
	return _2star_elf;
}

_3star_elf::_3star_elf() {
	//填写三星英雄的属性
	type = _3star_Elf;
	maxHealthPoint = 2268;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 2268;//初始血量为最大血量
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
	star = 3;
}

_3star_elf* _3star_elf::createhero() {
	auto _3star_elf = _3star_elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	_3star_elf->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_elf->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_elf->bloodBar->setMidpoint(Point(0, 1));
	_3star_elf->bloodBar->setScaleX(0.22);
	_3star_elf->scheduleUpdate();
	//elf->addChild(elf->bloodBar, 2);
	_3star_elf->picturename = "elf.png";
	_3star_elf->addChild(temp);

	_3star_elf->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_3star_elf->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_elf->speedAttack);
	_3star_elf->autorelease();
	return _3star_elf;
}