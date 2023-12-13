#include"hero.h"
#include"const.h"

int hero::HealthPoint = heroConsts::max_health_point;
int hero::BluePoint = heroConsts::max_blue_point;

hero::hero() {

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

Vec2 hero::getSpritePosition() {
	return delegateSprite->getPosition();
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

bool hero::in_attack_range() {

}


