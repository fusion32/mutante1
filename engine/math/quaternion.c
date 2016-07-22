#include "quaternion.h"

#include "vector3.h"
#include "matrix4.h"

#include <math.h>

// identity
// ========
static const Quaternion l_quat_identity = {1.0f, 0.0f, 0.0f, 0.0f};
const Quaternion *quat_identity = &l_quat_identity;

// quaternion utility
// ==================

void quat_copy(Quaternion *dst, const Quaternion *src)
{
	// memcpy(dst, src, sizeof(Quaternion));

	dst->w = src->w;
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

void quat_tomatrix(Matrix4 *dst, const Quaternion *q)
{
	dst->m11 = 1.0f - (2.0f * q->y * q->y) - (2.0f * q->z * q->z);
	dst->m12 = (2.0f * q->x * q->y) - (2.0f * q->z * q->w);
	dst->m13 = (2.0f * q->x * q->z) + (2.0f * q->y * q->w);
	dst->m14 = 0.0f;

	dst->m21 = (2.0f * q->x * q->y) + (2.0f * q->z * q->w);
	dst->m22 = 1.0f - (2.0f * q->x * q->x) - (2.0f * q->z * q->z);
	dst->m23 = (2.0f * q->y * q->z) - (2.0f * q->x * q->w);
	dst->m24 = 0.0f;

	dst->m31 = (2.0f * q->x * q->z) - (2.0f * q->y * q->w);
	dst->m32 = (2.0f * q->y * q->z) + (2.0f * q->x * q->w);
	dst->m33 = 1.0f - (2.0f * q->x * q->x) - (2.0f * q->y * q->y);
	dst->m34 = 0.0f;

	dst->m41 = 0.0f;
	dst->m42 = 0.0f;
	dst->m43 = 0.0f;
	dst->m44 = 1.0f;
}

void quat_angleaxis(Quaternion *dst, const float angle, const Vector3 *axis)
{
	Vector3 c;
	float rad = 0.5f * angle * DEG2RAD;
	float half_sin = sinf(rad);

	vec3_copy(&c, axis);
	vec3_normalize(&c);
	dst->w = cosf(rad);
	dst->x = half_sin * c.x;
	dst->y = half_sin * c.y;
	dst->z = half_sin * c.z;
}

void quat_rotationbetween(Quaternion *dst, const Vector3 *v, const Vector3 *u)
{
	Vector3 cross;
	Vector3 cv, cu;
	float m;

	vec3_copy(&cv, v);
	vec3_copy(&cu, u);
	vec3_normalize(&cv);
	vec3_normalize(&cu);

	m = sqrtf(2.0f + 2.0f * vec3_dot(&cv, &cu));
	vec3_cross(&cross, &cv, &cu);
	vec3_multf(&cross, 1.0f / m);

	dst->w = 0.5f * m;
	dst->x = cross.x;
	dst->y = cross.y;
	dst->z = cross.z;
}

void quat_rotatev3(Vector3 *dst, const Quaternion *q, const Vector3 *v)
{
	Quaternion res, tmp;
	Quaternion p = { 0.0f, v->x, v->y, v->z };
	Quaternion qconj = { q->w, -q->x, -q->y, -q->z};

	quat_mult(&tmp, q, &p);
	quat_mult(&res, &tmp, &qconj);
	dst->x = res.x;
	dst->y = res.y;
	dst->z = res.z;
}

// quaternion arithmetic
// ===============

float quat_norm(const Quaternion *q)
{
	return sqrtf(
		q->w * q->w +
		q->x * q->x +
		q->y * q->y +
		q->z * q->z);
}

float quat_sqrnorm(const Quaternion *q)
{
	return
		q->w * q->w +
		q->x * q->x +
		q->y * q->y +
		q->z * q->z;
}

void quat_normalize(Quaternion *q)
{
	float norm = 1.0f / sqrtf(
		q->w * q->w +
		q->x * q->x +
		q->y * q->y +
		q->z * q->z);

	q->w *= norm;
	q->x *= norm;
	q->y *= norm;
	q->z *= norm;
}

void quat_conjugate(Quaternion *q)
{
	q->x = -q->x;
	q->y = -q->y;
	q->z = -q->z;
}

void quat_mult(Quaternion *dst, const Quaternion *a, const Quaternion *b)
{
	dst->w = a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z;
	dst->x = a->w * b->x + b->w * a->x + a->y * b->z - b->y * a->z;
	dst->y = a->w * b->y + b->w * a->y - a->x * b->z + b->x * a->z;
	dst->z = a->w * b->z + b->w * a->z + a->x * b->y - b->x * a->y;
}