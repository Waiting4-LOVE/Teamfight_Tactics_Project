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

	auto sprite = Sprite::create("battlemap.png");
	// 获取窗口的大小

	// 计算缩放比例，使图片填满整个窗口
	float scaleX = visibleSize.width / sprite->getContentSize().width;
	float scaleY = visibleSize.height / sprite->getContentSize().height;

	// 使用ScaleTo动作来缩放图片
	sprite->setScaleX(scaleX);
	sprite->setScaleY(scaleY);

	// 设置图片的位置为窗口中心
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	// 添加图片为此层的子节点
	this->addChild(sprite, 0);
	return true;
}

/*IntMap MapIntReturn(Point point)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (sqrt((point.x - mapPosition[i][j].x) * (point.x - mapPosition[i][j].x)    //遍历地图，判断是否在格子内
				+ (point.y - mapPosition[i][j].y) * (point.y - mapPosition[i][j].y)) < 37.5 * sqrt(2))
				return IntMap(i, j);    //返回离散型坐标
		}
	}
	return IntMap(-1, -1);
}
int a[65];*/

void MapLayer::update(float dt)
{

}
