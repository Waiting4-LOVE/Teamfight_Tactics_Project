#pragma once
#include"cocos2d.h"
USING_NS_CC;


int countLattice(Vec2 lat1, Vec2 lat2);
std::pair<int, int> positionToLattice(Vec2 pos);
Vec2 latticeToPosition(std::pair<int, int> lat);
bool judgeExist(std::pair<int, int> lat);
void setLatticeExist(std::pair<int, int> lat,int exist);
extern Vec2 battleLattice[6][7];
extern Vec2 waitLattice[2][9];
extern float oneLattice;
extern bool battleLatticeExist[6][7];
extern bool waitLatticeExist[2][9];
