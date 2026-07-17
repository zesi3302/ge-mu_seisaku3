#include "gameOverScene.h"
#include "../data.h"
#include "../../lib/input/keyInput.h"
#include "../sound/soundManager.h"

//定義関連====================================
//============================================

//---------------------------
//コンストラクタ
//---------------------------
CGameOverScene::CGameOverScene() {
	//最初はデータ初期化
	m_state = INIT;
}

//---------------------------
//デストラクタ
//---------------------------
CGameOverScene::~CGameOverScene() {
	//安全のためにデータ破棄処理を呼び出し
	Exit();
}


//---------------------------
//描画処理
//---------------------------
void CGameOverScene::Draw()
{
	DrawRotaGraph(WINDOW_SIZE_X * 0.5f, WINDOW_SIZE_Y * 0.5f, 1, 0.0, m_backhndl, TRUE);
}

//---------------------------
//初期化
//---------------------------
void CGameOverScene::Init()
{
	CSoundManager::Play(CSoundManager::BGM_GAMEOVER, DX_PLAYTYPE_LOOP);
	m_backhndl = -1;
}

//---------------------------
//データ読み込み
//---------------------------
void CGameOverScene::Load()
{
	m_backhndl = LoadGraph("data/graphic/ge-muo-ba-.jpg");

}

//---------------------------
//メイン処理
//---------------------------
void CGameOverScene::Step()
{
	if (CKeyInput::IsTrg(KEY_SELECT) == true)
	{
		m_state = END;
		m_result = 0;
	}
}

//---------------------------
//終了前処理
//---------------------------
void CGameOverScene::Exit()
{
	CSoundManager::StopAll();
}
