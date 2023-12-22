#include "cocos2d.h"
#include <math.h>
#include <string>
using namespace cocos2d;
using namespace std;

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
	littleHero* m_attackTarget = nullptr; //攻击对象指针
	ccArray* m_playerArray = ccArrayNew(9); //玩家备战区的棋子数组
	ccArray* m_fightArray = ccArrayNew(15); //玩家战斗区的棋子数组
	//chessInfo Used[5];

	/*----------------------装备信息---------------------*/
	ccArray* m_equipment = ccArrayNew(10); //装备数组
	ccArray* m_unEquipedEpt = ccArrayNew(10); //未穿的装备
	int m_occupiedSlot = 0;
	bool m_isPackageOpened = false;
	packageSlot m_packageSlot[3][4] = {};
	Point slotPoint[12] = {};


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
	inline void setPicture(const std::string picName) { this->m_picName = picName; } //设置图片文件，换皮肤
	inline void hurt(const int delBlood) { this->m_blood -= delBlood; } //受到伤害，减少血量
	inline void addCoins(const int num) { this->m_coins += num; } //增加金币
	inline void delCoins(const int num) { this->m_coins -= num; } //减少金币
	inline void addExp(const int exp) {
		this->m_exp += exp;
		if (this->m_exp > this->m_upExp) {
			this->m_exp -= this->m_upExp;
			this->m_level++;
		} //升级
	} //增加经验
	inline bool isDead() { return this->m_blood <= 0; }
	void win(); //战斗获胜函数
	void lose(int hurt); //战斗失败函数
	CREATE_FUNC(littleHero);

	/*------------------------控制小小英雄移动----------------------*/
	inline MoveTo* move(const Vec2 curPos); //移动小小英雄状态
	inline Vec2 updatePos(const Vec2& pos) { this->m_pos = pos; } //更新当前位置

protected:
	bool haveNewHero = false; //判断是否有新棋子
	Vec2 m_SrcPos = Vec2(505, 305); //初始位置
	Vec2 m_pos = this->m_SrcPos; //当前位置
	int m_maxBlood = 100; //最大血量
	int m_blood = this->m_maxBlood; //当前血量，初始为100,
	const int m_moveSpeed = 300; //移动速度
	int m_upExp = 10; //升级需要的经验值
	int m_coins = 10; //金币
	int m_exp = 0; //经验值
	int m_level = 1; //等级
	std::string m_picName = NULL; //图片名称
	int m_round = 0; //记录游戏回合数
	int m_continueWin = 0; //记录连胜场次
	int m_continueLose = 0; //记录连败场次
	const int m_maxContinueWin = 7; //最多连胜7次，便不再计算
	const int m_maxContinueLose = 7; //最多连败7次，便不再计算
	void countNextUPExp();
};
extern littleHero MyLittleHero;


extern littleHero h1, h2, h3, h4, h5, h6, h7, h8;
