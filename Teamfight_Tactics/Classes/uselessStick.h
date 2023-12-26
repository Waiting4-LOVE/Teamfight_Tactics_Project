#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class uselessStick :public Equipment{
public:
	CREATE_FUNC(uselessStick);
	static uselessStick* createUselessStick();
};

