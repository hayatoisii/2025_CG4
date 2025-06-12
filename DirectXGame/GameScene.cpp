#include "GameScene.h"

GameScene::~GameScene() { 
	delete model2_;
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	// 3Dモデルデータの生成
	model2_ = Model2::CreateRing(5, 1.0f, 0.6f);
//	model2_ = Model2::CreateCube(5);


	//worldTransform.scale_ = {3.0f, 3.0f, 3.0f};

	// カメラの初期化
	camera_.Initialize();
	camera_.translation_ = {0.0f, 0.0f, -10.0f};
	camera_.rotation_ = {0.0f, 0.0f, 0.0f};
	camera_.UpdateMatrix();
	camera_.TransferMatrix();

	worldTransform.Initialize();
   // worldTransform.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransform.TransferMatrix();
}

void GameScene::Update() {
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	// モデルの描画
	if (model2_) {
		model2_->Draw(worldTransform, camera_);
	}

	Model2::PostDraw();
}