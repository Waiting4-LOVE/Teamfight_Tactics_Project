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
	inline littleHero();
	inline littleHero(std::string picName);
	littleHero* attackTarget = nullptr;

	/*------------------------get��----------------------*/
	inline int getCurBlood() { return this->m_blood; }
	inline int getCoins() { return this->m_coins; }
	inline int getExp() { return this->m_exp; }
	inline Vec2 getCurPos() { return this->m_pos; }

	/*------------------------set��----------------------*/
	inline void setPos(Vec2& pos) { this->m_pos = pos; } //����λ�ã�����ΪVec2
	inline void setPos(const int x, const int y) { this->m_pos.x = x, this->m_pos.y = y; } //����λ�ã�����Ϊ����������ֵ
	inline void setSrcPos() { this->m_pos = this->m_SrcPos; } //���س�ʼλ��
	inline Vec2 updatePos(const Vec2& pos) { this->m_pos = pos; } //���µ�ǰλ��
	inline void setPicture(const std::string picName) { this->m_picName = picName; } //����ͼƬ�ļ�����Ƥ��
	inline void hurt(const int delBlood) { this->m_blood -= delBlood; } //�ܵ��˺�������Ѫ��
	inline void addCoins(const int num) { this->m_coins += num; } //���ӽ��
	inline void delCoins(const int num) { this->m_coins -= num; } //���ٽ��
	inline void addExp(const int exp); //���Ӿ���
	inline bool isDead() { return this->m_blood <= 0; }
	CREATE_FUNC(littleHero);

	/*------------------------����ССӢ���ƶ�----------------------*/
	inline MoveTo* move(const Vec2 curPos); //�ƶ�ССӢ��״̬
	inline Vec2 updatePos(const Vec2& pos); //���µ�ǰλ��


protected:
	Vec2 m_SrcPos; //��ʼλ��
	Vec2 m_pos; //��ǰλ��
	int m_maxBlood; //���Ѫ��
	int m_blood; //��ǰѪ������ʼΪ100,
	const int m_moveSpeed; //�ƶ��ٶ�
	const int m_upExp; //������Ҫ�ľ���ֵ
	int m_coins; //���
	int m_exp; //����ֵ
	int m_level; //�ȼ�
	std::string m_picName; //ͼƬ����
};
#endif //__LITTLE_HERO_SPRITE_HPP__

