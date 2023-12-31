#pragma once
#include "cocos2d.h"
#include "Maplayer.h"
#include "equipmentFile.h"
USING_NS_CC;


//地图：64*36
#define ChessNumber 35
#define OriginalChess 15
#define EptNum 8
class GameData : Scene
{
public:
	static GameData* createGameData();
	CREATE_FUNC(GameData);
	virtual bool init();

	int GetGameTurn() { return game_turn; }

	/* 初始化所有基本信息 */
	void GameStartInit();

	
	int game_turn = 0;
	bool isai = 1;
	bool host = 0;
	bool isonline = 0;
	bool canstart = 0;
	bool allstart = 0;
	void ChangeGameTurn() { game_turn++; }

};

struct chessInfo
{
	int address = 0;
	std::string picture_name = "";
	int money = 0;
	bool buy = false;
};

struct eptInfo {
	int address;
	std::string picName;
	bool selected;
};
/*外部声明全局变量 global_data*/
extern GameData* global_data;

enum ChessType
{
	None = -1, Knight, CannedPig, DarkKnight,
	Elf, FlyDragon, Gargomon, Ghost, GoldenMonster,
	IceFire, Master, Pitman, Ranger, Snowman, SnowMonster,
	WildBoar,
	//2星英雄
	 _2star_Knight, _2star_CannedPig, _2star_DarkKnight, _2star_Elf,
	_2star_FlyDragon, _2star_Gargomon, _2star_Ghost, _2star_GoldenMonster, _2star_IceFire,
	_2star_Master, _2star_Pitman, _2star_Ranger, _2star_Snowman, _2star_SnowMonster,
	_2star_WildBoar,
	//3星英雄
    _3star_Knight, _3star_CannedPig, _3star_DarkKnight, _3star_Elf,
	_3star_FlyDragon, _3star_Gargomon, _3star_Ghost, _3star_GoldenMonster, _3star_IceFire,
	_3star_Master, _3star_Pitman, _3star_Ranger, _3star_Snowman, _3star_SnowMonster,
	_3star_WildBoar
};

enum EquipmentType {
	StromSword = 0,
	CrookedBow,
	BoxingGloves,
	GiantBelt,
	Hauberk,
	NegativeCape,
	TearsOfTheGoddess,
	UselessStick
};

extern const int PB[10][5];
extern const chessInfo chess_store[OriginalChess];
extern const eptInfo allEptInfo[EptNum];