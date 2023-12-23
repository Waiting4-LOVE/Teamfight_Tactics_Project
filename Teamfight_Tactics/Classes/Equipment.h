#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__
#include "cocos2d.h"
USING_NS_CC;

#define STORMSWORD 1
#define CROOKEDBOW 2
#define BOXINGLOVES 3
#define GIANTBELT 4
#define HAUBERK 5
#define NEGATIVECAPE 6
#define TEARSOFTHEGODDESS 7
#define USELESSSTICK 8

enum class EquipmentType {
	None,
	stromSword,
	crookedBow,
	boxingGloves,
	giantBelt,
	hauberk,
	negativeCape,
	tearsOfTheGoddess,
	uselessStick
};

class Equipment:public Sprite {
public:
	/*对棋子进行装备加成*/
	int getaddAttackDistance() { return this->addAttackDistance; } //攻击距离
	int getaddHealthLimit() { return this->addHealthLimit; } //生命上限
	int getaddHealth() { return this->addHealth; } //当前生命值
	int getaddPhysicalArmor() { return this->addPhysicalArmor; } //物理护甲
	int getaddMagicalArmor() { return this->addMagicalArmor; } //法术护甲
	double getaddAttackSpeed() { return this->addAttackSpeed; } //攻速
	int getaddDamage() { return this->addDamage; } //攻击力
	int getaddMagic() { return this->addMagic; } //法强
	int getaddBlue() { return this->addBlue; } //法力
	int getaddBlueLimit() { return this->addBlueLimit; } //法力上限
	double getcriticalHit() { return this->addCriticalHit; } //暴击率
	int type;//装备类型
protected:
	int addAttackDistance; //攻击距离
	int addHealthLimit;    //生命上限
	int addHealth;         //当前生命值
	int addPhysicalArmor;  //物理护甲
	int addMagicalArmor;   //法术护甲
	double addAttackSpeed; //攻速
	int addDamage;         //攻击力
	int addMagic;          //法强
	int addBlue;           //法力
	int addBlueLimit;      //法力上限
	double addCriticalHit;    //暴击率
private:
	int searchDistance = 30;
};
#endif