#pragma once
#include<cocos2d.h>
#include"HeroFile.h"


USING_NS_CC;
using namespace std;

class HeroLayer :public Layer
{
public:
	static HeroLayer* createHeroLayer();
	CREATE_FUNC(HeroLayer);

	void PlayerArrayInit(ccArray* Array, int playerinfo);
	virtual bool init();
	void update(float dt);

	void pcShowPlayerArray();
	void pcShowFightArray();
	void ChessMove(hero* herocase, littleHero&playerdata, littleHero& AttackPlayer);
private:
	//void upgrade(littleHero& littlehero);
	//hero* HeroLayer::upgradeChessCreate(int type);

	friend class GameScene;
	float CountDistance(hero* h1, hero* h2);
	float CountDistance(Point p1, Point p2);
};
