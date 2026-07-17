#pragma once
#include "sceneBase.h"
#include <DxLib.h>
#include"../../lib/2D/2DObject.h"

//ゲーム本編を管理するクラス
class CTitleScene :public CSceneBase
{
private:
	int m_hndl;
	int m_backhndl;
	VECTOR m_pos;
	VECTOR m_backpos;
	int m_time;
public:

	//コンストラクタ
	CTitleScene();
	//デストラクタ
	~CTitleScene();

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