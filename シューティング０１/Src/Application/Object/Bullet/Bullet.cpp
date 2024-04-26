#include "Bullet.h"
#include "../../Scene/GameScene.h"

void Bullet::Update()
{
	// 移動処理
	m_pos += m_movePow;
	if (m_pos.y > (360.0f + 37.0f))
	{
		OnHit();
	}

	// 当たり判定
	for (auto& obj : m_owner->GetObjList())
	{
		// 自分自身とは当たり判定しない
		if (obj->GetObjType() == ObjectType::Bullet)continue;
		if (obj->GetObjType() == ObjectType::Player)continue;

		// 敵だったら当たり判定を行う
		if (obj->GetObjType() == ObjectType::Enemy)
		{
			// 対象座標 - 自分座標 = 対象へのベクトル
			Math::Vector3 v;
			v = obj->GetPos() - m_pos;

			// 球判定・・・ベクトルの長さで判定
			if (v.Length() < 38.0f)
			{
				// Hit時の処理を行う
				obj->OnHit();
				OnHit();
			}
		}
	}

	// 行列
	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Bullet::Draw()
{
	Math::Rectangle rc;
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);

	rc = { 0,0,13,37 };
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 13, 37, &rc);
}

void Bullet::Init()
{
	m_tex.Load("Asset/Textures/bullet.png");
	m_pos = m_initPos;
	m_mat = Math::Matrix::Identity;
	m_movePow = { 0,2,0 };
	m_objType = ObjectType::Bullet;
}

void Bullet::OnHit()
{
	m_aliveFlg = false;
}

void Bullet::Release()
{
}
