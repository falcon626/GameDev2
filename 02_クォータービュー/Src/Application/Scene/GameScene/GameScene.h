#pragma once

#include "../BaseScene/BaseScene.h"

class Player;

class GameScene : public BaseScene
{
public :

	GameScene() { Init(); }
	~GameScene() {}

private:

	void Event() override;
	void Init() override;

	// 必要な時だけ参照するため
	std::weak_ptr<Player> m_player;

	// wp 参照増減なしアクセス権なし
	// up 1つのポインタでしか所有できない
	// sp 参照増減ありアクセス権あり
};