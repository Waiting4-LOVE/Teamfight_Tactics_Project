#include "boxingGloves.h"

boxingGloves* boxingGloves::createBoxingGloves() {
	auto boxingGloves = boxingGloves::create();
	boxingGloves->initWithFile("boxingGloves.png"); //图像初始化
	boxingGloves->type = BOXINGLOVES; //设置属性种类

	//属性加成设定值
	boxingGloves->addAttackDistance = 0; //攻击距离
	boxingGloves->addMagicalArmor = 0; //法术护甲
	boxingGloves->addPhysicalArmor = 0; //物理护甲
	boxingGloves->addBlue = 0; //法术值
	boxingGloves->addBlueLimit = 0; //法术上限
	boxingGloves->addCriticalHit = 0.2; //暴击率
	boxingGloves->addAttackSpeed = 0; //攻击速度
	boxingGloves->addDamage = 0; //攻击力
	boxingGloves->addMagic = 0; //法强
	boxingGloves->addHealth = 0; //生命值
	boxingGloves->addHealthLimit = 0; //生命上限

	boxingGloves->retain();
	return boxingGloves;
}
