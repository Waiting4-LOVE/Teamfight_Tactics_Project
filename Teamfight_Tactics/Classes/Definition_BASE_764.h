#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#define DISPLAY_TIME_INIT_SCENE 2
#define TRANSITION_TIME 2

//װ�����ԣ���ӦֵΪ�������е�λ��
const int eptNum = 2; //װ������
const int eptTypeNum = 2; //������Ը���
const int physical_attack = 0; //������
const int spell_attack = 1; //��������
const int physical_defence = 2; //�￹
const int spell_defence = 3; //ħ��
const int attack_speed = 4; //����
const int blue_heal = 5; //����
const int blood_heal = 6; //��Ѫ
const int critical_hit = 7; //����
const int max_blood = 8; //����Ѫ������
const int shovel = 9; //�����
const int add_hero = 10; //������һ��Ӣ��

//����װ������
//��0�д���װ�����
int eptArr[eptNum][eptTypeNum + 1] = { {0,1,0},{1,0,1} };
std::string eptName[eptNum] = { "10","20" };

#endif // __DEFINITION_H__
