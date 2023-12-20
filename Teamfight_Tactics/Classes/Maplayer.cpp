#include"MapLayer.h"

MapLayer* MapLayer::createMapLayer()
{
	auto temp = MapLayer::create();
	temp->retain();
	return temp;
}
bool MapLayer::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("battlemapunclick.png");
	// ��ȡ���ڵĴ�С

	// �������ű�����ʹͼƬ������������
	float scaleX = visibleSize.width / sprite->getContentSize().width;
	float scaleY = visibleSize.height / sprite->getContentSize().height;

	// ʹ��ScaleTo����������ͼƬ
	sprite->setScaleX(scaleX);
	sprite->setScaleY(scaleY);

	// ����ͼƬ��λ��Ϊ��������
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	// ����ͼƬΪ�˲���ӽڵ�
	this->addChild(sprite, 0);
	return true;
}

IntMap MapIntReturn(Point point)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //������ͼ���ж��Ƿ��ڸ�����
				+ (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
				return IntMap(i, j);    //������ɢ������
		}
	}
	return IntMap(-1, -1);
}
int a[65];

void MapLayer::update(float dt)
{

}
Point mapPosition[8][10];
bool ChessExist[8][10] = {};