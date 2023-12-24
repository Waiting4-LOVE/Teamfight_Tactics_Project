#pragma once
#include<cocos2d.h>
#include"const.h"
#include <string>
#include"database.h"
#include "littleHero.h"
//#include"Equipment.h"
using namespace cocos2d;
using namespace heroConsts;
using namespace std;

class hero :public Sprite
{
private:

public:

	ccArray* equipment = ccArrayNew(5);
	string picturename;//ͼƬ����
	int picturenum;//ͼƬ����
	static hero* createhero(string picture_name);
	hero();

	/*get�ຯ��*/

	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	Sprite* getEnemy();
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	int getHealthPoint();//����Ӣ�����ڵ�Ѫ��
	int getBluePoint();//����Ӣ�����ڵ�����
	int getDefencePoint();//����Ӣ�����ڵĻ���
	Point getTempPosition() { return Point(xtemp, ytemp);}
	int getType() { return type; }
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //�����������
	int getStar() { return star; }
	Point getPosition() { return Point(x, y); }
	float getAttackSpeed() { return speedAttack; }
	int getAttackDistance() { return distanceAttack; }
	const cocos2d::Size getContentSize() { return Size(width, height); }   //���ͼƬ����

	/*set���ͺ���*/
	void setPlayer(int player);
	void setAttackSpeed(float a) { speedAttack = a; }
	void setHealth(float a) { HealthPoint = a; }
	void set(float x1, float y1);
	void set(Point point) {
		x = point.x;
		y = point.y;
	};
	void setTempPosition() { xtemp = x; ytemp = y; }


	//����Ѫ������
	Sprite* bloodFrame = Sprite::create("BloodFrame.png");
	Sprite* blueFrame = Sprite::create("BloodFrame.png");
	ProgressTimer* bloodBar = ProgressTimer::create(Sprite::create("Blood.png"));
	ProgressTimer* blueBar = ProgressTimer::create(Sprite::create("Mana.png"));


	float calculateDistance(Sprite* d_sprite);//���㱾��������˾��뺯��
	bool doDamage(int attackpoint);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool blueClear();//�ͷż���Ҫ�����������ͷż���֮���������
	void healthRecover(int health_once, int lasting);//��Ѫ����
	void blueRocover();//��������
	void healthRecoverOnce(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blueRecoverOnce();//��һ����
	//void EquipmentChange();
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
	hero* attackTarget;//����Ŀ��

	CREATE_FUNC(hero);


protected:
	int nowTime;//����schedule��ʱ�����ʱ��
	int oldTime;//����schedule��ʱ��ǰ��ʱ��
	float height = 0;//����ͼƬ�ĳ��ȺͿ��
	float width = 0;

	int maxHealthPoint;//Ѫ�����ֵ
	int maxBluePoint;//����ֵ���ֵ
	int maxShieldPoint;//�������ֵ

	float xtemp = x;
	float ytemp = y;

	float x = 0.f;//��ʵλ��
	float y = 0.f;

	int type = None;//����
	int OfPlayer = 0;//�������
	int CoinsNeeded = 0;//������
	int SoldCoins = CoinsNeeded;//����������
	int star = 1;//�Ǽ�

	/*Ӣ�ۻ�������*/
	
	int fee;//Ӣ���������
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


	/*װ���ӳ�����*//*��������Ŀ������Ϊװ���ӳ����ڻ�������֮�Ͻ��еģ���֮����Ҫ���ʻ�������*/
	int addHealthPoint;//���ӵ�Ѫ��
	int addPhysicsAttackPoint;//���ӵ��﹥ֵ
	int addMagicPoint;//���ӵķ�ǿ
	int addSpeedAttack;//���ӵĹ���
	int addBlueAttack;//���ӵ��ͷż������跨��ֵ���������Ǹ�����
	int addCriticalChance;//���ӵı�����
	int addDefencePhysics;//���ӵ��￹
	int addDefenceMagic;//���ӵ�ħ��
	
	
};