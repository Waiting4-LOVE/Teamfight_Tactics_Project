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
	MyLittleHerobloodBar->setBarChangeRate(Point(1, 0));
	MyLittleHerobloodBar->setType(ProgressTimer::Type::BAR);
	MyLittleHerobloodBar->setMidpoint(Point(0, 1));
	MyLittleHerobloodBar->setScaleX(0.22);
	MyLittleHerobloodBar->setScaleY(0.6);
	bloodFrame->setScaleX(0.22);
	bloodFrame->setScaleY(0.6);
	myLittleHerosprite->addChild(bloodFrame, 1);
	myLittleHerosprite->addChild(MyLittleHerobloodBar, 2);

	player2HerobloodBar->setBarChangeRate(Point(1, 0));
	player2HerobloodBar->setType(ProgressTimer::Type::BAR);
	player2HerobloodBar->setMidpoint(Point(0, 1));
	player2HerobloodBar->setScaleX(0.22);
	player2HerobloodBar->setScaleY(0.6);
	bloodFrame2->setScaleX(0.22);
	bloodFrame2->setScaleY(0.6);
	player2LittleHerosprite->addChild(bloodFrame2, 1);
	player2LittleHerosprite->addChild(player2HerobloodBar, 2);

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
	myLittleHerosprite->setPosition(MyLittleHero.getCurPos()); //���þ����λ��
	this->addChild(myLittleHerosprite); //�ӵ�����

	player2LittleHerosprite->setPosition(1519,949); //���þ����λ��
	this->addChild(player2LittleHerosprite); //�ӵ���

	/*------------------------ССӢ�۴�������------------------*/
	Animation* animation = Animation::create();
	for (int i = 1; i <= 9; ++i) {
		char frameName[20];
		sprintf(frameName, "EGG%d.png", i);
		animation->addSpriteFrameWithFile(frameName);
	}
	animation->setDelayPerUnit(0.08f);  // ����ÿ֡�Ĳ���ʱ��
	animation->setRestoreOriginalFrame(true);
	Animate* animate = Animate::create(animation);
	RepeatForever* repeat = RepeatForever::create(animate);
	myLittleHerosprite->runAction(repeat);

	Animation* animation2 = Animation::create();
	for (int i = 1; i <= 9; ++i) {
		char frameName[20];
		sprintf(frameName, "EGG%d.png", i);
		animation2->addSpriteFrameWithFile(frameName);
	}
	animation2->setDelayPerUnit(0.08f);  // ����ÿ֡�Ĳ���ʱ��
	animation2->setRestoreOriginalFrame(true);
	Animate* animate2 = Animate::create(animation2);
	RepeatForever* repeat2 = RepeatForever::create(animate2);
	player2LittleHerosprite->runAction(repeat2);
	




	// ��������¼�������
	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(LittleHeroLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	return true;
}

void LittleHeroLayer::update(float dt)
{
	/*------------------------Player1(����)------------------------*/

	/*------------------------Ѫ��------------------*/
	MyLittleHerobloodBar->setPosition(Vec2(50, this->_contentSize.height +100));
	bloodFrame->setPosition(Vec2(50, this->_contentSize.height + 100));
	MyLittleHerobloodBar->setPercentage(float(MyLittleHero.getCurBlood()) / 100 * 100);
	MyLittleHerobloodBar->setTag(MyLittleHero.getCurBlood());
	//Hyut->setString(to_string(MyLittleHero.getCurBlood()));

	/*------------------------��Ǯ------------------*/
	Coins->setString(to_string(MyLittleHero.getCoins())); //��ʱ��¼

	//player1Experience->setPercentage(player1data.ExperienceValue * 100 / player1data.NextNeedExp);
	//��ʱ����Grades->setString("Lv. " + to_string(player1data.Grade));



	/*------------------------Player1(�Է�)------------------------*/

	/*------------------------Ѫ��------------------*/
	player2HerobloodBar->setPosition(Vec2(50, this->_contentSize.height + 100));
	bloodFrame2->setPosition(Vec2(50, this->_contentSize.height + 100));
	player2HerobloodBar->setPercentage(player2data.getCurBlood());
	player2HerobloodBar->setTag(player2data.getCurBlood());
	//Hyut2->setString(to_string(player2data.HealthValue));

	/*------------------------��Ǯ------------------*/
	//����Coins2->setString("Coins: " + to_string(player2data.Gold)); //��ʱ��¼

	//����player2Experience->setPercentage(player2data.ExperienceValue * 100 / player2data.NextNeedExp);
	//Grades2->setString("Lv. " + to_string(player2data.Grade));
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


