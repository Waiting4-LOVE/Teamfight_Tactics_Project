#pragma once
#include "hero.h"
class knight :public hero{
public:
	knight();
	static knight* createhero();
	void releaseSkill();
	CREATE_FUNC(knight);
	void update(float dt);

};

