#include "battleMap.h"
USING_NS_CC;
Vec2 battleLattice[6][7];
Vec2 waitLattice[2][9];

float oneLattice;
battleMap::battleMap()
{

}

battleMap::~battleMap()
{

}

void battleMapinit()
{
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
	float pieceX = 861.0f / 1920.0f * visibleSize.width / 15.0f;//六边形宽度（不是边长）的一半
	oneLattice = pieceX / sqrt(3) * 2;//六边形边长
	float pieceY = pieceX * sqrt(3);
	Vec2 startPoint = { origin.x + (visibleSize.width - pieceX * 13) / 2, origin.y + (visibleSize.height - pieceY * 5) / 2 };//左下点位坐标

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
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
	startPoint = { startPoint.x - pieceX / 6,startPoint.y - pieceY * 1.5f };
	pieceX *= 5.0 / 6;
	for (int j = 0; j < 9; j++)
	{
		waitLattice[0][j] = { startPoint.x + pieceX * j * 2,startPoint.y };
		waitLattice[1][j] = { origin.x + visibleSize.width - waitLattice[0][j].x,origin.y + visibleSize.height - waitLattice[0][j].y };
	}
}

int countLattice(Vec2 lat1, Vec2 lat2)
{
	float disSquare = lat1.distance(lat2);
	for (int i = 1; i <= 10; i++)
	{
		if (oneLattice * i * 2 >= disSquare)//两倍边长作为攻击距离的一格
			return i;
	}
	return 100;
}

Vec2 positionToLattice(Vec2 pos)
{
	Vec2 ans = battleLattice[0][0];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 3; j++)
		{
			if (battleLattice[i][j].distance(pos) < ans.distance(pos))
				ans = battleLattice[i][j];
		}
	for (int j = 0; j < 9; j++)
	{
		if (waitLattice[0][j].distance(pos) < ans.distance(pos))
			ans = battleLattice[0][j];
	}
	float minDistance = ans.distance(pos);
	if (minDistance > oneLattice)//如果已经在格子区域之外（简易判断）
		return { 10000,10000 };
	return ans;
}