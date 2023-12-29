#include "giantBelt.h"

giantBelt* giantBelt::createGiantBelt() {
	auto giantBelt = giantBelt::create();
	giantBelt->initWithFile("giantBelt.png"); //图像初始化
	giantBelt->type = GIANTBELT; //设置属性种类

	//属性加成设定值
	giantBelt->addAttackDistance = 0; //攻击距离
	giantBelt->addMagicalArmor = 0; //法术护甲
	giantBelt->addPhysicalArmor = 0; //物理护甲
	giantBelt->addBlue = 0; //法术值
	giantBelt->addBlueLimit = 0; //法术上限
	giantBelt->addCriticalHit = 0; //暴击率
	giantBelt->addAttackSpeed = 0; //攻击速度
	giantBelt->addDamage = 0; //攻击力
	giantBelt->addMagic = 0; //法强
	giantBelt->addHealth = 150; //生命值
	giantBelt->addHealthLimit = 150; //生命上限

	giantBelt->retain();
	return giantBelt;
}
