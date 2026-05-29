#include"collisionManager.h"

//void CCollisionManager::CheckHitPlayerToCoin(CPlayer& player,CCoinManager& coin){
//	bool isHit = false;
//	for (int i = 0;i < COIN_MAX;i++) {
//		CCoin& onecoin = coin.GetCoin(i);
//		if (!onecoin.GetActive())continue;
//		VECTOR plpos = player.GetCenter();
//		int plrad = PLAYER_SIZE;
//		VECTOR coinpos = onecoin.GetPos();
//		int coinrad = OBJECT_SIZE;
//		isHit = CCollision::CheckHitSphereToSphere(plpos, plrad, coinpos, coinrad);
//		if (isHit) {
//			onecoin.HitCalc();
//			return;
//		}
//
//	}
//}
//
//void CCollisionManager::CheckhitPlayerToTrap(CPlayer& player, CTrapManager& trap) {
//	bool isHit = false;
//	for (int i = 0;i < TRAP_MAX;i++) {
//		CTrap& onetrap = trap.GetTrap(i);
//		if (!onetrap.GetActive())continue;
//		VECTOR plpos = player.GetCenter();
//		int plrad = PLAYER_SIZE;
//		VECTOR trappos = onetrap.GetPos();
//		int traprad = OBJECT_SIZE;
//		isHit = CCollision::CheckHitSphereToSphere(plpos, plrad, trappos, traprad);
//		if (isHit) {
//			player.HitCalc();
//			return;
//		}
//
//	}
//}
bool CCollisionManager::CheckHitCursorToCharacter(CSelectScene::CHARACTER& chara) {
	bool isHit = false;
		if (!chara.m_isActive)return isHit;
		int MouseX, MouseY;

		GetMousePoint(&MouseX, &MouseY);
		isHit=CCollision::ChekHitDotToSquare(VGet(MouseX, MouseY, 0.0f), chara.m_pos, 256, 256);
		if (isHit) {
			chara.m_isSelect = true;
			return isHit;
		}
		else {
			chara.m_isSelect = false;
			return isHit;
		}


	return isHit;
}
bool CCollisionManager::PlayerToFloor(int x, int y, tagPlayerDirection dir, CStageManager& stage)
{
	int X, Y;
	X = x / MAP_CHIP_DRAW_SIZE;
	Y = y / MAP_CHIP_DRAW_SIZE;

	CStageBase ste = stage.GetStageData();

	int up = Y - 1;
	int down = Y + 1;
	int left = X - 1;
	int right = X + 1;

	int half = MAP_CHIP_DRAW_SIZE / 2;

	switch (dir)
	{
	case UP:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(X * MAP_CHIP_DRAW_SIZE + half, up * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			// °‚ÌŽí—Þ‚ª1‚¾‚Á‚½‚ç“®‚¯‚é
			int type = ste.GetFloorType(X, Y - 1);
			type = type % 100;
			if (type != 0 && type != 2) {
				return false;
			}
		}

		break;
	case DOWN:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(X * MAP_CHIP_DRAW_SIZE + half, down * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X, Y + 1);
			type = type % 100;
			if (type != 0 && type != 3) {
				return false;
			}
		}

		break;
	case LEFT:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(left * MAP_CHIP_DRAW_SIZE + half, Y * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X - 1, Y);
			type = type % 100;
			if (type != 0 && type != 4) {
				return false;
			}
		}

		break;
	case RIGHT:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(right * MAP_CHIP_DRAW_SIZE + half, Y * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X + 1, Y);
			type = type % 100;
			if (type != 0 && type != 5) {
				return false;
			}
		}

		break;
	}

	return true;
}
bool CCollisionManager::PlayerToGool(int x, int y, tagPlayerDirection dir, CStageManager& stage)
{
	int X, Y;
	X = x / MAP_CHIP_DRAW_SIZE;
	Y = y / MAP_CHIP_DRAW_SIZE;

	CStageBase ste = stage.GetStageData();

	int up = Y - 1;
	int down = Y + 1;
	int left = X - 1;
	int right = X + 1;

	int half = MAP_CHIP_DRAW_SIZE / 2;

	switch (dir)
	{
	case UP:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(X * MAP_CHIP_DRAW_SIZE + half, up * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			// °‚ÌŽí—Þ‚ª1‚¾‚Á‚½‚ç“®‚¯‚é
			int type = ste.GetFloorType(X, Y - 1);
			type = type % 100;
			if (type == 6) {
				return true;
			}
		}

		break;
	case DOWN:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(X * MAP_CHIP_DRAW_SIZE + half, down * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X, Y + 1);
			type = type % 100;
			if (type == 6) {
				return true;
			}
		}

		break;
	case LEFT:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(left * MAP_CHIP_DRAW_SIZE + half, Y * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X - 1, Y);
			type = type % 100;
			if (type == 6) {
				return true;
			}
		}

		break;
	case RIGHT:
		if (CCollision::SquareToSquare(VGet(x, y, 0.0f), PLAYER_RADIUS, PLAYER_RADIUS,
			VGet(right * MAP_CHIP_DRAW_SIZE + half, Y * MAP_CHIP_DRAW_SIZE + half, 0.0f), MAP_CHIP_DRAW_SIZE, MAP_CHIP_DRAW_SIZE)) {
			int type = ste.GetFloorType(X + 1, Y);
			type = type % 100;
			if (type == 6) {
				return true;
			}
		}

		break;
	}
	return false;
	//return true;
}