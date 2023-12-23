#include"hero.h"
#include"const.h"
#include"battleMap.h"
USING_NS_CC;
hero* hero::createhero(string picture_name)
{
	auto hero = hero::create();
	auto temp = Sprite::create(picture_name);
	hero->addChild(temp);
	hero->autorelease();
	return hero;
}

hero::hero() {
	this->addChild(bloodFrame, 1);
	this->addChild(bloodBar, 2);
	this->addChild(blueFrame, 1);
	this->addChild(blueBar, 2);
	this->schedule(CC_SCHEDULE_SELECTOR(bloodUpdate), 1 / 60.0f);
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

void hero::move(float dt) {
	Vec2 targetPosition = getEnemyPosition();
	if (targetPosition.x == 10000 && targetPosition.y == 10000)
	{
		return;
	}
	float distance = this->getPosition().distance(targetPosition);
	if (countLattice(this->getPosition(), targetPosition) > distanceAttack)
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
		if (distance < distanceAttack)                           //小于攻击距离则开始攻击
		{
			blueRecoverOnce();
			skill();
			attackTarget->doDamage(this->addPhysicsAttackPoint);
			if (attackTarget->die())
			{
				attackTarget = NULL;
			}
		}
	}
}

void hero::bloodUpdate(float dt)
{
	float heroX = this->getPosition().x, heroY = this->getPosition().y;
	bloodBar->setPosition(heroX, heroY + oneLattice);
	bloodFrame->setPosition(heroX, heroY + oneLattice);
	blueBar->setPosition(heroX, heroY + oneLattice - (bloodFrame->getContentSize().height + blueFrame->getContentSize().height) / 2);
	blueFrame->setPosition(heroX, heroY + oneLattice - (bloodFrame->getContentSize().height + blueFrame->getContentSize().height) / 2);

	bloodBar->setPercentage(100.0f * HealthPoint / maxHealthPoint);
	//Blood->setTag(Health);
	blueBar->setPercentage(100.0f * BluePoint / maxBluePoint);
	//_Mana->setTag(Mana);
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
	if (HealthPoint <= 0)
		return true;
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
	this->schedule(CC_SCHEDULE_SELECTOR(attack), 1.0f / this->speedAttack);
	this->schedule(CC_SCHEDULE_SELECTOR(move), 1 / 60.0f);
	this->schedule(CC_SCHEDULE_SELECTOR(bloodUpdate), 1 / 60.0f);
}
/*
static void onMouseDown(Event* event, bool& isDragging, Vec2& startDragPos)
{
	EventMouse* e = dynamic_cast<EventMouse*>(event);
	if (e->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT) {
		isDragging = true;
		startDragPos = Vec2(e->getCursorX(), e->getCursorY());
	}
}

static void onMouseMove(Event* event, bool isDragging, Vec2& startDragPos, hero* herocase)
{
	EventMouse* e = dynamic_cast<EventMouse*>(event);
	if (isDragging) {
		Vec2 currentPos = Vec2(e->getCursorX(), e->getCursorY());
		Vec2 delta = currentPos - startDragPos;
		herocase->setPosition(herocase->getPosition() + delta);
		startDragPos = currentPos;
	}
}

static void onMouseUp(Event* event, bool& isDragging, std::pair<int, int> firstLatPos, hero* herocase)
{
	isDragging = false;
	std::pair<int, int> lastLatPos = positionToLattice(herocase->getPosition());
	if (lastLatPos == (std::pair<int, int>{-1, -1}) || judgeExist(lastLatPos))
		lastLatPos = firstLatPos;
	else
		herocase->setPosition(latticeToPosition(lastLatPos));
}

void hero::beMoved()
{
	bool isDragging = false;
	Vec2 startDragPos;
	std::pair<int, int> firstLatPos = this->getLatPos();
	auto listener = EventListenerMouse::create();

	listener->onMouseDown = CC_CALLBACK_1(onMouseDown, this, std::ref(isDragging), std::ref(startDragPos));

	listener->onMouseMove = CC_CALLBACK_1(onMouseMove, this, isDragging, std::ref(startDragPos), this);

	listener->onMouseUp = CC_CALLBACK_1(onMouseUp, this, std::ref(isDragging), firstLatPos, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
*/