#include "GameScene.h"

GameScene::~GameScene() { delete modelParticle_; }

void GameScene::Initialize() {

	Model2::StaticFinalize();

	// 3Dモデルデータの生成
	modelParticle_ = Model2::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	worldTransform.Initialize();
}

void GameScene::Update() {
	// パーティクルの更新
	// particle_->Update();
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