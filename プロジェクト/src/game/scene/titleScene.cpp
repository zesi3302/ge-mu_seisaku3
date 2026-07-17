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
	DrawRotaGraph(WINDOW_SIZE_X * 0.5f, WINDOW_SIZE_Y * 0.5f, 1, 0.0, m_backhndl, TRUE);

}

//---------------------------
//初期化
//---------------------------
void CTitleScene::Init()
{

	m_backhndl = -1;
}

//---------------------------
//データ読み込み
//---------------------------
void CTitleScene::Load()
{
	CSoundManager::Play(CSoundManager::BGM_TITLE, DX_PLAYTYPE_LOOP);
	m_backhndl = LoadGraph("data/graphic/taitoru.jpg");

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
		//CMaterial::Setid(1);

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
