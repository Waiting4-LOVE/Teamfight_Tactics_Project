#include<cocos2d.h>
#include"const.h"
using namespace cocos2d;
using namespace heroConsts;

class hero:public cocos2d::Node
{
private:

public:
	Sprite* delegateSprite;
	Vec2 getSpritePosition();//Vec2为2维向量，反映的是精灵坐标位置x,y
	float calculate_distance();//计算本精灵与敌人距离函数
	Vec2 getEnemyPosition();//返回的是离本精灵最近的敌人的坐标
	hero();
	bool in_attack_range();//判断是否进入攻击范围内函数
	static int get_HealthPoint();//返回英雄现在的血条
	static int get_BluePoint();//返回英雄现在的蓝条
	static int get_DefencePoint();//返回英雄现在的护盾
	bool dodamage(int attackpoint);//我方收到伤害函数，这包括了我方护盾与血量的减少
	bool skill_release();//释放技能要求蓝条满，释放技能之后蓝条清空
	void health_recover(int health_once,int lasting);//回血函数
	void blue_rocover();//回蓝函数
	void health_recover_once(int health_once);//回一次血//参数指的是一次回血量
	void blue_recover_once();//回一次蓝
	void eguipment_bonus();//装备加成函数
	void equipment_put_on();//佩戴装备函数
	void equipment_take_off();//脱下装备函数

	//将每个人的精灵进行存储，在进行攻击时，我方精灵通过遍历对方的精灵对应的坐标，计算我方精灵到对方精灵的距离，找到最短距离的精灵，返回该精灵的坐标，再找到该坐标对应的格子，寻找最短路径，待所有人走到

protected:
	int nowTime;//调用schedule定时器后的时间
	int oldtime;//调用schedule定时器前的时间
	int ActorType;//英雄类型
	static const int max_healthpoint;//血条最大值
	static const int max_bluepoint;//法力值最大值
	static const int max_shieldpoint;//护盾最大值
	static int HealthPoint;//血条
	static int BluePoint;//法力值
	static int shieldPoint;//护盾
	static int physics_attack_point;//物攻值
	static int magic_point;//法强
	static int fee;//英雄所需费用
	static int speed_attack;//攻速
	static int distance_attack;//攻击距离
	static int blue_attack;//释放技能所需法力值
	static int critical_chance;//暴击率
	static int defence_physics;//物抗
	static int defence_magic;//魔抗
	Vector<int>equipment;//身上所戴装备
};