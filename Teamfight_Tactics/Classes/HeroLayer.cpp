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
			temp1->setPosition(10000, 10000);
			temp1->set(10000, 10000);
		}
		temp1->setPlayer(temp->getPlayer());
		//temp1->EquipmentChange();
		if (ccArrayContainsObject(Array, temp))
			ccArrayRemoveObject(Array, temp);
		ccArrayInsertObjectAtIndex(Array, temp1, i);
		this->addChild(temp1);
		auto lat = positionToLattice(temp->getPosition());
		setLatticeExist(lat, 1);//设置占位
	}
}

bool HeroLayer::init() {
	//auto sprite = hero1::createhero();
	/*初始化的内容，后续需要放到其他位置*/
	
	
	auto temp = master::createhero();  
	temp->set(waitLattice[1][0]);
	temp->setTempPosition();

	auto temp1 = darkKnight::createhero();
	temp1->set(battleLattice[5][0]);
	temp1->setTempPosition();

	auto temp2 = cannedPig::createhero();
	temp2->set(battleLattice[5][6]);
	temp2->setTempPosition();

	auto temp3 = flyDragon::createhero();
	temp3->set(battleLattice[0][6]);
	temp3->setTempPosition();

	auto temp4 = ghost::createhero();
	temp4->set(800, 400);
	temp4->setTempPosition();

	auto temp5 = gargomon::createhero();
	temp5->set(800, 800);
	temp5->setTempPosition();

	auto temp6 = elf::createhero();
	temp6->set(1000, 500);
	temp6->setTempPosition();

	auto temp7 = goldenMonster::createhero();
	temp7->set(1280, 800);
	temp7->setTempPosition();

	auto temp8 = iceFire::createhero();
	temp8->set(1100, 900);
	temp8->setTempPosition();

	auto temp9 = knight::createhero();
	temp9->set(1200, 400);
	temp9->setTempPosition();

	auto temp10 = pitman::createhero();
	temp10->set(800, 400);
	temp10->setTempPosition();

	auto temp11 = ranger::createhero();
	temp11->set(1000, 800);
	temp11->setTempPosition();

	auto temp12 = snowman::createhero();
	temp12->set(1400, 400);
	temp12->setTempPosition();

	auto temp13 = snowMonster::createhero();
	temp13->set(1000, 400);
	temp13->setTempPosition();

	auto temp14 = wildBoar::createhero();
	temp14->set(800, 800);
	temp14->setTempPosition();
	
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp3);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp4);
	//ccArrayAppendObject(MyLittleHero.m_fightArray, temp6);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp9);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp10);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp11);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp12);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp13);
	ccArrayAppendObject(MyLittleHero.m_fightArray, temp14);

	ccArrayAppendObject(player2data.m_fightArray, temp7);
	ccArrayAppendObject(player2data.m_fightArray, temp8);
	ccArrayAppendObject(player2data.m_fightArray, temp1);
	ccArrayAppendObject(player2data.m_fightArray, temp2);
	ccArrayAppendObject(player2data.m_fightArray, temp5);
	



	PlayerArrayInit(MyLittleHero.m_playerArray, 0);
	PlayerArrayInit(player2data.m_playerArray, 0);      //  电脑玩家信息暂不显示
	PlayerArrayInit(MyLittleHero.m_fightArray, 0);
	PlayerArrayInit(player2data.m_fightArray, 0);

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
			(atemp.y - chessPosition.y) * (atemp.y - chessPosition.y));   //求距离
		if (distanceTemp < distance && distanceTemp>0 && !((hero*)temp)->die()) //确定攻击目标
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
	//移动，以1e-2为单位移动

	else if (herocase->attackTarget == (hero*)nullptr)  //无攻击目标则结束
	{
		return;
	}
	if (distance >= herocase->getAttackDistance() * oneLattice && !herocase->attackTarget->die())    //距离大于射程且目标没死则移动
	{
		herocase->setPosition(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);
		herocase->set(herocase->getPosition() + (herocase->attackTarget->getPosition() - herocase->getPosition()) / distance * heroConsts::move_speed);  //将新位置传入类中
	}
	//连续移动
}


void HeroLayer::update(float dt)
{
	for (int i = 0; i < MyLittleHero.m_fightArray->num; i++)
	{
		((hero*)(MyLittleHero.m_fightArray->arr[i]))->die();
		ChessMove((hero*)(MyLittleHero.m_fightArray->arr[i]), MyLittleHero, player2data);
	}
	/*if (MyLittleHero.haveNewHero)
	{
		MyLittleHero.haveNewHero = false;
		auto temp = (hero*)(MyLittleHero.m_playerArray->arr[MyLittleHero.m_playerArray->num - 1]);
		temp->setPosition(temp->getTempPosition());
		CCLOG("%f,%f", temp->getTempPosition().x, temp->getTempPosition().y);
		this->addChild(temp);
	}*/
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
		int s = 0;  //三个待升级棋子
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
			if (s < 3)   //若在备战区没寻满三个，则进入战斗区找
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
				&& temp[0]->getType() == i && temp[1]->getType() == i && temp[2]->getType() == i)  //防止Bug
			{
				auto upgrade_chess = upgradeChessCreate(i);

				littlehero.heronumber[i] -= 3;
				for (int k = 0; k < 3; k++)
				{
					ccArrayAppendArray(upgrade_chess->equipment, temp[k]->equipment);
					temp[k]->retain();          //不retain在release下无法运行
					temp[k]->removeFromParent();
					if (ccArrayContainsObject(tempArray[k], temp[k]))
					{
						ccArrayRemoveObject(tempArray[k], temp[k]);    //_referanceCount>0 报错（加retain后貌似解决）
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
		//二星与三星英雄

	default:
		break;
	}
}

/*PC_Player相关*/
void HeroLayer::pcShowPlayerArray()
{
	for (int i = 0; i < player2data.m_playerArray->num; i++)
	{
		hero* cur = (hero*)player2data.m_playerArray->arr[i];
		cur->setPosition(Director::getInstance()->getVisibleOrigin() * 2 + Director::getInstance()->getVisibleSize() - cur->getPosition());
	}
}
void HeroLayer::pcShowFightArray()
{
	/*位置初始化*/
	for (int i = 0; i < player2data.m_fightArray->num; i++)
	{
		hero* cur = (hero*)player2data.m_fightArray->arr[i];
		cur->setPosition(Director::getInstance()->getVisibleOrigin() * 2 + Director::getInstance()->getVisibleSize() - cur->getPosition());
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

