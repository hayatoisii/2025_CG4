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

	KamataEngine::Sprite* sprite_ = nullptr;

	Input* input_ = nullptr;

	bool isEnd_ = false;
};