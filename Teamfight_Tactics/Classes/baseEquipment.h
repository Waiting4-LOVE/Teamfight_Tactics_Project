#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__
#include <vector>
#include <string>

enum EquipmentType {
	physical_attack, //������
	spell_attack, //��������
	physical_defence, //�￹
	spell_defence, //ħ��
	attack_speed, //����
	blue_heal, //����
	blood_heal, //��Ѫ
	critical_hit, //����
	max_blood, //����Ѫ������
	shovel, //�����
	add_hero //������һ��Ӣ��
};

struct epItem {
	std::vector<EquipmentType> ept; //���װ������
	std::string epname;
	int id; //װ�����
};

class baseEquipment {
public:

};

#endif