#include "cannedPig.h"

cannedPig::cannedPig() {
	type = CannedPig;
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
	distanceAttack = 15;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
	star = 1;
}

cannedPig* cannedPig::createhero() {
	//auto cannedPig = new hero1();
	//cannedPig->set(100, 100);
	auto cannedPig = cannedPig::create();
	auto temp = Sprite::create("cannedPig.png");
	temp->setScale(2.5);
	cannedPig->bloodBar->setBarChangeRate(Point(1, 0));
	cannedPig->bloodBar->setType(ProgressTimer::Type::BAR);
	cannedPig->bloodBar->setMidpoint(Point(0, 1));
	cannedPig->bloodBar->setScaleX(0.22);
	cannedPig->scheduleUpdate();
	//cannedPig->addChild(cannedPig->bloodBar, 2);
	//cannedPig->picturename = "cannedPig.png";
	cannedPig->addChild(temp);

	cannedPig->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	cannedPig->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / cannedPig->speedAttack);
	cannedPig->autorelease();
	return cannedPig;
}

void cannedPig::attack(float dt)
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
			shootbullet("wind.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void cannedPig::releaseSkill() {

}

_2star_cannedPig::_2star_cannedPig() {
	//��д����Ӣ�۵�����
}

_2star_cannedPig* _2star_cannedPig::createhero() {
	auto _2star_cannedPig = _2star_cannedPig::create();
	auto temp = Sprite::create("cannedPig.png");
	temp->setScale(2.5);
	_2star_cannedPig->addChild(temp);
	_2star_cannedPig->autorelease();
	return _2star_cannedPig;
}

_3star_cannedPig::_3star_cannedPig() {
	//��д����Ӣ�۵�����
}

_3star_cannedPig* _3star_cannedPig::createhero() {
	auto _3star_cannedPig = _3star_cannedPig::create();
	auto temp = Sprite::create("cannedPig.png");
	temp->setScale(2.5);
	_3star_cannedPig->addChild(temp);
	_3star_cannedPig->autorelease();
	return _3star_cannedPig;
}