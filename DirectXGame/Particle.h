#pragma once

#include "KamataEngine.h"
#include "Model2.h"

using namespace KamataEngine;

class Particle {
public:
	~Particle();

	void Initialize(Model2* model);

	void Update();

	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model2* model_ = nullptr;
};