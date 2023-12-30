#include"HeroLayer.h"

littleHero MyLittleHero;
littleHero player2data;

hero* CreateHero(int type) {
	switch (type)
	{
	case DarkKnight:
		return darkKnight::createhero();
		break;
	case Master:
		return master::createhero();
		break;
	case CannedPig:
		return cannedPig::createhero();
		break;
	case FlyDragon:
		return flyDragon::createhero();
		break;
	case Ghost:
		return ghost::createhero();
		break;
	case Gargomon:
		return gargomon::createhero();
		break;
	case GoldenMonster:
		return goldenMonster::createhero();
		break;
	case IceFire:
		return iceFire::createhero();
		break;
	case Knight:
		return knight::createhero();
		break;
	case Pitman:
		return pitman::createhero();
		break;
	case Ranger:
		return ranger::createhero();
		break;
	case Snowman:
		return snowman::createhero();
		break;
	case Elf:
		return elf::createhero();
		break;
	case WildBoar:
		return wildBoar::createhero();
		break;
	case SnowMonster:
		return snowMonster::createhero();
		break;
	case _2star_DarkKnight:
		return darkKnight::createhero();
		break;
	case _2star_Master:
		return master::createhero();
		break;
	case _2star_CannedPig:
		return cannedPig::createhero();
		break;
	case _2star_FlyDragon:
		return flyDragon::createhero();
		break;
	case _2star_Ghost:
		return ghost::createhero();
		break;
	case _2star_Gargomon:
		return gargomon::createhero();
		break;
	case _2star_GoldenMonster:
		return goldenMonster::createhero();
		break;
	case _2star_IceFire:
		return iceFire::createhero();
		break;
	case _2star_Knight:
		return knight::createhero();
		break;
	case _2star_Pitman:
		return pitman::createhero();
		break;
	case _2star_Ranger:
		return ranger::createhero();
		break;
	case _2star_Snowman:
		return snowman::createhero();
		break;
	case _2star_Elf:
		return elf::createhero();
		break;
	case _2star_WildBoar:
		return wildBoar::createhero();
		break;
	case _2star_SnowMonster:
		return snowMonster::createhero();
		break;
	case _3star_DarkKnight:
		return darkKnight::createhero();
		break;
	case _3star_Master:
		return master::createhero();
		break;
	case _3star_CannedPig:
		return cannedPig::createhero();
		break;
	case _3star_FlyDragon:
		return flyDragon::createhero();
		break;
	case _3star_Ghost:
		return ghost::createhero();
		break;
	case _3star_Gargomon:
		return gargomon::createhero();
		break;
	case _3star_GoldenMonster:
		return goldenMonster::createhero();
		break;
	case _3star_IceFire:
		return iceFire::createhero();
		break;
	case _3star_Knight:
		return knight::createhero();
		break;
	case _3star_Pitman:
		return pitman::createhero();
		break;
	case _3star_Ranger:
		return ranger::createhero();
		break;
	case _3star_Snowman:
		return snowman::createhero();
		break;
	case _3star_Elf:
		return elf::createhero();
		break;
	case _3star_WildBoar:
		return wildBoar::createhero();
		break;
	case _3star_SnowMonster:
		return snowMonster::createhero();
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
			/*temp1->setPosition(10000, 10000);
			temp1->set(10000, 10000*/
		}
		temp1->setPlayer(temp->getPlayer());
		//temp1->EquipmentChange();
		if (ccArrayContainsObject(Array, temp))
			ccArrayRemoveObject(Array, temp);
		ccArrayInsertObjectAtIndex(Array, temp1, i);
		this->addChild(temp1);
		auto lat = positionToLattice(temp->getPosition());
		setLatticeExist(lat, 1);//����ռλ
	}
}

bool HeroLayer::init() {
	
	PlayerArrayInit(MyLittleHero.m_playerArray, 0);
	PlayerArrayInit(player2data.m_playerArray, 1);      //  ���������Ϣ�ݲ���ʾ
	PlayerArrayInit(MyLittleHero.m_fightArray, 0);
	PlayerArrayInit(player2data.m_fightArray, 1);

	return true;
}


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
	if (distance >= herocase->getAttackDistance() * oneLattice * 2 && !herocase->attackTarget->die())    //������������Ŀ��û�����ƶ�
	{
		herocase->setPosition(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);
		herocase->set(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);  //����λ�ô�������
	}
	//�����ƶ�
}


void HeroLayer::update(float dt)
{
	for (int i = 0; i < MyLittleHero.m_fightArray->num; i++)
	{
		((hero*)(MyLittleHero.m_fightArray->arr[i]))->die();
		ChessMove((hero*)(MyLittleHero.m_fightArray->arr[i]), MyLittleHero, player2data);
	}
	for (int i = 0; i < player2data.m_fightArray->num; i++)
	{
		((hero*)(player2data.m_fightArray->arr[i]))->die();
		ChessMove((hero*)(player2data.m_fightArray->arr[i]), player2data, MyLittleHero);
	}
}

void HeroLayer::upgrade(littleHero& littlehero)
{

	for (int i = 0; i < 16; i++)
	{
		hero* temp[3] = { NULL,NULL,NULL };
		ccArray* tempArray[3] = {};
		int s = 0;  //��������������
		if (littlehero.chessnumber[i] >= 3 && i < 16)
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

				littlehero.chessnumber[i] -= 3;
				for (int k = 0; k < 3; k++)
				{
					ccArrayAppendArray(upgrade_chess->equipment, temp[k]->equipment);
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
	switch (type + 16)
	{
	case _2star_DarkKnight:
		return darkKnight::createhero();
		break;
	case _2star_Master:
		return master::createhero();
		break;
	case _2star_CannedPig:
		return cannedPig::createhero();
		break;
	case _2star_FlyDragon:
		return flyDragon::createhero();
		break;
	case _2star_Ghost:
		return ghost::createhero();
		break;
	case _2star_Gargomon:
		return gargomon::createhero();
		break;
	case _2star_GoldenMonster:
		return goldenMonster::createhero();
		break;
	case _2star_IceFire:
		return iceFire::createhero();
		break;
	case _2star_Knight:
		return knight::createhero();
		break;
	case _2star_Pitman:
		return pitman::createhero();
		break;
	case _2star_Ranger:
		return ranger::createhero();
		break;
	case _2star_Snowman:
		return snowman::createhero();
		break;
	case _2star_Elf:
		return elf::createhero();
		break;
	case _2star_WildBoar:
		return wildBoar::createhero();
		break;
	case _2star_SnowMonster:
		return snowMonster::createhero();
		break;
	case _3star_DarkKnight:
		return darkKnight::createhero();
		break;
	case _3star_Master:
		return master::createhero();
		break;
	case _3star_CannedPig:
		return cannedPig::createhero();
		break;
	case _3star_FlyDragon:
		return flyDragon::createhero();
		break;
	case _3star_Ghost:
		return ghost::createhero();
		break;
	case _3star_Gargomon:
		return gargomon::createhero();
		break;
	case _3star_GoldenMonster:
		return goldenMonster::createhero();
		break;
	case _3star_IceFire:
		return iceFire::createhero();
		break;
	case _3star_Knight:
		return knight::createhero();
		break;
	case _3star_Pitman:
		return pitman::createhero();
		break;
	case _3star_Ranger:
		return ranger::createhero();
		break;
	case _3star_Snowman:
		return snowman::createhero();
		break;
	case _3star_Elf:
		return elf::createhero();
		break;
	case _3star_WildBoar:
		return wildBoar::createhero();
		break;
	case _3star_SnowMonster:
		return snowMonster::createhero();
		break;
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
		hero* cur = (hero*)player2data.m_playerArray->arr[i];
		cur->setPosition(cur->getTempPosition());
	}
}
void HeroLayer::pcShowFightArray()
{
	/*λ�ó�ʼ��*/
	for (int k = 0; k < player2data.m_fightArray->num; k++)
	{
		hero* cur = (hero*)player2data.m_fightArray->arr[k];
		for (int i = 3; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (battleLatticeExist[i][j] == 0)
				{
					cur->set(battleLattice[i][j]);
					cur->setTempPosition();
					cur->setPosition(cur->getTempPosition());
				}
				
			}
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

