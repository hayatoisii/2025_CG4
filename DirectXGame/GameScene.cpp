#include "GameScene.h"

GameScene::~GameScene() { 

}

void GameScene::Initialize() {

	stage_ = new Stage();
	stage_->Initialize();

	player_ = new Player();
	player_->Initialize();

	graph_ = new Graph();
	graph_->Initialize();

	// カメラの初期化
	camera_.Initialize();

	worldTransform.Initialize();
}

void GameScene::Update() {

	stage_->Update();

	player_->Update();

	graph_->Update();

}

void GameScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	graph_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model::PreDraw(dxCommon->GetCommandList());

	player_->Draw();

	Model::PostDraw();
}