#ifndef __DEFINITION_H__
#define __DEFINITION_H__

#define DISPLAY_TIME_INIT_SCENE 2
<<<<<<< HEAD
#define TRANSITION_TIME 2
=======
#define TRANSITION_TIME 0.5

>>>>>>> master
//װ�����ԣ���ӦֵΪ�������е�λ��
#define eptNum 46 //װ������
#define basicEptNum 9 //����װ��
#define synEptNum 37 //�ϳ�װ��
#define eptTypeNum 14 //������Ը���
#define physical_attack 0 //������
#define spell_attack 1 //��������
#define physical_defence 2 //�￹
#define spell_defence 3 //ħ��
#define attack_speed 4 //����
#define blue_heal 5 //����
#define blood_heal 6 //��Ѫ
#define critical_hit_ratio 7 //������
#define max_blood 8 //����Ѫ������
#define max_spell 9 //���ӷ�������
#define shovel 10 //�����
#define critical_hit_value 11 //�����˺�
#define suck_blood 12 //��Ѫ
#define add_hero 13 //������һ��Ӣ��

//����װ������
//��0�д���װ����ţ�id�ż�Ϊװ���������е�λ��
static int basicEptArr[basicEptNum][eptTypeNum + 1] = { {0,10},{1,0,0,0,0,10},{2,0,10},
	{3,0,0,0,0,0,0,0,0,0,15},{4,0,0,20},{5,0,0,0,20},{6,0,0,0,0,0,0,0,0,150},{7,0,0,0,0,0,0,0,0,0,0,1},{8,0,0,0,0,0,0,0,0.2} };
static std::string basicEptName[basicEptNum] = { "�����","����֮��" ,"���ô��","Ů��֮��",
"���Ӽ�","��������", "��������","�����","ȭ��" };

static int synEptArr[synEptNum][eptTypeNum + 1] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0.1},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0.22}, };
static std::string synEptName[synEptNum] = { "�޾�֮��","����˹�Ƽ�ǹ��","˷��֮ì","","" ,"" ,"" ,"" ,""
,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,
"" ,"" ,"" ,"" ,"" };

#endif // __DEFINITION_H__
