#include "sceneManager.h"
#include "titleScene.h"
#include "resultScene.h"
#include"selectScene.h"
#include "gameOverScene.h"
#include "../sound/soundManager.h"
#include "../player/count.h"

//定義関連====================================

//============================================

//---------------------------
//コンストラクタ
//---------------------------
CSceneManager::CSceneManager() {
	//最初はデータ初期化
	m_sceneID = TITLE;

	m_scene[0] = new CTitleScene;
	m_scene[1] = new CResultScene;
	m_scene[2] = new CGameOverScene;

	CSoundManager::Init();
	CSoundManager::Load();

	m_chara = -1;
}

//---------------------------
//デストラクタ
//---------------------------
CSceneManager::~CSceneManager() {

	for (int i = 0; i < SCENE_NUM - 1; i++)
	{
		delete m_scene[i];
	}

	CSoundManager::Exit();
}

//---------------------------
//実行処理
//---------------------------
int CSceneManager::Loop()
{
	//ゲームが終了したかを外部に伝えるため
	int result = -1;

	switch (m_sceneID)
	{
	case TITLE:
		count = GetRand(CCount::Getid() - 1);
		result = m_scene[TITLE]->Loop();
		CCount::Setid(2);

		if (result == 0)
		{
			CSoundManager::StopAll();

			m_sceneID = SELECT;
		}
		break;
	case SELECT:

		if (m_select.Loop() != -1)
		{
			CSoundManager::StopAll();
			if (count == CCount::Getsetid()) {
				m_sceneID = RESULT;
			}
			else m_sceneID = GAMEOVER;
		}
		break;
	case RESULT:
		if (m_scene[RESULT]->Loop() != -1)
		{
			CSoundManager::StopAll();
			if (CCount::Getid() < 8)
			{
				CCount::Setplusid(1);

				count = GetRand(CCount::Getid() - 1);

				m_sceneID = SELECT;
			}
			else {
				m_sceneID = TITLE;

			}


		}
		break;
	case GAMEOVER:
		if (m_scene[GAMEOVER]->Loop() != -1)
		{
			CSoundManager::StopAll();

			m_sceneID = TITLE;
		}
	}

	//本編が終了したかどうかを外部に伝える
	return result;
}

//---------------------------
//描画処理
//---------------------------
void CSceneManager::Draw()
{
	switch (m_sceneID)
	{
	case TITLE:
		m_scene[TITLE]->Draw();
		break;
	case SELECT:
		m_select.Draw();
		break;
	case RESULT:
		m_scene[RESULT]->Draw();
		break;
	case GAMEOVER:
		m_scene[GAMEOVER]->Draw();
		break;
	}
}

