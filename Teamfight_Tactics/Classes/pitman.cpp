#include"pitman.h"

pitman::pitman() {
	type = Pitman;
	maxHealthPoint = 100;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao don't know";
	HealthPoint = 100000;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.7f;
	distanceAttack = 2;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 1;
}

pitman* pitman::createhero() {
	//auto pitman = new pitman();
	//pitman->set(100, 100);
	auto pitman = pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	pitman->bloodBar->setBarChangeRate(Point(1, 0));
	pitman->bloodBar->setType(ProgressTimer::Type::BAR);
	pitman->bloodBar->setMidpoint(Point(0, 1));
	pitman->bloodBar->setScaleX(0.22);
	pitman->scheduleUpdate();
	//pitman->addChild(pitman->bloodBar, 2);
	//pitman->picturename = "pitman.png";
	pitman->addChild(temp);

	pitman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	pitman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / pitman->speedAttack);
	pitman->autorelease();
	return pitman;
}

void pitman::attack(float dt)
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
			shootbullet("earthball.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void pitman::releaseSkill() {

}

_2star_pitman::_2star_pitman() {
	//填写二星英雄的属性
	type = _2star_Pitman;
	maxHealthPoint = 810;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 1;
	name = "Pitman";
	HealthPoint = 810;//初始血量为最大血量
	BluePoint = 15;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.7f;
	distanceAttack = 2;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 2;
	//填写二星英雄的属性
}

_2star_pitman* _2star_pitman::createhero() {
	auto _2star_pitman = _2star_pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	_2star_pitman->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_pitman->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_pitman->bloodBar->setMidpoint(Point(0, 1));
	_2star_pitman->bloodBar->setScaleX(0.22);
	_2star_pitman->scheduleUpdate();
	//pitman->addChild(pitman->bloodBar, 2);
	_2star_pitman->picturename = "pitman.png";
	_2star_pitman->addChild(temp);

	_2star_pitman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_2star_pitman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_pitman->speedAttack);
	_2star_pitman->autorelease();
	return _2star_pitman;
}

_3star_pitman::_3star_pitman() {
	//填写三星英雄的属性
	type = _3star_Pitman;
	maxHealthPoint = 1458;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 1;
	name = "Pitman";
	HealthPoint = 1458;//初始血量为最大血量
	BluePoint = 15;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 0.7f;
	distanceAttack = 2;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 3;
	//填写三星英雄的属性
}

_3star_pitman* _3star_pitman::createhero() {
	auto _3star_pitman = _3star_pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	_3star_pitman->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_pitman->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_pitman->bloodBar->setMidpoint(Point(0, 1));
	_3star_pitman->bloodBar->setScaleX(0.22);
	_3star_pitman->scheduleUpdate();
	//pitman->addChild(pitman->bloodBar, 2);
	_3star_pitman->picturename = "pitman.png";
	_3star_pitman->addChild(temp);

	_3star_pitman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_3star_pitman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_pitman->speedAttack);
	_3star_pitman->autorelease();
	return _3star_pitman;
}