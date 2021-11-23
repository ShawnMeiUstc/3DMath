#pragma once
#include <algorithm>
extern class Vector3;

bool floatEqual(const float x, const float y) {
	return abs(x - y) < 1e-10f;
}

bool isZeroVector(const Vector3& a) {
	return floatEqual(a.x, 0.0f) && floatEqual(a.y, 0.0f) && floatEqual(a.z, 0.0f);
}