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
	DrawFormatString(32, 32, GetColor(255, 0, 0), "ゲームオーバー");
	DrawRotaGraph(m_pos.x, m_pos.y, 0.9, 0.0, m_hndl, TRUE);
}

//---------------------------
//初期化
//---------------------------
void CGameOverScene::Init()
{
	CSoundManager::Play(CSoundManager::BGM_GAMEOVER, DX_PLAYTYPE_BACK);

	m_hndl = -1;
	m_pos.x = WINDOW_SENTER_X;
	m_pos.y = WINDOW_SENTER_Y;
}

//---------------------------
//データ読み込み
//---------------------------
void CGameOverScene::Load()
{
	
	m_hndl = LoadGraph("data/graphic/Image (28).jpg");

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
