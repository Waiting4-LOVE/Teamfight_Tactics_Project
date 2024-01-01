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
	star = 1;
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


	master->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / master->speedAttack);
	master->autorelease();
	return master;
}

void master::attack(float dt)
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
			shootbullet("shroom.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void master::releaseSkill() {

}

_2star_master::_2star_master() {
	//填写二星英雄的属性
	type = _2star_Master;
	maxHealthPoint = 1170;
	maxBluePoint = 40;
	maxShieldPoint = 0;
	fee = 3;
	name = "Master";
	HealthPoint = 1170;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 2;
}

_2star_master* _2star_master::createhero() {
	auto _2star_master = _2star_master::create();
	auto temp = Sprite::create("master.png");
	temp->setScale(2.5);
	_2star_master->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_master->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_master->bloodBar->setMidpoint(Point(0, 1));
	_2star_master->bloodBar->setScaleX(0.22);
	_2star_master->scheduleUpdate();
	//master->addChild(master->bloodBar, 2);
	_2star_master->picturename = "master.png";
	_2star_master->addChild(temp);

	_2star_master->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_2star_master->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_master->speedAttack);
	_2star_master->autorelease();
	return _2star_master;
}

_3star_master::_3star_master() {
	//填写三星英雄的属性
	type = _3star_Master;
	maxHealthPoint = 2106;
	maxBluePoint = 40;
	maxShieldPoint = 0;
	fee = 3;
	name = "Master";
	HealthPoint = 2106;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 3;
}

_3star_master* _3star_master::createhero() {
	auto _3star_master = _3star_master::create();
	auto temp = Sprite::create("master.png");
	temp->setScale(2.5);
	_3star_master->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_master->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_master->bloodBar->setMidpoint(Point(0, 1));
	_3star_master->bloodBar->setScaleX(0.22);
	_3star_master->scheduleUpdate();
	//master->addChild(master->bloodBar, 2);
	_3star_master->picturename = "master.png";
	_3star_master->addChild(temp);

	_3star_master->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_3star_master->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_master->speedAttack);
	_3star_master->autorelease();
	return _3star_master;
}