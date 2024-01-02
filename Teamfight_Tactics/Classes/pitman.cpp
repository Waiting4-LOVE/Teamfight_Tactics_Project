#include"pitman.h"

pitman::pitman() {
	type = Pitman;
	maxHealthPoint = 450;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 1;
	name = "Pitman";
	HealthPoint = 450;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 15;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 48;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 15;
	defenceMagic = 15;
	star = 1;
}

pitman* pitman::createhero() {
	//auto pitman = new pitman();
	//pitman->set(100, 100);
	auto pitman = pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	pitman->bloodBar->setBarChangeRate(Point(1, 0));
	pitman->bloodBar->setType(ProgressTimer::Type::BAR);
	pitman->bloodBar->setMidpoint(Point(0, 1));
	pitman->bloodBar->setScaleX(0.22);
	pitman->scheduleUpdate();
	//pitman->addChild(pitman->bloodBar, 2);
	pitman->picturename = "pitman.png";
	pitman->addChild(temp);

	pitman->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	pitman->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / pitman->speedAttack);
	pitman->autorelease();
	return pitman;
}

void pitman::attack(float dt)
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
			shootbullet("earthball.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void pitman::releaseSkill() {

}

_2star_pitman::_2star_pitman() {
	//��д����Ӣ�۵�����
	type = Pitman;
	maxHealthPoint = 810;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 1;
	name = "Pitman";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 15;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 72;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 15;
	defenceMagic = 15;
	star = 2;
}

_2star_pitman* _2star_pitman::createhero() {
	auto _2star_pitman = _2star_pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	_2star_pitman->addChild(temp);
	_2star_pitman->autorelease();
	return _2star_pitman;
}

_3star_pitman::_3star_pitman() {
	//��д����Ӣ�۵�����
	type = Pitman;
	maxHealthPoint = 1458;
	maxBluePoint = 60;
	maxShieldPoint = 100;
	fee = 1;
	name = "Pitman";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 15;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 108;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 15;
	defenceMagic = 15;
	star = 3;
}

_3star_pitman* _3star_pitman::createhero() {
	auto _3star_pitman = _3star_pitman::create();
	auto temp = Sprite::create("pitman.png");
	temp->setScale(2.5);
	_3star_pitman->addChild(temp);
	_3star_pitman->autorelease();
	return _3star_pitman;
}