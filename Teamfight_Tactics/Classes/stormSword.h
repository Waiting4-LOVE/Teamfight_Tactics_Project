#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class stormSword :public Equipment {
public:
	CREATE_FUNC(stormSword);
	static stormSword* createStormSword();
};

