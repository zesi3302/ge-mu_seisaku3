#pragma once
#include "sceneBase.h"
#include "../../lib/2D/2DObject.h"
#include"../data.h"
#include"../player/player.h"
#include "../Stage/Stage.h"

//ゲーム本編を管理するクラス
class CPlayScene :public CSceneBase
{
private:

	CPlayer m_Player;
	CStageManager m_Stage;
	//enum tagScene {
	//	INIT,			//初期化
	//	LOAD,			//読み込み
	//	STARTWAIT,
	//	MAIN,			//更新
	//	ENDWAIT,
	//	END,			//データの破棄

	//	NUM
	//};
	//tagScene m_State;			//シーンの状態
	//int m_EndingNum;			//Loopのリターンで返す変数A
	//int m_MemEnd;				//次のシーンの分岐を記憶

	//CPlayer m_Player;
	//CStageManager m_Stage;
public:

	//コンストラクタ
	CPlayScene();
	//デストラクタ
	~CPlayScene();

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

