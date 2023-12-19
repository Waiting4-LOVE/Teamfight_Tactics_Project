#include"hero1.h"


hero1::hero1() {
	maxHealthPoint = 100;
	maxBluePoint = 100;
	maxShieldPoint = 100;
	fee = 2;
	name = "yao yao don't know";
	HealthPoint = 100;//初始血量为最大血量
	BluePoint = 0;//初始蓝量为0
	shieldPoint = 0;//初始护盾值为0
	physicsAttackPoint = 10;
	magicPoint = 0;
	speedAttack = 5;
	distanceAttack = 10;
	blueAttack = maxBluePoint;
	criticalChance = 0.05;
	defencePhysics = 5;
	defenceMagic = 5;
}

hero1* hero1::createhero() {
	auto hero1 = hero1::create();
	hero1->autorelease();
	return hero1;
}


void hero1::releaseSkill() {
	
}