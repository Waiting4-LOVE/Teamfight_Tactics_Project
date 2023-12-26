#pragma once
#include "Equipment.h"
#include "cocos2d.h"
USING_NS_CC;

class boxingGloves :public Equipment{
public:
	CREATE_FUNC(boxingGloves);
	static boxingGloves* createBoxingGloves();
};

