#include "resultScene.h"
#include "../data.h"
#include "../../lib/input/keyInput.h"
#include "../sound/soundManager.h"

//定義関連====================================
//============================================

//---------------------------
//コンストラクタ
//---------------------------
CResultScene::CResultScene() {
	//最初はデータ初期化
	m_state = INIT;
	Init();
}

//---------------------------
//デストラクタ
//---------------------------
CResultScene::~CResultScene() {
	//安全のためにデータ破棄処理を呼び出し
	Exit();
}


//---------------------------
//描画処理
//---------------------------
void CResultScene::Draw()
{
	DrawFormatString(32, 32, GetColor(255, 0, 0), "タイトル");
	DrawRotaGraph(m_pos.x, m_pos.y, 0.9, 0.0, m_hndl, TRUE);

}

//---------------------------
//初期化
//---------------------------
void CResultScene::Init()
{
	m_hndl = -1;
	m_pos.x = WINDOW_SENTER_X;
	m_pos.y = WINDOW_SENTER_Y;
}

//---------------------------
//データ読み込み
//---------------------------
void CResultScene::Load()
{
	CSoundManager::Play(CSoundManager::BGM_RESULT, DX_PLAYTYPE_LOOP);
	m_hndl = LoadGraph("data/graphic/Image (29).jpg");

}

//---------------------------
//メイン処理
//---------------------------
void CResultScene::Step()
{
	//スペースで終わる
	if (CKeyInput::IsTrg(KEY_SELECT))
	{
		m_result = 0;
		m_state = END;
	}
	if (CKeyInput::IsTrg(KEY_CANCEL)) {
		m_result = 1;
		m_state = END;
	}

}


//---------------------------
//終了前処理
//---------------------------
void CResultScene::Exit()
{
	CSoundManager::StopAll();
}