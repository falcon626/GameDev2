#include "BackGround.h"

void BackGround::Init()
{
	m_polygon.SetMaterial("Asset/Textures/BackGround.png");
	m_polygon.SetScale(200.0f);
	m_polygon.SetPivot(KdSquarePolygon::PivotType::Center_Bottom);
	m_mWorld = Math::Matrix::CreateTranslation(0.0f, 0.0f, 100.0f);
}

void BackGround::DrawUnLit()
{
	KdShaderManager::Instance().m_StandardShader.DrawPolygon(m_polygon, m_mWorld);
}