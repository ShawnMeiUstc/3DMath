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





