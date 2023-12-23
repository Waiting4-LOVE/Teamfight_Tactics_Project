#include<cocos2d.h>
#include"const.h"
#include <string>
#include"database.h"
#include"Equipment.h"
using namespace cocos2d;
using namespace heroConsts;
using namespace std;

class hero :public Sprite
{
private:

public:

	string picturename;//图片名字
	int picturenum;//图片数量
	static hero* createhero(string picture_name);
	hero();
	Vec2 getSpritePosition();//Vec2为2维向量，反映的是精灵坐标位置x,y
	float calculateDistance(Sprite* d_sprite);//计算本精灵与敌人距离函数
	Sprite* getEnemy();
	Vec2 getEnemyPosition();//返回的是离本精灵最近的敌人的坐标
	int getHealthPoint();//返回英雄现在的血条
	int getBluePoint();//返回英雄现在的蓝条
	int getDefencePoint();//返回英雄现在的护盾
	bool doDamage(int attackpoint);//我方收到伤害函数，这包括了我方护盾与血量的减少
	bool blueClear();//释放技能要求蓝条满，释放技能之后蓝条清空
	void healthRecover(int health_once, int lasting);//回血函数
	void blueRocover();//回蓝函数
	void healthRecoverOnce(int health_once);//回一次血//参数指的是一次回血量
	void blueRecoverOnce();//回一次蓝
	void equipmentPutOn(Sprite* item);//佩戴装备函数,装备加成
	void equipmentTakeOff(Sprite* item);//脱下装备函数，取消装备加成
	//张圣坤的数据库调取对方精灵
	//将每个人的精灵进行存储，在进行攻击时，我方精灵通过遍历对方的精灵对应的坐标，计算我方精灵到对方精灵的距离，找到最短距离的精灵，返回该精灵的坐标，再找到该坐标对应的格子，寻找最短路径，待所有人走到
	void move(float dt);//寻路
	void attack(float dt);//攻击
	void bloodUpdate(float dt);//更新英雄头上血条蓝条等信息
	void skill();//放技能
	bool die();
	virtual void releaseSkill();
	void reset();
	//void beMoved();
	pair<int, int> getLatPos()const { return latPos; }
	CREATE_FUNC(hero);


protected:
	int nowTime;//调用schedule定时器后的时间
	int oldTime;//调用schedule定时器前的时间

	int maxHealthPoint;//血条最大值
	int maxBluePoint;//法力值最大值
	int maxShieldPoint;//护盾最大值

	/*英雄基本属性*/
	hero* attackTarget;//攻击目标
	int fee;//英雄所需费用
	int ActorType;//英雄类型
	std::string name;
	int HealthPoint;//血条
	int BluePoint;//当前法力值
	int originBluePoint;//初始法力值
	int shieldPoint;//护盾
	int physicsAttackPoint;//物攻值
	int magicPoint;//法强
	int speedAttack;//攻速，每秒多少次
	int distanceAttack;//攻击距离
	int blueAttack;//释放技能所需法力值
	int criticalChance;//暴击率
	int defencePhysics;//物抗
	int defenceMagic;//魔抗
	pair<int, int>latPos;//处于哪个格子上
	//创建血条蓝条
	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	Sprite* blueFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.jpg"));
	ProgressTimer* blueBar = ProgressTimer::create(Sprite::create("Mana.png"));

	/*装备加成属性*//*这样做的目的是因为装备加成是在基础属性之上进行的，而之后仍要访问基础属性*/
	int addHealthPoint;//增加的血量
	int addPhysicsAttackPoint;//增加的物攻值
	int addMagicPoint;//增加的法强
	int addSpeedAttack;//增加的攻速
	int addBlueAttack;//增加的释放技能所需法力值（理论上是负数）
	int addCriticalChance;//增加的暴击率
	int addDefencePhysics;//增加的物抗
	int addDefenceMagic;//增加的魔抗

	std::vector<int>equipment;//身上所戴装备
};