#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class cannedPig :public hero
{
public:
	cannedPig();
	static cannedPig* createhero();
	void releaseSkill();
	CREATE_FUNC(cannedPig);
};

class _2star_cannedPig :public cannedPig
{
public:
	_2star_cannedPig();
	static _2star_cannedPig* createhero();
	CREATE_FUNC(_2star_cannedPig);
};

class _3star_cannedPig :public cannedPig
{
	_3star_cannedPig();
	static _3star_cannedPig* createhero();
	CREATE_FUNC(_3star_cannedPig);
};