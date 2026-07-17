#pragma once
#include "sceneBase.h"
#include <DxLib.h>
#include "../../lib/2D/2DObject.h"

enum tagResultUi
{
	RESULT_UI_GOAL,

	RESULT_UI_NUM,
};

//ゲーム本編を管理するクラス
class CResultScene :public CSceneBase
{
private:
	C2DObject m_backGround;				//背景
	C2DObject m_ui[RESULT_UI_NUM];		//表示するUI

public:

	//コンストラクタ
	CResultScene();
	//デストラクタ
	~CResultScene();

	//描画処理
	void Draw();

private:

	//初期化
	void Init();

	//データ読み込み
	void Load();

	//メイン処理
	void Step();

	//終了前処理
	void Exit();

};

