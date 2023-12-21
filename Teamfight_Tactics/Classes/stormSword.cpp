#include "stormSword.h"

stormSword* stormSword::createStormSword() {
	auto stormSword = stormSword::create();
	stormSword->initWithFile("stormSword.png"); //图像初始化
	stormSword->type = STORMSWORD; //设置属性种类
	//属性加成设定值
	stormSword->addAttackDistance = 0; //攻击距离
	stormSword->addMagicalArmor = 0; //法术护甲
	stormSword->addPhysicalArmor = 0; //物理护甲
	stormSword->addBlue = 0; //法术值
	stormSword->addBlueLimit = 0; //法术上限
	stormSword->addCriticalHit = 0; //暴击率
	stormSword->addAttackSpeed = 0; //攻击速度
	stormSword->addDamage = 10; //攻击力
	stormSword->addMagic = 0; //法强
	stormSword->addHealth = 0; //生命值
	stormSword->addHealthLimit = 0; //生命上限

	stormSword->retain();
	return stormSword;
}