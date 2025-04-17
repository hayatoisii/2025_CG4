#include "Particle.h"

Particle::~Particle() {}

void Particle::Initialize(Model* model) { 
	assert(model);

	model_ = model;
	worldTransform_.Initialize();

}

void Particle::Update() {

	worldTransform_.TransferMatrix(); }

void Particle::Draw(Camera& camera) {
	// モデル描画
	model_->Draw(worldTransform_, camera);
}


