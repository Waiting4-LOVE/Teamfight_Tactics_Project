#include "SelecScene.h"
#include "BattleScene.h"
#include "Sources.h"
USING_NS_CC;
cocos2d::Scene* BattleScene::createScene()
{
	return BattleScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
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
	auto sprite = Sprite::create("battlemapunclick.png");
	if (sprite == nullptr)
	{
		problemLoading("'battlemapunclick.png'");
	}
	else
	{
		// 获取窗口的大小
		Size visibleSize = Director::getInstance()->getVisibleSize();

		// 计算缩放比例，使图片填满整个窗口
		float scaleX = visibleSize.width / sprite->getContentSize().width;
		float scaleY = visibleSize.height / sprite->getContentSize().height;

		// 使用ScaleTo动作来缩放图片
		sprite->setScaleX(scaleX);
		sprite->setScaleY(scaleY);

		// 设置图片的位置为窗口中心
		sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

		// 添加图片为此层的子节点
		this->addChild(sprite, 0);
	}
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