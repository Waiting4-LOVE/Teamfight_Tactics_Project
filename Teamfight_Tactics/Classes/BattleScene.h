/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#pragma once
#ifndef __BATTLE_SCENE_H__
#define __BATTLE_SCENE_H__

#include "cocos2d.h"
#include "Maplayer.h"
#include "RoundTimer.h"
#include "LittleHeroLayer.h"
#include "GameData.h"
#include "HeroLayer.h"
class BattleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	// a selector callback
	//void GotoGamescene(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
private:
	/**********��ʱ����Update**************/
	RoundTimer* timer = RoundTimer::create(10);
	void update(float dt);
	void TurnInfoInit();


	//��ս������ƶ�����
	void ChessMoveInMouse();
	void onMouseScroll(Event* event);
	void onMouseMove(Event* event);
	void onMouseUp(Event* event);
	void onMouseDown(Event* event);
	void GameStartMouseInit();
	//Point MapJudge(Point point);//�ж�����Ƿ��ڵ�ͼ��
	int MouseToChess = -1;//���ָ�������

	//���Ϻ���
	bool FindMouseTarget(ccArray* Array, EventMouse* e);
	void soldHero(hero* temp, ccArray* Array, littleHero& playerdata);

	void BattleScene::addChess(littleHero& littlehero, int playerinfo);


	void Win();  //�жϴ򶷽���
	/* void JudgeWin(PlayerData& playerdata, int sum[]);
	 void WinRetain(ccArray* Array);

	 void ToFightArray(Chess* chess, PlayerData& playerdata);
	 */
	 /***********������Layer************/
	void BattleScene::ArrayToArray(hero* chess, ccArray* arrayFrom, ccArray* arrayTo);
	MapLayer* map = MapLayer::createMapLayer();
	LittleHeroLayer* littleLayer = LittleHeroLayer::createPlayer();
	HeroLayer* heroLayer = HeroLayer::createHeroLayer();

	int turn = 0;
	/*װ��ϵͳ*/
   /* Package* layerPackage = Package::createPackage();
	bool EquipSearchChess(const float EquipX, const float EquipY, const int EquipIndex);
	int MouseSelectedEquip = -1;*/

	CREATE_FUNC(BattleScene);

};

#endif // __BATTLE_SCENE_H__
