#include "ShopLayer.h"
USING_NS_CC;
ShopLayer* ShopLayer::createShopLayer()
{
	auto temp=ShopLayer::create();

	temp->retain();
	return temp;
}

bool ShopLayer::init()
{
	srand(time(NULL));
	return true;
}

ShopLayer::ShopLayer()
{
	heroShop();
}

void ShopLayer::refreshShop1(cocos2d::Ref* pSender)
{
    /*if (player1data.Gold >= 2)
    {

        player1data.Gold -= 2;
        s_layer->removeAllChildren();
        chessStore();
    }
    else
    {
        auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return;
    }*/
}

void ShopLayer::heroShop()
{
    /*-------------------1026 174 显示金币-------------------*/
    //记得弄一个金币数量返回字符串的函数
    auto goldlabel = Label::createWithTTF("Gold: ", "fonts/Marker Felt.ttf", 36);
    goldlabel->setPosition(1026, 174);
    shop_Layer->addChild(goldlabel);

    /*------------------refresh----------------------------*/
    auto Refresh = MenuItemImage::create("refresh.png", "refresh.png", CC_CALLBACK_1(ShopLayer::refreshShop1, this));
    auto reFresh = Menu::create(Refresh, nullptr);
    reFresh->setPosition(110, 570);
    shop_Layer->addChild(reFresh, 1);
   // refresh(player1data);
    /*if (player2data.Gold > 2)
    {
        player2data.Gold -= 2;
        refresh(player2data);
    }*/





}
