#include"cocos2d.h"
USING_NS_CC;
//’Ω∂∑µÿÕº¿‡
class battleMap :public cocos2d::Scene {
public:
	CREATE_FUNC(battleMap);
	battleMap();
	~battleMap();
private:
	bool battleLatticeExist[6][7];
	bool waitLatticeExist[2][9];
};
Vec2 battleLattice[6][7];
Vec2 waitLattice[2][9];
int countLattice(Vec2 lat1, Vec2 lat2);
std::pair<int, int>positionToLattice(Vec2 pos);
Vec2 latticeToPosition(std::pair<int, int> lat);
void battleMapinit();
float oneLattice;
bool judgeExist(std::pair<int, int>lat);