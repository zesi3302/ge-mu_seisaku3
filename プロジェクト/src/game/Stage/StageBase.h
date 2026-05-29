#pragma once
#include <DxLib.h>


// マップの高さ
const int MAP_HIGH = 20;
// マップの横幅
const int MAP_WIDE = 20;


typedef struct {
	int m_FloorType[MAP_HIGH][MAP_WIDE];	// 床の種類
	int m_X;			// X座標
	int m_Y;			// Y座標

}FLOOR;


// マップチップの画像枚数
const int MAP_CHIP_X = 7;		// マップチップの画像枚数(横)
const int MAP_CHIP_Y = 1;		// マップチップの画像枚数(縦)
const int MAP_CHIP_SIZE = 32;	// マップチップの縦横サイズ

const int MAP_CHIP_DRAW_SIZE = 48;

// 床ブロックのサイズ
const int MAP_CHIP_HALF = (int)(MAP_CHIP_DRAW_SIZE * 0.5f);

enum MAP_CHIP_TYPE
{
	FLOOR1,

	WALL,


};

class CStageBase
{
protected:
	//FLOOR m_Floor;

	int m_FloorType[MAP_HIGH][MAP_WIDE];

public:

	void Init();
	void Load(int i);
	void Draw(const int* hndl);

public:
	void GetPosition(int& x, int& y);

	int GetFloorType(int x, int y);
};