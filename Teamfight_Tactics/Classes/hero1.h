#include<cocos2d.h>
#include"const.h"
#include"hero.h"
using namespace cocos2d;
using namespace heroConsts;


class hero1 :public hero
{
public:
	hero1();
	static hero1* createhero();
	void releaseSkill();
	CREATE_FUNC(hero1);
};

class _2star_hero1 :public hero1
{
public:
	_2star_hero1();
	static _2star_hero1* createhero();
	CREATE_FUNC(_2star_hero1);
};

class _3star_hero1 :public hero1
{
	_3star_hero1();
	static _3star_hero1* createhero();
	CREATE_FUNC(_3star_hero1);
};