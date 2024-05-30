#include "GameScene.h"
#include "../SceneManager.h"
#include "../../Object/BackGround/BackGround.h"
#include "../../Object/Ground/Ground.h"
#include "../../Object/Player/Player.h"

void GameScene::Event()
{
	Math::Vector3 playerPos = Math::Vector3::Zero;
	if (!m_player.expired())
	{
		std::shared_ptr<Player> _work = m_player.lock();
		playerPos = _work->GetPos();
	}
	auto traMat = Math::Matrix::CreateTranslation(playerPos.x, playerPos.y+3, playerPos.z-3);
	auto rodMat = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(30));
	m_camera->SetCameraMatrix((rodMat*traMat));
}

void GameScene::Init()
{
	m_camera = std::make_unique<KdCamera>();
	m_camera->SetProjectionMatrix(60);

	auto backGround = std::make_shared<BackGround>();
	backGround->Init();
	auto ground = std::make_shared<Ground>();
	ground->Init();
	auto player = std::make_shared<Player>();
	player->Init();
	//m_objList.emplace_back(backGround);
	AddObject(backGround);
	AddObject(ground);
	AddObject(player);
	m_player = player;
}
