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

