#ifndef __MW_CPP_STARTBACKGROUND_H__
#define __MW_CPP_STARTBACKGROUND_H__

#include "cocos2d.h"

class startBackground :public cocos2d::Layer {
private:
	cocos2d::Size winSize;
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(startBackground);
};
#endif