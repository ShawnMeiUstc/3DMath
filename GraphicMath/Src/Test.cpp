#include <iostream>
#include "Vector3.h"
#include "EulerAngles.h"
#include "Matrix4x3.h"
#include "Quaternion.h"


int main() {
	Vector3 v{};
	EulerAngles e{};
	Matrix4x3 m{};
	Quaternion q{};

	std::cout << v.x << " " << e.heading << " " << m.m11 << " " << q.w << std::endl;
}