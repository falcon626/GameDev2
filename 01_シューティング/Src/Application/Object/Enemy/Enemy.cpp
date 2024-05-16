#include "Enemy.h"

void Enemy::Update()
{
	m_pos += m_movePow;

	if (m_pos.y < (-360.0f - 32.0f))
	{
		m_pos.y = (360.0f + 32.0f);
	}

	Math::Matrix transMat;
	transMat = Math::Matrix::CreateTranslation(m_pos);
	m_mat = transMat;
}

void Enemy::Draw()
{
	Math::Rectangle rc;
	KdShaderManager::Instance().m_spriteShader.SetMatrix(m_mat);

	rc = { 0,0,64,64 };
	KdShaderManager::Instance().m_spriteShader.DrawTex(&m_tex, 0, 0, 64, 64, &rc);
}

void Enemy::Init()
{
	m_tex.Load("Asset/Textures/enemy.png");
	m_pos = {};
	m_mat = Math::Matrix::Identity;
	m_movePow = { 0,-2,0 };
	m_objType = ObjectType::Enemy; // 種類は「エネミー」
}

void Enemy::OnHit()
{
	m_aliveFlg = false;
}

void Enemy::Release()
{
	//テクスチャはKdTexture型のデストラクタで
	//自動ReleaseされるのでReleaseを呼ぶ必要はない
}
