#include "GameScene.h"

GameScene::~GameScene() { 
	delete model2_;
	Model2::StaticFinalize();
}

void GameScene::Initialize() {

	Model2::StaticInitialize();

	// 3Dモデルデータの生成
	model2_ = Model2::CreateCube();

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
	if (model2_) {
		model2_->Draw(worldTransform, camera_);
	}

	Model2::PostDraw();
}