#ifndef __MATRIX4_H__
#define __MATRIX4_H__

typedef struct Matrix4{
	float
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44;
} Matrix4;

typedef struct Vector2 Vector2;
typedef struct Vector3 Vector3;
typedef struct Vector4 Vector4;

// identity
// ========
extern		const Matrix4 *mat4_identity;

// matrix utility
// ==============
void		mat4_copy(Matrix4 *dst, const Matrix4 *src);
void		mat4_transpose(Matrix4 *dst, const Matrix4 *src);

void		mat4_multv2(Vector2 *dst, const Matrix4 *a, const Vector2 *v);
void		mat4_multv3(Vector3 *dst, const Matrix4 *a, const Vector3 *v);
void		mat4_multv4(Vector4 *dst, const Matrix4 *a, const Vector4 *v);

// matrix arithmetic
// =================
void		mat4_add(Matrix4 *a, const Matrix4 *b);
void		mat4_sub(Matrix4 *a, const Matrix4 *b);
void		mat4_multf(Matrix4 *a, const float f);
void		mat4_mult(Matrix4 *dst, const Matrix4 *a, const Matrix4 *b);

#endif //__MATRIX4_H__