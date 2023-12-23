#pragma once
#include "cocos2d.h"
#include <string>
#include "littleHero.h"


using namespace cocos2d;
using namespace std;


class LittleHeroLayer :public Layer
{
public:
	static LittleHeroLayer* createPlayer();
	virtual bool init();
	void update(float dt);
	void BuyExp(Ref* pSender);


	Label* Coins = Label::createWithTTF(to_string(MyLittleHero.getCoins()), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Grades = Label::createWithTTF(to_string(MyLittleHero.getLevel()), "fonts/Marker Felt.ttf", 22);  //临时记录
	Label* Hyut = Label::createWithTTF(to_string(MyLittleHero.getCurBlood()), "fonts/Marker Felt.ttf", 24);

	MenuItemImage* BuyExpItem = MenuItemImage::create("BuyExp.png", "BuyExp.png",
		CC_CALLBACK_1(LittleHeroLayer::BuyExp, this));
	Menu* buyexp = Menu::create(BuyExpItem, nullptr);
	Sprite * myLittleHerosprite = Sprite::create("p1.png");
	//血条显示
	//* MyLittleHeroBlood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	//Sprite* MyLittleHeroBloodFrame = Sprite::create("BloodFrame.jpg");

	//ProgressTimer* MyLittleHeroExperience = ProgressTimer::create(Sprite::create("greenblood.png"));
	//Sprite* MyLittleHeroexpFrame = Sprite::create("BloodFrame.jpg");


	 /***********小小英雄移动操作************/
	//void LittleHeroMoveInMouse();
	void onMouseDown(Event* event);
	bool ismoving = false;

	CREATE_FUNC(LittleHeroLayer);
};