#pragma once
#include <DxLib.h>
#include "../Stage/Stage.h"

// プレイヤーのアニメーション数
const int PL_ANIM_NUM = 2;
// プレイヤーのアニメーション速度
const int PL_ANIM_SPD = 15;

enum tagPlayerState
{
	WAIT,
	MOVE,

};

enum tagPlayerDirection
{
	UP,			//上方向
	DOWN,		//下方向
	LEFT,		//左方向
	RIGHT,		//右方向
};

// プレイヤーの歩行速度
const int PLAYER_SPEED = 3;
// プレイヤーの大きさ
const int PLAYER_RADIUS = 15;

class CPlayer
{
private:
	int m_X;	// X座標
	int m_Y;	// Y座標
	bool m_isActive;
	int m_Hndl[PL_ANIM_NUM];	// 画像ハンドル
	int m_AnimTime;				// アニメーション時間

	tagPlayerState m_State;	// 状態遷移
	tagPlayerDirection m_Direction;	// 状態遷移
	CStageManager m_Stage;

public:
	void Init();
	void Load();
	void Step(CStageManager& stage);
	void Exit();
	void Draw();

public:
	void GetPosition(int& x, int& y);
	void SetPosition(int x, int y);
	tagPlayerDirection GetDir();
	void playerHitCalc_1();
	//生存フラグを取得
	bool GetActive() { return m_isActive; }
	bool SetActive() { return m_isActive; }

	// 壁とぶつかったときの処理
	void Calc(int x, int y);
};