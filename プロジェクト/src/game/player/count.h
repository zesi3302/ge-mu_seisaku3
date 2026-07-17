#pragma once

class CCount
{
private:
	static int m_id;
	static int m_setid;

	static int m_hndl[8];
public:
	//コンストラクタ・デストラクタ
	CCount();
	~CCount();

	//初期化
	static void Init();

	//ロード
	static void Load();

	//終了処理
	static void Exit();

	//ハンドルを取得
	static int GetHndl() { return m_hndl[m_id]; }
	static int Getid() { return m_id; }
	static int Getsetid() { return m_setid; }

	//IDを設定
	static void Setsetid(int _id) { m_setid = _id; }

	static void Setid(int _id) { m_id = _id; }
	static void Setplusid(int _id) { m_id = m_id + _id; }
};

