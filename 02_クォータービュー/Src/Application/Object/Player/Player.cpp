#include "Player.h"

void Player::Init()
{
	m_polygon.SetMaterial("Asset/Textures/Player.png");
	m_polygon.SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_speed = 0.1f;
	m_dir = Math::Vector3::Zero;
	m_mWorld = Math::Matrix::Identity;
	m_pos = Math::Vector3::Zero;
	m_polygon.SetSplit(4, 8);
	m_gravity = NULL;
}

void Player::GenerateDepthMapFromLight()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_polygon, m_mWorld);
}

void Player::DrawLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_polygon, m_mWorld);
}

void Player::Update()
{
	m_polygon.SetUVRect(12);
	m_dir = Math::Vector3::Zero;
	if (GetAsyncKeyState(VK_UP) & 0x8000)m_dir += {0, 0, 1};
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)m_dir += {0, 0, -1};
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)m_dir += {-1, 0, 0};
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)m_dir += {1, 0, 0};
	m_dir.Normalize();
	m_pos += m_dir*m_speed;
	m_gravity += 0.0005f;
	m_pos.y -= m_gravity;

	// RayBegin
	// レイ判定に必要なパラメータを設定する構造体を宣言
	KdCollider::RayInfo rayInfo;
	rayInfo.m_pos = m_pos;
	rayInfo.m_pos.y += 0.1f;
	rayInfo.m_dir = { 0.0f,1.0f,0.0f };
	rayInfo.m_type = KdCollider::Type::TypeGround;
	// RayEnd
}

void Player::PostUpdate()
{
	m_mWorld = Math::Matrix::CreateTranslation(m_pos);
}
