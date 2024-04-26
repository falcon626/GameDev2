#pragma once

#include "../BaseObject.h"

class GameScene;

class Bullet :public BaseObject
{
public:

	Bullet() {}
	~Bullet() { Release(); }

	void Update()override;
	void Draw()override;
	void Init()override;
	void OnHit()override;

	void SetOwner(GameScene* _owner) { m_owner = _owner; }
	void SetPos(Math::Vector3 _pos) { m_initPos = _pos; }

private:

	GameScene* m_owner = nullptr;
	Math::Vector3 m_initPos;
	Math::Vector3 m_movePow;

	void Release()override;
};