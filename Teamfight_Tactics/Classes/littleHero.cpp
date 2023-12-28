#include "littleHero.h"

//littleHero::littleHero() :m_maxBlood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100),m_SrcPos(Vec2(505, 305)) {}

//littleHero::littleHero(std::string picName) : m_blood(100), m_moveSpeed(300), m_coins(0), m_exp(0), m_level(1), m_upExp(100), m_picName(picName) {}

//littleHero::littleHero() {}

//littleHero::littleHero(std::string picName) : m_picName(picName) {}

void littleHero::addExp(const int exp) {
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




void littleHero::LHAnimation(string picturename, const int picturenum, Sprite* sprite, Point location, const float speed, const int loop)
{
	Animation* animation = Animation::create();

	const char* picname = picturename.c_str();

	for (int i = 1; i <= picturenum; i++) {
		char key[32];
		sprintf(key, picname, i);
		animation->addSpriteFrameWithFile(key);
	}

	animation->setDelayPerUnit(speed); //�趨�ٶ�
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(loop); //loop=-1,ѭ��
	auto action = Animate::create(animation);
	action->setTag(-2);
	//sp->runAction(animate);
	sprite->runAction(action);
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

void littleHero::reset()
{
	m_playerArray = ccArrayNew(100);   //��ұ�ս������������
	m_fightArray = ccArrayNew(100);
	m_maxBlood = 100;   //����ֵ����
	m_blood = m_maxBlood; //����ֵ
	m_level = 1; //��ҵȼ�
	m_exp= 0;   //����ֵ
	m_coins = 10;  //���
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
