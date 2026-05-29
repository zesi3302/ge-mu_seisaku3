#include "count.h"
#include <DxLib.h>



int CMaterial::m_id;
int CMaterial::m_hndl[4];

//コンストラクタ
CMaterial::CMaterial()
{
	Init();
}

//デストラクタ
CMaterial::~CMaterial()
{
	Exit();
}

//初期化
void CMaterial::Init()
{
	m_id = 0;
	for (int hndl_i = 0; hndl_i < 4; hndl_i++)
	{
		m_hndl[hndl_i] = -1;
	}
}



//終了処理
void CMaterial::Exit()
{
	for (int hndl_i = 0; hndl_i < 4; hndl_i++)
	{
		if (m_hndl[hndl_i] != -1)
		{
			DeleteGraph(m_hndl[hndl_i]);
			m_hndl[hndl_i] = -1;
		}
	}
}

