#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class flyDragon :public hero
{
public:
	flyDragon();
	static flyDragon* createhero();
	void releaseSkill();
	CREATE_FUNC(flyDragon);
};

class _2star_flyDragon :public flyDragon
{
public:
	_2star_flyDragon();
	static _2star_flyDragon* createhero();
	CREATE_FUNC(_2star_flyDragon);
};

class _3star_flyDragon :public flyDragon
{
public:
	_3star_flyDragon();
	static _3star_flyDragon* createhero();
	CREATE_FUNC(_3star_flyDragon);
};