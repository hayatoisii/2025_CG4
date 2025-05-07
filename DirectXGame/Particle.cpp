#include "Particle.h"

using namespace MathUtility;

Particle::~Particle() {}

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);

	model_ = model;
	worldTransform_.Initialize();

	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.1f, 0.1f, 0.1f};

	velocity_ = velocity;

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.TransferMatrix();
	worldTransform_.UpdateMatrix();
}

void Particle::Update() {

	objectColor_.SetColor(color_);

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;

	if (isFinished_) {
		return;
	}
	counter_ += 1.0f / 60.0f;

	if (counter_ >= KDuration) {
		counter_ = KDuration;
		isFinished_ = true;
	}

	color_.w = std::clamp(1.0f - counter_ / KDuration, 0.0f, 1.0f);

	worldTransform_.TransferMatrix();
	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) {
	// モデル描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}