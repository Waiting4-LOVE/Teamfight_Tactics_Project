#include "battleMap.h"
USING_NS_CC;

void battleMapinit()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	/*
	战斗格子位

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
		}*/
		/*
		备战席：
		总宽度与战斗格相同
		共9格

		startPoint = { startPoint.x - pieceX / 6,startPoint.y - pieceY * 1.5f };
		pieceX *= 5.0 / 6;
		for (int j = 0; j < 9; j++)
		{
			waitLattice[0][j] = { startPoint.x + pieceX * j * 2,startPoint.y };
			waitLattice[1][j] = { origin.x + visibleSize.width - waitLattice[0][j].x,origin.y + visibleSize.height - waitLattice[0][j].y };
		}*/

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

std::pair<int, int> positionToLattice(Vec2 pos)
{
	std::pair<int, int> ans = { 0,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 7; j++)
		{
			if (battleLattice[i][j].distance(pos) < battleLattice[ans.first][ans.second].distance(pos))
				ans = { i + 1,j };//如果是战斗区，则x加一，以便与备战区区分
		}
	for (int j = 0; j < 9; j++)
	{
		if (waitLattice[0][j].distance(pos) < battleLattice[ans.first][ans.second].distance(pos))
			ans = { 0,j };
	}
	float minDistance = battleLattice[ans.first][ans.second].distance(pos);
	if (minDistance > oneLattice)//如果已经在格子区域之外（简易判断）
		return { -1,-1 };
	return ans;
}

Vec2 latticeToPosition(std::pair<int, int> lat)
{
	int x = lat.first, y = lat.second;
	if (x > 0)
	{
		x--;
		return battleLattice[x][y];
	}
	return waitLattice[x][y];
}

void setLatticeExist(std::pair<int, int> lat, int exist)
{
	int x = lat.first, y = lat.second;
	if (x > 0)
	{
		x--;
		battleLatticeExist[x][y] = exist;
	}
	else
	{
		waitLatticeExist[x][y] = exist;
	}
}

bool judgeExist(std::pair<int, int> lat)
{
	int x = lat.first, y = lat.second;
	if (y > 0)
	{
		y--;
		return battleLatticeExist[x][y];
	}
	return waitLatticeExist[x][y];
}

const Vec2 battleLattice[6][7] = {
Vec2(712.5f,385.0f),Vec2(827.5f,385.0f),Vec2(942.5f,385.0f),Vec2(1057.5f,385.0f),Vec2(1172.5f,385.0f),Vec2(1287.5f,385.0f),Vec2(1402.5f,385.0f),
Vec2(655.0f,485.6f),Vec2(770.0f,485.6f),Vec2(885.0f,485.6f),Vec2(1000.0f,485.6f),Vec2(1115.0f,485.6f),Vec2(1230.0f,485.6f),Vec2(1345.0f,485.6f),
Vec2(712.5f,586.2f),Vec2(827.5f,586.2f),Vec2(942.5f,586.2f),Vec2(1057.5f,586.2f),Vec2(1172.5f,586.2f),Vec2(1287.5f,586.2f),Vec2(1402.5f,586.2f),
Vec2(655.0f,686.8f),Vec2(770.0f,686.8f),Vec2(885.0f,686.8f),Vec2(1000.0f,686.8f),Vec2(1115.0f,686.8f),Vec2(1230.0f,686.8f),Vec2(1345.0f,686.8f),
Vec2(712.5f,787.4f),Vec2(827.5f,787.4f),Vec2(942.5f,787.4f),Vec2(1057.5f,787.4f),Vec2(1172.5f,787.4f),Vec2(1287.5f,787.4f),Vec2(1402.5f,787.4f),
Vec2(655.0f,888.0f),Vec2(770.0f,888.0f),Vec2(885.0f,888.0f),Vec2(1000.0f,888.0f),Vec2(1115.0f,888.0f),Vec2(1230.0f,888.0f),Vec2(1345.0f,888.0f) };

const Vec2 waitLattice[2][9] = {
Vec2(610.0f,270.0f),Vec2(710.6f,270.0f),Vec2(811.2f,270.0f),Vec2(911.9f,270.0f),Vec2(1012.5f,270.0f),Vec2(1113.1f,270.0f),Vec2(1213.8f,270.0f),Vec2(1314.4f,270.0f),Vec2(1415.0f,270.0f),
Vec2(630.0f,1020.0f),Vec2(730.6f,1020.0f),Vec2(831.2f,1020.0f),Vec2(931.9f,1020.0f),Vec2(1032.5f,1020.0f),Vec2(1133.1f,1020.0f),Vec2(1233.8f,1020.0f),Vec2(1334.4f,1020.0f),Vec2(1435.0f,1020.0f) };

float oneLattice = 66.395f;
bool battleLatticeExist[6][7];
bool waitLatticeExist[2][9];