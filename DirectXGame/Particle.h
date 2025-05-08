#pragma once
#include "algorithm"
#include "KamataEngine.h"

using namespace KamataEngine;
/*/
class Particle {
public:
	~Particle();

	void Initialize(Model* model, Vector3 position, Vector3 velocity);

	void Update();

	void Draw(Camera& camera);

	bool IsFinished() { return isFinished_; }

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;

	// 色変更オブジェクト
	ObjectColor objectColor_;
    // 色の数値
	Vector4 color_;

	KamataEngine::Vector3 velocity_;

	bool isFinished_ = false;
	float counter_ = 0.0f;
	const float KDuration = 1.0f;

};
/*/