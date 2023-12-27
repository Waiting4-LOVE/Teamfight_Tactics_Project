#include "helpAndSetLayer.h"

helpAndSetLayer* helpAndSetLayer::createLayer() {
	auto layer = helpAndSetLayer::create();
	layer->retain();
	layer->autorelease();
	return layer;
}

bool helpAndSetLayer::init() {
    MenuItemImage* backInScene = MenuItemImage::create("backNormal.png", "backSelected.png",
        CC_CALLBACK_1(helpAndSetLayer::backToMenu, this));
    Menu* BackInScene = Menu::create(backInScene, nullptr);
    backInScene->setScaleX(0.1);
    backInScene->setScaleY(0.1);

    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
    // 窗口左上角的坐标
    float leftX = origin.x;
    float topY = origin.y + visibleSize.height;
    BackInScene->setPosition(leftX + 20, topY - 20);

    this->addChild(BackInScene, 1);
    return true;
}

void helpAndSetLayer::backToMenu(cocos2d::Ref* pSender) {
    //MyLittleHero.remain();
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 10; j++){
            //ChessExist[i][j] = 0;徐陈皓：还要修改，推出后算作小小英雄死亡
        }
    }
    _director->replaceScene(SelectScene::createScene());
}