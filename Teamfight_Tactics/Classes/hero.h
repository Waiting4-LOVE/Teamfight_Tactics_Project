#pragma once
#include<cocos2d.h>
#include"const.h"
#include <string>
#include "RoundTimer.h"
#include"database.h"
#include "littleHero.h"
#include"equipmentFile.h"
#include"battleMap.h"

using namespace cocos2d;
using namespace heroConsts;


class hero :public Sprite
{
private:

public:

	ccArray* equipment = ccArrayNew(5);
	std::string picturename;//ͼƬ����
	int picturenum;//ͼƬ����
	static hero* createhero(std::string picture_name);
	hero();

	/*get�ຯ��*/

	Vec2 getSpritePosition();//Vec2Ϊ2ά��������ӳ���Ǿ�������λ��x,y
	Sprite* getEnemy();
	Vec2 getEnemyPosition();//���ص����뱾��������ĵ��˵�����
	int getHealthPoint();//����Ӣ�����ڵ�Ѫ��
	int getBluePoint();//����Ӣ�����ڵ�����
	int getDefencePoint();//����Ӣ�����ڵĻ���
	Point getTempPosition() { return Point(xtemp, ytemp); }
	int getType() { return type; }
	int getCoinsNeeded() { return CoinsNeeded; }
	int getSoldCoins() { return SoldCoins; }
	int getPlayer() { return OfPlayer; }           //�����������
	int getStar() { return star; }
	Point getPosition() { return Point(x, y); }
	float getAttackSpeed() { return speedAttack; }
	int getAttackDistance() { return distanceAttack; }
	int getPhysicalAttack() { return physicsAttackPoint; }
	int getMagicalPoint() { return magicPoint; }
	int getCriticalChance() { return criticalChance; }//������
	int getDefencePhysics() { return defencePhysics; }//�￹
	int getDefenceMagic() { return defenceMagic; }//ħ��//ħ��
	int getHeroStar() { return star; }
	std::string getname() { return name; }
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
	Label* Star = Label::createWithTTF(std::to_string(star), "fonts/arial.ttf", 24);

	float calculateDistance(Sprite* d_sprite);//���㱾��������˾��뺯��
	void onDamageReceived(int damage, int type);
	bool doDamage(int damage, int type = 0, bool damageVisible = 0);//�ҷ��յ��˺���������������ҷ�������Ѫ���ļ���
	bool blueClear();//�ͷż���Ҫ�����������ͷż���֮���������
	void healthRecover(int health_once, int lasting);//��Ѫ����
	void blueRocover();//��������
	void healthRecoverOnce(int health_once);//��һ��Ѫ//����ָ����һ�λ�Ѫ��
	void blueRecoverOnce();//��һ����
	void EquipmentChange();
	void hero::EquipToChess(Equipment* equ);
	virtual void attack(float dt);//����
	void bloodUpdate(float dt);//����Ӣ��ͷ��Ѫ����������Ϣ
	void skill();//�ż���
	bool die();
	virtual void releaseSkill();
	void shootbullet(std::string picturename, Point deltaPos, hero* mychess, int size, int damageType = 0, bool isCanSee = 0);
	void reset();
	bool isMove = 0;
	hero* attackTarget = nullptr;//����Ŀ��

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
	float speedAttack;//���٣�ÿ����ٴ�
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