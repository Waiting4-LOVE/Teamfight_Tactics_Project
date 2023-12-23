#include<cocos2d.h>
#include"const.h"
#include <string>
#include"database.h"
#include"Equipment.h"
using namespace cocos2d;
using namespace heroConsts;
using namespace std;

class hero :public Sprite
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
	void healthRecover(int health_once, int lasting);//��Ѫ����
	void blueRocover();//��������
	void healthRecoverOnce(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blueRecoverOnce();//��һ����
	void equipmentPutOn(Sprite* item);//���װ������,װ���ӳ�
	void equipmentTakeOff(Sprite* item);//����װ��������ȡ��װ���ӳ�
	//��ʥ�������ݿ��ȡ�Է�����
	//��ÿ���˵ľ�����д洢���ڽ��й���ʱ���ҷ�����ͨ�������Է��ľ����Ӧ�����꣬�����ҷ����鵽�Է�����ľ��룬�ҵ���̾���ľ��飬���ظþ�������꣬���ҵ��������Ӧ�ĸ��ӣ�Ѱ�����·�������������ߵ�
	void move(float dt);//Ѱ·
	void attack(float dt);//����
	void bloodUpdate(float dt);//����Ӣ��ͷ��Ѫ����������Ϣ
	void skill();//�ż���
	bool die();
	virtual void releaseSkill();
	void reset();
	//void beMoved();
	pair<int, int> getLatPos()const { return latPos; }
	CREATE_FUNC(hero);


protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldTime;//����schedule��ʱ��ǰ��ʱ��

	int maxHealthPoint;//Ѫ�����ֵ
	int maxBluePoint;//����ֵ���ֵ
	int maxShieldPoint;//�������ֵ

	/*Ӣ�ۻ�������*/
	hero* attackTarget;//����Ŀ��
	int fee;//Ӣ���������
	int ActorType;//Ӣ������
	std::string name;
	int HealthPoint;//Ѫ��
	int BluePoint;//��ǰ����ֵ
	int originBluePoint;//��ʼ����ֵ
	int shieldPoint;//����
	int physicsAttackPoint;//�﹥ֵ
	int magicPoint;//��ǿ
	int speedAttack;//���٣�ÿ����ٴ�
	int distanceAttack;//��������
	int blueAttack;//�ͷż������跨��ֵ
	int criticalChance;//������
	int defencePhysics;//�￹
	int defenceMagic;//ħ��
	pair<int, int>latPos;//�����ĸ�������
	//����Ѫ������
	Sprite* bloodFrame = Sprite::create("BloodFrame.jpg");
	Sprite* blueFrame = Sprite::create("BloodFrame.jpg");
	ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.jpg"));
	ProgressTimer* blueBar = ProgressTimer::create(Sprite::create("Mana.png"));

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