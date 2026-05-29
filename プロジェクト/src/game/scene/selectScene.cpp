#include "selectScene.h"
#include "../data.h"
#include "../../lib/input/keyInput.h"
#include "../sound/soundManager.h"
#include"../collision/collisionManager.h"
#include "../player/count.h"

//定義関連====================================
static const char* BACK_GROUND_PATH = "data/graphic/Goal/goalBackGround.png";
//============================================

//---------------------------
//コンストラクタ
//---------------------------
CSelectScene::CSelectScene() {
	//最初はデータ初期化
	m_state = INIT;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		m_chara[i].m_isActive = true;
	}
	//m_chara[0].m_isActive = true;
}

//---------------------------
//デストラクタ
//---------------------------
CSelectScene::~CSelectScene() {
	//安全のためにデータ破棄処理を呼び出し
	Exit();
}

int CSelectScene::Loop()
{
	//ゲームが終了したかを外部に伝えるため
	m_result = -1;

	switch (m_state)
	{
	case INIT:
		//初期化
		Init();

		m_state = LOAD;	//ロードに進む
		break;
	case LOAD:
		//データ読み込み
		Load();

		m_state = MAIN;	//メインの処理に進む
		break;
	case MAIN:
		//メイン処理
		Step();
		break;
	case END:
		//終了前処理
		Exit();

		m_state = INIT;	//初期化に進む
		break;
	}

	//本編が終了したかどうかを外部に伝える
	return m_result;
}
//---------------------------
//描画処理
//---------------------------
void CSelectScene::Draw()
{
	m_backGround.Draw();
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (m_chara[i].m_isActive) {
			DrawRotaGraph(m_chara[i].m_pos.x, m_chara[i].m_pos.y, 1.0f, 0.0f, m_chara[i].m_hndl, true);
		}
	}
}

//---------------------------
//初期化
//---------------------------
void CSelectScene::Init()
{
	CSoundManager::Play(CSoundManager::BGM_SELECT, DX_PLAYTYPE_LOOP);

	m_charaCount = 4;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		m_chara[i].m_hndl = -1;

		m_chara[i].m_isSelect = false;
		m_chara[i].m_pos = ZERO;
		/*if (m_chara[i].m_isActive)
			m_charaCount++;*/
	}

	m_backGround.Init(VGet(WINDOW_SIZE_X * 0.5f,WINDOW_SIZE_Y * 0.5f,0.0f));
}

//---------------------------
//データ読み込み
//---------------------------
void CSelectScene::Load()
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if(m_chara[i].m_hndl==-1&&m_chara[i].m_isActive)
		m_chara[i].m_hndl = LoadGraph(CHARACTER_PATH[i]);
	}
	m_backGround.Load("data/graphic/Image (30).jpg");
}

//---------------------------
//メイン処理
//---------------------------
void CSelectScene::Step()
{
	int k = 0;
	int l = 1;
	int j = 0;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (m_chara[i].m_isActive) {
			j++;
			if (j == 5) {
				j = 0;
				k = 0;
				l++;
			}
			k++;
			m_chara[i].m_pos = VGet(WINDOW_SIZE_X / 5 * k, WINDOW_SIZE_Y / 3* l,0.0f);
		}
	}
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (CCollisionManager::CheckHitCursorToCharacter(m_chara[i])) {
			if (CKeyInput::IsTrg(KEY_SELECT)) {
				m_state = END;
				m_result = i;
				CMaterial::Setid(i);
			}
		}
	}
}

//---------------------------
//終了前処理
//---------------------------
void CSelectScene::Exit()
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (m_chara[i].m_hndl != -1) {
			DeleteGraph(m_chara[i].m_hndl);
			m_chara[i].m_hndl = -1;
		}
	}
	m_backGround.Exit();
	CSoundManager::StopAll();
}

