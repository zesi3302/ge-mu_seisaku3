#pragma once
#include "sceneBase.h"
#include <DxLib.h>

//ゲーム本編を管理するクラス
class CGameOverScene :public CSceneBase
{
private:
	int m_backhndl;
public:

	//コンストラクタ
	CGameOverScene();
	//デストラクタ
	~CGameOverScene();

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

