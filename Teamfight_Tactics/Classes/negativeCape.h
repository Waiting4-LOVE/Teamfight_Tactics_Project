#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class negativeCape :public Equipment{
public:
	CREATE_FUNC(negativeCape);
	static negativeCape* createNegativeCape();
};

