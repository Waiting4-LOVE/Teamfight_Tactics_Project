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
    this->addChild(hsLayer, 4);
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
    // to illustrate the event....
   /* EventMouse* e = (EventMouse*)event;
    if (MouseSelectedEquip != -1 && timer->pTime > 1e-6)
    {
        ((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(e->getCursorX(), e->getCursorY());
    }
    if (MouseToChess != -1)
    {
        if (timer->pTime < 1e-2 && MouseToChess < FightNumber)
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            temp->setPosition(MapJudge(temp->getTempPosition()));
            temp->set(MapJudge(temp->getTempPosition()));
            MouseToChess = -1;
            return;
        }
        else if (MouseToChess < FightNumber)             //小于FightNumber为战斗区，大于FightNumber为备战区
        {
            auto temp = (Chess*)(player1data.FightArray->arr[MouseToChess]);
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //移动之
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                        //回到原位，取消选取
            }
        }
        else if (MouseToChess >= FightNumber)
        {
            auto temp = (Chess*)(player1data.PlayerArray->arr[MouseToChess - FightNumber]);
            auto point = MapJudge(temp->getPosition());
            if (point != Point(-1, -1) && point.y <= mapPosition[0][4].y + 37.5)
            {
                temp->setPosition(e->getCursorX(), e->getCursorY());
                temp->set(e->getCursorX(), e->getCursorY());  //移动之
            }
            else
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
                MouseToChess = -1;                           //回到原位，取消选取
            }
        }
    }*/
    //等ly、zyh写完
}

void BattleScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    /*EventMouse* e = (EventMouse*)event;
    if ((int)e->getMouseButton() == 0)
    {
        //取消装备选取
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
        }
    }
    if ((int)e->getMouseButton() == 0)
    {

        if (MouseToChess >= 0 && MouseToChess < FightNumber)
        {
            auto temp = ((Chess*)(player1data.FightArray->arr[MouseToChess]));
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //拒绝重合
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));

            }
            else if (MapIntReturn(temp->getPosition()).y != 0 && MapIntReturn(temp->getPosition()).y != 9)   //若不在备战席
            {

                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));
                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
                temp->setTempPosition();
            }
            else    //若在备战席，则将其放入
            {
                ToPlayerArray(temp, player1data);
            }
        }
        else if (MouseToChess >= FightNumber)
        {
            auto temp = ((Chess*)(player1data.PlayerArray->arr[MouseToChess - FightNumber]));
            if (ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] == 1)   //拒绝重合
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
            else if (MapIntReturn(temp->getPosition()).y == 0 || MapIntReturn(temp->getPosition()).y == 9)  //若在备战席
            {
                Point temppoint = MapJudge(temp->getPosition());
                temp->setPosition(MapJudge(temp->getPosition()));
                temp->set(MapJudge(temp->getPosition()));

                ChessExist[MapIntReturn(temp->getPosition()).x][MapIntReturn(temp->getPosition()).y] = 1;
                ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 0;
                temp->setTempPosition();
            }
            else if (test_timer->pTime > 1e-6)       //若进入战斗区
            {
                if (player1data.FightArray->num < player1data.Grade)
                    ToFightArray(temp, player1data);
                else
                {
                    temp->setPosition(MapJudge(temp->getTempPosition()));
                    temp->set(MapJudge(temp->getTempPosition()));
                    auto label = Label::createWithTTF("Not enough Grade!", "fonts/Marker Felt.ttf", 36);
                    this->addChild(label);
                    label->setTextColor(Color4B::WHITE);
                    label->setPosition(800, 400);
                    auto move = FadeOut::create(2.0f);
                    label->runAction(move);
                    MouseToChess = -1;
                }
            }
            else                            //其他不可控情况
            {
                temp->setPosition(MapJudge(temp->getTempPosition()));
                temp->set(MapJudge(temp->getTempPosition()));
            }
        }
        MouseToChess = -1;                   //取消选取

    }*/
    //等ly、zyh写完
}

void BattleScene::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;

    /*选中对象的标志*/
    int Obj_is_Selected = 0;

    /*装备选取*/
   /* if (!Obj_is_Selected && timer->pTime > 1e-6)
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
    }

    if (!Obj_is_Selected)
    {
        if (FindMouseTarget(player1data.FightArray, e) == 1)       //在战斗区寻找目标
            FindMouseTarget(player1data.PlayerArray, e);  //寻找不到则在备战区寻找
    }*/
}

