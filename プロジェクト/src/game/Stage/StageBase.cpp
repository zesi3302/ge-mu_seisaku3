#include "StageBase.h"

// マップデータファイルパス
const char* MAP_DATA_PATH[] = {
	"Data/Stage/stage.csv",
	"Data/Stage/stage2.csv",
	"Data/Stage/stage3.csv",
	"Data/Stage/stage4.csv",
	"Data/Stage/stage5.csv",
	"Data/Stage/stage6.csv",
	"Data/Stage/stage7.csv",
	"Data/Stage/stage8.csv",
	"Data/Stage/stage9.csv",
	"Data/Stage/stage10.csv",
};


void CStageBase::Init()
{

}

void CStageBase::Load(int i)
{


	// csvファイルからデータを読み込み
	FILE* fp;
	if (fopen_s(&fp, MAP_DATA_PATH[i], "r") != 0) return;

	// 実際のデータ取得
	// マップ縦分ループ
	for (int y = 0; y < MAP_HIGH; y++)
	{
		// マップ横分ループ
		for (int x = 0; x < MAP_WIDE; x++) {
			// データ1つ分取得
			fscanf_s(fp, "%d", &m_FloorType[y][x]);
			// カンマor改行を飛ばす
			fgetc(fp);
		}
	}

	fclose(fp);
}

void CStageBase::Draw(const int* hndl)
{
	for (int y = 0; y < MAP_HIGH; y++) {
		for (int x = 0; x < MAP_WIDE; x++) {
			int id = m_FloorType[y][x];
			if (id <= -1) break;
			if (id >= 100) {
				id = id % 100;
			}
			DrawRotaGraph(MAP_CHIP_HALF + x * MAP_CHIP_DRAW_SIZE,
				MAP_CHIP_HALF + y * MAP_CHIP_DRAW_SIZE, 1.5f, 0.0f,
				hndl[id], TRUE);
		}
	}
}

int CStageBase::GetFloorType(int x, int y)
{
	return m_FloorType[y][x];
}
