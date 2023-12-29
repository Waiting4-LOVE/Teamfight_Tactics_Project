#pragma once
#include<cocos2d.h>
#include"const.h"
#include <string>
#include "RoundTimer.h"
#include"database.h"
#include "littleHero.h"
//#include"Equipment.h"
using namespace cocos2d;
using namespace heroConsts;
using namespace std;

class hero :public Sprite
{
private:
	RoundTimer* test_timer = RoundTimer::create(5);
public:

	ccArray* equipment = ccArrayNew(5);
	string picturename;//图片名字
	int picturenum;//图片数量
	static hero* createhero(string picture_name);
	hero();

	/*get类函数*/

	Vec2 getSpritePosition();//Vec2为2维向量，反映的是精灵坐标位置x,y
	Sprite* getEnemy();
	Vec2 getEnemyPosition();//返回的是离本精灵最近的敌人的坐标
	int getHealthPoint();//返回英雄现在的血条
	int getBluePoint();//返回英雄现在的蓝条
	int getDefencePoint();//返回英雄现在的护盾
	Point getTempPosition() { return Point(xtemp, ytemp); }
	int getType() { return type; }
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //返回所属玩家
	int getStar() { return star; }
	Point getPosition() { return Point(x, y); }
	float getAttackSpeed() { return speedAttack; }
	int getAttackDistance() { return distanceAttack; }
	int getPhysicalAttack() { return physicsAttackPoint; }
	int getMagicalPoint() { return magicPoint; }
	int getCriticalChance() {return criticalChance;}//暴击率
	int getDefencePhysics() { return defencePhysics; }//物抗
	int getDefenceMagic() { return defenceMagic; }//魔抗//魔抗
	string getname() { return name; }
	const cocos2d::Size getContentSize() { return Size(width, height); }   //获得图片长宽

	/*set类型函数*/
	void setPlayer(int player);
	void setAttackSpeed(float a) { speedAttack = a; }
	void setHealth(float a) { HealthPoint = a; }
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }


	//创建血条蓝条
	Sprite* bloodFrame = Sprite::create("BloodFrame.png");
	Sprite* blueFrame = Sprite::create("BloodFrame.png");
	ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.png"));
	ProgressTimer* blueBar = ProgressTimer::create(Sprite::create("Mana.png"));


	float calculateDistance(Sprite* d_sprite);//计算本精灵与敌人距离函数
	void onDamageReceived(int damage, int type);
	bool doDamage(int damage, int type = 0, bool damageVisible = 0);//我方收到伤害函数，这包括了我方护盾与血量的减少
	bool blueClear();//释放技能要求蓝条满，释放技能之后蓝条清空
	void healthRecover(int health_once, int lasting);//回血函数
	void blueRocover();//回蓝函数
	void healthRecoverOnce(int health_once);//回一次血//参数指的是一次回血量
	void blueRecoverOnce();//回一次蓝
	//void EquipmentChange();
	void equipmentPutOn(Sprite* item);//佩戴装备函数,装备加成
	void equipmentTakeOff(Sprite* item);//脱下装备函数，取消装备加成
	//张圣坤的数据库调取对方精灵
	//将每个人的精灵进行存储，在进行攻击时，我方精灵通过遍历对方的精灵对应的坐标，计算我方精灵到对方精灵的距离，找到最短距离的精灵，返回该精灵的坐标，再找到该坐标对应的格子，寻找最短路径，待所有人走到
	void attack(float dt);//攻击
	void bloodUpdate(float dt);//更新英雄头上血条蓝条等信息
	void skill();//放技能
	bool die();
	virtual void releaseSkill();
	void hero::shootbullet(string picturename, Point deltaPos, hero* mychess);
	void reset();
	bool isMove = 0;
	hero* attackTarget = nullptr;//攻击目标

	CREATE_FUNC(hero);


protected:
	int nowTime;//调用schedule定时器后的时间
	int oldTime;//调用schedule定时器前的时间
	float height = 0;//所带图片的长度和宽度
	float width = 0;

	int maxHealthPoint;//血条最大值
	int maxBluePoint;//法力值最大值
	int maxShieldPoint;//护盾最大值

	float xtemp = x;
	float ytemp = y;

	float x = 0.f;//真实位置
	float y = 0.f;

	int type = None;//种类
	int OfPlayer = 0;//所属玩家
	int CoinsNeeded = 0;//所需金币
	int SoldCoins = CoinsNeeded;//卖掉所获金币
	int star = 1;//星级

	/*英雄基本属性*/

	int fee;//英雄所需费用
	std::string name;
	int HealthPoint;//血条
	int BluePoint;//当前法力值
	int originBluePoint;//初始法力值
	int shieldPoint;//护盾
	int physicsAttackPoint;//物攻值
	int magicPoint;//法强
	float speedAttack;//攻速，每秒多少次
	int distanceAttack;//攻击距离
	int blueAttack;//释放技能所需法力值
	int criticalChance;//暴击率
	int defencePhysics;//物抗
	int defenceMagic;//魔抗


	/*装备加成属性*//*这样做的目的是因为装备加成是在基础属性之上进行的，而之后仍要访问基础属性*/
	int addHealthPoint;//增加的血量
	int addPhysicsAttackPoint;//增加的物攻值
	int addMagicPoint;//增加的法强
	int addSpeedAttack;//增加的攻速
	int addBlueAttack;//增加的释放技能所需法力值（理论上是负数）
	int addCriticalChance;//增加的暴击率
	int addDefencePhysics;//增加的物抗
	int addDefenceMagic;//增加的魔抗


};