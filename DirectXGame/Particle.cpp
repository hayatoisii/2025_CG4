#include "Particle.h"

using namespace MathUtility;

Particle::~Particle() {}

void Particle::Initialize(Model* model, Vector3 position) {
	assert(model);

	model_ = model;
	worldTransform_.Initialize();

	worldTransform_.translation_ = position;

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};
}

void Particle::Update() {

	objectColor_.SetColor(color_);

	worldTransform_.translation_ += {0.0f, 0.0f, 0.0f};

	worldTransform_.TransferMatrix();

	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) {
	// モデル描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}