#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class knight :public hero
{
public:
	knight();
	void attack(float dt);
	static knight* createhero();
	void releaseSkill();
	CREATE_FUNC(knight);
};

class _2star_knight :public knight
{
public:
	_2star_knight();
	static _2star_knight* createhero();
	CREATE_FUNC(_2star_knight);
};

class _3star_knight :public knight
{
	_3star_knight();
	static _3star_knight* createhero();
	CREATE_FUNC(_3star_knight);
}; 
