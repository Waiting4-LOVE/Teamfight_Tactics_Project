#include"hero.h"
#include"const.h"


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

	this->addChild(Star, 1);
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
	float my_x, my_y;//���ڴ��ҷ���Ӣ�۵�λ������
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
	//��������class������������Ϊ����Ҫ���ʵĶ��ֵ����ݿ����֮�������������AI��֮����ʹ���µĶ���
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
	blueRecoverOnce();
	skill();
	return true;
}

bool hero::blueClear() {
	if (BluePoint >= maxBluePoint) {
		BluePoint = 0;//�ͷż��ܺ���������
		return 1;
	}
	else
		return 0;
}

void hero::EquipmentChange() {
	for (int i = 0; i < equipment->num; i++)
	{
		auto equ = (Equipment*)equipment->arr[i];
		this->EquipToChess(equ);
	}
}

void hero::EquipToChess(Equipment* equ)
{
	this->maxHealthPoint += equ->getaddHealthLimit();
	HealthPoint = maxHealthPoint;

	this->speedAttack += equ->getaddAttackSpeed();
	this->schedule(CC_SCHEDULE_SELECTOR(hero::attack), 1 / this->speedAttack);

	this->physicsAttackPoint += equ->getaddDamage();
	this->distanceAttack += equ->getaddAttackDistance();
	this->defencePhysics += equ->getaddPhysicalArmor();
	this->defenceMagic += equ->getaddMagicalArmor();
	this->maxBluePoint += equ->getaddBlueLimit();
	this->magicPoint += equ->getaddMagic();
	this->criticalChance += equ->getcriticalHit();
}


void hero::attack(float dt)
{
	if (attackTarget != NULL && !die())
	{
		float  distance = sqrt((attackTarget->getPosition().x - getPosition().x)  //��þ���
			* (attackTarget->getPosition().x - getPosition().x) +
			(attackTarget->getPosition().y - getPosition().y)
			* (attackTarget->getPosition().y - getPosition().y));
		if (distance < distanceAttack*oneLattice*2)                           //С�ڹ���������ʼ����
		{
			isMove = 0;
			shootbullet("redlight.png", attackTarget->getPosition() - this->getPosition(), this);
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
	Star->setPosition(Vec2(85, 50));
	Star->setString(to_string(star));
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

void hero::set(float x1 = 0, float y1 = 0)  //������ֵ��������������ʽ
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
	bullet->setScale(1);
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