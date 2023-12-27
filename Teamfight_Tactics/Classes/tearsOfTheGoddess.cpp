#include "tearsOfTheGoddess.h"

tearsOfTheGoddess* tearsOfTheGoddess::createTearsOfTheGoddess() {
	auto tearsOfTheGoddess = tearsOfTheGoddess::create();
	tearsOfTheGoddess->initWithFile("tearsOfTheGoddess.png"); //ͼ���ʼ��
	tearsOfTheGoddess->type = TEARSOFTHEGODDESS; //������������

	//���Լӳ��趨ֵ
	tearsOfTheGoddess->addAttackDistance = 0; //��������
	tearsOfTheGoddess->addMagicalArmor = 0; //��������
	tearsOfTheGoddess->addPhysicalArmor = 0; //������
	tearsOfTheGoddess->addBlue = 15; //����ֵ
	tearsOfTheGoddess->addBlueLimit = 15; //��������
	tearsOfTheGoddess->addCriticalHit = 0; //������
	tearsOfTheGoddess->addAttackSpeed = 0; //�����ٶ�
	tearsOfTheGoddess->addDamage = 0; //������
	tearsOfTheGoddess->addMagic = 0; //��ǿ
	tearsOfTheGoddess->addHealth = 0; //����ֵ
	tearsOfTheGoddess->addHealthLimit = 0; //��������

	tearsOfTheGoddess->retain();
	return tearsOfTheGoddess;
}