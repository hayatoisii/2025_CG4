#include "Particle.h"
#include <cassert>

Particle::~Particle() {}

void Particle::Initialize(Model2* model) { 
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