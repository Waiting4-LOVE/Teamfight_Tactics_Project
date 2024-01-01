#include"snowMonster.h"

snowMonster::snowMonster() {
	type = SnowMonster;
	maxHealthPoint = 1100;
	maxBluePoint = 130;
	maxShieldPoint = 100;
	fee = 4;
	name = "SnowMonster";
	HealthPoint = 1100;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 60;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 50;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 60;
	defenceMagic = 60;
	star = 1;
	CoinsNeeded = 4;
}

snowMonster* snowMonster::createhero() {
	//auto snowMonster = new snowMonster();
	//snowMonster->set(100, 100);
	auto snowMonster = snowMonster::create();
	auto temp = Sprite::create("snowMonster.png");
	temp->setScale(2.5);
	snowMonster->bloodBar->setBarChangeRate(Point(1, 0));
	snowMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	snowMonster->bloodBar->setMidpoint(Point(0, 1));
	snowMonster->bloodBar->setScaleX(0.22);
	snowMonster->scheduleUpdate();
	//snowMonster->addChild(snowMonster->bloodBar, 2);
	snowMonster->picturename = "snowMonster.png";
	snowMonster->addChild(temp);

	snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / snowMonster->speedAttack);
	snowMonster->autorelease();
	return snowMonster;
}

void snowMonster::attack(float dt)
{
	if (attackTarget != NULL && !die())
	{
		float  distance = sqrt((attackTarget->getPosition().x - getPosition().x)  //��þ���
			* (attackTarget->getPosition().x - getPosition().x) +
			(attackTarget->getPosition().y - getPosition().y)
			* (attackTarget->getPosition().y - getPosition().y));
		if (distance < distanceAttack * oneLattice * 2)                           //С�ڹ���������ʼ����
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

void snowMonster::releaseSkill() {
	shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this, 2,0,1);
}

_2star_snowMonster::_2star_snowMonster() {
	//��д����Ӣ�۵�����
	type = _2star_SnowMonster;
	maxHealthPoint = 1980;
	maxBluePoint = 130;
	maxShieldPoint = 100;
	fee = 4;
	name = "SnowMonster";
	HealthPoint = 1980;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 60;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 75;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 60;
	defenceMagic = 60;
	star = 2;
}

_2star_snowMonster* _2star_snowMonster::createhero() {
	auto _2star_snowMonster = _2star_snowMonster::create();
	auto temp = Sprite::create("snowMonster.png");
	temp->setScale(2.5);
	_2star_snowMonster->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_snowMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_snowMonster->bloodBar->setMidpoint(Point(0, 1));
	_2star_snowMonster->bloodBar->setScaleX(0.22);
	_2star_snowMonster->scheduleUpdate();
	//snowMonster->addChild(snowMonster->bloodBar, 2);
	_2star_snowMonster->picturename = "snowMonster.png";
	_2star_snowMonster->addChild(temp);

	_2star_snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_2star_snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_snowMonster->speedAttack);
	_2star_snowMonster->autorelease();
	return _2star_snowMonster;
}

_3star_snowMonster::_3star_snowMonster() {
	//��д����Ӣ�۵�����
	type = _3star_SnowMonster;
	maxHealthPoint = 3564;
	maxBluePoint = 130;
	maxShieldPoint = 100;
	fee = 4;
	name = "SnowMonster";
	HealthPoint = 3564;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 60;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 113;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 60;
	defenceMagic = 60;
	star = 3;
}

_3star_snowMonster* _3star_snowMonster::createhero() {
	auto _3star_snowMonster = _3star_snowMonster::create();
	auto temp = Sprite::create("snowMonster.png");
	temp->setScale(2.5);
	_3star_snowMonster->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_snowMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_snowMonster->bloodBar->setMidpoint(Point(0, 1));
	_3star_snowMonster->bloodBar->setScaleX(0.22);
	_3star_snowMonster->scheduleUpdate();
	//snowMonster->addChild(snowMonster->bloodBar, 2);
	_3star_snowMonster->picturename = "snowMonster.png";
	_3star_snowMonster->addChild(temp);

	_3star_snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_3star_snowMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_snowMonster->speedAttack);
	_3star_snowMonster->autorelease();
	return _3star_snowMonster;
}