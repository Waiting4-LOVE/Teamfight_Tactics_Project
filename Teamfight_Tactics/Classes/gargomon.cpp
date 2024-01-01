#include"gargomon.h"

gargomon::gargomon() {
	type = Gargomon;
	maxHealthPoint = 10000;
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
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 1;
}

gargomon* gargomon::createhero() {
	//auto gargomon = new gargomon();
	//gargomon->set(100, 100);
	auto gargomon = gargomon::create();
	auto temp = Sprite::create("gargomon.png");
	temp->setScale(2.5);
	gargomon->bloodBar->setBarChangeRate(Point(1, 0));
	gargomon->bloodBar->setType(ProgressTimer::Type::BAR);
	gargomon->bloodBar->setMidpoint(Point(0, 1));
	gargomon->bloodBar->setScaleX(0.22);
	gargomon->scheduleUpdate();
	//gargomon->addChild(gargomon->bloodBar, 2);
	//gargomon->picturename = "gargomon.png";
	gargomon->addChild(temp);

	gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / gargomon->speedAttack);
	gargomon->autorelease();
	return gargomon;
}

void gargomon::attack(float dt)
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

void gargomon::releaseSkill() {

}

_2star_gargomon::_2star_gargomon() {
	//填写二星英雄的属性
	type = _2star_Gargomon;
	maxHealthPoint = 1890;
	maxBluePoint = 110;
	maxShieldPoint = 100;
	fee = 5;
	name = "Gargomon";
	HealthPoint = 1890;//初始血量为最大血量
	BluePoint = 60;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 132;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 60;
	defenceMagic = 60;
	star = 2;
}

_2star_gargomon* _2star_gargomon::createhero() {
	auto _2star_gargomon = _2star_gargomon::create();
	auto temp = Sprite::create("gargomon.png");
	temp->setScale(2.5);
	_2star_gargomon->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_gargomon->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_gargomon->bloodBar->setMidpoint(Point(0, 1));
	_2star_gargomon->bloodBar->setScaleX(0.22);
	_2star_gargomon->scheduleUpdate();
	//gargomon->addChild(gargomon->bloodBar, 2);
	_2star_gargomon->picturename = "gargomon.png";
	_2star_gargomon->addChild(temp);

	_2star_gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_2star_gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_gargomon->speedAttack);
	_2star_gargomon->autorelease();
	return _2star_gargomon;
}

_3star_gargomon::_3star_gargomon() {
	//填写三星英雄的属性
	type = _3star_Gargomon;
	maxHealthPoint = 3402;
	maxBluePoint = 110;
	maxShieldPoint = 100;
	fee = 5;
	name = "Gargomon";
	HealthPoint = 3402;//初始血量为最大血量
	BluePoint = 60;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 198;
	magicPoint = 100;
	speedAttack = 0.8f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 60;
	defenceMagic = 60;
	star = 3;
}

_3star_gargomon* _3star_gargomon::createhero() {
	auto _3star_gargomon = _3star_gargomon::create();
	auto temp = Sprite::create("gargomon.png");
	temp->setScale(2.5);
	_3star_gargomon->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_gargomon->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_gargomon->bloodBar->setMidpoint(Point(0, 1));
	_3star_gargomon->bloodBar->setScaleX(0.22);
	_3star_gargomon->scheduleUpdate();
	//gargomon->addChild(gargomon->bloodBar, 2);
	_3star_gargomon->picturename = "gargomon.png";
	_3star_gargomon->addChild(temp);

	_3star_gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_3star_gargomon->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_gargomon->speedAttack);
	_3star_gargomon->autorelease();
	return _3star_gargomon;
}