#pragma once
#include <DxLib.h>
#include <vector>
#include "StageBase.h"

using namespace std;

// マップの種類
enum tagMapNumber
{
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6,
	STAGE7,
	STAGE8,
	STAGE9,
	STAGE10,

	NUM			// マップの数
};


const char MAP_CHIP_PATH[] = { "data/Graphic/maptip.png" };

// マップチップの枚数
const int MAP_CHIP_NUM = MAP_CHIP_X * MAP_CHIP_Y;

class CStageManager
{
private:
	int randamu;

	// マップチップの画像
	int m_ChipHndl[MAP_CHIP_NUM];

	tagMapNumber m_MapState;

	vector<CStageBase> m_Stage;

public:
	CStageManager();

	void Init();
	void Load();
	void Step(int& x, int& y, int dir);
	void Exit();
	void Draw();

public:
	CStageBase GetStageData();
private:
	void MapChange(int& x, int& y, int dir);

	void GetMapStartPoint(tagMapNumber nowMap, tagMapNumber nextMap, int& x, int& y);
};