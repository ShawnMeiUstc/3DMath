#pragma once

class Vector3;
class EulerAngles;

class Quaternion {
public :
	float w, x, y, z;
	void identity() {
		w = 1.0f;
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	void setToRotateAboutX(float theta);
	void setToRotateAboutY(float theta);
	void setToRotateAboutZ(float theta);
	void setToRotateAboutAxis(const Vector3& axis, float theta);

	void setToRotateObjectToInertial(const EulerAngles& orientation);
	void setToRotateInertialToObject(const EulerAngles& orientation);

	Quaternion operator* (const Quaternion& a) const;
	/// <summary>
	///  调用对象可作为左值，不能是const
	/// </summary>
	Quaternion& operator*= (const Quaternion& a);

	void normalize();

	float getRotationAngle() const;
	Vector3 getRotationAxis() const;
};

extern const Quaternion kQuaternionIdentity;

extern float dotPruduct(const Quaternion& a, const Quaternion& b);

extern Quaternion slerp(const Quaternion& p, const Quaternion& q, float t);

extern Quaternion conjugate(const Quaternion& q);

extern Quaternion pow(const Quaternion& q, float exp);