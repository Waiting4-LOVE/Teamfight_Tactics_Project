#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class crookedBow :public Equipment{
public:
	CREATE_FUNC(crookedBow);
	static crookedBow* createCrookedBow();
};

