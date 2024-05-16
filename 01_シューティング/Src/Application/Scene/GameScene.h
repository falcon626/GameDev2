#pragma once

//class Player;
class BaseObject;

class GameScene
{
public:

	GameScene() {}              // 生成時 コンストラクタ
	~GameScene() { Release(); } // 破棄時 デストラクタ・・・Release()

	void PreUpdate();                    // 更新を呼ぶ前の処理
	void Update();                       // 更新
	void Draw();                         // 描画
	void Init();                         // 初期化
	void Shot(Math::Vector3 _playerPos); // 弾の発射処理

	// オブジェクトのリストを取得
	std::vector<std::shared_ptr<BaseObject>>GetObjList()
	{
		return m_objList;
	}

private:

	// Sceneを捨てるタイミングで呼ぶのでプライベートに
	void Release();   // 終了処理

	//Player* m_player = nullptr;          // 派生クラスの生ポインタ
	//BaseObject* m_player = nullptr;      // 基底クラスの生ポインタ
	//std::shared_ptr<Player>m_player;     // スマートポインタ 派生クラス
	//std::shared_ptr<BaseObject>m_player; // スマートポインタ 基底クラス
	//std::shared_ptr<BaseObject>m_enemy;  

	// 全オブジェクトを可変長で管理
	std::vector<std::shared_ptr<BaseObject>>m_objList;

	const int EnemyNum = 10;
};

