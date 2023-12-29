#include "uselessStick.h"

uselessStick* uselessStick::createUselessStick() {
	auto uselessStick = uselessStick::create();
	uselessStick->initWithFile("uselessStick.png"); //图像初始化
	uselessStick->type = USELESSSTICK; //设置属性种类

	//属性加成设定值
	uselessStick->addAttackDistance = 0; //攻击距离
	uselessStick->addMagicalArmor = 0; //法术护甲
	uselessStick->addPhysicalArmor = 0; //物理护甲
	uselessStick->addBlue = 0; //法术值
	uselessStick->addBlueLimit = 0; //法术上限
	uselessStick->addCriticalHit = 0; //暴击率
	uselessStick->addAttackSpeed = 0; //攻击速度
	uselessStick->addDamage = 0; //攻击力
	uselessStick->addMagic = 10; //法强
	uselessStick->addHealth = 0; //生命值
	uselessStick->addHealthLimit = 0; //生命上限

	uselessStick->retain();
	return uselessStick;
}
