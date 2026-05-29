#pragma once

class CMaterial
{
private:
	static int m_id;
	static int m_hndl[4];
public:
	//コンストラクタ・デストラクタ
	CMaterial();
	~CMaterial();
	
	//初期化
	static void Init();

	//ロード
	static void Load();

	//終了処理
	static void Exit();

	//ハンドルを取得
	static int GetHndl() { return m_hndl[m_id]; }
	static int Getid() { return m_id; }
	//IDを設定
	static void Setid(int _id) { m_id = _id; }
};

