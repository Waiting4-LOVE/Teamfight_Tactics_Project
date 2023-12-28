#include"ranger.h"

ranger::ranger() {
	type = Ranger;
	maxHealthPoint = 600;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 600;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 55;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

ranger* ranger::createhero() {
	//auto ranger = new ranger();
	//ranger->set(100, 100);
	auto ranger = ranger::create();
	auto temp = Sprite::create("ranger.png");
	temp->setScale(2.5);
	ranger->bloodBar->setBarChangeRate(Point(1, 0));
	ranger->bloodBar->setType(ProgressTimer::Type::BAR);
	ranger->bloodBar->setMidpoint(Point(0, 1));
	ranger->bloodBar->setScaleX(0.22);
	ranger->scheduleUpdate();
	//ranger->addChild(hero1->bloodBar, 2);
	//ranger->picturename = "ranger.png";
	ranger->addChild(temp);

	ranger->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	ranger->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / ranger->speedAttack);
	ranger->autorelease();
	return ranger;
}


void ranger::releaseSkill() {

}

_2star_ranger::_2star_ranger() {
	//��д����Ӣ�۵�����
	type = Ranger;
	maxHealthPoint = 1080;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 600;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 83;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_2star_ranger* _2star_ranger::createhero() {
	auto _2star_ranger = _2star_ranger::create();
	_2star_ranger->picturename = "";
	_2star_ranger->picturenum = 0;
	_2star_ranger->autorelease();
	return _2star_ranger;
}

_3star_ranger::_3star_ranger() {
	//��д����Ӣ�۵�����
	type = Ranger;
	maxHealthPoint = 1944;
	maxBluePoint = 30;
	maxShieldPoint = 0;
	fee = 2;
	name = "Ranger";
	HealthPoint = 600;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 124;
	magicPoint = 100;
	speedAttack = 0.75f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_3star_ranger* _3star_ranger::createhero() {
	auto _3star_ranger = _3star_ranger::create();
	_3star_ranger->autorelease();
	return _3star_ranger;
}