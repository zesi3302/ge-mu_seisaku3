#include "Player.h"
//#include"../../Lib/Controll/Keyboard/key.h"
#include "../../lib/input/keyInput.h"
#include "Player.h"
#include "../data.h"
#include "../collision/collisionManager.h"

const char* PL_FILE_PATH[] = {
	"",
	""
};

void CPlayer::Init()
{
	for (int i = 0; i < PL_ANIM_NUM; i++) {
		m_Hndl[i] = -1;
	}
	/*m_Stage.GetPosition(x, y);
	m_Player.SetPosition(x, y);*/
	m_isActive = true;
	m_X = WINDOW_SENTER_X + 48 / 2;
	m_Y = 48 *18+ 48/2;
	m_State = MOVE;
}


void CPlayer::Load()
{
	for (int i = 0; i < PL_ANIM_NUM; i++) {
		m_Hndl[i] = LoadGraph(PL_FILE_PATH[i]);
	}
}


void CPlayer::Step(CStageManager& stage)
{
	switch (m_State)
	{
	case WAIT:
		break;
	case MOVE:
		if (CKeyInput::IsRep(KEY_UP))
		{
			//m_isActive = false;
			m_Direction = UP;
			if (CCollisionManager::PlayerToFloor(m_X, m_Y, m_Direction, stage)) {
				m_Y -= PLAYER_SPEED;
			}
			if (CCollisionManager::PlayerToGool(m_X, m_Y, m_Direction, stage)) {
				m_isActive = false;
			}

		}
		if (CKeyInput::IsRep(KEY_DOWN))
		{
			m_Direction = DOWN;
			if (CCollisionManager::PlayerToFloor(m_X, m_Y, m_Direction, stage)) {
				m_Y += PLAYER_SPEED;
			}
			if (CCollisionManager::PlayerToGool(m_X, m_Y, m_Direction, stage)) {
				m_isActive = false;
			}
		}
		if (CKeyInput::IsRep(KEY_LEFT))
		{
			m_Direction = LEFT;
			if (CCollisionManager::PlayerToFloor(m_X, m_Y, m_Direction, stage)) {
				m_X -= PLAYER_SPEED;
			}
			if (CCollisionManager::PlayerToGool(m_X, m_Y, m_Direction, stage)) {
				m_isActive = false;
			}
		}
		if (CKeyInput::IsRep(KEY_RIGHT))
		{
			m_Direction = RIGHT;
			if (CCollisionManager::PlayerToFloor(m_X, m_Y, m_Direction, stage)) {
				m_X += PLAYER_SPEED;
			}
			if (CCollisionManager::PlayerToGool(m_X, m_Y, m_Direction, stage)) {
				m_isActive = false;
			}
		}

		break;
	}

}


void CPlayer::Exit()
{
	for (int i = 0; i < PL_ANIM_NUM; i++) {
		if (m_Hndl[i] != -1) {
			DeleteGraph(m_Hndl[i]);
			m_Hndl[i] = -1;
		}
	}
}


void CPlayer::Draw()
{
	//if (m_isActive == false)return;
	DrawRotaGraph(m_X, m_Y, 1.0f, 0.0f, m_Hndl[0], TRUE);
	DrawCircle(m_X, m_Y, PLAYER_RADIUS, GetColor(255, 0, 0));
}

void CPlayer::GetPosition(int& x, int& y)
{
	x = m_X;
	y = m_Y;
}

void CPlayer::SetPosition(int x, int y)
{
	m_X = x;
	m_Y = y;
}

tagPlayerDirection CPlayer::GetDir()
{
	return m_Direction;
}

void CPlayer::Calc(int x, int y)
{
	m_X += x;
	m_Y += y;
}
//---------------------------
//	“–‚½‚è”»’èŒã‚Ìˆ—
//---------------------------
void CPlayer::playerHitCalc_1()
{

	m_isActive = false;
}