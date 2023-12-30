#include "SelecScene.h"
#include "BattleScene.h"
#include "Sources.h"
#include "Definition.h"
USING_NS_CC;

PC_Player pc_player;
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
	//��Ϣ���ʼ��
	infoFrame->setAnchorPoint(Vec2(0, 0.5));
	infoFrame->setScale(1.5);
	infoFrame->setPosition(10000, 10000);
	infoFrame->addChild(heroInfo, 1);
	heroInfo->setPosition(82, -7);
	heroInfo->setColor(Color3B::WHITE);
	heroInfo->setAnchorPoint(Vec2(0, 0));

	/***********������Layer************/
	this->addChild(map, 0);        //��ͼ��
	this->addChild(HSlayer, 1);   //���ذ�ť
	this->addChild(littleLayer, 1); //СӢ�۲�
	this->addChild(timer, 2);        //��ʱ����
	this->addChild(shopLayer, 3);   //�̵��
	this->addChild(heroLayer, 4);   //Ӣ�۲�
	this->addChild(infoFrame, 100);//��Ϣ��


	/**********��ʱ����Update**************/
	this->scheduleUpdate();
	littleLayer->scheduleUpdate();
	shopLayer->scheduleUpdate();
	heroLayer->scheduleUpdate();

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

void BattleScene::GotoSelectScene(cocos2d::Ref* pSender)
{
	auto scene = SelectScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}*/

void BattleScene::update(float dt)
{
	if (timer->pTime > 1e-6)
	{
		heroLayer->upgrade(MyLittleHero);             //����Ƿ������
		heroLayer->upgrade(player2data);
		addChess(MyLittleHero, 0);
		addChess(player2data, 1);
		pc_player.pcJudgeMoneyUsage();
	}
	heroLayer->scheduleUpdate();

	addChess(MyLittleHero, 0);
	addChess(player2data, 1);

	ChessMoveInMouse();
	if (timer->pTime < -1e-2)
	{
		if (PC_ShowFlag)
		{
			pc_player.pcCreateBattleArray();
			//pc_player.pcEquipment();
			heroLayer->pcShowFightArray();  //��ʾ���������Ϣ
			heroLayer->pcShowPlayerArray();
			if (player2data.m_playerArray->num == 9)
				soldHero(pc_player.pcSoldHero(), player2data.m_playerArray, player2data);   //����������
			PC_ShowFlag = 0;
		}
		GameStartMouseInit();   //ȡ����ս�������ӵ�ѡȡ
		timer->setPosition(10000, 10000);
		heroLayer->scheduleUpdate();
		Win();
	}

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
	CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
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

void BattleScene::showInfo(hero* chess)//��ʾӢ����Ϣ
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

void BattleScene::hideInfo()//����Ӣ����Ϣ
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
		if (timer->pTime < 0.01f && MouseToChess < MyLittleHero.m_fightArray->num)//ս��ʱ�����ƶ�ս��������
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(temp->getTempPosition());
			temp->set(temp->getTempPosition());
			MouseToChess = -1;
			return;
		}
		else         //С��FightNumberΪս����������FightNumberΪ��ս��
		{
			if (MouseToChess >= MyLittleHero.m_fightArray->num)
			{
				auto temp = (hero*)(MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]);
				temp->setPosition(e->getCursorX(), e->getCursorY());
				temp->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
			}
			else if (MouseToChess >= 0)
			{
				auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
				temp->setPosition(e->getCursorX(), e->getCursorY());
				temp->set(e->getCursorX(), e->getCursorY());  //�ƶ�֮
			}
		}
	}
	//��ly��zyhд��
}

void BattleScene::onMouseUp(Event* event)
{
	//CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
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
				if (lat.first > 0 && timer->pTime > 0.01f)   //ս�����Ƶ�ս���� 
				{
					ArrayToArray(temp, MyLittleHero.m_fightArray, MyLittleHero.m_fightArray);
				}
				else if (lat.first == 0 && timer->pTime > 0.01f)  //ս�����Ƶ���սϯ
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
				//CCLOG("�غ���");
			}
			else
			{
				pair<int, int>lat = positionToLattice(temp->getPosition());
				if (lat.first == 0)   //��սϯ�Ƶ���սϯ
				{
					ArrayToArray(temp, MyLittleHero.m_playerArray, MyLittleHero.m_playerArray);
				}
				else if (lat.first > 0 && timer->pTime > 0.01f)   //��սϯ�Ƶ�ս����
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
				else                            //�������ɿ����
				{
					temp->setPosition(temp->getTempPosition());
					temp->set(temp->getTempPosition());
				}
			}
		}
		MouseToChess = -1;                   //ȡ��ѡȡ

	}
	//CCLOG("%d %d %d", MyLittleHero.getLevel(), MyLittleHero.m_fightArray->num, MyLittleHero.m_playerArray->num);
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
	if (MouseToChess >= 0 && !infoIsShow)
	{
		if (MouseToChess >= MyLittleHero.m_fightArray->num)
		{
			showInfo((hero*)MyLittleHero.m_playerArray->arr[MouseToChess - MyLittleHero.m_fightArray->num]);
		}
		else
		{
			showInfo((hero*)MyLittleHero.m_fightArray->arr[MouseToChess]);
		}
		infoIsShow = 1;
	}
	else if (MouseToChess < 0 && infoIsShow)
	{
		hideInfo();
		infoIsShow = 0;
	}
}

bool BattleScene::FindMouseTarget(ccArray* Array, EventMouse* e)
{
	int temp = 0;
	if (Array == MyLittleHero.m_playerArray)
	{
		temp = MyLittleHero.m_fightArray->num;
	}
	if (timer->pTime > 0.01f || temp == 0)//��ս���ڼ�����ƶ���սϯʱ���ƶ�
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

void BattleScene::GameStartMouseInit()
{
	if (timer->pTime < 1e-2 && timer->pTime > -1e-2)
	{
		if (MouseToChess < MyLittleHero.m_fightArray->num && MouseToChess != -1)
		{
			auto temp = (hero*)(MyLittleHero.m_fightArray->arr[MouseToChess]);
			temp->setPosition(temp->getTempPosition());
			temp->set(temp->getTempPosition());
			MouseToChess = -1;
		}
	}
}

void BattleScene::addChess(littleHero& littlehero, int playerinfo)
{
	if (littlehero.haveNewHero)                  //���������Ӽ���
	{
		bool flag = 1;
		auto temp = (hero*)(littlehero.m_playerArray->arr[littlehero.m_playerArray->num - 1]);
		if (playerinfo == 0)
		{
			for (int i = 0; i < 9; i++)
			{

				if (waitLatticeExist[0 + playerinfo][i] == 0)//����ս���п�λ
				{
					littlehero.delCoins(temp->getCoinsNeeded());
					temp->set(waitLattice[0 + playerinfo][i]);
					temp->setTempPosition();
					temp->setPosition(temp->getTempPosition());
					heroLayer->addChild(temp);
					temp->retain();
					littlehero.haveNewHero = 0;
					temp->setPlayer(playerinfo);
					littlehero.chessnumber[temp->getType()]++;     //��¼������������Ϣ
					setLatticeExist({ 0 + playerinfo,i }, 1);//����ռλ
					flag = 0;
					littlehero.haveNewHero = 0;
					flag = 0;
					break;

				}
			}
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{

				if (waitLatticeExist[0 + playerinfo][i] == 0)//����ս���п�λ
				{
					littlehero.delCoins(temp->getCoinsNeeded());
					temp->set(waitLattice[0 + playerinfo][i]);
					temp->setTempPosition();
					temp->setPosition(temp->getTempPosition());
					heroLayer->addChild(temp);
					temp->retain();
					littlehero.haveNewHero = 0;
					temp->setPlayer(playerinfo);
					littlehero.chessnumber[temp->getType()]++;     //��¼������������Ϣ
					waitLatticeExist[0 + playerinfo][i] = 1;//����ռλ
					flag = 0;
					littlehero.haveNewHero = 0;
					flag = 0;
					break;

				}
			}
		}
		if (flag)
		{
			ccArrayRemoveObject(littlehero.m_playerArray, temp);   //���ʧ��
			littlehero.haveNewHero = 0;

		}
	}
}

void BattleScene::Win()
{
	int sum[2] = { 0,0 };
	JudgeWin(MyLittleHero, sum);
	JudgeWin(player2data, sum);
	if (sum[0] == 0 || sum[1] == 0)
	{
		if (sum[1] == 0)//��Ӯ
		{

			MyLittleHero.win();
			player2data.lose(2 + 2 * sum[0]);
		}

		else if (sum[0] == 0)//����
		{
			player2data.win();
			MyLittleHero.lose(2 + 2 * sum[1]);
		}

		WinRetain(MyLittleHero.m_playerArray);
		WinRetain(player2data.m_playerArray);
		WinRetain(MyLittleHero.m_fightArray);
		WinRetain(player2data.m_fightArray);

		heroLayer->unscheduleUpdate();

		//װ�����Ƴ�(δʵ��)

		if (MyLittleHero.getCurBlood() > 0 && player2data.getCurBlood() > 0)
		{
			auto newScene = BattleScene::createScene();
			Director::getInstance()->pushScene(newScene);
		}

		else
		{
			string name = MyLittleHero.getCurBlood() <= 0 ? "You Lose!" : "You Win!";
			auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 78);
			label->setTextColor(Color4B::WHITE);
			label->setPosition(800, 400);
			auto move = FadeOut::create(5.0f);
			label->runAction(move);
			this->addChild(label);
			this->unscheduleUpdate();
			MyLittleHero.reset();
			player2data.reset();
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					battleLatticeExist[i][j] = 0;
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					waitLatticeExist[i][j] = 0;
				}
			}
			_director->replaceScene(TransitionFade::create(1 / 8.0f, SelectScene::createScene()));
		}

	}

}

void BattleScene::JudgeWin(littleHero& littlehero, int sum[])
{
	for (int i = 0; i < littlehero.m_fightArray->num; i++)
	{
		auto temp = (hero*)(littlehero.m_fightArray->arr[i]);
		if (!temp->die())
		{
			sum[temp->getPlayer()]++;
		}
	}
}

void BattleScene::WinRetain(ccArray* Array)
{
	for (int i = 0; i < Array->num; i++)
	{
		auto temp = ((hero*)Array->arr[i]);

		temp->retain();                    //����
		temp->removeFromParent();          //���´���������Ƚ���remove
		temp->reset();                  //�ָ�ԭ��
	}
}

void BattleScene::ArrayToArray(hero* chess, ccArray* arrayFrom, ccArray* arrayTo)//��սϯ/ս���� From to To�ĸı�
{
	pair<int, int>lat = positionToLattice(chess->getPosition());//���ڸ���
	pair<int, int>beforeLat = positionToLattice(chess->getTempPosition());//ԭ����
	chess->setPosition(latticeToPosition(lat));//�ŵ������λ����
	chess->set(latticeToPosition(lat));
	setLatticeExist(lat, 1);//������ڸ���
	setLatticeExist(beforeLat, 0);//��ԭ���ӷſ�
	chess->setTempPosition();
	if (arrayFrom != arrayTo)//���߲�һ������Ҫ����
	{
		ccArrayRemoveObject(arrayFrom, chess);
		ccArrayAppendObject(arrayTo, chess);
	}
}