#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class darkKnight :public hero
{
public:
	darkKnight();
	void attack(float dt);
	static darkKnight* createhero();
	void releaseSkill();
	CREATE_FUNC(darkKnight);
};

class _2star_darkKnight :public darkKnight
{
public:
	_2star_darkKnight();
	static _2star_darkKnight* createhero();
	CREATE_FUNC(_2star_darkKnight);
};

class _3star_darkKnight :public darkKnight
{
	_3star_darkKnight();
	static _3star_darkKnight* createhero();
	CREATE_FUNC(_3star_darkKnight);
};