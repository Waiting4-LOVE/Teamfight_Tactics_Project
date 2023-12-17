#include"hero.h"
#include"const.h"

int hero::HealthPoint = heroConsts::max_health_point;
int hero::BluePoint = heroConsts::max_blue_point;

hero::hero() {

}

Vec2 hero::getSpritePosition() {
	return delegateSprite->getPosition();
}

float hero::calculate_distance(Sprite* d_sprite) {
	float distance;
	float my_x, my_y;//���ڴ��ҷ���Ӣ�۵�λ������
	float d_x, d_y;
	my_x = delegateSprite->getPosition().x;
	my_y = delegateSprite->getPosition().y;
	d_x = d_sprite->getPosition().x;
	d_y = d_sprite->getPosition().y;
	distance = (my_x - d_x) * (my_x - d_x) + (my_y - d_y) * (my_y - d_y);
	return distance;
}

Vec2 hero::getEnemyPosition() {
	float min_distance = 100000;
	float t;
	int order = 0;
	//��������class������������Ϊ����Ҫ���ʵĶ��ֵ����ݿ����֮�������������AI��֮����ʹ���µĶ���
	for (int i = 0;i<database.getnum(); i++) {
		if ((t=calculate_distance(database.d_sprite[i])) < min_distance) {
			min_distance = t;
			order = i;
		}
	}
	return database.getVec2(database.d_sprite[order]);
}

void hero::health_recover_once(int health_once) {
	if (HealthPoint + health_once <= max_healthpoint) {
		HealthPoint += health_once;
	}
	else {
		HealthPoint = max_healthpoint;
	}
}

void hero::health_recover(int health_once,int lasting) {
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
			health_recover_once(health_once);
			t = now.tv_sec;
		}
		if (now.tv_sec - t1 >= lasting) {
			break;
		}
	}
}

void hero::blue_recover_once() {
	if (BluePoint + blue_once <= max_bluepoint) {
		BluePoint += blue_once;
	}
	else {
		BluePoint = max_bluepoint;
	}
}

void hero::blue_rocover() {

}

int hero::get_HealthPoint() {
	return HealthPoint;
}

int hero::get_BluePoint() {
	return BluePoint;
}

int hero::get_DefencePoint() {
	return shieldPoint;
}

bool hero::dodamage(int attackpoint) {
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

bool hero::skill_release() {
	if (BluePoint == max_bluepoint) {
		BluePoint = 0;//�ͷż��ܺ���������
		return 1;
	}
	else
		return 0;
}

void hero::equipment_put_on(Sprite* item) {

}

void hero::equipment_take_off(Sprite* item) {

}

