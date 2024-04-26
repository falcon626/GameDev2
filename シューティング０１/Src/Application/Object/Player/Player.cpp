#include "Player.h"

#include "../../Scene/GameScene.h"

void Player::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)m_pos.x -= Player_MoveNum;

	if (GetAsyncKeyState('D') & 0x8000)m_pos.x += Player_MoveNum;

	if (GetAsyncKeyState('S') & 0x8000)m_pos.y -= Player_MoveNum;

	if (GetAsyncKeyState('W') & 0x8000)m_pos.y += Player_MoveNum;

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_owner->Shot(m_pos);
	}

	// 当たり判定・・・敵の情報が必要
	// オブジェクトリストを全て見ていく
	for (auto& obj : m_owner->GetObjList())
	{
		// 自分自身とは当たり判定しない
		if (obj->GetObjType() == ObjectType::Player)continue;
		
		// 敵だったら当たり判定を行う
		if (obj->GetObjType() == ObjectType::Enemy)
		{
			// 対象座標 - 自分座標 = 対象へのベクトル
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			// 球判定・・・ベクトルの長さで判定
			if (v.Length() < 64.0f)
			{
				// Hit時の処理を行う
				obj->OnHit();
			}
		}
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;

	// 拡縮×回転×座標
	// 移動行列という呼び方から座標行列へ
}

void Player::Draw()
{
	Math::Rectangle rc;
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);

	rc = { 0,0,64,64 };
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);

	// KdShaderManager::Instance()から引っ張ってくる必要がある
	// 1年生の時はマクロで省略されていた
}

void Player::Init()
{
	m_tex.Load("Asset/Textures/player.png");
	m_pos = {};                     // 0,0で初期化
	m_mat = Math::Matrix::Identity; // 単位行列で初期化
	m_objType = ObjectType::Player; // 種類は「プレイヤー」

	// 単位行列・・・拡大率全て1.0,他の値は全て0
	// 1,0,0,0
	// 0,1,0,0
	// 0,0,1,0
	// 0,0,0,1
}

void Player::Release()
{
	// KdTexture.h 137行目
	//テクスチャはKdTexture型のデストラクタで
	//自動ReleaseされるのでReleaseを呼ぶ必要はない
}
