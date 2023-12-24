#include"cocos2d.h"
USING_NS_CC;
//’Ω∂∑µÿÕº¿‡
class battleMap :public cocos2d::Scene {
public:
	CREATE_FUNC(battleMap);
	battleMap();
	~battleMap();
private:
	bool battleLatticeIsEmpty[6][7];
	bool waitLatticeIsEmpty[2][9];
};

int countLattice(Vec2 lat1, Vec2 lat2);
Vec2 positionToLattice(Vec2 pos);
extern Vec2 battleLattice[6][7];
extern Vec2 waitLattice[2][9];

extern float oneLattice;