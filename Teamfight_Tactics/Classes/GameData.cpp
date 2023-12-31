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

const chessInfo chess_store[OriginalChess] = { { Knight,"knightInShop.png",1 },{ CannedPig,"cannedPigInShop.png",4 },
	{ DarkKnight,"darkKnightInShop.png",3 },{ Elf,"elfInShop.png",3 } ,
	{ FlyDragon,"flyDragonInShop.png",4 } ,{ Gargomon,"gargomonInShop.png",5 } ,
	{ Ghost,"ghostInShop.png",5 } ,{ GoldenMonster,"goldenMonsterInShop.png",2 } ,
	{ IceFire,"iceFireInShop.png",5 } ,{ Master,"masterInShop.png",3 },
	{ Pitman,"pitmanInShop.png",1 },{ Ranger,"rangerInShop.png",2 },
	{ Snowman,"snowmanInShop.png",1 },{ SnowMonster,"snowMonsterInShop.png",4 },
	{ WildBoar,"wildBoarInShop.png",2 } };
     //初步的棋子商店，后续可加上卡池功能

//全部装备信息
const eptInfo allEptInfo[EptNum] = {
	{StromSword,"stromSword.png",false},
	{CrookedBow,"crookedBow.png",false},
	{BoxingGloves,"boxingGloves.png",false},
	{GiantBelt,"giantBelt.png",false},
	{Hauberk,"hauberk.png",false},
	{NegativeCape,"negativeCape.png",false},
	{TearsOfTheGoddess,"tearsOfTheGoddess.png",false},
	{UselessStick,"uselessStick.png",false}
};