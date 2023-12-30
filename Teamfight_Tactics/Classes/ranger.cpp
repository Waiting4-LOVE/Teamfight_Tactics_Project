#include"ranger.h"

ranger::ranger() {
	type = Ranger;
	maxHealthPoint = 600;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 600;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 1;
	CoinsNeeded = 2;
}

ranger* ranger::createhero() {
	//auto ranger = new ranger();
	//ranger->set(100, 100);
	auto ranger = ranger::create();
	auto temp = Sprite::create("ranger.png");
	temp->setScale(2.5);
	ranger->bloodBar->setBarChangeRate(Point(1, 0));
	ranger->bloodBar->setType(ProgressTimer::Type::BAR);
	ranger->bloodBar->setMidpoint(Point(0, 1));
	ranger->bloodBar->setScaleX(0.22);
	ranger->scheduleUpdate();
	//ranger->addChild(hero1->bloodBar, 2);
	ranger->picturename = "ranger.png";
	ranger->addChild(temp);

	ranger->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	ranger->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / ranger->speedAttack);
	ranger->autorelease();
	return ranger;
}

void ranger::attack(float dt)
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
			shootbullet("spark.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void ranger::releaseSkill() {

}

_2star_ranger::_2star_ranger() {
	//填写二星英雄的属性
	type = _2star_Ranger;
	maxHealthPoint = 1080;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 1080;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 2;
}

_2star_ranger* _2star_ranger::createhero() {
	auto _2star_ranger = _2star_ranger::create();
	auto temp = Sprite::create("ranger.png");
	temp->setScale(2.5);
	_2star_ranger->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_ranger->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_ranger->bloodBar->setMidpoint(Point(0, 1));
	_2star_ranger->bloodBar->setScaleX(0.22);
	_2star_ranger->scheduleUpdate();
	//ranger->addChild(hero1->bloodBar, 2);
	_2star_ranger->picturename = "ranger.png";
	_2star_ranger->addChild(temp);

	_2star_ranger->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_2star_ranger->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_ranger->speedAttack);
	_2star_ranger->autorelease();
	return _2star_ranger;
}

_3star_ranger::_3star_ranger() {
	//填写三星英雄的属性
	type = _3star_Ranger;
	maxHealthPoint = 1944;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 1944;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 3;
}

_3star_ranger* _3star_ranger::createhero() {
	auto _3star_ranger = _3star_ranger::create();
	auto temp = Sprite::create("ranger.png");
	temp->setScale(2.5);
	_3star_ranger->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_ranger->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_ranger->bloodBar->setMidpoint(Point(0, 1));
	_3star_ranger->bloodBar->setScaleX(0.22);
	_3star_ranger->scheduleUpdate();
	//ranger->addChild(hero1->bloodBar, 2);
	_3star_ranger->picturename = "ranger.png";
	_3star_ranger->addChild(temp);

	_3star_ranger->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_3star_ranger->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_ranger->speedAttack);
	_3star_ranger->autorelease();
	return _3star_ranger;
}