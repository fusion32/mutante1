#include "vector4.h"

#include <math.h>

// default vectors
// ===============
//

// vector utility
// ==============
void vec4_copy(Vector4 *dst, const Vector4 *src)
{
	// memcpy(dst, src, sizeof(Vector4));

	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->w = src->w;
}

// vector arithmetic
// =================
float vec4_norm(const Vector4 *v)
{
	return sqrtf(
		v->x * v->x +
		v->y * v->y +
		v->z * v->z +
		v->w * v->w);
}

float vec4_sqrnorm(const Vector4 *v)
{
	return
		v->x * v->x +
		v->y * v->y +
		v->z * v->z +
		v->w * v->w;
}

void vec4_normalize(Vector4 *v)
{
	float norm = 1.0f / sqrtf(
						v->x * v->x +
						v->y * v->y +
						v->z * v->z +
						v->w * v->w);

	v->x *= norm;
	v->y *= norm;
	v->z *= norm;
	v->w *= norm;
}

void vec4_multf(Vector4 *v, const float f)
{
	v->x *= f;
	v->y *= f;
	v->z *= f;
	v->w *= f;
}

void vec4_add(Vector4 *v, const Vector4 *u)
{
	v->x += u->x;
	v->y += u->y;
	v->z += u->z;
	v->w += u->w;
}

void vec4_sub(Vector4 *v, const Vector4 *u)
{
	v->x -= u->x;
	v->y -= u->y;
	v->z -= u->z;
	v->w -= u->w;
}

float vec4_dot(const Vector4 *v, const Vector4 *u)
{
	return
		v->x * u->x +
		v->y * u->y +
		v->z * u->z +
		v->w * u->w;
}