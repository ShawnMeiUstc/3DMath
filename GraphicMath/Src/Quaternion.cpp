#include <cassert>
#include "Util.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "EulerAngles.h"

const Quaternion kQuaternionIdentity = { 1.0f, 0.0f, 0.0f, 0.0f };

void Quaternion::setToRotateAboutX(float theta)
{
	float thetaOver2 = theta * 0.5;
	w = cos(thetaOver2);
	x = sin(thetaOver2);
	y = 0.0f;
	z = 0.0f;
}

void Quaternion::setToRotateAboutY(float theta)
{
	float thetaOver2 = theta * 0.5;
	w = cos(thetaOver2);
	x = 0.0f;
	y = sin(thetaOver2);
	z = 0.0f;
}

void Quaternion::setToRotateAboutZ(float theta)
{
	float thetaOver2 = theta * 0.5;
	w = cos(thetaOver2);
	x = 0.0f;
	y = 0.0f;
	z = sin(thetaOver2);
}

void Quaternion::setToRotateAboutAxis(const Vector3& axis, float theta)
{
	assert(fabs(magtitude(axis) - 1.0f) < .01f);

	float thetaOver2 = theta * 0.5f;
	float sinThetaOver2 = sin(thetaOver2);

	w = cos(thetaOver2);
	x = axis.x * sinThetaOver2;
	y = axis.y * sinThetaOver2;
	z = axis.z * sinThetaOver2;
}

void Quaternion::setToRotateObjectToInertial(const EulerAngles& orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(sp, cp, orientation.pitch * 0.5f);
	sinCos(sb, cb, orientation.bank * 0.5f);
	sinCos(sh, ch, orientation.heading * 0.5f);

	w = ch * cp * cb + sh * sp * sb;
	x = ch * sp * cb + sh * cp * sb;
	y = -ch * sp * sb + sh * cp * cb;
	z = -sh * sp * cb + ch * cp * sb;

}

void Quaternion::setToRotateInertialToObject(const EulerAngles& orientation)
{
	float sp, sb, sh;
	float cp, cb, ch;
	sinCos(sp, cp, orientation.pitch * 0.5f);
	sinCos(sb, cb, orientation.bank * 0.5f);
	sinCos(sh, ch, orientation.heading * 0.5f);

	w = ch * cp * cb + sh * sp * sb;
	x = -(ch * sp * cb + sh * cp * sb);
	y = -(ch * sp * sb - sh * cp * cb);
	z = -(sh * sp * cb - ch * cp * sb);
}

Quaternion Quaternion::operator*(const Quaternion& a) const
{
	Quaternion result;
	result.w = w * a.w - x * a.x - y * a.y - z * a.z;
	result.x = w * a.x + x * a.w + z * a.y - y * a.z;
	result.y = w * a.y + y * a.w - x * a.z - z * a.x;
	result.z = w * a.z + z * a.w + y * a.x - x * a.y;
	return result;
}

Quaternion& Quaternion::operator*=(const Quaternion& a)
{
	*this = *this * a;
	return *this;
}

void Quaternion::normalize()
{
	float mag = (float)sqrt(w * w + x * x + y * y + z * z);
	if (mag > 0.0f) {
		float oneOverMag = 1.0f / mag;
		w *= oneOverMag;
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
	}
	else {
		identity();
	}
}

float Quaternion::getRotationAngle() const
{
	float thetaOver2 = safeAcos(w);
	return thetaOver2 * 2.0f;
}

Vector3 Quaternion::getRotationAxis() const
{
	float sinThetaOver2Square = 1.0f - w*w;
	if (sinThetaOver2Square <= 0.0f) {
		return Vector3(1.0f, 0.0f, 0.0f);
	}
	float oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Square);

	return Vector3 (x * oneOverSinThetaOver2,
		y * oneOverSinThetaOver2,
		z * oneOverSinThetaOver2);
}

float dotPruduct(const Quaternion& a, const Quaternion& b)
{
	return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

Quaternion slerp(const Quaternion& p, const Quaternion& q, float t)
{
	// TODO 点乘求出两四元数的夹角，再者，vt 是 p q 的线性组合 求出系数，即可以得出vt的表示
	return Quaternion();
}

Quaternion conjugate(const Quaternion& q)
{
	Quaternion result;
	result.w = q.w;
	result.x = q.x;
	result.y = q.y;
	result.z = q.z;
	return result;
}

Quaternion pow(const Quaternion& q, float exp)
{
	// TODO  求出角度θ，新的角度为exp*θ，带入求新的四元数即可
	
	return Quaternion();
}
