#include "negativeCape.h"

negativeCape* negativeCape::createNegativeCape() {
	auto negativeCape = negativeCape::create();
	negativeCape->initWithFile("negativeCape.png"); //ͼ���ʼ��
	negativeCape->type = NEGATIVECAPE; //������������

	//���Լӳ��趨ֵ
	negativeCape->addAttackDistance = 0; //��������
	negativeCape->addMagicalArmor = 20; //��������
	negativeCape->addPhysicalArmor = 0; //������
	negativeCape->addBlue = 0; //����ֵ
	negativeCape->addBlueLimit = 0; //��������
	negativeCape->addCriticalHit = 0; //������
	negativeCape->addAttackSpeed = 0; //�����ٶ�
	negativeCape->addDamage = 0; //������
	negativeCape->addMagic = 0; //��ǿ
	negativeCape->addHealth = 0; //����ֵ
	negativeCape->addHealthLimit = 0; //��������

	negativeCape->retain();
	return negativeCape;
}
