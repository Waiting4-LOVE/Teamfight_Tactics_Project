#include<cocos2d.h>
#include"const.h"
#include"database.h"
using namespace cocos2d;
using namespace heroConsts;

class hero :public cocos2d::Node
{
private:

public:
	Sprite* delegateSprite;
	hero();
	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	float calculate_distance(Sprite* d_sprite);//���㱾��������˾��뺯��
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	int get_HealthPoint();//����Ӣ�����ڵ�Ѫ��
	int get_BluePoint();//����Ӣ�����ڵ�����
	int get_DefencePoint();//����Ӣ�����ڵĻ���
	bool dodamage(int attackpoint);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool skill_release();//�ͷż���Ҫ�����������ͷż���֮���������
	void health_recover(int health_once, int lasting);//��Ѫ����
	void blue_rocover();//��������
	void health_recover_once(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blue_recover_once();//��һ����
	void equipment_put_on(Sprite* item);//���װ������,װ���ӳ�
	void equipment_take_off(Sprite* item);//����װ��������ȡ��װ���ӳ�
	//��ʥ�������ݿ��ȡ�Է�����
	//��ÿ���˵ľ�����д洢���ڽ��й���ʱ���ҷ�����ͨ�������Է��ľ����Ӧ�����꣬�����ҷ����鵽�Է�����ľ��룬�ҵ���̾���ľ��飬���ظþ�������꣬���ҵ��������Ӧ�ĸ��ӣ�Ѱ�����·�������������ߵ�
	void move(float dt);//Ѱ·
	void attack(float dt);//����
	bool die();
protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldtime;//����schedule��ʱ��ǰ��ʱ��

	const int max_healthpoint;//Ѫ�����ֵ
	const int max_bluepoint;//����ֵ���ֵ
	const int max_shieldpoint;//�������ֵ

	std::pair<int, int> staticLatticeId;//׼��ʱ��λ��
	std::pair<int, int> dynamicLatticeId;//ս��ʱλ��
	/*Ӣ�ۻ�������*/
	hero* attackTarget;//����Ŀ��
	int fee;//Ӣ���������
	int ActorType;//Ӣ������
	std::string name;
	int HealthPoint;//Ѫ��
	int BluePoint;//��ǰ����ֵ
	int shieldPoint;//����
	int physics_attack_point;//�﹥ֵ
	int magic_point;//��ǿ
	int speed_attack;//����
	int distance_attack;//��������
	int blue_attack;//�ͷż������跨��ֵ
	int critical_chance;//������
	int defence_physics;//�￹
	int defence_magic;//ħ��

	/*װ���ӳ�����*//*��������Ŀ������Ϊװ���ӳ����ڻ�������֮�Ͻ��еģ���֮����Ҫ���ʻ�������*/
	int add_HealthPoint;//���ӵ�Ѫ��
	int add_physics_attack_point;//���ӵ��﹥ֵ
	int add_magic_point;//���ӵķ�ǿ
	int add_speed_attack;//���ӵĹ���
	int add_blue_attack;//���ӵ��ͷż������跨��ֵ���������Ǹ�����
	int add_critical_chance;//���ӵı�����
	int add_defence_physics;//���ӵ��￹
	int add_defence_magic;//���ӵ�ħ��

	std::vector<int>equipment;//��������װ��
};