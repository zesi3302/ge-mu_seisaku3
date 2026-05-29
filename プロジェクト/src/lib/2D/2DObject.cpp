#include"2DObject.h"

using namespace std;

//---------------------------
//	コンストラクタ
//---------------------------
C2DObject::C2DObject()
{
	Init();
}

//---------------------------
//	デストラクタ
//---------------------------
C2DObject::~C2DObject()
{
	Exit();
}

//---------------------------
//	初期化
//---------------------------
void C2DObject::Init(VECTOR _pos, float _rot)
{
	m_pos = _pos;
	m_rot = _rot;
	m_isActive = true;
	m_animData.m_frame = 0;
	m_animData.m_timeCount = 0;
	m_animData.m_speed = 0;
	m_animData.m_animId = 0;
	m_animData.m_animLoop = false;
}

//---------------------------
//	ロード (直接画像をロードする用)
//---------------------------
void C2DObject::Load(const char* _hndlPath)
{
	vector<int> hndl;

	hndl.push_back(LoadGraph(_hndlPath));

	m_hndl.push_back(hndl);
}

//---------------------------
//	ロード(中身でロードする用)
//---------------------------
void C2DObject::Load()
{

}

//---------------------------
//	毎フレームする処理
//---------------------------
void C2DObject::Step()
{
	if (m_hndl[m_animData.m_animId].size() > m_animData.m_frame)
	{
		m_animData.m_timeCount++;

		if (m_animData.m_speed >= m_animData.m_timeCount)
		{
			m_animData.m_frame++;
			m_animData.m_timeCount = 0;
		}
	}
	else if (m_animData.m_animLoop == true)
	{
		m_animData.m_frame = 0;
	}
}

//---------------------------
//			描写
//---------------------------
void C2DObject::Draw(float _size)
{
	if (m_isActive == false ||
		m_hndl.size() == 0)return;

	DrawRotaGraph((int)m_pos.x, (int)m_pos.y, _size, m_rot, m_hndl[m_animData.m_animId][m_animData.m_frame], TRUE);

}

//---------------------------
//			破棄
//---------------------------
void C2DObject::Exit()
{
	for (int animNum_i = 0; animNum_i < m_hndl.size(); animNum_i++)
	{
		for (int hndl_i = 0; hndl_i < m_hndl[animNum_i].size(); hndl_i++)
		{
			if (m_hndl[animNum_i][hndl_i] != -1)
			{
				DeleteGraph(m_hndl[animNum_i][hndl_i]);
				m_hndl[animNum_i][hndl_i] = -1;
			}
		}
	}
	m_hndl.clear();
}

//---------------------------
//	当たり判定後の処理
//---------------------------
void C2DObject::HitCalc()
{

}

//---------------------------
//	画像をロードする関数
//---------------------------
void C2DObject::LoadGraphic(const char* _hndlPath, int _allNum, int _sizeX, int _sizeY)
{
	//ハンドルが空なら処理をしない
	if (_hndlPath != nullptr)return;

	vector<int> hndl;

	//一枚以上ある場合
	if (_allNum != 1)
	{
		hndl.push_back(LoadGraph(_hndlPath));

	}
	else
	{

		for (int hndl_i = 0; hndl_i < _allNum; hndl_i++)
		{
			hndl.push_back(-1);
		}

		LoadDivGraph(_hndlPath, _allNum, _allNum , 1, _sizeX, _sizeY, &hndl[0]);

	}
	m_hndl.push_back(hndl);
}

//---------------------------
//画像のアニメーションを呼び出し
//---------------------------
void C2DObject::RequestAnim(int _animId, int _animSpeed, bool _isLoop)
{
	//現在のアニメーションに存在しない場合は処理をしない
	if (m_hndl.size() < _animId)return;

	m_animData.m_animId = _animId;
	m_animData.m_timeCount = 0;
	m_animData.m_frame = 0;
	m_animData.m_speed = _animSpeed;
	m_animData.m_animLoop = _isLoop;
}

