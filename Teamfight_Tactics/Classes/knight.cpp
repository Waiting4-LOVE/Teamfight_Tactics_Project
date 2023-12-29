#include"knight.h"

knight::knight() {
	type = Knight;
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
	distanceAttack = 2;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
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
	//knight->picturename = "pitman.png";
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
}

_2star_knight* _2star_knight::createhero() {
	auto _2star_knight = _2star_knight::create();
	auto temp = Sprite::create("knight.png");
	temp->setScale(2.5);
	_2star_knight->addChild(temp);
	_2star_knight->autorelease();
	return _2star_knight;
}

_3star_knight::_3star_knight() {
	//填写三星英雄的属性
}

_3star_knight* _3star_knight::createhero() {
	auto _3star_knight = _3star_knight::create();
	auto temp = Sprite::create("knight.png");
	temp->setScale(2.5);
	_3star_knight->addChild(temp);
	_3star_knight->autorelease();
	return _3star_knight;
}
