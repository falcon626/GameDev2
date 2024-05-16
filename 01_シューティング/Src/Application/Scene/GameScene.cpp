#include "GameScene.h"

#include "../Object/Player/Player.h"
#include "../Object/Enemy/Enemy.h"
#include "../Object/Bullet/Bullet.h"

void GameScene::PreUpdate()
{
	// Update前の更新処理
	// オブジェクトリストの整理をしておく

	// イテレータとは・・・コンテナクラス用のポインタのようなもの
	// コンテナを先頭から末尾まで遡る際に使用
	
	// イテレータ作成 ベタ書き版
	//std::vector<std::shared_ptr<BaseObject>>::iterator it;
	//it = m_objList.begin();

	// イテレータ作成 auto版 auto・・・型を自動的に設定
	auto it = m_objList.begin();

	while (it != m_objList.end()) // end()は最後の要素の1個後ろを返す
	{
		// whileは先に判断して中の処理を行うので最後の要素の1個後ろである必要がある

		// オブジェクトの有効チェック
		if ((*it)->GetAliveFlg() == false) // アドレスの中にアドレスがある
		{
			// 無効なオブジェクトをリストから削除
			it = m_objList.erase(it);
		}
		else
		{
			// 次の要素へイテレータを進める
			it++;
		}
	}

	// ↑の後には有効なオブジェクトだけのリストになっている
}

void GameScene::Update()
{
	//m_player->Update();
	//m_enemy->Update();

	// 3%の確率で出現させてみる
	if (rand() % 100 < 3)
	{
		// 1体分のインスタンスを生成 & 初期化してリストへ追加
		std::shared_ptr<Enemy> enemy;
		enemy = std::make_shared<Enemy>();
		
		enemy->Init();
		enemy->SetPos({ 640.0f, 0.0f,0.0f });
		enemy->SetMovePow({-2.0f, -2.0f, 0.0f});
		
		m_objList.push_back(enemy); // 初期化やセットをしてから追加
	}

	// 全オブジェクトの更新関数を呼ぶ
	// 範囲ベースFor
	/*for (auto& obj : m_objList)
	{
		obj->Draw();
	}*/
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Update();
	}
}

void GameScene::Draw()
{
	//m_player->Draw();
	//m_enemy->Draw();

	// 全オブジェクトの更新関数を呼ぶ
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Draw();
	}
}

void GameScene::Init()
{
	// 乱数初期化
	srand(timeGetTime());

	// プレイヤー
	//m_player = new Player();               // 生ポ
	//m_player = std::make_shared<Player>(); // スマポ
	//m_player->Init();
	//m_player->SetOwner(this);
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>();
	player->Init();
	player->SetOwner(this);
	m_objList.push_back(player);

	// エネミー
	//m_enemy = std::make_shared<Enemy>(); // スマポ
	//m_enemy->Init();
	std::shared_ptr<Enemy> enemy;

	for (int i = 0; i < EnemyNum; i++)
	{
		enemy = std::make_shared<Enemy>();
		enemy->Init();
		enemy->SetPos((-580.0f + i * 128.0f), 360.0f);
		m_objList.push_back(enemy);
	}

	// まとめて実装する方法(自作) ※playerのSetOwnerは出来ない
	/*m_objList.push_back(std::make_shared <Player>());
	m_objList.push_back(std::make_shared < Enemy>());
	for (int i = 0; i < m_objList.size(); i++)
	{
		m_objList[i]->Init();
	}*/
}

void GameScene::Shot(Math::Vector3 _playerPos)
{
	std::shared_ptr<Bullet> bullet;
	bullet = std::make_shared<Bullet>();
	bullet->SetPos(_playerPos);
	bullet->Init();
	bullet->SetOwner(this);
	m_objList.push_back(bullet);
}

void GameScene::Release()
{
	//delete m_player; // 生ポ(shared_ptrは自動削除)
}
