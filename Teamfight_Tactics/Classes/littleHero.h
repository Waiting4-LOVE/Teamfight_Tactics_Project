#ifndef __LITTLE_HERO_SPRITE_HPP__
#define __LITTLE_HERO_SPRITE_HPP__

#include "cocos2d.h"
#include <math.h>
USING_NS_CC;

#define EXP_FOR_LEVEL(level) ((level) * (level) * (level) * 2 / 5 + 2 * (level))

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in littleHero.cpp\n");
}

struct packageSlot {
	packageSlot(bool a, int b) { this->isOccupied = a; this->isEquiped = b; }
	packageSlot() { this->isOccupied = false; this->isEquiped = 0; }
	bool isOccupied;
	int isEquiped;
};

class littleHero :public Sprite {
public:
	inline littleHero();
	inline littleHero(std::string picName);
	littleHero* m_attackTarget = nullptr; //��������ָ��
	ccArray* m_playerArray = ccArrayNew(9); //��ұ�ս������������
	ccArray* m_fightArray = ccArrayNew(15); //���ս��������������
	//chessInfo Used[5];

	/*----------------------װ����Ϣ---------------------*/
	ccArray* m_equipment = ccArrayNew(10); //װ������
	ccArray* m_unEquipedEpt = ccArrayNew(10); //δ����װ��
	int m_occupiedSlot = 0;
	bool m_isPackageOpened = false;
	packageSlot m_packageSlot[3][4] = {};
	Point slotPoint[12] = {};


	/*------------------------get��----------------------*/
	inline int getCurBlood() { return this->m_blood; }
	inline int getCoins() { return this->m_coins; }
	inline int getExp() { return this->m_exp; }
	inline Vec2 getCurPos() { return this->m_pos; }
	inline int getContinueWin() { return this->m_continueWin; }
	inline int getContinueWiLose() { return this->m_continueLose; }
	inline int getRound() { return this->m_round; }
	inline int getBonus(int sort); //���ؽ������

	/*------------------------set��----------------------*/
	inline void setAttackTarger(littleHero* target) { this->m_attackTarget = target; } //���ù�������
	inline void setPos(Vec2& pos) { this->m_pos = pos; } //����λ�ã�����ΪVec2
	inline void setPos(const int x, const int y) { this->m_pos.x = x, this->m_pos.y = y; } //����λ�ã�����Ϊ����������ֵ
	inline void setSrcPos() { this->m_pos = this->m_SrcPos; } //���س�ʼλ��
	inline void setPicture(const std::string picName) { this->m_picName = picName; } //����ͼƬ�ļ�����Ƥ��
	inline void hurt(const int delBlood) { this->m_blood -= delBlood; } //�ܵ��˺�������Ѫ��
	inline void addCoins(const int num) { this->m_coins += num; } //���ӽ��
	inline void delCoins(const int num) { this->m_coins -= num; } //���ٽ��
	inline void addExp(const int exp); //���Ӿ���
	inline bool isDead() { return this->m_blood <= 0; }
	void win(); //ս����ʤ����
	void lose(int hurt); //ս��ʧ�ܺ���
	CREATE_FUNC(littleHero);

	/*------------------------����ССӢ���ƶ�----------------------*/
	inline MoveTo* move(const Vec2 curPos); //�ƶ�ССӢ��״̬
	inline Vec2 updatePos(const Vec2& pos) { this->m_pos = pos; } //���µ�ǰλ��

protected:
	bool haveNewHero = false; //�ж��Ƿ���������
	Vec2 m_SrcPos = Vec2(505, 305); //��ʼλ��
	Vec2 m_pos = this->m_SrcPos; //��ǰλ��
	int m_maxBlood = 100; //���Ѫ��
	int m_blood = this->m_maxBlood; //��ǰѪ������ʼΪ100,
	const int m_moveSpeed = 300; //�ƶ��ٶ�
	int m_upExp = 10; //������Ҫ�ľ���ֵ
	int m_coins = 10; //���
	int m_exp = 0; //����ֵ
	int m_level = 1; //�ȼ�
	std::string m_picName = NULL; //ͼƬ����
	int m_round = 0; //��¼��Ϸ�غ���
	int m_continueWin = 0; //��¼��ʤ����
	int m_continueLose = 0; //��¼���ܳ���
	const int m_maxContinueWin = 7; //�����ʤ7�Σ��㲻�ټ���
	const int m_maxContinueLose = 7; //�������7�Σ��㲻�ټ���
	void countNextUPExp();
};
#endif //__LITTLE_HERO_SPRITE_HPP__

extern littleHero h1, h2, h3, h4, h5, h6, h7, h8;
