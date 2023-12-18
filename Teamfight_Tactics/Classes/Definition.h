#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#define DISPLAY_TIME_INIT_SCENE 2
#define TRANSITION_TIME 0.5

//装备属性，对应值为在数组中的位置
const int eptNum = 2; //装备总数
const int eptTypeNum = 2; //最大属性个数
const int physical_attack = 0; //物理攻击
const int spell_attack = 1; //法术攻击
const int physical_defence = 2; //物抗
const int spell_defence = 3; //魔抗
const int attack_speed = 4; //攻速
const int blue_heal = 5; //回蓝
const int blood_heal = 6; //回血
const int critical_hit = 7; //暴击
const int max_blood = 8; //增加血量上限
const int shovel = 9; //金铲铲
const int add_hero = 10; //额外上一个英雄

//具体装备属性
//第0列代表装备编号
int eptArr[eptNum][eptTypeNum + 1] = { {0,1,0},{1,0,1} };
std::string eptName[eptNum] = { "10","20" };

#endif // __DEFINITION_H__
