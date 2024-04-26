#pragma once

#include "../BaseObject.h"

class GameScene; // 前方宣言

class Enemy :public BaseObject
{
public:

	Enemy() {}
	~Enemy() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void OnHit()override; // Hit時の処理をオーバーライド

	// セッター
	void SetPos(Math::Vector3 _pos) { m_pos = _pos; }
	void SetPos(float _x, float _y) { m_pos = { _x,_y,0.0f }; } // SetPos()のオーバーロード
	void SetMovePow(Math::Vector3 _movePow) { m_movePow = _movePow; }

private:

	Math::Vector3 m_movePow;

	void Release()override;

};