#pragma once
#include "sceneBase.h"
#include"selectScene.h"

//ゲーム本編を管理するクラス
class CSceneManager
{
private:

	//ゲーム中に使用するシーン
	enum tagScene
	{
		TITLE,		//タイトル画面
		RESULT,		//リザルト画面
		GAMEOVER,	//ゲームオーバー画面
		SELECT,

		SCENE_NUM,	//シーンの数
	};

	//各種シーン変数
	tagScene m_sceneID;	//今のシーン

	CSceneBase* m_scene[SCENE_NUM - 1];
	CSelectScene m_select;

	int m_chara;
	int count;
public:

	//コンストラクタ
	CSceneManager();
	//デストラクタ
	~CSceneManager();

	//実行処理
	int Loop();
	//描画処理
	void Draw();


};


