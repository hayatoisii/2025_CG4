#include "KamataEngine.h"
#include "MT.h"

using namespace KamataEngine;

void WorldTransform::UpdateMatrix() {

	Matrix4x4 matScale = MakeScaleMatrix(scale_);

	Matrix4x4 matRotX = MakeRotateXMatrix(rotation_.x);
	Matrix4x4 matRotY = MakeRotateYMatrix(rotation_.y);
	Matrix4x4 matRotZ = MakeRotateZMatrix(rotation_.z);
	Matrix4x4 matRot = Multiply(matRotX, Multiply(matRotY, matRotZ));

	Matrix4x4 matTrans = MakeTranslateMatrix(translation_);

	matWorld_ = Multiply(matScale, Multiply(matRot, matTrans));

	TransferMatrix();

}