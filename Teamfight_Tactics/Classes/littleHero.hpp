#ifndef __LITTLE_HERO_SPRITE_HPP__
#define __LITTLE_HERO_SPRITE_HPP__

#include "cocos2d.h"
#include <math.h>
USING_NS_CC;

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in littleHero.cpp\n");
}

class littleHero :public Sprite {
public:
	littleHero();
	~littleHero() = 0;
	bool Create(char* filename, int recover); //����ССӢ�۲�������õ���̨��
	void hurt(int delBlood); //�ܵ��˺�������Ѫ��
	void addCoins(int num); //���ӽ��
	void delCoins(int num); //���ٽ��
	void addExp(int exp); //���Ӿ���
	void move(Vec2 curPos); //�ƶ�ССӢ��״̬
	bool dead(); //����
	void test(); //���Ժ���
protected:
	Sprite* sp;
	Vec2 m_pos; //��ǰλ��
	int m_maxBlood = 100; //���Ѫ��
	int m_blood; //��ǰѪ������ʼΪ100,
	const int m_moveSpeed = 30; //�ƶ��ٶ�
	const int m_upExp = 100; //������Ҫ�ľ���ֵ
	int m_coins; //���
	int m_exp; //����ֵ
	int m_level; //�ȼ�
	int m_recover; //��Ѫ��
};

littleHero::littleHero() :m_blood(100), m_moveSpeed(30), m_coins(0), m_exp(0), m_level(1){  }

bool littleHero::Create(char* filename, int recover) {
	this->sp = Sprite::create(filename);
	if (sp == nullptr) problemLoading(filename);
	else {
		auto visibleSize = Director::getInstance()->getVisibleSize();
		this->m_pos = Director::getInstance()->getVisibleOrigin();
		sp->setPosition(Vec2(visibleSize.width / 2 + m_pos.x, visibleSize.height / 2 + m_pos.y)); //�ŵ��м�λ��
		this->addChild(sp, 0); //�ӵ�����
		this->m_recover = recover;
	}
	return true;
}

void littleHero::hurt(int delBlood) {
	this->m_blood -= delBlood;
}

void littleHero::addCoins(int num) {
	this->m_coins += num;
}

void littleHero::delCoins(int num) {
	this->m_coins -= num;
}

void littleHero::addExp(int exp) {
	this->m_exp += exp;
	if (this->m_exp > this->m_upExp) {
		this->m_exp -= this->m_upExp;
		this->m_level++;
	} //����
}

void littleHero::move(Vec2 curPos) {
	double dis = sqrt(pow(this->m_pos.x - curPos.x, 2) + pow(this->m_pos.y - curPos.y, 2)); //�����ƶ�����
	double moveSec = dis / this->m_moveSpeed; //�õ��˶�ʱ��
	auto moveTo = MoveTo::create(moveSec, curPos);
	this->sp->runAction(moveTo);
}

bool littleHero::dead() {
	return this->m_blood <= 0;
}

void littleHero::test() {
	printf("==================================\n");
	printf("��ǰѪ����%d\n", this->m_blood);
	printf("��ǰ��ң�%d\n", this->m_coins);
	printf("��ǰ���飺%d\n", this->m_exp);
	printf("��ǰ�ȼ���%d\n", this->m_level);
	printf("��ǰ��Ѫ����%d\n", this->m_recover);
	printf("==================================\n");
}
#endif //__LITTLE_HERO_SPRITE_HPP__

