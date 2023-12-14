#include"hero.h"
#include"const.h"

int hero::sHealthPoint = heroConsts::max_health_point;
int hero::sBluePoint = heroConsts::max_blue_point;


hero::hero() {
	sActorType = at_null;
}

void hero::health_recover() {
	
}

int hero::get_sHealthPoint() {
	return sHealthPoint;
}

int hero::get_sBluePoint() {
	return sBluePoint;
}

int hero::get_sDefencePoint() {
	return sDefencePoint;
}