#include "battleMap.h"
USING_NS_CC;
battleMap::battleMap()
{

}

battleMap::~battleMap()
{

}

bool battleMap::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*
	方案
	横向：
	25等分。偶数行第7格右边界作为起始点，每两格一个点位，共7个点位；奇数行第6格右侧开始，其余同偶数行（由第0行开始）
	纵向：
	每行的点位间距是横向根号3倍。共8行。

	左下角起始位置由计算得出
	*/
	float pieceX = visibleSize.width / 25;
	float pieceY = pieceX * sqrt(3);
	Vec2 startPoint = { origin.x + pieceX * 6, origin.y + (visibleSize.height - pieceY * 7) / 2 };//左下点位坐标

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				battleLattice[i][j] = { startPoint.x + pieceX * (i * 2 + 1), startPoint.y + pieceY * j };
			}
			else
			{
				battleLattice[i][j] = { startPoint.x + pieceX * (i * 2), startPoint.y + pieceY * j };
			}
		}
	/*
	备战席：
	总宽度与战斗格相同
	共9格
	*/
	startPoint = { startPoint.x - pieceX / 6,startPoint.y - pieceY * 1.5 };
	pieceX *= 5.0 / 6;
	for (int j = 0; j < 9; j++)
	{
		waitLattice[0][j] = { startPoint.x + pieceX * j * 2,startPoint.y };
		waitLattice[1][j] = { origin.x + visibleSize.width - waitLattice[0][j].x,origin.y + visibleSize.height - waitLattice[0][j].y };
	}
}

int battleMap::countLattice(Vec2 lat1, Vec2 lat2)
{
	float deltaX = lat1.x - lat2.x, deltaY = lat1.y - lat2.y;
	float disSquare = deltaX * deltaX + deltaY * deltaY;
	float oneLattice = (battleLattice[0][1].x - battleLattice[0][0].x) * 2 / sqrt(3);
	for (int i = 1; i <= 10; i++)
	{
		if (oneLattice * i * oneLattice * i >= disSquare)
			return i;
	}
	return 100;
}
/*
寻路方案：
以自身为中心，向外圈扩展。
广搜，找出能打到人的情况下走的最少的步数。
同时如果有多个最小步数，则找停下后能达到距离最近的敌方的位置。

*/