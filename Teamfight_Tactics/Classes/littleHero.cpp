#include "littleHero.h"

//littleHero::littleHero() {}

//littleHero::littleHero(std::string picName) : m_picName(picName) {}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	this->countNextUPExp(); //������������һ������ֵ
}

MoveTo* littleHero::move(const Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //�����ƶ�����
	double moveSec = dis / this->m_moveSpeed; //�õ��˶�ʱ��
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->updatePos(curPos);
	return moveTo;
}

void littleHero::countNextUPExp() {
	if (this->m_exp >= EXP_FOR_LEVEL[this->m_level - 1])
	{
		this->m_exp -= EXP_FOR_LEVEL[this->m_level - 1];
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

void littleHero::remain() {
	this->m_playerArray = ccArrayNew(9); //��ұ�ս����������
	this->m_fightArray = ccArrayNew(15);
	this->m_maxBlood = 100;
	this->m_blood = 100;
	this->m_level = 1;
	this->m_upExp = this->EXP_FOR_LEVEL[0];
	this->m_coins = 10;
	this->m_exp = 0;
	this->m_round = 0;
	this->m_continueWin = 0;
	this->m_continueLose = 0;
	this->m_occupiedSlot = false;
	this->m_isPackageOpened = 0;
	for (int i = 0; i < 12; i++){
		if (i < 3){
			for (int j = 0; j < 4; j++){
				this->m_packageSlot[i][j] = packageSlot(0, 0);
			}
		}
		this->m_slotPoint[i] = Point(0, 0);
	}
}