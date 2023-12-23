#include "crookedBow.h"

crookedBow* crookedBow::createCrookedBow() {
	auto crookedBow = crookedBow::create();
	crookedBow->initWithFile("crookedBow.png"); //图像初始化
	crookedBow->type = CROOKEDBOW; //设置属性种类

	//属性加成设定值
	crookedBow->addAttackDistance = 0; //攻击距离
	crookedBow->addMagicalArmor = 0; //法术护甲
	crookedBow->addPhysicalArmor = 0; //物理护甲
	crookedBow->addBlue = 0; //法术值
	crookedBow->addBlueLimit = 0; //法术上限
	crookedBow->addCriticalHit = 0; //暴击率
	crookedBow->addAttackSpeed = 0.1; //攻击速度
	crookedBow->addDamage = 0; //攻击力
	crookedBow->addMagic = 0; //法强
	crookedBow->addHealth = 0; //生命值
	crookedBow->addHealthLimit = 0; //生命上限

	crookedBow->retain();
	return crookedBow;
}