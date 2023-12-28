#include"master.h"

master::master() {
	type = Master;
	maxHealthPoint = 650;
	maxBluePoint = 40;
	maxShieldPoint = 0;
	fee = 3;
	name = "Master";
	HealthPoint = 650;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 40;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

master* master::createhero() {
	//auto master = new master();
	//master->set(100, 100);
	auto master = master::create();
	auto temp = Sprite::create("master.png");
	temp->setScale(2.5);
	master->bloodBar->setBarChangeRate(Point(1, 0));
	master->bloodBar->setType(ProgressTimer::Type::BAR);
	master->bloodBar->setMidpoint(Point(0, 1));
	master->bloodBar->setScaleX(0.22);
	master->scheduleUpdate();
	//master->addChild(master->bloodBar, 2);
	//master->picturename = "master.png";
	master->addChild(temp);

	master->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);


	master->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / master->speedAttack);
	master->autorelease();
	return master;
}


void master::releaseSkill() {

}

_2star_master::_2star_master() {
	//��д����Ӣ�۵�����
	type = Master;
	maxHealthPoint = 1170;
	maxBluePoint = 40;
	maxShieldPoint = 0;
	fee = 3;
	name = "Master";
	HealthPoint = 650;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 60;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_2star_master* _2star_master::createhero() {
	auto _2star_master = _2star_master::create();
	_2star_master->picturename = "";
	_2star_master->picturenum = 0;
	_2star_master->autorelease();
	return _2star_master;
}

_3star_master::_3star_master() {
	//��д����Ӣ�۵�����
	type = Master;
	maxHealthPoint = 2106;
	maxBluePoint = 40;
	maxShieldPoint = 0;
	fee = 3;
	name = "Master";
	HealthPoint = 650;//��ʼѪ��Ϊ���Ѫ��
	BluePoint = 0;//��ʼ����Ϊ0
	shieldPoint = 0;//��ʼ����ֵΪ0
	physicsAttackPoint = 90;
	magicPoint = 100;
	speedAttack = 0.7f;
	distanceAttack = 3;
	blueAttack = maxBluePoint;
	criticalChance = 0.25;
	defencePhysics = 20;
	defenceMagic = 20;
}

_3star_master* _3star_master::createhero() {
	auto _3star_master = _3star_master::create();
	_3star_master->autorelease();
	return _3star_master;
}