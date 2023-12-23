 //本头文件存储的为所有人物参数
#pragma once
#include <cocos2d.h>
#include<string>
using namespace cocos2d;


namespace heroConsts {

enum heroType
{
	player_1=1, player_2, player_3,player_4,player_5,player_6,player_7,player_8
};//英雄所属

const int blue_once = 5;
const int max_health_point = 100;//设置英雄血量为100
const int max_blue_point = 100;//设置英雄蓝条为100
const int max_defence_point = 100;//设置英雄护盾值为100
const int move_speed = 10;//棋盘上所有英雄的移动速度，1/60s走的路程




}