#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class pitman :public hero
{
public:
	pitman();
	static pitman* createhero();
	void releaseSkill();
	CREATE_FUNC(pitman);
};

class _2star_pitman :public pitman
{
public:
	_2star_pitman();
	static _2star_pitman* createhero();
	CREATE_FUNC(_2star_pitman);
};

class _3star_pitman :public pitman
{
public:
	_3star_pitman();
	static _3star_pitman* createhero();
	CREATE_FUNC(_3star_pitman);
};