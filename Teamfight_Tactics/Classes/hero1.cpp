#include"hero1.h"


hero1::hero1() {
	type = Hero1;
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
	speedAttack = 0.5;
	distanceAttack =3;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

hero1* hero1::createhero() {
	//auto Hero1 = new hero1();
	//Hero1->set(100, 100);
	auto hero1 = hero1::create();
	auto temp = Sprite::create("hero1.png");
	temp->setScale(2.5);
	hero1->bloodBar->setBarChangeRate(Point(1, 0));
	hero1->bloodBar->setType(ProgressTimer::Type::BAR);
	hero1->bloodBar->setMidpoint(Point(0, 1));
	hero1->bloodBar->setScaleX(0.22);
	hero1->blueBar->setBarChangeRate(Point(1, 0));
	hero1->blueBar->setType(ProgressTimer::Type::BAR);
	hero1->blueBar->setMidpoint(Point(0, 1));
	hero1->blueBar->setScaleX(0.22);

	hero1->scheduleUpdate();
	//hero1->addChild(hero1->bloodBar, 2);
	//hero1->picturename = "hero1.png";
	hero1->addChild(temp);

	hero1->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

	

	
	hero1->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1.0f / hero1->speedAttack);
	hero1->autorelease();
	return hero1;
}


void hero1::releaseSkill() {
	
}

_2star_hero1::_2star_hero1(){
	//��д����Ӣ�۵�����
}

_2star_hero1* _2star_hero1::createhero(){
	auto _2star_hero1 = _2star_hero1::create();
	_2star_hero1->picturename = "";
	_2star_hero1->picturenum = 0;
	_2star_hero1->autorelease();
	return _2star_hero1;
}

_3star_hero1::_3star_hero1(){
	//��д����Ӣ�۵�����
}

_3star_hero1* _3star_hero1::createhero() {
	auto _3star_hero1 = _3star_hero1::create();
	_3star_hero1->autorelease();
	return _3star_hero1;
}