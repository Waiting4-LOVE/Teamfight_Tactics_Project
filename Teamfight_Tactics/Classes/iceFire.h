#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class iceFire :public hero
{
public:
	iceFire();
	void attack(float dt);
	static iceFire* createhero();
	void releaseSkill();
	CREATE_FUNC(iceFire);
};

class _2star_iceFire :public iceFire
{
public:
	_2star_iceFire();
	static _2star_iceFire* createhero();
	CREATE_FUNC(_2star_iceFire);
};

class _3star_iceFire :public iceFire
{
	_3star_iceFire();
	static _3star_iceFire* createhero();
	CREATE_FUNC(_3star_iceFire);
};