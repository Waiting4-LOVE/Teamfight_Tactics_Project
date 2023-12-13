#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__
#include <vector>
#include <string>

enum EquipmentType {
	physical_attack, //物理攻击
	spell_attack, //法术攻击
	physical_defence, //物抗
	spell_defence, //魔抗
	attack_speed, //攻速
	blue_heal, //回蓝
	blood_heal, //回血
	critical_hit, //暴击
	max_blood, //增加血量上限
	shovel, //金铲铲
	add_hero //额外上一个英雄
};

struct epItem {
	std::vector<EquipmentType> ept; //存放装备属性
	std::string epname;
	int id; //装备序号
};

class baseEquipment {
public:

};

#endif