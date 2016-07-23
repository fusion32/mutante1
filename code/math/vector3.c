#include "vector3.h"

#include <math.h>

// default vectors
// ===============

static const Vector3 l_zero				= {0.0f, 0.0f, 0.0f};
static const Vector3 l_up				= {0.0f, 1.0f, 0.0f};
static const Vector3 l_right			= {1.0f, 0.0f, 0.0f};
static const Vector3 l_forward			= {0.0f, 0.0f, -1.0f};

const Vector3 *vec3_zero				= &l_zero;
const Vector3 *vec3_up					= &l_up;
const Vector3 *vec3_right				= &l_right;
const Vector3 *vec3_forward				= &l_forward;

// vector utility
// ==============

void vec3_copy(Vector3 *dst, const Vector3 *src)
{
	// memcpy(dst, src, sizeof(Vector3));

	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

// vector arithmetic
// =================

float vec3_norm(const Vector3 *v)
{
	return sqrtf(
		v->x * v->x +
		v->y * v->y +
		v->z * v->z);
}

float vec3_sqrnorm(const Vector3 *v)
{
	return
		v->x * v->x +
		v->y * v->y +
		v->z * v->z;
}

void vec3_normalize(Vector3 *v)
{
	float norm = 1.0f / sqrtf(
						v->x * v->x +
						v->y * v->y +
						v->z * v->z);

	v->x *= norm;
	v->y *= norm;
	v->z *= norm;
}

void vec3_multf(Vector3 *v, const float f)
{
	v->x *= f;
	v->y *= f;
	v->z *= f;
}

void vec3_add(Vector3 *v, const Vector3 *u)
{
	v->x += u->x;
	v->y += u->y;
	v->z += u->z;
}

void vec3_sub(Vector3 *v, const Vector3 *u)
{
	v->x -= u->x;
	v->y -= u->y;
	v->z -= u->z;
}

float vec3_dot(const Vector3 *v, const Vector3 *u)
{
	return
		v->x * u->x +
		v->y * u->y +
		v->z * u->z;
}

void vec3_cross(Vector3 *dst, const Vector3 *v, const Vector3 *u)
{
	dst->x = (v->y * u->z - v->z * u->y);
	dst->y = (v->z * u->x - v->x * u->z);
	dst->z = (v->x * u->y - v->y * u->x);
}