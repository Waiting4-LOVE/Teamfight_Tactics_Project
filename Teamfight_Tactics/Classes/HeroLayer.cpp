#include"HeroLayer.h"
hero* CreateHero(int type) {
	switch (type)
	{
	case hero1://
		return hero1::createhero();
		break;
	default:
		break;
	}

}

HeroLayer* HeroLayer::createHeroLayer() {
	auto temp = HeroLayer::create();
	temp->retain();
	return temp;
}
void HeroLayer::PlayerArrayInit(ccArray* Array, int playerinfo) {
	for (int i = 0; i < Array->num; i++) {
		auto temp = ((hero*)Array->arr[i]);
		temp->setPosition(temp->getTempPosition());
		temp->set(temp->getTempPosition());

		auto temp1 = CreateHero(temp->getType());
		if (playerinfo == 0)
		{
			temp1->setPosition(temp->getTempPosition());
			temp1->set(temp->getTempPosition());
			*(temp1->equipment) = *(temp->equipment);
			temp1->setTempPosition();
		}
		else
		{
			temp1->setPosition(temp->getTempPosition());
			temp1->set(temp->getTempPosition());
			temp1->setTempPosition();
			temp1->setPosition(10000, 10000);
			temp1->set(10000, 10000);
		}
		temp1->setPlayer(temp->getPlayer());
		temp1->EquipmentChange();
		if (ccArrayContainsObject(Array, temp))
			ccArrayRemoveObject(Array, temp);
		ccArrayInsertObjectAtIndex(Array, temp1, i);
		this->addChild(temp1);
		ChessExist[MapIntReturn(temp->getTempPosition()).x][MapIntReturn(temp->getTempPosition()).y] = 1;
	}
}

bool HeroLayer::init() {
	PlayerArrayInit(MyLittleHero.m_playerArray, 0);
	PlayerArrayInit(player2data.m_playerArray, 1);      //  ���������Ϣ�ݲ���ʾ
	PlayerArrayInit(MyLittleHero.m_fightArray, 0);
	PlayerArrayInit(player2data.m_fightArray, 1);
	return true;
}

/*
void HeroLayer::ChessMove(hero* herocase, littleHero& playerdata, littleHero& AttackPlayer)
{
	Point a(0, 0);
	Point chessPosition = herocase->getPosition();
	float distance = 9999999;



	for (int i = 0; i < AttackPlayer.m_fightArray->num; i++)
	{
		auto temp = AttackPlayer.m_fightArray->arr[i];
		Point atemp = ((hero*)temp)->getPosition();
		float distanceTemp = sqrt((atemp.x - chessPosition.x) * (atemp.x - chessPosition.x) +
			(atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //�����
		if (distanceTemp < distance && distanceTemp>0 && !((hero*)temp)->die()) //ȷ������Ŀ��
		{
			distance = distanceTemp;
			a = atemp;
			herocase->attackTarget = (hero*)temp;
		}
	}

	if (herocase->attackTarget != (hero*)nullptr)
	{
		distance = CountDistance(herocase, herocase->attackTarget);
	}
	//�ƶ�����1e-2Ϊ��λ�ƶ�

	else if (herocase->attackTarget == (hero*)nullptr)  //�޹���Ŀ�������
	{
		return;
	}
	if (distance >= herocase->getAttackDistance() * oneLattice && !herocase->attackTarget->die())    //������������Ŀ��û�����ƶ�
	{
		herocase->setPosition(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);
		herocase->set(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);  //����λ�ô�������
	}
	//�����ƶ�
}
*/

void HeroLayer::update(float dt)
{
	for (int i = 0; i < MyLittleHero.m_fightArray->num; i++)
	{
		((hero*)(MyLittleHero.m_fightArray->arr[i]))->die();
		//ChessMove((hero*)(MyLittleHero.m_fightArray->arr[i]), MyLittleHero, player2data);
	}
	for (int i = 0; i < player2data.m_fightArray->num; i++)
	{
		((hero*)(player2data.m_fightArray->arr[i]))->die();
		//ChessMove((hero*)(player2data.m_fightArray->arr[i]), player2data, MyLittleHero);
	}
}

void HeroLayer::upgrade(littleHero& littlehero)
{

	for (int i = 0; i < 16; i++)
	{
		hero* temp[3] = { NULL,NULL,NULL };
		ccArray* tempArray[3] = {};
		int s = 0;  //��������������
		if (littlehero.heronumber[i] >= 3 && i < 16)
		{
			for (int j = 0; j < littlehero.m_playerArray->num; j++)
			{
				if (((hero*)(littlehero.m_playerArray->arr[j]))->getType() == i)
				{
					if (s < 3)
					{
						temp[s] = ((hero*)(littlehero.m_playerArray->arr[j]));
						tempArray[s] = littlehero.m_playerArray;
						s++;
					}
					if (s == 3)
						break;

				}
			}
			if (s < 3)   //���ڱ�ս��ûѰ�������������ս������
			{
				for (int j = 0; j < littlehero.m_fightArray->num; j++)
				{
					if (((hero*)(littlehero.m_fightArray->arr[j]))->getType() == i)
					{
						if (s < 3)
						{
							temp[s] = ((hero*)(littlehero.m_fightArray->arr[j]));
							tempArray[s] = littlehero.m_fightArray;
							s++;
						}
						if (s == 3)
							break;

					}
				}
			}
			if (temp[0] != nullptr && temp[1] != nullptr && temp[2] != nullptr && s == 3
				&& temp[0]->getType() == i && temp[1]->getType() == i && temp[2]->getType() == i)  //��ֹBug
			{
				auto upgrade_chess = upgradeChessCreate(i);

				littlehero.heronumber[i] -= 3;
				for (int k = 0; k < 3; k++)
				{
					ccArrayAppendArray(upgrade_chess->equipment, temp[k]->equipment);
					ChessExist[MapIntReturn(temp[k]->getTempPosition()).x][MapIntReturn(temp[k]->getTempPosition()).y] = 0;
					temp[k]->retain();          //��retain��release���޷�����
					temp[k]->removeFromParent();
					if (ccArrayContainsObject(tempArray[k], temp[k]))
					{
						ccArrayRemoveObject(tempArray[k], temp[k]);    //_referanceCount>0 ������retain��ò�ƽ����
						// temp[i]->autorelease();
					}
				}
				upgrade_chess->EquipmentChange();
				ccArrayAppendObject(littlehero.m_playerArray, upgrade_chess);
				littlehero.haveNewHero = 1;
				return;
			}
		}

	}
}

hero* HeroLayer::upgradeChessCreate(int type)
{
	switch (type + 15)
	{
		//����������Ӣ��
	default:
		break;
	}

}


/*PC_Player���*/
void HeroLayer::pcShowPlayerArray()
{
	for (int i = 0; i < player2data.m_playerArray->num; i++)
	{
		((hero*)player2data.m_playerArray->arr[i])->setPosition(mapPosition[i][9].x, mapPosition[i][9].y);
		((hero*)player2data.m_playerArray->arr[i])->set(mapPosition[i][9].x, mapPosition[i][9].y);
	}
}
void HeroLayer::pcShowFightArray()
{
	/*λ�ó�ʼ��*/
	for (int i = 0; i < player2data.m_fightArray->num; i++)
	{
		if (i >= 0 && i <= 7)
		{
			((hero*)player2data.m_fightArray->arr[i])->setPosition(mapPosition[i][5].x, mapPosition[i][5].y);
			((hero*)player2data.m_fightArray->arr[i])->set(mapPosition[i][5].x, mapPosition[i][5].y);
			ChessExist[i][5] = 1;
		}
		else if (i >= 8 && i <= 15)
		{
			((hero*)player2data.m_fightArray->arr[i])->setPosition(mapPosition[i - 8][6].x, mapPosition[i - 8][6].y);
			((hero*)player2data.m_fightArray->arr[i])->set(mapPosition[i - 8][6].x, mapPosition[i - 8][6].y);
			ChessExist[i][6] = 1;
		}
		else if (i >= 16 && i <= 23)
		{
			((hero*)player2data.m_fightArray->arr[i])->setPosition(mapPosition[i - 16][7].x, mapPosition[i - 16][7].y);
			((hero*)player2data.m_fightArray->arr[i])->set(mapPosition[i - 16][7].x, mapPosition[i - 16][7].y);
			ChessExist[i][7] = 1;
		}
		else if (i >= 24 && i <= 31)
		{
			((hero*)player2data.m_fightArray->arr[i])->setPosition(mapPosition[i - 24][8].x, mapPosition[i - 24][8].y);
			((hero*)player2data.m_fightArray->arr[i])->set(mapPosition[i - 24][8].x, mapPosition[i - 24][8].y);
			ChessExist[i][8] = 1;
		}
	}

}


float HeroLayer::CountDistance(hero* c1, hero* c2)
{
	return sqrt(pow((c1->getPosition().x - c2->getPosition().x), 2)
		+ pow((c1->getPosition().y - c2->getPosition().y), 2));
}
float HeroLayer::CountDistance(Point p1, Point p2)
{
	return sqrt(pow((p1.x - p2.x), 2)
		+ pow((p1.y - p2.y), 2));
}

