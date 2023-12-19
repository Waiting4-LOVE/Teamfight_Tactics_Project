#include"cocos2d.h"
USING_NS_CC;
//’Ω∂∑µÿÕº¿‡
class battleMap :public cocos2d::Scene {
public:
	CREATE_FUNC(battleMap);
	battleMap();
	~battleMap();
	bool init();
private:
	bool battleLatticeIsEmpty[6][7];
	bool waitLatticeIsEmpty[2][9];
};
Vec2 battleLattice[6][7];
Vec2 waitLattice[2][9];
int countLattice(Vec2 lat1, Vec2 lat2);
Vec2 stickToLattice(Vec2 pos);