#include "TitleScene.h"
#include "KamataEngine.h"
#include <Windows.h>

using namespace KamataEngine;

TitleScene::~TitleScene() { delete sprite_; }

void TitleScene::Initialize() {

	input_ = KamataEngine::Input::GetInstance();

	textureHandle_ = TextureManager::Load("Title.png");

	sprite_ = Sprite::Create(textureHandle_, {100, -700});
}

void TitleScene::Update() {

	Vector2 position = sprite_->GetPosition();

	if (position.y < -100) {
		position.y += 3.0f; // スプライトの位置を下に移動
	} else {
		position.y = -100; // 最低位置を設定
	}

	sprite_->SetPosition(position);

	// SPACEキーで終了フラグ
	if (input_->TriggerKey(DIK_SPACE)) {
		isEnd_ = true;
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	Sprite::PostDraw();
}