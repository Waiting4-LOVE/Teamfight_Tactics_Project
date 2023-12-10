#include<cocos2d.h>
using namespace cocos2d;
using namespace heroConsts;

class hero:public Node
{
private:

public:
	hero();
	static int get_sHealthPoint();//返回英雄现在的血条
	static int get_sBluePoint();//返回英雄现在的蓝条
	static int get_sDefencePoint();//返回英雄现在的护盾
	void health_recover();//回血函数
protected:
	int sActorType;//英雄类型
	static int sHealthPoint;//血条
	static int sBluePoint;//蓝条
	static int sDefencePoint;//护盾
};