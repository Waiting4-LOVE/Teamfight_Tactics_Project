#include "tearsOfTheGoddess.h"

tearsOfTheGoddess* tearsOfTheGoddess::createTearsOfTheGoddess() {
	auto tearsOfTheGoddess = tearsOfTheGoddess::create();
	tearsOfTheGoddess->initWithFile("tearsOfTheGoddess.png"); //图像初始化
	tearsOfTheGoddess->type = TEARSOFTHEGODDESS; //设置属性种类

	//属性加成设定值
	tearsOfTheGoddess->addAttackDistance = 0; //攻击距离
	tearsOfTheGoddess->addMagicalArmor = 0; //法术护甲
	tearsOfTheGoddess->addPhysicalArmor = 0; //物理护甲
	tearsOfTheGoddess->addBlue = 15; //法术值
	tearsOfTheGoddess->addBlueLimit = 15; //法术上限
	tearsOfTheGoddess->addCriticalHit = 0; //暴击率
	tearsOfTheGoddess->addAttackSpeed = 0; //攻击速度
	tearsOfTheGoddess->addDamage = 0; //攻击力
	tearsOfTheGoddess->addMagic = 0; //法强
	tearsOfTheGoddess->addHealth = 0; //生命值
	tearsOfTheGoddess->addHealthLimit = 0; //生命上限

	tearsOfTheGoddess->retain();
	return tearsOfTheGoddess;
}