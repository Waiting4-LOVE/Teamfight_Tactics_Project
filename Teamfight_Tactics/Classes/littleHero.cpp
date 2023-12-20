#include "littleHero.h"

littleHero::littleHero() :m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100) {}

littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	if (this->m_exp > this->m_upExp) {
		this->m_exp -= this->m_upExp;
		this->m_level++;
	} //����
}

MoveTo* littleHero::move(const Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //�����ƶ�����
	double moveSec = dis / this->m_moveSpeed; //�õ��˶�ʱ��
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->updatePos(curPos);
	return moveTo;
}