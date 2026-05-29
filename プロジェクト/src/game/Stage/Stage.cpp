#include "Stage.h"
#include "../player/count.h"

CStageManager::CStageManager()
{
	m_MapState = STAGE1;
}

void CStageManager::Init()
{
	randamu = (GetRand(4));

	//m_Stage.resize(tagMapNumber::NUM);
	m_Stage.clear();

	for (int i = 0; i < tagMapNumber::NUM; i++) {
		CStageBase base;
		m_Stage.push_back(base);
	}

	for (int i = 0; i < MAP_CHIP_NUM; i++) {
		m_ChipHndl[i] = -1;
	}


	m_MapState = STAGE1;
}

void CStageManager::Load()
{
	switch (CMaterial::Getid())
	{
	case 0: {
		m_MapState = STAGE1;
		break;
	}
	case 1: {
		m_MapState = STAGE2;
		break;
	}
	case 2: {
		m_MapState = STAGE3;
		break;
	}
	case 3: {
		m_MapState = STAGE4;
		break;
	}
	case 4: {
		m_MapState = STAGE5;
		break;
	}
	case 5: {
		m_MapState = STAGE6;
		break;
	}
	case 6: {
		m_MapState = STAGE7;
		break;
	}
	case 7: {
		m_MapState = STAGE8;
		break;
	}
	default:
		break;
	}

	// マップチップの読み込み
	int res = LoadDivGraph(MAP_CHIP_PATH, MAP_CHIP_X * MAP_CHIP_Y,
		MAP_CHIP_X, MAP_CHIP_Y, MAP_CHIP_SIZE, MAP_CHIP_SIZE,
		m_ChipHndl);

	res;

	// マップデータの読み込み
	for (int i = 0; i < (int)tagMapNumber::NUM; i++) {
		m_Stage[i].Load(i);
	}

}

void CStageManager::Step(int& x, int& y, int dir)
{
	enum PLAYER_DIR
	{
		up,
		down,
		left,
		right,
	};

	int X, Y, type;
	X = x / MAP_CHIP_DRAW_SIZE;
	Y = y / MAP_CHIP_DRAW_SIZE;

	MapChange(x, y, dir);


}

void CStageManager::Exit()
{
}

void CStageManager::Draw()
{
	if (m_Stage.size() <= 1) return;
	m_Stage[m_MapState].Draw(m_ChipHndl);
}

CStageBase CStageManager::GetStageData()
{
	return m_Stage[m_MapState];
}

void CStageManager::MapChange(int& x, int& y, int dir)
{
	int type = -1;
	int X = x / MAP_CHIP_DRAW_SIZE;
	int Y = y / MAP_CHIP_DRAW_SIZE;

	switch (dir)
	{
		// 上
	case 0:
		type = m_Stage[m_MapState].GetFloorType(X, Y - 1);
		break;
		// 下
	case 1:
		type = m_Stage[m_MapState].GetFloorType(X, Y + 1);
		break;
		// 左
	case 2:
		type = m_Stage[m_MapState].GetFloorType(X - 1, Y);
		break;
		// 右
	case 3:
		type = m_Stage[m_MapState].GetFloorType(X + 1, Y);
		break;
	}
	if (type >= 10000) {
		// 10000で割った数を次の部屋数とする
		type = type / 10000;
		GetMapStartPoint(m_MapState, (tagMapNumber)(type - 1), x, y);
		m_MapState = (tagMapNumber)(type - 1);
	}
}

void CStageManager::GetMapStartPoint(tagMapNumber nowMap, tagMapNumber nextMap, int& x, int& y)
{
	for (int X = 0; X < MAP_HIGH; X++) {
		for (int Y = 0; Y < MAP_WIDE; Y++) {
			int type = m_Stage[nextMap].GetFloorType(X, Y);
			if (type >= 10000) {
				if (type / 10000 == (int)nowMap + 1) {
					x = X * MAP_CHIP_DRAW_SIZE + MAP_CHIP_HALF;
					y = Y * MAP_CHIP_DRAW_SIZE + MAP_CHIP_HALF;
					return;
				}
			}
		}
	}

}
