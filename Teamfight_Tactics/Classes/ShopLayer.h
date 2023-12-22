#pragma once
#include "cocos-ext.h"
#include "cocos2d.h"
#include "Sources.h"
using namespace cocos2d::extension;	


class ShopLayer : public cocos2d::Layer
{
private:
	int x = 730;
	int y = 75;
	const std::string heroValue[5] =
	{ "1 coin","2 coins","3 coins","4 coins","5 coins" };

	cocos2d::Layer * shop_Layer=Layer::create();

	//Hero* HeroCreate(int i);

public:
	static ShopLayer* createShopLayer();
	CREATE_FUNC(ShopLayer);
	virtual bool init();
	ShopLayer();

	void refreshShop1(cocos2d::Ref* pSender);
	void refreshShop2(cocos2d::Ref* pSender);


	/********商店锁定相关**********/
	void heroShop();
	void lockShop();
	void unlockShop();
	void storeHero(int heroNum);

	/**************购买相关***************/
	void cover(float x, float y);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);
	void buy5(cocos2d::Ref* pSender);
	//bool ifCanBuy(int m, PlayerData& playerdata);
	//friend class littleHero;

};
