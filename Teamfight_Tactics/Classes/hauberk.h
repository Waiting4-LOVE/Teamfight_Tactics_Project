#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class hauberk :public Equipment{
public:
	CREATE_FUNC(hauberk);
	static hauberk* createHauberk();
};

