#include "darkKnight.h"

darkKnight::darkKnight() {
	type = DarkKnight;
	maxHealthPoint = 850;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = 850;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
	star = 1;
}

darkKnight* darkKnight::createhero() {
	//auto darkKnight = new darkKnight();
	//darkKnight->set(100, 100);
	auto darkKnight = darkKnight::create();
	auto temp = Sprite::create("darkKnight.png");
	temp->setScale(0.22);
	darkKnight->bloodBar->setBarChangeRate(Point(1, 0));
	darkKnight->bloodBar->setType(ProgressTimer::Type::BAR);
	darkKnight->bloodBar->setMidpoint(Point(0, 1));
	darkKnight->bloodBar->setScaleX(0.22);
	darkKnight->scheduleUpdate();
	//darkKnight->addChild(hero1->bloodBar, 2);
	//darkKnight->picturename = "hero1.png";
	darkKnight->addChild(temp);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / darkKnight->speedAttack);
	darkKnight->autorelease();
	return darkKnight;
}

void darkKnight::attack(float dt)
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

void darkKnight::releaseSkill() {

}

_2star_darkKnight::_2star_darkKnight() {
	//填写二星英雄的属性
	type = DarkKnight;
	maxHealthPoint = 1530;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = maxHealthPoint;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
	star = 2;
}

_2star_darkKnight* _2star_darkKnight::createhero() {
	auto _2star_darkKnight = _2star_darkKnight::create();
	auto temp = Sprite::create("darkKnight.png");
	temp->setScale(0.22);
	_2star_darkKnight->addChild(temp);
	_2star_darkKnight->autorelease();
	return _2star_darkKnight;
}

_3star_darkKnight::_3star_darkKnight() {
	//填写三星英雄的属性
	type = DarkKnight;
	maxHealthPoint = 2754;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = maxHealthPoint;//初始血量为最大血量
	BluePoint = 70;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 135;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
	star = 3;
}

_3star_darkKnight* _3star_darkKnight::createhero() {
	auto _3star_darkKnight = _3star_darkKnight::create();
	auto temp = Sprite::create("darkKnight.png");
	temp->setScale(0.22);
	_3star_darkKnight->addChild(temp);
	_3star_darkKnight->autorelease();
	return _3star_darkKnight;
}