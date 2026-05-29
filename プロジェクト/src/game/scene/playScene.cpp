#include "playScene.h"
#include "../../lib/collision/collision.h"
#include"../collision/collisionManager.h"
#include "../sound/soundManager.h"
#include "../../lib/input/keyInput.h"
#include "../player/count.h"
#include "../../lib/system/fade.h"



CPlayScene::CPlayScene() {
	m_state = INIT;

}

CPlayScene::~CPlayScene() {
	Exit();
}



//描画
void CPlayScene::Draw() {
	//DrawFormatString(20, 20, RED, "プレイシーン");

	m_Stage.Draw();

	m_Player.Draw();


}

//初期化
void CPlayScene::Init() {


	m_Player.Init();
	m_Stage.Init();

}

//読み込み
void CPlayScene::Load() {
	CSoundManager::Play(CSoundManager::BGM_GAME, DX_PLAYTYPE_LOOP);

	m_Player.Load();

	m_Stage.Load();
}



//更新処理
void CPlayScene::Step() {
	m_Player.Step(m_Stage);

	
	if (CKeyInput::IsTrg(KEY_SELECT)) {
		m_state = END;
		m_result = 1;
	}
	if (m_Player.GetActive() == false)
	{
		m_state = END;
		m_result = 0;

	}
}



//終了処理
void CPlayScene::Exit() {

	m_Player.Exit();

	m_Stage.Exit();
	CSoundManager::StopAll();

}



