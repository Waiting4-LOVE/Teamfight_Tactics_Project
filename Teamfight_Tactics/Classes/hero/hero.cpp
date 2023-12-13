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
	gettimeofday(&now, NULL);//调用定时器
	t = now.tv_sec;
	t1 = t;//记录恢复血量的初始时间
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
	int extra_attack = 0;//如果护盾在一次攻击中被击破，来计算多余出的伤害
	if (attackpoint < 0) {

	}
	else {
		//如果此时角色护盾值大于0
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
		BluePoint = 0;//释放技能后蓝条清零
		return 1;
	}
	else
		return 0;
}

bool hero::in_attack_range() {

}


