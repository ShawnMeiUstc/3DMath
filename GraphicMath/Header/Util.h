/// 对变量而言，如果你想在本源文件中使用另一个源文件的变量（注意：此时这个变量应该是全局变量，定义它的位置是在所有函数之外），
/// 就需要在使用前用extern声明该变量，或者在头文件中用extern声明该变量；
///
/// 对函数而言，如果你想在本源文件中使用另一个源文件的函数（注意：此时这个函数应该是全局函数，定义它的位置是在所有函数之外），
/// 就需要在使用前用声明该函数，声明函数加不加extern都没关系，所以在头文件中函数可以不用加extern。

#pragma once
#include <algorithm>
#include <cmath>
const float KPI = 3.14159265f;
const float KPIOVER2 = KPI / 2.0f;
const float K2PI = KPI * 2.0f;
const float K1OVERPI = 1.0f / KPI;
const float K1OVER2PI = 1.0f / K2PI;



float wrapPI(float theta);
float safeAcos(float x);
inline void sinCos(float& returnSin, float& returnCos, float theta) {
	returnSin = sin(theta);
	returnCos = cos(theta);
}
class Vector3;
/// <summary>
/// 快速射线与三角形相交检测 思想就是射线方程和重心坐标参数方程联立，解得交点
/// https://www.cnblogs.com/graphics/archive/2010/08/09/1795348.html
/// </summary>
/// <param name="orig">射线起点</param>
/// <param name="dir">射线方向向量</param>
/// <param name="v0">三角形顶点</param>
/// <param name="v1">三角形顶点</param>
/// <param name="v2">三角形顶点</param>
/// <param name="t">相交时射线参数值 P = orig + dir·t </param>
/// <param name="u">交点在重心坐标下的参数值</param>
/// <param name="v">交点在重心坐标下的参数值</param>
/// <returns>是否相交</returns>
bool IntersectTriangle(const Vector3& orig, const Vector3& dir,
	Vector3& v0, Vector3& v1, Vector3& v2,
	float* t, float* u, float* v);


// https://zhuanlan.zhihu.com/p/99761177
// 凸多边形的相交性检测的分离轴定理



