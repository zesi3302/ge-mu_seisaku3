#include "resultScene.h"
#include "../data.h"
#include "../../lib/input/keyInput.h"
#include "../player/count.h"
#include "../sound/soundManager.h"

//定義関連====================================
static const char* BACK_GROUND_PATH = "data/graphic/kuria2.jpg";
static const char* UI_GRAPHIC_PATH[RESULT_UI_NUM] =
{
	"data/graphic/kuria1.jpg"
};

static const VECTOR UI_POS[RESULT_UI_NUM] =
{
	{WINDOW_SIZE_X * 0.5f,WINDOW_SIZE_Y * 0.5f,0.0f}
};

static const float UI_SIZE[RESULT_UI_NUM] =
{
	1.0f
};
//============================================

//---------------------------
//コンストラクタ
//---------------------------
CResultScene::CResultScene() {
	//最初はデータ初期化
	m_state = INIT;
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

	for (int ui_i = 0; ui_i < RESULT_UI_NUM; ui_i++)
	{
		m_ui[ui_i].Draw(UI_SIZE[ui_i]);
	}
	switch (CCount::Getid())
	{

	case 2:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/2");
		break;
	case 3:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/3");
		break;
	case 4:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/4");
		break;
	case 5:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/5");
		break;
	case 6:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/6");
		break;
	case 7:
		DrawExtendFormatString(250, 280, 8, 8, GetColor(0, 255, 0), "1/7");
		break;
	case 8:
		m_backGround.Draw();
		break;
	default:

		break;
	}
}

//---------------------------
//初期化
//---------------------------
void CResultScene::Init()
{
	CSoundManager::Play(CSoundManager::BGM_RESULT, DX_PLAYTYPE_LOOP);

	m_backGround.Init(VGet(WINDOW_SIZE_X * 0.5f, WINDOW_SIZE_Y * 0.5f, 0.0f));
	for (int ui_i = 0; ui_i < RESULT_UI_NUM; ui_i++)
	{
		m_ui[ui_i].Init(UI_POS[ui_i]);
	}
}

//---------------------------
//データ読み込み
//---------------------------
void CResultScene::Load()
{
	m_backGround.Load(BACK_GROUND_PATH);
	for (int ui_i = 0; ui_i < RESULT_UI_NUM; ui_i++)
	{
		m_ui[ui_i].Load(UI_GRAPHIC_PATH[ui_i]);
	}
}

//---------------------------
//メイン処理
//---------------------------
void CResultScene::Step()
{
	if (CKeyInput::IsTrg(KEY_SELECT) == true)
	{
		if (CCount::Getid() == 8) {
			m_result = 1;

		}
		else {
			m_result = 0;
		}
		m_state = END;
	}
}

//---------------------------
//終了前処理
//---------------------------
void CResultScene::Exit()
{
	m_backGround.Exit();
	for (int ui_i = 0; ui_i < RESULT_UI_NUM; ui_i++)
	{
		m_ui[ui_i].Exit();
	}

	CSoundManager::StopAll();
}

