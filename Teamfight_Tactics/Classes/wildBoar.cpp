#include"wildBoar.h"

wildBoar::wildBoar() {
	type = WildBoar;
	maxHealthPoint = 750;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = 750;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 40;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 1;
}

wildBoar* wildBoar::createhero() {
	//auto wildBoar = new wildBoar();
	//wildBoar->set(100, 100);
	auto wildBoar = wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	wildBoar->bloodBar->setBarChangeRate(Point(1, 0));
	wildBoar->bloodBar->setType(ProgressTimer::Type::BAR);
	wildBoar->bloodBar->setMidpoint(Point(0, 1));
	wildBoar->bloodBar->setScaleX(0.22);
	wildBoar->scheduleUpdate();
	//wildBoar->addChild(wildBoar->bloodBar, 2);
	wildBoar->picturename = "wildBoar.png";
	wildBoar->addChild(temp);
	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
	wildBoar->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / wildBoar->speedAttack);
	wildBoar->autorelease();
	return wildBoar;
}

void wildBoar::attack(float dt)
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

void wildBoar::releaseSkill() {

}

_2star_wildBoar::_2star_wildBoar() {
	//��д����Ӣ�۵�����
	type = WildBoar;
	maxHealthPoint = 1350;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 40;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 2;
}

_2star_wildBoar* _2star_wildBoar::createhero() {
	auto _2star_wildBoar = _2star_wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	_2star_wildBoar->addChild(temp);
	_2star_wildBoar->autorelease();
	return _2star_wildBoar;
}

_3star_wildBoar::_3star_wildBoar() {
	//��д����Ӣ�۵�����
	type = WildBoar;
	maxHealthPoint = 2430;
	maxBluePoint = 90;
	maxShieldPoint = 100;
	fee = 2;
	name = "WildBoar";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 40;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 45;
	defenceMagic = 45;
	star = 3;
}

_3star_wildBoar* _3star_wildBoar::createhero() {
	auto _3star_wildBoar = _3star_wildBoar::create();
	auto temp = Sprite::create("wildBoar.png");
	temp->setScale(2.5);
	_3star_wildBoar->addChild(temp);
	_3star_wildBoar->autorelease();
	return _3star_wildBoar;
}