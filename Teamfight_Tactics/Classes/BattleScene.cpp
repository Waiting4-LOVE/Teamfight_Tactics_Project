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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/***********所需子Layer************/
	this->addChild(map, 0);        //地图层
	this->addChild(littleLayer, 1); //小英雄层
	this->addChild(timer, 2);        //计时器层
	this->addChild(heroLayer, 3);   //英雄层
	// 创建一个鼠标事件监听器
	auto mouseListener = EventListenerMouse::create();

	// 设置鼠标按下事件处理

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

	/*addChess(player1data, 0);
	addChess(player2data, 1);*/

	//ChessMoveInMouse();
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
	auto turn_label = Label::createWithTTF("TURN", "fonts/Marker Felt.ttf", 24);
	turn_label->setPosition(200, 800);
	this->addChild(turn_label, 2);
	char* mTurn = new char[8];
	sprintf(mTurn, "Turn %02d", global_data->game_turn);
	turn_label->setString(mTurn);

}

void BattleScene::ChessMoveInMouse()
{
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
		if (timer->pTime < 0.25f && MouseToChess < MyLittleHero.m_fightArray->num)//战斗时不能移动战斗区棋子
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(temp->getTempPosition());
			temp->set(temp->getTempPosition());
			MouseToChess = -1;
			return;
		}
		else         //小于FightNumber为战斗区，大于FightNumber为备战区
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(e->getCursorX(), e->getCursorY());
			temp->set(e->getCursorX(), e->getCursorY());  //移动之
		}
	}
	//等ly、zyh写完
}

void BattleScene::onMouseUp(Event* event)
{
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
				if (lat.first == 0)   //战斗区移到备战席
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.25)  //战斗区移到战斗区 
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
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first == 0)   //备战席移到备战席
				{
					ArrayToArray(temp, MyLittleHero.m_playerArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.25f)   //备战席移到战斗区
				{
					if (MyLittleHero.m_fightArray->num < MyLittleHero.getLevel())
					{
						ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
					}
					else
					{
						temp->setPosition(temp->getTempPosition());
						temp->set(temp->getTempPosition());
						auto label = Label::createWithTTF("战斗区人数已满", "fonts/Marker Felt.ttf", 36);
						this->addChild(label);
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
}

bool BattleScene::FindMouseTarget(ccArray* Array, EventMouse* e)
{
	int temp = 0;
	if (Array == MyLittleHero.m_playerArray)
	{
		temp = MyLittleHero.m_fightArray->num;
	}
	if (timer->pTime > 0.25 || temp == 0)//非战斗期间或者移动备战席时可移动
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

void BattleScene::ArrayToArray(hero* chess, ccArray* arrayFrom, ccArray* arrayTo)//备战席/战斗区 From to To的改变
{
	pair<int, int>lat = positionToLattice(chess->getPosition());//现在格子
	pair<int, int>beforeLat = positionToLattice(chess->getTempPosition());//原格子
	chess->setPosition(latticeToPosition(lat));//放到最近的位置上
	chess->set(latticeToPosition(beforeLat));
	setLatticeExist(lat, 1);//填充现在格子
	setLatticeExist(beforeLat, 0);//将原格子放空
	chess->setTempPosition();
	if (arrayFrom != arrayTo)//两者不一样则需要调整
	{
		ccArrayRemoveObject(arrayTo, chess);
		ccArrayAppendObject(arrayFrom, chess);
	}
}