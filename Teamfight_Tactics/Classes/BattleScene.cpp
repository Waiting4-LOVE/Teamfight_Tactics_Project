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

	/***********������Layer************/
	this->addChild(map, 0);        //��ͼ��
	this->addChild(littleLayer, 1); //СӢ�۲�
	this->addChild(timer, 2);        //��ʱ����
    this->addChild(heroLayer, 3);   //Ӣ�۲�


    heroLayer->scheduleUpdate();
	// ����һ������¼�������
	auto mouseListener = EventListenerMouse::create();

	// ������갴���¼�����

	// ��Ӽ��������¼��ַ���
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

    if (littlehero.haveNewHero)                  //���������Ӽ���
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
                    littlehero.heronumber[temp->getType()]++;     //��¼������������Ϣ
                    ChessExist[i][0 + 9 * playerinfo] = 1;        //��ӳɹ�
                    flag = 0;
                    littlehero.haveNewHero = 0;        //��ֹĪ�������BUG
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
            littlehero.haveNewHero = 0;        //��ֹĪ�������BUG
            flag = 0;
            littlehero.haveNewHero = 0;        //��ֹĪ�������BUG
            flag = 0;
        }
        if (flag)
        {
            ccArrayRemoveObject(littlehero.m_playerArray, temp);   //���ʧ��
            littlehero.haveNewHero = 0;

        }
    }
}*/




void BattleScene::update(float dt)
{
	if (timer->pTime > 1e-6)
	{
		/*gamesprite->upgrade(player1data);             //����Ƿ������
		gamesprite->upgrade(player2data);
		addChess(player1data, 0);
		addChess(player2data, 1);
		pc_player.pcJudgeMoneyUsage();*/
	}
    heroLayer->scheduleUpdate();
	/*addChess(player1data, 0);
	addChess(player2data, 1);*/

	//ChessMoveInMouse();
	/*if (timer->pTime < -1e-2)
	{
		if (PC_ShowFlag)
		{
			pc_player.pcCreateBattleArray();
			pc_player.pcEquip();
			gamesprite->pcShowFightArray();  //��ʾ���������Ϣ
			gamesprite->pcShowPlayerArray();
			if (player2data.PlayerArray->num == 8)
				SoldChess(pc_player.pcSoldChess(), player2data.PlayerArray, player2data);   //����������
			PC_ShowFlag = 0;
		}
		GameStartMouseInit();   //ȡ����ս�������ӵ�ѡȡ
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
		if (timer->pTime < 0.25f && MouseToChess < MyLittleHero.m_fightArray->num)//ս��ʱ�����ƶ�ս��������
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(temp->getTempPosition());
			temp->set(temp->getTempPosition());
			MouseToChess = -1;
			return;
		}
		else         //С��FightNumberΪս����������FightNumberΪ��ս��
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(e->getCursorX(), e->getCursorY());
			temp->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
		}
	}
	//��ly��zyhд��
}

void BattleScene::onMouseUp(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
	{
		//ȡ��װ��ѡȡ
		/*
		if (MouseSelectedEquip != -1)
		{
			if (EquipSearchChess(e->getCursorX(), e->getCursorY(), MouseSelectedEquip))//װ������������������
			{
				player1data.occupied_slot--;
			}
			else  //����ʧ�ܣ�����ԭ��λ��
			{
				((Equipment*)(player1data.UnequipedEquipment->arr[MouseSelectedEquip]))->setPosition(player1data.slotPoint[MouseSelectedEquip]);
			}
			MouseSelectedEquip = -1;
		}*/

		if (MouseToChess >= 0 && MouseToChess < MyLittleHero.m_fightArray->num)
		{
			auto temp = ((hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]));
			if (judgeExist(positionToLattice(temp->getPosition()))) //�ܾ��غ�
			{
				temp->setPosition(temp->getTempPosition());
				temp->set(temp->getTempPosition());
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first == 0)   //ս�����Ƶ���սϯ
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.25)  //ս�����Ƶ�ս���� 
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_playerArray);
				}
				else//��ͼ������
				{
					temp->setPosition(temp->getTempPosition());
					temp->set(temp->getTempPosition());
				}
			}
		}
		else if (MouseToChess >= MyLittleHero.m_fightArray->num)
		{
			auto temp = ((hero*)(MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]));
			if (judgeExist(positionToLattice(temp->getPosition()))) //�ܾ��غ�
			{
				temp->setPosition(temp->getTempPosition());
				temp->set(temp->getTempPosition());
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first == 0)   //��սϯ�Ƶ���սϯ
				{
					ArrayToArray(temp, MyLittleHero.m_playerArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.25f)   //��սϯ�Ƶ�ս����
				{
					if (MyLittleHero.m_fightArray->num < MyLittleHero.getLevel())
					{
						ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
					}
					else
					{
						temp->setPosition(temp->getTempPosition());
						temp->set(temp->getTempPosition());
						auto label = Label::createWithTTF("ս������������", "fonts/Marker Felt.ttf", 36);
						this->addChild(label);
						label->setTextColor(Color4B::WHITE);
						label->setPosition(800, 400);
						auto fadeout = FadeOut::create(2.0f);
						label->runAction(fadeout);
					}
				}
				else                            //�������ɿ����
				{
					temp->setPosition(temp->getTempPosition());
					temp->set(temp->getTempPosition());
				}
			}
		}
		MouseToChess = -1;                   //ȡ��ѡȡ

	}
}

void BattleScene::onMouseDown(Event* event)
{
	EventMouse* e = (EventMouse*)event;

	/*ѡ�ж���ı�־*/
	int Obj_is_Selected = 0;

	/*װ��ѡȡ*/
   /*if (!Obj_is_Selected && timer->pTime > 1e-6)
	{
		for (int i = 0; i < player1data.UnequipedEquipment->num; i++)
		{
			float dx = (e->getCursorX() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().x);
			float dy = (e->getCursorY() - ((Equipment*)(player1data.UnequipedEquipment->arr[i]))->getPosition().y);
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < 20)
			{
				MouseSelectedEquip = i;  //ȷ��ѡ�е�װ��
				Obj_is_Selected = 1;
			}
		}
	}*/

	if (!Obj_is_Selected)
	{
		if (FindMouseTarget(MyLittleHero.m_fightArray, e))       //��ս����Ѱ��Ŀ��
			FindMouseTarget(MyLittleHero.m_playerArray, e);  //Ѱ�Ҳ������ڱ�ս��Ѱ��
	}
}

bool BattleScene::FindMouseTarget(ccArray* Array, EventMouse* e)
{
	int temp = 0;
	if (Array == MyLittleHero.m_playerArray)
	{
		temp = MyLittleHero.m_fightArray->num;
	}
	if (timer->pTime > 0.25 || temp == 0)//��ս���ڼ�����ƶ���սϯʱ���ƶ�
	{
		Vec2 mousePos(e->getCursorX(), e->getCursorY());
		for (int i = 0; i < Array->num; i++)
		{
			auto tempHero = (hero*)(Array->arr[i]);
			if (tempHero->getPosition().distance(mousePos) < 50)//������С��50����Ϊѡȡ�˸�Ӣ��
			{
				if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)//���
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

void BattleScene::soldHero(hero* temp, ccArray* Array, littleHero& playerdata)//����
{
	setLatticeExist(positionToLattice(temp->getPosition()), 0);//���ڸ��ӷſ�
	playerdata.addCoins(temp->getSoldCoins());
	//ccArrayAppendArray(playerdata.UnequipedEquipment, temp->equipment);//���µ�װ��
	temp->retain();
	heroLayer->removeChild(temp);       //����
	ccArrayRemoveObject(Array, temp);

}

void BattleScene::ArrayToArray(hero* chess, ccArray* arrayFrom, ccArray* arrayTo)//��սϯ/ս���� From to To�ĸı�
{
	pair<int, int>lat = positionToLattice(chess->getPosition());//���ڸ���
	pair<int, int>beforeLat = positionToLattice(chess->getTempPosition());//ԭ����
	chess->setPosition(latticeToPosition(lat));//�ŵ������λ����
	chess->set(latticeToPosition(beforeLat));
	setLatticeExist(lat, 1);//������ڸ���
	setLatticeExist(beforeLat, 0);//��ԭ���ӷſ�
	chess->setTempPosition();
	if (arrayFrom != arrayTo)//���߲�һ������Ҫ����
	{
		ccArrayRemoveObject(arrayTo, chess);
		ccArrayAppendObject(arrayFrom, chess);
	}
}