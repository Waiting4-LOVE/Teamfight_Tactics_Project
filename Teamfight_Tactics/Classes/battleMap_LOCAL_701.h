#include"cocos2d.h"
USING_NS_CC;
//’Ω∂∑µÿÕº¿‡
class battleMap :public cocos2d::Scene {
public:
	CREATE_FUNC(battleMap);
	battleMap();
	~battleMap();
	bool init();
	int countLattice(Vec2 lat1, Vec2 lat2);
private:
	bool battleLatticeIsEmpty[7][8];
	bool waitLatticeIsEmpty[2][9];
};
Vec2 battleLattice[7][8];
Vec2 waitLattice[2][9];