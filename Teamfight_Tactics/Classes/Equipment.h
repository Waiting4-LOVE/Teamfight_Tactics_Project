#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__
#include <vector>
#include <string>

class Equipment {
public:
	Equipment();
	Equipment addEquipment(int id, std::string name, std::vector<int>& v); //初始化一件装备
	std::vector<Equipment> initEpt(); //初始化装备并返回包含全部装备的数组
	std::vector<int>getEptType();
	std::string getEptName();
	int getEptId();
protected:
	std::vector<int> m_eptType; //根据装备属性类型查找相应值，如果值为0，则表示无该属性加成
	std::string m_eptName; //装备名称
	int m_id; //装备序号
};
#endif