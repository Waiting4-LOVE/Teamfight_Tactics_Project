#include "uselessStick.h"

uselessStick* uselessStick::createUselessStick() {
	auto uselessStick = uselessStick::create();
	uselessStick->initWithFile("uselessStick.png"); //ͼ���ʼ��
	uselessStick->type = USELESSSTICK; //������������

	//���Լӳ��趨ֵ
	uselessStick->addAttackDistance = 0; //��������
	uselessStick->addMagicalArmor = 0; //��������
	uselessStick->addPhysicalArmor = 0; //������
	uselessStick->addBlue = 0; //����ֵ
	uselessStick->addBlueLimit = 0; //��������
	uselessStick->addCriticalHit = 0; //������
	uselessStick->addAttackSpeed = 0; //�����ٶ�
	uselessStick->addDamage = 0; //������
	uselessStick->addMagic = 10; //��ǿ
	uselessStick->addHealth = 0; //����ֵ
	uselessStick->addHealthLimit = 0; //��������

	uselessStick->retain();
	return uselessStick;
}
