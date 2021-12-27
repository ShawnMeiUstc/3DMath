/// �Ա������ԣ���������ڱ�Դ�ļ���ʹ����һ��Դ�ļ��ı�����ע�⣺��ʱ�������Ӧ����ȫ�ֱ�������������λ���������к���֮�⣩��
/// ����Ҫ��ʹ��ǰ��extern�����ñ�����������ͷ�ļ�����extern�����ñ�����
///
/// �Ժ������ԣ���������ڱ�Դ�ļ���ʹ����һ��Դ�ļ��ĺ�����ע�⣺��ʱ�������Ӧ����ȫ�ֺ�������������λ���������к���֮�⣩��
/// ����Ҫ��ʹ��ǰ�������ú��������������Ӳ���extern��û��ϵ��������ͷ�ļ��к������Բ��ü�extern��

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
/// �����������������ཻ��� ˼��������߷��̺������������������������ý���
/// https://www.cnblogs.com/graphics/archive/2010/08/09/1795348.html
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
	float* t, float* u, float* v);


// https://zhuanlan.zhihu.com/p/99761177
// ͹����ε��ཻ�Լ��ķ����ᶨ��



