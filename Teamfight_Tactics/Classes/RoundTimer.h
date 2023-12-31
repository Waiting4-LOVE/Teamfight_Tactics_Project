#ifndef _GAME_TIMER_H_
#define _GAME_TIMER_H_

#include "cocos2d.h"


USING_NS_CC;

class RoundTimer :public cocos2d::Node
{
public:
	RoundTimer();

	virtual ~RoundTimer();

	static RoundTimer* create(float time);

	void update(float delta);

	bool init(float time);
	float pTime = 100;

private:

	cocos2d::Label* label;
	//friend class GameScene;
	//friend class Chess;

};

#endif