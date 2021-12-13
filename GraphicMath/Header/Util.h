#pragma once
#include <algorithm>
#include <cmath>

const float KPI = 3.14159265f;
const float KPIOVER2 = KPI / 2.0f;
const float K2PI = KPI * 2.0f;
const float K1OVERPI = 1.0f / KPI;
const float K1OVER2PI = 1.0f / K2PI;

/// extern�����ȫ�ֱ���/�����������ͷ�ļ������Դ�ļ����ã���ñ����������ظ�������extern
/// �ᱨ������������
/// Ҳ������һ��ͬһ�����²�ͬģ�飨.cpp���乲��һЩ������һ��cpp�ж��壬��һ��֮����extern
/// �����������øñ�����
extern float wrapPI(float theta);
extern float safeAcos(float x);
inline void sinCos(float& returnSin, float& returnCos, float theta) {
	returnSin = sin(theta);
	returnCos = cos(theta);
}





