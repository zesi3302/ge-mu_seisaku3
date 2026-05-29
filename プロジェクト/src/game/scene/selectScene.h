#pragma once
#include "sceneBase.h"
#include <DxLib.h>
#include "../../lib/2D/2DObject.h"
static const int CHARACTER_NUM = 8;
static const char CHARACTER_PATH[CHARACTER_NUM][255] = { "data/suuzi/1.png","data/suuzi/2.png","data/suuzi/3.png","data/suuzi/4.png", 
														"data/suuzi/5.png","data/suuzi/6.png","data/suuzi/7.png","data/suuzi/8.png" };
//ゲーム本編を管理するクラス
class CSelectScene {
public:

	typedef struct {
		int m_hndl;
		bool m_isActive;
		bool m_isSelect;
		VECTOR m_pos;
	}CHARACTER;
private:
	//シーン処理の流れ
	enum tagScene
	{
		INIT,		//データ初期化
		LOAD,		//データ読み込み
		MAIN,		//本編実行
		END,		//終了前のゲーム破棄
	};

	tagScene m_state;	//シーンの状態	

	int m_result;

	CHARACTER m_chara[CHARACTER_NUM];

	int m_charaCount;

	C2DObject m_backGround;

public:

	//コンストラクタ
	CSelectScene();
	//デストラクタ
	~CSelectScene();

	//描画処理
	void Draw();

	int Loop();


	void SetCharacter(int i) { m_chara[i].m_isActive = true; }

	VECTOR GetCharaPos(int i) { return m_chara[i].m_pos; }

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