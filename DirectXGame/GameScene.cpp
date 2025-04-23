#include "GameScene.h"

GameScene::~GameScene() {

	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();

	delete modelParticle_;

}

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	// パーティクルの生成
	for (int i = 0; i < 150; i++) {
		Particle* particle = new Particle(); // ローカル変数を使用
		Vector3 position = {0.5f * i, 0.0f, 0.0f};
		particle->Initialize(modelParticle_, position); // 正しいオブジェクトに対して呼び出し
		particles_.push_back(particle);
	}
}


void GameScene::Update() {
	// パーティクルの更新
	for (auto& particle : particles_) {
		particle->Update();
	}
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());

	for (auto& particle : particles_) {
		particle->Draw(camera_);
	}

	Model::PostDraw();
}