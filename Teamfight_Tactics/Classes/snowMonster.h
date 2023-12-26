#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class snowMonster :public hero
{
public:
	snowMonster();
	static snowMonster* createhero();
	void releaseSkill();
	CREATE_FUNC(snowMonster);
};

class _2star_snowMonster :public snowMonster
{
public:
	_2star_snowMonster();
	static _2star_snowMonster* createhero();
	CREATE_FUNC(_2star_snowMonster);
};

class _3star_snowMonster :public snowMonster
{
	_3star_snowMonster();
	static _3star_snowMonster* createhero();
	CREATE_FUNC(_3star_snowMonster);
};