#pragma once
#include "KamataEngine.h"
#include <cstdint>

using namespace KamataEngine;

class TitleScene {
public:

	~TitleScene();
	void Initialize();
	void Update();
	void Draw();
	bool IsEnd() const { return isEnd_; }

private:

	uint32_t textureHandle_ = 0;
	uint32_t textureHandle2_ = 0;

	Sprite* sprite_ = nullptr;
	Sprite* sprite2_ = nullptr;

	Input* input_ = nullptr;

	int blinkTimer_ = 0;

	bool isEnd_ = false;
};