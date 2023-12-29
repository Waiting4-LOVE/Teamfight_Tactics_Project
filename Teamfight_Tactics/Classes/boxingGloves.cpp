#include "boxingGloves.h"

boxingGloves* boxingGloves::createBoxingGloves() {
	auto boxingGloves = boxingGloves::create();
	boxingGloves->initWithFile("boxingGloves.png"); //ͼ���ʼ��
	boxingGloves->type = BOXINGLOVES; //������������

	//���Լӳ��趨ֵ
	boxingGloves->addAttackDistance = 0; //��������
	boxingGloves->addMagicalArmor = 0; //��������
	boxingGloves->addPhysicalArmor = 0; //������
	boxingGloves->addBlue = 0; //����ֵ
	boxingGloves->addBlueLimit = 0; //��������
	boxingGloves->addCriticalHit = 0.2; //������
	boxingGloves->addAttackSpeed = 0; //�����ٶ�
	boxingGloves->addDamage = 0; //������
	boxingGloves->addMagic = 0; //��ǿ
	boxingGloves->addHealth = 0; //����ֵ
	boxingGloves->addHealthLimit = 0; //��������

	boxingGloves->retain();
	return boxingGloves;
}
