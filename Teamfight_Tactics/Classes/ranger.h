#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class ranger :public hero
{
public:
	ranger();
	static ranger* createhero();
	void releaseSkill();
	CREATE_FUNC(ranger);
};

class _2star_ranger :public ranger
{
public:
	_2star_ranger();
	static _2star_ranger* createhero();
	CREATE_FUNC(_2star_ranger);
};

class _3star_ranger :public ranger
{
public:
	_3star_ranger();
	static _3star_ranger* createhero();
	CREATE_FUNC(_3star_ranger);
};