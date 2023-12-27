#pragma once
#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class elf :public hero
{
public:
	elf();
	static elf* createhero();
	void releaseSkill();
	CREATE_FUNC(elf);
};

class _2star_elf :public elf
{
public:
	_2star_elf();
	static _2star_elf* createhero();
	CREATE_FUNC(_2star_elf);
};

class _3star_elf :public elf
{
public:
	_3star_elf();
	static _3star_elf* createhero();
	CREATE_FUNC(_3star_elf);
};