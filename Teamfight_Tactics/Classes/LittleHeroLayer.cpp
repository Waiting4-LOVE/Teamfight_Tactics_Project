#include "LittleHeroLayer.h"

const Point myBloodPos = Point(250, 510);
const Point myGradesPos = Point(450, 170);
const Point myGoldPos = Point(1030, 170);
const Point BuyExpPos = Point(535, 115);
littleHero MyLittleHero;

LittleHeroLayer* LittleHeroLayer::createPlayer()
{
    auto LittleHeroLayer = LittleHeroLayer::create();
    //����
	

    return LittleHeroLayer;
}

bool LittleHeroLayer::init()
{
	/*------------------------����------------------*/
	if (MyLittleHero.getCoins() >= 4)
	{
		buyexp->setPosition(BuyExpPos);
		this->addChild(buyexp, 1);
	}

	/*------------------------�ȼ���ʾ------------------*/
	Grades->setPosition(myGradesPos);
	this->addChild(Grades, 1);

	/*------------------------�����ʾ------------------*/
	Coins->setPosition(myGoldPos);
	this->addChild(Coins, 1);


	/*------------------------ССӢ���ƶ�------------------*/
	this->addChild(myLittleHerosprite); //�ӵ�����
	 // ��������¼�������
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

		// �ƶ����鵽����Ҽ������λ��
		myLittleHerosprite->setPosition(location);
		CCLOG("Right mouse button clicked at (%f, %f)", location.x, location.y);
	}
}


