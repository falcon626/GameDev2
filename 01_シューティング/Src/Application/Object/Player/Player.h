#pragma once

// 基本的にヘッダーファイルの中で
// 別のヘッダーファイルをインクルードするのはNG
// 継承元クラスのヘッダーのみインクルードが必須なので可とする

#include "../BaseObject.h"

class GameScene; // 前方宣言

// よっぽどの事情がない限りpublic継承
// 何も書かない場合はprivate継承になる
class Player :public BaseObject
{
public:

	Player() {}
	~Player() { Release(); }

	// 基底クラスの仮想関数をオーバーライド
	// override指定子は無くてもオーバーライドされるが
	// オーバーライド可能かどうかを判別する目的でつけるべき(可読性の問題もある)
	void Update()override; // オーバーライド指定子
	void Draw()override;
	void Init()override;
	
	void SetOwner(GameScene* _owner) { m_owner = _owner; }

private:

	GameScene* m_owner = nullptr;

	void Release()override;

	const float Player_MoveNum = 5.0f;
};