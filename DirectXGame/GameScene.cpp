#include "GameScene.h"

GameScene::~GameScene() { 
	delete modelParticle_;
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	// 3Dモデルデータの生成
	modelParticle_ = Model2::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	worldTransform.Initialize();
}

void GameScene::Update() {

}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	// モデルの描画
	if (modelParticle_) {
		modelParticle_->Draw(worldTransform, camera_);
	}

	Model2::PostDraw();
}