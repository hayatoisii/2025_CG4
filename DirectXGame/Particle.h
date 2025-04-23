#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;

class Particle {
public:
	~Particle();

	void Initialize(Model* model, Vector3 position);

	void Update();

	void Draw(Camera& camera);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	// 色変更オブジェクト
	ObjectColor objectColor_;
    // 色の数値
	Vector4 color_;

};