#pragma once
class Vector3;
class EulerAngles;
class Quaternion;
class RotationMatrix;

enum class AxisTypeEnum
{
	x,
	y,
	z
};

class Matrix4x3 {
public:
	float m11, m12, m13; 
	float m21, m22, m23;
	float m31, m32, m33;
	float tx, ty, tz;

	void identity();

	void zeroTranslation();

	void setTranslation(const Vector3 &d);
	void setupTranslation(const Vector3& d);

	void setupLocalToParent(const Vector3& pos, const EulerAngles& orient);
	void setupLocalToParent(const Vector3& pos, const RotationMatrix& orient);
	void setupParentToLocal(const Vector3& pos, const EulerAngles& orient);
	void setupParentToLocal(const Vector3& pos, const RotationMatrix& orient);

	void setupRotate(AxisTypeEnum& axis, float theta);
	void setupRotate(const Vector3 &axis, float theta);

	void fromQuaternion(const Quaternion& q);

	void setupScale(const Vector3& s);

	void setupScaleAlongAxis(const Vector3& axis, float k);

	void setupShear(AxisTypeEnum axis, float s, float t);

	//构造投影矩阵，投影平面过原点,且垂直于单位向量n
	void setupProject(const Vector3& n);

	//构造反射矩阵
	void setupReflect(AxisTypeEnum axis, float k = 0.0f);

	//构造任意平面反射的矩阵
	void setupReflect(const Vector3& n);

};

//运算符* 用来变换点或连接矩阵，乘法的顺序从左往右沿变换的顺序进行
Vector3 operator* (const Vector3& p, const Matrix4x3& m);
Matrix4x3 operator* (const Matrix4x3& a, const Matrix4x3& b);


//运算符*=，保持和c++标准语法的一致性
Vector3& operator*= (Vector3& p, const Matrix4x3& m);
Matrix4x3& operator*= (Matrix4x3& a, const Matrix4x3& b);

//计算3x3部分的行列式值
float determinant(const Matrix4x3& m);

//计算矩阵的逆
Matrix4x3 inverse(const Matrix4x3& m);

//提取矩阵的平移部分
Vector3 getTranslation(const Matrix4x3& m);

//从矩阵中获取方位
//从父矩阵——局部矩阵矩阵中获取方位
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3& m);
//从局部矩——父矩阵阵矩阵中获取方位
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3& m);