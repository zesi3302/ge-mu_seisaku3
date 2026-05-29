#include "titleScene.h"
#include "../data.h"
#include"../../lib/input/keyInput.h"
#include "../sound/soundManager.h"

//定義関連====================================
//============================================

//---------------------------
//コンストラクタ
//---------------------------
CTitleScene::CTitleScene() {
	//最初はデータ初期化
	m_state = INIT;
	Init();
}

//---------------------------
//デストラクタ
//---------------------------
CTitleScene::~CTitleScene() {
	//安全のためにデータ破棄処理を呼び出し
	Exit();
}


//---------------------------
//描画処理
//---------------------------
void CTitleScene::Draw()
{
	DrawFormatString(32, 32, GetColor(255, 0, 0), "タイトル");
	DrawRotaGraph(m_pos.x, m_pos.y, 0.9, 0.0,m_hndl,TRUE);

}

//---------------------------
//初期化
//---------------------------
void CTitleScene::Init()
{
	m_hndl = -1;
	m_pos.x = WINDOW_SENTER_X;
	m_pos.y = WINDOW_SENTER_Y;
}

//---------------------------
//データ読み込み
//---------------------------
void CTitleScene::Load()
{
	CSoundManager::Play(CSoundManager::BGM_TITLE, DX_PLAYTYPE_LOOP);
	m_hndl = LoadGraph("data/graphic/Image (27).jpg");

}

//---------------------------
//メイン処理
//---------------------------
void CTitleScene::Step()
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
void CTitleScene::Exit()
{
	CSoundManager::StopAll();
}
