#pragma once
#include "cocos2d.h"
#include "Maplayer.h"

USING_NS_CC;


//��ͼ��64*36
#define ChessNumber 35
#define OriginalChess 15
class GameData : Scene
{
public:
	static GameData* createGameData();
	CREATE_FUNC(GameData);
	virtual bool init();
	/* ��ȡ��ǰ��Ϸ���ݵĺ��� */
	/* functions to obtain the game data */
	/*int GetPlayerCoin() { return player_coin; }
	int GetPlayerLevel() { return player_level; }
	int GetPlayerExe() { return player_exe; }
	int GetPlayerBlood() { return player_blood; }*/
	int GetGameTurn() { return game_turn; }

	//��¼���ӵ�����
//private:

	/* ��ʼ�����л�����Ϣ */
	void GameStartInit();

	/* ��ǰ����ȫ����Ϣ */
	/* global data */


	/*int player_coin;
	int player_level;
	int player_exe;
	int player_blood;*/
	int game_turn = 0;

	/* �޸ĵ�ǰ��Ϸ���ݵĺ��� */
	/*void ChangePlayerCoin(int benefit) { player_coin += benefit; }
	void ChangePlayerExe(int benefit) { player_exe += benefit; }   //�������԰�level�ĸı��߼��Ž��������
	void ChangePlayerBlood(int hurt) { player_blood -= hurt; }  */   //ע���˺�������
	void ChangeGameTurn() { game_turn++; }

};

struct chessInfo
{
	int address = 0;
	std::string picture_name = "";
	int money = 0;
	bool buy = false;
};
/*�ⲿ����ȫ�ֱ��� global_data*/
extern GameData* global_data;

enum ChessType
{
	None = -1,Knight,CannedPig,DarkKnight,
	Elf,FlyDragon,Gargomon,Ghost,GoldenMonster,
	IceFire,Master,Pitman,Ranger,Snowman,SnowMonster,
	WildBoar,
	//2��Ӣ��
	_2star_Knight, _2star_CannedPig, _2star_DarkKnight, _2star_Elf,
	_2star_FlyDragon, _2star_Gargomon, _2star_Ghost, _2star_GoldenMonster, _2star_IceFire,
	_2star_Master, _2star_Pitman, _2star_Ranger, _2star_Snowman, _2star_SnowMonster,
	_2star_WildBoar,
	//3��Ӣ��
	_3star_Knight, _3star_CannedPig, _3star_DarkKnight, _3star_Elf,
	_3star_FlyDragon, _3star_Gargomon, _3star_Ghost, _3star_GoldenMonster, _3star_IceFire,
	_3star_Master, _3star_Pitman, _3star_Ranger, _3star_Snowman, _3star_SnowMonster,
	_3star_WildBoar
};

extern const int PB[10][5];
extern const chessInfo chess_store[OriginalChess];