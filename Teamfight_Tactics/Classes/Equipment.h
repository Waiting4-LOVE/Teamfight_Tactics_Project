#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__
#include <vector>
#include <string>

class Equipment {
public:
	Equipment();
	Equipment addEquipment(int id, std::string name, std::vector<int>& v); //��ʼ��һ��װ��
	std::vector<Equipment> initEpt(); //��ʼ��װ�������ذ���ȫ��װ��������
	std::vector<int>getEptType();
	std::string getEptName();
	int getEptId();
protected:
	std::vector<int> m_eptType; //����װ���������Ͳ�����Ӧֵ�����ֵΪ0�����ʾ�޸����Լӳ�
	std::string m_eptName; //װ������
	int m_id; //װ�����
};
#endif