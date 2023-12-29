#include"snowman.h"

snowman::snowman() {
	type = Snowman;
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

void snowman::releaseSkill() {

}

_2star_snowman::_2star_snowman() {
	type = _2star_Snowman;
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
	star = 2;
	//��д����Ӣ�۵�����
}

_2star_snowman* _2star_snowman::createhero() {
	auto _2star_snowman = _2star_snowman::create();
	auto temp = Sprite::create("snowman.png");
	_2star_snowman->picturename = "";
	_2star_snowman->picturenum = 0;
	_2star_snowman->autorelease();
	return _2star_snowman;
}

_3star_snowman::_3star_snowman() {
	type = _3star_Snowman;
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
	star = 3;
	//��д����Ӣ�۵�����
}

_3star_snowman* _3star_snowman::createhero() {
	auto _3star_snowman = _3star_snowman::create();
	_3star_snowman->autorelease();
	return _3star_snowman;
}