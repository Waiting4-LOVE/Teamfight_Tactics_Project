#include "ShopLayer.h"
USING_NS_CC;

hero* ShopLayer::heroCreate(int ct) {
    switch (ct) {
    case 0:
        return hero1::createhero();
    }
}
ShopLayer* ShopLayer::createShopLayer()
{
	auto temp=ShopLayer::create();

	temp->retain();
	return temp;
}

bool ShopLayer::init()
{
	srand(time(NULL));

    /*------------------refresh----------------------------*/
    auto reFresh = Menu::create(Refresh, nullptr);
    reFresh->setPosition(535, 40);
    this->addChild(reFresh);
	return true;
}

ShopLayer::ShopLayer()
{
    shop_Layer->setPosition(0, 0);
    this->addChild(shop_Layer);
	heroShop();
}



void ShopLayer::heroShop()
{
    refreshShop2(MyLittleHero);
    //1
    auto buy1 = MenuItemImage::create(MyLittleHero.Used[0].picture_name, MyLittleHero.Used[0].picture_name, CC_CALLBACK_1(ShopLayer::buy1, this));
    auto Buy1 = Menu::create(buy1, nullptr);
    Buy1->setPosition(HeroInShopPos[0]);
    shop_Layer->addChild(Buy1);
    //2
    auto buy2 = MenuItemImage::create(MyLittleHero.Used[1].picture_name, MyLittleHero.Used[1].picture_name, CC_CALLBACK_1(ShopLayer::buy2, this));
    auto Buy2 = Menu::create(buy2, nullptr);
    Buy2->setPosition(HeroInShopPos[1]);
    shop_Layer->addChild(Buy2);
    //3
    auto buy3 = MenuItemImage::create(MyLittleHero.Used[2].picture_name, MyLittleHero.Used[2].picture_name, CC_CALLBACK_1(ShopLayer::buy3, this));
    auto Buy3 = Menu::create(buy3, nullptr);
    Buy3->setPosition(HeroInShopPos[2]);
    shop_Layer->addChild(Buy3);
    //4
    auto buy4 = MenuItemImage::create(MyLittleHero.Used[3].picture_name, MyLittleHero.Used[3].picture_name, CC_CALLBACK_1(ShopLayer::buy4, this));
    auto Buy4 = Menu::create(buy4, nullptr);
    Buy4->setPosition(HeroInShopPos[3]);
    shop_Layer->addChild(Buy4);
    //5
    auto buy5 = MenuItemImage::create(MyLittleHero.Used[4].picture_name, MyLittleHero.Used[4].picture_name, CC_CALLBACK_1(ShopLayer::buy5, this));
    auto Buy5 = Menu::create(buy5, nullptr);
    Buy5->setPosition(HeroInShopPos[4]);
    shop_Layer->addChild(Buy5);
    
}

bool ShopLayer::ifCanBuy(int m, littleHero& lh) {
    int sum = 0;
    if (lh.Used[m].money > MyLittleHero.getCoins()) {
        auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return 0;
    }
    for (int i = 0; i < 9; i++) {
        sum += waitLatticeExist[0][i];
    }
    if (sum == 9) {
        auto label = Label::createWithTTF("Prepare Zone is Full!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return 0;
    }
    else return 1;
}



void ShopLayer::refreshShop1(cocos2d::Ref* pSender) {
    if (MyLittleHero.getCoins() >= 2) {
        MyLittleHero.delCoins(2);
        shop_Layer->removeAllChildren();

        heroShop();
    }
    else {
        auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
        this->addChild(label);
        label->setTextColor(Color4B::WHITE);
        label->setPosition(800, 400);
        auto move = FadeOut::create(2.0f);
        label->runAction(move);
        return;
    }
}

void ShopLayer::refreshShop2(littleHero& lh) {
    for (int i = 0; i < 5; i++)
    {
        int deter = 0;
        deter = rand() % 100 + 1;
        for (int j = 0; j < 5; j++)
        {
            if (deter > PB[min(9, lh.getLevel()) - 1][j])
                deter -= PB[min(9, lh.getLevel()) - 1][j];
            else
            {
                int temp = 0;
                while (1)
                {
                    temp = rand() % OriginalChess;
                    if (chess_store[temp].money == j + 1)
                        break;
                }
                lh.Used[i].address = chess_store[temp].address;
                lh.Used[i].money = chess_store[temp].money;
                lh.Used[i].picture_name = chess_store[temp].picture_name;
                lh.Used[i].buy = false;
                break;
            }
        }
    }
}

void ShopLayer::cover(Vec2 point)
{
    auto cover = Sprite::create("cover.png");
    shop_Layer->addChild(cover);
    cover->setPosition(point);
}

void ShopLayer::buy1(cocos2d::Ref* pSender) {
    if (MyLittleHero.Used[0].buy == false && ifCanBuy(0, MyLittleHero))
    {
        auto sprite = heroCreate(MyLittleHero.Used[0].address);
        ccArrayAppendObject(MyLittleHero.m_playerArray, sprite);//放入GameSprite类中addChild
        MyLittleHero.Used[0].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        MyLittleHero.haveNewHero = true;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(HeroInShopPos[0]);//覆盖或者移除
    }
}

void ShopLayer::buy2(cocos2d::Ref* pSender) {
    if (MyLittleHero.Used[1].buy == false && ifCanBuy(1, MyLittleHero))
    {
        auto sprite = heroCreate(MyLittleHero.Used[1].address);
        ccArrayAppendObject(MyLittleHero.m_playerArray, sprite);//放入GameSprite类中addChild
        MyLittleHero.Used[1].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        MyLittleHero.haveNewHero = true;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(HeroInShopPos[1]);//覆盖或者移除
    }
}

void ShopLayer::buy3(cocos2d::Ref* pSender) {
    if (MyLittleHero.Used[2].buy == false && ifCanBuy(2, MyLittleHero))
    {
        auto sprite = heroCreate(MyLittleHero.Used[2].address);
        ccArrayAppendObject(MyLittleHero.m_playerArray, sprite);//放入GameSprite类中addChild
        MyLittleHero.Used[2].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        MyLittleHero.haveNewHero = true;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(HeroInShopPos[2]);//覆盖或者移除
    }
}

void ShopLayer::buy4(cocos2d::Ref* pSender) {
    if (MyLittleHero.Used[3].buy == false && ifCanBuy(3, MyLittleHero))
    {
        auto sprite = heroCreate(MyLittleHero.Used[3].address);
        ccArrayAppendObject(MyLittleHero.m_playerArray, sprite);//放入GameSprite类中addChild
        MyLittleHero.Used[3].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        MyLittleHero.haveNewHero = true;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(HeroInShopPos[3]);//覆盖或者移除
    }
}
void ShopLayer::buy5(cocos2d::Ref* pSender) {
    if (MyLittleHero.Used[4].buy == false && ifCanBuy(4, MyLittleHero))
    {
        auto sprite = heroCreate(MyLittleHero.Used[4].address);
        ccArrayAppendObject(MyLittleHero.m_playerArray, sprite);//放入GameSprite类中addChild
        MyLittleHero.Used[4].buy = true;                                     //备战区满载后应禁止点击此按钮(已实现)
        MyLittleHero.haveNewHero = true;           //GameSprite类中的update函数实时监测该变量的值，当其为1时则执行addChild操作
        cover(HeroInShopPos[4]);//覆盖或者移除
    }
}