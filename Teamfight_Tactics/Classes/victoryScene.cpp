#pragma once
#include "victoryScene.h"

Scene* victoryScene::createVictoryScene() {
	return victoryScene::create();
}

bool victoryScene::init() {
	if (Scene::create()) return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite1 = Sprite::create("victoryScene.png"); //这里图片资源需要补充
	sprite1->setPosition(800, 460);
	this->addChild(sprite1);

	/*---------MenuItemImage* BackToMenu--------*/
	auto backToMenu = MenuItemImage::create("backToMenu.png", "backToMenu.png", CC_CALLBACK_1(victoryScene::backToMenu, this));
	this->addChild(backToMenu);
	backToMenu->setPosition(600, 100);

	auto backToMenu0 = Menu::create(backToMenu, NULL);
	backToMenu->setPosition(Vec2::ZERO);
	this->addChild(backToMenu0, 1);

	/*-------------Sprite* victoryImage------*/
	auto victoryImage = Sprite::create("victoryImage.png"); //需要补充图片
	this->addChild(victoryImage);
	victoryImage->setPosition(600, 450);

	return true;
}

void victoryScene::backToMenu(cocos2d::Ref* pSender) {
	_director->replaceScene(SelectScene::createScene());
}
