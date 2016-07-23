#include "matrix4.h"

#include "vector2.h"
#include "vector3.h"
#include "vector4.h"

static const Matrix4 l_mat4_identity = {
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

const Matrix4 *mat4_identity = &l_mat4_identity;


// matrix utility
// ==============

void mat4_copy(Matrix4 *dst, const Matrix4 *src)
{
	// memcpy(dst, src, sizeof(Matrix4));

	dst->m11 = src->m11;
	dst->m12 = src->m12;
	dst->m13 = src->m13;
	dst->m14 = src->m14;

	dst->m21 = src->m21;
	dst->m22 = src->m22;
	dst->m23 = src->m23;
	dst->m24 = src->m24;

	dst->m31 = src->m31;
	dst->m32 = src->m32;
	dst->m33 = src->m33;
	dst->m34 = src->m34;

	dst->m41 = src->m41;
	dst->m42 = src->m42;
	dst->m43 = src->m43;
	dst->m44 = src->m44;
}

void mat4_transpose(Matrix4 *dst, const Matrix4 *src)
{
	dst->m11 = src->m11;
	dst->m12 = src->m21;
	dst->m13 = src->m31;
	dst->m14 = src->m41;

	dst->m21 = src->m12;
	dst->m22 = src->m22;
	dst->m23 = src->m32;
	dst->m24 = src->m42;

	dst->m31 = src->m13;
	dst->m32 = src->m23;
	dst->m33 = src->m33;
	dst->m34 = src->m43;

	dst->m41 = src->m14;
	dst->m42 = src->m24;
	dst->m43 = src->m34;
	dst->m44 = src->m44;
}

void mat4_multv2(Vector2 *dst, const Matrix4 *a, const Vector2 *v)
{
	dst->x = a->m11 * v->x + a->m12 * v->y;
	dst->y = a->m21 * v->x + a->m22 * v->y;
}

void mat4_multv3(Vector3 *dst, const Matrix4 *a, const Vector3 *v)
{
	dst->x = a->m11 * v->x + a->m12 * v->y + a->m13 * v->z;
	dst->y = a->m21 * v->x + a->m22 * v->y + a->m23 * v->z;
	dst->z = a->m31 * v->x + a->m32 * v->y + a->m33 * v->z;
}

void mat4_multv4(Vector4 *dst, const Matrix4 *a, const Vector4 *v)
{
	dst->x = a->m11 * v->x + a->m12 * v->y + a->m13 * v->z + a->m14 * v->w;
	dst->y = a->m21 * v->x + a->m22 * v->y + a->m23 * v->z + a->m24 * v->w;
	dst->z = a->m31 * v->x + a->m32 * v->y + a->m33 * v->z + a->m34 * v->w;
	dst->w = a->m41 * v->x + a->m42 * v->y + a->m43 * v->z + a->m44 * v->w;
}

// matrix arithmetic
// =================

void mat4_add(Matrix4 *a, const Matrix4 *b)
{
	a->m11 += b->m11;
	a->m12 += b->m12;
	a->m13 += b->m13;
	a->m14 += b->m14;

	a->m21 += b->m21;
	a->m22 += b->m22;
	a->m23 += b->m23;
	a->m24 += b->m24;

	a->m31 += b->m31;
	a->m32 += b->m32;
	a->m33 += b->m33;
	a->m34 += b->m34;

	a->m41 += b->m41;
	a->m42 += b->m42;
	a->m43 += b->m43;
	a->m44 += b->m44;
}

void mat4_sub(Matrix4 *a, const Matrix4 *b)
{
	a->m11 -= b->m11;
	a->m12 -= b->m12;
	a->m13 -= b->m13;
	a->m14 -= b->m14;

	a->m21 -= b->m21;
	a->m22 -= b->m22;
	a->m23 -= b->m23;
	a->m24 -= b->m24;

	a->m31 -= b->m31;
	a->m32 -= b->m32;
	a->m33 -= b->m33;
	a->m34 -= b->m34;

	a->m41 -= b->m41;
	a->m42 -= b->m42;
	a->m43 -= b->m43;
	a->m44 -= b->m44;
}

void mat4_multf(Matrix4 *a, const float f)
{
	a->m11 *= f;
	a->m12 *= f;
	a->m13 *= f;
	a->m14 *= f;

	a->m21 *= f;
	a->m22 *= f;
	a->m23 *= f;
	a->m24 *= f;

	a->m31 *= f;
	a->m32 *= f;
	a->m33 *= f;
	a->m34 *= f;

	a->m41 *= f;
	a->m42 *= f;
	a->m43 *= f;
	a->m44 *= f;
}

void mat4_mult(Matrix4 *dst, const Matrix4 *a, const Matrix4 *b)
{
	dst->m11 = a->m11 * b->m11 + a->m12 * b->m21 + a->m13 * b->m31 + a->m14 * b->m41;
	dst->m12 = a->m11 * b->m12 + a->m12 * b->m22 + a->m13 * b->m32 + a->m14 * b->m42;
	dst->m13 = a->m11 * b->m13 + a->m12 * b->m23 + a->m13 * b->m33 + a->m14 * b->m43;
	dst->m14 = a->m11 * b->m14 + a->m12 * b->m23 + a->m13 * b->m34 + a->m14 * b->m44;

	dst->m21 = a->m21 * b->m11 + a->m22 * b->m21 + a->m23 * b->m31 + a->m24 * b->m41;
	dst->m22 = a->m21 * b->m12 + a->m22 * b->m22 + a->m23 * b->m32 + a->m24 * b->m42;
	dst->m23 = a->m21 * b->m13 + a->m22 * b->m23 + a->m23 * b->m33 + a->m24 * b->m43;
	dst->m24 = a->m21 * b->m14 + a->m22 * b->m24 + a->m23 * b->m34 + a->m24 * b->m44;

	dst->m31 = a->m31 * b->m11 + a->m32 * b->m21 + a->m33 * b->m31 + a->m34 * b->m41;
	dst->m32 = a->m31 * b->m12 + a->m32 * b->m22 + a->m33 * b->m32 + a->m34 * b->m42;
	dst->m33 = a->m31 * b->m13 + a->m32 * b->m23 + a->m33 * b->m33 + a->m34 * b->m43;
	dst->m34 = a->m31 * b->m14 + a->m32 * b->m24 + a->m33 * b->m34 + a->m34 * b->m44;

	dst->m41 = a->m41 * b->m11 + a->m42 * b->m21 + a->m43 * b->m31 + a->m44 * b->m41;
	dst->m42 = a->m41 * b->m12 + a->m42 * b->m22 + a->m43 * b->m32 + a->m44 * b->m42;
	dst->m43 = a->m41 * b->m13 + a->m42 * b->m23 + a->m43 * b->m33 + a->m44 * b->m43;
	dst->m44 = a->m41 * b->m14 + a->m42 * b->m24 + a->m43 * b->m34 + a->m44 * b->m44;
}