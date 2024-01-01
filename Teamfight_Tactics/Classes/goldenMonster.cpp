#include "goldenMonster.h"

goldenMonster::goldenMonster() {
	type = GoldenMonster;
	maxHealthPoint = 100;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao don't know";
	HealthPoint = 100;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
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

goldenMonster* goldenMonster::createhero() {
	//auto goldenMonster = new goldenMonster();
	//goldenMonster->set(100, 100);
	auto goldenMonster = goldenMonster::create();
	auto temp = Sprite::create("goldenMonster.png");
	temp->setScale(2.5);
	goldenMonster->bloodBar->setBarChangeRate(Point(1, 0));
	goldenMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	goldenMonster->bloodBar->setMidpoint(Point(0, 1));
	goldenMonster->bloodBar->setScaleX(0.22);
	goldenMonster->scheduleUpdate();
	//goldenMonster->addChild(goldenMonster->bloodBar, 2);
	//goldenMonster->picturename = "goldenMonster.png";
	goldenMonster->addChild(temp);

	goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / goldenMonster->speedAttack);
	goldenMonster->autorelease();
	return goldenMonster;
}

void goldenMonster::attack(float dt)
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

void goldenMonster::releaseSkill() {

}

_2star_goldenMonster::_2star_goldenMonster() {
	//��д����Ӣ�۵�����
	type = _2star_GoldenMonster;
	maxHealthPoint = 1350;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 2;
	name = "GoldenMonster";
	HealthPoint = 1350;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.6f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 2;
}

_2star_goldenMonster* _2star_goldenMonster::createhero() {
	auto _2star_goldenMonster = _2star_goldenMonster::create();
	auto temp = Sprite::create("goldenMonster.png");
	temp->setScale(2.5);
	_2star_goldenMonster->bloodBar->setBarChangeRate(Point(1, 0));
	_2star_goldenMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	_2star_goldenMonster->bloodBar->setMidpoint(Point(0, 1));
	_2star_goldenMonster->bloodBar->setScaleX(0.22);
	_2star_goldenMonster->scheduleUpdate();
	//goldenMonster->addChild(goldenMonster->bloodBar, 2);
	_2star_goldenMonster->picturename = "goldenMonster.png";
	_2star_goldenMonster->addChild(temp);

	_2star_goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_2star_goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _2star_goldenMonster->speedAttack);
	_2star_goldenMonster->autorelease();
	return _2star_goldenMonster;
}

_3star_goldenMonster::_3star_goldenMonster() {
	//��д����Ӣ�۵�����
	type = _3star_GoldenMonster;
	maxHealthPoint = 2430;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 2;
	name = "GoldenMonster";
	HealthPoint = 2430;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.6f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 3;
}

_3star_goldenMonster* _3star_goldenMonster::createhero() {
	auto _3star_goldenMonster = _3star_goldenMonster::create();
	auto temp = Sprite::create("goldenMonster.png");
	temp->setScale(2.5);
	_3star_goldenMonster->bloodBar->setBarChangeRate(Point(1, 0));
	_3star_goldenMonster->bloodBar->setType(ProgressTimer::Type::BAR);
	_3star_goldenMonster->bloodBar->setMidpoint(Point(0, 1));
	_3star_goldenMonster->bloodBar->setScaleX(0.22);
	_3star_goldenMonster->scheduleUpdate();
	//goldenMonster->addChild(goldenMonster->bloodBar, 2);
	_3star_goldenMonster->picturename = "goldenMonster.png";
	_3star_goldenMonster->addChild(temp);

	_3star_goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	_3star_goldenMonster->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / _3star_goldenMonster->speedAttack);
	_3star_goldenMonster->autorelease();
	return _3star_goldenMonster;
}