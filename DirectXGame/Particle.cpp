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
}

void Particle::Update() {

	objectColor_.SetColor(color_);

	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;


	worldTransform_.TransferMatrix();

	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) {
	// モデル描画
	model_->Draw(worldTransform_, camera, &objectColor_);
}