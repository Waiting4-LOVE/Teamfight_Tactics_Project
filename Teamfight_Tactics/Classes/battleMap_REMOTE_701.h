#include"cocos2d.h"
USING_NS_CC;
//’Ω∂∑µÿÕº¿‡
class battleMap :public cocos2d::Scene {
public:
	CREATE_FUNC(battleMap);
	battleMap();
	~battleMap();
	bool init();
	static int countLattice(Vec2 lat1, Vec2 lat2);
	Vec2 stickToLattice(Vec2 pos);

private:
	static Vec2 battleLattice[6][7];
	static Vec2 waitLattice[2][9];
	bool battleLatticeIsEmpty[6][7];
	bool waitLatticeIsEmpty[2][9];
};
