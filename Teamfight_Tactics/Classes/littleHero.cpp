#include "littleHero.h"

//littleHero::littleHero() :m_maxBlood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100),m_SrcPos(Vec2(505, 305)) {}

//littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

//littleHero::littleHero() {}

//littleHero::littleHero(std::string picName) : m_picName(picName) {}

void littleHero::addExp(const int exp) {
	this->m_exp += exp;
	this->countNextUPExp(); //升级并计算下一级经验值
}


void littleHero::countNextUPExp() {
	if (this->m_exp >= EXP_FOR_LEVEL[this->m_level-1])
	{
		this->m_exp -= EXP_FOR_LEVEL[this->m_level-1];
		this->m_level++;
		return;
	}
}


/*littleHero* littleHero::createLH(string picture_name)
{
	auto temp = Sprite::create(picture_name);
	auto lh = new littleHero();
	lh->LHAnimation(picture_name, 9, lh, 0.08f, -1);
	lh->addChild(temp);
	return lh;
}*/

void littleHero::LHAnimation(std::string picturename, const int picturenum, Sprite* sprite,const float speed, const int loop)
{
	Animation* animation = Animation::create();

	const char* picname = picturename.c_str();

	for (int i = 1; i <= picturenum; i++) {
		char key[32];
		sprintf(key, picname, i);
		animation->addSpriteFrameWithFile(key);
	}

	animation->setDelayPerUnit(speed); //设定速度
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(loop); //loop=-1,循环
	auto action = Animate::create(animation);
	action->setTag(-2);
	//sp->runAction(animate);
	sprite->runAction(action);
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

void littleHero::reset()
{
	m_playerArray = ccArrayNew(100);   //玩家备战区的棋子数组
	m_fightArray = ccArrayNew(100);
	m_maxBlood = 100;   //生命值上限
	m_blood = m_maxBlood; //生命值
	m_level = 1; //玩家等级
	m_exp= 0;   //经验值
	m_coins = 10;  //金币
	/*occupied_slot = 0;
	is_package_opened = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i < 3)
		{
			for (int j = 0; j < 4; j++)
			{
				packageSlot[i][j] = PackageSlot(0, 0);

			}
		}
		slotPoint[i] = Point(0, 0);
	}*/
}
