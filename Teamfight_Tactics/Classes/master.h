#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class master :public hero
{
public:
	master();
	static master* createhero();
	void releaseSkill();
	CREATE_FUNC(master);
};

class _2star_master :public master
{
public:
	_2star_master();
	static _2star_master* createhero();
	CREATE_FUNC(_2star_master);
};

class _3star_master :public master
{
	_3star_master();
	static _3star_master* createhero();
	CREATE_FUNC(_3star_master);
};