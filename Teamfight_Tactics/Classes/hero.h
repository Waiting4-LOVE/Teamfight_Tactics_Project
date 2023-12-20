#include<cocos2d.h>
#include"const.h"
#include <string>
#include"database.h"
#include"Equipment.h"
using namespace cocos2d;
using namespace heroConsts;
using namespace std;

class hero:public Sprite
{
private: 

public:

	string picturename;//ͼƬ����
	int picturenum;//ͼƬ����
	static hero* createhero(string picture_name);
	hero();
	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	float calculateDistance(Sprite* d_sprite);//���㱾��������˾��뺯��
	Sprite* getEnemy();
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	int getHealthPoint();//����Ӣ�����ڵ�Ѫ��
	int getBluePoint();//����Ӣ�����ڵ�����
	int getDefencePoint();//����Ӣ�����ڵĻ���
	bool doDamage(int attackpoint);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool blueClear();//�ͷż���Ҫ�����������ͷż���֮���������
	void healthRecover(int health_once,int lasting);//��Ѫ����
	void blueRocover();//��������
	void healthRecoverOnce(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blueRecoverOnce();//��һ����
	void equipmentPutOn(Sprite* item);//���װ������,װ���ӳ�
	void equipmentTakeOff(Sprite* item);//����װ��������ȡ��װ���ӳ�
	//��ʥ�������ݿ��ȡ�Է�����
	//��ÿ���˵ľ�����д洢���ڽ��й���ʱ���ҷ�����ͨ�������Է��ľ����Ӧ�����꣬�����ҷ����鵽�Է�����ľ��룬�ҵ���̾���ľ��飬���ظþ�������꣬���ҵ��������Ӧ�ĸ��ӣ�Ѱ�����·�������������ߵ�
	virtual void releaseSkill();
	CREATE_FUNC(hero);


protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldTime;//����schedule��ʱ��ǰ��ʱ��
	
	int maxHealthPoint;//Ѫ�����ֵ
	int maxBluePoint;//����ֵ���ֵ
	int maxShieldPoint;//�������ֵ

	static std::pair<int, int> staticLatticeId;//׼��ʱ��λ��
	static std::pair<int, int> dynamicLatticeId;//ս��ʱλ��
	/*Ӣ�ۻ�������*/
	int fee;//Ӣ���������
	int ActorType;//Ӣ��������ң�1��2��3��4��5��6��7��8��
	std::string name;
	int HealthPoint;//Ѫ��
	int BluePoint;//��ǰ����ֵ
    int shieldPoint;//����
	int physicsAttackPoint;//�﹥ֵ
	int magicPoint;//��ǿ
	int speedAttack;//����
	int distanceAttack;//��������
	int blueAttack;//�ͷż������跨��ֵ
	int criticalChance;//������
	int defencePhysics;//�￹
	int defenceMagic;//ħ��

	/*װ���ӳ�����*//*��������Ŀ������Ϊװ���ӳ����ڻ�������֮�Ͻ��еģ���֮����Ҫ���ʻ�������*/
	int addHealthPoint;//���ӵ�Ѫ��
	int addPhysicsAttackPoint;//���ӵ��﹥ֵ
	int addMagicPoint;//���ӵķ�ǿ
	int addSpeedAttack;//���ӵĹ���
	int addBlueAttack;//���ӵ��ͷż������跨��ֵ���������Ǹ�����
	int addCriticalChance;//���ӵı�����
	int addDefencePhysics;//���ӵ��￹
	int addDefenceMagic;//���ӵ�ħ��

	std::vector<int>equipment;//��������װ��
};