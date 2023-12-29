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
	//snowMonster->picturename = "snowMonster.png";
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

void snowMonster::releaseSkill() {

}

_2star_snowMonster::_2star_snowMonster() {
	//��д����Ӣ�۵�����
	type = SnowMonster;
	maxHealthPoint = 1980;
	maxBluePoint = 130;
	maxShieldPoint = 100;
	fee = 4;
	name = "SnowMonster";
	HealthPoint = 1100;//��ʼѪ��Ϊ���Ѫ��
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
}

_2star_snowMonster* _2star_snowMonster::createhero() {
	auto _2star_snowMonster = _2star_snowMonster::create();
	_2star_snowMonster->picturename = "";
	_2star_snowMonster->picturenum = 0;
	_2star_snowMonster->autorelease();
	return _2star_snowMonster;
}

_3star_snowMonster::_3star_snowMonster() {
	//��д����Ӣ�۵�����
	type = SnowMonster;
	maxHealthPoint = 3564;
	maxBluePoint = 130;
	maxShieldPoint = 100;
	fee = 4;
	name = "SnowMonster";
	HealthPoint = 1100;//��ʼѪ��Ϊ���Ѫ��
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
}

_3star_snowMonster* _3star_snowMonster::createhero() {
	auto _3star_snowMonster = _3star_snowMonster::create();
	_3star_snowMonster->autorelease();
	return _3star_snowMonster;
}