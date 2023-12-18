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
		// ��ȡ���ڵĴ�С
		Size visibleSize = Director::getInstance()->getVisibleSize();

		// �������ű�����ʹͼƬ������������
		float scaleX = visibleSize.width / sprite->getContentSize().width;
		float scaleY = visibleSize.height / sprite->getContentSize().height;

		// ʹ��ScaleTo����������ͼƬ
		sprite->setScaleX(scaleX);
		sprite->setScaleY(scaleY);

		// ����ͼƬ��λ��Ϊ��������
		sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

		// ���ͼƬΪ�˲���ӽڵ�
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