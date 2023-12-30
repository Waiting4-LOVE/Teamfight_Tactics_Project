#include"knight.h"

knight::knight() {
	type = Knight;
	maxHealthPoint = 650;
	maxBluePoint = 140;
	maxShieldPoint = 0;
	fee = 1;
	name = "Knight";
	HealthPoint = 650;//初始血量为最大血量
	BluePoint = 50;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.55f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 40;
	defenceMagic = 40;
	star = 1;
}

knight* knight::createhero() {
	//auto knight = new knight();
	//knight->set(100, 100);
	auto knight = knight::create();
	auto temp = Sprite::create("knight.png");
	temp->setScale(2.5);
	knight->bloodBar->setBarChangeRate(Point(1, 0));
	knight->bloodBar->setType(ProgressTimer::Type::BAR);
	knight->bloodBar->setMidpoint(Point(0, 1));
	knight->bloodBar->setScaleX(0.22);
	knight->scheduleUpdate();
	//knight->addChild(pitman->bloodBar, 2);
	knight->picturename = "knight.png";
	knight->addChild(temp);
	knight->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	knight->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / knight->speedAttack);
	knight->autorelease();
	return knight;
}

void knight::attack(float dt)
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

void knight::releaseSkill() {

}

_2star_knight::_2star_knight() {
	//填写二星英雄的属性
	type = Knight;
	maxHealthPoint = 1170;
	maxBluePoint = 140;
	maxShieldPoint = 0;
	fee = 1;
	name = "Knight";
	HealthPoint = 650;//初始血量为最大血量
	BluePoint = 50;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.55f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 40;
	defenceMagic = 40;
	star = 2;
}

_2star_knight* _2star_knight::createhero() {
	auto _2star_knight = _2star_knight::create();
	_2star_knight->picturename = "";
	_2star_knight->picturenum = 0;
	_2star_knight->autorelease();
	return _2star_knight;
}

_3star_knight::_3star_knight() {
	//填写三星英雄的属性
	type = Knight;
	maxHealthPoint = 2106;
	maxBluePoint = 140;
	maxShieldPoint = 0;
	fee = 1;
	name = "Knight";
	HealthPoint = 650;//初始血量为最大血量
	BluePoint = 50;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.55f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 40;
	defenceMagic = 40;
	star = 3;
}

_3star_knight* _3star_knight::createhero() {
	auto _3star_knight = _3star_knight::create();
	_3star_knight->autorelease();
	return _3star_knight;
}
