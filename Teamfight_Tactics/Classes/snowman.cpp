#include"snowman.h"

snowman::snowman() {
	type = Snowman;
	maxHealthPoint = 450;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 450;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 1;
	CoinsNeeded = 1;
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
	snowman->picturename = "snowman.png";
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

void snowman::releaseSkill() {
	shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this, 2,0,1);
}

_2star_snowman::_2star_snowman() {
	//��д����Ӣ�۵�����
	type = _2star_Snowman;
	maxHealthPoint = 810;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 810;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 2;
}

_2star_snowman* _2star_snowman::createhero() {
	auto _2star_snowman = _2star_snowman::create();
	auto temp = Sprite::create("snowman.png");
	temp->setScale(2.5);
	_2star_snowman->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_snowman->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_snowman->bloodBar->setMidpoint(Point(0, 1));
	_2star_snowman->bloodBar->setScaleX(0.22);
	_2star_snowman->scheduleUpdate();
	//snowman->addChild(snowman->bloodBar, 2);
	_2star_snowman->picturename = "snowman.png";
	_2star_snowman->addChild(temp);

	_2star_snowman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_2star_snowman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_snowman->speedAttack);
	_2star_snowman->autorelease();
	return _2star_snowman;
}

_3star_snowman::_3star_snowman() {
	//��д����Ӣ�۵�����
	type = _3star_Snowman;
	maxHealthPoint = 1458;
	maxBluePoint = 50;
	maxShieldPoint = 100;
	fee = 1;
	name = "Snowman";
	HealthPoint = 1458;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 3;
}

_3star_snowman* _3star_snowman::createhero() {
	auto _3star_snowman = _3star_snowman::create();
	auto temp = Sprite::create("snowman.png");
	temp->setScale(2.5);
	_3star_snowman->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_snowman->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_snowman->bloodBar->setMidpoint(Point(0, 1));
	_3star_snowman->bloodBar->setScaleX(0.22);
	_3star_snowman->scheduleUpdate();
	//snowman->addChild(snowman->bloodBar, 2);
	_3star_snowman->picturename = "snowman.png";
	_3star_snowman->addChild(temp);

	_3star_snowman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	_3star_snowman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_snowman->speedAttack);
	_3star_snowman->autorelease();
	return _3star_snowman;
}