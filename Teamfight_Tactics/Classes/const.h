 //��ͷ�ļ��洢��Ϊ�����������
#pragma once
#include <cocos2d.h>
#include<string>
using namespace cocos2d;


namespace heroConsts {

enum heroType
{
	player_1=1, player_2, player_3,player_4,player_5,player_6,player_7,player_8
};//Ӣ������

const int blue_once = 10;
const int max_health_point = 100;//����Ӣ��Ѫ��Ϊ100
const int max_blue_point = 100;//����Ӣ������Ϊ100
const int max_defence_point = 100;//����Ӣ�ۻ���ֵΪ100
const float move_speed = 1.5;//����������Ӣ�۵��ƶ��ٶȣ�1/60s�ߵ�·��




}