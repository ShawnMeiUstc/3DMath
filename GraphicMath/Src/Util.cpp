#include "Util.h"

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
