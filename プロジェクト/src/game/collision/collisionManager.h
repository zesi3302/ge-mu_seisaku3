#pragma once
#include"../player/player.h"
#include"../scene/selectScene.h"

#include"../../lib/collision/collision.h"
#include"../data.h"
class CCollisionManager {
public:
	//static void CheckHitPlayerToCoin(CPlayer& player, CCoinManager& coin);
	//static void CheckhitPlayerToTrap(CPlayer& player, CTrapManager& trap);
	static bool CheckHitCursorToCharacter(CSelectScene::CHARACTER& chara);

	static bool PlayerToFloor(int x, int y, tagPlayerDirection dir, CStageManager& stage);

	static bool PlayerToGool(int x, int y, tagPlayerDirection dir, CStageManager& stage);
};