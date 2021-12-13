#include "Util.h"

/// <summary>
/// θ角限制在-π到π之间
/// </summary>
inline float wrapPI(float theta)
{
	theta += KPI;
	/// <summary>
	/// floor返回一个小于传入参数的最大整数 
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
