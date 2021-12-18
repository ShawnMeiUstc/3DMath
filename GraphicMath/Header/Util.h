#pragma once
#include <algorithm>
#include <cmath>

const float KPI = 3.14159265f;
const float KPIOVER2 = KPI / 2.0f;
const float K2PI = KPI * 2.0f;
const float K1OVERPI = 1.0f / KPI;
const float K1OVER2PI = 1.0f / K2PI;

/// extern定义的全局变量/函数，如果该头文件被多个源文件引用，则该变量名不会重复，不加extern
/// 会报重名变量错误
/// 也可以在一个同一工程下不同模块（.cpp）间共享一些变量（一个cpp中定义，另一个之中用extern
/// 声明即可引用该变量）
extern float wrapPI(float theta);
extern float safeAcos(float x);
inline void sinCos(float& returnSin, float& returnCos, float theta) {
	returnSin = sin(theta);
	returnCos = cos(theta);
}
/// <summary>
/// 快速射线与三角形相交检测
/// </summary>
/// <param name="orig">射线起点</param>
/// <param name="dir"></param>
/// <param name="v0"></param>
/// <param name="v1"></param>
/// <param name="v2"></param>
/// <param name="t"></param>
/// <param name="u"></param>
/// <param name="v"></param>
/// <returns></returns>
extern bool IntersectTriangle(const Vector3& orig, const Vector3& dir,
	Vector3& v0, Vector3& v1, Vector3& v2,
	float* t, float* u, float* v);





