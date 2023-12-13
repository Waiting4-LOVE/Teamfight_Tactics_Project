#include<cocos2d.h>
#include"const.h"
using namespace cocos2d;
using namespace heroConsts;

class hero:public cocos2d::Node
{
private:

public:
	Sprite* delegateSprite;
	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	float calculate_distance();//���㱾��������˾��뺯��
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	hero();
	bool in_attack_range();//�ж��Ƿ���빥����Χ�ں���
	static int get_HealthPoint();//����Ӣ�����ڵ�Ѫ��
	static int get_BluePoint();//����Ӣ�����ڵ�����
	static int get_DefencePoint();//����Ӣ�����ڵĻ���
	bool dodamage(int attackpoint);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool skill_release();//�ͷż���Ҫ�����������ͷż���֮���������
	void health_recover(int health_once,int lasting);//��Ѫ����
	void blue_rocover();//��������
	void health_recover_once(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blue_recover_once();//��һ����
	void eguipment_bonus();//װ���ӳɺ���
	void equipment_put_on();//���װ������
	void equipment_take_off();//����װ������

	//��ÿ���˵ľ�����д洢���ڽ��й���ʱ���ҷ�����ͨ�������Է��ľ����Ӧ�����꣬�����ҷ����鵽�Է�����ľ��룬�ҵ���̾���ľ��飬���ظþ�������꣬���ҵ��������Ӧ�ĸ��ӣ�Ѱ�����·�������������ߵ�

protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldtime;//����schedule��ʱ��ǰ��ʱ��
	int ActorType;//Ӣ������
	static const int max_healthpoint;//Ѫ�����ֵ
	static const int max_bluepoint;//����ֵ���ֵ
	static const int max_shieldpoint;//�������ֵ
	static int HealthPoint;//Ѫ��
	static int BluePoint;//����ֵ
	static int shieldPoint;//����
	static int physics_attack_point;//�﹥ֵ
	static int magic_point;//��ǿ
	static int fee;//Ӣ���������
	static int speed_attack;//����
	static int distance_attack;//��������
	static int blue_attack;//�ͷż������跨��ֵ
	static int critical_chance;//������
	static int defence_physics;//�￹
	static int defence_magic;//ħ��
	Vector<int>equipment;//��������װ��
};