#include "negativeCape.h"

negativeCape* negativeCape::createNegativeCape() {
	auto negativeCape = negativeCape::create();
	negativeCape->initWithFile("negativeCape.png"); //图像初始化
	negativeCape->type = NEGATIVECAPE; //设置属性种类

	//属性加成设定值
	negativeCape->addAttackDistance = 0; //攻击距离
	negativeCape->addMagicalArmor = 20; //法术护甲
	negativeCape->addPhysicalArmor = 0; //物理护甲
	negativeCape->addBlue = 0; //法术值
	negativeCape->addBlueLimit = 0; //法术上限
	negativeCape->addCriticalHit = 0; //暴击率
	negativeCape->addAttackSpeed = 0; //攻击速度
	negativeCape->addDamage = 0; //攻击力
	negativeCape->addMagic = 0; //法强
	negativeCape->addHealth = 0; //生命值
	negativeCape->addHealthLimit = 0; //生命上限

	negativeCape->retain();
	return negativeCape;
}
