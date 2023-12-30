#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class goldenMonster :public hero
{
public:
	goldenMonster();
	void attack(float dt);
	static goldenMonster* createhero();
	void releaseSkill();
	CREATE_FUNC(goldenMonster);
};

class _2star_goldenMonster :public goldenMonster
{
public:
	_2star_goldenMonster();
	static _2star_goldenMonster* createhero();
	CREATE_FUNC(_2star_goldenMonster);
};

class _3star_goldenMonster :public goldenMonster
{
public:
	_3star_goldenMonster();
	static _3star_goldenMonster* createhero();
	CREATE_FUNC(_3star_goldenMonster);
};