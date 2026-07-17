#include"collisionManager.h"


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

