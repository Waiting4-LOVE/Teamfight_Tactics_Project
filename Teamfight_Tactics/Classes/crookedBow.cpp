#include "crookedBow.h"

crookedBow* crookedBow::createCrookedBow() {
	auto crookedBow = crookedBow::create();
	crookedBow->initWithFile("crookedBow.png"); //ͼ���ʼ��
	crookedBow->type = CROOKEDBOW; //������������

	//���Լӳ��趨ֵ
	crookedBow->addAttackDistance = 0; //��������
	crookedBow->addMagicalArmor = 0; //��������
	crookedBow->addPhysicalArmor = 0; //������
	crookedBow->addBlue = 0; //����ֵ
	crookedBow->addBlueLimit = 0; //��������
	crookedBow->addCriticalHit = 0; //������
	crookedBow->addAttackSpeed = 0.1; //�����ٶ�
	crookedBow->addDamage = 0; //������
	crookedBow->addMagic = 0; //��ǿ
	crookedBow->addHealth = 0; //����ֵ
	crookedBow->addHealthLimit = 0; //��������

	crookedBow->retain();
	return crookedBow;
}