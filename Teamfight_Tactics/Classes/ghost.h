#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class ghost :public hero
{
public:
	ghost();
	static ghost* createhero();
	void releaseSkill();
	CREATE_FUNC(ghost);
};

class _2star_ghost :public ghost
{
public:
	_2star_ghost();
	static _2star_ghost* createhero();
	CREATE_FUNC(_2star_ghost);
};

class _3star_ghost :public ghost
{
	_3star_ghost();
	static _3star_ghost* createhero();
	CREATE_FUNC(_3star_ghost);
};