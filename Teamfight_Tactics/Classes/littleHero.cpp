#include "littleHero.h"

//littleHero::littleHero() :m_maxBlood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100),m_SrcPos(Vec2(505, 305)) {}

//littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

//littleHero::littleHero() {}

//littleHero::littleHero(std::string picName) : m_picName(picName) {}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	this->countNextUPExp(); //升级并计算下一级经验值
}
MoveTo* littleHero::move(const Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //计算移动距离
	double moveSec = dis / this->m_moveSpeed; //得到运动时间
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->updatePos(curPos);
	return moveTo;
}

void littleHero::countNextUPExp() {
	if (this->m_exp >= EXP_FOR_LEVEL[this->m_level])
	{
		this->m_exp -= EXP_FOR_LEVEL[this->m_level];
		this->m_level++;
		return;
	}
}


int littleHero::getBonus(int sort) {
	int bonus = 0;
	//连胜机制下的奖励
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
	//利息机制下的奖励
	int temp = this->m_coins / 10;
	if (temp > 5) temp = 5; //最多奖励5个金币
	bonus += temp;

	return bonus;
}

void littleHero::win() {
	this->m_round += 1;
	this->m_continueLose = 0;
	if (this->m_continueWin < this->m_maxContinueWin) this->m_continueWin += 1;
	//计算额外金币
	int bonus = this->getBonus(this->m_continueWin);
	//增加金币
	this->addCoins(3 + bonus);//回合结束+2，回合胜利+1，奖励制度
	//增加经验
	this->addExp(2);
}

void littleHero::lose(int hurt) {
	this->m_round += 1;
	this->m_continueWin = 0;
	if (this->m_continueLose < this->m_maxContinueLose) this->m_continueLose += 1;
	//计算额外金币
	int bonus = this->getBonus(this->m_continueLose);
	//增加金币
	this->addCoins(2 + bonus); //回合结束+2，奖励制度
	//增加经验
	this->addExp(2);
	//受到伤害
	this->hurt(hurt);
}