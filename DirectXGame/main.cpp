#include "KamataEngine.h"
#include <Windows.h>
#include "GameScene.h"
#include "TitleScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	KamataEngine::Initialize(L"LE3C_01_イシイ_ハヤト");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	TitleScene* titleScene = new TitleScene();
	titleScene->Initialize();

	GameScene* gameScene = new GameScene();
	gameScene->Initialize();

	// タイトルシーンループ
	while (!titleScene->IsEnd()) {
		if (KamataEngine::Update())
			break;

		titleScene->Update();

		dxCommon->PreDraw();

		titleScene->Draw();

		dxCommon->PostDraw();
	}
	delete titleScene;

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		gameScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		gameScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	delete gameScene;
	gameScene = nullptr;

	KamataEngine::Finalize();

	return 0;
}