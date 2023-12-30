#pragma once
#include "cocos-ext.h"
#include "cocos2d.h"
#include "Sources.h"
#include "littleHero.h"
#include "battleMap.h"
#include"HeroFile.h"
using namespace cocos2d::extension;	


class ShopLayer : public cocos2d::Layer
{
private:

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
	void refreshShop2(littleHero& lh);

	hero* heroCreate(int ct);

	/********商店锁定相关**********/
	void heroShop();
	void lockShop();
	void unlockShop();
	void storeHero(int heroNum);

	/**************购买相关***************/
	void cover(Vec2 point);
	void buy1(cocos2d::Ref* pSender);
	void buy2(cocos2d::Ref* pSender);
	void buy3(cocos2d::Ref* pSender);
	void buy4(cocos2d::Ref* pSender);
	void buy5(cocos2d::Ref* pSender);
	bool ifCanBuy(int m, littleHero& lh);
	//friend class littleHero;
	//刷新按钮
	MenuItemImage* Refresh = MenuItemImage::create("Refresh.png", "Refresh.png", CC_CALLBACK_1(ShopLayer::refreshShop1, this));
	
	string HeroInShop[1] = { "Hero1InShop.png" };
	Vec2 HeroInShopPos[5] = { Vec2(730, 78),Vec2(915,78),Vec2(1106,78),Vec2(1298,78),Vec2(1483,78)};

	/**************初始化***************/
	void initShop();


};
