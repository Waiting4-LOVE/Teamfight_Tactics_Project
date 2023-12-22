#include "SelecScene.h"
#include "BattleScene.h"
#include "littleHero.hpp"
#include "Sources.h"
USING_NS_CC;
cocos2d::Scene* BattleScene::createScene()
{
	return BattleScene::create();
}
/*static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}*/
bool BattleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// add "HelloWorld" splash screen"
	this->addChild(map, 0);        //地图层

	//精灵
	littleHero lh;
	auto littlehero = lh.Create("p1.png", 10);
	littlehero->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y)); //放到中间位置
	addChild(littlehero, 0); //加到树中

	// 创建一个鼠标事件监听器
	auto mouseListener = EventListenerMouse::create();

	// 设置鼠标按下事件处理
	auto temp=lh.getPos();

	// 添加监听器到事件分发器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	return true;
}

void BattleScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}