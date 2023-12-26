#include"ranger.h"

ranger::ranger() {
	type = Ranger;
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


	//hero1->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / ranger->speedAttack);
	ranger->autorelease();
	return ranger;
}


void ranger::releaseSkill() {

}

_2star_ranger::_2star_ranger() {
	//��д����Ӣ�۵�����
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
}

_3star_ranger* _3star_ranger::createhero() {
	auto _3star_ranger = _3star_ranger::create();
	_3star_ranger->autorelease();
	return _3star_ranger;
}