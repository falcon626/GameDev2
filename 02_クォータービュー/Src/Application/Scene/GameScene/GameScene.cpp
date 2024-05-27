#include "GameScene.h"
#include "../SceneManager.h"
#include "../../Object/BackGround/BackGround.h"
#include "../../Object/Ground/Ground.h"

void GameScene::Event()
{
	auto traMat = Math::Matrix::CreateTranslation(0, 3, -3);
	auto rolMa = Math::Matrix::CreateRotationX(DirectX::XMConvertToRadians(30));
	m_camera->SetCameraMatrix((rolMa*traMat));
}

void GameScene::Init()
{
	m_camera = std::make_unique<KdCamera>();
	m_camera->SetProjectionMatrix(60);

	auto backGround = std::make_shared<BackGround>();
	backGround->Init();
	auto ground = std::make_shared<Ground>();
	ground->Init();
	//m_objList.emplace_back(backGround);
	AddObject(backGround);
	AddObject(ground);
}
