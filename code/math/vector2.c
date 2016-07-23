#include "vector2.h"

#include <math.h>

// default vectors
// ===============

static const Vector2 l_zero				= {0.0f, 0.0f};
static const Vector2 l_up				= {0.0f, 1.0f};
static const Vector2 l_right			= {1.0f, 0.0f};

const Vector2 *vec2_zero				= &l_zero;
const Vector2 *vec2_up					= &l_up;
const Vector2 *vec2_right				= &l_right;


// vector utility
// ==============

void vec2_copy(Vector2 *dst, const Vector2 *src)
{
	// memcpy(dst, src, sizeof(Vector2));

	dst->x = src->x;
	dst->y = src->y;
}


// vector arithmetic
// =================

float vec2_norm(const Vector2 *v)
{
	return sqrtf(
		v->x * v->x +
		v->y * v->y);
}

float vec2_sqrnorm(const Vector2 *v)
{
	return
		v->x * v->x +
		v->y * v->y;
}

void vec2_normalize(Vector2 *v)
{
	float norm = 1.0f / sqrtf(
						v->x * v->x +
						v->y * v->y);

	v->x *= norm;
	v->y *= norm;
}

void vec2_multf(Vector2 *v, const float f)
{
	v->x *= f;
	v->y *= f;
}

void vec2_add(Vector2 *v, const Vector2 *u)
{
	v->x += u->x;
	v->y += u->y;
}

void vec2_sub(Vector2 *v, const Vector2 *u)
{
	v->x -= u->x;
	v->y -= u->y;
}

float vec2_dot(const Vector2 *v, const Vector2 *u)
{
	return
		v->x * u->x +
		v->y * u->y;
}