#include"elf.h"


elf::elf() {
	type = Elf;
	maxHealthPoint = 700;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = 700;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 25;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 1;
}

elf* elf::createhero() {
	//auto elf = new elf();
	//elf->set(100, 100);
	auto elf = elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	elf->bloodBar->setBarChangeRate(Point(1, 0));
	elf->bloodBar->setType(ProgressTimer::Type::BAR);
	elf->bloodBar->setMidpoint(Point(0, 1));
	elf->bloodBar->setScaleX(0.22);
	elf->scheduleUpdate();
	//elf->addChild(elf->bloodBar, 2);
	elf->picturename = "elf.png";
	elf->addChild(temp);

	elf->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	elf->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / elf->speedAttack);
	elf->autorelease();
	return elf;
}

void elf::attack(float dt)
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

void elf::releaseSkill() {

}

_2star_elf::_2star_elf() {
	//��д����Ӣ�۵�����
	type = Elf;
	maxHealthPoint = 1260;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 25;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 2;
}

_2star_elf* _2star_elf::createhero() {
	auto _2star_elf = _2star_elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	_2star_elf->addChild(temp);
	_2star_elf->autorelease();
	return _2star_elf;
}

_3star_elf::_3star_elf() {
	//��д����Ӣ�۵�����
	type = Elf;
	maxHealthPoint = 2268;
	maxBluePoint = 75;
	maxShieldPoint = 100;
	fee = 3;
	name = "Elf";
	HealthPoint = maxHealthPoint;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 25;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
	star = 3;
}

_3star_elf* _3star_elf::createhero() {
	auto _3star_elf = _3star_elf::create();
	auto temp = Sprite::create("elf.png");
	temp->setScale(2.5);
	_3star_elf->addChild(temp);
	_3star_elf->autorelease();
	return _3star_elf;
}