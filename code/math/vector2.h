#ifndef __VECTOR2_H__
#define __VECTOR2_H__

typedef struct Vector2 {
	float x, y;
} Vector2;

// default vectors
// ===============
extern		const Vector2 *vec2_zero;
extern		const Vector2 *vec2_up;
extern		const Vector2 *vec2_right;

// vector utility
// ===========
void		vec2_copy(Vector2 *dst, const Vector2 *src);

// vector arithmetic
// ===========
float		vec2_norm(const Vector2 *v);
float		vec2_sqrnorm(const Vector2 *v);
void		vec2_normalize(Vector2 *v);
void		vec2_multf(Vector2 *v, const float f);
void		vec2_add(Vector2 *v, const Vector2 *u);
void		vec2_sub(Vector2 *v, const Vector2 *u);
float		vec2_dot(const Vector2 *v, const Vector2 *u);

#endif // __VECTOR3_H__