#include "hauberk.h"

hauberk* hauberk::createHauberk() {
	auto hauberk = hauberk::create();
	hauberk->initWithFile("hauberk.png"); //ͼ���ʼ��
	hauberk->type = HAUBERK; //������������

	//���Լӳ��趨ֵ
	hauberk->addAttackDistance = 0; //��������
	hauberk->addMagicalArmor = 0; //��������
	hauberk->addPhysicalArmor = 20; //������
	hauberk->addBlue = 0; //����ֵ
	hauberk->addBlueLimit = 0; //��������
	hauberk->addCriticalHit = 0; //������
	hauberk->addAttackSpeed = 0; //�����ٶ�
	hauberk->addDamage = 0; //������
	hauberk->addMagic = 0; //��ǿ
	hauberk->addHealth = 0; //����ֵ
	hauberk->addHealthLimit = 0; //��������

	hauberk->retain();
	return hauberk;
}