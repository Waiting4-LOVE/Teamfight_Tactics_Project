#include "littleHero.h"

//littleHero::littleHero() :m_maxBlood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100),m_SrcPos(Vec2(505, 305)) {}

//littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

//littleHero::littleHero() {}

//littleHero::littleHero(std::string picName) : m_picName(picName) {}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	this->countNextUPExp(); //������������һ������ֵ
}


void littleHero::countNextUPExp() {
	if (this->m_exp >= EXP_FOR_LEVEL[this->m_level-1])
	{
		this->m_exp -= EXP_FOR_LEVEL[this->m_level-1];
		this->m_level++;
		return;
	}
}


int littleHero::getBonus(int sort) {
	int bonus = 0;
	//��ʤ�����µĽ���
	switch (sort) {
	case 3:
	case 4:
		bonus += 1;
		break;
	case 5:
	case 6:
		bonus += 2;
		break;
	case 7:
		bonus += 3;
		break;
	default:
		bonus += 0;
	}
	//��Ϣ�����µĽ���
	int temp = this->m_coins / 10;
	if (temp > 5) temp = 5; //��ཱ��5�����
	bonus += temp;

	return bonus;
}

void littleHero::win() {
	this->m_round += 1;
	this->m_continueLose = 0;
	if (this->m_continueWin < this->m_maxContinueWin) this->m_continueWin += 1;
	//���������
	int bonus = this->getBonus(this->m_continueWin);
	//���ӽ��
	this->addCoins(3 + bonus);//�غϽ���+2���غ�ʤ��+1�������ƶ�
	//���Ӿ���
	this->addExp(2);
}

void littleHero::lose(int hurt) {
	this->m_round += 1;
	this->m_continueWin = 0;
	if (this->m_continueLose < this->m_maxContinueLose) this->m_continueLose += 1;
	//���������
	int bonus = this->getBonus(this->m_continueLose);
	//���ӽ��
	this->addCoins(2 + bonus); //�غϽ���+2�������ƶ�
	//���Ӿ���
	this->addExp(2);
	//�ܵ��˺�
	this->hurt(hurt);
}