#pragma once
#include <algorithm>

bool floatEqual(const float x, const float y) {
	return abs(x - y) < 1e-10f;
}