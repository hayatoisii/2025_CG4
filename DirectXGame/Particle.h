#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;

class Particle {
public:
	~Particle();

	void Initialize();

	void Update();

	void Draw();

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
};
