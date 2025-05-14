#pragma once
#include "KamataEngine.h"
#include "MT.h"
#include "Particle.h"

using namespace KamataEngine;

class GameScene {
public:
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

	void ParticleBorn(Vector3 position);

private:
	// パーティクル3Dモデルデータ
	Model* modelParticle_ = nullptr;

	Camera camera_;

	// パーティクル
	Particle* particle_ = nullptr;

	std::list<Particle*> particles_;
};