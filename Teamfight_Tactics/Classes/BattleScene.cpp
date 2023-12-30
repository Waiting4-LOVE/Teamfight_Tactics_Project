#include "SelecScene.h"
#include "BattleScene.h"
#include "Sources.h"

USING_NS_CC;

cocos2d::Scene* BattleScene::createScene()
{
	return BattleScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool BattleScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	TurnInfoInit();
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//信息框初始化
	infoFrame->setAnchorPoint(Vec2(0, 0.5));
	infoFrame->setScale(1.5);
	infoFrame->setPosition(10000, 10000);
	infoFrame->addChild(heroInfo, 1);
	heroInfo->setPosition(82, -7);
	heroInfo->setColor(Color3B::WHITE);
	heroInfo->setAnchorPoint(Vec2(0, 0));

	/***********所需子Layer************/
	this->addChild(map, 0);        //地图层
	this->addChild(HSlayer, 1);   //返回按钮
	this->addChild(littleLayer, 1); //小英雄层
	this->addChild(timer, 2);        //计时器层
	this->addChild(shopLayer, 3);   //商店层
	this->addChild(heroLayer, 4);   //英雄层

	this->addChild(infoFrame, 100);//信息层


	/**********计时器及Update**************/
	this->scheduleUpdate();
	littleLayer->scheduleUpdate();
	shopLayer->scheduleUpdate();
	heroLayer->scheduleUpdate();
	// 创建一个鼠标事件监听器
	auto mouseListener = EventListenerMouse::create();

	// 设置鼠标按下事件处理
	scheduleUpdate();
	// 添加监听器到事件分发器
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
	return true;
}

void BattleScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
/*
void BattleScene::addChess(littleHero& littlehero, int playerinfo)
{

	if (littlehero.haveNewHero)                  //若有新棋子加入
	{
		bool flag = 1;
		auto temp = ((hero*)(littlehero.m_playerArray->arr[littlehero.m_playerArray->num - 1]));
		if (playerinfo == 0)
		{
			for (int i = 0; i < 8; i++)
			{

				if (ChessExist[i][0 + 9 * playerinfo] == 0)
				{
					littlehero.m_coins -= temp->getCoinsNeeded();
					heroLayer->addChild(temp);
					temp->setPosition(mapPosition[i][0 + 9 * playerinfo].x, mapPosition[i][0 + 9 * playerinfo].y);
					temp->set(mapPosition[i][0 + 9 * playerinfo].x, mapPosition[i][0 + 9 * playerinfo].y);
					temp->setTempPosition();
					temp->retain();
					littlehero.haveNewHero = 0;
					//temp->setPlayer(0);
					temp->setPlayer(playerinfo);
					littlehero.heronumber[temp->getType()]++;     //记录其棋子升级信息
					ChessExist[i][0 + 9 * playerinfo] = 1;        //添加成功
					flag = 0;
					littlehero.haveNewHero = 0;        //防止莫名其妙的BUG
					flag = 0;
					break;

				}
			}
		}
		else
		{
			littlehero.m_coins -= temp->getCoinsNeeded();
			heroLayer->addChild(temp);
			temp->setPosition(10000, 10000);
			temp->set(10000, 10000);
			temp->setPlayer(playerinfo);
			littlehero.heronumber[temp->getType()]++;
			littlehero.haveNewHero = 0;        //防止莫名其妙的BUG
			flag = 0;
			littlehero.haveNewHero = 0;        //防止莫名其妙的BUG
			flag = 0;
		}
		if (flag)
		{
			ccArrayRemoveObject(littlehero.m_playerArray, temp);   //添加失败
			littlehero.haveNewHero = 0;

		}
	}
}*/




void BattleScene::update(float dt)
{
	if (timer->pTime > 1e-6)
	{
		/*gamesprite->upgrade(player1data);             //监测是否可升级
		gamesprite->upgrade(player2data);
		addChess(player1data, 0);
		addChess(player2data, 1);
		pc_player.pcJudgeMoneyUsage();*/
	}

	addChess(MyLittleHero, 0);
	//addChess(player2data, 1);

	ChessMoveInMouse();
	/*if (timer->pTime < -1e-2)
	{
		if (PC_ShowFlag)
		{
			pc_player.pcCreateBattleArray();
			pc_player.pcEquip();
			gamesprite->pcShowFightArray();  //显示电脑玩家信息
			gamesprite->pcShowPlayerArray();
			if (player2data.PlayerArray->num == 8)
				SoldChess(pc_player.pcSoldChess(), player2data.PlayerArray, player2data);   //电脑卖棋子
			PC_ShowFlag = 0;
		}
		GameStartMouseInit();   //取消对战斗区棋子的选取
		timer->setPosition(10000, 10000);
		gamesprite->scheduleUpdate();
		Win();
	}*/

}

void BattleScene::TurnInfoInit()
{
	global_data->ChangeGameTurn();
	auto turn_label = Label::createWithTTF("TURN", "fonts/Marker Felt.ttf", 64);
	turn_label->setPosition(200, 900);
	this->addChild(turn_label, 2);
	char* mTurn = new char[8];
	sprintf(mTurn, "Turn %02d", global_data->game_turn);
	turn_label->setString(mTurn);

}

void BattleScene::ChessMoveInMouse()
{
	//CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
	auto MouseListener = EventListenerMouse::create();
	MouseListener = EventListenerMouse::create();
	MouseListener->onMouseMove = CC_CALLBACK_1(BattleScene::onMouseMove, this);
	MouseListener->onMouseUp = CC_CALLBACK_1(BattleScene::onMouseUp, this);
	MouseListener->onMouseDown = CC_CALLBACK_1(BattleScene::onMouseDown, this);
	MouseListener->onMouseScroll = CC_CALLBACK_1(BattleScene::onMouseScroll, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListener, this);
}

void BattleScene::onMouseScroll(Event* event)
{
	EventMouse* e = (EventMouse*)event;

	e->getScrollX();
	e->getScrollY();

}

void BattleScene::showInfo(hero* chess)//显示英雄信息
{
	infoFrame->setPosition(Vec2(0, 540));
	string heroInformation = StringUtils::format("%s\n%d\n%d\n%d\n%d\n%.2f\n%d\n%d\n%d\n%d\n", chess->getname().c_str(), chess->getHealthPoint(), chess->getBluePoint(), chess->getPhysicalAttack(), chess->getMagicalPoint(), chess->getAttackSpeed(), chess->getAttackDistance(), chess->getCriticalChance() * 100, chess->getDefencePhysics(), chess->getDefenceMagic());
	heroInfo->setString(heroInformation);

	if (heroPicture != NULL)
	{
		heroPicture->removeFromParent();
		heroPicture->release();
	}
	heroPicture = Sprite::create(chess->picturename);
	infoFrame->addChild(heroPicture, 1);
	heroPicture->setPosition(90, 300);
	//CCLOG("%s", chess->getname().c_str());
	if (heroStar != NULL)
	{
		heroStar->removeFromParent();
		heroStar->release();
	}
	if (chess->getHeroStar() == 1)
		heroStar = Sprite::create("1star.png");
	else if (chess->getHeroStar() == 2)
		heroStar = Sprite::create("2star.png");
	else
		heroStar = Sprite::create("3star.png");
	heroStar->setScale(0.15f);
	infoFrame->addChild(heroStar, 1);
	heroStar->setPosition(30, 300);
}

void BattleScene::hideInfo()//隐藏英雄信息
{
	infoFrame->setPosition(Vec2(10000, 10000));
}

void BattleScene::onMouseMove(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	/*
	if (MouseSelectedEquip != -1 && timer->pTime > 1e-6)
	{
		((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(e->getCursorX(), e->getCursorY());
	}*/
	if (MouseToChess != -1)
	{
		if (timer->pTime < 0.01f && MouseToChess < MyLittleHero.m_fightArray->num)//战斗时不能移动战斗区棋子
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(temp->getTempPosition());
			temp->set(temp->getTempPosition());
			MouseToChess = -1;
			return;
		}
		else         //小于FightNumber为战斗区，大于FightNumber为备战区
		{
			if (MouseToChess >= MyLittleHero.m_fightArray->num)
			{
				auto temp = (hero*)(MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]);
				temp->setPosition(e->getCursorX(), e->getCursorY());
				temp->set(e->getCursorX(), e->getCursorY());  //移动之
			}
			else if (MouseToChess >= 0)
			{
				auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
				temp->setPosition(e->getCursorX(), e->getCursorY());
				temp->set(e->getCursorX(), e->getCursorY());  //移动之
			}
		}
	}
	//等ly、zyh写完
}

void BattleScene::onMouseUp(Event* event)
{
	//CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
	EventMouse* e = (EventMouse*)event;
	if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
	{
		//取消装备选取
		/*
		if (MouseSelectedEquip != -1)
		{
			if (EquipSearchChess(e->getCursorX(), e->getCursorY(), MouseSelectedEquip))//装备搜索到附近的棋子
			{
				player1data.occupied_slot--;
			}
			else  //搜索失败，返回原有位置
			{
				((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(player1data.slotPoint[MouseSelectedEquip]);
			}
			MouseSelectedEquip = -1;
		}*/

		if (MouseToChess >= 0 && MouseToChess < MyLittleHero.m_fightArray->num)
		{
			auto temp = ((hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]));
			if (judgeExist(positionToLattice(temp->getPosition()))) //拒绝重合
			{
				temp->setPosition(temp->getTempPosition());
				temp->set(temp->getTempPosition());
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first > 0 && timer->pTime > 0.01f)   //战斗区移到战斗区 
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first == 0 && timer->pTime > 0.01f)  //战斗区移到备战席
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_playerArray);
				}
				else//地图外等情况
				{
					temp->setPosition(temp->getTempPosition());
					temp->set(temp->getTempPosition());
				}
			}
		}
		else if (MouseToChess >= MyLittleHero.m_fightArray->num)
		{
			auto temp = ((hero*)(MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]));
			if (judgeExist(positionToLattice(temp->getPosition()))) //拒绝重合
			{
				temp->setPosition(temp->getTempPosition());
				temp->set(temp->getTempPosition());
				//CCLOG("重合了");
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first == 0)   //备战席移到备战席
				{
					ArrayToArray(temp, MyLittleHero.m_playerArray, MyLittleHero.m_playerArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.01f)   //备战席移到战斗区
				{
					if (MyLittleHero.m_fightArray->num < MyLittleHero.getLevel())
					{
						ArrayToArray(temp, MyLittleHero.m_playerArray, MyLittleHero.m_fightArray);
					}
					else
					{
						temp->setPosition(temp->getTempPosition());
						temp->set(temp->getTempPosition());
						auto label = Label::createWithTTF("full", "fonts/Marker Felt.ttf", 36);
						this->addChild(label, 9);
						label->setTextColor(Color4B::WHITE);
						label->setPosition(800, 400);
						auto fadeout = FadeOut::create(2.0f);
						label->runAction(fadeout);
					}
				}
				else                            //其他不可控情况
				{
					temp->setPosition(temp->getTempPosition());
					temp->set(temp->getTempPosition());
				}
			}
		}
		MouseToChess = -1;                   //取消选取

	}
	//CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
}

void BattleScene::onMouseDown(Event* event)
{
	EventMouse* e = (EventMouse*)event;

	/*选中对象的标志*/
	int Obj_is_Selected = 0;

	/*装备选取*/
   /*if (!Obj_is_Selected && timer->pTime > 1e-6)
	{
		for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
		{
			float dx = (e->getCursorX() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().x);
			float dy = (e->getCursorY() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().y);
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < 20)
			{
				MouseSelectedEquip = i;  //确定选中的装备
				Obj_is_Selected = 1;
			}
		}
	}*/

	if (!Obj_is_Selected)
	{
		if (FindMouseTarget(MyLittleHero.m_fightArray, e))       //在战斗区寻找目标
			FindMouseTarget(MyLittleHero.m_playerArray, e);  //寻找不到则在备战区寻找
	}
	if (MouseToChess >= 0 && infoIsShow != MouseToChess)
	{
		if (MouseToChess >= MyLittleHero.m_fightArray->num)
		{
			showInfo((hero*)MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]);
		}
		else
		{
			showInfo((hero*)MyLittleHero.m_fightArray->arr[MouseToChess]);
		}
		infoIsShow = MouseToChess;
	}
	else if (MouseToChess < 0 && infoIsShow)
	{
		hideInfo();
		infoIsShow = 1000;
	}
}

bool BattleScene::FindMouseTarget(ccArray* Array, EventMouse* e)
{
	int temp = 0;
	if (Array == MyLittleHero.m_playerArray)
	{
		temp = MyLittleHero.m_fightArray->num;
	}
	if (timer->pTime > 0.01f || temp == 0)//非战斗期间或者移动备战席时可移动
	{
		Vec2 mousePos(e->getCursorX(), e->getCursorY());
		for (int i = 0; i < Array->num; i++)
		{
			auto tempHero = (hero*)(Array->arr[i]);
			if (tempHero->getPosition().distance(mousePos) < 50)//若距离小于50则视为选取了该英雄
			{
				if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)//左键
				{
					MouseToChess = temp + i;
					tempHero->setTempPosition();
				}
				else if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_RIGHT)
				{
					soldHero(tempHero, Array, MyLittleHero);
				}
				return 0;
			}
		}
	}
	return 1;
}

void BattleScene::soldHero(hero* temp, ccArray* Array, littleHero& playerdata)//卖出
{
	setLatticeExist(positionToLattice(temp->getPosition()), 0);//所在格子放空
	playerdata.addCoins(temp->getSoldCoins());
	//ccArrayAppendArray(playerdata.UnequipedEquipment, temp->equipment);//脱下的装备
	temp->retain();
	heroLayer->removeChild(temp);       //卖出
	ccArrayRemoveObject(Array, temp);

}

void BattleScene::addChess(littleHero& littlehero, int playerinfo)
{
	if (littlehero.haveNewHero)                  //若有新棋子加入
	{
		bool flag = 1;
		auto temp = (hero*)(littlehero.m_playerArray->arr[littlehero.m_playerArray->num - 1]);
		if (playerinfo == 0)
		{
			for (int i = 0; i < 9; i++)
			{

				if (waitLatticeExist[0 + playerinfo][i] == 0)//若备战区有空位
				{
					littlehero.delCoins(littlehero.Used[0].money);
					temp->set(waitLattice[0 + playerinfo][i]);
					temp->setTempPosition();
					temp->setPosition(temp->getTempPosition());
					heroLayer->addChild(temp);
					temp->retain();
					littlehero.haveNewHero = 0;
					temp->setPlayer(playerinfo);
					littlehero.heronumber[temp->getType()]++;     //记录其棋子升级信息
					setLatticeExist({ 0 + playerinfo,i }, 1);//设置占位
					flag = 0;
					littlehero.haveNewHero = 0;
					flag = 0;
					break;

				}
			}
		}
		else
		{
			littlehero.delCoins(temp->getCoinsNeeded());
			heroLayer->addChild(temp);
			temp->setPosition(10000, 10000);
			temp->set(10000, 10000);
			temp->setPlayer(playerinfo);
			littlehero.heronumber[temp->getType()]++;
			littlehero.haveNewHero = 0;
			flag = 0;
			littlehero.haveNewHero = 0;
			flag = 0;
		}
		if (flag)
		{
			ccArrayRemoveObject(littlehero.m_playerArray, temp);   //添加失败
			littlehero.haveNewHero = 0;

		}
	}
}

void BattleScene::ArrayToArray(hero* chess, ccArray* arrayFrom, ccArray* arrayTo)//备战席/战斗区 From to To的改变
{
	pair<int, int>lat = positionToLattice(chess->getPosition());//现在格子
	pair<int, int>beforeLat = positionToLattice(chess->getTempPosition());//原格子
	chess->setPosition(latticeToPosition(lat));//放到最近的位置上
	chess->set(latticeToPosition(lat));
	setLatticeExist(lat, 1);//填充现在格子
	setLatticeExist(beforeLat, 0);//将原格子放空
	chess->setTempPosition();
	if (arrayFrom != arrayTo)//两者不一样则需要调整
	{
		ccArrayRemoveObject(arrayFrom, chess);
		ccArrayAppendObject(arrayTo, chess);
	}
}