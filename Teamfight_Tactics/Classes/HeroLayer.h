#include<cocos2d.h>
#include"HeroFile.h"
#include"PlayerData.h"

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
private:
	void update(PlayerData& playerdata);
	Hero* GameSprite::updateChessCreate(int type);

	friend class GameScene;
	float CountDistance(Hero* h1, Hero* h2);
	float CountDistance(Point p1, Point p2);
};
