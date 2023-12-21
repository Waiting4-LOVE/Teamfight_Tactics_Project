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
	/*�����ӽ���װ���ӳ�*/
	int getaddAttackDistance() { return this->addAttackDistance; } //��������
	int getaddHealthLimit() { return this->addHealthLimit; } //��������
	int getaddHealth() { return this->addHealth; } //��ǰ����ֵ
	int getaddPhysicalArmor() { return this->addPhysicalArmor; } //������
	int getaddMagicalArmor() { return this->addMagicalArmor; } //��������
	double getaddAttackSpeed() { return this->addAttackSpeed; } //����
	int getaddDamage() { return this->addDamage; } //������
	int getaddMagic() { return this->addMagic; } //��ǿ
	int getaddBlue() { return this->addBlue; } //����
	int getaddBlueLimit() { return this->addBlueLimit; } //��������
	double getcriticalHit() { return this->addCriticalHit; } //������
	int type;//װ������
protected:
	int addAttackDistance; //��������
	int addHealthLimit;    //��������
	int addHealth;         //��ǰ����ֵ
	int addPhysicalArmor;  //������
	int addMagicalArmor;   //��������
	double addAttackSpeed; //����
	int addDamage;         //������
	int addMagic;          //��ǿ
	int addBlue;           //����
	int addBlueLimit;      //��������
	double addCriticalHit;    //������
private:
	int searchDistance = 30;
};
#endif