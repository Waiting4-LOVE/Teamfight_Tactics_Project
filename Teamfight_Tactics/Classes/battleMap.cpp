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
	����
	����
	25�ȷ֡�ż���е�7���ұ߽���Ϊ��ʼ�㣬ÿ����һ����λ����7����λ�������е�6���Ҳ࿪ʼ������ͬż���У��ɵ�0�п�ʼ��
	����
	ÿ�еĵ�λ����Ǻ������3������8�С�

	���½���ʼλ���ɼ���ó�
	*/
	float pieceX = visibleSize.width / 25;
	float pieceY = pieceX * sqrt(3);
	Vec2 startPoint = { origin.x + pieceX * 6, origin.y + (visibleSize.height - pieceY * 7) / 2 };//���µ�λ����

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
	��սϯ��
	�ܿ����ս������ͬ
	��9��
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
Ѱ·������
������Ϊ���ģ�����Ȧ��չ��
���ѣ��ҳ��ܴ��˵�������ߵ����ٵĲ�����
ͬʱ����ж����С����������ͣ�º��ܴﵽ��������ĵз���λ�á�

*/