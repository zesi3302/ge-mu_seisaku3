#include "count.h"
#include <DxLib.h>

static const char* GRAHICS_PATH[8] =
{
	"data/model/player/playerBody.png",
	"data/model/player/playerBody2.png",
	"data/model/player/playerBody3.png",
	"data/model/player/playerBody4.png",

};
int CCount::m_setid;
int CCount::m_id;
int CCount::m_hndl[8];

//コンストラクタ
CCount::CCount()
{
	Init();
}

//デストラクタ
CCount::~CCount()
{
	Exit();
}

//初期化
void CCount::Init()
{
	m_id = 0;
	m_setid = 0;
	for (int hndl_i = 0; hndl_i < 8; hndl_i++)
	{
		m_hndl[hndl_i] = -1;
	}
}

//ロード
void CCount::Load()
{
	for (int hndl_i = 0; hndl_i < 8; hndl_i++)
	{
		if (m_hndl[hndl_i] == -1)
		{
			m_hndl[hndl_i] = LoadGraph(GRAHICS_PATH[hndl_i]);
		}
	}
}

//終了処理
void CCount::Exit()
{
	for (int hndl_i = 0; hndl_i < 8; hndl_i++)
	{
		if (m_hndl[hndl_i] != -1)
		{
			DeleteGraph(m_hndl[hndl_i]);
			m_hndl[hndl_i] = -1;
		}
	}
}
