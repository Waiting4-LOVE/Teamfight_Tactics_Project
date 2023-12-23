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


	Label* Coins = Label::createWithTTF(to_string(MyLittleHero.getCoins()), "fonts/Marker Felt.ttf", 22);  //��ʱ��¼
	Label* Grades = Label::createWithTTF(to_string(MyLittleHero.getLevel()), "fonts/Marker Felt.ttf", 22);  //��ʱ��¼
	Label* Hyut = Label::createWithTTF(to_string(MyLittleHero.getCurBlood()), "fonts/Marker Felt.ttf", 24);

	MenuItemImage* BuyExpItem = MenuItemImage::create("BuyExp.png", "BuyExp.png",
		CC_CALLBACK_1(LittleHeroLayer::BuyExp, this));
	Menu* buyexp = Menu::create(BuyExpItem, nullptr);
	Sprite * myLittleHerosprite = Sprite::create("p1.png");
	//Ѫ����ʾ
	//* MyLittleHeroBlood = ProgressTimer::create(Sprite::create("Blood.jpg"));
	//Sprite* MyLittleHeroBloodFrame = Sprite::create("BloodFrame.jpg");

	//ProgressTimer* MyLittleHeroExperience = ProgressTimer::create(Sprite::create("greenblood.png"));
	//Sprite* MyLittleHeroexpFrame = Sprite::create("BloodFrame.jpg");


	 /***********ССӢ���ƶ�����************/
	//void LittleHeroMoveInMouse();
	void onMouseDown(Event* event);

	CREATE_FUNC(LittleHeroLayer);
};