#include<cocos2d.h>
#include"const.h"
#include"database.h"
using namespace cocos2d;
using namespace heroConsts;

class hero:public cocos2d::Node
{
private:

public:
	Sprite* delegateSprite;
	hero();
	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	float calculate_distance(Sprite* d_sprite);//���㱾��������˾��뺯��
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	static int get_HealthPoint();//����Ӣ�����ڵ�Ѫ��
	static int get_BluePoint();//����Ӣ�����ڵ�����
	static int get_DefencePoint();//����Ӣ�����ڵĻ���
	bool dodamage(int attackpoint);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool skill_release();//�ͷż���Ҫ�����������ͷż���֮���������
	void health_recover(int health_once,int lasting);//��Ѫ����
	void blue_rocover();//��������
	void health_recover_once(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blue_recover_once();//��һ����
	void equipment_put_on(Sprite* item);//���װ������,װ���ӳ�
	void equipment_take_off(Sprite* item);//����װ��������ȡ��װ���ӳ�
	//��ʥ�������ݿ��ȡ�Է�����
	//��ÿ���˵ľ�����д洢���ڽ��й���ʱ���ҷ�����ͨ�������Է��ľ����Ӧ�����꣬�����ҷ����鵽�Է�����ľ��룬�ҵ���̾���ľ��飬���ظþ�������꣬���ҵ��������Ӧ�ĸ��ӣ�Ѱ�����·�������������ߵ�

protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldtime;//����schedule��ʱ��ǰ��ʱ��
	
	static const int max_healthpoint;//Ѫ�����ֵ
	static const int max_bluepoint;//����ֵ���ֵ
	static const int max_shieldpoint;//�������ֵ

	/*Ӣ�ۻ�������*/
	static int fee;//Ӣ���������
	int ActorType;//Ӣ������
	std::string name;
	static int HealthPoint;//Ѫ��
	static int BluePoint;//��ǰ����ֵ
	static int shieldPoint;//����
	static int physics_attack_point;//�﹥ֵ
	static int magic_point;//��ǿ
	static int speed_attack;//����
	static int distance_attack;//��������
	static int blue_attack;//�ͷż������跨��ֵ
	static int critical_chance;//������
	static int defence_physics;//�￹
	static int defence_magic;//ħ��

	/*װ���ӳ�����*//*��������Ŀ������Ϊװ���ӳ����ڻ�������֮�Ͻ��еģ���֮����Ҫ���ʻ�������*/
	static int add_HealthPoint;//���ӵ�Ѫ��
	static int add_physics_attack_point;//���ӵ��﹥ֵ
	static int add_magic_point;//���ӵķ�ǿ
	static int add_speed_attack;//���ӵĹ���
	static int add_blue_attack;//���ӵ��ͷż������跨��ֵ���������Ǹ�����
	static int add_critical_chance;//���ӵı�����
	static int add_defence_physics;//���ӵ��￹
	static int add_defence_magic;//���ӵ�ħ��

	std::vector<int>equipment;//��������װ��
};