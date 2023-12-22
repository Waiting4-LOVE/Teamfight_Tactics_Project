#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#define DISPLAY_TIME_INIT_SCENE 2
<<<<<<< HEAD
#define TRANSITION_TIME 2
//装备属性，对应值为在数组中的位置
#define eptNum 46 //装备总数
#define basicEptNum 9 //基础装备
#define synEptNum 37 //合成装备
#define eptTypeNum 14 //最大属性个数
#define physical_attack 0 //物理攻击
#define spell_attack 1 //法术攻击
#define physical_defence 2 //物抗
#define spell_defence 3 //魔抗
#define attack_speed 4 //攻速
#define blue_heal 5 //回蓝
#define blood_heal 6 //回血
#define critical_hit_ratio 7 //暴击率
#define max_blood 8 //增加血量上限
#define max_spell 9 //增加法力上限
#define shovel 10 //金铲铲
#define critical_hit_value 11 //暴击伤害
#define suck_blood 12 //吸血
#define add_hero 13 //额外上一个英雄

//具体装备属性
//第0列代表装备编号，id号即为装备在数组中的位置
static int basicEptArr[basicEptNum][eptTypeNum + 1] = { {0,10},{1,0,0,0,0,10},{2,0,10},
	{3,0,0,0,0,0,0,0,0,0,15},{4,0,0,20},{5,0,0,0,20},{6,0,0,0,0,0,0,0,0,150},{7,0,0,0,0,0,0,0,0,0,0,1},{8,0,0,0,0,0,0,0,0.2} };
static std::string basicEptName[basicEptNum] = { "暴风大剑","反曲之弓" ,"无用大棒","女神之泪",
"锁子甲","负极斗篷", "巨人腰带","金铲铲","拳套" };

static int synEptArr[synEptNum][eptTypeNum + 1] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0.1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0.22}, };
static std::string synEptName[synEptNum] = { "无尽之刃","海克斯科技枪刃","朔极之矛","","" ,"" ,"" ,"" ,""
,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" };

#endif // __DEFINITION_H__
=======
#define TRANSITION_TIME 0.5

#endif // __DEFINITION_H__
>>>>>>> af6351573f01bec9f59a01fb54c34bb35deaac86
