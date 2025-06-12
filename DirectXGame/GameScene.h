#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Model2.h"

using namespace KamataEngine;

class GameScene 
{
public:
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

private:
	// パーティクル3Dモデルデータ
	Model2* modelParticle_ = nullptr;

	Camera camera_;

	WorldTransform worldTransform;

};