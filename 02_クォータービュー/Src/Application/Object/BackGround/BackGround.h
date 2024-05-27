#pragma once

class BackGround : public KdGameObject
{
public:
	BackGround(){}
	~BackGround() override {}

	void Init()override;
	void DrawUnLit()override;

private:
	KdSquarePolygon m_polygon;
};