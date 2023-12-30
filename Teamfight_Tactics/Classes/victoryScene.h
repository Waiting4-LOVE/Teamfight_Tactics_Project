#pragma once
#include "cocos2d.h"
#include "SelecScene.h"
USING_NS_CC;

class victoryScene :public Scene{
public:
	static Scene* createVictoryScene();
	CREATE_FUNC(victoryScene);
private:
	virtual bool init();
	void backToMenu(cocos2d::Ref* pSender);
};

