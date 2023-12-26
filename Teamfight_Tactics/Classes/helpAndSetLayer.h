#pragma once
#include "cocos2d.h"
#include "SelecScene.h"
#include "littleHero.h"
#include "Maplayer.h"
#include <string>
USING_NS_CC;

class helpAndSetLayer :public Layer{
public:
	virtual bool init();
	static helpAndSetLayer* createLayer();
	void backToMenu(cocos2d::Ref* pSender);
	CREATE_FUNC(helpAndSetLayer);
};

