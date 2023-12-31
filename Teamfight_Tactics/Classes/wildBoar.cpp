#include"wildBoar.h"

wildBoar::wildBoar() {
	type = WildBoar;
	maxHealthPoint = 750;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = 750;//初始血量为最大血量
	BluePoint = 40;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 1;
	CoinsNeeded = 2;
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
	wildBoar->picturename = "wildBoar.png";
	wildBoar->addChild(temp);

	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / wildBoar->speedAttack);
	wildBoar->autorelease();
	return wildBoar;
}

void wildBoar::attack(float dt)
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

void wildBoar::releaseSkill() {
	shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this, 2,1,1);
}

_2star_wildBoar::_2star_wildBoar() {
	//填写二星英雄的属性
	type = _2star_WildBoar;
	maxHealthPoint = 1350;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = 1350;//初始血量为最大血量
	BluePoint = 40;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 2;
}

_2star_wildBoar* _2star_wildBoar::createhero() {
	auto _2star_wildBoar = _2star_wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	_2star_wildBoar->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_wildBoar->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_wildBoar->bloodBar->setMidpoint(Point(0, 1));
	_2star_wildBoar->bloodBar->setScaleX(0.22);
	_2star_wildBoar->scheduleUpdate();
	//wildBoar->addChild(wildBoar->bloodBar, 2);
	_2star_wildBoar->picturename = "wildBoar.png";
	_2star_wildBoar->addChild(temp);

	_2star_wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	_2star_wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_wildBoar->speedAttack);
	_2star_wildBoar->autorelease();
	return _2star_wildBoar;
}

_3star_wildBoar::_3star_wildBoar() {
	//填写三星英雄的属性
	type = _3star_WildBoar;
	maxHealthPoint = 2430;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = 2430;//初始血量为最大血量
	BluePoint = 40;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 3;
}

_3star_wildBoar* _3star_wildBoar::createhero() {
	auto _3star_wildBoar = _3star_wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	_3star_wildBoar->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_wildBoar->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_wildBoar->bloodBar->setMidpoint(Point(0, 1));
	_3star_wildBoar->bloodBar->setScaleX(0.22);
	_3star_wildBoar->scheduleUpdate();
	//wildBoar->addChild(wildBoar->bloodBar, 2);
	_3star_wildBoar->picturename = "wildBoar.png";
	_3star_wildBoar->addChild(temp);

	_3star_wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	_3star_wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_wildBoar->speedAttack);
	_3star_wildBoar->autorelease();
	return _3star_wildBoar;
}