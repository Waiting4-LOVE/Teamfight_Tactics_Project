/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "OnlineRoomScene.h"
#include "Definition.h"
#include "GameData.h"
#include "OnlineWaitingScene.h"

USING_NS_CC;

Scene* OnlineRoomScene::createScene()
{
    return OnlineRoomScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool OnlineRoomScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(OnlineRoomScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object

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

    auto hostRoomItem = MenuItemImage::create(
        "hostRoom.png",
        "hostRoom.png",
        CC_CALLBACK_1(OnlineRoomScene::hostroom, this));

    if (hostRoomItem == nullptr ||
        hostRoomItem->getContentSize().width <= 0 ||
        hostRoomItem->getContentSize().height <= 0)
    {
        problemLoading("'hostRoom.png' and 'hostRoom.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 - hostRoomItem->getContentSize().width;
        float y = origin.y + visibleSize.height / 2;
        hostRoomItem->setPosition(Vec2(x, y));
    }

    auto joinRoomItem = MenuItemImage::create(
        "joinRoom.png",
        "joinRoom.png",
        CC_CALLBACK_1(OnlineRoomScene::joinroom, this));

    if (joinRoomItem == nullptr ||
        joinRoomItem->getContentSize().width <= 0 ||
        joinRoomItem->getContentSize().height <= 0)
    {
        problemLoading("'hostRoom.png' and 'hostRoom.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 + joinRoomItem->getContentSize().width;
        float y = origin.y + visibleSize.height / 2;
        joinRoomItem->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(closeItem, hostRoomItem, joinRoomItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);


    return true;

}


void OnlineRoomScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}


void OnlineRoomScene::hostroom(cocos2d::Ref* pSender)
{
    global_data->host = 1;
    auto scene = OnlineWaitingScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void OnlineRoomScene::joinroom(cocos2d::Ref* pSender)
{
    global_data->isonline = 1;
	auto scene = OnlineWaitingScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


