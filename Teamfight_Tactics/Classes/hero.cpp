#include"hero.h"
#include"const.h"
#include"battleMap.h"

hero* hero::createhero(string picture_name)
{
	auto hero = hero::create();
	auto temp = Sprite::create(picture_name);
	hero->addChild(temp);
	hero->autorelease();
	return hero;
}

hero::hero() 
{
	picturenum = 0;
	xtemp = x;
	ytemp = y;

	bloodBar->setBarChangeRate(Point(1, 0));
	bloodBar->setType(ProgressTimer::Type::BAR);
	bloodBar->setMidpoint(Point(0, 1));
	bloodBar->setScaleX(0.22);
    bloodBar->setScaleY(0.6);
	bloodFrame->setScaleX(0.22);
	bloodFrame->setScaleY(0.6);

	blueBar->setBarChangeRate(Point(1, 0));
	blueBar->setType(ProgressTimer::Type::BAR);
	blueBar->setMidpoint(Point(0, 1));
	blueBar->setScaleX(0.22);
	blueBar->setScaleY(0.3);
	blueFrame->setScaleX(0.22);
	blueFrame->setScaleY(0.3);

	this->scheduleUpdate();
	this->addChild(bloodFrame, 1);
	this->addChild(bloodBar, 2);
	this->addChild(blueFrame, 1);
	this->addChild(blueBar, 2);
	this->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);
}



Vec2 hero::getSpritePosition() {
	return getPosition();
}


float hero::calculateDistance(Sprite* d_sprite) {
	float distance;
	float my_x, my_y;//用于存我方该英雄的位置坐标
	float d_x, d_y;
	my_x = getPosition().x;
	my_y = getPosition().y;
	d_x = d_sprite->getPosition().x;
	d_y = d_sprite->getPosition().y;
	distance = (my_x - d_x) * (my_x - d_x) + (my_y - d_y) * (my_y - d_y);
	return distance;
}

Sprite* hero::getEnemy()
{
	return NULL;
}



Vec2 hero::getEnemyPosition() {
	float min_distance = 100000;
	float t;
	int order = 0;
	//我们暂用class后的这个对象作为我们要访问的对手的数据库对象，之后建立好玩家类与AI类之后再使用新的对象
	for (int i = 0; i < database.getnum(); i++) {
		if ((t = calculateDistance(database.d_sprite[i])) < min_distance) {
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

void hero::healthRecover(int health_once, int lasting) {
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
	blueRecoverOnce();
	skill();
	return true;
}

bool hero::blueClear() {
	if (BluePoint >= maxBluePoint) {
		BluePoint = 0;//释放技能后蓝条清零
		return 1;
	}
	else
		return 0;
}

void hero::equipmentPutOn(Sprite* item) {

}

void hero::equipmentTakeOff(Sprite* item) {

}


void hero::attack(float dt)
{
	if (attackTarget != NULL && !die())
	{
		float  distance = sqrt((attackTarget->getPosition().x - getPosition().x)  //获得距离
			* (attackTarget->getPosition().x - getPosition().x) +
			(attackTarget->getPosition().y - getPosition().y)
			* (attackTarget->getPosition().y - getPosition().y));
		if (distance < distanceAttack*oneLattice*2)                           //小于攻击距离则开始攻击
		{
			isMove = 0;
			shootbullet("1.png", attackTarget->getPosition() - this->getPosition(), this);
			blueRecoverOnce();
			skill();
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void hero::bloodUpdate(float dt)
{

	blueBar->setPosition(Vec2(0, this->_contentSize.height + 50));
	blueFrame->setPosition(Vec2(0, this->_contentSize.height + 50));
	bloodBar->setPosition(Vec2(0, this->_contentSize.height + 60));
	bloodFrame->setPosition(Vec2(0, this->_contentSize.height + 60));
	bloodBar->setPercentage(float(HealthPoint) / float(maxHealthPoint) * 100);
	bloodBar->setTag(HealthPoint);
	blueBar->setPercentage(float(BluePoint) / float(maxBluePoint) * 100);
	blueBar->setTag(BluePoint);
	
}

void hero::skill()
{
	if (blueClear() && attackTarget != NULL)
	{
		releaseSkill();
		BluePoint = 0;
	}
}

bool hero::die()
{
	if (HealthPoint <= 0) {
		setLatticeExist(positionToLattice(getPosition()), 0);
		setPosition(Point(10000, 10000));
		set(10000, 10000);
		return true;
	}
	return false;
}

void hero::releaseSkill() {

}

void hero::reset()
{
	BluePoint = originBluePoint;
	HealthPoint = maxHealthPoint;
	attackTarget = NULL;
	bloodBar->setPercentage(100.f);
	this->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1.0f / this->speedAttack);
	this->schedule(CC_SCHEDULE_SELECTOR(hero::bloodUpdate), 1 / 60.0f);

}

void hero::set(float x1 = 0, float y1 = 0)  //传入数值，有两种重载形式
{
	x = x1;
	y = y1;
}

void hero::setPlayer(int player)
{
	OfPlayer = player;
	if (player == 0)
	{

		//bloodBar->setSprite(Sprite::create("OurBlood.png"));
	}
}

void hero::shootbullet(string picturename, Point deltaPos, hero* mychess)
{
	Sprite* bullet = Sprite::create(picturename);
	this->addChild(bullet);
	bullet->setScale(0.22);
	bullet->setPosition(40, 30);

	auto move = MoveBy::create(1.f, deltaPos);
	auto back = MoveTo::create(0.f, Vec2(40, 30));
	auto appear = FadeIn::create(0.f);
	auto disappear = FadeOut::create(0.f);

	auto actionTo = Sequence::createWithTwoActions(appear, move);
	auto actionBack = Sequence::createWithTwoActions(disappear, back);
	auto all = Sequence::createWithTwoActions(actionTo, actionBack);
	bullet->runAction(Repeat::create(all, 1));
	attackTarget->doDamage(this->physicsAttackPoint);
}