#include"HeroLayer.h"



HeroLayer* HeroLayer::createHeroLayer() {
	auto temp = HeroLayer::create();
	temp->retain();
	return temp;
}