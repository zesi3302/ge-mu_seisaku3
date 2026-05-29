#pragma once
#include<DxLib.h>
#include<iostream>
#include<vector>

//2Dのオブジェクト
class C2DObject
{
protected:
	VECTOR							m_pos;		//座標
	float							m_rot;		//回転角度
	std::vector<std::vector<int>>	m_hndl;		//モデルハンドル
	bool							m_isActive;	//生存フラグ

	typedef struct {
		int							m_frame;	//アニメの現在のフレーム
		int							m_timeCount;//アニメの時間
		int							m_speed;	//アニメの再生速度
		int							m_animId;	//現在のアニメID
		bool						m_animLoop;	//アニメループフラグ
	}ANIM_DATA;

	ANIM_DATA						m_animData;	//アニメ再生関連データ

public:
	//コンストラクタ・デストラクタ
	C2DObject();
	virtual ~C2DObject();

	//初期化
	virtual void Init(VECTOR _pos = {0.0f,0.0f,0.0f}, float _rot = 0.0f);
	//ロード(直接画像をロードする用)
	void Load(const char* _hndlPath);
	//ロード(中身でロードする用)
	virtual void Load();
	//毎フレームする処理
	virtual void Step();
	//描写
	virtual void Draw(float _size = 1.0f);
	//破棄
	virtual void Exit();

	//当たり判定後の処理
	virtual void HitCalc();

protected:
	//画像をロードする関数
	//_hndlPath	:画像のパス
	//_allNum	:分割したときの画像の数(分割していなかったら入力しなくていい)
	//_sizeX	:分割した画像の大きさ横
	//_sizeY	:分割した画像の大きさ縦
	void LoadGraphic(const char* _hndlPath,int _allNum = 1,  int _sizeX = 1, int _sizeY = 1);

	//画像のアニメーションを呼び出し
	void RequestAnim(int _animId,int _animSpeed,bool _isLoop = true);

public:

	//座標出力
	VECTOR GetPos() { return m_pos; }
	//角度出力
	float GetRot() { return m_rot; }

	//座標設定
	void SetPos(VECTOR _pos) { m_pos = _pos; }
	//角度設定
	void SetRot(float _rot) { m_rot = _rot; }

	//生存フラグを取得
	bool GetActive() { return m_isActive; }


};

