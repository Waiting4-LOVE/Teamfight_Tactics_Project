#include "LittleHeroLayer.h"

const Point myBloodPos = Point(250, 510);
const Point myGradesPos = Point(450, 170);
const Point myGoldPos = Point(1030, 170);
const Point BuyExpPos = Point(535, 115);
littleHero MyLittleHero;

LittleHeroLayer* LittleHeroLayer::createPlayer()
{
    auto LittleHeroLayer = LittleHeroLayer::create();
    //精灵
	

    return LittleHeroLayer;
}

bool LittleHeroLayer::init()
{
	/*------------------------买经验------------------*/
	if (MyLittleHero.getCoins() >= 4)
	{
		buyexp->setPosition(BuyExpPos);
		this->addChild(buyexp, 1);
	}

	/*------------------------等级显示------------------*/
	Grades->setPosition(myGradesPos);
	this->addChild(Grades, 1);

	/*------------------------金币显示------------------*/
	Coins->setPosition(myGoldPos);
	this->addChild(Coins, 1);


	/*------------------------小小英雄移动------------------*/
	this->addChild(myLittleHerosprite); //加到树中
	 // 设置鼠标事件监听器
	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(LittleHeroLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	return true;
}

void LittleHeroLayer::update(float dt)
{
}

void LittleHeroLayer::BuyExp(Ref* pSender)
{
	if (MyLittleHero.getCoins() >= 4)
	{
		MyLittleHero.delCoins(4);
		MyLittleHero.addExp(4);
		Coins->setString(to_string(MyLittleHero.getCoins()));
	}
	else
	{
		this->removeChild(buyexp);
		auto label = Label::createWithTTF("Not enough money!", "fonts/Marker Felt.ttf", 36);
		this->addChild(label);
		label->setTextColor(Color4B::WHITE);
		label->setPosition(800, 400);
		auto move = FadeOut::create(2.0f);
		label->runAction(move);
		
	}
}

/*void LittleHeroLayer::LittleHeroMoveInMouse()
{
	auto MouseListener = EventListenerMouse::create();
	MouseListener = EventListenerMouse::create();
	MouseListener->onMouseDown = CC_CALLBACK_1(LittleHeroLayer::onMouseDown, this);
}*/

void LittleHeroLayer::onMouseDown(Event* event)
{
	auto mouseEvent = dynamic_cast<cocos2d::EventMouse*>(event);
	if (mouseEvent->getMouseButton() == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT)
	{
		auto locationInView = mouseEvent->getLocationInView();
		auto location = cocos2d::Director::getInstance()->convertToGL(locationInView);

		// 移动精灵到鼠标右键点击的位置
		myLittleHerosprite->setPosition(location);
		CCLOG("Right mouse button clicked at (%f, %f)", location.x, location.y);
	}
}


