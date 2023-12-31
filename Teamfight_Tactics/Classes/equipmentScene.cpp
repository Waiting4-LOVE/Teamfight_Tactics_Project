#include "equipmentScene.h"

cocos2d::Scene* EquipmentScene::createScene()
{
	return EquipmentScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

Equipment* EquipmentScene::equipmentCreate(int select) {
	switch (select) {
		case StromSword:
			return stormSword::createStormSword();
		case CrookedBow:
			return crookedBow::createCrookedBow();
		case BoxingGloves:
			return boxingGloves::createBoxingGloves();
		case GiantBelt:
			return giantBelt::createGiantBelt();
		case Hauberk:
			return hauberk::createHauberk();
		case NegativeCape:
			return negativeCape::createNegativeCape();
		case TearsOfTheGoddess:
			return tearsOfTheGoddess::createTearsOfTheGoddess();
		case UselessStick:
			return uselessStick::createUselessStick();
	}
}

bool EquipmentScene::init() {
	if (!Scene::init()) {
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("backpage.png");
	if (sprite == nullptr)
	{
		problemLoading("'backpage.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	eptSelect();
	this->scheduleUpdate();
	return true;
}

void EquipmentScene::eptSelect() {
	this->refresh(MyLittleHero);
	//1
	auto buy1 = MenuItemImage::create(MyLittleHero.randEpt[0].picName, MyLittleHero.randEpt[0].picName, CC_CALLBACK_1(EquipmentScene::select1, this));
	auto Buy1 = Menu::create(buy1, nullptr);
	Buy1->setPosition(eptInSelectPos[0]);
	this->addChild(Buy1);
	//2
	auto buy2 = MenuItemImage::create(MyLittleHero.randEpt[1].picName, MyLittleHero.randEpt[1].picName, CC_CALLBACK_1(EquipmentScene::select2, this));
	auto Buy2 = Menu::create(buy2, nullptr);
	Buy2->setPosition(eptInSelectPos[1]);
	this->addChild(Buy2);
	//3
	auto buy3 = MenuItemImage::create(MyLittleHero.randEpt[2].picName, MyLittleHero.randEpt[2].picName, CC_CALLBACK_1(EquipmentScene::select3, this));
	auto Buy3 = Menu::create(buy3, nullptr);
	Buy3->setPosition(eptInSelectPos[2]);
	this->addChild(Buy3);
	//4
	auto buy4 = MenuItemImage::create(MyLittleHero.randEpt[3].picName, MyLittleHero.randEpt[3].picName, CC_CALLBACK_1(EquipmentScene::select4, this));
	auto Buy4 = Menu::create(buy4, nullptr);
	Buy4->setPosition(eptInSelectPos[3]);
	this->addChild(Buy4);
}

void EquipmentScene::refresh(littleHero& lh) {
	int temp = rand() % 8;
	//给四件随机装备具体信息
	for (int i = 0; i < 4; i++) {
		lh.randEpt[i].address = temp;
		lh.randEpt[i].picName = allEptInfo[temp].picName;
		lh.randEpt[i].selected = allEptInfo[temp].selected;
		temp = rand() % 8;
	}
}


void EquipmentScene::select1(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[0].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[0].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[0].selected = true;
		MyLittleHero.haveNewEpt = true;
		Director::getInstance()->popScene();
	}
}

void EquipmentScene::select2(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[1].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[1].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[1].selected = true;
		MyLittleHero.haveNewEpt = true;
		Director::getInstance()->popScene();
	}
}

void EquipmentScene::select3(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[2].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[2].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[2].selected = true;
		MyLittleHero.haveNewEpt = true;
		Director::getInstance()->popScene();
	}
}

void EquipmentScene::select4(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[3].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[3].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[3].selected = true;
		MyLittleHero.haveNewEpt = true;
		Director::getInstance()->popScene();
	}
}
