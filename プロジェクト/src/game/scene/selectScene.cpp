#include "selectScene.h"
#include "../data.h"
#include "../../lib/input/keyInput.h"
#include"../collision/collisionManager.h"
#include "../player/count.h"
#include "../sound/soundManager.h"

//---------------------------
//コンストラクタ
//---------------------------
CSelectScene::CSelectScene() {
	//最初はデータ初期化
	m_state = INIT;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		m_chara[i].m_isActive = false;
	}
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
	int j = 0;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (m_chara[i].m_isActive) {
			j++;
			DrawRotaGraph(m_chara[i].m_pos.x, m_chara[i].m_pos.y, 1.0f, 0.0f, m_chara[i].m_hndl, true);
		}
	}
	switch (CCount::Getid())
	{

	case 2:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/2を当てろ！");

		break;
	case 3:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/3を当てろ！");
		break;
	case 4:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/4を当てろ！");
		break;
	case 5:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/5を当てろ！");
		break;
	case 6:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/6を当てろ！");
		break;
	case 7:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/7を当てろ！");
		break;
	case 8:
		DrawExtendFormatString(300, 50, 4, 4, GetColor(0, 0, 0), "1/8を当てろ！");
		break;
	default:

		break;
	}
}

//---------------------------
//初期化
//---------------------------
void CSelectScene::Init()
{
	CSoundManager::Play(CSoundManager::BGM_SELECT, DX_PLAYTYPE_LOOP);
	for (int i = 0; i < CHARACTER_NUM; i++) {
		m_chara[i].m_isActive = false;
	}
	for (int i = 0; i < CCount::Getid(); i++) {

		m_chara[i].m_isActive = true;
	}
	m_charaCount = 0;
	for (int i = 0; i < CHARACTER_NUM; i++) {
		m_chara[i].m_hndl = -1;

		m_chara[i].m_isSelect = false;
		m_chara[i].m_pos = ZERO;
		if (m_chara[i].m_isActive)
			m_charaCount++;
	}

	m_backGround.Init(VGet(WINDOW_SIZE_X * 0.5f, WINDOW_SIZE_Y * 0.5f, 0.0f));
}

//---------------------------
//データ読み込み
//---------------------------
void CSelectScene::Load()
{
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (m_chara[i].m_hndl == -1 && m_chara[i].m_isActive)
			m_chara[i].m_hndl = LoadGraph(CHARACTER_PATH[i]);
	}
	m_backGround.Load("data/suuzi/0.jpg");
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
			m_chara[i].m_pos = VGet(WINDOW_SIZE_X / 5 * k, WINDOW_SIZE_Y / 3 * l, 0.0f);
		}
	}
	for (int i = 0; i < CHARACTER_NUM; i++) {
		if (CCollisionManager::CheckHitCursorToCharacter(m_chara[i])) {
			if (CKeyInput::IsTrg(KEY_SELECT)) {
				m_state = END;
				m_result = i;
				CCount::Setsetid(i);


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

