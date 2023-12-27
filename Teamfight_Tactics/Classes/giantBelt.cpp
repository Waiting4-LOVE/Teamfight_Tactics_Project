#include "giantBelt.h"

giantBelt* giantBelt::createGiantBelt() {
	auto giantBelt = giantBelt::create();
	giantBelt->initWithFile("giantBelt.png"); //ͼ���ʼ��
	giantBelt->type = GIANTBELT; //������������

	//���Լӳ��趨ֵ
	giantBelt->addAttackDistance = 0; //��������
	giantBelt->addMagicalArmor = 0; //��������
	giantBelt->addPhysicalArmor = 0; //������
	giantBelt->addBlue = 0; //����ֵ
	giantBelt->addBlueLimit = 0; //��������
	giantBelt->addCriticalHit = 0; //������
	giantBelt->addAttackSpeed = 0; //�����ٶ�
	giantBelt->addDamage = 0; //������
	giantBelt->addMagic = 0; //��ǿ
	giantBelt->addHealth = 150; //����ֵ
	giantBelt->addHealthLimit = 150; //��������

	giantBelt->retain();
	return giantBelt;
}
