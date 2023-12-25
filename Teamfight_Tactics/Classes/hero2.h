#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class hero2 :public hero
{
public:
	hero2();
	static hero2* createhero();
	void releaseSkill();
	CREATE_FUNC(hero2);
};

class _2star_hero2 :public hero2
{
public:
	_2star_hero2();
	static _2star_hero2* createhero();
	CREATE_FUNC(_2star_hero2);
};

class _3star_hero2 :public hero2
{
	_3star_hero2();
	static _3star_hero2* createhero();
	CREATE_FUNC(_3star_hero2);
};