#include "Equipment.h"
#include "Definition.h"
#include <assert.h>

Equipment::Equipment() {

}

Equipment Equipment::addEquipment(int id, std::string name, std::vector<int>& v) {
	Equipment e;
	e.m_id = id;
	e.m_eptName = name;
	e.m_eptType = v;
	return e;
}

std::vector<Equipment> Equipment::initEpt() {
	std::vector<Equipment>eptData;
	//遍历整个装备数组
	for (int i = 0; i < eptNum; i++) {
		std::vector<int>temp;
		for (int j = 1; j < eptTypeNum + 1; j++) {
			temp.push_back(eptArr[i][j]); 
		}//temp将保存装备的所有属性
		eptData.push_back(this->addEquipment(eptArr[i][0], eptName[i], temp));
	}
	return eptData;
}

std::vector<int>Equipment::getEptType() {
	return this->m_eptType;
}

std::string Equipment::getEptName() {
	return this->m_eptName;
}

int Equipment::getEptId() {
	return this->m_id;
}