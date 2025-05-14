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
	modelParticle_ = Model::CreateFromOBJ("cube");

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
	
	Vector3 position = {0, 0, 0};
	Vector3 rotate = {0.0f, 0.0f, 0.0f};
	Vector3 scale = {0.2f, 2.0f, 0.2f};

		ParticleBorn(position, rotate, scale);
}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Model::PreDraw(dxCommon->GetCommandList());

	for (auto& particle : particles_) {
    		particle->Draw(camera_);
	}

	Model::PostDraw();
}


void GameScene::ParticleBorn(Vector3 position, Vector3 rotate, Vector3 scale) {
	// パーティクルの生成
	for (int i = 0; i < 1; i++) {
		Particle* particle = new Particle(); // ローカル変数を使用
		Vector3 velocity = {0, 0, 0};
		particle->Initialize(modelParticle_, position, rotate, scale, velocity); // 正しいオブジェクトに対して呼び出し
		particles_.push_back(particle);
	}
}
