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

//·µ»Ø×°±¸

bool EquipmentLayer::init() {
	return true;
}

void EquipmentLayer::update(float dt)
{
	if (MyLittleHero.haveNewEpt)
	{
		bool flag = 1;
		auto temp = (Equipment*)(MyLittleHero.m_unEquipedEpt->arr[MyLittleHero.m_unEquipedEpt->num - 1]);

	}
}



