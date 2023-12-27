#include "knight.h"

knight::knight() {
	type = Knight;
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
	distanceAttack = 225;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

knight* knight::createhero() {
	//auto Hero1 = new hero1();
	//Hero1->set(100, 100);
	auto knight = knight::create();
	auto temp = Sprite::create("knight.png");
	temp->setScale(2.5);
	knight->bloodBar->setBarChangeRate(Point(1, 0));
	knight->bloodBar->setType(ProgressTimer::Type::BAR);
	knight->bloodBar->setMidpoint(Point(0, 1));
	knight->bloodBar->setScaleX(0.22);
	knight->scheduleUpdate();
	//knight->addChild(knight->bloodBar, 2);
	//knight->picturename = "knight.png";
	knight->addChild(temp);

	knight->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);




	//knight->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / knight->speedAttack);
	knight->autorelease();
	return knight;
}


void knight::releaseSkill() {

}

_2star_knight::_2star_knight() {
	//��д����Ӣ�۵�����
}

_2star_knight* _2star_knight::createhero() {
	auto _2star_knight = _2star_knight::create();
	_2star_knight->picturename = "";
	_2star_knight->picturenum = 0;
	_2star_knight->autorelease();
	return _2star_knight;
}

_3star_knight::_3star_knight() {
	//��д����Ӣ�۵�����
}

_3star_knight* _3star_knight::createhero() {
	auto _3star_knight = _3star_knight::create();
	_3star_knight->autorelease();
	return _3star_knight;
}