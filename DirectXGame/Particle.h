#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;

class Particle {
public:
	~Particle();

	void Initialize(Model* model);

	void Update();

	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
};
