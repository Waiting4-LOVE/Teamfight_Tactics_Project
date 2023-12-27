#include "GameData.h"

/*定义全局变量 global_data*/
GameData* global_data = GameData::createGameData();


GameData* GameData::createGameData()
{
	auto game = GameData::create();
	game->retain();
	return game;
}

bool GameData::init()
{
	if (!Scene::init())
		return false;
	return true;
}

void GameData::GameStartInit()
{
	/*player_coin = 0;
	player_level = 1;
	player_exe = 0;
	player_blood = 100;*/
	game_turn = 0;
}

const int PB[10][5] = { {100,0,0,0,0},{75,25,0,0,0},{55,30,15,0,0},{45,33,20,2,0},{25,40,30,5,0},
					  {19,30,40,5,0},{19,30,40,10,1},{18,25,36,18,3},{10,15,20,35,10},{5,10,20,40,25 } };         //商店概率

const chessInfo chess_store[OriginalChess] = { { Knight,"knight.png",1 },{ CannedPig,"cannedPig.png",1 },
	{ DarkKnight,"darkKnight.png",1 },{ Elf,"elf.png",1 } ,
	{ FlyDragon,"flyDragon.png",1 } ,{ Gargomon,"gargomon.png",1 } ,
	{ Ghost,"ghost.png",1 } ,{ GoldenMonster,"goldenMonster.png",1 } ,
	{ IceFire,"iceFire.png",1 } ,{ Master,"master.png",1 },
	{ Pitman,"ritman.png",1 },{ Ranger,"ranger.png",1 },
	{ Snowman,"snowman.png",1 },{ SnowMonster,"snowMonster.png",1 },
	{ WildBoar,"wildBoar.png",1 } };
     //初步的棋子商店，后续可加上卡池功能