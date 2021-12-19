#include "Util.h"
#include "Vector3.h"

const Vector3 kZeroVector{0.0f, 0.0f, 0.0f};

/// <summary>
/// �Ƚ�������-�е���֮��
/// </summary>
inline float wrapPI(float theta)
{
	theta += KPI;
	/// <summary>
	/// floor����һ��С�ڴ��������������� 
	/// </summary>
	theta -= floor(theta * K1OVER2PI) * K2PI;
	theta -= KPI;
	return theta;
}

inline float safeAcos(float x)
{
	if (x <= -1.0f) {
		return KPI;
	}
	if (x >= 1.0f) {
		return KPI;
	}
	return acos(x);
}

/// <summary>
/// �����������������ཻ���
/// </summary>
/// <param name="orig">�������</param>
/// <param name="dir">���߷�������</param>
/// <param name="v0">�����ζ���</param>
/// <param name="v1">�����ζ���</param>
/// <param name="v2">�����ζ���</param>
/// <param name="t">�ཻʱ���߲���ֵ P = orig + dir��t </param>
/// <param name="u">���������������µĲ���ֵ</param>
/// <param name="v">���������������µĲ���ֵ</param>
/// <returns>�Ƿ��ཻ</returns>
bool IntersectTriangle(const Vector3& orig, const Vector3& dir,
    Vector3& v0, Vector3& v1, Vector3& v2,
    float* t, float* u, float* v)
{
    // E1
    Vector3 E1 = v1 - v0;

    // E2
    Vector3 E2 = v2 - v0;

    // P
    Vector3 P = crossProduct(dir, E2);

    // determinant
    float det = dotProduct(E1, P);

    // keep det > 0, modify T accordingly
    Vector3 T;
    if (det > 0)
    {
        T = orig - v0;
    }
    else
    {
        T = v0 - orig;
        det = -det;
    }

    // If determinant is near zero, ray lies in plane of triangle
    if (det < 0.0001f)
        return false;

    // Calculate u and make sure u <= 1
    *u = dotProduct(T, P);
    if (*u < 0.0f || *u > det)
        return false;

    // Q
    Vector3 Q = crossProduct(T,P);

    // Calculate v and make sure u + v <= 1
    *v = dotProduct(dir, Q);
    if (*v < 0.0f || *u + *v > det)
        return false;

    // Calculate t, scale parameters, ray intersects triangle
    *t = dotProduct(E2, Q);

    float fInvDet = 1.0f / det;
    *t *= fInvDet;
    *u *= fInvDet;
    *v *= fInvDet;

    return true;
}
