#include "GameScene.h"

GameScene::~GameScene() { delete modelParticle_; }

void GameScene::Initialize() {

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	particle_ = new Particle();
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() {
	// パーティクルの更新
	particle_->Update();

}

void GameScene::Draw() { 
	
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	particle_->Draw(camera_);

	Model::PostDraw();


}
