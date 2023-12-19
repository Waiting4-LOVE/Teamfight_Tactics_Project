#include<queue>
#include"hero.h"
#include"const.h"
#include"battleMap.h"

hero::hero() {

}

Vec2 hero::getSpritePosition() {
	return delegateSprite->getPosition();
}

float hero::calculate_distance(Sprite* d_sprite) {
	float distance;
	float my_x, my_y;//用于存我方该英雄的位置坐标
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
	//我们暂用class后的这个对象作为我们要访问的对手的数据库对象，之后建立好玩家类与AI类之后再使用新的对象
	if (database.getnum() == 0)
	{
		return { 10000,10000 };
	}
	for (int i = 0; i < database.getnum(); i++) {
		if ((t = calculate_distance(database.d_sprite[i])) < min_distance) {
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

void hero::health_recover(int health_once, int lasting) {
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

void hero::equipment_put_on(Sprite* item) {

}

void hero::equipment_take_off(Sprite* item) {

}

void hero::move(float dt) {
	Vec2 targetPosition = getEnemyPosition();
	if (targetPosition.x == 10000 && targetPosition.y == 10000)
	{
		return;
	}
	float distance = this->getPosition().distance(targetPosition);
	if (countLattice(this->getPosition(), targetPosition) > distance_attack)
	{
		this->setPosition(this->getPosition() + (targetPosition - this->getPosition()) / distance * move_speed);

	}
}

void hero::attack(float dt)
{
	if (attackTarget != NULL && !die())
	{
		float  distance = sqrt((attackTarget->getPosition().x - getPosition().x)  //获得距离
			* (attackTarget->getPosition().x - getPosition().x) +
			(attackTarget->getPosition().y - getPosition().y)
			* (attackTarget->getPosition().y - getPosition().y));
		if (distance < distance_attack)                           //小于攻击距离则开始攻击
		{
			attackTarget->dodamage(this->add_physics_attack_point);
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

bool hero::die()
{
	if (HealthPoint <= 0)
		return true;
	return false;
}