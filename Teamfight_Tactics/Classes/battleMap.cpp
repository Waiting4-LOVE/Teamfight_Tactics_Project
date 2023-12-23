#include "battleMap.h"
USING_NS_CC;
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
	����
	����
	25�ȷ֡�ż���е�7���ұ߽���Ϊ��ʼ�㣬ÿ����һ����λ����7����λ�������е�6���Ҳ࿪ʼ������ͬż���У��ɵ�0�п�ʼ��
	����
	ÿ�еĵ�λ����Ǻ������3������8�С�

	���½���ʼλ���ɼ���ó�
	*/
	float pieceX = 861.0f / 1920.0f * visibleSize.width / 15.0f;//�����ο�ȣ����Ǳ߳�����һ��
	oneLattice = pieceX / sqrt(3) * 2;//�����α߳�
	float pieceY = pieceX * sqrt(3);
	Vec2 startPoint = { origin.x + (visibleSize.width - pieceX * 13) / 2, origin.y + (visibleSize.height - pieceY * 5) / 2 };//���µ�λ����

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
	��սϯ��
	�ܿ����ս������ͬ
	��9��
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
		if (oneLattice * i * 2 >= disSquare)//�����߳���Ϊ���������һ��
			return i;
	}
	return 100;
}

std::pair<int, int> positionToLattice(Vec2 pos)
{
	std::pair<int, int> ans = { 0,0 };
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 3; j++)
		{
			if (battleLattice[i][j].distance(pos) < battleLattice[ans.first][ans.second].distance(pos))
				ans = { i,j + 1 };//�����ս��������y���һ���Ա��뱸ս������
		}
	for (int j = 0; j < 9; j++)
	{
		if (waitLattice[0][j].distance(pos) < battleLattice[ans.first][ans.second].distance(pos))
			ans = { 0,j };
	}
	float minDistance = battleLattice[ans.first][ans.second].distance(pos);
	if (minDistance > oneLattice)//����Ѿ��ڸ�������֮�⣨�����жϣ�
		return { -1,-1 };
	return ans;
}

Vec2 latticeToPosition(std::pair<int, int> lat)
{
	int x = lat.first, y = lat.second;
	if (y > 0)
	{
		y--;
		return battleLattice[x][y];
	}
	return waitLattice[x][y];
}

bool judgeExist(std::pair<int, int>lat)
{
	int x = lat.first, y = lat.second;
	if (y > 0)
	{
		y--;
		return battleLatticeExist[x][y];
	}
	return waitLatticeExist[x][y];
}