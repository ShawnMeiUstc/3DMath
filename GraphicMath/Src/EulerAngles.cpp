#include "Util.h"
#include "EulerAngles.h"
#include "Quaternion.h"
#include "Matrix4x3.h"
#include "RotationMatrix.h"

const EulerAngles kEulerAnglesIdentity(0.0f, 0.0f, 0.0f);

void EulerAngles::canonize()
{
	pitch = wrapPI(pitch);
	if (pitch < -KPIOVER2) {
		pitch = -KPI - pitch;
		heading += KPI;
		bank += KPI;
	}
	else if (pitch > KPIOVER2){
		pitch = KPI - pitch;
		heading += KPI;
		bank += KPI;
	}

	if (fabs(pitch) > KPIOVER2 - 1e-4) {
		heading += bank;
		bank = 0.0f;
	}
	else {
		bank = wrapPI(bank);
	}
	heading = wrapPI(heading);
}

void EulerAngles::fromObjectToInertialQuaternion(const Quaternion& q)
{
	float sp = -2.0f * (q.y * q.z - q.w * q.x);
	if (fabs(sp) > 0.9999f) {
		pitch = KPIOVER2 * sp;
		heading = atan2(-q.x * q.z + q.w * q.y, 0.5f - q.y * q.y - q.z * q.z);
		bank = 0.0f;
	}
	else {
		pitch = asin(sp);
		heading = atan2(q.x * q.z + q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
		bank = atan2(q.x * q.y + q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
	}
}

void EulerAngles::fromInertialToObjectQuaternion(const Quaternion& q)
{
	float sp = -2.0f * (q.y * q.z + q.w * q.x);
	if (fabs(sp) > 0.9999f) {
		pitch = KPIOVER2 * sp;
		heading = atan2(-q.x * q.z + q.w * q.y, 0.5f - q.y * q.y - q.z * q.z);
		bank = 0.0f;
	}
	else {
		pitch = asin(sp);
		heading = atan2(q.x * q.z - q.w * q.y, 0.5f - q.x * q.x - q.y * q.y);
		bank = atan2(q.x * q.y - q.w * q.z, 0.5f - q.x * q.x - q.z * q.z);
	}
}

void EulerAngles::fromObjectToWorldMatrix(const Matrix4x3& m)
{
	/// ...
}

void EulerAngles::fromWorldToObjectMatrix(const Matrix4x3& m)
{
	/// ...
}

void EulerAngles::fromRotationMatrix(const RotationMatrix& m)
{
	/// ...
}
