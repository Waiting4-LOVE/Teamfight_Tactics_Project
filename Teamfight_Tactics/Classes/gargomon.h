#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class gargomon :public hero
{
public:
	gargomon();
	void attack(float dt);
	static gargomon* createhero();
	void releaseSkill();
	CREATE_FUNC(gargomon);
};

class _2star_gargomon :public gargomon
{
public:
	_2star_gargomon();
	static _2star_gargomon* createhero();
	CREATE_FUNC(_2star_gargomon);
};

class _3star_gargomon :public gargomon
{
	_3star_gargomon();
	static _3star_gargomon* createhero();
	CREATE_FUNC(_3star_gargomon);
};