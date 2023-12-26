#include "hauberk.h"

hauberk* hauberk::createHauberk() {
	auto hauberk = hauberk::create();
	hauberk->initWithFile("hauberk.png"); //图像初始化
	hauberk->type = HAUBERK; //设置属性种类

	//属性加成设定值
	hauberk->addAttackDistance = 0; //攻击距离
	hauberk->addMagicalArmor = 0; //法术护甲
	hauberk->addPhysicalArmor = 20; //物理护甲
	hauberk->addBlue = 0; //法术值
	hauberk->addBlueLimit = 0; //法术上限
	hauberk->addCriticalHit = 0; //暴击率
	hauberk->addAttackSpeed = 0; //攻击速度
	hauberk->addDamage = 0; //攻击力
	hauberk->addMagic = 0; //法强
	hauberk->addHealth = 0; //生命值
	hauberk->addHealthLimit = 0; //生命上限

	hauberk->retain();
	return hauberk;
}