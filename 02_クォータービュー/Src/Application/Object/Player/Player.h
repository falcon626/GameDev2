#pragma once

class Player :public KdGameObject
{
public:
	Player() {};
	~Player() override {};
	void Init()override;
	void GenerateDepthMapFromLight()override;
	void DrawLit()override;
	void Update()override;
	void PostUpdate()override;
private:
	KdSquarePolygon m_polygon;
	// 座標
	Math::Vector3 m_pos;
	// 方向
	Math::Vector3 m_dir;
	// 移動量
	float m_speed;
	// 重力
	float m_gravity;
};