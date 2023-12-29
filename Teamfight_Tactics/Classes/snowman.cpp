#include"snowman.h"

snowman::snowman() {
	type = Snowman;
	maxHealthPoint = 450;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 450;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

snowman* snowman::createhero() {
	//auto snowman = new snowman();
	//snowman->set(100, 100);
	auto snowman = snowman::create();
	auto temp = Sprite::create("snowman.png");
	temp->setScale(2.5);
	snowman->bloodBar->setBarChangeRate(Point(1, 0));
	snowman->bloodBar->setType(ProgressTimer::Type::BAR);
	snowman->bloodBar->setMidpoint(Point(0, 1));
	snowman->bloodBar->setScaleX(0.22);
	snowman->scheduleUpdate();
	//snowman->addChild(snowman->bloodBar, 2);
	//snowman->picturename = "snowman.png";
	snowman->addChild(temp);

	snowman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	snowman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / snowman->speedAttack);
	snowman->autorelease();
	return snowman;
}

void snowman::attack(float dt)
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

void snowman::releaseSkill() {

}

_2star_snowman::_2star_snowman() {
	//填写二星英雄的属性
	type = Snowman;
	maxHealthPoint = 810;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 450;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_2star_snowman* _2star_snowman::createhero() {
	auto _2star_snowman = _2star_snowman::create();
	_2star_snowman->picturename = "";
	_2star_snowman->picturenum = 0;
	_2star_snowman->autorelease();
	return _2star_snowman;
}

_3star_snowman::_3star_snowman() {
	//填写三星英雄的属性
	type = Snowman;
	maxHealthPoint = 1458;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 450;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_3star_snowman* _3star_snowman::createhero() {
	auto _3star_snowman = _3star_snowman::create();
	_3star_snowman->autorelease();
	return _3star_snowman;
}