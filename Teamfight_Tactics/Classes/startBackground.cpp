#include "startBackground.h"
#include "Resource.h"
#include "audio/include/AudioEngine.h"
using namespace cocos2d;

Scene* startBackground::scene() {
	Scene* scene = Scene::create();
	startBackground* layer = startBackground::create();
	scene->addChild(layer);
	return scene;
}

bool startBackground::init() {
	if (!Layer::init()) return false;
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("CloseNormal.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("CloseNormal.png");
	
	this->winSize = Director::getInstance()->getWinSize();

	Sprite* sp = Sprite::create("CloseSelected.png");
	sp->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	sp->setScale(1.5);
	this->addChild(sp, 0, 1);
}