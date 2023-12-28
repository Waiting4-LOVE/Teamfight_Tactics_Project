#include "darkKnight.h"

darkKnight::darkKnight() {
	type = DarkKnight;
	maxHealthPoint = 850;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = 850;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 70;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
}

darkKnight* darkKnight::createhero() {
	//auto darkKnight = new darkKnight();
	//darkKnight->set(100, 100);
	auto darkKnight = darkKnight::create();
	auto temp = Sprite::create("darkKnight.png");
	temp->setScale(0.22);
	darkKnight->bloodBar->setBarChangeRate(Point(1, 0));
	darkKnight->bloodBar->setType(ProgressTimer::Type::BAR);
	darkKnight->bloodBar->setMidpoint(Point(0, 1));
	darkKnight->bloodBar->setScaleX(0.22);
	darkKnight->scheduleUpdate();
	//darkKnight->addChild(hero1->bloodBar, 2);
	//darkKnight->picturename = "hero1.png";
	darkKnight->addChild(temp);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	darkKnight->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / darkKnight->speedAttack);
	darkKnight->autorelease();
	return darkKnight;
}


void darkKnight::releaseSkill() {

}

_2star_darkKnight::_2star_darkKnight() {
	//��д����Ӣ�۵�����
	type = DarkKnight;
	maxHealthPoint = 1530;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = 850;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 70;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
}

_2star_darkKnight* _2star_darkKnight::createhero() {
	auto _2star_darkKnight = _2star_darkKnight::create();
	_2star_darkKnight->picturename = "";
	_2star_darkKnight->picturenum = 0;
	_2star_darkKnight->autorelease();
	return _2star_darkKnight;
}

_3star_darkKnight::_3star_darkKnight() {
	//��д����Ӣ�۵�����
	type = DarkKnight;
	maxHealthPoint = 2754;
	maxBluePoint = 120;
	maxShieldPoint = 100;
	fee = 3;
	name = "DarkKnight";
	HealthPoint = 850;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 70;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 135;
	magicPoint = 100;
	speedAttack = 0.65f;
	distanceAttack = 1;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 55;
	defenceMagic = 55;
}

_3star_darkKnight* _3star_darkKnight::createhero() {
	auto _3star_darkKnight = _3star_darkKnight::create();
	_3star_darkKnight->autorelease();
	return _3star_darkKnight;
}