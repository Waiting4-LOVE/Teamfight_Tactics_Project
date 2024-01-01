#include"ghost.h"

ghost::ghost() {
	type = Ghost;
	maxHealthPoint = 1100;
	maxBluePoint = 150;
	maxShieldPoint = 70;
	fee = 5;
	name = "Ghost";
	HealthPoint = 1100;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 70;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 70;
	defenceMagic = 70;
	star = 1;
	CoinsNeeded = 5;
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
	ghost->picturename = "ghost.png";
	ghost->addChild(temp);

	ghost->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	ghost->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / ghost->speedAttack);
	ghost->autorelease();
	return ghost;
}

void ghost::attack(float dt)
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
			shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this,1);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void ghost::releaseSkill() {
	shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this, 2,0,1);
}

_2star_ghost::_2star_ghost() {
	//填写二星英雄的属性
	type = _2star_Ghost;
	maxHealthPoint = 1980;
	maxBluePoint = 150;
	maxShieldPoint = 70;
	fee = 5;
	name = "Ghost";
	HealthPoint = 1980;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 105;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 70;
	defenceMagic = 70;
	star = 2;
}

_2star_ghost* _2star_ghost::createhero() {
	auto _2star_ghost = _2star_ghost::create();
	auto temp = Sprite::create("ghost.png");
	temp->setScale(2.5);
	_2star_ghost->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_ghost->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_ghost->bloodBar->setMidpoint(Point(0, 1));
	_2star_ghost->bloodBar->setScaleX(0.22);
	_2star_ghost->scheduleUpdate();
	//ghost->addChild(ghost->bloodBar, 2);
	_2star_ghost->picturename = "ghost.png";
	_2star_ghost->addChild(temp);

	_2star_ghost->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_2star_ghost->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_ghost->speedAttack);
	_2star_ghost->autorelease();
	return _2star_ghost;
}

_3star_ghost::_3star_ghost() {
	//填写三星英雄的属性
	type = _3star_Ghost;
	maxHealthPoint = 3564;
	maxBluePoint = 150;
	maxShieldPoint = 70;
	fee = 5;
	name = "Ghost";
	HealthPoint = 3564;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 158;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 70;
	defenceMagic = 70;
	star = 3;
}

_3star_ghost* _3star_ghost::createhero() {
	auto _3star_ghost = _3star_ghost::create();
	auto temp = Sprite::create("ghost.png");
	temp->setScale(2.5);
	_3star_ghost->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_ghost->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_ghost->bloodBar->setMidpoint(Point(0, 1));
	_3star_ghost->bloodBar->setScaleX(0.22);
	_3star_ghost->scheduleUpdate();
	//ghost->addChild(ghost->bloodBar, 2);
	_3star_ghost->picturename = "ghost.png";
	_3star_ghost->addChild(temp);

	_3star_ghost->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_3star_ghost->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_ghost->speedAttack);
	_3star_ghost->autorelease();
	return _3star_ghost;
}