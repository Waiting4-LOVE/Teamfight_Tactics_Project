#include "LittleHeroLayer.h"

const Point myBloodPos = Point(250, 510);
const Point myGradesPos = Point(450, 170);
const Point myGoldPos = Point(1030, 170);
const Point BuyExpPos = Point(535, 115);
//littleHero MyLittleHero;

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
		Grades->setString(to_string(MyLittleHero.getLevel()));
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
	if (mouseEvent->getMouseButton() == cocos2d::EventMouse::MouseButton::BUTTON_RIGHT && !ismoving)
	{
		
		auto locationInView = mouseEvent->getLocationInView();

		// �ƶ����鵽����Ҽ������λ��
		double dis = sqrt(pow(MyLittleHero.m_pos.x - locationInView.x, 2) + pow(MyLittleHero.m_pos.y - locationInView.y, 2));
		double moveSec = dis / MyLittleHero.m_moveSpeed;
		auto moveTo = MoveTo::create(moveSec, locationInView);
		auto callback = CallFunc::create([&]() { ismoving = false; });
		auto sequence = Sequence::create(moveTo, callback, nullptr);
		myLittleHerosprite->runAction(sequence);
		MyLittleHero.updatePos(locationInView);
		ismoving = true;
		CCLOG("Right mouse button clicked at (%f, %f,%lf)", locationInView.x, locationInView.y, moveSec);
	}
}


