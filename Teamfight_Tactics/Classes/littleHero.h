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
	bool haveNewHero = false; //判断是否有新棋子
	littleHero* m_attackTarget = nullptr; //攻击对象指针
	ccArray* m_playerArray = ccArrayNew(9); //玩家备战区的棋子数组
	ccArray* m_fightArray = ccArrayNew(15); //玩家战斗区的棋子数组
	int chessnumber[ChessNumber] = {};
	int EXP_FOR_LEVEL[10] = { 2,2,6,10,20,36,48,64,76,80 };//每级升级所需经验值
	chessInfo Used[5];




	/*----------------------显示---------------------*/
	std::string picturename;   //图片名字
	int picturenum;       //图片张数
	void LHAnimation(std::string picturename, const int picturenum, Sprite* sprite, const float speed, const int loop);

	//Sprite* bloodFrame = Sprite::create("BloodFrame.png");
	//ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.png"));
	//void bloodUpdate(float dt);

	/*----------------------装备信息---------------------*/
	bool haveNewEpt = false;
	ccArray* m_equipment = ccArrayNew(10); //装备数组
	ccArray* m_unEquipedEpt = ccArrayNew(10); //未穿的装备
	int m_occupiedSlot = 0;
	bool m_isPackageOpened = false;
	packageSlot m_packageSlot[2][2] = {};
	Point slotPoint[4] = {};
	eptInfo randEpt[4]; //随机选4件装备

	/*------------------------get类----------------------*/
	inline int getCurBlood() { return this->m_blood; }
	inline int getCoins() { return this->m_coins; }
	inline int getExp() { return this->m_exp; }
	inline int getLevel() { return this->m_level; }
	inline Vec2 getCurPos() { return this->m_pos; }
	inline int getContinueWin() { return this->m_continueWin; }
	inline int getContinueWiLose() { return this->m_continueLose; }
	inline int getRound() { return this->m_round; }
	inline int getBonus(int sort); //返回奖励金币

	/*------------------------set类----------------------*/
	inline void setAttackTarger(littleHero* target) { this->m_attackTarget = target; } //设置攻击对象
	inline void setPos(Vec2& pos) { this->m_pos = pos; } //设置位置，参数为Vec2
	inline void setPos(const int x, const int y) { this->m_pos.x = x, this->m_pos.y = y; } //设置位置，参数为两个坐标数值
	inline void setSrcPos() { this->m_pos = this->m_SrcPos; } //返回初始位置
	inline void setCurBlood(const int blood) { this->m_blood = blood; } //设置当前血量
	//inline void setPicture(const std::string picName) { this->m_picName = picName; } //设置图片文件，换皮肤
	inline void hurt(const int delBlood) { this->m_blood -= delBlood; } //受到伤害，减少血量
	bool CoinsIsChange = false;
	inline void addCoins(const int num) { this->m_coins += num; CoinsIsChange = true; } //增加金币
	inline void delCoins(const int num) { this->m_coins -= num; CoinsIsChange = true; } //减少金币
	inline void addExp(const int exp); //增加经验
	inline bool isDead() { return this->m_blood <= 0; }
	void win();
	void lose(int hurt); //战斗失败函数
	void reset(); //重置函数	
	CREATE_FUNC(littleHero);

	/*------------------------控制小小英雄移动----------------------*/
	inline void updatePos(const Vec2& pos) { this->m_pos = pos; } //更新当前位置

	friend class LittleHeroLayer;
	friend class HeroLayer;
	friend class PC_Player;
	friend class helpAndSetLayer;
	friend class ShopLayer;
	friend class HeroPile;
	friend class BattleScene;
	friend class EquipmentScene;

protected:

	Vec2 m_SrcPos = Vec2(505, 305); //初始位置
	Vec2 m_pos = this->m_SrcPos; //当前位置
	int m_maxBlood = 100; //最大血量
	int m_blood = this->m_maxBlood; //当前血量，初始为100,
	const int m_moveSpeed = 500; //移动速度
	int m_upExp = 10; //升级需要的经验值
	int m_coins = 100; //金币
	int m_exp = 0; //经验值
	int m_level = 1; //等级
	//std::string m_picName = NULL; //图片名称
	int m_round = 0; //记录游戏回合数
	int m_continueWin = 0; //记录连胜场次
	int m_continueLose = 0; //记录连败场次
	const int m_maxContinueWin = 7; //最多连胜7次，便不再计算
	const int m_maxContinueLose = 7; //最多连败7次，便不再计算
	void countNextUPExp(); //计算下一级升级所需经验
};
extern littleHero MyLittleHero;
extern littleHero player2data;

