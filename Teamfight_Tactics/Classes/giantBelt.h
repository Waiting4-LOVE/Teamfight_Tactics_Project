#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class giantBelt :public Equipment{
public:
	CREATE_FUNC(giantBelt);
	static giantBelt* createGiantBelt();
};

