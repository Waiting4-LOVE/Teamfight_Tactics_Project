#include"PC_Player.h"

//辅助函数
hero* heroCreate(int ct) {
	switch (ct) {
		case Knight:
			return knight::createhero();
			break;
		case CannedPig:
			return cannedPig::createhero();
			break;
		case DarkKnight:
			return darkKnight::createhero();
			break;
		case Elf:
			return elf::createhero();
			break;
		case FlyDragon:
			return flyDragon::createhero();
			break;
		case Gargomon:
			return gargomon::createhero();
			break;
		case Ghost:
			return ghost::createhero();
			break;
		case GoldenMonster:
			return goldenMonster::createhero();
			break;
		case IceFire:
			return iceFire::createhero();
			break;
		case Master:
			return master::createhero();
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
		case SnowMonster:
			return snowMonster::createhero();
			break;
		case WildBoar:
			return wildBoar::createhero();
			break;
		case _2star_Knight:
			return _2star_knight::createhero();
			break;
		case _2star_CannedPig:
			return _2star_cannedPig::createhero();
			break;
		case _2star_DarkKnight:
			return _2star_darkKnight::createhero();
			break;
		case _2star_Elf:
			return _2star_elf::createhero();
			break;
		case _2star_FlyDragon:
			return _2star_flyDragon::createhero();
			break;
		case _2star_Gargomon:
			return _2star_gargomon::createhero();
			break;
		case _2star_Ghost:
			return _2star_ghost::createhero();
			break;
		case _2star_GoldenMonster:
			return _2star_goldenMonster::createhero();
			break;
		case _2star_IceFire:
			return _2star_iceFire::createhero();
			break;
		case _2star_Master:
			return _2star_master::createhero();
			break;
		case _2star_Pitman:
			return _2star_pitman::createhero();
			break;
		case _2star_Ranger:
			return _2star_ranger::createhero();
			break;
		case _2star_Snowman:
			return _2star_snowman::createhero();
			break;
		case _2star_SnowMonster:
			return _2star_snowMonster::createhero();
			break;
		case _2star_WildBoar:
			return _2star_wildBoar::createhero();
			break;
		case _3star_Knight:
			return _3star_knight::createhero();
			break;
		case _3star_CannedPig:
			return _3star_cannedPig::createhero();
			break;
		case _3star_DarkKnight:
			return _3star_darkKnight::createhero();
			break;
		case _3star_Elf:
			return _3star_elf::createhero();
			break;
		case _3star_FlyDragon:
			return _3star_flyDragon::createhero();
			break;
		case _3star_Gargomon:
			return _3star_gargomon::createhero();
			break;
		case _3star_Ghost:
			return _3star_ghost::createhero();
			break;
		case _3star_GoldenMonster:
			return _3star_goldenMonster::createhero();
			break;
		case _3star_IceFire:
			return _3star_iceFire::createhero();
			break;
		case _3star_Master:
			return _3star_master::createhero();
			break;
		case _3star_Pitman:
			return _3star_pitman::createhero();
			break;
		case _3star_Ranger:
			return _3star_ranger::createhero();
			break;
		case _3star_Snowman:
			return _3star_snowman::createhero();
			break;
		case _3star_SnowMonster:
			return _3star_snowMonster::createhero();
			break;
		case _3star_WildBoar:
			return _3star_wildBoar::createhero();
			break;
	}
}

int PC_Player::pcJudgeMoneyUsage() {
	bool saveMoney = false;
	bool flag = false;
	if (this->CheckGoldInterest()) saveMoney = true;
	//检查是否能升星
	flag = this->CheckHeroUpgrade();
	//检查战斗区棋子能不能放满
	if (flag) flag = this->CheckFightArrLimit();
	//检查与敌方exp差距是否过大
	this->CheckBuyExp();
	//检查是否靠近利息点
	flag = this->CheckGoldInterest();
	//买高费棋子
	if (!saveMoney) {
		//如果不省钱
		if (!flag) flag = this->CheckHighFeeHero(); //不靠近利息点，则买高费
		//如果上一步买了高费英雄，则不刷新商店
		if (flag && player2data.getCoins() >= 2) {
			player2data.delCoins(2);
			this->refresh(player2data);
		}
	}
	return 0;
}

bool PC_Player::CheckHeroUpgrade() {
	for (int i = 0; i < ChessNumber; i++) {
		if (player2data.chessnumber[i] > 0) {
			//找到存在的棋子种类
			for (int j = 0; j < 5; j++) {
				//判断是否存在可升星棋子或其子棋子（后半句为判断三星）
				if (player2data.Used[j].address == i ||
					(player2data.Used[j].address > OriginalChess &&
						i == player2data.Used[j].address - OriginalChess)) {
					if (this->pcBuyHero(j)) return false; //买棋子
				}
			}
		}
	}
	return true;
}

bool PC_Player::CheckFightArrLimit() {
	//计算当前棋子总数  备战区加战斗区
	int chessNum = player2data.m_fightArray->num + player2data.m_playerArray->num;
	if (chessNum <= player2data.m_level && player2data.m_coins > 5) {
		//棋子总数不足并且金币充足
		int tempCoin = 0, tempAddress = -1;
		//购买逻辑
		for (int j = 0; j < 5; j++) {
			if (player2data.Used[j].money >= tempCoin && player2data.Used[j].buy == false) {
				tempCoin = player2data.Used[j].money; //寻找最高费棋子
				tempAddress = j;
			}
		}
		if (tempAddress != -1) {
			if (this->pcBuyHero(tempAddress)) return false; //购买英雄
		}
		else return true; //无法购买
	}
	return true;
}

void PC_Player::CheckBuyExp() {
	//计算等级差值
	int levelDiff = MyLittleHero.m_level - player2data.m_level;
	//计算经验差值
	int expDiff = MyLittleHero.m_exp - player2data.m_exp;
	//若存在等级差或相同等级但经验差超过5，在金币充足的情况下进行购买经验
	while ((levelDiff > 0 || expDiff > 5) && player2data.m_coins > 4) {
		player2data.addExp(4);
		player2data.delCoins(4);
		levelDiff = MyLittleHero.m_level - player2data.m_level;
		expDiff = MyLittleHero.m_exp - player2data.m_exp;
	}
}

bool PC_Player::CheckGoldInterest() {
	//返回true表示需要进行存钱
	if (player2data.m_coins > 5 && player2data.m_coins < 10) return true;
	else if (player2data.m_coins > 25 && player2data.m_coins < 30) return true;
	else if (player2data.m_coins > 45 && player2data.m_coins < 50) return true;
	else return false;
}

bool PC_Player::CheckHighFeeHero() {
	int tempCoin = 0, tempAddress = -1;
	for (int j = 0; j < 5; j++) {
		if (player2data.Used[j].money >= tempCoin && player2data.Used[j].buy == false) {
			tempCoin = player2data.Used[j].money; //寻找最高费棋子
			tempAddress = j;
		}
	}
	if (tempCoin >= 3) {
		//三费卡
		if (this->pcBuyHero(tempAddress)) return false;
	}
	return true;
}

hero* upgradeChessCreate(int type)
{
	switch (type + 15)
	{
	case _2star_DarkKnight:
		return _2star_darkKnight::createhero();
		break;
	case _2star_Master:
		return _2star_master::createhero();
		break;
	case _2star_CannedPig:
		return _2star_cannedPig::createhero();
		break;
	case _2star_FlyDragon:
		return _2star_flyDragon::createhero();
		break;
	case _2star_Ghost:
		return _2star_ghost::createhero();
		break;
	case _2star_Gargomon:
		return _2star_gargomon::createhero();
		break;
	case _2star_GoldenMonster:
		return _2star_goldenMonster::createhero();
		break;
	case _2star_IceFire:
		return _2star_iceFire::createhero();
		break;
	case _2star_Knight:
		return _2star_knight::createhero();
		break;
	case _2star_Pitman:
		return _2star_pitman::createhero();
		break;
	case _2star_Ranger:
		return _2star_ranger::createhero();
		break;
	case _2star_Snowman:
		return _2star_snowman::createhero();
		break;
	case _2star_Elf:
		return _2star_elf::createhero();
		break;
	case _2star_WildBoar:
		return _2star_wildBoar::createhero();
		break;
	case _2star_SnowMonster:
		return _2star_snowMonster::createhero();
		break;
	case _3star_DarkKnight:
		return _3star_darkKnight::createhero();
		break;
	case _3star_Master:
		return _3star_master::createhero();
		break;
	case _3star_CannedPig:
		return _3star_cannedPig::createhero();
		break;
	case _3star_FlyDragon:
		return _3star_flyDragon::createhero();
		break;
	case _3star_Ghost:
		return _3star_ghost::createhero();
		break;
	case _3star_Gargomon:
		return _3star_gargomon::createhero();
		break;
	case _3star_GoldenMonster:
		return _3star_goldenMonster::createhero();
		break;
	case _3star_IceFire:
		return _3star_iceFire::createhero();
		break;
	case _3star_Knight:
		return _3star_knight::createhero();
		break;
	case _3star_Pitman:
		return _3star_pitman::createhero();
		break;
	case _3star_Ranger:
		return _3star_ranger::createhero();
		break;
	case _3star_Snowman:
		return _3star_snowman::createhero();
		break;
	case _3star_Elf:
		return _3star_elf::createhero();
		break;
	case _3star_WildBoar:
		return _3star_wildBoar::createhero();
		break;
	case _3star_SnowMonster:
		return _3star_snowMonster::createhero();
		break;
		//二星与三星英雄

	default:
		break;
	}
}

bool PC_Player::pcBuyHero(int selected) {
	if (player2data.m_fightArray->num + player2data.m_playerArray->num <= player2data.m_level + 9) {
		//保证不超过备战区的最大容量
		if (player2data.m_coins >= player2data.Used[selected].money && player2data.Used[selected].buy == false) {
			//金币充足就购买
			auto temp = heroCreate(player2data.Used[selected].address);
			ccArrayAppendObject(player2data.m_playerArray, temp);
			player2data.haveNewHero = true;
			player2data.Used[selected].buy = true;
			return true;
		}
		else return false;
	}
	return true;
}

void PC_Player::pcCreateBattleArray() {
	for (int j = 3; j >= 1; j--) {
		for (int i = 0; i < player2data.m_playerArray->num; i++) {
			if (player2data.m_fightArray->num < player2data.m_level) {
				//可以继续在战斗区放棋子，优先选最高星级的英雄
				if (((hero*)(player2data.m_playerArray->arr[i]))->getStar() == j) {
					ccArrayAppendObject(player2data.m_fightArray, player2data.m_playerArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.m_playerArray, i);
				}
				else break;
			}
		}
		if (player2data.m_fightArray->num == player2data.m_level) break;
	}
	//如果战斗区已满，则需要进行更新更高级的英雄
	//1星换成2星
	for (int i = 0; i < player2data.m_fightArray->num; i++) {
		if (((hero*)(player2data.m_fightArray->arr[i]))->getStar() > 1) continue;
		else {
			for (int j = 0; j < player2data.m_playerArray->num; j++) {
				if (((hero*)(player2data.m_playerArray->arr[j]))->getStar() > 1) {
					//挑选出大于1星的英雄，将1星英雄进行交换
					ccArrayAppendObject(player2data.m_fightArray, player2data.m_playerArray->arr[j]);
					ccArrayRemoveObjectAtIndex(player2data.m_playerArray, j);
					ccArrayAppendObject(player2data.m_playerArray, player2data.m_fightArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.m_fightArray, i);
				}
			}
		}
	}
	//将2星换成3星
	for (int i = 0; i < player2data.m_fightArray->num; i++) {
		if (((hero*)(player2data.m_fightArray->arr[i]))->getStar() == 3) continue;
		else {
			for (int j = 0; j < player2data.m_playerArray->num; j++) {
				if (((hero*)(player2data.m_playerArray->arr[j]))->getStar() == 3) {
					//挑选出3星英雄，将2星英雄进行交换
					ccArrayAppendObject(player2data.m_fightArray, player2data.m_playerArray->arr[j]);
					ccArrayRemoveObjectAtIndex(player2data.m_playerArray, j);
					ccArrayAppendObject(player2data.m_playerArray, player2data.m_fightArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.m_fightArray, i);
				}
			}
		}
	}
}

void PC_Player::pcEquipment() {
	for (int i = 0; i < player2data.m_unEquipedEpt->num; i++) {
		int equipTargetIndex = rand() % (player2data.m_fightArray->num);
		auto temp = (hero*)player2data.m_fightArray->arr[equipTargetIndex];
		ccArrayAppendObject(temp->equipment, ((Equipment*)player2data.m_unEquipedEpt->arr[i]));
		ccArrayRemoveObjectAtIndex(player2data.m_unEquipedEpt, i);
		((Equipment*)player2data.m_unEquipedEpt->arr[i])->removeFromParent();
		temp->EquipmentChange();
	}
}

void PC_Player::refresh(littleHero& lh) {
	for (int i = 0; i < 5; i++) {
		int deter = 0;
		deter = rand() % 100 + 1; //生成1-100随机数，随机选择英雄
		for (int j = 0; j < 5; j++) {
			if (deter > PB[std::min(9, player2data.m_level) - 1][j]) deter -= PB[std::min(9, player2data.m_level) - 1][j];
			else {
				int temp = 0;
				while (1) {
					temp = rand() % OriginalChess; //随机选一个英雄棋子
					if (chess_store[temp].money == j + 1) break;
				}
				player2data.Used[i].address = chess_store[temp].address;
				player2data.Used[i].money = chess_store[temp].money;
				player2data.Used[i].picture_name = chess_store[temp].picture_name;
				player2data.Used[i].buy = false;
				break;
			}
		}
	}
}

hero* PC_Player::pcSoldHero() {
	for (int i = 0; i < player2data.m_playerArray->num; i++) {
		auto temp = (hero*)player2data.m_playerArray->arr[i];
		if (temp->getStar() == 1 && temp->getCoinsNeeded() <= 2) return temp; //卖掉最低星级
	}
}

PC_Player pl_player;