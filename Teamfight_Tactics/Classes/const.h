//��ͷ�ļ��洢��Ϊ�����������
#pragma once
#include <cocos2d.h>
#include<string>
using namespace cocos2d;


namespace heroConsts {

enum heroType
{
	at_null=1, at_player, at_ai
};//Ӣ�����ͷ�Ϊ�����������

const int blue_once = 5;
const int max_health_point = 100;//����Ӣ��Ѫ��Ϊ100
const int max_blue_point = 100;//����Ӣ������Ϊ100
const int max_defence_point = 100;//����Ӣ�ۻ���ֵΪ100
const int move_speed = 10;//����������Ӣ�۵��ƶ��ٶȣ�0.02s�ߵ�·��




}