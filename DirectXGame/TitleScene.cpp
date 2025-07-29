#include "TitleScene.h"
#include "KamataEngine.h"
#include <Windows.h>

using namespace KamataEngine;

TitleScene::~TitleScene() { delete sprite_; }

void TitleScene::Initialize() {

	input_ = KamataEngine::Input::GetInstance();

	textureHandle_ = TextureManager::Load("Title.png");
	textureHandle2_ = TextureManager::Load("TitleSpace.png");

	sprite_ = Sprite::Create(textureHandle_, {100, -700});
	sprite2_ = Sprite::Create(textureHandle2_, {100, -700});
}

void TitleScene::Update() {

	Vector2 position = sprite_->GetPosition();
	Vector2 position2 = sprite2_->GetPosition();

	blinkTimer_++;

	if (position.y < -100) {
		position.y += 3.0f; // スプライトの位置を下に移動
		position2.y += 3.0f;
	} else {
		position.y = -100; // 最低位置を設定
		position2.y = -100;
	}

	sprite_->SetPosition(position);
	sprite2_->SetPosition(position2);

	// SPACEキーで終了フラグ
	if (input_->TriggerKey(DIK_SPACE)) {
		isEnd_ = true;
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	if ((blinkTimer_ / 30) % 2 == 0) {
		sprite2_->Draw();
	}

	Sprite::PostDraw();
}