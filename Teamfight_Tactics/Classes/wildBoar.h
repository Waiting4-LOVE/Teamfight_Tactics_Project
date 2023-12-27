#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class wildBoar :public hero
{
public:
	wildBoar();
	static wildBoar* createhero();
	void releaseSkill();
	CREATE_FUNC(wildBoar);
};

class _2star_wildBoar :public wildBoar
{
public:
	_2star_wildBoar();
	static _2star_wildBoar* createhero();
	CREATE_FUNC(_2star_wildBoar);
};

class _3star_wildBoar :public wildBoar
{
public:
	_3star_wildBoar();
	static _3star_wildBoar* createhero();
	CREATE_FUNC(_3star_wildBoar);
};