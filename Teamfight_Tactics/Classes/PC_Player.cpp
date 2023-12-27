#include"PC_Player.h"

//��������
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
	//����Ƿ�������
	flag = this->CheckHeroUpgrade();
	//���ս���������ܲ��ܷ���
	if (flag) flag = this->CheckFightArrLimit();
	//�����з�exp����Ƿ����
	this->CheckBuyExp();
	//����Ƿ񿿽���Ϣ��
	flag = this->CheckGoldInterest();
	//��߷�����
	if (!saveMoney) {
		if (flag) flag = this->CheckHighFeeHero();
		if (flag && player2data.getCoins() >= 2) {
			player2data.delCoins(2);
			this->refresh(player2data);
		}
	}
	return 0;
}

bool PC_Player::CheckHeroUpgrade() {
	for (int i = 0; i < ChessNumber; i++) {
		if (player2data.heronumber[i] > 0) {
			//�ҵ����ڵ���������
			for (int j = 0; j < 5; j++) {
				//�ж��Ƿ���ڿ��������ӻ��������ӣ�����Ϊ�ж����ǣ�
				if (player2data.Used[j].address == i ||
					(player2data.Used[j].address > OriginalChess &&
						i == player2data.Used[j].address - OriginalChess)) {
					if (this->pcBuyHero(j)) return 0; //������
				}
			}
		}
	}
	return 1;
}

bool PC_Player::CheckFightArrLimit() {
	//���㵱ǰ��������  ��ս����ս����
	int chessNum = player2data.m_fightArray->num + player2data.m_playerArray->num;
	if (chessNum <= player2data.m_level && player2data.m_coins > 5) {
		//�����������㲢�ҽ�ҳ���
		int tempCoin = 0, tempAddress = -1;
		//�����߼�
		for (int j = 0; j < 5; j++) {
			if (player2data.Used[j].money >= tempCoin && player2data.Used[j].buy == false) {
				tempCoin = player2data.Used[j].money; //Ѱ����߷�����
				tempAddress = j;
			}
		}
		if (tempAddress != -1) {
			if (this->pcBuyHero(tempAddress)) return 0; //����Ӣ��
		}
		else return 1; //�޷�����
	}
	return 1;
}

void PC_Player::CheckBuyExp() {
	//����ȼ���ֵ
	int levelDiff = MyLittleHero.m_level - player2data.m_level;
	//���㾭���ֵ
	int expDiff = MyLittleHero.m_exp - player2data.m_exp;
	//�����ڵȼ������ͬ�ȼ���������5���ڽ�ҳ��������½��й�����
	while ((levelDiff > 0 || expDiff > 5) && player2data.m_coins > 4) {
		player2data.addExp(4);
		player2data.delCoins(4);
		levelDiff = MyLittleHero.m_level - player2data.m_level;
		expDiff = MyLittleHero.m_exp - player2data.m_exp;
	}
}

int PC_Player::CheckGoldInterest() {
	//����1��ʾ��Ҫ���д�Ǯ
	if (player2data.m_coins < 10) return 1;
	else if (player2data.m_coins > 25 && player2data.m_coins < 30) return 1;
	else if (player2data.m_coins > 45 && player2data.m_coins < 50) return 1;
	else return 0;
}

bool PC_Player::CheckHighFeeHero() {
	int tempCoin = 0, tempAddress = -1;
	for (int j = 0; j < 5; j++) {
		if (player2data.Used[j].money >= tempCoin && player2data.Used[j].buy == false) {
			tempCoin = player2data.Used[j].money; //Ѱ����߷�����
			tempAddress = j;
		}
	}
	if (tempCoin >= 3) {
		//���ѿ�
		if (this->pcBuyHero(tempAddress)) return 0;
	}
}

bool PC_Player::pcBuyHero(int j) {
	if (player2data.m_fightArray->num + player2data.m_playerArray->num <= player2data.m_level + 9) {
		//��֤��������ս�����������
		if (player2data.m_coins >= player2data.Used[j].money && player2data.Used[j].buy == false) {
			//��ҳ���͹���
			auto temp = heroCreate(player2data.Used[j].address);
			ccArrayAppendObject(player2data.m_playerArray, temp);
			player2data.haveNewHero = true;
			player2data.Used[j].buy = true;
			return 1;
		}
		else return 0;
	}
	return 1;
}

void PC_Player::pcCreateBattleArray() {
	for (int j = 3; j >= 1; j--) {
		for (int i = 0; i < player2data.m_playerArray->num; i++) {
			if (player2data.m_fightArray->num < player2data.m_level) {
				//���Լ�����ս���������ӣ�����ѡ����Ǽ���Ӣ��
				if (((hero*)(player2data.m_playerArray->arr[i]))->getStar() == j) {
					ccArrayAppendObject(player2data.m_fightArray, player2data.m_playerArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.m_playerArray, i);
				}
				else break;
			}
		}
		if (player2data.m_fightArray->num == player2data.m_level) break;
	}
	//���ս��������������Ҫ���и��¸��߼���Ӣ��
	//1�ǻ���2��
	for (int i = 0; i < player2data.m_fightArray->num; i++) {
		if (((hero*)(player2data.m_fightArray->arr[i]))->getStar() > 1) continue;
		else {
			for (int j = 0; j < player2data.m_playerArray->num; j++) {
				if (((hero*)(player2data.m_playerArray->arr[j]))->getStar() > 1) {
					//��ѡ������1�ǵ�Ӣ�ۣ���1��Ӣ�۽��н���
					ccArrayAppendObject(player2data.m_fightArray, player2data.m_playerArray->arr[j]);
					ccArrayRemoveObjectAtIndex(player2data.m_playerArray, j);
					ccArrayAppendObject(player2data.m_playerArray, player2data.m_fightArray->arr[i]);
					ccArrayRemoveObjectAtIndex(player2data.m_fightArray, i);
				}
			}
		}
	}
	//��2�ǻ���3��
	for (int i = 0; i < player2data.m_fightArray->num; i++) {
		if (((hero*)(player2data.m_fightArray->arr[i]))->getStar() == 3) continue;
		else {
			for (int j = 0; j < player2data.m_playerArray->num; j++) {
				if (((hero*)(player2data.m_playerArray->arr[j]))->getStar() == 3) {
					//��ѡ��3��Ӣ�ۣ���2��Ӣ�۽��н���
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
		deter = rand() % 100 + 1; //����1-100����������ѡ��Ӣ��
		for (int j = 0; j < 5; j++) {
			if (deter > PB[min(9, player2data.m_level) - 1][j]) deter -= PB[min(9, player2data.m_level) - 1][j];
			else {
				int temp = 0;
				while (1) {
					temp = rand() % OriginalChess; //���ѡһ��Ӣ������
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
		if (temp->getStar() == 1 && temp->getCoinsNeeded() <= 2) return temp; //��������Ǽ�
	}
}

PC_Player pl_player;