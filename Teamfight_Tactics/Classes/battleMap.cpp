#include "battleMap.h"
USING_NS_CC;

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
	float minDistance = 10000.0f;
	std::pair<int, int> ans = { 1,0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 7; j++)
		{
			if (battleLattice[i][j].distance(pos) < minDistance)
			{
				ans = { i + 1 ,j };
				minDistance = battleLattice[i][j].distance(pos);
			}
			//如果是战斗区，则x加一，以便与备战区区分
		}
	for (int j = 0; j < 9; j++)
	{
		if (waitLattice[0][j].distance(pos) < minDistance)
		{
			ans = { 0 ,j };
			minDistance = waitLattice[0][j].distance(pos);
		}
		else if (waitLattice[1][j].distance(pos) < minDistance)
		{
			ans = { 7 ,j };
			minDistance = waitLattice[1][j].distance(pos);
		}
	}
	if (minDistance > oneLattice)//如果已经在格子区域之外（简易判断）
		return { -1,-1 };
	return ans;
}

Vec2 latticeToPosition(std::pair<int, int> lat)
{
	int x = lat.first, y = lat.second;
	if (x > 0 && x < 7)
	{
		x--;
		return battleLattice[x][y];
	}
	else if (x == 0) return waitLattice[x][y];
	else if (x == 7) return waitLattice[1][y];
}

void setLatticeExist(std::pair<int, int> lat, int exist)//战斗区为1-3，敌方为4-6
{
	int x = lat.first, y = lat.second;
	if (x > 0 && x < 7)
	{
		x--;
		battleLatticeExist[x][y] = exist;
	}
	else if (x == 0) waitLatticeExist[x][y] = exist;
	else if (x == 7) waitLatticeExist[1][y] = exist;
}

bool judgeExist(std::pair<int, int> lat)
{
	int x = lat.first, y = lat.second;
	if (x > 0)
	{
		x--;
		return battleLatticeExist[x][y];
	}
	return waitLatticeExist[x][y];
}

Vec2 positionToEnemyPosition(Vec2 pos)
{
	std::pair<int, int> lat = positionToLattice(pos);
	if (lat.first == 0)
	{
		return waitLattice[0][8-lat.second];
	}
	else
	{
		lat.first--;
		return battleLattice[5 - lat.first][8 - lat.second];
	}
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