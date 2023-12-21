#include "cocos2d.h"
#include <math.h>
#include <string>
using namespace cocos2d;
using namespace std;

class littleHero {
public:
	//inline littleHero();
	//inline littleHero(std::string picName);
	littleHero* attackTarget = nullptr;

	/*------------------------get类----------------------*/
	inline int getCurBlood() { return this->m_blood; }
	inline int getCoins() { return this->m_coins; }
	inline int getExp() { return this->m_exp; }
	inline int getLevel() { return this->m_level; }	
	inline Vec2 getCurPos() { return this->m_pos; }

	/*------------------------set类----------------------*/
	inline void setPos(Vec2& pos) { this->m_pos = pos; } //设置位置，参数为Vec2
	inline void setPos(const int x, const int y) { this->m_pos.x = x, this->m_pos.y = y; } //设置位置，参数为两个坐标数值
	inline void setSrcPos() { this->m_pos = this->m_SrcPos; } //返回初始位置
	
	//inline void setPicture(const std::string picName) { this->m_picName = picName; } //设置图片文件，换皮肤
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
	//CREATE_FUNC(littleHero);

	/*------------------------控制小小英雄移动----------------------*/
	inline MoveTo* move(const Vec2 curPos); //移动小小英雄状态
	inline void updatePos(const Vec2& pos) { this->m_pos = pos; } //更新当前位置
	
	friend class LittleHeroLayer;

protected:
	Vec2 m_SrcPos= Vec2(505, 305); //初始位置
	Vec2 m_pos= m_SrcPos; //当前位置
	int m_maxBlood=100; //最大血量
	int m_blood= m_maxBlood; //当前血量，初始为100,
	const int m_moveSpeed=300; //移动速度
	const int m_upExp=10; //升级需要的经验值
	int m_coins=10; //金币
	int m_exp=0; //经验值
	int m_level=1; //等级
	//std::string m_picName; //图片名称
};
extern littleHero MyLittleHero;


