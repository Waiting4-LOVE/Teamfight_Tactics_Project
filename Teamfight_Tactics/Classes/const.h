//本头文件存储的为所有人物参数
#pragma once
#include <cocos2d.h>
using namespace cocos2d;


namespace heroConsts {

enum heroType
{
	at_null=1, at_player, at_ai
};//英雄类型分为玩家与电脑玩家

const int blue_once = 5;
const int max_health_point = 100;//设置英雄血量为100
const int max_blue_point = 100;//设置英雄蓝条为100
const int max_defence_point = 100;//设置英雄护盾值为100
const int move_speed = 1;//棋盘上所有英雄的移动速度




}