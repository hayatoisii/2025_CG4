#include "GameScene.h"
#include <random>

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

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

	srand((unsigned)time(NULL));
}

void GameScene::Update() {
	// パーティクルの更新
	for (auto& particle : particles_) {
		particle->Update();
	}

	particles_.remove_if([](Particle* particle) {
		if (particle->IsFinished()) {
			delete particle;
			return true;
		}
		return false;
	});

	Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
	if (rand() % 20 == 0) {
		ParticleBorn(position);
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

void GameScene::ParticleBorn(Vector3 position) {
	// パーティクルの生成
	for (int i = 0; i < 80; i++) {
		Particle* particle = new Particle(); // ローカル変数を使用
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
		particle->Initialize(modelParticle_, position, velocity); // 正しいオブジェクトに対して呼び出し
		particles_.push_back(particle);
	}
}