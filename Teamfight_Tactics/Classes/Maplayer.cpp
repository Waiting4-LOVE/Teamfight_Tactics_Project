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

	// ���ͼƬΪ�˲���ӽڵ�
	this->addChild(sprite, 0);
	return true;
}

void MapLayer::update(float dt)
{

}