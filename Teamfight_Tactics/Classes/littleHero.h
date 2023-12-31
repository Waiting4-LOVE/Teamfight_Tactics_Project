#pragma once
#include "cocos2d.h"
#include"GameData.h"
#include <math.h>
#include <string>
using namespace cocos2d;

USING_NS_CC;


struct packageSlot {
	packageSlot(bool a, int b) { this->isOccupied = a; this->isEquiped = b; }
	packageSlot() { this->isOccupied = false; this->isEquiped = 0; }
	bool isOccupied;
	int isEquiped;
};

class littleHero :public Sprite {
public:
	//inline littleHero();
	//inline littleHero(std::string picName);
	littleHero* createLH(std::string picture_name);
	bool haveNewHero = false; //�ж��Ƿ���������
	littleHero* m_attackTarget = nullptr; //��������ָ��
	ccArray* m_playerArray = ccArrayNew(9); //��ұ�ս������������
	ccArray* m_fightArray = ccArrayNew(15); //���ս��������������
	int chessnumber[ChessNumber] = {};
	int EXP_FOR_LEVEL[10] = { 2,2,6,10,20,36,48,64,76,80 };//ÿ���������辭��ֵ
	chessInfo Used[5];




	/*----------------------��ʾ---------------------*/
	std::string picturename;   //ͼƬ����
	int picturenum;       //ͼƬ����
	void LHAnimation(std::string picturename, const int picturenum, Sprite* sprite, const float speed, const int loop);

	//Sprite* bloodFrame = Sprite::create("BloodFrame.png");
	//ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.png"));
	//void bloodUpdate(float dt);

	/*----------------------װ����Ϣ---------------------*/
	bool haveNewEpt = false;
	ccArray* m_equipment = ccArrayNew(10); //װ������
	ccArray* m_unEquipedEpt = ccArrayNew(10); //δ����װ��
	int m_occupiedSlot = 0;
	bool m_isPackageOpened = false;
	packageSlot m_packageSlot[2][2] = {};
	Point slotPoint[4] = {};
	eptInfo randEpt[4]; //���ѡ4��װ��

	/*------------------------get��----------------------*/
	inline int getCurBlood() { return this->m_blood; }
	inline int getCoins() { return this->m_coins; }
	inline int getExp() { return this->m_exp; }
	inline int getLevel() { return this->m_level; }
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
	inline void setCurBlood(const int blood) { this->m_blood = blood; } //���õ�ǰѪ��
	//inline void setPicture(const std::string picName) { this->m_picName = picName; } //����ͼƬ�ļ�����Ƥ��
	inline void hurt(const int delBlood) { this->m_blood -= delBlood; } //�ܵ��˺�������Ѫ��
	bool CoinsIsChange = false;
	inline void addCoins(const int num) { this->m_coins += num; CoinsIsChange = true; } //���ӽ��
	inline void delCoins(const int num) { this->m_coins -= num; CoinsIsChange = true; } //���ٽ��
	inline void addExp(const int exp); //���Ӿ���
	inline bool isDead() { return this->m_blood <= 0; }
	void win();
	void lose(int hurt); //ս��ʧ�ܺ���
	void reset(); //���ú���	
	CREATE_FUNC(littleHero);

	/*------------------------����ССӢ���ƶ�----------------------*/
	inline void updatePos(const Vec2& pos) { this->m_pos = pos; } //���µ�ǰλ��

	friend class LittleHeroLayer;
	friend class HeroLayer;
	friend class PC_Player;
	friend class helpAndSetLayer;
	friend class ShopLayer;
	friend class HeroPile;
	friend class BattleScene;
	friend class EquipmentScene;

protected:

	Vec2 m_SrcPos = Vec2(505, 305); //��ʼλ��
	Vec2 m_pos = this->m_SrcPos; //��ǰλ��
	int m_maxBlood = 100; //���Ѫ��
	int m_blood = this->m_maxBlood; //��ǰѪ������ʼΪ100,
	const int m_moveSpeed = 500; //�ƶ��ٶ�
	int m_upExp = 10; //������Ҫ�ľ���ֵ
	int m_coins = 100; //���
	int m_exp = 0; //����ֵ
	int m_level = 1; //�ȼ�
	//std::string m_picName = NULL; //ͼƬ����
	int m_round = 0; //��¼��Ϸ�غ���
	int m_continueWin = 0; //��¼��ʤ����
	int m_continueLose = 0; //��¼���ܳ���
	const int m_maxContinueWin = 7; //�����ʤ7�Σ��㲻�ټ���
	const int m_maxContinueLose = 7; //�������7�Σ��㲻�ټ���
	void countNextUPExp(); //������һ���������辭��
};
extern littleHero MyLittleHero;
extern littleHero player2data;

