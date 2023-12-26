#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class snowman :public hero
{
public:
	snowman();
	static snowman* createhero();
	void releaseSkill();
	CREATE_FUNC(snowman);
};

class _2star_snowman :public snowman
{
public:
	_2star_snowman();
	static _2star_snowman* createhero();
	CREATE_FUNC(_2star_snowman);
};

class _3star_snowman :public snowman
{
	_3star_snowman();
	static _3star_snowman* createhero();
	CREATE_FUNC(_3star_snowman);
};