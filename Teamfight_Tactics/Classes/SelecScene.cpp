#include "SelecScene.h"
#include "BattleScene.h"
#include "Sources.h"
#include "Definition.h"
USING_NS_CC;
cocos2d::Scene* SelectScene::createScene()
{
    return SelectScene::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool SelectScene::init()
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
    auto sprite = Sprite::create("backpage.png");
    if (sprite == nullptr)
    {
        problemLoading("'backpage.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    auto singleItem = MenuItemImage::create(
        "single.png",
        "singleselected.png",
        CC_CALLBACK_1(SelectScene::menuCloseCallback, this));
    auto multiItem = MenuItemImage::create(
        "multiplayer.png",
        "multiplayerselected.png",
        CC_CALLBACK_1(SelectScene::menuCloseCallback, this));
    if (singleItem == nullptr ||
        singleItem->getContentSize().width <= 0 ||
        singleItem->getContentSize().height <= 0)
    {
        problemLoading("'single.png' and 'singleselected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 - multiItem->getContentSize().width;
        float y = origin.y + visibleSize.height / 2;
        singleItem->setPosition(Vec2(x, y));
    }
    if (multiItem == nullptr ||
        multiItem->getContentSize().width <= 0 ||
        multiItem->getContentSize().height <= 0)
    {
        problemLoading("'multiplayer.png' and 'multiplayerselected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 + multiItem->getContentSize().width;
        float y = origin.y + visibleSize.height / 2;
        multiItem->setPosition(Vec2(x, y));
    }
    // create menu, it's an autorelease object
    auto menu2 = Menu::create(singleItem, multiItem, NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2, 1);

    //test°´Å¥
    auto testItem = MenuItemImage::create(
        "test.png",
        "test.png",
        CC_CALLBACK_1(SelectScene::GotoBattleScene, this));
    if (testItem == nullptr ||
        testItem->getContentSize().width <= 0 ||
        testItem->getContentSize().height <= 0)
    {
        problemLoading("'test.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - testItem->getContentSize().width / 2;
        float y = origin.y + testItem->getContentSize().height / 2;
        testItem->setPosition(Vec2(x, y));
    }
    auto testmenu = Menu::create(testItem, NULL);
    testmenu->setPosition(Vec2::ZERO);
    this->addChild(testmenu, 1);

    return true;
}

void SelectScene::GotoBattleScene(cocos2d::Ref* pSender)
{
    auto scene = BattleScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void SelectScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
