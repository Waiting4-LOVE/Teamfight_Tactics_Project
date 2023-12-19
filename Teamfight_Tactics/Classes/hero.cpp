#include"hero.h"
#include"const.h"

hero* hero::createhero(string picture_name)
{
	auto hero=hero::create();
	auto temp = Sprite::create(picture_name);
	hero->addChild(temp);
	hero->autorelease();
	return hero;
}

hero::hero() {

}



Vec2 hero::getSpritePosition() {
	return getPosition();
}


float hero::calculateDistance(Sprite* d_sprite) {
	float distance;
	float my_x, my_y;//���ڴ��ҷ���Ӣ�۵�λ������
	float d_x, d_y;
	my_x = getPosition().x;
	my_y = getPosition().y;
	d_x = d_sprite->getPosition().x;
	d_y = d_sprite->getPosition().y;
	distance = (my_x - d_x) * (my_x - d_x) + (my_y - d_y) * (my_y - d_y);
	return distance;
}

Sprite* hero::getEnemy() {

}



Vec2 hero::getEnemyPosition() {
	float min_distance = 100000;
	float t;
	int order = 0;
	//��������class������������Ϊ����Ҫ���ʵĶ��ֵ����ݿ����֮�������������AI��֮����ʹ���µĶ���
	for (int i = 0;i<database.getnum(); i++) {
		if ((t=calculateDistance(database.d_sprite[i])) < min_distance) {
			min_distance = t;
			order = i;
		}
	}
	return database.getVec2(database.d_sprite[order]);
}

void hero::healthRecoverOnce(int health_once) {
	if (HealthPoint + health_once <= maxHealthPoint) {
		HealthPoint += health_once;
	}
	else {
		HealthPoint = maxHealthPoint;
	}
}

void hero::healthRecover(int health_once,int lasting) {
	//this->schedule(CC_SCHEDULE_SELECTOR(hero::health_recover_once), 1.0f);
	int t;
	int t1;
	int interval;
	struct timeval now;
	gettimeofday(&now, NULL);//���ö�ʱ��
	t = now.tv_sec;
	t1 = t;//��¼�ָ�Ѫ���ĳ�ʼʱ��
	while (1) {
		interval = now.tv_sec - t;
		if (interval >= 1) {
			healthRecoverOnce(health_once);
			t = now.tv_sec;
		}
		if (now.tv_sec - t1 >= lasting) {
			break;
		}
	}
}

void hero::blueRecoverOnce() {
	if (BluePoint + blue_once <= maxBluePoint) {
		BluePoint += blue_once;
	}
	else {
		BluePoint = maxBluePoint;
	}
}

void hero::blueRocover() {

}

int hero::getHealthPoint() {
	return HealthPoint;
}

int hero::getBluePoint() {
	return BluePoint;
}

int hero::getDefencePoint() {
	return shieldPoint;
}

bool hero::doDamage(int attackpoint) {
	int extra_attack = 0;//���������һ�ι����б����ƣ��������������˺�
	if (attackpoint < 0) {

	}
	else {
		//�����ʱ��ɫ����ֵ����0
		if (shieldPoint > 0) {
			shieldPoint -= attackpoint;
			if (shieldPoint < 0) {
				extra_attack = -shieldPoint;
				shieldPoint = 0;
			}
		}
		else {
			HealthPoint -= extra_attack;
			if (HealthPoint <= 0) {
				return false;
			}
			else {
			    HealthPoint -= attackpoint;
				if (HealthPoint <= 0)
				{
					return false;
				}
				else {
					HealthPoint -= attackpoint;
				}
			}
		}
	}
	return true;
}

bool hero::blueClear() {
	if (BluePoint == maxBluePoint) {
		BluePoint = 0;//�ͷż��ܺ���������
		return 1;
	}
	else
		return 0;
}

void hero::equipmentPutOn(Sprite* item) {

}

void hero::equipmentTakeOff(Sprite* item) {

}

void hero::releaseSkill() {

}

