#include<cocos2d.h>
using namespace cocos2d;
using namespace heroConsts;

class hero:public Node
{
private:

public:
	hero();
	static int get_sHealthPoint();//����Ӣ�����ڵ�Ѫ��
	static int get_sBluePoint();//����Ӣ�����ڵ�����
	static int get_sDefencePoint();//����Ӣ�����ڵĻ���
	void health_recover();//��Ѫ����
protected:
	int sActorType;//Ӣ������
	static int sHealthPoint;//Ѫ��
	static int sBluePoint;//����
	static int sDefencePoint;//����
};