#include "stormSword.h"

stormSword* stormSword::createStormSword() {
	auto stormSword = stormSword::create();
	stormSword->initWithFile("stormSword.png"); //ͼ���ʼ��
	stormSword->type = STORMSWORD; //������������
	//���Լӳ��趨ֵ
	stormSword->addAttackDistance = 0; //��������
	stormSword->addMagicalArmor = 0; //��������
	stormSword->addPhysicalArmor = 0; //������
	stormSword->addBlue = 0; //����ֵ
	stormSword->addBlueLimit = 0; //��������
	stormSword->addCriticalHit = 0; //������
	stormSword->addAttackSpeed = 0; //�����ٶ�
	stormSword->addDamage = 10; //������
	stormSword->addMagic = 0; //��ǿ
	stormSword->addHealth = 0; //����ֵ
	stormSword->addHealthLimit = 0; //��������

	stormSword->retain();
	return stormSword;
}