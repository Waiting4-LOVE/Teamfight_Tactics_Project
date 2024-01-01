#include"equipmentLayer.h"

EquipmentLayer* EquipmentLayer::createSelectLayer() {
	auto temp = EquipmentLayer::create();
	temp->retain();
	return temp;
}

static void problemLoading(const char* filename) {
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

std::string getType(int address) {
	switch (address) {
		case 0:
			return "stormSword";
		case 1:
			return "crookedBow";
		case 2:
			return "boxingGloves";
		case 3:
			return "giantBelt";
		case 4:
			return "hauberk";
		case 5:
			return "negativeCape";
		case 6:
			return "tearsOfTheGoddess";
		case 7:
			return "uselessStick";
	}
}

bool EquipmentLayer::init() {
	this->refresh(MyLittleHero);
	//1
	auto buy1 = MenuItemImage::create(MyLittleHero.randEpt[0].picName, MyLittleHero.randEpt[0].picName, CC_CALLBACK_1(EquipmentLayer::select1, this));
	auto Buy1 = Menu::create(buy1, nullptr);
	Buy1->setPosition(eptInSelectPos[0]);
	this->addChild(Buy1, 1);
	//2
	auto buy2 = MenuItemImage::create(MyLittleHero.randEpt[1].picName, MyLittleHero.randEpt[1].picName, CC_CALLBACK_1(EquipmentLayer::select2, this));
	auto Buy2 = Menu::create(buy2, nullptr);
	Buy2->setPosition(eptInSelectPos[1]);
	this->addChild(Buy2, 1);
	//3
	auto buy3 = MenuItemImage::create(MyLittleHero.randEpt[2].picName, MyLittleHero.randEpt[2].picName, CC_CALLBACK_1(EquipmentLayer::select3, this));
	auto Buy3 = Menu::create(buy3, nullptr);
	Buy3->setPosition(eptInSelectPos[2]);
	this->addChild(Buy3, 1);
	//4
	auto buy4 = MenuItemImage::create(MyLittleHero.randEpt[3].picName, MyLittleHero.randEpt[3].picName, CC_CALLBACK_1(EquipmentLayer::select4, this));
	auto Buy4 = Menu::create(buy4, nullptr);
	Buy4->setPosition(eptInSelectPos[3]);
	this->addChild(Buy4, 1);
	return true;
}

Equipment* EquipmentLayer::equipmentCreate(int select) {
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

void EquipmentLayer::eptSelect() {
	this->refresh(MyLittleHero);
	//1
	auto buy1 = MenuItemImage::create(MyLittleHero.randEpt[0].picName, MyLittleHero.randEpt[0].picName, CC_CALLBACK_1(EquipmentLayer::select1, this));
	auto Buy1 = Menu::create(buy1, nullptr);
	Buy1->setPosition(eptInSelectPos[0]);
	this->addChild(Buy1);
	//2
	auto buy2 = MenuItemImage::create(MyLittleHero.randEpt[1].picName, MyLittleHero.randEpt[1].picName, CC_CALLBACK_1(EquipmentLayer::select2, this));
	auto Buy2 = Menu::create(buy2, nullptr);
	Buy2->setPosition(eptInSelectPos[1]);
	this->addChild(Buy2);
	//3
	auto buy3 = MenuItemImage::create(MyLittleHero.randEpt[2].picName, MyLittleHero.randEpt[2].picName, CC_CALLBACK_1(EquipmentLayer::select3, this));
	auto Buy3 = Menu::create(buy3, nullptr);
	Buy3->setPosition(eptInSelectPos[2]);
	this->addChild(Buy3);
	//4
	auto buy4 = MenuItemImage::create(MyLittleHero.randEpt[3].picName, MyLittleHero.randEpt[3].picName, CC_CALLBACK_1(EquipmentLayer::select4, this));
	auto Buy4 = Menu::create(buy4, nullptr);
	Buy4->setPosition(eptInSelectPos[3]);
	this->addChild(Buy4);
}

void EquipmentLayer::refresh(littleHero& lh) {
	int temp = rand() % 8;
	//给四件随机装备具体信息
	for (int i = 0; i < 4; i++) {
		lh.randEpt[i].address = temp;
		lh.randEpt[i].picName = allEptInfo[temp].picName;
		lh.randEpt[i].selected = allEptInfo[temp].selected;
		temp = rand() % 8;
	}
}

void EquipmentLayer::select1(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[0].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[0].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[0].selected = true;
		MyLittleHero.haveNewEpt = true;

		if (MyLittleHero.m_unEquipedEpt->num + MyLittleHero.m_equipment->num <= 5) {
			std::string name = "Get an equipment: ";
			name += getType(MyLittleHero.randEpt[0].address);
			auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 40);
			label->setTextColor(Color4B::WHITE);
			label->setPosition(1600, 900);
			auto move = FadeOut::create(3.0f);
			label->runAction(move);
			this->addChild(label, 1);
		}
	}
}

void EquipmentLayer::select2(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[1].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[1].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[1].selected = true;
		MyLittleHero.haveNewEpt = true;

		if (MyLittleHero.m_unEquipedEpt->num + MyLittleHero.m_equipment->num <= 5) {
			std::string name = "Get an equipment: ";
			name += getType(MyLittleHero.randEpt[1].address);
			auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 40);
			label->setTextColor(Color4B::WHITE);
			label->setPosition(1600, 900);
			auto move = FadeOut::create(3.0f);
			label->runAction(move);
			this->addChild(label, 1);
		}
	}
}

void EquipmentLayer::select3(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[2].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[2].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[2].selected = true;
		MyLittleHero.haveNewEpt = true;

		if (MyLittleHero.m_unEquipedEpt->num + MyLittleHero.m_equipment->num <= 5) {
			std::string name = "Get an equipment: ";
			name += getType(MyLittleHero.randEpt[2].address);
			auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 40);
			label->setTextColor(Color4B::WHITE);
			label->setPosition(1600, 900);
			auto move = FadeOut::create(3.0f);
			label->runAction(move);
			this->addChild(label, 1);
		}
	}
}

void EquipmentLayer::select4(cocos2d::Ref* pSender) {
	if (MyLittleHero.randEpt[3].selected == false) {
		auto sprite = equipmentCreate(MyLittleHero.randEpt[3].address);
		ccArrayAppendObject(MyLittleHero.m_unEquipedEpt, sprite);
		MyLittleHero.randEpt[3].selected = true;
		MyLittleHero.haveNewEpt = true;

		if (MyLittleHero.m_unEquipedEpt->num + MyLittleHero.m_equipment->num <= 5) {
			std::string name = "Get an equipment: ";
			name += getType(MyLittleHero.randEpt[3].address);
			auto label = Label::createWithTTF(name, "fonts/Marker Felt.ttf", 40);
			label->setTextColor(Color4B::WHITE);
			label->setPosition(1600, 900);
			auto move = FadeOut::create(3.0f);
			label->runAction(move);
			this->addChild(label, 1);
		}
	}
}
