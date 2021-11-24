#pragma once
#include "Util.h"
#include "Stdafx.h"

class Vector3 {
public:
	float x, y, z;
	Vector3() = default;
	Vector3(const Vector3& a) : x(a.x), y(a.y), z(a.z) {}
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	Vector3& operator=(const Vector3& rhs) {  // p493 = [] () -> 必须是成员 返回引用模拟连续赋值
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	Vector3& operator+=(const Vector3& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	Vector3& operator-=(const Vector3& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	Vector3& operator*=(const float num) {
		x *= num;
		y *= num;
		z *= num;
		return *this;
	}
	Vector3& operator/=(const float num) {
		assert(floatEqual(num, 0.0f));
		const float oneOverNum = 1.0f / num;
		x *= oneOverNum;
		y *= oneOverNum;
		z *= oneOverNum;
		return *this;
	}

	void zero() { x = y = z = 0.0f; }
	void normalize() {
		assert(!isZeroVector(*this));
		const float oneOverMag = 1.0f / sqrt(x * x + y * y + z * z);
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
};

inline bool operator==(const Vector3& lhs, const Vector3& rhs) { // p493 对称性运算符，算术、相等性、关系、位运算符等，
	return floatEqual(lhs.x, rhs.x) &&                    // 任一端运算对象可能发生类型转换，最好非成员
		floatEqual(lhs.y, rhs.y) &&
		floatEqual(lhs.z, rhs.z);
}

inline bool operator!=(const Vector3& lhs, const Vector3& rhs) {
	return !(lhs == rhs);
}

inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs) {
	return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs) {
	return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline Vector3 operator*(const Vector3& a, float num) {
	return Vector3(num * a.x, num * a.y, num * a.z);
}

inline Vector3 operator*(float num, const Vector3& a) { // 左乘一个数
	return Vector3(num * a.x, num * a.y, num * a.z);
}

inline Vector3 operator/(const Vector3& a, const float num) {
	assert(floatEqual(num, 0.0f));
	const float oneOverNum = 1.0f / num;                                // 尽量用乘法代替除法
	return Vector3(oneOverNum * a.x, oneOverNum * a.y, oneOverNum * a.z);
}

inline Vector3 operator-(const Vector3& a) {
	return Vector3(-a.x, -a.y, -a.z);
}

inline float magtitude(const Vector3& a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline float dotProduct(const Vector3& lhs, const Vector3& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline Vector3 crossProduct(const Vector3& lhs, const Vector3& rhs) {
	return Vector3(
		lhs.y * rhs.z - rhs.y * lhs.z,
		lhs.z * rhs.x - rhs.z * lhs.x,
		lhs.x * rhs.y - rhs.x * lhs.y
	);
}

inline float distance(const Vector3& a, const Vector3& b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

