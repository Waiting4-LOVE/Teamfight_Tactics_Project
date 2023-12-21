#include "littleHero.h"

//littleHero::littleHero() :m_maxBlood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100),m_SrcPos(Vec2(505, 305)) {}

//littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

/*void littleHero::addExp(int exp) {
	this->m_exp += exp;
	if (this->m_exp > this->m_upExp) {
		this->m_exp -= this->m_upExp;
		this->m_level++;
	} //升级
}
*/
MoveTo* littleHero::move(const Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //计算移动距离
	double moveSec = dis / this->m_moveSpeed; //得到运动时间
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->updatePos(curPos);
	return moveTo;
}
